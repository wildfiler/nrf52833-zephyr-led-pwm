#include <zephyr.h>
#include <device.h>
#include <drivers/led.h>

#define LEDS DT_PATH(pwmleds)
#if DT_NODE_HAS_STATUS(LEDS, okay)
#else
#error "No device :("
#endif

void main(void)
{
	const struct device *led = DEVICE_DT_GET(LEDS);

	led_set_brightness(led, 0, 1);
	led_set_brightness(led, 1, 5);
	led_set_brightness(led, 3, 20);
	led_set_brightness(led, 2, 80);


  // int row[] = {0, 1, 5, 20};
  int row[] = {20, 5, 1, 0};
	int leds[] = {0, 1, 2, 3};
	int leds_order[] = {0, 1, 3, 2};

	while(1)
	{
		for (int i = 0; i < 4; i++)
		{
			led_set_brightness(led, leds_order[i], row[leds[i]]);
			leds[i] += 1;
			if(leds[i] > 3) {
				leds[i] = 0;
			}
		}

		k_sleep(K_MSEC(200));
	}
}