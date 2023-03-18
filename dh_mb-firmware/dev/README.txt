This folder contains some seperated parts of the final firmware. It contains tests on different libraries and ways to solve problems.

WS2812B library:
In the little research I did, to decide what library I want to use to control the WS2812B LED, I sumbled upon this test/comparison:
https://blog.ja-ke.tech/2019/06/02/neopixel-performance.html
It compares the FastLED, Adafruit NeoPixel and NeoPixelBus libraries in different memory usage and speed/reaction time for 100 and 1000 LEDs. Its quite interesting acutally.
In conclusion, the NeoPixel library is the smallest in size, uses the least ram and is extremely fast, regarding the delay between the command in code and the reaction time untill it starts to transmit.
For 100 LEDs its a lot slower than the FastLED when it comes to setting individual or multiple leds, but faster with 1000 LEDs. The NeoPixelBus library is in almost all tests the worst.
The issue with the FastLED is, that it overwrites interrupts. That means, that if you use sevevos, sensors or want to detect button preses, the FastLED can block the interrupt, leading to information losses.
As far as I understood, it does that, because it uses RMT, which (in the esp32 is part of the hardware?) can transform user code to a waveform. It is very versatile and can be used for transmitting and recieving data. The WS2812B do not have a timing/clock pin, that means the information send to them has to be very prcise in timing. When we now allow interrupts, this timing can be disturbed and send invalid or incpmplete data to the LEDs. This can be overwritten by allowing interrupts, if they are crucial to the application. I wonder if that could be solved by usind the second core of the esp32, that is (as fas as I know) used for the wirreless part of the esp32.

My conclusion is, that I will be usind the FasLED library (by Daniel Garcia) because it seems to be the most versitile. In case I run into problems with the interrupts, I will see if allowing interrupts works, if not I will have to switch to a different library.
