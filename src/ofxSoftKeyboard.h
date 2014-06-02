/*
 *  ofxSoftKeyboard.h
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */


#ifndef _OFX_SOFTKEYBOARD
#define _OFX_SOFTKEYBOARD

#include "ofMain.h"
#include "ofxSoftKey.h"

enum ofxSoftKeyboardLayout
{
	OFXSK_LAYOUT_KEYPAD = 0,
	OFXSK_LAYOUT_KEYBOARD_FULL,
	OFXSK_LAYOUT_KEYBOARD_FULL_FRENCH,
	OFXSK_LAYOUT_KEYBOARD_FORM,
	OFXSK_LAYOUT_KEYBOARD_FORM_FRENCH,

	OFXSK_NUM_LAYOUTS
};

class ofBaseApp;

class ofxSoftKeyboard   {
public:
	ofxSoftKeyboard();
	~ofxSoftKeyboard();

	void setup( ofBaseApp* app, ofxSoftKeyboardLayout layout, ofTrueTypeFont* font = NULL );
	void setLayout(ofxSoftKeyboardLayout layout);
	void setFont(ofTrueTypeFont* font);
	void addPadding(int top, int right, int bottom, int left);
	void reset();
	void draw(float x, float y);
	ofxSoftKey& addKey(int c);
	void newRow();
	
	
protected:
	
	ofBaseApp* app;
	ofTrueTypeFont* font;
	vector<ofxSoftKey*> keys;
	
};

#endif