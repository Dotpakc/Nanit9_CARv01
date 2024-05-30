// зробити керування двома моторами через броузер
// написати бібліотеку для керування двома моторами
// підключити MPU6050 і додати можливість задавати кут повороту машинки
#include <Arduino.h>
#include <WiFi.h>
// #include <ESPAsyncWebServer.h>
// FreeRTOS - це операційна система реального часу, яка використовується для керування завданнями на ESP32
#include <WebServer.h>

#include <template.h>

#include <secret_config.h>



#define MOTOR1_A 14 // Left motor
#define MOTOR1_B 12 // Left motor
#define MOTOR2_A 25 // Right motor
#define MOTOR2_B 26 // Right motor

#define BUZZER 13 // Buzzer


WebServer server(80);// создаем веб-сервер на порту 80 (стандартный порт для HTTP)


void handler_main() {
  server.send(200, "text/html", htmlContent);
}


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASS); // підключаємося до Wi-Fi
  while (WiFi.status() != WL_CONNECTED) { // чекаємо поки не підключимося
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP()); // виводимо IP-адресу в моніторі порта

  server.on("/", HTTP_GET, handler_main);

  server.on("/forward", HTTP_GET, []() {
    digitalWrite(MOTOR1_A, HIGH);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, HIGH);
    digitalWrite(MOTOR2_B, LOW);
    server.send(200, "text/plain", "Forward");
  });

  server.on("/backward", HTTP_GET, []() {
    digitalWrite(MOTOR1_A, LOW);
    digitalWrite(MOTOR1_B, HIGH);
    digitalWrite(MOTOR2_A, LOW);
    digitalWrite(MOTOR2_B, HIGH);
    server.send(200, "text/plain", "Backward");
  });

  server.on("/turnLeft", HTTP_GET, []() {
    digitalWrite(MOTOR1_A, LOW);
    digitalWrite(MOTOR1_B, HIGH);
    digitalWrite(MOTOR2_A, HIGH);
    digitalWrite(MOTOR2_B, LOW);
    server.send(200, "text/plain", "Turn Left");
  });

  server.on("/turnRight", HTTP_GET, []() {
    digitalWrite(MOTOR1_A, HIGH);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, LOW);
    digitalWrite(MOTOR2_B, HIGH);
    server.send(200, "text/plain", "Turn Right");
  });

  server.on("/stop", HTTP_GET, []() {
    digitalWrite(MOTOR1_A, LOW);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, LOW);
    digitalWrite(MOTOR2_B, LOW);
    server.send(200, "text/plain", "Stop");
  });

  server.on("/buzzer", HTTP_GET, []() {
    tone(BUZZER, 450, 1000);
    server.send(200, "text/plain", "Buzzer");
  });

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  //freeRTOS
}

