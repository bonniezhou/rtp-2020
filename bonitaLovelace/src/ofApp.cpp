#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    dim = 250;
    // all photos have a 1.25 aspect ratio so this is hard coded to center
    gap = (1.25*dim - dim) / 2;
    
    bordelle = getAverage(getImages("bordelle"));
    bracli = getAverage(getImages("bracli"));
    creepyyeha = getAverage(getImages("creepyyeha"));
    elma = getAverage(getImages("elma"));
    eob = getAverage(getImages("eob"));
    fortnight = getAverage(getImages("fortnight"));
    qos = getAverage(getImages("qos"));
    studiopia = getAverage(getImages("studiopia"));
    tarynwinters = getAverage(getImages("tarynwinters"));
}

// Returns a vector of resized images.
vector < ofImage > ofApp::getImages(string dirName) {
    ofDirectory dir;
    dir.listDir(dirName);
    
    vector < ofImage > images;
    for (int i = 0; i < dir.size(); i++) {
        // load all images from directory into vector
        ofImage img;
        img.load(dir.getPath(i));
        images.push_back(img);
        cout << dirName << ": loaded " << i << " of " << dir.size() << endl;

        ofRectangle targetDim(0,gap,dim,dim);
        ofRectangle imageDim(0,0,images.back().getWidth(),
                             images.back().getHeight());
        
        // crop to square
        targetDim.scaleTo(imageDim);
        images.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
        
        // resize to dim
        images.back().resize(dim,dim);
    }
    return images;
}

// Returns overlaid "average" image from a vector of images of the same size.
ofImage ofApp::getAverage(vector < ofImage > images) {
    ofImage img;
    
    img.allocate(dim,dim, OF_IMAGE_COLOR);
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            // calculate RGB sums
            float r = 0;
            float g = 0;
            float b = 0;
            for (int k = 0; k < images.size(); k++){
                ofColor color = images[k].getColor(i,j);
                r += color.r;
                g += color.g;
                b += color.b;
            }

            // calculate RGB averages
            r /= (float)images.size();
            g /= (float)images.size();
            b /= (float)images.size();
            img.setColor(i,j, ofColor(r, g, b));
        }
    }
    img.update();
    
    return img;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    bordelle.draw(0, 0);
    bracli.draw(dim, 0);
    creepyyeha.draw(dim * 2, 0);
    elma.draw(0, dim);
    eob.draw(dim, dim);
    fortnight.draw(dim * 2, dim);
    qos.draw(0, dim * 2);
    studiopia.draw(dim, dim * 2);
    tarynwinters.draw(dim * 2, dim * 2);
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
