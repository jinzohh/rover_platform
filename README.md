# Getting Started

rover.py is a custom Python library to control the rover platform. Below are the instructions on how to call functions from the rover library.

Make sure rover.py is in the same directory as your main Python script.

You will need my pre-assembled rover to use rover.py script. This script is not compatible with other rover platforms.

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



