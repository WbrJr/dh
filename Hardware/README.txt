So this is my hardware folder. You can find here all files you need to recreate this PCB (Gerber files, BOM, Pnp file) [or edit the existing pcb (EasyEda) - file too big. Contact me in case you are interested!]

For future revisions I want to switch to KiCad, but I wanted to use an easyer eda for my first pcb. It was hard and took long enough, but I hope I got it now. 

# How do I use the board?
Its quite simple if you have worked with UART programmers befor.
The dh_mb has a UART port, that is called 0* on the right hand side of the esp32 antenna. (the photos in the v1.1 are not up to date, there it is called H0_UART). 
To program it, just connect the UART programmer to the pins. Keep in mind, IT ONLY TAKES 3V3!!! and dont forget to swab RX and TX. So make shure to put the jumper on the 3V3 part, not the 5V part before connecting it to your esp.
The ws2812b LED that is in the center of the board needs to be supplied with 5V in order to work. The little IC on the corner of the esp32 is a level shifter from 3v3 (esp gpio out) to 5v (ws2812b data in) and needs to be supplied with 5V as well in oder to function propperly. It is enough (for testing) to hook up a 5V of the UART programmer to one of the 5V pins on one of the headers.

Now if you wnat to upload code (I am using the Arduino IDE2) you need to get the board packege for the esp32 boards. In arduino, you can use this tutorial: https://randomnerdtutorials.com/getting-started-with-esp32/ and copy this 
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
into the "Additional boards manager URLs" space.

Now go into the board manager and download the esp32 board package. 
If you have done that, connect the programmer to your board and you pc and select the correct port and choose the "ESP32 Dev Module". Before uploading, we have to set the boot mode of the esp32 to flashing. In order to do that, press the "STD_BTN" and "RST_BTN" at the same time and release the reset button first. Now you should be able to upload one of my test codes in the firmware folder to the esp.
If it can not reach the board, it is most likely not set into programming mode. Make shure to press both buttons at the same time and keep the std_btn pressed and relese the rst_btn first!
Be aware, the FastLED library is not super efficient and can break interrupts if you or libraries you use, are using them. I think the adafruit library is better in that regard but not as fast.

# And how do I use the board in an actual application?
There are some resistors (R1/R2-R3) that are meant to be selector pins for the power input you want to use the board at. In order to use the board at the VIN (big blue screw terminal) with 5V only, bridge the pads of the R3 with a little bit of solder. To use the board with more that 5.7V, you need to remove the solder from R3 and bridge R1 and R2 (seperately of cause).
Those solder pads select weather the VIN of the screw terminal is connected to the 5V rail of the baord directly or if the LDO (linear volrage regulator) for the 5V rail should be active.
What you do with the board now it up to you. I am curius what you are building with them, so let me know if you would like. 
