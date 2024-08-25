import serial
import time
import string

# Reading and writing data from and to Arduino serially.
# rfcomm0 -> this could be different depending on your setup
ser = serial.Serial("/dev/rfcomm0", 9600)
ser.write(str.encode('Start\r\n'))

while True:
    if ser.in_waiting > 0:
        rawserial = ser.readline()
        cookedserial = rawserial.decode('utf-8').strip('\r\n')
        print(cookedserial)