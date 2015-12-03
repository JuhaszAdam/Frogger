#include <stdio.h>
#include <conio.h>

#include "MyConsole.h"

HANDLE hConsole;

int Console_Screen_Buffer_Width=0;
int Console_Screen_Buffer_Height=0;
PCHAR_INFO Console_Screen_Buffer=NULL;

void Init_Console()
{
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hStdin=GetStdHandle(STD_INPUT_HANDLE);
}

void Set_Console_Title(char *FTitle)
{
    SetConsoleTitle(FTitle);
}

void Set_Console_Buffer_Sizes(int FWidth, int FHeight)
{
    COORD c=
    {
        (short int) FWidth,
        (short int) FHeight
    };

    SetConsoleScreenBufferSize(hConsole,c);

    Console_Screen_Buffer_Width=FWidth;
    Console_Screen_Buffer_Height=FHeight;
    Console_Screen_Buffer=(PCHAR_INFO)realloc(Console_Screen_Buffer,sizeof(CHAR_INFO) * FWidth*FHeight);
}

void Set_Console_FullScreen()
{
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
}

void Set_Console_Cursor_Position(int FX, int FY)
{
    COORD c=
    {
        (short int) FX,
        (short int) FY
    };

    SetConsoleCursorPosition(hConsole,c);
}

void Set_Console_Text_Color(int FColor_Code)
{
    SetConsoleTextAttribute(hConsole, FColor_Code);
}

void Clear_Console_Buffer()
{
    memset(Console_Screen_Buffer,0,sizeof(CHAR_INFO)*Console_Screen_Buffer_Width*Console_Screen_Buffer_Height);
}

void Write_To_Console_Buffer(int FX, int FY, int FColor_Code, char FCharacter)
{
    if (
         (FX>=Console_Screen_Buffer_Width)
         ||
         (FY>=Console_Screen_Buffer_Height)
       )
    {
        printf("\r\nTulindexelted a kepernyo buffert!!!");
        printf("\r\nMax x=%i  Bejovo FX=%i",Console_Screen_Buffer_Width,FX);
        printf("\r\nMay y=%i  Bejovo FY=%i",Console_Screen_Buffer_Height,FY);
        getch();
        return;
    }
    PCHAR_INFO p=& Console_Screen_Buffer[FY*Console_Screen_Buffer_Width+FX];
    p->Char.AsciiChar=FCharacter;
    p->Attributes=FColor_Code;
}

void Write_Buffer_To_Console()
{
    COORD bufsize=
    {
        (short int) Console_Screen_Buffer_Width,
        (short int) Console_Screen_Buffer_Height
    };

    COORD bufpos=
    {
        (short int) 0,
        (short int) 0
    };

    SMALL_RECT destrect=
    {
        0,
        0,
        (short int)Console_Screen_Buffer_Width,
        (short int)Console_Screen_Buffer_Height
    };

    WriteConsoleOutput(
        hConsole,
        Console_Screen_Buffer,
        bufsize,
        bufpos,
        &destrect
    );
}

void MySleep(int Fms)
{
    Sleep(Fms);
}
