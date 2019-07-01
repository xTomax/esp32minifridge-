#ifndef tachometer_H
#define tachometer_H


#include <Arduino.h>
#include <atomic>

#define TCH 25
#define TCH_cold 2

int rpm = 0;
int rpmCold = 0;

std::atomic<int> half_rev;
std::atomic<int> half_rev_cold;

void cnt_rpm(){
  half_rev++;
}
void cnt_rpm_cold(){
  half_rev_cold++;
}

void setup_tachometer() {
  pinMode(TCH,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TCH),cnt_rpm,RISING);
  pinMode(TCH_cold,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TCH_cold),cnt_rpm_cold,RISING);
}
void readRPM() {
    rpm = half_rev.exchange(0);
    Serial.print("RPM Hot: ");
    Serial.println(rpm*30); //(1s RPM so * 60 / 2 = *30)
  }

void readRPMCold() {
    rpmCold = half_rev_cold.exchange(0);
    Serial.print("RPM Cold: ");
    Serial.println(rpmCold*30); //(1s RPM so * 60 / 2 = *30)
  }

#endif
