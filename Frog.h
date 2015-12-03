//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : JuhaszAdamFrogger
//  @ File Name : Frog.h
//  @ Date : 2015.11.14.
//  @ Author : Juh�sz �d�m
//
//


#if !defined(_FROG_H)
#define _FROG_H

#include "Coordinate.h"
#include "Entity.h"
#include "DirectionEnum.h"

class Frog : public Entity
{
public:

    Frog();
    char symbol;

    void move(DirectionEnum direction);
    void tick();
    void render();
};

#endif  //_FROG_H
