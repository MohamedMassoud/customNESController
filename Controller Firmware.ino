

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>

#ifndef STASSID
#define STASSID "Test"
#define STAPSK  "testpass"
#endif

unsigned int localPort = 8888;      // local port to listen on
uint8_t __up = 1;
uint8_t __down = 1;
uint8_t __left = 1;
uint8_t __right = 1;
uint8_t __a = 1;
uint8_t __b = 1;
uint8_t __strt = 1;
uint8_t __slct = 1;
boolean tick = false;

// buffers for receiving and sending data
char  ReplyBuffer[] = "nth";       // a string to send back

WiFiUDP Udp;
IPAddress ip(192, 168, 43, 137);


void configurePort(uint8_t port, uint8_t custom)
{
  if (custom == INPUT)
  {
    writeBlockData(port, 0xFF);
  }
  else if (custom == OUTPUT)
  {
    writeBlockData(port, 0x00);
  }
  else
  { 
    writeBlockData(port, custom);
  }
}

uint8_t readGP()
{
  uint8_t statusGP = 0;
  Wire.beginTransmission(0x20);
  Wire.write(0x09);
  Wire.endTransmission();
  Wire.requestFrom(0x20, 1); // ler do chip  1 byte
  statusGP = Wire.read();
  return statusGP;

  Serial.print("Value of GPIO is: ");
  Serial.println(255 - statusGP);
}

void writeBlockData(uint8_t cmd, uint8_t data)
{
  Wire.beginTransmission(0x20);
  Wire.write(cmd);
  Wire.write(data);
  Wire.endTransmission();
  delay(10);
}
uint8_t valueFromPin(uint8_t pin, uint8_t statusGP)
{
  return (statusGP & ( 0x0001 << pin)) == 0 ? 0 : 1;
}


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);
   Serial.println();
  Wire.begin(0, 2); //ESP-01

  Wire.setClock(200000); //frequencia

  //configura o GPIO0 como OUTPUT (todos os pinos)
  configurePort(0x00, INPUT);
  //configura o GPIO1 como INPUT o GP1.0 e como OUTPUT os outros GP1
  //writeBlockData(0x09, B00000000);
}

void loop() {
  // if there's data available, read a packet




uint8_t gpStat = readGP();
 // Serial.println(gpStat);
  uint8_t up = valueFromPin(7, gpStat);
  uint8_t down = valueFromPin(6, gpStat);
  uint8_t left = valueFromPin(5, gpStat);
  uint8_t right = valueFromPin(4, gpStat);
  uint8_t a = valueFromPin(2, gpStat);
  uint8_t b = valueFromPin(3, gpStat);
  uint8_t strt = valueFromPin(1, gpStat);
  uint8_t slct = valueFromPin(0, gpStat);
  //Serial.print("connecting to ");
  //Serial.print(host);
  //Serial.print(':');
  //Serial.println(port);

  // Use WiFiClient class to create TCP connections
  if (__up + up == 1 || __down + down == 1 || __left + left == 1 || __right + right == 1 || __a + a == 1 || __b + b == 1 || __strt + strt == 1 || __slct + slct == 1)tick = true;
  //Serial.print("Tick: ");
  //Serial.println(tick);wwww
  if (tick) {
    
    
    // This will send a string to the server
    Serial.println("sending data to server");
    

      if (__up == 0 && up == 1) {
        Serial.println("UP released");
        Udp.beginPacket(ip, 8888);
        Udp.write("UP OFF");
        Udp.endPacket();
      } else if (__up == 1 && up == 0) {
        Serial.println("UP pressed: ");
        Udp.beginPacket(ip, 8888);
        Udp.write("UP ON");
        Udp.endPacket();
      }

      if (__down == 0 && down == 1) {
        Serial.println("Down released");
        Udp.beginPacket(ip, 8888);
        Udp.write("DOWN OFF");
        Udp.endPacket();
      } else if (__down == 1 && down == 0) {
        Serial.println("Down pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("DOWN ON");
        Udp.endPacket();
      }

      if (__left == 0 && left == 1) {
        Serial.println("Left released");
        Udp.beginPacket(ip, 8888);
        Udp.write("LEFT OFF");
        Udp.endPacket();
      } else if (__left == 1 && left == 0) {
        Serial.println("Left pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("LEFT ON");
        Udp.endPacket();
      }

      if (__right == 0 && right == 1) {
        Serial.println("Right released");
        Udp.beginPacket(ip, 8888);
        Udp.write("RIGHT OFF");
        Udp.endPacket();
      } else if (__right == 1 && right == 0) {
        Serial.println("Right pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("RIGHT ON");
        Udp.endPacket();
      }

      if (__a == 0 && a == 1) {
        Serial.println("A pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("A OFF");
        Udp.endPacket();
      } else if (__a == 1 && a == 0) {
        Serial.println("A pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("A ON");
        Udp.endPacket();
      }

      if (__b == 0 && b == 1) {
        Serial.println("B released");
        Udp.beginPacket(ip, 8888);
        Udp.write("B OFF");
        Udp.endPacket();
      } else if (__b == 1 && b == 0) {
        Serial.println("B pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("B ON");
        Udp.endPacket();
      }

      if (__strt == 0 && strt == 1) {
        Serial.println("Start released");
        Udp.beginPacket(ip, 8888);
        Udp.write("START OFF");
        Udp.endPacket();
      } else if (__strt == 1 && strt == 0) {
        Serial.println("Start pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("START ON");
        Udp.endPacket();
      }

      if (__slct == 0 && slct == 1) {
        Serial.println("Select released");
        Udp.beginPacket(ip, 8888);
        Udp.write("SELECT OFF");
        Udp.endPacket();
      } else if (__slct == 1 && slct == 0) {
        Serial.println("Select pressed");
        Udp.beginPacket(ip, 8888);
        Udp.write("SELECT ON");
        Udp.endPacket();
      }


    // Close the connection
    __up = up;
    __down = down;
    __left = left;
    __right = right;
    __a = a;
    __b = b;
    __strt = strt;
    __slct = slct;
    Serial.println();
    Serial.println("closing connection");
    tick = false;
    //wdelay(50); // execute once every 5 minutes, don't flood remote service


    // send a reply, to the IP address and port that sent us the packet we received
  }
 }
