#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mistakes.load("mistakes.png");
    mistakes2.allocate(mistakes.getWidth(),
                       mistakes.getHeight(),
                       OF_IMAGE_COLOR);

    ofPushMatrix();
    ofScale(0.5, 0.5);
    mistakes.draw(0, 0);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofColor pink = ofColor(252, 210, 245);
    ofColor black = ofColor(0);
    // Set each pixel of mistakes2 to be the color of that pixel in mistakes
    for (int i = 0; i < mistakes.getWidth(); i++) {
        for (int j = 0; j < mistakes.getHeight(); j++) {
            if (mistakes.getColor(i, j).getBrightness() > 150) {
                mistakes2.setColor(i, j, pink);
            } else {
                mistakes2.setColor(i, j, black);
            }
        }
    }
    mistakes2.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofScale(0.5, 0.5);
//    mistakes.draw(0, 0);
    mistakes2.draw(mistakes.getWidth(), 0);
    ofPopMatrix();
}

void ofApp::dilate( ofImage & imgSrc, ofImage & imgDest){
    // assumptions!
    // img1 / img2 same w/h
    // both grayscale / binary images
    ofColor pink = ofColor(252, 210, 245);
    ofColor black = ofColor(0);
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            
            // neighbors
            // edges
            
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);
            
            // neighbor values
            
            ofColor n_ = imgSrc.getColor(i,j_p_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_p_1);
            ofColor e_ = imgSrc.getColor(i_p_1,j);
            ofColor se = imgSrc.getColor(i_p_1,j_m_1);
            ofColor s_ = imgSrc.getColor(i,j_m_1);
            ofColor sw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor nw = imgSrc.getColor(i_m_1,j_p_1);
            
            if (n_.getBrightness() > 127 ||
                ne.getBrightness() > 127 ||
                e_.getBrightness() > 127 ||
                se.getBrightness() > 127 ||
                s_.getBrightness() > 127 ||
                sw.getBrightness() > 127 ||
                w_.getBrightness() > 127 ||
                nw.getBrightness() > 127 ){
                imgDest.setColor(i,j, pink);
            } else {
                imgDest.setColor(i,j, black);
            }
        }
    }
    imgDest.update();
}


void ofApp::erode( ofImage & imgSrc, ofImage & imgDest){
    // assumptions!
    // img1 / img2 same w/h
    // both grayscale / binary images
    ofColor pink = ofColor(252, 210, 245);
    ofColor black = ofColor(0);
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            
            // neighbors
            // edges
            
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);
            
            // neighbor values
            
            ofColor n_ = imgSrc.getColor(i,j_p_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_p_1);
            ofColor e_ = imgSrc.getColor(i_p_1,j);
            ofColor se = imgSrc.getColor(i_p_1,j_m_1);
            ofColor s_ = imgSrc.getColor(i,j_m_1);
            ofColor sw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor nw = imgSrc.getColor(i_m_1,j_p_1);
            
            if (n_.getBrightness() < 127 ||
                ne.getBrightness() < 127 ||
                e_.getBrightness() < 127 ||
                se.getBrightness() < 127 ||
                s_.getBrightness() < 127 ||
                sw.getBrightness() < 127 ||
                w_.getBrightness() < 127 ||
                nw.getBrightness() < 127 ){
                imgDest.setColor(i,j, black);
            } else {
                imgDest.setColor(i,j, pink);
            }
        }
    }
    imgDest.update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'd') {
        dilate(mistakes, mistakes2);
        dilate(mistakes2, mistakes);
    } else if (key == 'e') {
        erode(mistakes, mistakes2);
        erode(mistakes2, mistakes);
    }
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
