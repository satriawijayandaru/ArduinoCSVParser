#include "CSVtoArray.h"
int i;
CSVtoArray csvtoarray();
String formatted;
void setup() {
  Serial.begin(115200);

}

void loop() {
//  Serial.println(csvtoarray.convertCSV());
  Serial.println(formatted);
  csvParsing();
  generatecsv();
  delay(250);
}

void csvParsing() {
  if (hwserial.available() > 0) {
    incomingByte = hwserial.read();  
    incomingString += incomingByte;
    if(incomingByte == '`'){
      int str_len = incomingString.length() - 1;
      incomingCSV[i] = incomingString.substring(0, str_len);
      Serial.print("Incoming ");
      Serial.print(i);
      Serial.print(" = ");
      Serial.println(incomingCSV[i]);
      Serial.println();
      incomingString = "";
      i = 0;
    }
    if (incomingByte == ',') {
      int str_len = incomingString.length() - 1;
      incomingCSV[i] = incomingString.substring(0, str_len);
      Serial.print("Incoming ");
      Serial.print(i);
      Serial.print(" = ");
      Serial.println(incomingCSV[i]);
      i++;
      incomingString = "";
    }
  }
}

void generatecsv(){
  formatted = "";
  formatted += i;
  formatted += ',';
  i++;
  formatted += i;
  formatted += ',';
  i++;
  formatted += i;
  formatted += ',';
  i++;
  formatted += i;
  formatted += ',';
  i++;
  formatted += i;
  formatted += ',';
  i++;
  formatted += i;
  formatted += '`';
  i++;
  
}
