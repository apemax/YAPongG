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

using namespace std;

#ifndef AIBAT_H
#define AIBAT_H

class aibat
{
  public:
    aibat();
    void Move();
    int Height = 250;
    int Width = 50;
    int PositionX;
    int PositionY;
    int VelocityX;
    int VelocityY;
};

extern aibat aibatone;

#endif //AIBAT_H
