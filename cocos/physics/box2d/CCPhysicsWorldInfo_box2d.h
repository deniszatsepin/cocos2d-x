/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __CCPHYSICS_WORLD_INFO_BOX2D_H__
#define __CCPHYSICS_WORLD_INFO_BOX2D_H__

#include "../CCPhysicsSetting.h"
#if (CC_PHYSICS_ENGINE == CC_PHYSICS_BOX2D)
#include "Box2D.h"
#include "CCPlatformMacros.h"
NS_CC_BEGIN
class PhysicsBodyInfo;
class PhysicsJointInfo;
class PhysicsShapeInfo;

class PhysicsWorldInfo
{
public:
    inline b2World* getWorld() { return _world; }
    void addShape(PhysicsShapeInfo& shape);
    void removeShape(PhysicsShapeInfo& shape);
    void addBody(PhysicsBodyInfo& body);
    void removeBody(PhysicsBodyInfo& body);
    void addJoint(PhysicsJointInfo& joint);
    void removeJoint(PhysicsJointInfo& joint);
    void setGravity(const Vect& gravity);
    inline bool isLocked() { return _world->IsLocked(); }
    inline void step(float delta) { _world->Step(delta, VELOCITY_ITERRATIONS, POSITION_ITERRATIONS); }
    
private:
    b2World* _world;
    static const int32 VELOCITY_ITERRATIONS = 8;
    static const int32 POSITION_ITERRATIONS = 1;

private:
    PhysicsWorldInfo();
    ~PhysicsWorldInfo();

    friend class PhysicsWorld;
};

NS_CC_END

#endif // CC_PHYSICS_ENGINE == CC_PHYSICS_BOX2D
#endif // __CCPHYSICS_WORLD_INFO_BOX2D_H__
