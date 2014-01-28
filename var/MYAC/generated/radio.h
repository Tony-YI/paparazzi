/* This file has been generated from /Users/tony-yi/git/paparazzi_local/conf/radios/radio_wfly7_YI_2013_7_13.xml */
/* Please DO NOT EDIT */

#ifndef RADIO_H
#define RADIO_H

#define RADIO_NAME "projectv1"

#define RADIO_CTL_NB 8

#define RADIO_FILTER 7

#define RADIO_CTL_A 0
#define RADIO_THROTTLE RADIO_CTL_A
#define RADIO_CTL_B 1
#define RADIO_PITCH RADIO_CTL_B
#define RADIO_CTL_C 2
#define RADIO_ROLL RADIO_CTL_C
#define RADIO_CTL_D 3
#define RADIO_YAW RADIO_CTL_D
#define RADIO_CTL_E 4
#define RADIO_MODE RADIO_CTL_E
#define RADIO_CTL_F 5
#define RADIO_KILL_SWITCH RADIO_CTL_F
#define RADIO_CTL_NoneG 6
#define RADIO_NOTUSEDG RADIO_CTL_NoneG
#define RADIO_CTL_NoneH 7
#define RADIO_NOTUSEDH RADIO_CTL_NoneH

#define RADIO_THROTTLE_NEUTRAL 1100
#define RADIO_THROTTLE_MIN 1100
#define RADIO_THROTTLE_MAX 2050
#define RADIO_PITCH_NEUTRAL 1500
#define RADIO_PITCH_MIN 2000
#define RADIO_PITCH_MAX 1000
#define RADIO_ROLL_NEUTRAL 1500
#define RADIO_ROLL_MIN 2000
#define RADIO_ROLL_MAX 1000
#define RADIO_YAW_NEUTRAL 1500
#define RADIO_YAW_MIN 2000
#define RADIO_YAW_MAX 1000
#define RADIO_MODE_NEUTRAL 1500
#define RADIO_MODE_MIN 2000
#define RADIO_MODE_MAX 1000
#define RADIO_KILL_SWITCH_NEUTRAL 1500
#define RADIO_KILL_SWITCH_MIN 2000
#define RADIO_KILL_SWITCH_MAX 1000
#define RADIO_NOTUSEDG_NEUTRAL 1500
#define RADIO_NOTUSEDG_MIN 1000
#define RADIO_NOTUSEDG_MAX 2000
#define RADIO_NOTUSEDH_NEUTRAL 1500
#define RADIO_NOTUSEDH_MIN 1000
#define RADIO_NOTUSEDH_MAX 2000

#define PPM_PULSE_TYPE PPM_PULSE_TYPE_POSITIVE
#define PPM_DATA_MIN_LEN (800ul)
#define PPM_DATA_MAX_LEN (2200ul)
#define PPM_SYNC_MIN_LEN (5000ul)
#define PPM_SYNC_MAX_LEN (15000ul)

#define NormalizePpmFIR(_ppm, _rc) {\
  static uint8_t avg_cpt = 0; /* Counter for averaging */\
  int16_t tmp_radio;\
  tmp_radio = _ppm[RADIO_THROTTLE] - RC_PPM_TICKS_OF_USEC(1100);\
  _rc.values[RADIO_THROTTLE] = tmp_radio * (MAX_PPRZ / (float)(RC_PPM_SIGNED_TICKS_OF_USEC(2050-1100)));\
  Bound(_rc.values[RADIO_THROTTLE], 0, MAX_PPRZ); \
\
  tmp_radio = _ppm[RADIO_PITCH] - RC_PPM_TICKS_OF_USEC(1500);\
  _rc.values[RADIO_PITCH] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))));\
  Bound(_rc.values[RADIO_PITCH], MIN_PPRZ, MAX_PPRZ); \
\
  tmp_radio = _ppm[RADIO_ROLL] - RC_PPM_TICKS_OF_USEC(1500);\
  _rc.values[RADIO_ROLL] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))));\
  Bound(_rc.values[RADIO_ROLL], MIN_PPRZ, MAX_PPRZ); \
\
  tmp_radio = _ppm[RADIO_YAW] - RC_PPM_TICKS_OF_USEC(1500);\
  _rc.values[RADIO_YAW] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))));\
  Bound(_rc.values[RADIO_YAW], MIN_PPRZ, MAX_PPRZ); \
