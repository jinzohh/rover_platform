from rover import Rover
from inputs import get_key
import inputs

rover = Rover()

devices = inputs.devices.gamepads
device = devices[0]
#print(device)

while True:
    events = inputs.get_gamepad()
    for event in events:
        #print(event.ev_type, event.code, event.state)
        #print(event.state)
        if event.code == 'ABS_HAT0Y' and event.state == -1:
            print("Going forward")
            rover.rover_forward()
        elif event.code == 'ABS_HAT0Y' and event.state == 1:
            print("Going backward")
            rover.rover_backward()
        elif event.code == 'ABS_HAT0X' and event.state == 1:
            print("Turning right")
            rover.rover_right()
        elif event.code == 'ABS_HAT0X' and event.state == -1:
            print("Turning left")
            rover.rover_left()
        elif event.ev_type == 'Key' and event.code == 'BTN_TL' and event.state == 1:
            print("Moving left")
            rover.rover_move_left()
        elif event.ev_type == 'Key' and event.code == 'BTN_TR' and event.state == 1:
            print("Moving right")
            rover.rover_move_right()
        elif event.ev_type == 'Key' and event.code == 'BTN_C' and event.state == 1:
            print("Motor Power On")
            rover.rover_power()
        elif event.code == 'ABS_HAT0Y' and event.state == 0 or event.code == 'ABS_HAT0X' and event.state == 0 or event.ev_type == 'Key' and event.state == 0:
            print("Stopping")
            rover.stoprover()
