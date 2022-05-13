int vibeArray[] = {3, 5, 6, 9, 10, 11};
int ledArray[] = {4, 7, 8, 12, 13, 17};
const int button = 2;

const int delayInput = A1;
const int intensityInput = A2;
int counter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(delayInput, INPUT);
  pinMode(intensityInput, INPUT);

  for (int i = 0; i <= 5; i++) {
    pinMode(vibeArray[i], OUTPUT);

  }

  for (int i = 0; i <= 5; i++) {
    pinMode(ledArray[i], OUTPUT);

  }

  digitalWrite(ledArray[0], HIGH);
  delay(1000);
  digitalWrite(ledArray[0], LOW);

}

void loop() {
  int button_read = digitalRead(button);
  int delayRead = analogRead(delayInput);
  int intensityRead = analogRead(intensityInput);

  delayRead = map(delayRead, 0, 1024, 50, 300);
  intensityRead = map(intensityRead, 0, 1024, 50, 255);


  if (counter == 0) {
    Serial.println("OFF");
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    digitalWrite(ledArray[0], HIGH);

  }


  if (counter == 1) {
    Serial.println("MODE_1");
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    digitalWrite(ledArray[counter], HIGH);

    for (int i = 0; i <= 5; i++) {
      analogWrite(vibeArray[i], intensityRead);
    }
  }


  else if (counter == 2) {
    Serial.println("MODE_2");
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    digitalWrite(ledArray[counter], HIGH);


    vibrationPulse (delayRead, intensityRead);

  }


  else if (counter == 3) {
    Serial.println("MODE_3");
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    digitalWrite(ledArray[counter], HIGH);

    vibrationEscalate(intensityRead);


  }

  else if (counter == 4) {
    Serial.println("MODE_4");
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    digitalWrite(ledArray[counter], HIGH);

    vibrationWave (delayRead, intensityRead);

  }

  else if (counter == 5) {
    Serial.println("MODE_5");
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    digitalWrite(ledArray[counter], HIGH);

    vibrationRythm(intensityRead);
  }




  if (button_read == LOW) {
    counter = counter + 1;
    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], HIGH);
    }

    delay(500);

    for (int i = 0; i <= 5; i++) {
      digitalWrite(ledArray[i], LOW);
    }
    delay(1000);
  }

  if (counter > 5) {
    counter = 0;
  }
  delay(10);


}

//________________________________________________________________________________________________________



void vibrationPulse (int delayR, int intensityR) {

  Serial.println(delayR);
  Serial.println(intensityR);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);
  }

  delay(delayR);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(delayR);
}





void vibrationWave (int delayR, int intensityR) {

  delayR = delayR / 20;
  Serial.println(delayR);
  Serial.println(intensityR);

  for (intensityR; intensityR <= 250; intensityR++) {
    for (int i = 0; i <= 5; i++) {
      analogWrite(vibeArray[i], intensityR);
    }

    delay(delayR);

  }

  for (int l = 250; l >= 10; l--) {
    for (int i = 0; i <= 5; i++) {
      analogWrite(vibeArray[i], l);
    }

    delay(delayR);
  }

}





void vibrationEscalate (int intensityR) {


  int rDelay = 280;
  intensityR = map(intensityR, 50, 255, 20, 70);

  Serial.println(intensityR);

  for (intensityR; intensityR <= 250; intensityR++) {
    for (int i = 0; i <= 5; i++) {
      analogWrite(vibeArray[i], intensityR);
    }
    delay(50);
  }
  
  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 255);
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 255);
  }

  delay(rDelay);


}





void vibrationRythm (int intensityR) {

  int rDelay = 280;

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DUN
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DUN
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DUN
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay * 2);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DUNNNNN
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay / 2);


  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DU
  }

  delay(rDelay);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay / 2);


  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DU
  }

  delay(rDelay / 2);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }

  delay(rDelay / 2);


  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DU
  }

  delay(rDelay / 2);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }


  delay(rDelay / 2);


  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], intensityR);        //DU
  }

  delay(rDelay / 2);

  for (int i = 0; i <= 5; i++) {
    analogWrite(vibeArray[i], 0);
  }




  delay(rDelay * 2);





}
