'''
imitate data coming from sensors to debug while testing off of rpi
'''

from random import random

class DummySHTC3:
    def __init__(self):
        pass
    @property
    def measurements(self):
        return (20+2*random(),40+2*random())
