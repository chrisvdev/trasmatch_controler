const unsigned short BAUD = 300;
const unsigned short WAIT = 1000;
const byte RESET = 2;
const byte THRU = 3;
const byte START = 4;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RESET,INPUT);
  pinMode(THRU,INPUT);
  pinMode(START,INPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.begin(BAUD,SERIAL_8N1); // posiblemente sea tambien SERIAL_8N0
   while (!Serial) {
    ; // wait for serial port to connect.
  }
  digitalWrite(LED_BUILTIN,LOW);
}

void reset(){
  Serial.write(0xFF3CEFFF);
}

void thru() {
  Serial.write(0xFF5DFFFF);
  Serial.write(0x5DFFFF6D);
  Serial.write(0xFFFF);
}

void start(){
  Serial.write(0xFF5EEFFF);
  Serial.write(0x5EEFFFEF);
  Serial.write(0xFF);
  delay(WAIT);
  Serial.write(0x6EFFFF);

}

void loop() {
  if (digitalRead(RESET)==HIGH) reset();
  if (digitalRead(THRU)==HIGH) thru();
  if (digitalRead(START)==HIGH) start();
}





