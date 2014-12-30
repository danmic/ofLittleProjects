#include "Grid.h"

SquareGrid::SquareGrid(const vector<vector<SquareCell> >& grid){
    
    this->grid = grid;
    w = grid.begin()->size();
    h = grid.size();
    
    for (int y = 0; y != h; y++) {
        for (int x = 0; x != w; x++) {
            ofPoint p;
            p.x = x * (grid[y][x].getEdge() + 1);
            p.y = y * (grid[y][x].getEdge() + 1);
            this->grid[y][x].setPosition(p);
        }
    }
}

int SquareGrid::getStates(int x, int y) const{
    
    int ret = 0;
    
    //Let the grid be thoroidal
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            
            int posi = i==-1 ? h-1 : i;
            int posj = j==-1 ? w-1 : j;
            posi = posi%h;
            posj = posj%w;
            
            //Accumulate in ret the state of the neighbours
            ret += grid[posi][posj].getState();
            
        }
    }
    
    //Subtract the state of the current cell
    ret -= grid[x][y].getState();
    
    return ret;
    
}

void SquareGrid::gameOfLife(){
    
    //Apply the game of life rules
    //  1. Save the number of alive neighbours in the variable neighbourhood
    //  2. Change the prevState member of the cell objects according to the rules
    //  3. Swap state and prevState of each cell
    
    for (int x = 0; x != h; x++) {
        for (int y = 0; y != w; y++) {
            
            int neighbours = getStates(x, y);
            
            //Condition for death
            bool death = (grid[x][y].getState() == 1) && (neighbours < 2 || neighbours > 3);
            //Condition for birth
            bool birth = (grid[x][y].getState() == 0) && (neighbours == 3);
            
            if (death) {
                grid[x][y].changePrevState(0);
            }else if (birth){
                grid[x][y].changePrevState(1);
            }else{//Stasis
                grid[x][y].changePrevState(grid[x][y].getState());
            }
            
        }
    }
    
    for (int i = 0; i != h; i++) {
        for (int j = 0; j != w; j++) {
            grid[i][j].swapStates();
        }
    }
    
}

void SquareGrid::display() const{
    for (auto r : grid) {
        for (auto c : r) {
            ofPushMatrix();
            ofTranslate(c.getEdge()/2.0, c.getEdge()/2.0);
            c.display();
            ofPopMatrix();
        }
    }
}