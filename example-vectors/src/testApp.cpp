#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    mover=new ofxSPAutomata(1);
    mover1=new ofxSPAutomata(3);
    
    gravity=ofVec2f(0,0.1);
    
}

//--------------------------------------------------------------
void testApp::update(){
    //ofSaveFrame();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    mover->update();
    mover->checkEdges();
    mover->display();
    mover->applyGravity(gravity);

    
    mover1->update();
    mover1->checkEdges();
    mover1->display();
    mover1->applyGravity(gravity);
   
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='a')
    {
        gravity=ofVec2f(0,-0.01);
    }
    else if(key=='b')
    {
        gravity=ofVec2f(0,0.01);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}