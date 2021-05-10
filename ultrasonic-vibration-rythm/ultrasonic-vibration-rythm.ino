char onTouch = 0;
char TOLERANCE = 20; // cm

// the use of global variables is avoided for memory optimization purposes

void setup() {
  // CONNECTIONS
  // ULT TRIG 1 - 2
  // ULT TRIG 2 - 3
  // ULT TRIG 3 - 4
  
  // ULT ECH0 1 - 5
  // ULT ECHO 2 - 6
  // ULT ECHO 3 - 7

  // VIB INPUT 1 - 8
  // VIB INPUT 2 - 9
  // VIB INPUT 3 - 10

  // TOUCH INPUT - 11
  
  pinMode(2, OUTPUT);// TRIGGER - OUTPUT
  pinMode(3, OUTPUT);// TRIGGER - OUTPUT
  pinMode(4, OUTPUT);// TRIGGER - OUTPUT
  
  pinMode(5, INPUT);// ECHO - INPUT
  pinMode(6, INPUT);// ECHO - INPUT
  pinMode(7, INPUT);// ECHO - INPUT
  
  pinMode(8, OUTPUT);// VIB - OUTPUT
  pinMode(9, OUTPUT);// VIB - OUTPUT
  pinMode(10, OUTPUT);// VIB - OUTPUT
  
  pinMode(11, INPUT); // TOUCH - INPUT
  
  Serial.begin(9600);// enable serial monitor
}
void loop() {
  
  char touched = digitalRead(11);
  long t[3];
  char vib[3] = {0, 0, 0};
  long cm[3];

  // touch sensor as on/off handler
  if(touched == 1 && onTouch == 1){
    onTouch = 0;
    touched = 0;
    delay(600);
  }
  if(touched == 1 && onTouch == 0){
    onTouch = 1;
    touched = 0;
    delay(600);
  }
  if(onTouch == 1){
    Serial.println();// print space
    Serial.println();// print space
    
    //pulse output TRIGGERS
    int pin = 2;
    for (int i = pin; i <= 4; i++){
      digitalWrite(i, LOW);
      delayMicroseconds(4);
      digitalWrite(i, HIGH);
      delayMicroseconds(10);
      digitalWrite(i, LOW);

      t[i - pin] = pulseIn(i + 3, HIGH); // input pulse and save it in variable
      cm[i - pin] = t[i - pin] / 29 / 2; // time convert distance

      if(cm[i - pin] <= TOLERANCE && vib[0] == 0 && vib[1] == 0 && vib[2] == 0){
        vib[i - pin] = 1;
        VibrateRythm01(i, pin, 1000);
        vib[i - pin] = 0;
      } else{
        vib[i - pin] = 0;
      }

      // printing of info
      Serial.print("Sensor #");
      Serial.print((i - pin));
      Serial.print(": ");
      Serial.print(cm[i - pin]); // print serial monitor cm
      Serial.print(" cm \t");
      
      delay(100);// delay
    }
    
  } else{
    // do nothing
    Serial.print("System Turned Off \n");
  }
  
}

// function that vibrates once
void VibrateSimple(int i, int pin, int ms){
  Serial.print("Sensor #");
  Serial.print((i - pin));
  Serial.print(" activated vibration");
  Serial.println();// print space
  
  digitalWrite(i + 6, HIGH);
  delay(ms);
  digitalWrite(i + 6, LOW);
  delay(ms);
}

// function that vibrates 3 times
void VibrateRythm01(int i, int pin, int ms){
  Serial.print("Sensor #");
  Serial.print((i - pin));
  Serial.print(" activated vibration");
  Serial.println();// print space

  for (int k = 0; k < 3; k++){
    char pin = 8;
    if (k != 0) {
      pin = i + 6;
    }
    digitalWrite(pin, HIGH);
    delay(ms);
    digitalWrite(pin, LOW);
    delay(ms);
  }
}
