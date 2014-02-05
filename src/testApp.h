#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxKinect.h"


class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
ofImage fondo;

ofxCvColorImage colorImage;
ofxCvGrayscaleImage grayImage;
ofxCvGrayscaleImage whiteMask;
ofxCvColorImage paintImage;
    
    
    ofxKinect kinect;
    ofxCvGrayscaleImage kinectDepth;
    ofFbo backLayer;
    ofFbo kinectDepthBuffer;
    
    ofxCvContourFinder kinectContours;
    vector <ofPolyline> downSampledContour;
    
    float nearThreshold, farThreshold;


int canvasWidth, canvasHeight;
    
    ofShader maskShader;



};
