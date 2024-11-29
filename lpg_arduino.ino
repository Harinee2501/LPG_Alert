#include <Servo.h>
//const int LED=13;
const int buzzer = 7;
Servo myServo;
const int sensorPin = A0; // Analog pin connected to the sensor
int sensorValue = 0; 
// Define the pin numbers for the push button and the LED
const int buttonPin = 2; // the pin number of the push button
const int ledPin = 13; // the pin number of the LED
// Variables to store the state of the button and LED
int buttonState = 0;
int lastButtonState = 0;
bool ledState = false;
bool systemActive = false;
void setup() {
 // Set the button pin as an input
 pinMode(buttonPin, INPUT);
 // Set the LED pin as an output
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
// pinMode(LED, OUTPUT);
 pinMode(buzzer, OUTPUT);
 Serial.begin(9600); // Initialize serial communication
myServo.attach(9);
}
void loop() {
 //myServo.write(0);
 sensorValue = analogRead(sensorPin); // Read sensor value
 
 // Print the sensor reading to the serial monitor
 Serial.print("Sensor Value: ");
 Serial.println(sensorValue);
 
 // Add any additional logic or functionality here
 
 delay(1000); // Delay for stability or adjust as needed
 
 // Read the state of the push button
 buttonState = digitalRead(buttonPin);
 // If the button state has changed
 if (buttonState != lastButtonState) {
 // If the button is pressed
 if (buttonState == LOW) {
 systemActive = !systemActive;
 // If the system is active
 if (systemActive) {
 if (sensorValue<200){
 digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the 
voltage level)
 delay(1000); 
 tone(buzzer, 4000); // Send 1KHz sound signal...
 delay(1000);
 myServo.write(90); // Set servo position
 // Delay for smooth motion
 
 delay(15); 
 //myServo.detach();
 //noTone(buzzer);
 }
 // Sweep the servo from 180 to 0 degrees
 }
 else {
 // If the system is inactive, reset everything
 digitalWrite(ledPin, LOW); // Turn off the LED
 noTone(buzzer); // Turn off the buzzer
 myServo.write(0); // Move servo to initial position
 }
 // Toggle the LED state
 //Serial.print(lastButtonState);
 }
 }
 // Save the current button state for the next iteration
 lastButtonState = buttonState;
}
