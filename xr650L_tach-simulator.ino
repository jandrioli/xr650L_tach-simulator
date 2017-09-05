/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/


void setup() { 
  Serial.begin(115200);
  pinMode(5, OUTPUT); 
} 



// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A3);

  int desired_rpm = map(sensorValue, 0, 1023, 60, 9000)/60;
  // print out the value you read:
  Serial.print("POT:");
  Serial.print(sensorValue);
  Serial.print(" RPM:");
  Serial.println(desired_rpm*60);
  
  
  digitalWrite(5, HIGH);
  delay(1);
  digitalWrite(5, LOW);
  delay( 1000/desired_rpm  );
}



