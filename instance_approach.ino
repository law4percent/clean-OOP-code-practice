class RunningLights {
private:
    int* pins;     // pointer to array of LED pins
    int count;     // number of LEDs

    void allOn() {
        for (int i = 0; i < count; i++) {
            digitalWrite(pins[i], HIGH);
        }
    }

    void allOff() {
        for (int i = 0; i < count; i++) {
            digitalWrite(pins[i], LOW);
        }
    }

public:
    RunningLights(int p[], int c) {
        pins = p;
        count = c;
        for (int i = 0; i < count; i++) {
            pinMode(pins[i], OUTPUT);
        }
    }

    // Mode 1: Chase (one by one left to right)
    void chase(int delayTime) {
        for (int i = 0; i < count; i++) {
            allOff();
            digitalWrite(pins[i], HIGH);
            delay(delayTime);
        }
    }

    // Mode 2: Bounce (left to right then back)
    void bounce(int delayTime) {
        for (int i = 0; i < count; i++) {
            allOff();
            digitalWrite(pins[i], HIGH);
            delay(delayTime);
        }
        for (int i = count - 2; i > 0; i--) {
            allOff();
            digitalWrite(pins[i], HIGH);
            delay(delayTime);
        }
    }

    // Mode 3: All Blink
    void blink(int delayTime) {
        allOn();
        delay(delayTime);
        allOff();
        delay(delayTime);
    }
};

// ---------------------------------------
// Usage
// ---------------------------------------

int ledPins[] = {2, 3, 4, 5, 6};  
RunningLights lights(ledPins, 5);

void setup() {
    Serial.begin(9600);
    Serial.println("Running Lights Demo (Clean Code OOP)");
}

void loop() {
    lights.chase(200);   // mode 1: chase
    lights.bounce(150);  // mode 2: bounce
    lights.blink(300);   // mode 3: blink
}
