#include "button.hpp"
#include "window.hpp"
using namespace genv;

Button::Button(Window* w, int xpos, int ypos, int xsize, int ysize, std::string nev, std::function<void()> f):Widget(w, xpos, ypos, xsize, ysize), name(nev), _f(f)
{
}

void Button::draw()
{
    gout<<move_to(_posx, _posy)<<color(255,255,255)<<box(_sizex,_sizey);
    gout<<move_to(_posx+_sizex*0.1, _posy+_sizey*0.2)<<font("LiberationSans-Regular.ttf",_sizey*0.4)<<color(0,0,0)<<text(name);
}

int Button::getValue()
{
}

void Button::whenmouse(genv::event ev)
{
    if(ev.button==btn_left)
    {
        _f();
    }
}


