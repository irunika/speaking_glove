import mraa
import time 

x = mraa.Gpio(17)
x.dir(mraa.DIR_OUT)

while 1:
	x.write(1)
	time.sleep(0.2)
	x.write(0)
	time.sleep(0.2)
