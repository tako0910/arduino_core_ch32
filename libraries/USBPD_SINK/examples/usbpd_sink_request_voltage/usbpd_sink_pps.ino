#include <usbpd_def.h>
#include <usbpd_sink.h>

void setup()
{
    Serial.begin(115200);
    usbpd_sink_init();
    while (!usbpd_sink_get_ready())
    {
        delay(100);
    }

    if (usbpd_sink_get_pps_num() > 0)
    {
        for (int i = 0; i < usbpd_sink_get_pps_num(); i++)
        {
            Serial.printf("pps[%d] min:%d max:%d current:%d\r\n", i, usbpd_sink_get_pps_min_voltage(i), usbpd_sink_get_pps_max_voltage(i), usbpd_sink_get_pps_current(i));
        }
    }
    else
    {
        Serial.println("PPS not supported");
    }
}

void loop()
{
    delay(1000);
}