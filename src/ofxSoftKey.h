/*
 *  ofxSoftKey.h
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Modified by Elie Zananiri on 14/06/04.
 *  
 */

#pragma once

#define OFXSK_PADDING_TOP		0
#define OFXSK_PADDING_RIGHT		1
#define OFXSK_PADDING_BOTTOM	2
#define OFXSK_PADDING_LEFT		3

#define OFXSK_KEY_CAPS 10002

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

//--------------------------------------------------------------
class ofxSoftKey
: public ofxMSAInteractiveObject
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
    
    ofxSoftKey& setModifier(bool bModifier);
    
	ofxSoftKey& setTextColor(const ofColor& c);
	ofxSoftKey& setTextBGColor(const ofColor& c);
	ofxSoftKey& setBorderColor(const ofColor& c);
	ofxSoftKey& setHoverColor(const ofColor& c);
	
	//void setup();
	//void update();
	void draw(ofTrueTypeFont* font = NULL);
	//void exit();
	
	//void onRollOver(int x, int y);
	//void onRollOut();
	//void onMouseMove(int x, int y);
	//void onDragOver(int x, int y, int button);
	//void onDragOutside(int x, int y, int button);
	void onPress(int x, int y, int button);
	void onRelease(int x, int y, int button);
	void onReleaseOutside(int x, int y, int button);
	//void keyPressed( int key );
	//void keyReleased( int key );

protected:
    void init(int key0, int key1);
    	
    int key[2];
	string label[2];
    bool bModifier;
    
	ofColor textColor, textBGColor, borderColor, hoverColor;

};
