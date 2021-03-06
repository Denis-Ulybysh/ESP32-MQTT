#include <Arduino.h>
#include <RotaryEncoder.h>

// Set pins below according to your hardware setup
const uint8_t PIN_A = 34;
const uint8_t PIN_B = 35;

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
 //RotaryEncoder encoder(34, 35, RotaryEncoder::LatchMode::FOUR3);

// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(PIN_A, PIN_B, RotaryEncoder::LatchMode::TWO03);


void setup()
{
  Serial.begin(9600);
  Serial.println("SimplePollRotator example for the RotaryEncoder library.");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
  } // if
} // loop ()

