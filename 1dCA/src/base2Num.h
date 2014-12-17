#pragma once

#include "ofMain.h"

class base2Num {
public:
    static string convertToBase2(int n10, int pad=0);
    static int convertToBase10(string n2);
};