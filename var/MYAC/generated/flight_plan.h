/* This file has been generated from /Users/tony-yi/git/paparazzi_local/conf/flight_plans/rotorcraft_basic_YI_2013_7_16.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#include "std.h"
#include "generated/modules.h"
#include "autopilot.h"
#define FLIGHT_PLAN_NAME "MYAC-TEST"
#define NAV_UTM_EAST0 377349
#define NAV_UTM_NORTH0 4824583
#define NAV_UTM_ZONE0 31
#define NAV_LAT0 435641194 /* 1e7deg */
#define NAV_LON0 14812805 /* 1e7deg */
#define NAV_ALT0 147000 /* mm above msl */
#define NAV_MSL0 51850 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 0.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_STDBY 2
#define WP_p1 3
#define WP_p2 4
#define WP_LZ 5
#define WAYPOINTS { \
 {42.0, 42.0, 150},\
 {0.0, 0.0, 150},\
 {3.0, 0.0, 150},\
 {3.0, 3.0, 150},\
 {3.0, -3.0, 150},\
 {1.0, 0.0, 150},\
};
#define WAYPOINTS_LLA { \
 {435645043, 14817909, 15000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435641194, 14812805, 15000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435641199, 14813176, 15000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435641469, 14813170, 15000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435640929, 14813183, 15000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {435641196, 14812929, 15000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
};
#define NB_WAYPOINT 6
#define NB_BLOCK 14
#define GROUND_ALT 147.
#define GROUND_ALT_CM 14700
#define SECURITY_HEIGHT 2.
#define SECURITY_ALT 149.
#define HOME_MODE_HEIGHT 2.
#define MAX_DIST_FROM_HOME 60.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // Wait GPS
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavKillThrottle()))
          NextStageAndBreak();
        break;
      Label(while_1)
      Stage(1)
        if (! (!(GpsFixValid()))) Goto(endwhile_2) else NextStageAndBreak();
        Stage(2)
          Goto(while_1)
        Label(endwhile_2)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // Geo init
    ; // pre_call
    switch(nav_stage) {
      Label(while_3)
      Stage(0)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_4) else NextStageAndBreak();
        Stage(1)
          Goto(while_3)
        Label(endwhile_4)
      Stage(2)
        if (! (NavSetGroundReferenceHere()))
          NextStageAndBreak();
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // Holding point
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavKillThrottle()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (FALSE) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(0));
          NavVerticalAutoThrottleMode(RadOfDeg(0));
          NavVerticalThrottleMode(9600*(0));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // Start Engine
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavResurrect()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (FALSE) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(0));
          NavVerticalAutoThrottleMode(RadOfDeg(0));
          NavVerticalThrottleMode(9600*(0));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(4) // Takeoff
    ; // pre_call
    if ((nav_block != 5) && ((stateGetPositionEnu_f())->z>2.000000)) { GotoBlock(5); return; }
    switch(nav_stage) {
      Stage(0)
        if (! (NavSetWaypointHere(WP_STDBY)))
          NextStageAndBreak();
        break;
      Stage(1)
        NavGotoWaypoint(2);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalClimbMode(0.500000);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(5) // Standby
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        NavGotoWaypoint(2);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(2), 0.);
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(6) // stay_p1
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        NavGotoWaypoint(3);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(7) // go_p2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (NavApproaching(4,CARROT)) NextStageAndBreakFrom(4) else {
          NavGotoWaypoint(4);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(4), 0.);
        }
        break;
      Stage(1)
        GotoBlock(6);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(8) // line_p1_p2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (NavApproachingFrom(4,3,CARROT)) NextStageAndBreakFrom(4) else {
          NavSegment(3, 4);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(4), 0.);
        }
        break;
      Stage(1)
        NavGotoWaypoint(4);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(4), 0.);
        if ((stage_time>20)) NextStageAndBreak();
        break;
      Stage(2)
        if (NavApproachingFrom(3,4,CARROT)) NextStageAndBreakFrom(3) else {
          NavSegment(4, 3);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        }
        break;
      Stage(3)
        GotoBlock(6);
        break;
      default:
      Stage(4)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(9) // circle
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        NavCircleWaypoint(3, 2);
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(10) // land here
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavSetWaypointHere(WP_LZ)))
          NextStageAndBreak();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(11) // land
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (NavApproaching(5,CARROT)) NextStageAndBreakFrom(5) else {
          NavGotoWaypoint(5);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(5), 0.);
        }
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(12) // flare
    ; // pre_call
    if ((nav_block != 2) && NavDetectGround()) { GotoBlock(2); return; }
    switch(nav_stage) {
      Stage(0)
        if (! (NavStartDetectGround()))
          NextStageAndBreak();
        break;
      Stage(1)
        NavGotoWaypoint(5);
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalClimbMode(-(0.300000));
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(13) // HOME
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    default: break;
  }
}
#endif // NAV_C

#endif // FLIGHT_PLAN_H
