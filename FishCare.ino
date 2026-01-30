#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

WiFiClientSecure client;
String textFix = "GET /SEU_ENDPOINT_AQUI";

LiquidCrystal_I2C lcd(0x27, 20, 4);

int LED_BUILTIN = 2;
int Led1 = 21;
int Led2 = 22;

int tempMin = 26;
int tempMax = 30;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("NOME DA REDE", "SENHA DA REDE");
  client.setInsecure();
  delay(2000);
  sensors.begin();
  Serial.println("Iniciando sensor DS18B20...");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);

  Wire.begin(18, 19);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("FishCare IoT");
  lcd.setCursor(0, 2);
  lcd.print("STATUS:");
  lcd.setCursor(0, 3);
  lcd.print("TEMPERATURA:");
  lcd.setCursor(14, 3);
  lcd.print(char(B11011111));
  lcd.setCursor(15, 3);
  lcd.print("C");
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  int tempArredondada = round(tempC);

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Erro: sensor não encontrado!");
  } else {
    Serial.print("Temperatura da água: ");
    Serial.print(tempC);
    Serial.println(" ºC");

    lcd.setCursor(12, 3);
    lcd.print(tempArredondada);
  }

  if (client.connect("docs.google.com", 443) == 1) {
    lcd.setCursor(7, 2);
    lcd.print("ONLINE   ");
    String toSend = textFix;
    toSend += String(tempArredondada);
    toSend += "&submit=Submit HTTP/1.1";
    client.println(toSend);
    client.println("Host: docs.google.com");
    client.println();
    client.stop();
    Serial.println("Dados enviados.");
  } else {
    lcd.setCursor(7, 2);
    lcd.print("OFFLINE   ");
    Serial.println("Erro ao se conectar");
  }

  if (tempArredondada < tempMin) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);

  } else if (tempArredondada > tempMax) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);

  } else {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
  }

  delay(5000);
}