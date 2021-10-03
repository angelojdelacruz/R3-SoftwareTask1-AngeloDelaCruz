// C++ code
int inPin = (A0); // Declares pin A0 as the input pin
int outOnes1 = (8); // This and the next four lines declare pins 8, 9, 10, and 12 as output pins for the ones digit.
int outOnes2 = (9);
int outOnes3 = (12);
int outOnes4 = (10);
int outTens1 = (13); // This and the next four lines declare pins 13, 3, 11, and 2 as output pins for the tens digit.
int outTens2 = (3);
int outTens3 = (11);
int outTens4 = (2);
float potentInput = 0.0; // Declares a variable to store a value read from the potentiometer
float percentage = 0.0; // Declares a variable to store percentage
int wholePercent = 0; // Used to store the percentage variable as a rounded whole number
int onesDigit = 0; // Declares a variable to store the digit in the ones place
int tensDigit = 0; // Declares a variable to store the digit in the tens place
void setup() {
  // Marks the input pin as an input and the output pins as outputs.
  pinMode (inPin, INPUT);
  pinMode (outOnes1, OUTPUT);
  pinMode (outOnes2, OUTPUT);
  pinMode (outOnes3, OUTPUT);
  pinMode (outOnes4, OUTPUT);
  pinMode (outTens1, OUTPUT);
  pinMode (outTens2, OUTPUT);
  pinMode (outTens3, OUTPUT);
  pinMode (outTens4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potentInput = analogRead(inPin); // Reads value from potentiometer
  percentage = (potentInput/1023)*100; // Converts potentiometer input to a percentage from 0% to 100%
  wholePercent = round(percentage); // Rounds percentage to a whole number
  if (wholePercent == 100) { // Manually rounds 100% to 99%, as that is the max that can be displayed with 2 7 segment displays
    wholePercent = wholePercent - 1;
  }
  onesDigit = wholePercent % 10; // Stores the digit in the ones place
  tensDigit = (wholePercent - onesDigit) / 10; // Stores the digit in the tens place
  // These next four lines aren't necessary, they're there to confirm the values of the above variables
  // Serial.println(percentage);
  // Serial.println(wholePercent);
  // Serial.println(tensDigit);
  // Serial.println(onesDigit);

  // Ones digit loop - Manually converts the digit stored in the ones place to its binary equivalent with a 7 segment decoder.
  for (int i=0; i<10; i++) {
    if (onesDigit == i) {
        if (i == 0) {
          digitalWrite(outOnes1, LOW);
          digitalWrite(outOnes2, LOW);
          digitalWrite(outOnes3, LOW);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 1) {
          digitalWrite(outOnes1, HIGH);
          digitalWrite(outOnes2, LOW);
          digitalWrite(outOnes3, LOW);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 2) {
          digitalWrite(outOnes1, LOW);
          digitalWrite(outOnes2, HIGH);
          digitalWrite(outOnes3, LOW);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 3) {
          digitalWrite(outOnes1, HIGH);
          digitalWrite(outOnes2, HIGH);
          digitalWrite(outOnes3, LOW);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 4) {
          digitalWrite(outOnes1, LOW);
          digitalWrite(outOnes2, LOW);
          digitalWrite(outOnes3, HIGH);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 5) {
          digitalWrite(outOnes1, HIGH);
          digitalWrite(outOnes2, LOW);
          digitalWrite(outOnes3, HIGH);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 6) {
          digitalWrite(outOnes1, LOW);
          digitalWrite(outOnes2, HIGH);
          digitalWrite(outOnes3, HIGH);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 7) {
          digitalWrite(outOnes1, HIGH);
          digitalWrite(outOnes2, HIGH);
          digitalWrite(outOnes3, HIGH);
          digitalWrite(outOnes4, LOW);
        }
        else if (i == 8) {
          digitalWrite(outOnes1, LOW);
          digitalWrite(outOnes2, LOW);
          digitalWrite(outOnes3, LOW);
          digitalWrite(outOnes4, HIGH);
        }
        else if (i == 9) {
          digitalWrite(outOnes1, HIGH);
          digitalWrite(outOnes2, LOW);
          digitalWrite(outOnes3, LOW);
          digitalWrite(outOnes4, HIGH);
        }
    }
  }
  // Tens digit loop - Manually converts the digit stored in the tens place to its binary equivalent with a 7 segment decoder
  for (int i; i<10 ; i++) {
    if (tensDigit == i) {
        if (i == 0){
          digitalWrite(outTens1, LOW);
          digitalWrite(outTens2, LOW);
          digitalWrite(outTens3, LOW);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 1){
          digitalWrite(outTens1, HIGH);
          digitalWrite(outTens2, LOW);
          digitalWrite(outTens3, LOW);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 2){
          digitalWrite(outTens1, LOW);
          digitalWrite(outTens2, HIGH);
          digitalWrite(outTens3, LOW);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 3){
          digitalWrite(outTens1, HIGH);
          digitalWrite(outTens2, HIGH);
          digitalWrite(outTens3, LOW);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 4){
          digitalWrite(outTens1, LOW);
          digitalWrite(outTens2, LOW);
          digitalWrite(outTens3, HIGH);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 5){
          digitalWrite(outTens1, HIGH);
          digitalWrite(outTens2, LOW);
          digitalWrite(outTens3, HIGH);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 6){
          digitalWrite(outTens1, LOW);
          digitalWrite(outTens2, HIGH);
          digitalWrite(outTens3, HIGH);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 7){
          digitalWrite(outTens1, HIGH);
          digitalWrite(outTens2, HIGH);
          digitalWrite(outTens3, HIGH);
          digitalWrite(outTens4, LOW);
      }
        else if (i == 8){
          digitalWrite(outTens1, LOW);
          digitalWrite(outTens2, LOW);
          digitalWrite(outTens3, LOW);
          digitalWrite(outTens4, HIGH);
      }
        else if (i == 9){
          digitalWrite(outTens1, HIGH);
          digitalWrite(outTens2, LOW);
          digitalWrite(outTens3, LOW);
          digitalWrite(outTens4, HIGH);
      }
    }
  }
  delay(1000); // Stops the program from looping again for 1 second
  
}