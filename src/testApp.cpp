#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    
    canvasWidth = 1024;
    canvasHeight = 768;
        
    fondo.loadImage("tvSignal.jpg");
    
    // INIT MASK TEMP
    mousePosLayer.allocate(canvasWidth, canvasHeight);
    mousePosLayer.begin();
    ofClear(0, 0, 0);
    mousePosLayer.end();
    
    
    maskPx.allocate(canvasWidth, canvasHeight, OF_IMAGE_COLOR_ALPHA);
    finalCanvas.allocate(canvasWidth, canvasHeight, OF_IMAGE_COLOR_ALPHA);
    
    backLayer.allocate(canvasWidth, canvasHeight);
    
    //------ KINECT INIT
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    if(kinect.isConnected()) {
		ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
		ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
		ofLogNotice() << "zero plane pixel size : " << kinect.getZeroPlanePixelSize() << "mm";
		ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
	}
    
    //kinect.setCameraTiltAngle(15);
    
    kinectDepth.allocate(kinect.width, kinect.height);
    
    //------
    
    // FBO FOR KINECT BUFFER
    kinectDepthBuffer.allocate(kinect.width, kinect.height);
    
    maskShader.load("maskShader");

    

}

//--------------------------------------------------------------
void testApp::update(){
    
    /*
    mousePosLayer.begin();
    ofSetColor(255);
    ofCircle(mouseX, mouseY, 50);
    mousePosLayer.end();
    */
    
    ofSetColor(255);
    
    // DRAWING ONTO BACKGROUND
    
    backLayer.begin();
    ofClear(0);
    ofSetColor(255);
    fondo.draw(0,0);
    backLayer.end();
    
    
    // DRAWING ONTO KINECT FBO

    kinect.update();
    if(kinect.isFrameNew()) {
        kinectDepth.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
        kinectDepth.mirror(true, true);
 
    
        kinectDepthBuffer.begin();
        ofClear(0);
        kinectDepth.draw(0,0);
        kinectDepthBuffer.end();
    }
   
    
    
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    ofBackground(100);

    /*
    pxFinalCanvas = finalCanvas.getPixels();
    
    
    mousePosLayer.readToPixels(maskPx);
    pxMask = maskPx.getPixels();
    
    
    
    for (int x=0; x < canvasWidth; x++) {
        for (int y=0; y < canvasHeight; y++) {
            
            
            int loc = x + (y * canvasWidth);
            
            //cout << loc << endl;
            
            int brightness = int(pxMask[loc * 4]);
            
            if (brightness > 250) {
                pxFinalCanvas[loc * 4 + 0] = fondo.getPixels()[loc * 3 + 0];
                pxFinalCanvas[loc * 4 + 1] = fondo.getPixels()[loc * 3 + 1];
                pxFinalCanvas[loc * 4 + 2] = fondo.getPixels()[loc * 3 + 2];
                pxFinalCanvas[loc * 4 + 3] = 255;
            }
        }
    }
    
    finalCanvas.update();
    finalCanvas.draw(0,0);
    
    fondo.draw(0,0, 200,200);
    mousePosLayer.draw(200, 0, 200,200);
     */
    
    //--------
    
    
    /*
    maskShader.begin();
    
    ofSetColor(0);
    

    maskShader.setUniform2f("mouse", mouseX * 1.0, mouseY * 1.0);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    
    maskShader.end();
    */
    
    //cout << mouseX << endl;
    
    //mousePosLayer.draw(0, 0);
    //kinectDepth.draw(0,0);
    
        
    float horizontalProportion = kinectDepthBuffer.getWidth() / backLayer.getWidth() ;
    float verticalProportion = kinectDepthBuffer.getHeight() / backLayer.getHeight();
    
    /*
    backLayer.begin();
    ofClear(0);
    ofSetColor(255);
    fondo.draw(0,0);
    backLayer.end();
    */
    
    maskShader.begin();
    
    maskShader.setUniform2f("scaling", horizontalProportion , verticalProportion);
    //maskShader.setUniform2f("mouse", mouseX / float(canvasWidth) , mouseY / float(canvasHeight));
    
    maskShader.setUniformTexture("backTex", backLayer.getTextureReference(), 0);
    maskShader.setUniformTexture("depthTex", kinectDepthBuffer.getTextureReference(), 1);
    
    //maskShader.setUniform1f("time", ofGetFrameNum() * 0.5);
    //maskShader.setUniform2f("resolution", float(canvasWidth), float(canvasHeight));
    
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    maskShader.end();
    
    //kinectDepthBuffer.draw(canvasWidth - kinect.getWidth(), canvasHeight - kinect.getHeight());
    //backLayer.draw(canvasWidth - kinect.getWidth(), canvasHeight - kinect.getHeight(), 128, 96);
    
    //backLayer.draw(0,0);
    
    
    
}   

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == OF_KEY_UP) {
        kinect.setCameraTiltAngle(kinect.getCurrentCameraTiltAngle() + 5);
        cout << "Angle + 5" << endl;
    }
    if (key == OF_KEY_DOWN) {
        kinect.setCameraTiltAngle(kinect.getCurrentCameraTiltAngle() - 5);
        cout << "Angle - 5" << endl;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
