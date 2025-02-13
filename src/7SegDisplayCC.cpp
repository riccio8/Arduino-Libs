/*

Code for turning on and off the 7 leds on a 7-segment display common cathode

*/


#define pinA 7
#define button2 3
#define button1 2
int data;
int count = 0;
int buttonState = 0;
int lastState = 0;

int uno[7] = {0, 1, 1, 0, 0, 0, 0};
int due[7] = {1, 1, 0, 1, 1, 0, 1};
int tre[7] = {1, 1, 1, 1, 0, 0, 1};
int quattro[7] = {0, 1, 1, 0, 0, 1, 1};
int cinque[7] = {1, 0, 1, 1, 0, 1, 1};
int sei[7] = {1, 0, 1, 1, 1, 1, 1};
int sette[7] = {1, 1, 1, 0, 0, 0, 0};
int otto[7] = {1, 1 ,1 ,1 ,1 ,1 ,1};
int nove[7] = {1, 1, 1, 1 ,0, 1, 1};
int zero[7] = {1, 1, 1, 1, 1, 1, 0};


void setMode(int pinstart,int len){
    for (int i = pinstart; i < len+pinstart; i++){
      pinMode(i, OUTPUT);
      }
}

void clean(int pinstart,int len){
    for (int i = pinstart; i < len+pinstart; i++){
      digitalWrite(i, LOW);
      }
}

void accendi(int bin[7]) {
  // Accendi i LED in base ai valori dell'array
  for (int i = 0; i < 7; i++) {
    if (bin[i] == 0) {
      digitalWrite(pinA + i, LOW);  // Spegni il LED
    } else {
      digitalWrite(pinA + i, HIGH); // Accendi il LED
    }
  }
}


void accendiNum(int num){
  
    switch (num) {
      case 1:
        accendi(uno);
        break;
      case 2:
        accendi(due);
        break;
      case  3:
        accendi(tre);
        break;
      case 4:
        accendi(quattro);
        break;
      case 5:
        accendi(cinque);
        break;
      case 6:
        accendi(sei);
        break;
      case 7:
        accendi(sette);
        break;
      case 8:
        accendi(otto);
        break;
      case 9:
        accendi(nove);
        break;
      case 0:
        accendi(zero);
        break;
      default:
        Serial.print("no number");
  }
}

void setup() {
  clean(7, 7);
  Serial.begin(9600);
  // put your setup code here, to run once:
  int start = 7;
  int len = 13;
  setMode(7, 7);
}


void loop() {
    buttonState = digitalRead(button1);
  if (digitalRead(button1) == HIGH && count < 9 && lastState == LOW){
    count ++;
    accendiNum(count);    
    Serial.println(count);
    delay(150);
  }

    if (digitalRead(button2) == HIGH && count >= 1 ){
      count = count - 1;
      accendiNum(count);    
      Serial.println(count);
      delay(150);
  }

  lastState = buttonState;
}


