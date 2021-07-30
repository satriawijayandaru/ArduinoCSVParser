#define ser2 Serial2
#define ser1 Serial
String formatted;

void setup() {
  ser1.begin(115200);
  ser2.begin(115200);
}

void loop() {
  formatted = "";
  formatted += millis() / 1000;
  formatted += ',';
  formatted += millis();
  formatted += ',';
  formatted += millis() * 2;
  formatted += ',';
  formatted += millis() / 2;
  formatted += ',';
  formatted += millis() / 3.00;
  formatted += ',';
  formatted += "Satria";
  formatted += '`';
  ser1.println(formatted);
  ser2.println(formatted);
  delay(20);
}
