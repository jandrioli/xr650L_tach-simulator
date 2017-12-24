/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  thermistor 436
  temp 36

  therm 385
  temp 26

  temp62
  therm650
*/


void setup() { 
  Serial.begin(115200);
  pinMode(5, OUTPUT); 
} 

long oldtimer = 0;

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A3);

  int desired_rpm = map(sensorValue, 0, 1023, 60, 9000)/60;
  if ( millis() - oldtimer > 5000)
  {
    oldtimer = millis();
    // print out the value you read:
    Serial.print("POT:");
    Serial.print(sensorValue);
    Serial.print(" RPM:");
    Serial.println(desired_rpm*60);
    int temp = analogRead(A2);
    float millivolts = (temp / 1024.0) * 5000;
    float celsius = millivolts / 10;  // sensor output is 10mV per degree Celsius
    Serial.print("Temperature:");
    Serial.println(celsius);

    
    int ther = analogRead(A1);
    Serial.print("Temperature:");
    Serial.print(ther);
    Serial.println();
    
  }
  
  digitalWrite(5, HIGH);
  delay(5);
  digitalWrite(5, LOW);
  delay( 1000/desired_rpm  );
}



