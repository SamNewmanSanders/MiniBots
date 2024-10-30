int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, distance, prevdistance, prev2distance;

 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  //Update previous readings to from an average
  prevdistance = distance;
  prev2distance = prevdistance;
 
  // Convert the time into a distance
  distance = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  long normalised_distance = (distance + prevdistance + prev2distance)/3;

  //Serial.print("Actual:");
  //Serial.print(distance);
  //Serial.print("cm\n");
  Serial.print("Normalized:");
  Serial.print(normalised_distance);
  Serial.print("cm");
  Serial.println();
  
  delay(250);

}
