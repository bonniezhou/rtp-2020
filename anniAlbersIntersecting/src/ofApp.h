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
    
    void drawRow(float x, float y, ofColor weft);
    void drawCell(float x, float y, ofColor warp, ofColor weft);
    
    ofColor orange;
    ofColor navy;
    ofColor white;
    ofColor lightBlue;
    int numCols;
    
    int numColsInCell;
    int numRowsInCell;
    int threadWidth;
    int threadHeight;
};
