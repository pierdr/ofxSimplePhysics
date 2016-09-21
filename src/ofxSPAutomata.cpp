//
//  ofxSPAutomata.cpp
//  example-vectors
//
//  Created by local on 9/1/16.
//
//

#include "ofxSPAutomata.h"
#pragma mark AUTOMATA constructor
ofxSPAutomata::ofxSPAutomata():super(AUTOMATA)
{
    ofxSPAutomata(10);
}
ofxSPAutomata::ofxSPAutomata(float initMass):super(AUTOMATA)
{
    location.set(ofRandom(100,ofGetScreenWidth()-100),ofRandom(100,ofGetScreenHeight()-100));
    velocity.set(0,0);
    acceleration.set(0,0);
    dimensions.set(36,36);
    mass=initMass;
    displayForces=false;
}
#pragma mark AUTOMATA methods
void ofxSPAutomata::update(){
    velocity+=acceleration;
    location+=velocity;
    if(collisionDetected)
    {
        collisionCounter--;
        if(collisionCounter==0)
        {
            collisionDetected=false;
        }
    }
    drawAcceleration=acceleration;
    acceleration=acceleration*0;
}
void ofxSPAutomata::applyForce(ofVec2f force){
    ofVec2f f=force;
    f/mass;
    acceleration+=f;
}
void ofxSPAutomata::applyGravity(ofVec2f g){
    g=g*mass;
    applyForce(g);
}
void ofxSPAutomata::display(){
    ofFill();
    ofSetColor(223, 223, 223);
   
    
    squashStretch=acceleration;
    squashStretch=squashStretch.normalize();
    
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotate(-velocity.angle(ofVec2f(0,1)));
    float mapSS=ofMap(abs(squashStretch.length()),0,1,0,0.2);
     ofSetLineWidth(1);
    ofDrawEllipse(dimensions.x/4,dimensions.y/4,dimensions.x/10,dimensions.y/10);
     ofSetLineWidth(130);
    ofDrawEllipse(0,0,dimensions.x,dimensions.y);
    ofSetColor(0,0,0);
    ofSetLineWidth(1);
    ofDrawLine(0, 0, 0, dimensions.y/2);
    ofPopMatrix();
    if(displayForces)
    {
        ofPushMatrix();
        ofTranslate(location.x,location.y);
        ofRotate(-drawAcceleration.angle(ofVec2f(0,1)));
        ofSetLineWidth(1);
        ofSetColor(123,123,123);
        ofDrawLine(0,0,0,ofMap(drawAcceleration.normalize().length(),0,1,0,dimensions.y));
        ofPopMatrix();
    }
    ofNoFill();
}
Boolean ofxSPAutomata::isInside(ofRectangle rec){
    if(rec.inside(location.x,location.y))
    {
        return true;
    }
    return false;
}
Boolean ofxSPAutomata::isInside(int x,int y,int radius){
    
    if(location.distance(ofVec2f(x,y))<(dimensions.x/2)+radius)
    {
        return true;
    }
    return false;
}
void ofxSPAutomata::drag(ofxSPFluid f){
    float speed=velocity.length();
    float dragMagnitude=f.c*speed*speed;
    ofVec2f dragV=velocity;
    dragV*-1;
    dragV.normalize();
    dragV=dragV*dragMagnitude;
    applyForce(dragV);
}
void ofxSPAutomata::didCollide()
{
    collisionDetected=true;
    collisionCounter=2;
}
void ofxSPAutomata::checkEdges()
{
    
    if(location.x+(dimensions.x/2)>ofGetWidth())
    {
        velocity.x=-(velocity.x*0.7);
        location.x=ofGetWidth()-(dimensions.x/2)-2;
    }
    else if(location.x-(dimensions.x/2)<0)
    {
        velocity.x=-(velocity.x*0.7);
        location.x=(dimensions.x/2)+2;
    }
    
    if(location.y+(dimensions.y/2)>ofGetHeight()){
        velocity.y=-(velocity.y*0.7);
        location.y=ofGetHeight()-(dimensions.y/2)-2;
    }
    else if(location.y-(dimensions.y/2)<0)
    {
        velocity.y=-(velocity.y*0.7);
        location.y=dimensions.y/2+2;
    }
}