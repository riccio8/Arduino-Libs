struct MotorPins { // struct for storing motor pin numbers so u don't have to repeat every pin for each motor
    int enable;
    int in1;
    int in2;
};

class Motor {
private:        // private variables where u store the pin numbers for each motor
    MotorPins motorA;
    MotorPins motorB;

public:
    Motor(MotorPins _motorA, MotorPins _motorB); // constructor for the motor class

    void clockwiseA();      // functions for rotating the motors
    void counterClockwiseA();   // functions for rotating the motors counter-clockwise
    
    void clockwiseB();
    void counterClockwiseB();

    void enableA();     // functions for enabling the motor
    void disableA();   // functions for disabling the motor

    void enableB();
    void disableB();

    void disable() {  // function for disabling both motors
        disableA();
        disableB();
    }

    void enable() { // function for enabling both motors
        enableA();
        enableB();
    }
};

Motor::Motor(MotorPins _motorA, MotorPins _motorB) {
    motorA = _motorA; // store the pin numbers for each motor in the private variables
    motorB = _motorB;

    // initialize the motor pins as outputs
    pinMode(motorA.enable, OUTPUT);
    pinMode(motorA.in1, OUTPUT);
    pinMode(motorA.in2, OUTPUT);

    pinMode(motorB.enable, OUTPUT);
    pinMode(motorB.in1, OUTPUT);
    pinMode(motorB.in2, OUTPUT);
}

void Motor::clockwiseA() {
    digitalWrite(motorA.in1, HIGH);
    digitalWrite(motorA.in2, LOW);
}

void Motor::counterClockwiseA() {
    digitalWrite(motorA.in1, LOW);
    digitalWrite(motorA.in2, HIGH);
}

void Motor::clockwiseB() {
    digitalWrite(motorB.in1, HIGH);
    digitalWrite(motorB.in2, LOW);
}

void Motor::counterClockwiseB() {
    digitalWrite(motorB.in1, LOW);
    digitalWrite(motorB.in2, HIGH);
}

void Motor::enableA() {
    digitalWrite(motorA.enable, HIGH);
}

void Motor::disableA() {
    digitalWrite(motorA.enable, LOW);
}

void Motor::enableB() {
    digitalWrite(motorB.enable, HIGH);
}

void Motor::disableB() {
    digitalWrite(motorB.enable, LOW);
}





/* 

USAGE EXAMPLE:

MotorPins motor1 = {5, 6, 7};  // Pin for motor A
MotorPins motor2 = {8, 9, 10}; // Pin for motor B

Motor myMotors(motor1, motor2);

void setup() {
    Serial.begin(9600);
}

void loop() {
    myMotors.enableA();
    myMotors.enableB();

    myMotors.clockwiseA();
    myMotors.clockwiseB();
    delay(2000);

    myMotors.counterClockwiseA();
    myMotors.counterClockwiseB();
    delay(2000);
}





*/
