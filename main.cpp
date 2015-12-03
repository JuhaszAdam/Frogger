#include <iostream>

#include "Console.h"
#include "MyConsole.h"
#include "Playground.h"
#include <conio.h>

using namespace std;

int main()
{
    cout << "Starting..." << endl;
    int victories = 0;
    int deaths = 0;
    char ch = ' ';
    do
    {
        ch =' ';
        Playground *playground=Playground::getInstance();
        playground->init();

        while (playground->active)
        {
            playground->tick();
        }

        playground->console->fillArea(12, 6, 68, 13, FCIY|BCN , '#');
        playground->console->fillArea(13, 7, 67, 12, FCIY|BCN , ' ');
        playground->console->drawBuffer();

        playground->console->setPosition(36,8);
        cout <<((playground->victory)?"You Won!":"You Died!");

        playground->console->setPosition(28,10);
        cout<<"Press 'x' or 'n' to exit!";

        ch = getch();
    }
    while(ch !='x' && ch != 'n');

    Set_Console_Cursor_Position(0,20);
    return 0;
}
