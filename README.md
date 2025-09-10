# Practice 3-A: ESP32 Wi-Fi Web Server (English Version)

## Materials
- ESP32

## Introduction
In this practice, for my Digital Processors course, I learned how to create a simple web page using the Wi-Fi peripheral of the ESP32. The ESP32 acts as a web server and serves an HTML page accessible from a browser.

## Code Explanation (with comments explaining line by line):
```cpp
#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Mi Ada";       // Enter your Wi-Fi SSID
const char* password = "telefono4ada";  // Enter your Wi-Fi password

WebServer server(80);  // Create a WebServer on port 80
void handle_root();

void setup() {
  Serial.begin(115200);                  // Start Serial at 115200 bps
  Serial.println("Try Connecting to "); 
  Serial.println(ssid);                  // Show the SSID in Serial Monitor

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());        // Print ESP32 IP

  server.on("/", handle_root);           // Handle root URL

  server.begin();                        // Start the server
  Serial.println("HTTP server started");
  delay(100);
}

void loop() {
  server.handleClient();                 // Handle incoming client requests
}

// HTML & CSS content for the web page
String HTML = "<!DOCTYPE html>\
<html>\
<head>\
<title> &#128516; Nuestra Pagina con ESP32  </title>\
<body style= 'background-color: #e0c89a;'> \
</head>\
<body>\
<hr>\
<h2>Authors: </h2>\
<lu>\
<li>Ada Salvador</li>\
<li>Milene Granda</li>\
</lu>\
<hr><h2>ESP32</h2><img src='https://tienda.bricogeek.com/5833-large_default/esp32-wroom-wifi-bluetooth.jpg'/></body></html>";

// Function executed when root URL is accessed (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}
```

## How to Run

1. **Install PlatformIO**
   - Install [VS Code](https://code.visualstudio.com/)
   - Install the [PlatformIO extension](https://platformio.org/install/ide?install=vscode)

2. **Create a New Project**
   - Open PlatformIO in VS Code
   - Create a new project and select your board (e.g., ESP32 Dev Module)
   - Choose **Arduino framework**

3. **Add the Code**
   - Replace the contents of `src/main.cpp` with the code provided above

4. **Connect the Hardware**
   - Connect the ESP32 board to your computer via USB

5. **Build and Upload**
   - Click **Build (✓)** to compile the code
   - Click **Upload (→)** to flash the code to your ESP32

6. **Observe the Output**
   - Open a browser and navigate to the ESP32 IP shown in the Serial Monitor
   - You should see the web page served by the ESP32


# Práctica 3-A: Servidor Web con ESP32 (Versión en Español)

## Materiales
- ESP32

## Introducción
En esta práctica, para mi curso de Procesadores Digitales, aprendí a crear una página web simple utilizando el periférico Wi-Fi del ESP32. El ESP32 actúa como servidor web y entrega una página HTML accesible desde un navegador.

## Explicación del código (con comentarios línea por línea):

```cpp
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
## Cómo Ejecutar

1. **Instalar PlatformIO**
   - Instala [VS Code](https://code.visualstudio.com/)
   - Instala la [extensión PlatformIO](https://platformio.org/install/ide?install=vscode)

2. **Crear un Nuevo Proyecto**
   - Abre PlatformIO en VS Code
   - Crea un nuevo proyecto y selecciona tu placa (ejemplo: ESP32 Dev Module)
   - Elige el **framework Arduino**

3. **Agregar el Código**
   - Reemplaza el contenido de `src/main.cpp` con el código proporcionado arriba

4. **Conectar el Hardware**
   - Conecta la placa ESP32 a tu computadora mediante USB

5. **Compilar y Subir**
   - Haz clic en **Build (✓)** para compilar el código
   - Haz clic en **Upload (→)** para cargar el código en tu ESP32

6. **Observar el Resultado**
   - Abre un navegador y navega a la IP del ESP32 que aparece en el Monitor Serial
   - Deberías ver la página web servida por el ESP32

### Recursos
- Video explicativo en español sobre la creación del servidor web con ESP32: [Ver video](assets/practica3A.mp4)
