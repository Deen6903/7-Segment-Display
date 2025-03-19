/// Define the pins for each segment (D0 to D6)
const int segmentA = 2; // D0
const int segmentB = 3; // D1
const int segmentC = 4; // D2
const int segmentD = 5; // D3
const int segmentE = 6; // D4
const int segmentF = 7; // D5
const int segmentG = 10; // D6
const int buttonPin = 9; // Button pin

// Variable to hold the current number
int currentNumber = 0; // Start counting from 0

// Debounce variables
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
bool lastButtonState = HIGH;

void setup() {
  // Initialize the digital pins as OUTPUTs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  
  // Initialize button pin
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor

  // Display the initial number (0)
  displayNumber(currentNumber); // Show zero initially
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(buttonPin);

  // Check for button press (with debounce)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Wait for debounce delay
    delay(debounceDelay);
    
    // Read the button state again
    buttonState = digitalRead(buttonPin);

    // Only increment if the button is still pressed
    if (buttonState == LOW) {
      // Button was pressed, increase the number
      currentNumber++;
      if (currentNumber > 9) currentNumber = 0; // Reset to 0 after 9
      displayNumber(currentNumber); // Update display with new number
    }
  }

  lastButtonState = buttonState; // Store the last button state
}

// Function to display the current number on the 7-segment display
void displayNumber(int number) {
  // Clear all segments first
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);

  // Set segments based on the number using if-else statements
  if (number == 1) {
      digitalWrite(segmentB, HIGH); // b
      digitalWrite(segmentC, HIGH); // c
  } else if (number == 2) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentE, HIGH);  // e
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 3) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 4) {
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentF, HIGH);  // f
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 5) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentF, HIGH);  // f
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 6) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentE, HIGH);  // e
      digitalWrite(segmentF, HIGH);  // f
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 7) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
  } else if (number == 8) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentE, HIGH);  // e
      digitalWrite(segmentF, HIGH);  // f
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 9) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentF, HIGH);  // f
      digitalWrite(segmentG, HIGH);  // g
  } else if (number == 0) {
      digitalWrite(segmentA, HIGH);  // a
      digitalWrite(segmentB, HIGH);  // b
      digitalWrite(segmentC, HIGH);  // c
      digitalWrite(segmentD, HIGH);  // d
      digitalWrite(segmentE, HIGH);  // e
      digitalWrite(segmentF, HIGH);  // f
  }
}