//
//  RotateAction.hpp
//  PixelDead_SDL
//
//  Created by Tom Albrecht on 25.12.15.
//  Copyright © 2015 Tom Albrecht. All rights reserved.
//

#ifndef RotateAction_hpp
#define RotateAction_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "tmxparser.h"

#include "Action.hpp"
#include "Sprite.hpp"

class RotateToAction;
typedef std::unique_ptr<RotateToAction> RotateToActionPtr;
class Node;

/**
 * Rotates the target Nodes by x radians in y duration
 */
class RotateToAction : public Action {
public:
    RotateToAction(double duration, double radians);
    static RotateToActionPtr create(double duration, double radians);

    
    void update();
    void start();
    
    
private:
    Sprite *targetSprite = NULL;
    double mDestRot = 255;
    double mStartRot = 0;
};

#endif /* RotateAction_hpp */
