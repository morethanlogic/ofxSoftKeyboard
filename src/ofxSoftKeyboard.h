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

#define OFXSK_LAYOUT_KEYPAD 1
#define OFXSK_LAYOUT_KEYBOARD_FULL 2

class ofBaseApp;

class ofxSoftKeyboard   {
public:
	ofxSoftKeyboard();
	~ofxSoftKeyboard();

	void setup( ofBaseApp* app, int layout, ofxSoftKeyFont* font = NULL );
	void setLayout(int layout);
	void setFont(ofxSoftKeyFont* font);
	void addPadding(int top, int right, int bottom, int left);
	void reset();
	void draw(float x, float y);
	ofxSoftKey& addKey(int c);
	void newRow();
	
	
protected:
	
	ofBaseApp* app;
	ofxSoftKeyFont* font;
	vector<ofxSoftKey*> keys;
	
};

#endif