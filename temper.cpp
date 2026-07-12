#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

Servo servo;

// Пины
const int LED_PIN = 13;
const int BUTTON_PIN = 2;
const int FAN_PIN = 3;
const int RED_LED = 4;

// DS18B20
const int ONE_WIRE_BUS = A5;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// LCD (пример для параллельного дисплея)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int mode = 0;
const int MAX_MODE = 2;

void setup() {
    servo.attach(6);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(FAN_PIN, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    sensors.begin();

    lcd.begin(16, 2);

    Serial.begin(9600);
}

void loop() {
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  Serial.print("Device count: ");
  Serial.println(sensors.getDeviceCount());   // ← сколько датчиков нашла библиотека

  if (temperature == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor disconnected or wiring issue!");
  } else {
    Serial.print("Temperature: ");
    Serial.println(temperature);
  }

  // ... остальной код
  delay(1000);   // добавь небольшую задержку
}
