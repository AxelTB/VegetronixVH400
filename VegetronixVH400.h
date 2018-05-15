class VegetronixVH400 {
private:
  //Probe pin
  unsigned short pin;
  //ADC Maximum voltage
  double ADCVoltage;

public:
  /*  Constructor
  *   Parameters:
  *               pin: board analog pin
  *               voltage: ADC maximum voltage (Min 3v fot hw definition)
  */
  VegetronixVH400(unsigned short pin,double voltage=3.3);
  //Read water content
  double getVWC();
  //virtual ~VegetronixVH400 ();

};
