/* Project name: ATTiny85 - OLED (I2C)
    Project URI: https://www.studiopieters.nl/attiny85-oled-i2c
    Description: ATTiny85 - OLED (I2C)
    Version: 2.0.9
    License: MIT
*/

#include <Tiny4kOLED.h>

void setup() {

  // Send the initialization sequence to the oled. This leaves the display turned off
  oled.begin();
  // Clear the memory before turning on the display
  oled.clear();
  // Turn on the display
  oled.on();
  // Switch the half of RAM that we are writing to, to be the half that is non currently displayed
  oled.switchRenderFrame();
}

void loop() {

  /* -----------------------------------------
     Show screen with two different font sizes
     -----------------------------------------
  */

  // Clear the non-displayed half of the memory to all black
  // (The previous clear only cleared the other half of RAM)
  oled.clear();

  // The characters in the 8x16 font are 8 pixels wide and 16 pixels tall
  // 2 lines of 16 characters exactly fills 128x32
  oled.setFont(FONT8X16);

  // Position the cusror
  // usage: oled.setCursor(X IN PIXELS, Y IN ROWS OF 8 PIXELS STARTING WITH 0);
  oled.setCursor(12, 0);

  // Write the text to oled RAM (which is not currently being displayed)
  // Wrap strings in F() to save RAM!
  oled.print(F("StudioPieters"));

  // The characters in the 6x8 font are 6 pixels wide and 8 pixels tall
  // 4 lines of 21 characters only fills 126x32
  oled.setFont(FONT6X8);

  // Position the cusror
  // Two rows down because the 8x16 font used for the last text takes two rows of 8 pixels
  oled.setCursor(1, 2);

  // Write the text to oled RAM (which is not currently being displayed)
  oled.print(F("ATTiny85 - OLED (I2C)"));

  // Position the cusror
  // Cursor X is in pixels, and does not need to be a multiple of the font width
  oled.setCursor(44, 3);

  // Write the text to oled RAM (which is not currently being displayed)
  oled.print(F("Project"));

  // Swap which half of RAM is being written to, and which half is being displayed
  oled.switchFrame();

  delay(3000);
}
