#include "graphics.hpp"
#include "widget.hpp"
#include "amoba_palya.hpp"

#include <vector>

using namespace std;
using namespace genv;

void event_loop(vector<Widget*> & widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev &&ev.keycode!=key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        widgets[i]->setFocus(true);
                        focus = i;
                } else {
                        widgets[i]->setFocus(false);
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(NULL, 0, ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}

int main()
{

    gout.open(500,500);
    vector<Widget*> w;
    AmobaPalya *ab = new AmobaPalya(NULL, 0, 0, 0, 500, 500, 20);
    ab->add(w);
    event_loop(w);
    return 0;
}
