/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
/**************************************************************/
// from http://www.sunfounder.com/index.php?c=case_incs&a=detail_&id=102&name=super%20kit
const int clkPin= 2;
const int dtPin= 3;
const int swPin= 4 ;//the number of the button
 
int encoderVal = 0;
 
void setup()
{
  pinMode(clkPin, INPUT);//set clkPin as INPUT
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);
}
 
void loop()
{
  int change = getEncoderTurn();//
  encoderVal = encoderVal + change;
  if(digitalRead(swPin) == LOW)//if button pull down
  {
    encoderVal = 0;
  }
  Serial.println(encoderVal);
}
 
int getEncoderTurn(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  int newA = digitalRead(clkPin);//read the value of clkPin to newA
  int newB = digitalRead(dtPin);//read the value of dtPin to newB
  if (newA != oldA || newB != oldB)
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}
