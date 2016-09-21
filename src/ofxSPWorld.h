//
//  ofxSPWorld.hpp
//  example-vectors
//
//  Created by local on 9/18/16.
//
//
#pragma once
#import "ofxSimplePhysics.h"
#import "ofxSPFluid.h"
#import "ofxSPAutomata.h"

#ifndef ofxSPWorld_hpp
#define ofxSPWorld_hpp

#include <stdio.h>

class ofxSPWorld: public ofxSimplePhysics{
private:  
    typedef ofxSimplePhysics super;
public:
    /////////////////////////////////////////////////
    ////
    //// WORLD --> 1
    ////
    /////////////////////////////////////////////////
    ofxSPWorld(ofVec2f gravity);
    ofxSPWorld();
    
    ofVec2f g;
    vector<ofxSPFluid>           fluids;
    vector<ofxSPAutomata>        automatas;
    vector<ofVec2f>              globalForces;
    
    void addFluid(ofxSPFluid f);
    void addAutomata(ofxSPAutomata a);
    void removeAutomata(ofxSPAutomata *a);
    
    void update();
    void applyGlobalForce(ofVec2f f);
    
    void changeGravity(ofVec2f newGravity);
    void display();
    
    
};

#endif /* ofxSPWorld_hpp */
