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
    
    //------
    
    maskShader.load("maskShader");

    

}

//--------------------------------------------------------------
void testApp::update(){
    
    mousePosLayer.begin();
    ofSetColor(0);
    ofCircle(mouseX, mouseY, 50);
    mousePosLayer.end();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

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
    fondo.draw(0,0);
    
    
    maskShader.begin();
    
    ofSetColor(0);
    

    maskShader.setUniform2f("mouse", mouseX * 1.0, mouseY * 1.0);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    
    maskShader.end();
    
    
    cout << mouseX << endl;
    
}   

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
