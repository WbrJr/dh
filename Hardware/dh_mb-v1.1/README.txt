Here are the files of the first produced pcb

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
