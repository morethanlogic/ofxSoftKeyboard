/*
 *  ofxSoftKey.h
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Modified by Elie Zananiri on 14/06/04.
 *  Modified by Hugues Bruyère on 15/09/28.
 */

#pragma once

#define OFXSK_PADDING_TOP		0
#define OFXSK_PADDING_RIGHT		1
#define OFXSK_PADDING_BOTTOM	2
#define OFXSK_PADDING_LEFT		3

#define OFXSK_KEY_CAPS 10002

#define OFXSK_KEY_DOTCOM 10100

#include "ofMain.h"

//--------------------------------------------------------------
class ofxSoftKey
: public ofRectangle
{
public:
	bool isLastInRow;
	int* padding;
	
	ofxSoftKey(int key);
	ofxSoftKey(int key0, int key1);
    
	~ofxSoftKey();

	ofxSoftKey& setPadding(int top, int right, int bottom, int left);
	ofxSoftKey& padLeft(int left);
	ofxSoftKey& padRight(int right);
	
	ofxSoftKey& setKey(int key);
    ofxSoftKey& setKey(int key0, int key1);
        
    ofxSoftKey& setModifier(bool val);
    ofxSoftKey& setIsMouseOver(bool val);
    bool isMouseOver();
    
	ofxSoftKey& setTextColor(const ofColor& c);
	ofxSoftKey& setTextBGColor(const ofColor& c);
	ofxSoftKey& setBorderColor(const ofColor& c);
	ofxSoftKey& setHoverColor(const ofColor& c);
	
	void draw(ofTrueTypeFont* font = NULL);

	void onPress(int x, int y, int button);
	void onRelease(int x, int y, int button);

	static float scale;
    static ofColor textColor, textBGColor, borderColor, hoverColor;

protected:
    void init(int key0, int key1);
    	
    int key[2];
	string label[2];
    bool bModifier;
    
    bool bIsMouseOver;
    
	

};
