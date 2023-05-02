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

using namespace std;

SDL_Texture* Bat = NULL;
SDL_Texture* Background = NULL;
SDL_Texture* Ball = NULL;


SDL_Texture* loadTexture(std::string path)
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if( loadedSurface == NULL )
    {
        cout << "Error loading file: " << IMG_GetError() << endl;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
        if( newTexture == NULL )
        {
            cout << "Error creating texture: " << SDL_GetError() << endl;
        }

        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void LoadAssets()
{
  Bat = loadTexture("bat.png");
  Background = loadTexture("background.png");
  Ball = loadTexture("ball.png");

  if(Bat == NULL)
  {
    cout << SDL_GetError() << endl;
  }

  if(Background == NULL)
  {
    cout << SDL_GetError() << endl;
  }

  if(Ball == NULL)
  {
    cout << SDL_GetError() << endl;
  }
}
