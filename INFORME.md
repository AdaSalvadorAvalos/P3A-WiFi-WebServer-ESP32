# Práctica 3: ejercicio A

## MATERIALES
- ESP32

## Presentación:
Crear una web usando el periférico de wi-fi del microprocesador ESP32.

## EXPLICACIÓN CÓDIGO(con comentarios que explican el funcionamiento línea a línea):

```
#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Mi Ada";  // Pones tu SSID 
const char* password = "telefono4ada";  //y la contraseña

WebServer server(80);  // creas un WebServer con el puerto 80 por defecto
void handle_root();
void setup() {
 Serial.begin(115200);//Establece la velocidad de datos en bits por segundo para la transmisión de datos en serie
 Serial.println("Try Connecting to "); //muestra por la terminal
 Serial.println(ssid); //muestra por la terminal

 // conecta a la módem de tu wi-fi
 WiFi.begin(ssid, password);

 // chequea si el wi-fi està conectado al wi-fi network
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected successfully");
 Serial.print("Got IP: ");
 Serial.println(WiFi.localIP());  //enseña ESP32 IP en el puerto serie

 server.on("/", handle_root);

 server.begin(); //iniciar el servidor
 Serial.println("HTTP server started");
 delay(100); 
}

void loop() {
 server.handleClient();
}

// ponemos el codigo en HTML & CSS de nuestra página web
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

// función que se ejecuta en la url de el Handle root  (/)
void handle_root() {
 server.send(200, "text/html", HTML);
}
```
Salida explicada con más claridad en el vídeo.
