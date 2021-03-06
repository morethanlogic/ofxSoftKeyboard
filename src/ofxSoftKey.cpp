/*
 *  ofxSoftKey.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxSoftKey.h"
#include "ofBaseApp.h"


#pragma mark CONSTRUCTORS

//--------------------------------------------------------------
ofxSoftKey::ofxSoftKey(int _key, ofBaseApp* _app) {
	
	app = _app;
	key = _key;
	
	
	
	textColor.setHex(0x000000);
	textBGColor.setHex(0xCCCCCC);
	borderColor.setHex(0x000000);
	hoverColor.setHex(0x999999);
	clickColor.setHex(0xFF0000);
	isLastInRow = false;
	
	disableAppEvents();
	enableMouseEvents();
	
	padding = new int[4];
	setPadding(5, 5, 5, 5);

	switch(_key) {
		case OFXSK_KEY_SHIFT:
			label = "shift";
			setSize(115, 40);
			break;
		case OFXSK_KEY_TAB: 
			label = "tab";
			setSize(70, 40);
			break;
		case OFXSK_KEY_CAPS: 
			label = "caps";
			setSize(85, 40);
			break;
		case OFXSK_KEY_DELETE: 
			label = "delete";
			setSize(85, 40);
			break;
		case OFXSK_KEY_RETURN: 
			label = "return";
			setSize(85, 40);
			break;
		default:
			label = string(1, key);
			setSize(40, 40);
			break;
	}
}

//--------------------------------------------------------------
ofxSoftKey::~ofxSoftKey()
{
	delete [] padding;
}


#pragma mark PADDING

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setPadding(int top, int right, int bottom, int left) {
	padding[OFXSK_PADDING_TOP] = top;
	padding[OFXSK_PADDING_RIGHT] = right;
	padding[OFXSK_PADDING_BOTTOM] = bottom;
	padding[OFXSK_PADDING_LEFT] = left;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padLeft(int left) {
	padding[OFXSK_PADDING_LEFT] += left;
	return *this;
}
	
//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padRight(int right) {
	padding[OFXSK_PADDING_RIGHT] += right;
	return *this;
}



#pragma mark APP EVENTS



//--------------------------------------------------------------
void ofxSoftKey::draw() {
	
	// Draw the background
	ofFill();
	if(isMouseOver()) ofSetColor(hoverColor);
	else ofSetColor(textBGColor);
	ofRect(x, y, width, height);
	
	// Draw the outline.
	ofNoFill();
	ofSetColor(borderColor);
	ofRect( x, y, width, height );
	
	// Draw the actual letter
	ofSetColor(textColor);
	ofDrawBitmapString(label, x+10, y+height-10);

}




#pragma mark SETTERS

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setKey(char key) {
	this->key = key;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setTextColor(const ofColor& c) {
	this->textColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setTextBGColor(const ofColor& c) {
	this->textBGColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setBorderColor(const ofColor& c) {
	this->borderColor = c;
	return *this;
}



#pragma mark MOUSE INTERACTION


//--------------------------------------------------------------
void ofxSoftKey::onPress(int x, int y, int button) {
	
	
	switch(key) {
		case OFXSK_KEY_SHIFT:
			
			break;
		case OFXSK_KEY_TAB: 
			app->keyPressed('\t');
			break;
		case OFXSK_KEY_CAPS: 
			
			break;
		case OFXSK_KEY_DELETE: 
			app->keyPressed(OF_KEY_BACKSPACE);
			break;
		case OFXSK_KEY_RETURN: 
			app->keyPressed('\n');
			break;
		default:
			app->keyPressed((int)key);
			break;
	}
	//ofNotifyEvent(ofEvents.keyPressed, (int)key, testapp);
}

//--------------------------------------------------------------
void ofxSoftKey::onRelease(int x, int y, int button) {
	
	switch(key) {
		case OFXSK_KEY_SHIFT:
			
			break;
		case OFXSK_KEY_TAB: 
			app->keyReleased('\t');
			break;
		case OFXSK_KEY_CAPS: 
			
			break;
		case OFXSK_KEY_DELETE: 
			app->keyReleased(OF_KEY_BACKSPACE);
			break;
		case OFXSK_KEY_RETURN: 
			app->keyReleased('\n');
			break;
		default:
			app->keyReleased((int)key);
			break;
	}
	//ofNotifyEvent(ofEvents.keyReleased, (int)key, testapp));
}

//--------------------------------------------------------------
void ofxSoftKey::onReleaseOutside(int x, int y, int button) {

}
