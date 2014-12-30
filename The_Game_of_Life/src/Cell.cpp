#include "Cell.h"

void SquareCell::setState(int newState){
    prevState = state;
    state = (newState!=0) ? 1 : 0;
}

SquareCell::SquareCell(const ofPoint& position, float edge){
    this->position = position;
    this->edge = edge;
}

void SquareCell::display() const{
        
    if (prevState == state) {
        state==0 ? ofSetColor(243, 249, 254) : ofSetColor(2, 136, 240);
    }else{
        prevState==0 ? ofSetColor(155, 206, 245) : ofSetColor(38, 153, 242);
    }
    
    //Draw the circle
    ofCircle(position, edge/float(2));
    
}