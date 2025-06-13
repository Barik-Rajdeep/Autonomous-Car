#include <Servo.h>

// Pins
const int TRIG = 9;
const int ECHO = 10;
const int SERVO = 6;
const int BUZZER = 8;

// Constants
const int CENTER_ANGLE = 90;
const int LEFT_ANGLE = 150;
const int RIGHT_ANGLE = 30;
const int SAFE_DISTANCE = 30;
const int DANGER_DISTANCE = 10;
const int TURN_SPEED = 5; // Servo turning speed (smooth motion)

Servo steeringServo;
bool obstacleDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  steeringServo.attach(SERVO);
  steeringServo.write(CENTER_ANGLE); // Keep wheels centered by default
  Serial.println("🚗 Car-Like Steering System Initialized");
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  if (duration == 0) return 999; // Handle timeout case

  return duration * 0.034 / 2;
}

void beep(int distance) {
  if (distance <= DANGER_DISTANCE) {
    tone(BUZZER, 1000);
    Serial.println("⚠️ DANGER! Buzzer ON (1000 Hz)");
  }
  else if (distance <= SAFE_DISTANCE) {
    tone(BUZZER, 700);
    Serial.println("⚠️ WARNING! Buzzer ON (700 Hz)");
  }
  else {
    noTone(BUZZER);
    Serial.println("✅ SAFE! Buzzer OFF");
  }
}

void smoothTurn(int targetAngle) {
  int currentAngle = steeringServo.read();
  
  while (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) currentAngle += TURN_SPEED;
    else if (currentAngle > targetAngle) currentAngle -= TURN_SPEED;

    steeringServo.write(currentAngle);
    delay(50); // Smooth transition delay
  }
}

void avoidObstacle() {
  long leftDistance = getDistanceAtAngle(LEFT_ANGLE);
  long rightDistance = getDistanceAtAngle(RIGHT_ANGLE);

  Serial.print("🔍 Scanning | Left: ");
  Serial.print(leftDistance);
  Serial.print(" cm | Right: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  if (leftDistance > rightDistance) {
    Serial.println("➡️ Smoothly Turning RIGHT to avoid obstacle.");
    smoothTurn(RIGHT_ANGLE);
  } else {
    Serial.println("⬅️ Smoothly Turning LEFT to avoid obstacle.");
    smoothTurn(LEFT_ANGLE);
  }

  delay(500);  
  smoothTurn(CENTER_ANGLE); // Smoothly return to center
  Serial.println("🔄 Returning to CENTER position.");
}

long getDistanceAtAngle(int angle) {
  steeringServo.write(angle);
  delay(400);
  return getDistance();
}

void loop() {
  long frontDistance = getDistance();
  beep(frontDistance);

  if (frontDistance < SAFE_DISTANCE) {
    obstacleDetected = true;
    Serial.println("🚨 OBSTACLE DETECTED! Taking Evasive Action...");
    avoidObstacle();
  } else {
    obstacleDetected = false;
    Serial.println("✅ Path Clear. Wheels Stopped.");
  }

  delay(300);
}
