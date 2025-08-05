// Define pins
const int trigPin = 9;
const int echoPin = 8;
const int buzzerPin = 5;
const int ledPin = 6;

void setup() {

// Initialize serial communication
Serial.begin(9600);

// Set pins as input/output
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(ledPin, OUTPUT);
}

void loop() {

// Variable to store duration and distance
long duration;
int distance;

// Clear the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Set the trigPin HIGH for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Read the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculate the distance
distance = duration * 0.0343 / 2;

// Display the distance on Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

// If distance is within 20 cm, activate buzzer and LED
if (distance > 0 && distance <= 20) {
int beepFrequency = map(distance, 1, 20, 2000, 500); // Adjust beep frequency based on distance

tone(buzzerPin, beepFrequency);

int ledBrightness = map(distance, 1, 20, 255, 50); // Adjust LED brightness based on distance

analogWrite(ledPin, ledBrightness);
} else {
noTone(buzzerPin);
digitalWrite(ledPin, LOW);
}
delay(500); // Delay for stability
}
