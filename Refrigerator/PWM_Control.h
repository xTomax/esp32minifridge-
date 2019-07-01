#ifndef PWM_Control_H
#define PWM_Control_H

int freq = 5000;
int pwm_hot_channel = 0;
int pwm_cold_channel = 1;
int resolution = 8;

byte pwm_hot_pin = 26;
byte pwm_cold_pin = 0;
 
void pwm_setup() {
 
  ledcSetup(pwm_hot_channel, freq, resolution);
  ledcAttachPin(pwm_hot_pin, pwm_hot_channel);
  
  ledcSetup(pwm_cold_channel, freq, resolution);
  ledcAttachPin(pwm_cold_pin, pwm_cold_channel);
 
}

void setHotDuty(byte du){//Set the duty cycle
  ledcWrite(pwm_hot_channel, du);
}

void setColdDuty(byte du){//Set the duty cycle
  ledcWrite(pwm_cold_channel, du);
}

int hotDutyCycle = 80;
bool hotFlip = true;
void cycle_hot(){
    if (hotFlip)
        setHotDuty(++hotDutyCycle);
    else
        setHotDuty(--hotDutyCycle);
    
    if (hotDutyCycle >= 255 || hotDutyCycle <= 80) //This specific fan (Intel 1155 stock fan's) gos form 80 to 255 in an 8bit res.)
        hotFlip=!hotFlip;
}

int coldDutyCycle = 80;
bool coldFlip = true;
void cycle_cold(){
    if (coldFlip)
        setColdDuty(++coldDutyCycle);
    else
        setColdDuty(--coldDutyCycle);
    
    if (coldDutyCycle >= 255 || coldDutyCycle <= 80) //This specific fan (Intel 1155 stock fan's) gos form 80 to 255 in an 8bit res.)
        coldFlip=!coldFlip;
}
#endif
