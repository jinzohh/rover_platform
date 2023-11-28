import serial

class Rover:

    def __init__(self):
        self.ser_rover = serial.Serial('/dev/ttyACM0', 9600)
        self.my_boolean = False
        self.status = "OFF"

    def stoprover(self):
        self.ser_rover.write(b'0')

    def rover_forward(self):
        self.ser_rover.write(b'1')

    def rover_backward(self):
        self.ser_rover.write(b'2')

    def rover_right(self):
        self.ser_rover.write(b'3')

    def rover_left(self):
        self.ser_rover.write(b'4')

    def rover_move_right(self):
        self.ser_rover.write(b'7')

    def rover_move_left(self):
        self.ser_rover.write(b'8')

    def rover_power(self):

        if(self.my_boolean == False):
            self.ser_rover.write(b'5')
            self.my_boolean = True
            self.status = "ON"
            print("Rover is ON")

        else:
            self.ser_rover.write(b'6')
            self.my_boolean = False
            self.status = "OFF"
            print("Rover is OFF")

    def rover_off(self):
        self.ser_rover.write(b'6')
        self.my_boolean = False
        self.status = "OFF"
        print("Rover is OFF")

    def rover_on(self):
        self.ser_rover.write(b'5')
        self.my_boolean = True
        self.status = "ON"
        print("Rover is ON")

    def get_rover_status(self):
        return self.status
    

