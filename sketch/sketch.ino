// Copyright (c) Olivier Dagenais. All rights reserved.
// Licensed under the MIT license. See LICENSE in the project root.

/*
 * scrappy-02: I/O tester
 *
 * TODO: include diagram
 */

const int pmw[] = {
  3,
  5,
  6,
  9,
  10,
  11
};
const int pmwCount = 6;

const int digitalIn[] = {
  2,
  4,
  7,
  8,
  12
};
const int inCount = 5;

const int analogCount = 6;

int brightness = 0;
int fadeAmount = 5;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < inCount; i++) {
    int digitalPin = digitalIn[i];
    pinMode(digitalPin, INPUT_PULLUP);
  }
  for (int o = 0; o < pmwCount; o++) {
    int digitalPin = pmw[o];
    pinMode(digitalPin, OUTPUT);
  }
}

void loop() {

  for (int a = 0; a < analogCount; a++) {
    int v = analogRead(a);
    Serial.print(v < 15 ? 1 : 0);
    Serial.print(v);
    Serial.print(", ");
  }
  for (int i = 0; i < inCount; i++) {
    int digitalPin = digitalIn[i];
    int v = digitalRead(digitalPin);
    Serial.print(v == 0 ? 1 : 0);
  }
  Serial.println();

  for (int c = 0; c < pmwCount; c++) {
    int digitalPin = pmw[c];
    analogWrite(digitalPin, brightness);
  }

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
