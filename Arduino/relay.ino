#define RELAY1 11
#define RELAY2 12

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    // Set the relay pins as output
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {  // Check if data is available
        char received = Serial.read();  // Read the character sent from the PC
        Serial.println(received);       // Print the received character to the console

        switch (received) {
            case '0':
                // Turn both relays off
                digitalWrite(RELAY1, LOW);
                digitalWrite(RELAY2, LOW);
                delay(250);
                break;
            case '1':
                // Turn off RELAY2, then turn on RELAY1 after a delay
                digitalWrite(RELAY2, LOW);
                delay(250);
                digitalWrite(RELAY1, HIGH);
                delay(250);
                break;
            case '2':
                // Turn off RELAY1, then turn on RELAY2 after a delay
                digitalWrite(RELAY1, LOW);
                delay(250);
                digitalWrite(RELAY2, HIGH);
                delay(250);
                break;
            default:
                // Ignore any other input
                break;
        }
    }
}
