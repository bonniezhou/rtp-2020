#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    orange = ofColor(216, 86, 45);
    navy = ofColor(15, 40, 76);
    white = ofColor(220, 207, 200);
    lightBlue = ofColor(76, 104, 162);
    numCols = 33;
    
    numColsInCell = 8;
    numRowsInCell = 44;
    threadWidth = 3;
    threadHeight = 5;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int originX = 10;
    int originY = 50;
    drawRow(originX, originY, orange);
    drawRow(originX, originY + threadHeight * numRowsInCell, lightBlue);
    drawRow(originX, originY + threadHeight * numRowsInCell * 2, orange);
}

void ofApp::drawRow(float xpos, float ypos, ofColor weft) {
    ofColor warp;
    int x = xpos;
    int y = ypos;
    for (int i = 0; i < numCols; i++) {
        if (i % 2 == 0) {
            warp = orange;
        } else if ((i + 1) % 4 == 0) {
            warp = white;
        } else {
            warp = navy;
        }
        drawCell(x, y, warp, weft);
        x += numColsInCell * threadWidth;
    }
}

void ofApp::drawCell(float xpos, float ypos, ofColor warp, ofColor weft){
    int x = xpos;
    int y = ypos;
    ofColor startColor;
    ofColor endColor;
    for (int r = 0; r < numRowsInCell; r++) {
        if (r % 2 == 0) {
            startColor = weft;
            endColor = warp;
        } else {
            startColor = warp;
            endColor = weft;
        }
        for (int c = 0; c < numColsInCell; c++) {
            if (c % 2 == 0) {
                ofSetColor(startColor);
            } else {
                ofSetColor(endColor);
            }
            ofDrawRectangle(x, y, threadWidth, threadHeight);
            x += threadWidth;
        }
        x = xpos;
        y += threadHeight;
    }
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
