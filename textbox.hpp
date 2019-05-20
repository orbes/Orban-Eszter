#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include <string>
#include "graphics.hpp"
#include "widget.hpp"

using namespace std;

class TextBox : public Widget {
protected:
    string _text;
	bool _edit;
	int _r, _g, _b;

public:
    TextBox(Widget * parent, int id, int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(Widget * source, int message, event ev);

    const string & getText() const;
    void setText(const string & s);
    void setColor(int r, int g, int b);
    void setEdit(bool edit);
};


#endif // TEXTBOX_HPP_INCLUDED
