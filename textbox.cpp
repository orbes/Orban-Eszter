#include "textbox.hpp"

TextBox::TextBox(Widget * parent, int id, int x, int y, int sx, int sy)
    : Widget(parent, id, x + 2, y + 2, sx - 4, sy - 4) {
	_edit = true;

}

void TextBox::draw() const
{
    Widget::draw();
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y )
         << move_to(_x+1, _y+1) << color(0,0,0) << box(_size_x-2, _size_y-2 )
         << move_to(_x+5, _y+15) << color(255,255,255) << text(_text);
}

void TextBox::handle(Widget * source, int message, event ev) {

  Widget::handle(source, message, ev);

}

const string & TextBox::getText() const {
    return (_text);
}


void TextBox::setText(const string & text) {
  _text = text;
}

void TextBox::setEdit(bool edit) {
  _edit = edit;
}
