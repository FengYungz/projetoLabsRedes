#include <DHT11.h>
#include <SoftwareSerial.h>

#define VENTOINHA 13
float maxTemp = 25.5, minTemp=24.5;
float maxHumid = 50, minHumid = 40;

// Create an instance of the DHT11 class and set the digital I/O pin.
DHT11 dht11(2);

void setup()
{
    // Initialize serial communication at 115200 baud.
    Serial.begin(9600);
    pinMode(VENTOINHA, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop()
{
    // Read the humidity from the sensor.
    float humidity = dht11.readHumidity();

    // Read the temperature from the sensor.
    float temperature = dht11.readTemperature();

    // If the temperature and humidity readings were successful, print them to the serial monitor.
    if (temperature != -1 && humidity != -1)
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" C");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }
    else
    {
        // If the temperature or humidity reading failed, print an error message.
        Serial.println("Error reading data");
    }

    if(temperature > maxTemp && humidity > maxHumid){
      digitalWrite(VENTOINHA, LOW);
      digitalWrite(12, LOW);
      Serial.print("----------------Temperatura acima do ideal----------------\n");
      Serial.print("Baixando temperatura...");
    } else {
      digitalWrite(12, HIGH);
      digitalWrite(VENTOINHA, HIGH);
      Serial.print("----------------Temperatura e Umidade OK----------------\n");
    }

    // Wait for 2 seconds before the next reading.
    delay(2000);
}
