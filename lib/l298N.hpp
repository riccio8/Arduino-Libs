struct MotorPins {
    int enable;
    int in1;
    int in2;
};

class Motor {
private:
    MotorPins motorA;
    MotorPins motorB;

public:
    Motor(MotorPins _motorA, MotorPins _motorB);

    void clockwiseA();
    void counterClockwiseA();
    
    void clockwiseB();
    void counterClockwiseB();

    void enableA();
    void disableA();

    void enableB();
    void disableB();

    void disable() {
        disableA();
        disableB();
    }

    void enable() {
        enableA();
        enableB();
    }
};

Motor::Motor(MotorPins _motorA, MotorPins _motorB) {
    motorA = _motorA;
    motorB = _motorB;

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

MotorPins motor1 = {5, 6, 7};  // Pin per il motore A
MotorPins motor2 = {8, 9, 10}; // Pin per il motore B

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


MORE INFO AT:
https://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf


*/
