'''
while shtc3 sensor is connected, collect data and store it to specific file for access by other programs
'''

import os
import time
import argparse
from datetime import datetime
import busio, board, adafruit_shtc3
i2c = busio.I2C(board.SCL, board.SDA)
sht = adafruit_shtc3.SHTC3(i2c)
basepath = os.path.dirname(__file__)


if(__name__=='__main__'):
    p=argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    p.add_argument('--period',type=int,default=1800,help='Interval between measurements in [s]')
    args= p.parse_args()
    PERIOD = args.period
    fpath = os.path.join(basepath,'log.csv')
    while True:
        ts = str(datetime.now()).split('.')[0]
        t,rh = sht.measurements
        print("Time    :",ts)
        print("Temp (C):",t)
        print("RelH (%):",rh)
        print('-'*20)
        with open(fpath,'a') as f:
            f.write("{},{},{}\n".format(ts,t,rh))
            f.close()
        time.sleep(PERIOD)
    
    print('Stopping Program...')

