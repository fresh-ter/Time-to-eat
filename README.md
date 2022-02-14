# Time-to-eat
Simple laser alarm.

## Preparing for deployment
```bash
$ sudo apt install gcc-avr binutils-avr avr-libc avrdude
```
## Deployment (for ATtiny13 using USBASP)
```bash
$ avr-gcc -Wall -g -Os -mmcu=attiny13 -o main.bin main.c
$ avr-objcopy -j .text -j .data -O ihex main.bin main.hex
$ avrdude -C /etc/avrdude.conf -p attiny13 -c usbasp -U flash:w:main.hex:i -P usb -F
```

