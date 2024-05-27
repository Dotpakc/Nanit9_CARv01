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

}

void loop() {
 
}

