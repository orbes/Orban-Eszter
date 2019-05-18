///játékmester

#ifndef __AMOBA_JATEK_HPP
#define __AMOBA_JATEK_HPP

#include <vector>

using namespace std;

class AmobaJatek{
public:
    AmobaJatek(int _height, int _width);
    virtual ~AmobaJatek();

    void set_value(int x, int y);
    int get_value(int x, int y);
    bool is_fulltable();
    void set_matrix_defvalue();
    void _row();
    void _column();
    void _diagonal();
    void _win();
    bool is_win();

protected:
    int height, width;
    vector<vector<int> > matrix;
    int curr_value;
    bool win;
};
#endif // __AMOBA_JATEK__HPP
