/* Hello World OLED Test */
#include "SSD1306.h"         // alias for `#include "SSD1306Wire.h"`
SSD1306 display(0x3c, 5, 4); // Initialise the OLED display using Wire library
const int button = 16;
int temp = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(button, INPUT);
  display.init(); // Initialising the UI will init the display too.
  display.flipScreenVertically();
  display.clear(); // clear display on setup
}
void loop()
{
  temp = digitalRead(button);
  while (temp == HIGH)
  {
    delay(300);
    Serial.println("Button pressed");
    drawHelloWorld();
    display.display(); // update what's displayed
    // update temp with current state to determine whether to stay in the loop
    temp = digitalRead(button);
  }
  display.clear();
  display.display(); // update what's displayed
}
void drawHelloWorld()
{
  char a[]{"Hello,"};
  char b[]{"World!"};
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 0, a);
  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 38, b);
}