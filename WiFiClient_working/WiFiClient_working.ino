#include <ESP8266HTTPClient.h>

/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <WiFi.h>
//#include <HTTPClient.h>
#include <ArduinoJson.h>
 char* ssid     = "LS-4505";
 char* password = "12345678";

const char* host = "thedush.com";
const char* privateKey = "1";




StaticJsonBuffer<500> jsonBuffer;

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    pinMode(13,OUTPUT);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}


void loop()
{
   HTTPClient http;

        http.begin("http://thedush.com:8080/query?Id=1"); //HTTP

        int httpCode = http.GET();
        if(httpCode > 0) {

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                JsonObject& root = jsonBuffer.parseObject(http.getString());
                if(root["State"] == "OFF"){
                  digitalWrite(13,0);
                }
                else{
                  digitalWrite(13,1);
                }
                root["State"].printTo(Serial);
            }
        } else {
            Serial.println("[HTTP] GET... failed, error: \n");
        }
        jsonBuffer.clear();

        http.end();
        delay(500);
        
}

