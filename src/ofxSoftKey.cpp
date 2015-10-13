/*
 *  ofxSoftKey.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Modified by Elie Zananiri on 14/06/04.
 *  Modified by Hugues Bruyère on 15/09/28.
 */

#include "ofxSoftKey.h"

//--------------------------------------------------------------
float ofxSoftKey::scale = 1.0f;
ofColor ofxSoftKey::textColor;
ofColor ofxSoftKey::textBGColor;
ofColor ofxSoftKey::borderColor;
ofColor ofxSoftKey::hoverColor;

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
    bIsMouseOver = false;
	
	textColor.set(255);
	textBGColor.set(20);
	borderColor.set(128);
	hoverColor.set(128);
	isLastInRow = false;
	
//	disableAppEvents();
//	enableMouseEvents();
	
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
    if(bIsMouseOver) {
        ofSetColor(hoverColor);
    }
    else {
       ofSetColor(textBGColor);
    }
	ofDrawRectangle(x, y, width, height);
	
	// Draw the outline.
	ofNoFill();
	ofSetColor(borderColor);
	ofDrawRectangle( x, y, width, height );
	
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
			setSize(115 * scale, 40 * scale);
			break;
            
		case OF_KEY_TAB:
			label[0] = "tab";
			label[1] = "TAB";
			setSize(70 * scale, 40 * scale);
			break;
            
		case OFXSK_KEY_CAPS:
			label[0] = "caps";
            label[1] = "CAPS";
			setSize(85 * scale, 40 * scale);
			break;
            
		case OF_KEY_BACKSPACE:
		case OF_KEY_DEL:
			label[0] = "delete";
            label[1] = "DELETE";
			setSize(85 * scale, 40 * scale);
			break;
            
		case OF_KEY_RETURN:
			label[0] = "return";
			label[1] = "RETURN";
			setSize(85 * scale, 40 * scale);
			break;
            
        case OFXSK_KEY_DOTCOM:
            label[0] = ".com";
            label[1] = ".COM";
            setSize(85 * scale, 40 * scale);
            break;
            
		default:
			label[0] = string(1, key[0]);
			label[1] = string(1, key[1]);
			setSize(40 * scale, 40 * scale);
			break;
	}
    
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setModifier(bool val)
{
    this->bModifier = val;
    return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setIsMouseOver(bool val)
{
    this->bIsMouseOver = val;
    return *this;
}

//--------------------------------------------------------------
bool ofxSoftKey::isMouseOver()
{
    return bIsMouseOver;
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
    bIsMouseOver = true;
    
    ofKeyEventArgs args;
    args.type = ofKeyEventArgs::Pressed;
    args.key = key[bModifier];
    
    switch (key[0]) {
        case OFXSK_KEY_DOTCOM:
            args.key = 46;
            ofNotifyEvent(ofEvents().keyPressed, args, this);
            args.key = 99;
            ofNotifyEvent(ofEvents().keyPressed, args, this);
            args.key = 111;
            ofNotifyEvent(ofEvents().keyPressed, args, this);
            args.key = 109;
            ofNotifyEvent(ofEvents().keyPressed, args, this);
            
            return;
            break;
    }

	ofNotifyEvent(ofEvents().keyPressed, args, this);
}

//--------------------------------------------------------------
void ofxSoftKey::onRelease(int x, int y, int button)
{
    bIsMouseOver = false;
    
    ofKeyEventArgs args;
	args.type = ofKeyEventArgs::Released;
	args.key = key[bModifier];
    
    switch (key[0]) {
        case OFXSK_KEY_DOTCOM:
            args.key = 46;
            ofNotifyEvent(ofEvents().keyReleased, args, this);
            args.key = 99;
            ofNotifyEvent(ofEvents().keyReleased, args, this);
            args.key = 111;
            ofNotifyEvent(ofEvents().keyReleased, args, this);
            args.key = 109;
            ofNotifyEvent(ofEvents().keyReleased, args, this);
            
            return;
            break;
    }
    
	ofNotifyEvent(ofEvents().keyReleased, args, this);
}

