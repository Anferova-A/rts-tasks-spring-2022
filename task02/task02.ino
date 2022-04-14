#include <TaskManagerIO.h>

#define led_1 (3)
#define led_2 (5)
#define led_3 (6)
#define led_4 (9)
#define led_5 (10)
#define led_6 (11)

int ledState1 = LOW;
int ledState2 = LOW;
int ledState3 = LOW;
int ledState4 = LOW;
int ledState5 = LOW;
int ledState6 = LOW;

void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  
  taskManager.scheduleFixedRate(500, [] {
        led(ledState1, led_1);
        });

  taskManager.scheduleFixedRate(1700, [] {
        led(ledState2, led_2);
        });

  taskManager.scheduleFixedRate(950, [] {
        led(ledState3, led_3);
        });

  taskManager.scheduleFixedRate(100, [] {
        led(ledState4, led_4);
        });

  taskManager.scheduleFixedRate(3200, [] {
        led(ledState5, led_5);
        });

  taskManager.scheduleFixedRate(4000, [] {
        led(ledState6, led_6);
        });
}

void loop() {
  taskManager.runLoop();
}

void led(int ledState, int port)
{
      if (ledState == LOW) {
        ledState = HIGH;
      } 
      else {
        ledState = LOW;
      }
       digitalWrite(port, ledState);
}