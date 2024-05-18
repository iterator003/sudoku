#include "window.hpp"
#include "graphics.hpp"
#include <vector>

using namespace std;
using namespace genv;


Window::Window(int sx, int sy):_sx(sx), _sy(sy)
{
    gout.open(_sx,_sy);
    helyes=false;
    jatek=false;
}

static int select(vector<Widget*> v, int ex, int ey)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]->isactive() && v[i]->me(ex, ey))
            return i;
    }
    return -1;
}

static int selected=-1;

void Window::event_loop()
{
    event ev;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if(!helyes)
        {
        if(select(_widgets,ev.pos_x,ev.pos_y)!=-1)
        {
            selected=select(_widgets,ev.pos_x,ev.pos_y);
            _widgets[selected]->whenmouse(ev);
        }
        if(selected!=-1 && (ev.keycode==key_down || ev.keycode==key_up))
        {
            _widgets[selected]->whenmouse(ev);
        }
        gout<<move_to(0,0)<<color(0,0,0)<<box(_sx,_sy);
        for(Widget* s:_widgets)
        {
            s->draw();
        }
        if(!jatek) gout<<move_to(40,10)<<color(255,0,0)<<text("Valassz nehezsegi szintet!");
        if(jatek)
        for(int i=0; i<4; i++)
        {
            gout<<move_to(xkezd, ykezd+i*sbutton*3)<<color(255,0,0)<<line(9*sbutton, 0)<<move_to(xkezd, ykezd+i*sbutton*3+1)<<color(255,0,0)<<line(9*sbutton, 0)
            <<move_to(xkezd+i*sbutton*3, ykezd)<<line(0, 9*sbutton)<<move_to(xkezd+i*sbutton*3-1, ykezd)<<line(0, 9*sbutton);
        }
        }
        if(helyes) gout<<move_to(0,0)<<color(0,0,0)<<box(_sx,_sy)<<move_to(_sx/2-_sx*0.3, _sy/3)<<color(255,0,0)<<font("LiberationSans-Regular.ttf",30)<<text("Megoldottad a sudokut!");
        gout<<refresh;
    }
}

void Window::add_widget(Widget* w)
{
    _widgets.push_back(w);
}

void Window::nyertel()
{
    helyes=true;
}

bool Window::jateke()
{
    return jatek;
}

void Window::kezdes()
{
    jatek=true;
}
