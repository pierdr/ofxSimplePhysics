//
//  ofxSPWorld.cpp
//  example-vectors
//
//  Created by local on 9/18/16.
//
//

#include "ofxSPWorld.h"
ofxSPWorld::ofxSPWorld(ofVec2f gravity):super(WORLD){
    g=gravity;
    
}
ofxSPWorld::ofxSPWorld():super(WORLD){
    g=ofVec2f(0,0);
}
void ofxSPWorld::update(){
    int times=0;
    for(int i=0;i<automatas.size();i++)
    {
        
        automatas.at(i).update();
        automatas.at(i).applyGravity(g);
        
        for(vector<ofVec2f>::iterator forcesIt=globalForces.begin();forcesIt!=globalForces.end();forcesIt++)
        {
            automatas.at(i).applyForce((ofVec2f)*forcesIt);
        }
        if(!automatas.at(i).collisionDetected)
        {
            for(int z=0;z<automatas.size();z++)
            {
                if(z==i)
                {
                    continue;
                }
                if(automatas.at(i).isInside(automatas.at(z).location.x,automatas.at(z).location.y,automatas.at(z).dimensions.x))
                {
                    
                    ofVec2f forceCollision=ofVec2f(((automatas.at(i).velocity.x*automatas.at(i).mass)+(automatas.at(z).velocity.x*automatas.at(z).mass))/(automatas.at(i).mass+automatas.at(z).mass),((automatas.at(i).velocity.y*automatas.at(i).mass)+(automatas.at(z).velocity.y*automatas.at(z).mass))/(automatas.at(i).mass+automatas.at(z).mass) );
                    
                    //apply collision force
                    automatas.at(z).applyForce((forceCollision/3)*-1);
                    automatas.at(i).applyForce((forceCollision/3));
                    
                    //apply new location
                    /*while(automatas.at(i).isInside(automatas.at(z).location.x,automatas.at(z).location.y,automatas.at(z).dimensions.x))
                    {
                        automatas.at(z).location+=(forceCollision.normalize()*2);
                        
                    }*/
                    
                    
                    automatas.at(i).didCollide();
                    automatas.at(z).didCollide();
                }
            }
        }
        
        automatas.at(i).checkEdges();
        
        times++;
    }
}
void ofxSPWorld::addFluid(ofxSPFluid f){
    fluids.push_back(f);
}
void ofxSPWorld::addAutomata(ofxSPAutomata a){
    automatas.push_back(a);
}
void ofxSPWorld::removeAutomata(ofxSPAutomata *a){
    for(int i=0;i<automatas.size();i++)
    {
        if(&(automatas.at(i))==a)
        {
            automatas.erase(automatas.begin()+i);
            return;
        }
    }
}
void ofxSPWorld::applyGlobalForce(ofVec2f f){
    for(int i=0;i<automatas.size();i++)
    {
       
            automatas.at(i).applyForce(f);
        
    }
}

void ofxSPWorld::changeGravity(ofVec2f newGravity){
    g=newGravity;
}
void ofxSPWorld::display(){
    for(int i=0;i<automatas.size();i++)
    {
        automatas.at(i).display();
    }
}
