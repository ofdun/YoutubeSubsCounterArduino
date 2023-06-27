#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include "secrets.h"

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9

MCUFRIEND_kbv tft;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    uint16_t ID = tft.readID();
    tft.begin(ID);
    tft.setRotation(3);
    tft.fillScreen(0x0000);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(2);
    tft.println("TFT is prepared to act!");
    delay(1000);
}

void loop()
{
    // put your main code here, to run repeatedly:
    int subs = get_subs();
    // size_t *subs = get_subs();
    tft.fillScreen(0x0000);
    tft.setCursor(10, 50);
    tft.print(subs);
    delay(1000);
}

char *get_request_url()
{
    // Compute the length of the URL string
    int url_length = strlen("https://www.googleapis.com/youtube/v3/channels?part=statistics&id=&key=") + strlen(API_KEY) + 1;

    // Allocate memory for the URL string
    char *url = (char *)malloc(url_length);

    sprintf(url, "https://www.googleapis.com/youtube/v3/channels?part=statistics&id=&key=%s", API_KEY);
    return url;
}

int get_subs()
{
}
