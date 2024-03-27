# Getting Started

rover.py is a custom Python library to easily turn a Raspberry Pi into a rover (nearly as plug-and-play). Below are the instructions on how to call functions from the rover library.

Make sure rover.py is in the same directory as your main Python script.
For exmaple, the rover_controller.py should be in the same directory as rover.py.

### Prerequisite
Use an Arduino Uno with a motor shield such as the Adafruit Motor Shield or similar. Connect the motors, wheels, and an external power supply to power the motor shield separately from the Arduino Uno. The rover.py has a function to turn the motor shield on and off, so if you'd like to utilize this function, add a relay to the motor shield and make sure Pin 2 controlls the relay swtich to power the motor shield. See motor_v2.ino file for details. Finally, uplaod the motor_v2.ino file into the Arudino Uno with motor shield.

Next, on a Raspberry Pi with a USB connector, connect a wireless game controller and run the rover_controller.py. As mentioned above, make sure rover.py is in the same directory as rover_controller.py so that the library can be accessed without any issues.

That's basically it! Time to make a robot out of a Raspberry Pi!

Make sure git is installed:
```
sudo apt install git
```

Make sure inputs library is installed:
```
pip install inputs
```

Clone this repository:
```
git clone https://github.com/jinzohh/rover_platform.git
```

Change directory to the rover_platform directory after cloning:
```
cd rover_platform
```

Run rover_controller.py script:
```
python rover_controller.py
```

### Moving the rover around

1. Create a new Python script and import the library as below:

```
from rover import Rover

rover = Rover()

# Move forward
rover.rover_forward()

# Move backward
rover.rover_backward()

# Turn right
rover.rover_right()

# Turn left
rover.rover_left()

# Move right (moving sideways)
rover.rover_move_right()

# Move left (moving sideways)
rover.rover_move_left()

# Stop
rover.stoprover()

# Power On/Off
rover.rover_power()  # Calling this will turn on or turn off. Default is off.

# Power Off (hard switch)
rover.rover_off()

# Power On (hard switch)
rover.rover_on()

# Get power on/off status
rover.get_rover_status()  # Calling this will tell you the current state of power of the rover.
```



