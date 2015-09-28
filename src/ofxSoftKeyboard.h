/*
 *  ofxSoftKeyboard.h
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Modified by Elie Zananiri on 14/06/04.
 *  Modified by Hugues Bruyère on 15/09/28.
 */


#pragma once

#include "ofMain.h"
#include "ofxSoftKey.h"

enum ofxSoftKeyboardLayout
{
	OFXSK_LAYOUT_KEYPAD = 0,
	OFXSK_LAYOUT_KEYBOARD_FULL,
	OFXSK_LAYOUT_KEYBOARD_FULL_FRENCH,
	OFXSK_LAYOUT_KEYBOARD_FORM,
	OFXSK_LAYOUT_KEYBOARD_FORM_FRENCH,
	OFXSK_LAYOUT_KEYBOARD_FORM_ALL_CAPS,

	OFXSK_NUM_LAYOUTS
};

class ofxSoftKeyboard   
{
public:
	ofxSoftKeyboard();
	~ofxSoftKeyboard();

	void setup(ofxSoftKeyboardLayout layout = OFXSK_LAYOUT_KEYBOARD_FULL, ofTrueTypeFont* font = NULL);
	void setLayout(ofxSoftKeyboardLayout layout);
	void setFont(ofTrueTypeFont* font);
    void setUsingForwardedMouseEvents(bool val);
	void reset();
	
	void setPadding(int top, int right, int bottom, int left);
	void setDrawFrame(bool bDrawFrame) { this->bDrawFrame = bDrawFrame; }
	void setBorderColor(const ofColor& col) { borderColor = col; }
	void setFillColor(const ofColor& col) { fillColor = col; }

	const ofRectangle& getBounds() { return bounds; }

	void draw(float x, float y);

	ofxSoftKey& addKey(int key0);
	ofxSoftKey& addKey(int key0, int key1);
	void newRow();
    
    void enable();
    void disable();
	
    void keyPressed(ofKeyEventArgs& args);
    void keyReleased(ofKeyEventArgs& args);
    
    void mousePressed(ofMouseEventArgs& args);
    void mouseReleased(ofMouseEventArgs& args);
    
    void mouseMoved(ofMouseEventArgs& args);
    void mouseDragged(ofMouseEventArgs& args);
    
protected:
	ofTrueTypeFont* font;
	vector<ofxSoftKey*> keys;

	ofRectangle bounds;
	int* padding;
	bool bDrawFrame;
	ofColor borderColor;
	ofColor fillColor;

	ofxSoftKeyboardLayout layout;
	bool bShiftModifier;
    bool bCapsModifier;
    
    bool bIsEnabled;
    bool bIsUsingForwardedMouseEvents;
	
};
