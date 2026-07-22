#include <Servo.h>

Servo door;

int trigPin = 9;
int echoPin = 10;
int buzzer = 8;

int redLED = 13;
int greenLED = 12;
int yellowLED = 7;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  door.attach(6);

  door.write(0);

  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 20) {

    tone(buzzer, 523);
    delay(150);
    tone(buzzer, 659);
    delay(150);
    tone(buzzer, 784);
    delay(200);
    noTone(buzzer);

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

    for (int pos = 0; pos <= 90; pos++) {
      door.write(pos);
      delay(15);
    }

    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    delay(2000);

    tone(buzzer, 784);
    delay(150);
    tone(buzzer, 659);
    delay(150);
    tone(buzzer, 523);
    delay(200);
    noTone(buzzer);

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);

    for (int pos = 90; pos >= 0; pos--) {
      door.write(pos);
      delay(15);
    }

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    delay(1000);
  }

  delay(100);
}
