#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP
#include "window.hpp"
#include "button.hpp"
#include "spinbox.hpp"
#include <vector>
#include <list>


class MyWindow:public Window
{
    std::vector<std::vector<Spinbox *>> tabla;
    std::vector<std::vector<int>> megold;
    Button * konnyu;
    Button * kozepes;
    Button * nehez;
    public:
        MyWindow(int sx, int sy);
        void esemeny(Spinbox*s);
        void oszlop(std::list<Spinbox*> & kivalasztottak,Spinbox*s, bool & van);
        void sor(std::list<Spinbox*> & kivalasztottak, Spinbox*s, bool & van);
        void block(std::list<Spinbox*> & kivalasztottak, Spinbox*s, bool & van);
        bool ellenoriz();
        void betolt(std::string);

};


#endif // MYWINDOW_H
