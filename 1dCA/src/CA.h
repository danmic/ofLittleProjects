#pragma once

#include "ofMain.h"

//1-Dimensional Cellular Automata with neighbourhood of 3 elements
class CA {
public:
    
    //Constructors
    CA(){}
    CA(const string& initState, bool gen = false);
    
    //Set the ruleset
    void setRules(const string& ruleset){
        //Revert the ruleset passed as a parameter to let
        //applyRuleToNeighbourhood function work correctly
        this->ruleset = string(ruleset.rbegin(), ruleset.rend());
    }
    
    //New generation
    void generate();
    
    void clearHistory(){history.clear();}
    
    vector<string> getHistory() const{return h ? history : vector<string>(1, state);}
    
private:
    
    //A string of 0s and 1s to indicate the current state of CA
    string state;
    
    //Keep track of how many generations happened
    bool h;     //If h == 0 don't memorize past generations
    int generation;
    //Store in history all generation
    vector<string> history;
    
    //Rules
    string ruleset;
    
    
    string getNeighbourhood(int i);
    char applyRuleToNeighbourhood(const string& neighbourhood);
    
};