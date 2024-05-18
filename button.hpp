#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include <functional>


class Button: public Widget
{
    std::string name;
    std::function<void()> _f;
public:
    Button(Window* w, int xpos, int ypos, int xsize, int ysize, std::string nev, std::function<void()> f);
    virtual void draw();
    virtual int getValue();
    virtual void whenmouse(genv::event ev);
};

#endif // BUTTON_HPP
