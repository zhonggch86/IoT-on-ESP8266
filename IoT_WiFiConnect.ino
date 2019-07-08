#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>


#define TFT_CS     D1
#define TFT_RST    D2  
#define TFT_DC     D3
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

 



#include <ESP8266WiFi.h>
/*
void smartConfig()
{
  WiFi.mode(WIFI_STA);
  Serial.println("\r\nWait for Smartconfig");
  WiFi.beginSmartConfig();
  while (1)
  {
    Serial.print(".");
    //digitalWrite(LED, 0);
   // delay(500);
   // digitalWrite(LED, 1);
   // delay(500);
    if (WiFi.smartConfigDone())
    {
      Serial.println("SmartConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      break;
    }
  }
}
 
void setup()
{
  Serial.begin(115200);
  Serial.println("Start module");
  //pinMode(LED, OUTPUT);
  //digitalWrite(LED, 0);
  smartConfig();
}
 
void loop()
{
  delay(100);
  Serial.println("Start module");
}
*/

bool autoConfig()
{
  WiFi.begin();
  for (int i = 0; i < 20; i++)
  {
    int wstatus = WiFi.status();
    if (wstatus == WL_CONNECTED)
    {
      Serial.println("AutoConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      WiFi.printDiag(Serial);
      return true;
      break;
    }
    else
    {
      Serial.print("AutoConfig Waiting......");
      Serial.println(wstatus);
      delay(1000);
    }
  }
  Serial.println("AutoConfig Faild!" );
  return false;
  //WiFi.printDiag(Serial);
}
void smartConfig()
{
WiFi.mode(WIFI_STA);
  Serial.println("\r\nWait for Smartconfig");
  WiFi.beginSmartConfig();
  while (1)
  {
    Serial.print(".");
    if (WiFi.smartConfigDone())
    {
      Serial.println("SmartConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      WiFi.setAutoConnect(true);  // 设置自动连接
      break;
    }
    delay(1000); // 这个地方一定要加延时，否则极易崩溃重启
  }
}

void setup()
{
  Serial.begin(115200);

  if (!autoConfig())
  {
    Serial.println("Start module");
    smartConfig();
  }
}

void loop()
{
  delay(1000);
  Serial.println("loop");
}

/*
 * 
 void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color); 
  // ST7735_BLUE; ST7735_WHITE; ST7735_GREEN; ST7735_YELLOW; ST7735_MAGENTA; ST7735_RED
  tft.setTextWrap(true);
  tft.print(text);
}
*/

/*
void led(int i){
  int a;
  switch (i){
    case 1: a = 500;
    Serial.println(1);
    break;
    case 2: a = 100;
    Serial.println(0);
    break;
    case 3; a = 1000;
  }
  digitalWrite(15,LOW);
  delay(a);
  digitalWrite(15,HIGH);
  delay(a);
}
*/
