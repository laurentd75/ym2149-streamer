#include "uart.h"
#include "ym2149.h"

#define LED PORTB5  // Digital port 13 noted the board has an led on pin 13 already(should be yellow and be right below the pin)
void set_led_out(void) {
  DDRB |= 1 << LED;
}

int main() {
  unsigned int i;
  unsigned char data[16];

  set_ym_clock();
  set_bus_ctl();
  initUART();
  set_led_out();

  for/*ever*/(;;) {
    for (i=0; i<16; i++) {
      data[i] = getByte();
    }
    for (i=0; i<15; i++) {
      send_data(i, data[i]);
    }
  }

  return 0;
}