struct MotorPins { // struct for storing motor pin numbers so u don't have to repeat every pin for each motor
    int enable; // the pin where u connected the enable pin of the motor driver
    int in1;
    int in2;
};

class Motor {
private:        // private variables where u store the pin numbers for each motor
    MotorPins motorA;
    MotorPins motorB; // motor B is optional

public:

   /* The underscore (_) before parameter names is a naming convention 
    to distinguish constructor parameters from class member variables. 
    It has no special meaning in C++ but helps avoid naming conflicts.
    */

    Motor(MotorPins _motorA, MotorPins _motorB = {-1, -1, -1}); // constructor for the motor class
    // motorB is optional, if it's not initialized, motorB will be set to {-1, -1, -1} as default so it won't be seen as a valid motor and won't cause any issues

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

    if (motorB.enable != -1) { // Verify if motor B has been initialized
        pinMode(motorB.enable, OUTPUT);
        pinMode(motorB.in1, OUTPUT);
        pinMode(motorB.in2, OUTPUT);
    }
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
    if (motorB.enable != -1) {  // Verify if motor B has been initialized
        digitalWrite(motorB.in1, HIGH);
        digitalWrite(motorB.in2, LOW);
    }
}

void Motor::counterClockwiseB() {
    if (motorB.enable != -1) {  // Verify if motor B has been initialized
        digitalWrite(motorB.in1, LOW);
        digitalWrite(motorB.in2, HIGH);
    }
}


void Motor::enableA() {
    digitalWrite(motorA.enable, HIGH);
}

void Motor::disableA() {
    digitalWrite(motorA.enable, LOW);
}

void Motor::enableB() {
    if (motorB.enable != -1) {
        digitalWrite(motorB.enable, HIGH);
    }
}

void Motor::disableB() {
    if (motorB.enable != -1) {
        digitalWrite(motorB.enable, LOW);
    }
}

/* 
     Using an initializer list is more efficient because it directly 
    initializes the member variables instead of first creating them 
    with a default constructor and then assigning a new value:

    Motor(MotorPins _motorA, MotorPins _motorB) : motorA(_motorA), motorB(_motorB)

    we cannot do this in our case

*/


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
