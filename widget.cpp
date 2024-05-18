#include "widget.hpp"
#include "window.hpp"


Widget::Widget(Window* w, int xpos, int ypos, int xsize, int ysize): _w(w), _posx(xpos), _posy(ypos), _sizex(xsize), _sizey(ysize)
{
    _active=true;
    _w->add_widget(this);

}
bool Widget::me(int evx, int evy)
{
    return (evx<_posx+_sizex && evx>_posx) && (evy<_posy+_sizey && evy>_posy);
}
bool Widget::isactive()
{
    return _active;
}
void Widget::deactivate()
{
    _active=false;
}
