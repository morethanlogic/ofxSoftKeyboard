/*
 *  ofxSoftKey.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Modified by Elie Zananiri on 14/06/04.
 *  
 */

#include "ofxSoftKey.h"

//--------------------------------------------------------------
float ofxSoftKey::scale = 1.0f;

#pragma mark CONSTRUCTORS

//--------------------------------------------------------------
ofxSoftKey::ofxSoftKey(int key)
{
    init(key, toupper(key));
}

//--------------------------------------------------------------
ofxSoftKey::ofxSoftKey(int key0, int key1)
{
    init(key0, key1);
}

//--------------------------------------------------------------
void ofxSoftKey::init(int key0, int key1)
{
	setKey(key0, key1);
    
    bModifier = false;
	
	textColor.set(255);
	textBGColor.set(30);
	borderColor.set(128);
	hoverColor.set(128);
	isLastInRow = false;
	
	disableAppEvents();
	enableMouseEvents();
	
	padding = new int[4];
	setPadding(5, 5, 5, 5);
}

//--------------------------------------------------------------
ofxSoftKey::~ofxSoftKey()
{
	delete [] padding;
}


#pragma mark PADDING

//--------------------------------------------------------------
void ofxSoftKey::setSize(float w, float h)
{
	ofxMSAInteractiveObject::setSize(w * scale, h * scale);
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setPadding(int top, int right, int bottom, int left) {
	padding[OFXSK_PADDING_TOP] = top * scale;
	padding[OFXSK_PADDING_RIGHT] = right * scale;
	padding[OFXSK_PADDING_BOTTOM] = bottom * scale;
	padding[OFXSK_PADDING_LEFT] = left * scale;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padLeft(int left) {
	padding[OFXSK_PADDING_LEFT] += left * scale;
	return *this;
}
	
//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padRight(int right) {
	padding[OFXSK_PADDING_RIGHT] += right * scale;
	return *this;
}



#pragma mark APP EVENTS



//--------------------------------------------------------------
void ofxSoftKey::draw(ofTrueTypeFont* font) {
	
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
	if (font == NULL) {
		ofDrawBitmapString(label[bModifier], x+10, y+height-10);
	}
	else {
		font->drawString(label[bModifier], x+10, y+height-10);
	}

}




#pragma mark SETTERS

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setKey(int key)
{
    return setKey(key, key);
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setKey(int key0, int key1)
{
	key[0] = key0;
    key[1] = key1;
    
    switch (key[0]) {
		case OF_KEY_SHIFT:
			label[0] = "shift";
			label[1] = "SHIFT";
			setSize(115, 40);
			break;
            
		case OF_KEY_TAB:
			label[0] = "tab";
			label[1] = "TAB";
			setSize(70, 40);
			break;
            
		case OFXSK_KEY_CAPS:
			label[0] = "caps";
            label[1] = "CAPS";
			setSize(85, 40);
			break;
            
		case OF_KEY_BACKSPACE:
		case OF_KEY_DEL:
			label[0] = "delete";
            label[1] = "DELETE";
			setSize(85, 40);
			break;
            
		case OF_KEY_RETURN:
			label[0] = "return";
			label[1] = "RETURN";
			setSize(85, 40);
			break;
            
		default:
			label[0] = string(1, key[0]);
			label[1] = string(1, key[1]);
			setSize(40, 40);
			break;
	}
    
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setModifier(bool bModifier)
{
    this->bModifier = bModifier;
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
void ofxSoftKey::onPress(int x, int y, int button)
{	
    ofKeyEventArgs args;
	args.type = ofKeyEventArgs::Pressed;
	args.key = key[bModifier];
	ofNotifyEvent(ofEvents().keyPressed, args, this);
}

//--------------------------------------------------------------
void ofxSoftKey::onRelease(int x, int y, int button)
{
    ofKeyEventArgs args;
	args.type = ofKeyEventArgs::Released;
	args.key = key[bModifier];
	ofNotifyEvent(ofEvents().keyReleased, args, this);
}

//--------------------------------------------------------------
void ofxSoftKey::onReleaseOutside(int x, int y, int button) 
{

}
