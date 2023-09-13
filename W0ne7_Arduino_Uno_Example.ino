#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8}; // These are the pins you have connected from the W0ne7 to the arduino. Any input pins on the arduino can be used, just change the numbers here as needed

// Variables will change (don't change these manually):
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0};         // Current state of each button
int lastButtonStates[] = {0, 0, 0, 0, 0, 0, 0};     // Previous state of each button

void setup() {
  // Initialize button pins as inputs with pull-down resistors:
  for (int i = 0; i < 7; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  // Initialize the Keyboard library:
  Keyboard.begin();
}

void loop() {
  // Read the state of each button:
  for (int i = 0; i < 7; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);

    // Compare the button state to its previous state:
    if (buttonStates[i] != lastButtonStates[i]) {
      // If the state has changed, increment the counter:
      if (buttonStates[i] == HIGH) {
        // If the current state is HIGH, the button went from off to on:
        // Send corresponding keyboard key press:
        char keyToSend = 'a' + i; // Convert button index to character 'a' to 'g'
        Keyboard.press(keyToSend);
      } 
      else {
        // If the current state is LOW, the button went from on to off:
        Keyboard.releaseAll();

      }

    }
    // Save the current state as the last state for the next time through the loop:
    lastButtonStates[i] = buttonStates[i];
  }
}
