#include "mywindow.hpp"
#include "widget.hpp"
#include "spinbox.hpp"
#include <fstream>
#include "window.hpp"


using namespace std;


MyWindow::MyWindow(int sx, int sy):Window(sx, sy)
{
    konnyu=new Button(this, 40,50,100,50,"konnyu", [&](){betolt("sudoku1");});
    kozepes=new Button(this, 160,50,100,50,"kozepes", [&](){betolt("sudoku2");});
    nehez=new Button(this, 280,50,100,50,"nehez", [&](){betolt("sudoku3");});
}

void MyWindow::betolt(string palya)
{
    string fajlnev=palya+".txt";
    ifstream f(fajlnev);
    if(!f.good()) cout<<"hiba";
    for(int i=0; i<9; i++)
    {
        vector<Spinbox*> sor;
        for(int j=0; j<9; j++)
        {
            int s=0;
            f>>s;
            if(!s)
            {
                Spinbox *w=new Spinbox(this, 1, 9, xkezd+j*sbutton, ykezd+i*sbutton, sbutton, sbutton, [&](Spinbox* s){esemeny(s);}, i, j);
                sor.push_back(w);
            }
            else
            {
                Spinbox *w=new Spinbox(this, s, s, xkezd+j*sbutton, ykezd+i*sbutton, sbutton, sbutton, [&](Spinbox* s){esemeny(s);}, i, j);
                sor.push_back(w);
            }
        }
        tabla.push_back(sor);
    }
    f.close();
    fajlnev=palya+"_megold.txt";
    megold=vector<vector<int>>(9,vector<int>(9,0));
    f.open(fajlnev);
    if(!f.good()) cout<<"hiba!";
    for(int i=0; i<9; i++) for(int j=0; j<9; j++) f>>megold[i][j];
    f.close();
    konnyu->deactivate();
    kozepes->deactivate();
    nehez->deactivate();
    kezdes();
}

void MyWindow::sor(std::list<Spinbox*> & kivalasztottak, Spinbox*s, bool & van)
{
    for(int i=0; i<9; i++)
    {
        if(i!=s->getCol() && tabla[s->getRow()][i]->getValue()==s->getValue())
        {
            van=true;
            kivalasztottak.push_back(tabla[s->getRow()][i]);
        }
    }
}

void MyWindow::oszlop(list<Spinbox*> & kivalasztottak, Spinbox*s, bool & van)
{
    for(int i=0; i<9; i++)
    {
        if(i!=s->getRow() && tabla[i][s->getCol()]->getValue()==s->getValue())
        {
            van=true;
            kivalasztottak.push_back(tabla[i][s->getCol()]);
        }
    }
}

void MyWindow::block(list<Spinbox*> & kivalasztottak, Spinbox*s, bool & van)
{
    int xstart=3*((s->getRow())/3);
    int ystart=3*((s->getCol())/3);
    for(int i=xstart; i<xstart+3; i++)
    {
        for(int j=ystart; j<ystart+3; j++)
        {
            if(!(i==s->getRow() && j==s->getCol()) && tabla[i][j]->getValue()==s->getValue())
            {
                van=true;
                kivalasztottak.push_back(tabla[i][j]);
            }
        }
    }
}

void MyWindow::esemeny(Spinbox * s)
{
    if(ellenoriz()) nyertel();
    static list<Spinbox*> kivalasztottak;
    for(auto a : kivalasztottak)
    {
        a->nincs();
    }
    bool van=false;
    kivalasztottak.clear();
    oszlop(kivalasztottak, s, van);
    sor(kivalasztottak, s, van);
    block(kivalasztottak, s, van);
    if(van) kivalasztottak.push_back(s);
    for(auto a:kivalasztottak)
    {
        a->utkozes();
    }
}

bool MyWindow::ellenoriz()
{
    int cvy=0;
    int cvx=0;
    bool sorhelyes=true;
    while(cvy<9)
    {
        cvx=0;
        while(cvx<9 && tabla[cvy][cvx]->getValue()==megold[cvy][cvx])
        {
            cvx++;
        }
        if(cvx!=9) sorhelyes=false;
        cvy++;
    }
    if(cvy==9 && sorhelyes) return true;
    else return false;
}
