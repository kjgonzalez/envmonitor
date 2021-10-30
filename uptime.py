'''
simple updater of current uptime

this opens / generates a file, counts how many lines are in the file, and then keeps increasing the
    uptime for that particular line.
'''

import argparse
import time
import os
from datetime import datetime as dt
filepath = 'data/uptime.txt'

class Uptime:
    def __init__(self,fpath=None):
        if(fpath is None):
            # attempt to find file on own
            self.fpath = os.path.join(os.path.dirname(__file__),'data','uptime.txt')
        else:
            self.fpath = fpath
        self.t0 = self.now()
        self.stamp = str(self.t0)

        # check if file exists. if not, create it
        if (not os.path.exists(self.fpath)):
            print("file doesn't exist, creating at:",self.fpath)
            with open(self.fpath, 'w') as f:
                f.write('date,uptime (D days HH:MM:SS)\n')

        self.raw = [i for i in open(self.fpath)]
        self.raw.append('')

    @staticmethod
    def now():
        return dt.now().replace(microsecond=0)

    def elapsed(self):
        return self.now()-self.t0

    def updatestr(self):
        return '{},{}\n'.format(self.stamp,self.elapsed())

    def updateFile(self):
        self.raw[-1] = self.updatestr()
        with open(self.fpath,'w') as f:
            [f.write(i) for i in self.raw]
        print('uptime:',self.raw[-1][:-1])
        return 0


if(__name__ == '__main__'):
    p = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    p.add_argument('--period', default=60*30, help='update period [s]')
    args = p.parse_args()
    per = int(args.period)

    # initial time write
    print('update period [s]:',per)
    up = Uptime(filepath)

    while(True):
        up.updateFile()
        time.sleep(per)

# eof
