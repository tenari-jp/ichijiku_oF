#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cout << "setup" << endl;
	ofSetFullscreen(true);
	frame.setup(720, 1280);
	frame.setFromDir("cone", 1);
	cout << "GLES information =====" << endl;
	GLint r;
	glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &r);
	cout << "render :" << r << endl;

	an.setup();
	valueSmooth = ofMap(an.update(), 0, 1023, 0, 1, true);
}

//--------------------------------------------------------------
void ofApp::update(){
//	cout << an.update() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	float val = ofMap(an.update(), 0, 1023, 0, 1, true);
	valueSmooth += (val - valueSmooth) / 5.0;

	frame.draw(valueSmooth);
	ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 30, 30);
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
