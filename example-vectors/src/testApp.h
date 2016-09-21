#pragma once

#include "ofMain.h"
#import "ofxSimplePhysics.h"
#import "ofxSPAutomata.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        ofxSPAutomata *mover;
        ofxSPAutomata *mover1;
        ofxSPAutomata *mover2;
        ofxSPAutomata *mover3;
    
        ofVec2f gravity;
    
};
