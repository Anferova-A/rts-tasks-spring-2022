int ledLights[] = {3, 5, 6, 9, 10};
unsigned long intervals[] = {300000, 200000, 40000, 200, 40};

int ledStates[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long milliseconds[] = {0, 0, 0, 0, 0};

void setup() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    pinMode(ledLights[ledN], OUTPUT);
  }
}

void loop() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    unsigned long currentMilliseconds = micros();
    if (currentMilliseconds - milliseconds[ledN] >= intervals[ledN]) {
      milliseconds[ledN] = currentMilliseconds;

      if (ledStates[ledN] == LOW) {
        ledStates[ledN] = HIGH;
      } 
      else {
        ledStates[ledN] = LOW;
      }
       digitalWrite(ledLights[ledN], ledStates[ledN]);
    }
  }
}