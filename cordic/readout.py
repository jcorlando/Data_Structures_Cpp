import numpy as np
import matplotlib.pyplot as plt

with open('output.dat') as f:
    lines = f.read().splitlines()

cosine = []
sine = []

for each in range(len(lines)):
    cosine.append(float(lines[each].split(',')[0]))
    sine.append(float(lines[each].split(',')[1]))

#------------------Define and set x-axis------------------------
dt = np.linspace(0, 360, 1081)
#------------------Define and set x-axis------------------------

#---------------Plot Cosine---------------
plt.figure(1)
plt.title("Cosine")
plt.plot(dt, cosine)
plt.xlabel("Degrees")
#---------------Plot Cosine---------------

#---------------Plot Sine---------------
plt.figure(2)
plt.title("Sine")
plt.plot(dt, sine)
plt.xlabel("Degrees")
#---------------Plot Sine---------------

#-------Show all Plots and Figures-------
plt.show()
#-------Show all Plots and Figures-------

