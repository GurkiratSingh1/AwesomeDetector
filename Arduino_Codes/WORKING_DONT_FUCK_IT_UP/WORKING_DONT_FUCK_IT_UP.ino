/*
 *  Simple HTTP get webclient test
 */
 
#include <ESP8266WiFi.h>
 
const char* ssid     = "Gurkirat";
const char* password = "password";
 
const char* host = "nigelfrnds.localtunnel.me";
 
void setup() {
  Serial.begin(115200);
  delay(100);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
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
 
int value = 0;
 
void loop() {
  delay(5000);
  ++value;
 
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 3000;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
//  String url = "/";
//  Serial.print("Requesting URL: ");
//  Serial.println(url);
//  
//  // This will send the request to the server
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" + 
//               "Connection: close\r\n\r\n");
//  delay(500);
  Serial.println("POST!!!!!!!!!!!!!!!");
  String PostData = "title=foo&body=bar&userId=1";
client.println("POST /api HTTP/1.1");
client.println("Host: nigelfrnds.localtunnel.me/api");
client.println("Cache-Control: no-cache");
client.println("Content-Type: application/x-www-form-urlencoded");
client.print("Content-Length: ");
client.println(PostData.length());
client.println();
client.println(PostData);
  delay(500);
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
}
