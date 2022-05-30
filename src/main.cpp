


#include <WiFi.h>
#include <WebServer.h>


const char* ssid = "Mi Ada";  
const char* password = "telefono4ada"; 

WebServer server(80);  
void handle_root();
void setup() {
 Serial.begin(115200);
 Serial.println("Try Connecting to ");
 Serial.println(ssid);


 WiFi.begin(ssid, password);


 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected successfully");
 Serial.print("Got IP: ");
 Serial.println(WiFi.localIP());  

 server.on("/", handle_root);

 server.begin();
 Serial.println("HTTP server started");
 delay(100); 
}

void loop() {
 server.handleClient();
}


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


void handle_root() {
 server.send(200, "text/html", HTML);
}
