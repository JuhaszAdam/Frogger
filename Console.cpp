//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : JuhaszAdamFrogger
//  @ File Name : Console.cpp
//  @ Date : 2015.11.14.
//  @ Author : Juh�sz �d�m
//
//


#include "Console.h"
#include "MyConsole.h"

Console::Console()
{
    Init_Console();
    Set_Console_Text_Color(FCIY|BCN);
}

void Console::setSize(int w, int h)
{
    width=w;
    height=h;

    Set_Console_Buffer_Sizes(w, h);
    clearScreen();
}

void Console::clearScreen()
{
    Clear_Console_Buffer();
}

void Console::drawBuffer()
{
    Write_Buffer_To_Console();
}

void Console::draw(int x, int y, int color, char symbol)
{
    Write_To_Console_Buffer(x, y, color, symbol);
}

void Console::setPosition(int x, int y)
{
    Set_Console_Cursor_Position(x,y);
}

void Console::fillArea(int ax, int ay, int bx, int by, int color, char symbol)
{
    for(int i=ax; i<bx; i++)
    {
        for(int j=ay; j<by; j++)
        {
            Write_To_Console_Buffer(i, j, color, symbol);
        }
    }
}
