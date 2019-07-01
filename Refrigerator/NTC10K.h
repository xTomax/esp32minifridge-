#ifndef NTC10K_H
#define NTC10K_H

//Schematic:
// [Ground] ---- [10k-Resistor] -------|------- [Thermistor] ---- [+5v]
//                                     |
//                               Analog Pin 4

//Resistor used for the readings. It's the same on all of them!
#define R10 10000
#define MEDIA 10  //Numero de contagem para se atingit um valor medio!

#define NTCPin 27
#define NTCPinCold 4

void tempMediaNTC();

float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int Vo;

float readNTC(byte pin){
    Vo = analogRead(pin);
    Vo = analogRead(pin);
    R2 = R10 * (4095.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;
    return Tc;
}

/*********  Calculo da Media  ***************/

float sumNTC = 0;
byte contaMedia = 0;
float tempAtual = -1000;
void tempMediaNTC(){
    sumNTC += readNTC(NTCPin);
    contaMedia++;
    if (contaMedia >= MEDIA){
      tempAtual = sumNTC/MEDIA;
      contaMedia = sumNTC = 0;
      Serial.print("Temperatura NTC ");
      Serial.print(": ");
      Serial.print(tempAtual);
      Serial.println(" C");  
    }
  }

float sumNTCCold = 0;
byte contaMediaCold = 0;
float tempAtualCold = 1000;
void tempMediaNTCCold(){
    sumNTCCold += readNTC(NTCPinCold);
    contaMediaCold++;
    if (contaMediaCold >= MEDIA){
      tempAtualCold = sumNTCCold/MEDIA;
      contaMediaCold = sumNTCCold = 0;
      Serial.print("Temperatura NTC ");
      Serial.print(": ");
      Serial.print(tempAtualCold);
      Serial.println(" C");  
    }
}
#endif
