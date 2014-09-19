#pragma once

#ifndef _MY_STRATEGY_H_
#define _MY_STRATEGY_H_

#include "Strategy.h"

#include "coordfix.h"
#include "geom.h"
#include "shape.h"

class MyStrategy : public Strategy {
public:
    MyStrategy();
    void move(const model::Hockeyist& self, const model::World& world, const model::Game& game, model::Move& move);

private:    
    const double StrikeAnglePrecision = M_PI / 180;
    const double StrikeAngleCorrection = M_PI / 270;

    const double DefenceAreaR = 50;
    const double DefenceAreaDist = 190;

    const double ApproximateDeadZoneX0 = 15;
    const double ApproximateDeadZoneX1 = 35;
    const double DangerousPuckSpeed = 13;

    const double AttackAreaDestX = 775;
    const double AttackAreaDestY = 300;

    double _attackDestX;
    double _attackDestY0;
    double _attackDestY1;

    Sector _attackPuckArea;
    ShapeSubtraction _attackAreaL0;
    ShapeSubtraction _attackAreaL1;

    bool _first;
    CoordFix _fix;

    HockeyistF _self;
    WorldF _world;
    GameF _game;
    MoveF _move;

    bool _checkInL0;

    double conv0(double x, double z);
    double conv1(double x, double z);
    void goAngle(double a);
    void gotoXY(double x, double y);
    void gotoXY(const UnitF& u);

    bool isNearStick(const HockeyistF& h, double x, double y);
    bool isNearStick(const HockeyistF& h, const UnitF& u);
    bool isNearStick(double x, double y);
    bool isNearStick(const UnitF& u);

    int opponentsAttacking(double x, double y);
    int opponentsAttacking(const UnitF& u);
    int opponentsAttackingHP(const HockeyistF& h, const PuckF& p);     //Attacking hockeyist with puck
    int opponentsReadyToActHP(const HockeyistF& h, const PuckF& p);     //Attacking hockeyist with puck

    void defend();
    int nearestToPuck();

    bool isOnMyHalf(double x);
    bool isOnMyHalf(const UnitF& u);

    bool isPuckGoingToMyNet();
    bool canApproximatelyHitPuckToNet();

    void act();
};

#endif
