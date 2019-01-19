#include <QTRSensors.h>

// Sensor array: all digital pins being used for sensors should be included here, as well as the total amount.
QTRSensorsRC qtr((char[]) {39, 41, 38, 40, 43, 44, 42, 45, 47, 46, 49, 48, 51, 50, 53, 52}, 16);
int sensors[16];

void setup()
{
  //optional: wait for some input from the user, such as  a button press

  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
  pinMode(33, OUTPUT);
  digitalWrite(33, LOW);
  pinMode(35, OUTPUT);
  digitalWrite(35, HIGH);
  pinMode(37, OUTPUT);
  digitalWrite(37, HIGH);
  pinMode(34, OUTPUT);
  digitalWrite(34, LOW);
  pinMode(36, OUTPUT);
  digitalWrite(36, LOW);


  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode

  // Calibration, we should probably do this if possible, but the sensor array has to be on the line!
  for (int i = 0; i < 250; i++)// make the calibration take about 5 seconds
  {
    qtr.calibrate();
    delay(20);
  }

  Serial.begin(9600);
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are done with setup
}

void loop()
{
  Serial.println(qtr.readLine(sensors));
  delay(200);
}
