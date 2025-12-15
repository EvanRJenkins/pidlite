#ifndef PIDLITE_H
#define PIDLITE_H
/*
Configuration header
*/
#include "config.h"
/*
If USE_FLOAT defined in config.h,
use float instead of double
*/
#ifdef USE_FLOAT
  typedef float pidL_t;
#else
  typedef double pidL_t;
#endif
/*
Config struct for pid lib
*/
struct pidLite_Config {
  // Setpoint and process value
  pidL_t SP, PV;
  // Proportinal, integral, derivative terms
  pidL_t Pval, Ival;
  // Control Value (Mathematical output)
  pidL_t CV;
  // Gain factors
  const pidL_t Pgain, Igain;
};
/*
Update SP at target PID
*/
void pidLite_setSP(struct pidLite_Config *PID, pidL_t new_SP);
/*
Update PV at target PID
*/
void pidLite_setPV(struct pidLite_Config *PID, pidL_t new_PV);
/*
Calculate error
*/
pidL_t pidLite_getError(struct pidLite_Config *PID);
/*
Calculate P term
*/
void pidLite_getP(struct pidLite_Config *PID, pidL_t error);
/*
Calculate I term
*/
void pidLite_getI(struct pidLite_Config *PID, pidL_t error);
/*
Update target pid
*/
void pidLite_update(struct pidLite_Config *PID);
//
#endif
