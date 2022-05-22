
/*
 ESP32 Web Server - STA Mode
 modified on 25 MAy 2019
 by Mohammadreza Akbari @ Electropeak
 https://electropeak.com/learn
*/

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Mi Ada";  // Enter your SSID here
const char* password = "telefono4ada";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)
void handle_root();
void setup() {
 Serial.begin(115200);
 Serial.println("Try Connecting to ");
 Serial.println(ssid);

 // Connect to your wi-fi modem
 WiFi.begin(ssid, password);

 // Check wi-fi is connected to wi-fi network
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected successfully");
 Serial.print("Got IP: ");
 Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

 server.on("/", handle_root);

 server.begin();
 Serial.println("HTTP server started");
 delay(100); 
}

void loop() {
 server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<head>\
<title> &#128516; Nuestra Pagina con ESP32  </title>\
<body style= 'background-color: #e0c89a;'> \
</head>\
<body>\
<hr>\
<h2>Autoras: </h2>\
<lu>\
<li>Ada Salvador</li>\
<li>Milene Granda</li>\
</lu>\
<hr><h2>ESP32</h2><img src='https://tienda.bricogeek.com/5833-large_default/esp32-wroom-wifi-bluetooth.jpg'/></body></html>";

// Handle root url (/)
void handle_root() {
 server.send(200, "text/html", HTML);
}
