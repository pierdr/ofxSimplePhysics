//
//  ofxSPAutomata.hpp
//  example-vectors
//
//  Created by local on 9/1/16.
//
//

#pragma once
#import "ofxSimplePhysics.h"
#import "ofxSPFluid.h"
#include <stdio.h>

class ofxSPAutomata: public ofxSimplePhysics{
    private:  // Prevents erroneous use by other classes.
        typedef ofxSimplePhysics super;
    public:
    /////////////////////////////////////////////////
    ////
    //// AUTOMATA --> 0
    ////
    /////////////////////////////////////////////////
    ofxSPAutomata();
    ofxSPAutomata(float initMass);
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f dimensions;
    ofVec2f squashStretch;
    
    Boolean collisionDetected;
    Boolean displayForces;
    int collisionCounter;
    float topSpeed=10;
    
    float mass;
    
    void update();
    void display();
    void checkEdges();
    void drag(ofxSPFluid f);
    
    void applyForce(ofVec2f force);
    void applyGravity(ofVec2f g);
    
    Boolean isInside(ofRectangle rec);
    Boolean isInside(int x,int y,int radius);
    void didCollide();
private:
    ofVec2f drawAcceleration;

};



