#include "VegetronixVH400.h"
#include "Arduino.h"

VegetronixVH400::VegetronixVH400(unsigned short pin, double voltage){
  //Save pin
  this->pin=pin;
  //Save ADCVoltage
  this->ADCVoltage=voltage;
  //Set-up pin
  pinMode(pin,INPUT);
}

double VegetronixVH400::getVWC(){
  //Get value in volt
  double ddp=(double) analogRead(this->pin)*this->ADCVoltage/1023;


  /*Convert voltage in Vater content with a curve linearized around 4 points
  (As in https://www.vegetronix.com/Products/VH400/VH400-Piecewise-Curve.phtml)*/
  if (ddp<1.1) {
    return (double) 10*ddp-1;
  }
  else if (ddp<1.3) {
    return (double) 25*ddp-17.5;
  }
  else if (ddp<1.82) {
    return (double) 48.08*ddp-47.5;
  }
  else if (ddp<2.2) {
    return (double) 26.32*ddp-7.89;
  }
  else{
    return (double) 62.5*ddp-87.5;
  }
}
