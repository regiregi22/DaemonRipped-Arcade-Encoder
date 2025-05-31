# DaemonRipped Arcade Encoder
This is an arcade controller project based on MickGyver's DaemonBite joystick, but removing all extra functions to a minimum. A four directions stickk and up to 12 buttons are supported. It uses any standerd Arduino Pro Micro board.

Debouncing for mechanical switches is already activated (adds around 0.035ms latency, which is nothing). 10ms should be an ideal value, lowering it might cause problems, and it shouldn't be any higher than 20ms.

PENDIENTE:  
The input lag for an arcade controller or adapter built around this project is minimal. Here is the result from a test with a 1ms polling rate:

| Samples | Average | Max | Min | Std Dev |
| ------ | ------ | ------ | ------ | ------ | 
| 13962 | 0.74ms | 1.28ms | 0.23ms | 0.29ms |  


## Wiring:  
The wiring is simple. Connect one leg of each microswitch to GND and the other leg to the digital pin according to the schematic below. That's it!  

![Assemble1](images/daemonbite-arcade-encoder-wiring.png)

PENDIENTE:  
## Programming the Arduino:  
1. Solder J1 on the Arduino Pro Micro (to properly run 5v for 16Mhz).
1. Open up Arduino, then go to the Preferences (File > Preferences). Then, towards the bottom of the window, paste this URL into the "Additional Board Manager URLs" text box: https://raw.githubusercontent.com/sparkfun/Arduino_Boards/main/IDE_Board_Manager/package_sparkfun_index.json
1. Open the Board Manager by clicking Tools, then hovering over the Board selection tab and clicking Board Manager. Search for 'sparkfun' in the Board Manager. You should see the SparkFun AVR Boards package appear. Click install.
1. Download the free Arduino IDE: https://www.arduino.cc/en/main/software
2. Connect the Arduino Pro Micro to a USB port and let the drivers install.
3. Choose the correct board and virtual COM port in the IDE.
3. Compile/Upload the project.
