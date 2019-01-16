#include <QTRSensors.h>

// Sensor array: all digital pins being used for sensors should be included here, as well as the total amount.
QTRSensorsRC qtr((char[]) {14, 15, 16}, 3);
int sensors[3];

void setup()
{
  //optional: wait for some input from the user, such as  a button press

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode

  // Calibration, we should probably do this if possible, but the sensor array has to be on the line!
  /*
  for (int i = 0; i < 250; i++)  // make the calibration take about 5 seconds
  {
    qtr.calibrate();
    delay(20);
  }
  */
  Serial.begin(9600);
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are done with setup
}

void loop()
{
  Serial.println(qtr.readLine(sensors));
  //maybe use Serial.flush() instead?
  delay(100);
}
