/*
    This file is part of YAPongG.

    YAPongG is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    YAPongG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with YAPongG.  If not, see <http://www.gnu.org/licenses/>.
*/
// Copyright (C) 2023 Peter Wright
// Author: Peter "apemax" Wright
// YAPongG

#include <iostream>
#include "main.h"
#include "playerbat.h"
#include "ball.h"
#include "aibat.h"

using namespace std;

SDL_Event Event;

SDL_Window* Window = NULL;
SDL_Renderer* Renderer = NULL;

int main()
{
  bool MainLoop = true;
  int Game_State = 2;
  //SDL init.

  playerbat playerone;
  aibat aibatone;
  ball ballone;

  SDL_Rect RectPlayerBat;
  SDL_Rect RectAIBat;
  SDL_Rect RectBall;

  RectPlayerBat.x = playerone.PositionX;
  RectPlayerBat.y = playerone.PositionY;
  RectPlayerBat.w = playerone.Width;
  RectPlayerBat.h = playerone.Height;

  RectAIBat.x = aibatone.PositionX;
  RectAIBat.y = aibatone.PositionY;
  RectAIBat.w = aibatone.Width;
  RectAIBat.h = aibatone.Height;

  RectBall.x = ballone.PositionX;
  RectBall.y = ballone.PositionY;
  RectBall.w = ballone.Width;
  RectBall.h = ballone.Height;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    cout << "Failed to initialise SDL: " << endl;
    cout << SDL_GetError() << endl;
  }
  else
  {
    Window = SDL_CreateWindow("YAPongG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (Window == NULL)
    {
      cout << "Failed to create SDL window: " << endl;
      cout << SDL_GetError() << endl;
    }
    else
    {
      Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (Renderer == NULL)
      {
        cout << "Failed to create SDL renderer: " << endl;
        cout << SDL_GetError() << endl;
      }

      LoadAssets();

      int imgFlags = IMG_INIT_PNG;

      if( !(IMG_Init(imgFlags) & imgFlags))
      {
        cout << "SDL_image could not initialize! SDL_image Error: " <<  IMG_GetError() << endl;
      }

      while (MainLoop == true)
      {
        //Handle SDL input
        while (SDL_PollEvent(&Event) != 0)
        {
          playerone.HandleInput();

          if (Event.type == SDL_KEYDOWN)
          {
            if (Event.key.keysym.sym == SDLK_ESCAPE)
            {
              if (Game_State == 1)
              {
                cout << "Quit?" << endl;
                //output message to quit game.
              }
              else if (Game_State == 2)
              {
                Game_State = 3;
              }
              else if (Game_State == 3)
              {
                Game_State = 2;
              }
            }
          }

          if (Event.type == SDL_QUIT)
          {
            MainLoop = false;
          }
        }

        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
        SDL_RenderClear(Renderer);

        //Switch between game state
        if (Game_State == 1)
        {
          //Main menu.
          SDL_RenderClear(Renderer);

          SDL_RenderPresent(Renderer);
        }
        else if (Game_State == 2)
        {
          //In game.

          playerone.Move();

          ballone.Move();

          aibatone.Move();

          RectPlayerBat.x = playerone.PositionX;
          RectPlayerBat.y = playerone.PositionY;

          RectAIBat.x = aibatone.PositionX;
          RectAIBat.y = aibatone.PositionY;

          RectBall.x = ballone.PositionX;
          RectBall.y = ballone.PositionY;

          if (ballone.VelocityX == 0)
          {
            ballone.VelocityX -= 5;
          }
          if (SDL_HasIntersection(&RectBall, &RectPlayerBat) == true)
          {
            ballone.VelocityX += 10;

            if (playerone.VelocityY > 0 && ballone.VelocityY == 0)
            {
              ballone.VelocityY += 5;
            }
            if (playerone.VelocityY < 0 && ballone.VelocityY == 0)
            {
              ballone.VelocityY -= 5;
            }
          }
          if (SDL_HasIntersection(&RectBall, &RectAIBat) == true)
          {
            ballone.VelocityX -= 10;
          }

          aibatone.VelocityY = ballone.VelocityY;

          if (ballone.PositionX <= 0)
          {
            aibatone.Score += 1;

            ballone.PositionX = 640;
            ballone.PositionY = 360;
          }

          if (ballone.PositionX + ballone.Width >= SCREEN_WIDTH)
          {
            playerone.Score += 1;

            ballone.PositionX = 640;
            ballone.PositionY = 360;
          }

          SDL_RenderCopy(Renderer, Background, NULL, NULL);

          SDL_RenderCopy(Renderer, Bat, NULL, &RectPlayerBat);

          SDL_RenderCopy(Renderer, Ball, NULL, &RectBall);

          SDL_RenderCopy(Renderer, Bat, NULL, &RectAIBat);

          SDL_RenderPresent(Renderer);

        }
        else if (Game_State == 3)
        {
          //Pause menu.
          SDL_RenderClear(Renderer);

          SDL_RenderPresent(Renderer);
        }

      } //End of main loop.
    }
  }

  SDL_DestroyWindow(Window);
  SDL_Quit();

  return 0;
}
