import mraa
import time 

an = []
	
for i in range(1,45):
	try:
		x = mraa.Aio(i)
		print x.read()
		time.sleep(1)
		an.insert(i)
	except err:
		print err

print an