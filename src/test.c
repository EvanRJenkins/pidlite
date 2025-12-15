#include "pidlite.h"
#include <stdio.h>

#define OUTPUT_FACTOR 0.05

int main(void) {
  struct pidLite_Config PID = {
    .PV = 0.0,
    .SP = 50.0,
    .Pval = 0.0,
    .Ival = 0.0,
    .CV = 0.0,
    .Pgain = 20.0,
    .Igain = 10.0
  }; 
  int i = 0;
  for (i = 0; i < 50; i++) {
    pidLite_update(&PID);
    PID.PV += i;
    printf("Setpoint: %f     Process Value: %f\n", PID.SP, PID.PV);
    PID.PV += PID.CV * OUTPUT_FACTOR;
    printf("Setpoint: %f     Process Value: %f\n", PID.SP, PID.PV);
  }
  return 0;
}
