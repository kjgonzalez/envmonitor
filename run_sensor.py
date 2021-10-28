'''
while shtc3 sensor is connected, collect data and store it to specific file for access by other programs
'''

import time
import busio, board, adafruit_shtc3
i2c = busio.I2C(board.SCL, board.SDA)
sht = adafruit_shtc3.SHTC3(i2c)

while True:
    t,rh = sht.measurements
    print("Temp (C):",t)
    print("RelH (%):",rh)
    print('-'*20)
    # with open('data','w') as f:
    #     f.write("{},{}\n".format(t,rh))
    time.sleep(1)
    
print('Stopping Program...')

