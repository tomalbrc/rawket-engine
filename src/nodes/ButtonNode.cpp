//
//  ButtonNode.cpp
//  PixelDead_SDL
//
//  Created by Tom Albrecht on 23.12.15.
//  Copyright © 2015 Tom Albrecht. All rights reserved.
//

#include "ButtonNode.hpp"

inline bool operator!=(const Color& lhs, const Color& rhs) { return !(lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a); }
inline bool operator==(const Color& lhs, const Color& rhs) { return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a); }

ButtonNodePtr ButtonNode::create(std::string s) {
    ButtonNodePtr p(new ButtonNode());
    p->init(s);
    return p;
}
ButtonNodePtr ButtonNode::create(std::string text, std::string fontpath, int fontSize) {
    ButtonNodePtr p(new ButtonNode());
    p->init(text,fontpath,fontSize, p->mNormalColor);
    return p;
}
ButtonNodePtr ButtonNode::create(std::string text, std::string fontpath, int fontSize, Color col) {
    ButtonNodePtr p(new ButtonNode());
    p->init(text,fontpath,fontSize, col);
    return p;
}



bool ButtonNode::init(std::string s) {
    if (LabelNode::init()) {
        setText(s);
        return true;
    }
    return false;
}
bool ButtonNode::init(std::string text, std::string fontpath, int fontSize, Color col) {
    return LabelNode::init(text,fontpath,fontSize, col);
}

ButtonNode::~ButtonNode() {
    mCallback = NULL;
}



void ButtonNode::mouseClickBegan(SDL_MouseButtonEvent event, Vec2 coords) {
    if (RectIntersectsVec2(getBoundingBox(), convertToNodeSpace(coords))) {
        if (mCallback != nullptr) mCallback(this);
    }
}

void ButtonNode::mouseMoved(SDL_MouseMotionEvent, Vec2 coords) {
    if (RectIntersectsVec2(getBoundingBox(), convertToNodeSpace(coords))) {
        if (mHoverColor != getTextColor())
            setTextColor(mHoverColor);
    } else if (mNormalColor != getTextColor())
        setTextColor(mNormalColor);
}



void ButtonNode::setHandler(ButtonNodeCallback callback) {
    mCallback = callback;
}



void ButtonNode::setHoverColor(Color hoverColor) {
    mHoverColor = hoverColor;
}
Color ButtonNode:: getHoverColor() {
    return mHoverColor;
}


void ButtonNode::setNormalColor(Color normalColor) {
    mNormalColor = normalColor;
}
Color ButtonNode:: getNormalColor() {
    return mNormalColor;
}
