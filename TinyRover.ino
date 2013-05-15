// Motor 1 (right) forward pin (PB3 = digital pin 3)
#define MOTOR1FWDPIN 3
// Motor 1 (right) reverse pin (PB4 = digital pin 4)
#define MOTOR1RVSPIN 4
// Motor 2 (left) forward pin (PB0 = digital pin 0)
#define MOTOR2FWDPIN 0
// Motor 2 (left) reverse pin (PB2 = digital pin 1)
#define MOTOR2RVSPIN 1
// IR sensor pin (ADC1 = analog pin 1 != digital pin 1)
#define IRPIN 1

// Make the rover going forward
void forwardRover() {
  stopMotor();
  digitalWrite(MOTOR1FWDPIN, HIGH);
  digitalWrite(MOTOR2RVSPIN, LOW);
  digitalWrite(MOTOR2FWDPIN, HIGH);
  digitalWrite(MOTOR2RVSPIN, LOW);
}

// Make the rover going reverse
void reverseRover() {
  stopMotor();
  digitalWrite(MOTOR1FWDPIN, LOW);
  digitalWrite(MOTOR1RVSPIN, HIGH);
  digitalWrite(MOTOR2FWDPIN, LOW);
  digitalWrite(MOTOR2RVSPIN, HIGH);
}

// Make the rover turning right
void turnRight() {
  stopMotor();
  digitalWrite(MOTOR1FWDPIN, LOW);
  digitalWrite(MOTOR1RVSPIN, HIGH);
  digitalWrite(MOTOR2FWDPIN, HIGH);
  digitalWrite(MOTOR2RVSPIN, LOW);
}

// Make the rover turning left
void turnLeft() {
  stopMotor();
  digitalWrite(MOTOR1FWDPIN, HIGH);
  digitalWrite(MOTOR1RVSPIN, LOW);
  digitalWrite(MOTOR2FWDPIN, LOW);
  digitalWrite(MOTOR2RVSPIN, HIGH);
}

void stopMotor() {
  digitalWrite(MOTOR1FWDPIN, LOW);
  digitalWrite(MOTOR1RVSPIN, LOW);
  digitalWrite(MOTOR2FWDPIN, LOW);
  digitalWrite(MOTOR2RVSPIN, LOW);
}
  

// Get distance (cm) measured by IR sensor
float getDistance() {
  // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  float volts = (float)analogRead(IRPIN)*0.0048828125;   
  return 65.0 * pow(volts, -1.10) / 2.55;
}  

void setup() {
  // Initialize random generator
  randomSeed(analogRead(IRPIN));
  
  // Initialize pins
  pinMode(MOTOR1FWDPIN, OUTPUT);
  pinMode(MOTOR1RVSPIN, OUTPUT);
  pinMode(MOTOR2FWDPIN, OUTPUT);
  pinMode(MOTOR2RVSPIN, OUTPUT);

  // Start rover
  forwardRover();
}

void loop() {
  // If we are too close from an obstacle (i.e. less than 15 cm)
  if (getDistance() < 15.0) {
    // Reverse rover until we are at about 25 cm from the obstacle
    reverseRover();
    
    while (getDistance() < 25.0) {
      // Do nothing, just wait for the correct distance
    }

    // We randomly turn the rover to left or right, for a random amount of time (between 2 and 4 seconds)
    if (random(150) < 75) {
      turnLeft();
    } else {
      turnRight();
    }
    
    //delay(4000);
    delay(random(2000,4000));
    
    // We make the rover going forward again
    forwardRover();
  }
}
