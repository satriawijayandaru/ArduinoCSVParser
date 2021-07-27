#ifndef cta
#define cta

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class CSVtoArray{
  public:
    // Constructor
    CSVtoArray(String csvString);

    //Methods
    char convertCSV();

  private:
  
};
#endif
