#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	
	messageFont.loadFont("vag.ttf", 32, true, true);
	keyboardFont.loadFont("vag.ttf", 12, true, true);
	
	layout = OFXSK_LAYOUT_KEYBOARD_FULL;
	keyboard.setup(layout, &keyboardFont);
	bUseKeyboardFont = true;

	sprintf(eventString, "framerate: %f\nright-click to toggle font", ofGetFrameRate());
	
	message = "";
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	keyboard.draw(100, 350);
	
	float w = messageFont.stringWidth(eventString);
	float h = messageFont.stringHeight(eventString);
	
	ofSetHexColor(0xffffff);
	messageFont.drawString(eventString, 98,198);
	
	ofSetColor(255,122,220);
	messageFont.drawString(eventString, 100,200);
	

	ofSetHexColor(0xffffff);
	messageFont.drawString(message, 98,298);
	
	ofSetColor(255,122,220);
	messageFont.drawString(message, 100,300);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	sprintf(eventString, "keyPressed = %c (ASCII %i)", key, key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
	
	if (key == OF_KEY_RIGHT) {
		layout = (ofxSoftKeyboardLayout)((layout + 1) % (int)OFXSK_NUM_LAYOUTS);
		keyboard.setLayout(layout);
		return;
	}
	else if (key == OF_KEY_LEFT) {
		layout = (ofxSoftKeyboardLayout)(layout - 1);
		if (layout < 0) layout = (ofxSoftKeyboardLayout)(layout + OFXSK_NUM_LAYOUTS);
		keyboard.setLayout(layout);
		return;
	}
	
	sprintf(eventString, "keyReleased = %c (ASCII %i)", key, key);
	
	if(key == OF_KEY_BACKSPACE || key == OF_KEY_DEL) {
		message = message.substr(0, message.size()-1);
	} 
	else {
		message += (char)key;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	if (button == 2) {
		bUseKeyboardFont ^= 1;
		keyboard.setFont(bUseKeyboardFont? &keyboardFont : NULL);
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

