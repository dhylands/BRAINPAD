This is a MicroPython board definition file for the BrainPad from GHI Electronics.

The product page for the BrainPad can be found here: http://docs.ghielectronics.com/hardware/products/brainpad.html

Build the firmware using:
```
cd micropython/ports/stm32/boards
git clone https://github.com/dhylands/BRAINPAD.git
cd ..
make BOARD=BRAINPAD
```

To get the BrainPad into DFU mode, press and hold the BOOT0 pushbutton
while plugging in the USB cable.

Once in DFU mode, you should be able to use the ```dfu-util --list``` command and see
something like this:
```
Found DFU: [0483:df11] ver=2200, devnum=9, cfg=1, intf=0, alt=3, name="@Device Feature/0xFFFF0000/01*004 e", serial="3473375A3334"
Found DFU: [0483:df11] ver=2200, devnum=9, cfg=1, intf=0, alt=2, name="@OTP Memory /0x1FFF7800/01*512 e,01*016 e", serial="3473375A3334"
Found DFU: [0483:df11] ver=2200, devnum=9, cfg=1, intf=0, alt=1, name="@Option Bytes  /0x1FFFC000/01*016 e", serial="3473375A3334"
Found DFU: [0483:df11] ver=2200, devnum=9, cfg=1, intf=0, alt=0, name="@Internal Flash  /0x08000000/04*016Kg,01*064Kg,03*128Kg", serial="3473375A3334"
```

Setup udev rules as described [here](https://github.com/micropython/micropython/wiki/Board-STM32F407-Discovery)

Now you can flash MicroPython using:
```
make BOARD=BRAINPAD deploy
```

The board should reboot, and you should then be able to connect to the MicroPython REPL
on the usb serial port (typically /dev/ttyACM0):
```
MicroPython v1.9.2-60-gbeeb748 on 2017-09-06; BRAINPAD with STM32F401RE
Type "help()" for more information.
>>> 
```

Now that MicroPython is installed, as long as you can get to the REPL, then you
can get back into DFU mode by using the command:
```
>>> pyb.bootloader()
```
or by pressing and holding BOOT0 while plugging in the USB cable.

Currently, the L pushbutton is connected to the User Switch.

## Peripheral Testing status:

Tested:
- USB Repl/Mass Storage
- LED (including PWM intensity)

To be tested:
- Push Buttons
- Piezo Buzzer
- Servo
- LCD
- Accelerometer
- Temperature Sensor
- Light Sensor
