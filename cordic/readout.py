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


cosine = []
sine = []

for each in range(len(lines)):
    cosine.append(lines[each].split(',')[0])
    sine.append(lines[each].split(',')[1])

# for each in range(len(cosine)):
#     print(cosine[each])

# for each in range(len(sine)):
#     print(sine[each])




