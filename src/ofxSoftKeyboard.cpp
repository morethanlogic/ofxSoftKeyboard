/*
 *  ofxSoftKeyboard.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 *  Modified by Elie Zananiri on 14/06/04.
 *  
 */

#include "ofxSoftKeyboard.h"

//--------------------------------------------------------------
ofxSoftKeyboard::ofxSoftKeyboard() {

	ofAddListener(ofEvents().keyPressed, this, &ofxSoftKeyboard::keyPressed);
	ofAddListener(ofEvents().keyReleased, this, &ofxSoftKeyboard::keyReleased);
}

//--------------------------------------------------------------
ofxSoftKeyboard::~ofxSoftKeyboard() {

	ofRemoveListener(ofEvents().keyPressed, this, &ofxSoftKeyboard::keyPressed);
	ofRemoveListener(ofEvents().keyReleased, this, &ofxSoftKeyboard::keyReleased);
	reset();
}

//--------------------------------------------------------------
void ofxSoftKeyboard::setup(ofxSoftKeyboardLayout layout, ofTrueTypeFont* font) {
	
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
			addKey('`', '~'); addKey('1', '!'); addKey('2', '@'); addKey('3', '#'); addKey('4', '$'); addKey('5', '%'); addKey('6', '^'); addKey('7', '&'); addKey('8', '*'); addKey('9', '('); addKey('0', ')'); addKey('-', '_'); addKey('=', '+'); addKey(OF_KEY_DEL); newRow();
			addKey(OF_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('[', '{'); addKey(']', '}'); addKey('\\', '|'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';', ':'); addKey('\'', '"'); addKey(OF_KEY_RETURN); newRow();
			addKey(OF_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(',', '<'); addKey('.', '>'); addKey('/', '?'); addKey(OF_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;

		case OFXSK_LAYOUT_KEYBOARD_FULL_FRENCH:
			addKey('`', '~'); addKey('1', '!'); addKey('2', '@'); addKey('3', '#'); addKey('4', '$'); addKey('5', '%'); addKey('6', '^'); addKey('7', '&'); addKey('8', '*'); addKey('9', '('); addKey('0', ')'); addKey('-', '_'); addKey('=', '+'); addKey(OF_KEY_DEL); newRow();
			addKey('à', 'À').padLeft(52); addKey('â', 'Â'); addKey('ç', 'Ç'); addKey('é', 'É'); addKey('è', 'È'); addKey('ê', 'Ê'); addKey('ë', 'Ë'); addKey('ï', 'Ï'); addKey('î', 'Î'); addKey('ô', 'Ô'); addKey('ù', 'Ù'); addKey('û', 'Û'); addKey('ü', 'Ü'); newRow();
			addKey(OF_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('[', '{'); addKey(']', '}'); addKey('\\', '|'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';', ':'); addKey('\'', '"'); addKey(OF_KEY_RETURN); newRow();
			addKey(OF_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(',', '<'); addKey('.', '>'); addKey('/', '?'); addKey(OF_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;

		case OFXSK_LAYOUT_KEYBOARD_FORM:
			addKey('1').padLeft(52); addKey('2'); addKey('3'); addKey('4'); addKey('5'); addKey('6'); addKey('7'); addKey('8'); addKey('9'); addKey('0'); addKey('-'); addKey('+'); addKey(OF_KEY_DEL); newRow();
			addKey(OF_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('_'); addKey('*'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OF_KEY_RETURN); newRow();
			addKey(OF_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('@'); addKey(OF_KEY_SHIFT); newRow();
			addKey(' ').padLeft(254).setSize(300, 40);
			break;

		case OFXSK_LAYOUT_KEYBOARD_FORM_FRENCH:
			addKey('1').padLeft(52); addKey('2'); addKey('3'); addKey('4'); addKey('5'); addKey('6'); addKey('7'); addKey('8'); addKey('9'); addKey('0'); addKey('-'); addKey('+'); addKey(OF_KEY_DEL); newRow();
			addKey('à', 'À').padLeft(52); addKey('â', 'Â'); addKey('ç', 'Ç'); addKey('é', 'É'); addKey('è', 'È'); addKey('ê', 'Ê'); addKey('ë', 'Ë'); addKey('ï', 'Ï'); addKey('î', 'Î'); addKey('ô', 'Ô'); addKey('ù', 'Ù'); addKey('û', 'Û'); addKey('ü', 'Ü'); newRow();
			addKey(OF_KEY_TAB); addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('_'); addKey('*'); newRow();
			addKey(OFXSK_KEY_CAPS); ; addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OF_KEY_RETURN); newRow();
			addKey(OF_KEY_SHIFT); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('@'); addKey(OF_KEY_SHIFT); newRow();
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
	ofxSoftKey* key = new ofxSoftKey(key0);
	key->setPadding(6, 6, 6, 6);
	keys.push_back(key);
	return *keys.back();
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKeyboard::addKey(int key0, int key1)
{
    ofxSoftKey* key = new ofxSoftKey(key0, key1);
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
void ofxSoftKeyboard::keyPressed(ofKeyEventArgs& args)
{
    
}

//--------------------------------------------------------------
void ofxSoftKeyboard::keyReleased(ofKeyEventArgs& args)
{
    switch (args.key) {
		case OF_KEY_SHIFT:
			bCapsModifier = false;
			bShiftModifier ^= 1;
            for (int i = 0; i < keys.size(); i++) {
                keys[i]->setModifier(bShiftModifier);
            }
            break;
            
		case OFXSK_KEY_CAPS:
			bShiftModifier = false;
			bCapsModifier ^= 1;
            for (int i = 0; i < keys.size(); i++) {
                keys[i]->setModifier(bCapsModifier);
            }
			break;
            
		default:
			if (bShiftModifier) {
                // Unset shift before returning.
				bCapsModifier = false;
				bShiftModifier = false;
				for (int i = 0; i < keys.size(); i++) {
					keys[i]->setModifier(bShiftModifier);
				}
            }
			break;
	}

	
}
