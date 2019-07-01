#include <Arduino.h>
#include <atomic>

#include "NTC10K.h"
#include "tachometer.h"
#include "PWM_Control.h"
#include "TaskManager.h"

void setup() {
  Serial.begin(9600);
  setup_tachometer();
  pwm_setup();
}

void loop() {
    ts.execute();
}
