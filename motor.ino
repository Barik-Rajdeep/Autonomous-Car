#define RELAY_FORWARD 7
#define RELAY_BACKWARD 8

String movement_status = "Waiting for Data";

void setup() {
    Serial.begin(9600);
    pinMode(RELAY_FORWARD, OUTPUT);
    pinMode(RELAY_BACKWARD, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read();

        if (command == 'F') {
            digitalWrite(RELAY_FORWARD, HIGH);
            digitalWrite(RELAY_BACKWARD, LOW);
            movement_status = "Moving Forward 🚗➡️";
        } 
        else if (command == 'B') {
            digitalWrite(RELAY_FORWARD, LOW);
            digitalWrite(RELAY_BACKWARD, HIGH);
            movement_status = "Moving Backward 🚗⬅️";
        } 
        else if (command == 'S') {
            digitalWrite(RELAY_FORWARD, LOW);
            digitalWrite(RELAY_BACKWARD, LOW);
            movement_status = "Stopped ⏹️";
        }

        // Send real-time status to Raspberry Pi
        Serial.println(movement_status);
    }
}
