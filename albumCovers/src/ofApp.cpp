#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // hard-coded, each image is 640 x 640
    dim = 640;
    
    // set vector of diagonal points
    setDiagonalPoints(dim);
    
    // load & allocate images
    beySrc.load("lemonade.jpg");
    beyDest = getSortedDiagonal(getColors(beySrc));
    jheneSrc.load("chilombo.jpg");
    jheneDest = getSortedDiagonal(getColors(jheneSrc));
    
    khalidSrc.load("freespirit.jpg");
    khalidDest = getSortedHorizontal(getColors(khalidSrc));
    weekndSrc.load("starboy.jpg");
    weekndDest = getSortedHorizontal(getColors(weekndSrc));
    
    nickiSrc.load("queen.jpg");
    nickiDest = getSortedVertical(getColors(nickiSrc));
    gambinoSrc.load("becausetheinternet.jpg");
    gambinoDest = getSortedVertical(getColors(gambinoSrc));
}

vector < ofColor > ofApp::getColors(ofImage source) {
    vector < ofColor > colors;
    
    // get all colors from source image
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            colors.push_back(source.getColor(i, j));
        }
    }
    // sort colors in place
    sort(colors.begin(), colors.end(),
        [](const ofColor a, const ofColor b) -> bool
    {
        return a.getBrightness() > b.getBrightness();
    });
    
    return colors;
}

void ofApp::setDiagonalPoints(int dim) {
    // create vector of points representing pixels in diagonal order
    int k = 0;
    while (k < dim) {
        int i = 0;
        int j = k - i;
        while (j >= 0) {
            points.push_back(ofPoint(i, j));
            cout << points.back() << endl;

            i += 1;
            j -= 1;
        }
        k += 1;
    }
    int s = 1;
    while (s < dim) {
        int i = s;
        int j = k - i;
        while (j >= s) {
            points.push_back(ofPoint(i, j));
            cout << points.back() << endl;

            i += 1;
            j -= 1;
        }
        s += 1;
        k += 1;
    }
}

ofImage ofApp::getSortedDiagonal(vector < ofColor > colors) {
    ofImage sorted;
    
    sorted.allocate(dim, dim, OF_IMAGE_COLOR);
    // set pixel to corresponding color in diagonal order
    int c = 0;
    for (int p = 0; p < points.size(); p++) {
        sorted.setColor(points[p].x, points[p].y, colors[c]);
        c += 1;
    }
    sorted.update();
    
    return sorted;
}

ofImage ofApp::getSortedHorizontal(vector < ofColor > colors) {
    ofImage sorted;
    
    sorted.allocate(dim, dim, OF_IMAGE_COLOR);
    // set pixel to corresponding color in horizontal order
    int k = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            sorted.setColor(j, i, colors[k]);
            k += 1;
        }
    }
    sorted.update();
    
    return sorted;
}

ofImage ofApp::getSortedVertical(vector < ofColor > colors) {
    ofImage sorted;
    
    sorted.allocate(dim, dim, OF_IMAGE_COLOR);
    // set pixel to corresponding color in vertical order
    int k = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            sorted.setColor(i, j, colors[k]);
            k += 1;
        }
    }
    sorted.update();
    
    return sorted;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofScale(.4, .4);
    
    jheneDest.draw(0, 0);
    weekndDest.draw(dim, 0);
    gambinoDest.draw(0, dim);
    beyDest.draw(dim, dim);
    khalidDest.draw(0, dim * 2);
    nickiDest.draw(dim, dim * 2);
    
    jheneSrc.draw(dim * 2, 0);
    weekndSrc.draw(dim * 3, 0);
    gambinoSrc.draw(dim * 2, dim);
    beySrc.draw(dim * 3, dim);
    khalidSrc.draw(dim * 2, dim * 2);
    nickiSrc.draw(dim * 3, dim * 2);
    
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
