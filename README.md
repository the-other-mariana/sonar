
# Sonar

<img align="right" width="300px" src="https://github.com/the-other-mariana/sonar/blob/master/media/sonar.png">


Sonar is a Sensory Substitution Device built as a belt that helps the blind navigate in the world based on ultrasonic sensor object detection that trigger a vibration rythm.

## Specifications

- Arduino Board: `Arduino Nano`
- Processor: `ATMega328P`
- Chip for USB Driver: `CH340G`
- Sensor: `Ultrasonic Sensor HC-SR04` x3
- Sensor: `Touch Sensor TTP223B` x1
- Motor: `Vibration Motor` x3
- Battery: Any recharging smartphone power bank of 5V,1A

### Vibration Motor

There are many options for these motors, but the ones used are the following. <br />

![image](https://github.com/the-other-mariana/sonar/blob/master/media/motors.jpg?raw=true) <br />

## Wiring

The complete wiring of the system should look as below. <br />

![image](https://github.com/the-other-mariana/sonar/blob/master/media/wiring.png?raw=true) <br />

## Compile & Run

1. Open the [.ino code](https://github.com/the-other-mariana/sonar/blob/master/ultrasonic-vibration-rythm/ultrasonic-vibration-rythm.ino) that implements the solution.

2. Click on the left-corner button that has a check on it. It will compile and verify the program.

3. Click on the Upload button, besides the Verify button.

4. Buckle the belt around your waist, **over** your clothes.

5. Press the touch sensor that is on the right of the belt, to turn on the processing.

Then, the ultrasonic sensor array (size 3) does its job in order to activate the vibration motors until you press again the touch sensor that acts as a On/Off button.


<br />

![image](https://github.com/the-other-mariana/sonar/blob/master/prototype/waist01.jpg?raw=true) <br />

## Stop

1. Touch the button to turn off the sensor processing.

2. Unplug the Arduino from the battery.

3. Take off the belt.
