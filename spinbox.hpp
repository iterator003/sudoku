#ifndef SPINBOX_HPP
#define SPINBOX_HPP
#include "widget.hpp"
#include "graphics.hpp"
#include <functional>

class Spinbox : public Widget{
int lbound, ubound, value, row, col;
bool utkoz;
std::function<void(Spinbox*s)>_f;
public:
Spinbox(Window* w, int lowbound, int upbound, int x, int y, int sizex, int sizey, std::function<void(Spinbox*s)> f, int r, int c);
virtual int getValue();
virtual void draw();
virtual void whenmouse(genv::event ev);
int getCol();
int getRow();
void utkozes();
void nincs();
void newbound();
};

#endif // SPINBOX_HPP
