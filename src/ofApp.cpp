#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFullscreen(true);
	frame.setup(720, 1280);
	frame.setFromDir("cone", 1);
	an.setup();
	valueSmooth = ofMap(an.update(), 0, 1023, 0, 1, true);
	recv.setup(12400);
}

//--------------------------------------------------------------
void ofApp::update(){

	while (recv.hasWaitingMessages())
	{
		ofxOscMessage m;
		recv.getNextMessage(m);
		cout << m.getAddress() << endl;
		if (m.getAddress() == "/load")
		{
			frame.setFromDir(m.getArgAsString(0), 1);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	if (frame.loading)
	{
		float loadin = frame.loadUpdate();
		ofSetColor(255);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight() * loadin);
		if (loadin == 1)
		{
			valueSmooth = ofMap(an.update(), 0, 1023, 0, 1, true);
		}
	}
	else
	{
		ofSetColor(255);
		float val = ofMap(an.update(), 0, 1023, 0, 1, true);
		valueSmooth += (val - valueSmooth) / 5.0;
		frame.draw(valueSmooth);
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
