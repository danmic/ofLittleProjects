#pragma once

#include "ofMain.h"

class SquareCell{
public:
    //Constructors
    SquareCell(){}
    SquareCell(float edge){ this->edge = edge; }
    SquareCell(const ofPoint& position, float edge);
    
    //Get the current state
    int getState() const{ return state; }
    //Get the previous state
    int getPrevState() const{ return prevState; }
    //Get the edge length
    float getEdge() const{ return edge; }
    
    //Set position
    void setPosition(const ofPoint& pos){ position = pos; }
    
    //Set the current state and change the previous state
    void setState(int newState);
    
    //Set the previous state without changing the current state
    void changePrevState(int newPrevState){ prevState = newPrevState; }
    //Set the current state without changing the previous state
    void changeState(int newState){ state = newState; }
    //Swap the current and the previous state
    void swapStates(){int s = state; state = prevState; prevState = s;}
    
    //Display the cell
    void display() const;

private:
    //Current and previous state
    int state;
    int prevState;

    //Position of the cell's center
    ofPoint position;
    //Lenght of edge (2*radius)
    float edge;
};