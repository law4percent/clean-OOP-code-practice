class RunningLights {
public:
    static const int ledCount = 5;
    static int pins[ledCount];

    static void setupPins() {
        for (int i = 0; i < ledCount; i++) {
            pinMode(pins[i], OUTPUT);
        }
    }

    // Mode 1: Chase (one by one left to right)
    static void chase(int delayTime) {
        for (int i = 0; i < ledCount; i++) {
            allOff();
            digitalWrite(pins[i], HIGH);
            delay(delayTime);
        }
    }

    // Mode 2: Bounce (left to right and back)
    static void bounce(int delayTime) {
        for (int i = 0; i < ledCount; i++) {
            allOff();
            digitalWrite(pins[i], HIGH);
            delay(delayTime);
        }
        for (int i = ledCount - 2; i > 0; i--) {
            allOff();
            digitalWrite(pins[i], HIGH);
            delay(delayTime);
        }
    }

    // Mode 3: All Blink
    static void blink(int delayTime) {
        allOn();
        delay(delayTime);
        allOff();
        delay(delayTime);
    }

private:
    static void allOff() {
        for (int i = 0; i < ledCount; i++) {
            digitalWrite(pins[i], LOW);
        }
    }

    static void allOn() {
        for (int i = 0; i < ledCount; i++) {
            digitalWrite(pins[i], HIGH);
        }
    }
};

// Define static array
int RunningLights::pins[RunningLights::ledCount] = {2, 3, 4, 5, 6};

void setup() {
    Serial.begin(9600);
    RunningLights::setupPins();
}

void loop() {
    RunningLights::chase(200);   // mode 1
    RunningLights::bounce(150);  // mode 2
    RunningLights::blink(300);   // mode 3
}
