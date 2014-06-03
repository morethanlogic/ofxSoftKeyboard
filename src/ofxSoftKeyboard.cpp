/*
 *  ofxSoftKeyboard.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxSoftKeyboard.h"

ofxSoftKeyboard::ofxSoftKeyboard() {
	
}

//--------------------------------------------------------------
ofxSoftKeyboard::~ofxSoftKeyboard() {
	reset();
}

//--------------------------------------------------------------
void ofxSoftKeyboard::setup( ofBaseApp* _app, ofxSoftKeyboardLayout layout, ofTrueTypeFont* font ) {
	
	app = _app;
	setLayout(layout);
	setFont(font);
    
    bShiftModifier = false;
	bCapsModifier = false;
}

//--------------------------------------------------------------
void ofxSoftKeyboard::setFont(ofTrueTypeFont* _font) {

	font = _font;
}

//--------------------------------------------------------------
void ofxSoftKeyboard::setLayout(ofxSoftKeyboardLayout _layout) {
	
	reset();
	
	layout = _layout;

	switch(layout) {
	
		case OFXSK_LAYOUT_KEYPAD:
			addKey('1'); addKey('2'); addKey('3'); newRow();
			addKey('4'); addKey('5'); addKey('6'); newRow();
			addKey('7'); addKey('8'); addKey('9'); newRow();
			addKey('*'); addKey('0'); addKey('#');
			break;
			
		case OFXSK_LAYOUT_KEYBOARD_FULL:
			addKey('`', '~'); addKey('1', '!'); addKey('2', '@'); addKey('3', '#'); addKey('4', '$'); addKey('5', '%'); addKey('6', '^'); addKey('7', '&'); addKey('8', '*'); addKey('9', '('); addKey('0', ')'); addKey('-', '_'); addKey('=', '+'); addKey(OFXSK_KEY_DELETE); newRow();
			addKey(OFXSK_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('[', '{'); addKey(']', '}'); addKey('\\', '|'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';', ':'); addKey('\'', '"'); addKey(OFXSK_KEY_RETURN); newRow();
			addKey(OFXSK_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(',', '<'); addKey('.', '>'); addKey('/', '?'); addKey(OFXSK_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;

		case OFXSK_LAYOUT_KEYBOARD_FULL_FRENCH:
			addKey('~'); addKey('1'); addKey('2'); addKey('3'); addKey('4'); addKey('5'); addKey('6'); addKey('7'); addKey('8'); addKey('9'); addKey('0'); addKey('-'); addKey('+'); addKey(OFXSK_KEY_DELETE); newRow();
			addKey('�').padLeft(52); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); newRow();
			addKey(OFXSK_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('['); addKey(']'); addKey('|'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OFXSK_KEY_RETURN); newRow();
			addKey(OFXSK_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('/'); addKey(OFXSK_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;

		case OFXSK_LAYOUT_KEYBOARD_FORM:
			addKey('@'); addKey('1'); addKey('2'); addKey('3'); addKey('4'); addKey('5'); addKey('6'); addKey('7'); addKey('8'); addKey('9'); addKey('0'); addKey('-'); addKey('+'); addKey(OFXSK_KEY_DELETE); newRow();
			addKey(OFXSK_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('_'); addKey('*'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OFXSK_KEY_RETURN); newRow();
			addKey(OFXSK_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('/'); addKey(OFXSK_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;

		case OFXSK_LAYOUT_KEYBOARD_FORM_FRENCH:
			addKey('@'); addKey('1'); addKey('2'); addKey('3'); addKey('4'); addKey('5'); addKey('6'); addKey('7'); addKey('8'); addKey('9'); addKey('0'); addKey('-'); addKey('+'); addKey(OFXSK_KEY_DELETE); newRow();
			//addKey('�').padLeft(52); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); addKey('�'); newRow();
			addKey(OFXSK_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('_'); addKey('*'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OFXSK_KEY_RETURN); newRow();
			addKey(OFXSK_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('/'); addKey(OFXSK_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;
	}
}

//--------------------------------------------------------------
void ofxSoftKeyboard::reset() {
	for(int i=0; i<keys.size(); i++) {
		delete keys[i];
	}
	keys.clear();
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKeyboard::addKey(int key0)
{
	ofxSoftKey* key = new ofxSoftKey(key0, this);
	key->setPadding(6, 6, 6, 6);
	keys.push_back(key);
	return *keys.back();
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKeyboard::addKey(int key0, int key1)
{
    ofxSoftKey* key = new ofxSoftKey(key0, key1, this);
	key->setPadding(6, 6, 6, 6);
	keys.push_back(key);
	return *keys.back();
}

//--------------------------------------------------------------
void ofxSoftKeyboard::newRow() {
	
	keys.back()->isLastInRow = true;
}

//--------------------------------------------------------------
void ofxSoftKeyboard::draw(float x, float y) {
	
	int xpos = x;
	int ypos = y;
	
	for(int i=0; i<keys.size(); i++)
	{
		xpos += keys[i]->padding[OFXSK_PADDING_LEFT];
		
		keys[i]->setPosition(xpos, ypos);
		keys[i]->draw(font);
		
		if(keys[i]->isLastInRow) {

			xpos  = x;
			ypos += keys[i]->height + keys[i]->padding[OFXSK_PADDING_BOTTOM];
			
		} else {
			xpos += keys[i]->width + keys[i]->padding[OFXSK_PADDING_RIGHT];
		}
	}
}

//--------------------------------------------------------------
void ofxSoftKeyboard::keyPressed(int key)
{
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
}

//--------------------------------------------------------------
void ofxSoftKeyboard::keyReleased(int key)
{
    switch (key) {
		case OFXSK_KEY_SHIFT:
			bCapsModifier = false;
			bShiftModifier ^= 1;
            for (int i = 0; i < keys.size(); i++) {
                keys[i]->setModifier(bShiftModifier);
            }
            break;
            
		case OFXSK_KEY_TAB:
			app->keyReleased('\t');
			break;
            
		case OFXSK_KEY_CAPS:
			bShiftModifier = false;
			bCapsModifier ^= 1;
            for (int i = 0; i < keys.size(); i++) {
                keys[i]->setModifier(bCapsModifier);
            }
			break;
            
		case OFXSK_KEY_DELETE:
			app->keyReleased(OF_KEY_BACKSPACE);
			break;
            
		case OFXSK_KEY_RETURN:
			app->keyReleased('\n');
			break;
            
		default:
			app->keyReleased((int)key);
            if (bShiftModifier) {
                // Unset shift before returning.
                keyReleased(OFXSK_KEY_SHIFT);
            }
			break;
	}
}
