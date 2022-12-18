'''
while shtc3 sensor is connected, collect data and store it to specific file for access by other programs
'''

import os
import time
import argparse
from datetime import datetime
if('arm' in os.uname().machine):
    import busio, board, adafruit_shtc3
    i2c = busio.I2C(board.SCL, board.SDA)
    sht = adafruit_shtc3.SHTC3(i2c)
else:
    print('!!!!! NOT ON RPI, USING DUMMY LIBRARY !!!!!')
    import dummylib as dl
    sht = dl.DummySHTC3()
fpath = os.path.join(os.path.dirname(__file__),'data/log_shtc3.csv') # appends to data


if(__name__=='__main__'):
    p=argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    p.add_argument('--period',type=int,default=1800,help='Interval between measurements in [s]')
    p.add_argument('--nolog',default=False,action='store_true',help='Disable logging')

    args= p.parse_args()
    PERIOD = args.period
    LOG = not args.nolog
    print('PERIOD:',PERIOD)
    print('LOG:',LOG)

    while True:
        ts = str(datetime.now()).split('.')[0]
        t,rh = sht.measurements
        print('Time: {} | Temp (C): {:.4f} | RelH (%): {:.4f}'.format(ts,t,rh),end='')
        if(LOG):
            firstwrite=not os.path.exists(fpath)
            with open(fpath,'a') as f:
                if(firstwrite): f.write('Time,Temp_C,RH_%\n')
                f.write("{},{},{}\n".format(ts,t,rh))
                f.close()
            print(' | Saved ')
        else:
            print('')
        time.sleep(PERIOD)
    
    print('Stopping Program...')
# eof
