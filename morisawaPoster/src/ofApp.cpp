#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofTrueTypeFontSettings settings("MPLUS1p-Black.ttf", 100);
    settings.antialiased = true;
    settings.contours = true;
//    settings.dpi = 72;
    settings.addRanges(ofAlphabet::Japanese);
    font.load(settings);
    ofSetBackgroundColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int color = 50;
    float ypos = 760;
    float scale = 0.025;
    for (int i = 0; i < 70; i++) {
        drawMorisawa(color, ypos, scale);
        if (i < 3) {
            color += 4;
            ypos -= 3;
        } else if (i < 10) {
            color += 4;
            ypos -= i;
        } else {
            color += 3;
            ypos -= 10;
        }
        scale += 0.025;
    }

    drawMorisawa(20, ypos, 1);
}

void ofApp::drawMorisawa(int color, float ypos, float scale) {
    string text = "モリサワ";
    vector < ofPath > paths = font.getStringAsPoints(text);
    
    ofSetColor(color);
    ofPushMatrix();
        ofScale(1, scale, 1);
        ofTranslate(0, ypos*(1/scale));
        for (int i = 0; i < paths.size(); i++) {
            paths[i].draw();
        }
    ofPopMatrix();
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
