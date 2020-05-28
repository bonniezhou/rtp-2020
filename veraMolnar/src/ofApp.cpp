#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(227,223,216);
    ofSetLineWidth(0.2);
    ofNoFill();
    
    origin = 100;
    width = 60;
    gap = 5;
    margin = 12;
    colors[0].set(202,99,20); // orange
    colors[1].set(4,0,26);    // purple
    colors[2].set(63,24,7);   // brown
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    for (int i = 0; i < 9; i++) {
        int numSquares;
        if (i <= 4) {
            numSquares = pow(2, i);
        } else if (i ==5) {
            numSquares = 24;
        }else if (i == 6) {
            numSquares = 8;
        } else if (i == 7) {
            numSquares = 2;
        } else if (i == 8) {
            numSquares = 1;
        }
        
        for (int j = 0; j < 6; j++) {
            ofSetColor(colors[(int)ofRandom(0, 3)]);
            
            for (int n = 0; n < numSquares; n++) {
                drawSquare(i, j);
            }
        }
    }
}

void ofApp::drawSquare(int i, int j) {
    float x1 = origin + (width + gap)*i + ofRandom(-margin, margin);
    float y1 = origin + (width + gap)*j + ofRandom(-margin, margin);
    
    float x2 = x1 + width + ofRandom(-margin, margin);
    float y2 = y1 + ofRandom(-margin, margin);
    
    float x3 = x2 + ofRandom(-margin, margin);
    float y3 = y1 + width + ofRandom(-margin, margin);
    
    float x4 = x1 + ofRandom(-margin, margin);
    float y4 = y3 + ofRandom(-margin, margin);
    
    ofDrawLine(x1, y1, x2, y2);
    ofDrawLine(x2, y2, x3, y3);
    ofDrawLine(x3, y3, x4, y4);
    ofDrawLine(x4, y4, x1, y1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
