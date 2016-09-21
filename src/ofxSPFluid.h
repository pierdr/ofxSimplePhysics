//
//  ofxSPFluid.hpp
//  example-vectors
//
//  Created by local on 9/18/16.
//
//
#pragma once
#import "ofxSimplePhysics.h"

#ifndef ofxSPFluid_hpp
#define ofxSPFluid_hpp




#include <stdio.h>

class ofxSPFluid: public ofxSimplePhysics{
private:  // Prevents erroneous use by other classes.
    typedef ofxSimplePhysics super;
public:
    /////////////////////////////////////////////////
    ////
    //// FLUID --> 2
    ////
    /////////////////////////////////////////////////
    ofxSPFluid(ofRectangle rect,float coefficient);
    
    ofRectangle rect;
    float c;
    
    
};


#endif /* ofxSPFluid_hpp */

