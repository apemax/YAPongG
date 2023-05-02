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

#include "ball.h"
#include "main.h"

using namespace std;

ball::ball()
{
  PositionX = 640;
  PositionY = 360;

  VelocityX = 0;
  VelocityY = 0;
}

void ball::Move()
{
  PositionY += VelocityY;

  if(PositionY < 0)
  {
    VelocityY += 5;
  }
  if (PositionY + Height > SCREEN_HEIGHT)
  {
    VelocityY -= 5;
  }

  PositionX += VelocityX;

  if( ( PositionX < 0 ) || ( PositionX + Width > SCREEN_WIDTH ) )
  {
    PositionX -= VelocityX;
  }
}
