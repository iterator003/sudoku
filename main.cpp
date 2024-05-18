#include "mywindow.hpp"

using namespace std;

int main()
{
    Window * w=new MyWindow(500, 500);
    w->event_loop();
    return 0;
}
