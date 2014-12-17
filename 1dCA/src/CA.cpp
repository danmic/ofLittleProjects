#include "CA.h"
#include "base2Num.h"

CA::CA(const string& initState, bool gen){
    
    state = initState;
    ruleset = string(8, '0');
    generation = 0;
    h = gen;
    
    if (h) {
        history.push_back(state);
    }

}

string CA::getNeighbourhood(int i){
    
    
    auto back = (i-1<0) ? state.size()-1 : i-1;
    auto forward = (i+1>state.size()-1) ? 0 : i+1;
    return ofToString( state[back] ) + ofToString(state[i]) + ofToString( state[forward] );
    
}

char CA::applyRuleToNeighbourhood(const string& neighbourhood){
    
    int l = base2Num::convertToBase10(neighbourhood);
    return ruleset[ base2Num::convertToBase10(neighbourhood) ];
    
}

void CA::generate(){
    
    generation++;
    
    auto newState = state;
    
    for (int i = 0; i != state.size(); i++) {
        auto neighbourhood = getNeighbourhood(i);
        newState[i] = applyRuleToNeighbourhood(neighbourhood);
    }
    
    state = newState;
    
    if (h) {
        history.push_back(state);
    }
    
}