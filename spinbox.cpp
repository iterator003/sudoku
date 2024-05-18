#include "spinbox.hpp"
#include "widget.hpp"
#include "window.hpp"
#include "mywindow.hpp"
#include <cmath>

using namespace genv;
Spinbox::Spinbox(Window* w, int lowbound, int upbound, int x, int y, int sizex, int sizey, std::function<void(Spinbox*s)> f, int r, int c):Widget(w, x, y, sizex, sizey), lbound(lowbound), ubound(upbound), _f(f), row(r), col(c)
{
    utkoz=false;
    if(ubound!=lbound) value=0;
    else value=ubound;
}

int Spinbox::getValue()
{
    return value;
}

void Spinbox::draw()
{
    int r, g, b;
    if(lbound==ubound)
    {
        r=200; g=200; b=200;
    }
    else
    {
        r=255; g=255; b=255;
    }
    gout<<move_to(_posx, _posy)<<color(r,g,b)<<box(_sizex, _sizey);
    if(value!=0)
    if(utkoz)
    gout<<move_to(_posx+_sizex*0.35,_posy+_sizey*0.15)<<color(255,0,0)<<font("LiberationSans-Regular.ttf",_sizey*0.6)<<text(std::to_string(value));
    else
    gout<<move_to(_posx+_sizex*0.35,_posy+_sizey*0.15)<<color(0,0,0)<<font("LiberationSans-Regular.ttf",_sizey*0.6)<<text(std::to_string(value));
    gout<<move_to(_posx,_posy)<<color(0,0,0)<<line(_sizex, 0)<<line(0,_sizey);
}


void Spinbox::whenmouse(genv::event ev)
{
    if((ev.button==btn_wheelup || ev.keycode==key_pgup || ev.keycode==key_up) && value<=ubound)
        if(value<ubound) value++;
        else value=lbound;
    if((ev.button==btn_wheeldown || ev.keycode==key_pgdn || ev.keycode==key_down) && value>=lbound)
        if(value>lbound) value--;
        else value=ubound;
    if(ev.button==btn_wheelup || ev.keycode==key_pgup || ev.keycode==key_up || ev.button==btn_wheeldown || ev.keycode==key_pgdn || ev.keycode==key_down) _f(this);
    if(ev.button==btn_left)
    {
        value=0;
        _f(this);
    }

}

int Spinbox::getCol()
{
    return col;
}

int Spinbox::getRow()
{
    return row;
}

void Spinbox::utkozes()
{
    utkoz=true;
}

void Spinbox::nincs()
{
    utkoz=false;
}

void Spinbox::newbound()
{
    ubound=9;
    lbound=1;
}
