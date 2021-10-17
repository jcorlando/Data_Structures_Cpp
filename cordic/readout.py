import wave
import numpy as np
import sys
import math
import struct
import matplotlib.pyplot as plt
from scipy import signal
from scipy.signal import lfilter, butter, kaiserord, firwin, freqz
from scipy.io import wavfile


with open('output.dat') as f:
    lines = f.read().splitlines()


for each in range(len(lines)):
    print(lines[each])



