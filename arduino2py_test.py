#from __future__ import print_function

import serial
import syslog
import time


#The following line is for serial over GPIO
port = '/dev/ttyUSB0'
baud = 9600

try:
	ard = serial.Serial(port,baud,timeout=5)
except:
	print("FAILURE TO CONNECT!!!")


while True:
	#msg = ard.read(ard.inWaiting())
	msg = ard.read()
	# print ("Message from arduino: ")
	print (msg, end = "")