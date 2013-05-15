TinyRover
=========

TinyRover is an ATtiny85 based obstacle avoiding rover, programmed with Arduino IDE. The goal of this rover is to use few items and signals.

* [Youtube video of TinyRover in action](http://www.youtube.com/watch?v=7z_jytPrwxs)


Requirements
------------

Tiny Rover use few items:

* An [ATtiny85](http://www.atmel.com/devices/attiny85.aspx) microcontroller which will be the “brain” of the rover.
* A [Sharp GP2Y0A21YK0F](http://www.adafruit.com/product/164) IR distance sensor, which will be the “eyes” of the rover.
* A [LD293D](http://www.adafruit.com/products/807) motor driver, which will be the “nerves” of the rover.
* Two DC motors which will be the “muscles” of the rover
* A [L78S05](http://www.st.com/web/catalog/sense_power/FM142/CL1015/SC315/PF63345) voltage regulator to power all of the above.

We need to use as few items as possible because ATtiny85 provides only five I/O : four of then will be used as digital outputs to control L293D motor driver, and the last one will be used as analog input to be used with IR distance sensor.

You can find all the schematics into “doc/TinyRover.fzz”, to open with [Fritzing](http://fritzing.org/).

To program it, you'll have to use [Arduino](http://arduino.cc) IDE and upload to the ATtiny85 “TinyRover.ino” sketch. If you need info how upload sketches to ATtiny85 microcontrollers, you may refer to [http://hlt.media.mit.edu/?p=1695](http://hlt.media.mit.edu/?p=1695)

How does it work
----------------

The algorithm of TinyRover is pretty simple:

1. The rover goes forward until an obstacle is below 15 cm.
2. Then the rover goes backward until the obstacle is at least at 25cm.
3. Then the rover randomly turn left or right for 2 to 4 seconds
4. Go to step 1

The live assembly
-----------------

The frame of the rover is really too big, but I just used [MovingRaspi](https://github.com/aboudou/movingraspi)'s frame.

![Live assembly](/imgs/TinyRover.jpg "Live assembly")
