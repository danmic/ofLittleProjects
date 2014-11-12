#include "InsertionSort.h"


void insertionSort(int x, int y, ofImage& image, int currentValue, char channel){
    //Store in previousX and previousY the position of the last pixel of a channel
    int previousX = x - 1;
    int previousY = y;
    
    if (x == 0) {           //If the current pixel is (0, n) for some n
        previousX = image.width - 1;
        previousY = y - 1;
    }
    
    int previousC;
    
    //Save in previousC the value of pixel (previousX, previousY) component
    switch (channel) {
        case 'r':
            previousC = image.getColor(previousX, previousY).r;
            break;
        
        case 'g':
            previousC = image.getColor(previousX, previousY).g;
            break;
            
        case 'b':
            previousC = image.getColor(previousX, previousY).b;
            break;
            
        default:
            break;
    }
    
    if ( currentValue >= previousC) {   //If currentValue is larger than the maximum value in the image
        
        switch (channel) {
            case 'r':
                image.setColor(x, y, ofColor(currentValue, 0, 0));
                break;
                
            case 'g':
                image.setColor(x, y, ofColor(0, currentValue, 0));
                break;
                
            case 'b':
                image.setColor(x, y, ofColor(0, 0, currentValue));
                break;
                
            default:
                break;
        }
        
    }else{                              //Otherwise, insert currentValue in the right position
        
        //The variable find will be true when the position will have been found
        bool find = false;
        
        while (previousY >= 0) {
            while (previousX >= 0) {
                
                //Change the value of previousC with the value of (previousX, previousY)
                switch (channel) {
                    case 'r':
                        previousC = image.getColor(previousX, previousY).r;
                        break;
                        
                    case 'g':
                        previousC = image.getColor(previousX, previousY).g;
                        break;
                        
                    case 'b':
                        previousC = image.getColor(previousX, previousY).b;
                        break;
                        
                    default:
                        break;
                }
                
                //Shift the elements one step on the right until the position
                //where currentValue must be inserted is found
                if (currentValue < previousC) {
                    
                    if (previousX == image.width - 1) {

                        switch (channel) {
                            case 'r':
                                image.setColor(0, previousY+1, ofColor(previousC, 0, 0));
                                break;
                                
                            case 'g':
                                image.setColor(0, previousY+1, ofColor(0, previousC, 0));
                                break;
                                
                            case 'b':
                                image.setColor(0, previousY+1, ofColor(0, 0, previousC));
                                break;
                                
                            default:
                                break;
                        }
                        
                    }else{
                        
                        switch (channel) {
                            case 'r':
                                image.setColor(previousX+1, previousY, ofColor(previousC, 0, 0));
                                break;
                                
                            case 'g':
                                image.setColor(previousX+1, previousY, ofColor(0, previousC, 0));
                                break;
                                
                            case 'b':
                                image.setColor(previousX+1, previousY, ofColor(0, 0, previousC));
                                break;
                                
                            default:
                                break;
                        }
                     
                    }
                    
                }else{              //If the position is found
                    
                    find = true;
                    break;
                    
                }
                
                //Update previousX
                previousX--;
                
            }
            
            //If previousX == -1 and previousY == 0 then the position where currentC must be inserted
            //is (0, 0)
            
            if(previousX == -1 && previousY == 0){
                
                previousX = 0;
                find = true;
            
            }
            
            if (find) {
            
                break;
            
            }
            
            //Update previousX and previousY
            previousX = image.width - 1;
            previousY--;
            
        }
        
        //Set up the pixel (previousX, previousY) with currentValue
        switch (channel) {
            case 'r':
                image.setColor(previousX, previousY, ofColor(currentValue, 0, 0));
                break;
                
            case 'g':
                image.setColor(previousX, previousY, ofColor(0, currentValue, 0));
                break;
                
            case 'b':
                image.setColor(previousX, previousY, ofColor(0, 0, currentValue));
                break;
                
            default:
                break;
        }
        
    }
    
}