#include "base2Num.h"

//Pad indicates the number of digits
string base2Num::convertToBase2(int n10, int pad){
    
    string ret = "";
    
    //Store in r the remainders
    deque<int> r;
    while (n10 != 0) {
        r.push_front(n10%2);
        n10 /= 2;
    }
    
    //Apply padding when required
    while (pad > r.size()) {
        r.push_front(0);
    }
    
    //Generate the string from r
    while (!r.empty()) {
        ret += ofToString(r.front());
        r.pop_front();
    }
    
    return ret;
    
}

int base2Num::convertToBase10(string n2){
    
    int ret = 0;
    
    //Calculate the number in base 10
    for (int i = 0; i != n2.size(); i++) {
        ret += ofToInt(string(1, n2[i])) * pow(2.0, int(n2.size()-i-1));
    }
    
    return ret;
    
}
