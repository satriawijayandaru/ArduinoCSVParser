#define hwserial Serial2


String incomingString;
String incomingCSV[100];
int currentCSVIndex = 0;
int maxCSVIndex;

void setup() {
  hwserial.begin(115200);
  Serial.begin(2000000);

}

void loop() {
  if (hwserial.available() > 0) {
    serialIN(hwserial.read(), 1);
  }
}

void serialIN(char incomingSerial, bool debugMode) {
  char incomingByte;
  incomingByte = incomingSerial;
  incomingString += incomingByte;
  if (incomingByte == ',') {
    int str_len = incomingString.length() - 1;
    incomingCSV[currentCSVIndex] = incomingString.substring(0, str_len);
    if (debugMode == 1) {
      Serial.print("Incoming ");
      Serial.print(currentCSVIndex);
      Serial.print(" = ");
      Serial.println(incomingCSV[currentCSVIndex]);
    }
    currentCSVIndex++;
    incomingString = "";
  }
  if (incomingByte == '`') {
    int str_len = incomingString.length() - 1;
    incomingCSV[currentCSVIndex] = incomingString.substring(0, str_len);
    if (debugMode == 1) {
      Serial.print("Incoming ");
      Serial.print(currentCSVIndex);
      Serial.print(" = ");
      Serial.println(incomingCSV[currentCSVIndex]);


      
      Serial.print("max Index   = ");
      Serial.println(maxCSVIndex);
      Serial.println();
    }
    incomingString = "";
    maxCSVIndex = currentCSVIndex;
    currentCSVIndex = 0;
  }
}