\
  _rc.avg_values[RADIO_MODE] += _ppm[RADIO_MODE];\
  _rc.avg_values[RADIO_KILL_SWITCH] += _ppm[RADIO_KILL_SWITCH];\
  _rc.avg_values[RADIO_NOTUSEDG] += _ppm[RADIO_NOTUSEDG];\
  _rc.avg_values[RADIO_NOTUSEDH] += _ppm[RADIO_NOTUSEDH];\
  avg_cpt++;\
  if (avg_cpt == RC_AVG_PERIOD) {\
    avg_cpt = 0;\
    tmp_radio = _rc.avg_values[RADIO_MODE] / RC_AVG_PERIOD -  RC_PPM_TICKS_OF_USEC(1500);\
    _rc.values[RADIO_MODE] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))));\
    _rc.avg_values[RADIO_MODE] = 0;\
    Bound(_rc.values[RADIO_MODE], MIN_PPRZ, MAX_PPRZ); \
\
    tmp_radio = _rc.avg_values[RADIO_KILL_SWITCH] / RC_AVG_PERIOD -  RC_PPM_TICKS_OF_USEC(1500);\
    _rc.values[RADIO_KILL_SWITCH] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))));\
    _rc.avg_values[RADIO_KILL_SWITCH] = 0;\
    Bound(_rc.values[RADIO_KILL_SWITCH], MIN_PPRZ, MAX_PPRZ); \
\
    tmp_radio = _rc.avg_values[RADIO_NOTUSEDG] / RC_AVG_PERIOD -  RC_PPM_TICKS_OF_USEC(1500);\
    _rc.values[RADIO_NOTUSEDG] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))));\
    _rc.avg_values[RADIO_NOTUSEDG] = 0;\
    Bound(_rc.values[RADIO_NOTUSEDG], MIN_PPRZ, MAX_PPRZ); \
\
    tmp_radio = _rc.avg_values[RADIO_NOTUSEDH] / RC_AVG_PERIOD -  RC_PPM_TICKS_OF_USEC(1500);\
    _rc.values[RADIO_NOTUSEDH] = tmp_radio * (tmp_radio >=0 ? (MAX_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500))) : (MIN_PPRZ/(float)(RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500))));\
    _rc.avg_values[RADIO_NOTUSEDH] = 0;\
    Bound(_rc.values[RADIO_NOTUSEDH], MIN_PPRZ, MAX_PPRZ); \
\
 }\
}

#define NormalizePpmIIR(_ppm, _rc) {\
  int32_t tmp_radio;\
  int32_t tmp_value;\
\
  tmp_radio = _ppm[RADIO_THROTTLE] - RC_PPM_TICKS_OF_USEC(1100);\
  tmp_value = (tmp_radio * MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2050-1100));\
  Bound(tmp_value, 0, MAX_PPRZ); \
  _rc.values[RADIO_THROTTLE] = (pprz_t)(tmp_value);\
\
  tmp_radio = _ppm[RADIO_PITCH] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_PITCH] = (pprz_t)(tmp_value);\
\
  tmp_radio = _ppm[RADIO_ROLL] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_ROLL] = (pprz_t)(tmp_value);\
\
  tmp_radio = _ppm[RADIO_YAW] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_YAW] = (pprz_t)(tmp_value);\
\
  tmp_radio = _ppm[RADIO_MODE] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_MODE] = (pprz_t)((RADIO_FILTER * _rc.values[RADIO_MODE] + tmp_value) / (RADIO_FILTER + 1));\
\
  tmp_radio = _ppm[RADIO_KILL_SWITCH] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_KILL_SWITCH] = (pprz_t)((RADIO_FILTER * _rc.values[RADIO_KILL_SWITCH] + tmp_value) / (RADIO_FILTER + 1));\
\
  tmp_radio = _ppm[RADIO_NOTUSEDG] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_NOTUSEDG] = (pprz_t)((RADIO_FILTER * _rc.values[RADIO_NOTUSEDG] + tmp_value) / (RADIO_FILTER + 1));\
\
  tmp_radio = _ppm[RADIO_NOTUSEDH] - RC_PPM_TICKS_OF_USEC(1500);\
  tmp_value = (tmp_radio >=0 ? (tmp_radio *  MAX_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(2000-1500)) : (tmp_radio * MIN_PPRZ) / (RC_PPM_SIGNED_TICKS_OF_USEC(1000-1500)));\
  Bound(tmp_value, MIN_PPRZ, MAX_PPRZ); \
  _rc.values[RADIO_NOTUSEDH] = (pprz_t)((RADIO_FILTER * _rc.values[RADIO_NOTUSEDH] + tmp_value) / (RADIO_FILTER + 1));\
\
}


#endif // RADIO_H
