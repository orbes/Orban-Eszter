#include "amoba_jatek.hpp"

#include <iostream>

using namespace std;

AmobaJatek::AmobaJatek(int _height, int _width)
{
    height=_height;
    width=_width;
    curr_value=1;
    win=false;

    for(int i=0; i<height; i++)
    {
        vector<int> sor(width, 0);
        matrix.push_back(sor);
    }
}

AmobaJatek::~AmobaJatek()
{
    //dtor
}

void AmobaJatek::set_value(int x, int y)
{
    if(matrix[x][y]==0)
    {
        matrix[x][y]=curr_value;

        if(curr_value==1)
        {
            curr_value=2;
        }else
        {
            curr_value=1;
        }
    }
}

int AmobaJatek::get_value(int x, int y)
{
    return matrix[x][y];
}

bool AmobaJatek::is_fulltable()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(matrix[i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}

void AmobaJatek::set_matrix_defvalue()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            matrix[i][j]=0;
        }
    }
}

void AmobaJatek::_row()
{
    for(int i=0; i<height; i++)
    {
        int c=0;
        for(int j=0; j<width-1; j++)
        {
            if(matrix[i][j]>0 && matrix[i][j]==matrix[i][j+1])
            {
                c++;
            }else
            {
                c=0;
            }

            if(c==4)
            {
                win=true;

                for(int k=j-3; k<=j+1; k++)
                {
                    matrix[i][k]=3;
                }
            }
        }
    }
}

void AmobaJatek::_column()
{
    for(int i=0; i<width; i++)
    {
        int v=0;
        for(int j=0; j<height-1; j++)
        {
            if(matrix[j][i]>0 && matrix[j][i]==matrix[j+1][i])
            {
                v++;
            }else
            {
                v=0;
            }

            if(v==4)
            {
                win=true;

                for(int k=j-3; k<=j+1; k++)
                {
                    matrix[k][i]=3;
                }
            }
        }
    }
}

void AmobaJatek::_diagonal()
{
    for(int i=0; i<height-1; i++)
    {
        int b=0;
        for(int j=0; j<width-1; j++)
        {
            if(matrix[i][j]>0 && matrix[i][j]==matrix[i+1][j+1])
            {
                b++;
            }else if(matrix[i][j]>0 && matrix[i][j]!=matrix[i+1][j+1])
            {
                b=0;
            }

            if(b==4)
            {
                win=true;

                for(int k=j-3; k<=j+1; k++)
                {
                    matrix[i][k]=3;
                }
            }
        }
    }
}

void AmobaJatek::_win()
{
    _row();
    _column();
    _diagonal();
}

bool AmobaJatek::is_win()
{
    _win();
    return win;
}

