#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDirectory dir;
    dir.listDir("chocolate");
    
    for (int i = 0; i < dir.size(); i++){
        ofImage img;
        img.load(dir.getPath(i));
        int w = img.getWidth();
        int h = img.getHeight();
        
        // Increase brightness and saturation
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                ofColor color = img.getColor(i, j);
                
                float s = color.getSaturation();
                color.setSaturation(s + 1);
                float b = color.getBrightness();
                color.setBrightness(b + 40);
                
                img.setColor(i, j, color);
            }
        }
        
        // Crop image to 50 x 70
        ofRectangle targetDim(0,0,50,70);
        ofRectangle imageDim(0,0,w,h);
        targetDim.scaleTo(imageDim);
        
        img.crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
        img.resize(50,70);
        
        // New width and heights (50 x 70)
         w = img.getWidth();
         h = img.getHeight();
        
        // Average color of all pixels
        float r = 0;
        float g = 0;
        float b = 0;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                ofColor color = img.getColor(i,j);
                r += color.r;
                g += color.g;
                b += color.b;
            }
        }
        r /= w * h;
        g /= w * h;
        b /= w * h;
        
        images.push_back(img);
        colors.push_back(ofColor(r, g, b));
        cout << "loaded " << i + 1 << " of " << dir.size() << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    float x = (int)(ofGetElapsedTimef() * 10);
    float x = mouseX;
    ofSeedRandom(x);
    
    for (int c = 0; c < colors.size(); c++) {
        if (ofRandom(0, 1) < 0.4) {
            ofSetColor(colors[c]);
            ofDrawRectangle((c / 10) * 50, (c % 10) * 70, 50, 70);
        } else {
            images[c].draw((c / 10) * 50, (c % 10) * 70);
        }
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
