#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    int dim;
    vector < ofPoint > points;
        
    ofImage beySrc;
    ofImage gambinoSrc;
    ofImage jheneSrc;
    ofImage khalidSrc;
    ofImage nickiSrc;
    ofImage weekndSrc;
    
    ofImage beyDest;
    ofImage gambinoDest;
    ofImage jheneDest;
    ofImage khalidDest;
    ofImage nickiDest;
    ofImage weekndDest;
    
    vector < ofColor > getColors(ofImage source);
    void setDiagonalPoints(int dim);
    ofImage getSortedDiagonal(vector < ofColor > colors);
    ofImage getSortedHorizontal(vector < ofColor > colors);
    ofImage getSortedVertical(vector < ofColor > colors);
};
