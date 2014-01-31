#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	myShader.loadShader("myShader");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	myShader.setShaderActive(true);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	glTranslatef(ofGetWidth()/2.0, ofGetHeight()/2.0, 0);
	glutSolidTeapot(130);
	glPopMatrix();	
	glDisable(GL_DEPTH_TEST);
	myShader.setShaderActive(false);
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

