#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"
#include "window.hpp"

class Window;

class Widget{
protected:
int _posx, _posy, _sizex, _sizey;
bool _active;
Window* _w;
public:
Widget(Window* w, int xpos, int ypos, int xsize, int ysize);
virtual void draw()=0;
virtual int getValue()=0;
bool me(int evx, int evy);
virtual void whenmouse(genv::event ev)=0;
bool isactive();
void deactivate();
};

#endif // WIDGET_H
