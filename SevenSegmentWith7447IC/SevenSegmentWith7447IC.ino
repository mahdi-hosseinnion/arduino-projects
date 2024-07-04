const int firstDigitPins[4] = {2, 3, 4, 5};
const int secondDigitPins[4] = {6, 7, 8, 9};
const int increasePin = 12;
const int decreasePin = 13;
int number = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(firstDigitPins[i], OUTPUT);
    pinMode(secondDigitPins[i], OUTPUT);
  }
  pinMode(increasePin, INPUT_PULLUP);
  pinMode(decreasePin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  displayNumber(number);
  if(digitalRead(increasePin) == LOW){
      while(digitalRead(increasePin) == LOW){
      }
      number++;
  }
  if(digitalRead(decreasePin) == LOW){
      while(digitalRead(decreasePin) == LOW){
      }
      number--;

  }
  if (number > 99 || number < 0){
    number = 0;
  }
}
void displayNumber(int num){
  displayFirstDigit(number % 10);
  displaySecondDigit(number / 10);
}
void displayFirstDigit(int num) {
  for (int i = 0; i < 4; i++) {
      digitalWrite(firstDigitPins[i], ((num >> i) & 0x01) ? HIGH : LOW);
  }
}
void displaySecondDigit(int num) {  
  for (int i = 0; i < 4; i++) {
    digitalWrite(secondDigitPins[i], ((num >> i) & 0x01) ? HIGH : LOW);
  }
}
