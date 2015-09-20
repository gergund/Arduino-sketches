#!/usr/bin/env python

import time,serial

comm =  serial.Serial('/dev/ttyACM0',9600)

while True:
	comm.write('a')
	time.sleep(1)
	comm.write('b')
        time.sleep(1)
	comm.write('c')
        time.sleep(1)
	comm.write('d')
        time.sleep(1)
	comm.write('e')
        time.sleep(1)
	comm.write('e')
	time.sleep(1)
	comm.write('d')
	time.sleep(1)
	comm.write('c')
	time.sleep(1)
	comm.write('b')
	time.sleep(1)
	comm.write('a')
	
	
