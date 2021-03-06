//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : JuhaszAdamFrogger
//  @ File Name : Coordinate.cpp
//  @ Date : 2015.11.14.
//  @ Author : Juh�sz �d�m
//
//


#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

Coordinate::Coordinate()
{
    this->x = 0;
    this->y = 0;
}

bool Coordinate::collidesWith(Coordinate other)
{
    return
        (this->x == other.getX())&&(this->y == other.getY());
}

int Coordinate::getX()
{
    return this->x;
}

int Coordinate::getY()
{
    return this->y;
}

void Coordinate::setX(int x)
{
    this->x = x;
}

void Coordinate::setY(int y)
{
    this->y = y;
}

void Coordinate::setCoordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}
