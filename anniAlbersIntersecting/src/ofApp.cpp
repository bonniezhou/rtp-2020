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
    
    ofSetColor(lightBlue);
    ofSetLineWidth(5);
    int colWidth = numColsInCell * threadWidth;
    
    int x = originX + 20 * colWidth;
    int y = originY + 12 * threadHeight + 2;
    drawSnake(x, y, x - 2 * colWidth, x + colWidth, 11, 100);
    
    drawWarp(originX, originY);
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

void ofApp::drawSnake(int x1, int y1, int minX, int maxX, int height, int seed) {
    ofSeedRandom(seed);
    float x2;
    float y2;
    for (int i = 0; i < height; i++) {
        int lineLength = ofRandom(3*3, maxX - minX);
        x2 = i % 2 == 0 ? MAX(minX, x1 - lineLength) : MIN(maxX, x1 + lineLength);
        y2 = y1;
        ofDrawLine(x1, y1, x2, y2);

        if (i == height - 1) {
            return;
        }
        x1 = x2;
        y1 = y2 + 10;
        ofDrawLine(x2, y2, x1, y1);
    }
}

void ofApp::drawWarp(float xpos, float ypos) {
    int x = xpos;
    int y = ypos;
    for (int i = 0; i < numCols; i++) {
        if (i % 2 == 0) {
            ofSetColor(orange);
        } else if ((i + 1) % 4 == 0) {
            ofSetColor(white);
        } else {
            ofSetColor(navy);
        }
        drawWarpCol(x, y);
        x += numColsInCell * threadWidth;
    }
}

void ofApp::drawWarpCol(float xpos, float ypos){
    int x = xpos;
    int y = ypos;
    ofColor startColor;
    ofColor endColor;
    for (int r = 0; r < numRowsInCell * 3; r++) {
        for (int c = 0; c < numColsInCell; c++) {
            if (r % 2 == 0 && c % 2 != 0) {
                ofDrawRectangle(x+1, y, threadWidth-1, threadHeight);
            }
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
