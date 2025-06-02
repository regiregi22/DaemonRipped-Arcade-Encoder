# DaemonRipped Arcade Encoder
This is an arcade controller project based on MickGyver's DaemonBite, but removing all extra functions. A four-direction stick and up to 12 buttons are supported. It uses any standard Arduino Pro Micro board.  

Debouncing for mechanical switches is already activated (adds only around 0.035ms latency). 10ms setting for debounce should be an ideal value, lowering it might cause problems, and it shouldn't be any higher than 20ms.  
<br />
## Performance:
-The input lag for an arcade controller built around this project is minimal. Here is the result from a [test with a native polling rate of 1ms](https://inputlag.science/controller/methodology):  

#### DaemonRipped Arcade Encoder (tested with debouncing on):
| Samples | Average | Max | Min | Std Dev | % On next frame |
| ------ | ------ | ------ | ------ | ------ | ------ | 
| 1000 | 0.72ms | 1.19ms | 0.41ms | 0.24ms | 96% |  

<br />  

-Just for comparison, this is the latency for a common low latency controller:
#### Sony DualShock 4 (Bluetooth) (native polling rate 1ms):
| Samples | Average | Max | Min | Std Dev | % On next frame |
| ------ | ------ | ------ | ------ | ------ | ------ |
| 1000 | 3.00ms | 12.0ms | 2.20ms | 0.70ms | 83% |  


#### Sony DualShock 4 (Wired) (native polling rate 4ms):
| Samples | Average | Max | Min | Std Dev | % On next frame | 
| ------ | ------ | ------ | ------ | ------ | ------ |
| 1000 | 10.3ms | 12.4ms | 7.50ms | 1.20ms | 39% |  

<br />  

## Wiring:  
The wiring is simple. Connect one leg of each microswitch to GND and the other leg to the digital pin according to the schematic below:  

![Assemble1](images/daemonbite-arcade-encoder-wiring.png)
<br />
## Programming the Arduino board:  
1. Solder J1 on the Arduino Pro Micro (to properly run 5v for 16Mhz).
2. Download the free Arduino IDE: https://www.arduino.cc/en/main/software.
3. Connect the Arduino Pro Micro to a USB port and let the drivers install.
4. Open up Arduino, then go to the Preferences (File > Preferences). Then, towards the bottom of the window, paste this URL into the "Additional Board Manager URLs" text box: https://raw.githubusercontent.com/sparkfun/Arduino_Boards/main/IDE_Board_Manager/package_sparkfun_index.json.
5. Open the Board Manager by clicking Tools, then hovering over the Board selection tab and clicking Board Manager. Search for 'sparkfun' in the Board Manager. You should see the SparkFun AVR Boards package appear. Click install. Close Arduino IDE.
6. Open the file "C:\Users\USER\AppData\Local\Arduino15\packages\SparkFun\hardware\avr\1.1.13\boards.txt" and edit the name of the USB joystick in the string "promicro.build.usb_product=". Change the value of "promicro.build.vid=" if using more than one joystick.
7. Select Tools > Board: > SparkFun AVR Boards > SparkFun Pro Micro.
8. Select Tools > Port: > COM Port.
9. Select Tools > Processor: > ATmega32U4 (5V, 16 Mhz).
10. Compile/Upload the project.
