#pragma once

#include "ofMain.h"
#include "Cell.h"

class SquareGrid {
public:
    //Constructors
    SquareGrid(){}
    SquareGrid(const vector<vector<SquareCell> >& grid);
    
    //Get the sum of the current states in the neighbourhood of a given cell
    int getStates(int x, int y) const;
    //Get the grid
    vector<vector<SquareCell> > getGrid() const {return grid;}
    //Get grid's dimensions
    ofPoint getDim() const{return ofPoint(w, h);}
    
    //Apply the game of life rules
    void gameOfLife();
    
    //Display grid
    void display() const;
    
protected:
    //Grid storing the cells
    vector<vector<SquareCell> > grid;
    
    //Dimensions of the grid
    int w, h;
};