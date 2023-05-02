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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

#ifndef MAIN_H
#define MAIN_H

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Texture* loadTexture(std::string path);
void LoadAssets();

extern SDL_Event Event;
extern SDL_Texture* Bat;
extern SDL_Texture* Background;
extern SDL_Texture* Ball;
extern SDL_Renderer* Renderer;

#endif //MAIN_H
