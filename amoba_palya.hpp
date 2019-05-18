///játék tér

#ifndef AMOBA_PALYA_HPP_INCLUDED
#define AMOBA_PALYA_HPP_INCLUDED

#include <vector>
#include <string>

#include "graphics.hpp"
#include "widget.hpp"
#include "textbox.hpp"
#include "amoba_jatek.hpp"

class AmobaPalya : public Widget {
protected:
    vector<vector<TextBox>> matrix;
    AmobaJatek* GameMaster;
    int _number;
public:
    AmobaPalya(Widget * parent, int id, int x, int y, int sx, int sy, int  number);
	virtual ~AmobaPalya();
	virtual void handle(Widget * source, int message, event ev);
    virtual void draw();
    void add(vector<Widget *> & widgets);

};


#endif // LISTVIEW_HPP_INCLUDED
