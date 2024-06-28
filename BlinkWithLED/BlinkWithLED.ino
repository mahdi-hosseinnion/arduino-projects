const int LED_PIN = 2;
const int SECOND_LED_PIN = 5;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(SECOND_LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(SECOND_LED_PIN, LOW);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(SECOND_LED_PIN, HIGH);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
}
