#include "amoba_palya.hpp"

#include <iostream>
#include <vector>

#define __AMOBA_PALYA__IDC_BOX 1

AmobaPalya::AmobaPalya(Widget * parent, int id, int x, int y, int sx, int sy, int number)
    : Widget(parent, id, x, y, sx, sy)
   {
    _number = number;
    GameMaster = new AmobaJatek(_number, _number);

	for(int iy = 0; iy< number; iy++)
    {
        int pixel_y=(sy/number)*iy+y;  ///pixel x y => hová rakjuk a négyzetett
        vector<TextBox> line;
        for(int ix=0; ix<number; ix++)
        {
            int pixel_x=(sx/number)*ix;
            TextBox tb(this, __AMOBA_PALYA__IDC_BOX, pixel_x, pixel_y, _size_x/number, _size_y/number);
            line.push_back(tb);
        }
        matrix.push_back(line);
    }
}


AmobaPalya::~AmobaPalya() {
}

void AmobaPalya::add(vector<Widget *> & widgets) {
  widgets.push_back(this);
  for(int i=0; i<_number; i++)
  {
      for(int j=0; j<_number; j++)
      {
        matrix.at(i).at(j).add(widgets);
      }
  }
}

void AmobaPalya::draw()
{
    for(int i=0; i<_number; i++)
    {
        for (int j=0; j<_number; j++)
        {
           switch (GameMaster->get_value(i,j))
           {
               case 0: matrix[i][j].draw(); break;
               case 1: matrix[i][j].setText("X"); break;
               case 2: matrix[i][j].setText("O"); break;
           }
        }
    }
}

void AmobaPalya::handle(Widget * source, int message, event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        for(int i=0; i<_number; i++)
        {
            for(int j=0; j<_number; j++)
            {
                if(matrix.at(i).at(j).is_selected(ev.pos_x, ev.pos_y))
                {
                    GameMaster->set_value(i, j);
                    draw();
                }
            }
        }

}
}




