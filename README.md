# dh
This is my second version of my self made smart home. The fist version was completely developed on the raspberry pi 3 and esp8266 dev boards. I made some interesting choices, so creating a second version is the only logical step to continue this project.

For this project I designed and ordered a custom pcb (dh_mb) with the following characteristics:
  - esp32-wroom32-e (4mb)
  - ws2812b indicator led
  - reset and std button
  - 5-26V input (lower voltages recommended, the linear voltage regulators are extremely inefficient)
  - 4 pin header packets of 7 (4 GPIO, 3v3, 5v, GND)
  
The basic idea is, that the 4 pinheader packets can be used to create custom modules, that can be added into the firmware easily and alow the user to create new smart home devices very fast and easy.
  
There are already some things I would like to change about the board, like:
  - adding a usb-c port
  - changing some lables
  - switching the uart pins around so the esp can not be shorted by accidentally flipping the programmer connector
  - exchanging the diode with a pnp reverse polarity protection
 I suppose there are going to be a lot of other changes I want to add to this board to make it more safe, versitile and easier to use.
 So far the pcb is working propperly though.
 
 My next goals are:
  - creating a basic but modular firmware for the dh_mb
  - creating a second version of the smart home server (propably with node.js, not apache2. but I have to read into that a lot more)
    - the backend part is ok for now i think, but I want to work on the frontend more and get into typescript and javascript (I used a lot of php for my first version :( I know, I am sorry)

All this will take very long i suppose, because I can not work on this full time. And I am still studying electrical engineering and information technology, so I am by no means experienced. This is a big project for me, but I had so much fun with the first version and want to bring this to the next step.

I want to invite you to contribute to this project if you are interested. I appreciate any help!
