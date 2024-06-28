const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Digit to segment mapping for common anode display
const byte digitCodes[10] = {
  // a, b, c, d, e, f, g mapped to 2 to 8
  B0000001, // 0
  B1001111, // 1
  B0010010, // 2
  B0000110, // 3
  B1001100, // 4
  B0100100, // 5
  B0100000, // 6
  B0001111, // 7
  B0000000, // 8
  B0000100  // 9
};

int number = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  displayNumber(number);
  number++;
  delay(1000);
  if(number>9) number = 0;
}
void displayNumber(int number) {
  
  // Get the segment code for the number
  byte segmentsBits = digitCodes[number];
  
  // Update the segment pins
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(segmentsBits, 6 - i) ? HIGH : LOW);
  }
}