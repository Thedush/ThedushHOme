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
#include <DNSServer.h>            
#include <ESP8266WebServer.h>
#include <WiFiManager.h> 
#include <ArduinoJson.h>


const char* host = "thedush.com";
const char* privateKey = "1";




StaticJsonBuffer<500> jsonBuffer;

void setup()
{
     // put your setup code here, to run once:
    Serial.begin(115200);

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings
    //wifiManager.resetSettings();
    wifiManager.autoConnect("ThoughtBox","12345678");

    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    //wifiManager.autoConnect("AutoConnectAP");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
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
                Serial.println();
            }
        } else {
            Serial.println("[HTTP] GET... failed, error: \n");
        }
        jsonBuffer.clear();

        http.end();
        delay(500);
        
}

