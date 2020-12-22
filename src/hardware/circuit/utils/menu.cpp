#include "menu.hpp"
#include "../../machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"
#include "./menu_circuit.hpp"

#include "../F405ControlBoard.hpp"  //temp

#define SIZEOFARRAY(array) (sizeof(array)/sizeof((array)[0]))
#define INTERVAL_CNT    100

Menu Menu::m_instance;

using namespace F405ControlBoard;

const MenuList List_Main[] =
{
    //{"CircuitMenu"      ,showCircuitMenu        ,{255,255,255}}
    //{"Menu1"            ,          },
    //{"Menu2"            ,          },
    //{"Menu3"            ,          },
    {"CircuitMenu"      ,showCircuitMenu        }
};

const RotaryMenu Menu_Main =
{
    {'M', 'a', 'i', 'n', 'M', 'e', 'n', 'u'},
    SIZEOFARRAY(List_Main),
    List_Main
};

bool Menu::inputSelect(void)
{
    static int interval = INTERVAL_CNT;
    if(!buttonPin[0].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }
    return false;
}

bool Menu::inputCancel(void)
{
    static int interval = INTERVAL_CNT;
    if(!buttonPin[1].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }
    return false;
}

bool Menu::inputLeft(void)
{
    static int interval = INTERVAL_CNT;
    if(!buttonPin[2].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }
    return false;
}

bool Menu::inputRight(void)
{
    static int interval = INTERVAL_CNT;
    if(!buttonPin[3].read())
    {
        if(interval == 0)
        {
            interval = INTERVAL_CNT;
            return true;
        }
    }
    else
    {
        if(interval > 0) interval--;
    }
    return false;
}

//メニューを表示
void Menu::showMenu(const RotaryMenu* menu, int cursor)
{
    //:**************************************************
    //! clcd
    //:**************************************************
    interface::clcd.line(0);
    interface::clcd.printf(menu->menuTitle);
    interface::clcd.line(1);
    interface::clcd.printf(menu->menu[cursor].title);

    //:**************************************************
    //! serial
    //:**************************************************
    showMenuFrameForSerial();
    interface::pcDebug->setCursor(1, 1);
    interface::pcDebug->printf(menu->menu[cursor].title);
    interface::pcDebug->setCursor(1, 12);
    interface::pcDebug->printf(menu->menuTitle);
    for(int i = 0; i < 8; i++)
    {
        if(i >= menu->listNumber)break;
        if((i + 8) < menu->listNumber)
        {

            interface::pcDebug->printf("%s", (cursor == i)? "->" : "  ");
            interface::pcDebug->printf("%s", menu->menu[i].title);
            interface::pcDebug->setCursor(26, i + 3);
            interface::pcDebug->printf("%s", (cursor == i)? "->" : "  ");
            interface::pcDebug->printf("%s", menu->menu[i + 8].title);
            //printf("\033[%d;H%c%s\033[%d;25H%c%s", i+4, (cursor == i)? '>' : ' ', menu->menu[i].title, i+4, (cursor == i+8)? '>' : ' ', menu->menu[i+8].title);
        }
        else
        {
            interface::pcDebug->setCursor(1, i + 3);
            interface::pcDebug->printf("%s", (cursor == i)? "->" : "  ");
            interface::pcDebug->printf("%s", menu->menu[i].title);
            //printf("\033[%d;H%c%s", i+4, (cursor == i)? '>' : ' ', menu->menu[i].title);
        }
    }
}

void Menu::showMenuFrameForSerial(void)
{
    interface::pcDebug->setColor(Serial::White);
    interface::pcDebug->clear();
    interface::pcDebug->setCursor(1, 2);
    interface::pcDebug->printf("------------------------------------------------");
    interface::pcDebug->setCursor(30, 12);
    interface::pcDebug->printf("[");
    interface::pcDebug->setColor(Serial::Red);
    interface::pcDebug->printf("R");
    interface::pcDebug->setColor(Serial::White);
    interface::pcDebug->printf(":select ");
    interface::pcDebug->setColor(Serial::Blue);
    interface::pcDebug->printf("B");
    interface::pcDebug->setColor(Serial::White);
    interface::pcDebug->printf(":return]");
    //printf("[\033[31mR\033[39m:move on \033[34mB\033[39m:return]");
}
