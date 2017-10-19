import sympy as sp
from sympy import *
import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()

x = np.arange(-50, 50, 0.1)
mu = 0
sigma = 1
fx = (1/np.sqrt(2*np.pi*sigma)) * np.exp(-(x-mu)**2/(2*sigma))   

plt.plot(x, fx, label="N(0, 1)")

plt.legend()
plt.grid()
plt.xlabel('x')   
plt.ylabel('fx')

xx = sp.symbols("x")
y = (1/sp.sqrt(2*sp.pi*sigma)) * sp.exp(-(xx-mu)**2/(2*sigma))   
yd = sp.integrate(y, (xx, -50, 50))
yds = sp.integrate(y, (xx, -3*sigma, 3*sigma))

x1 = np.arange(-3*sigma, 3*sigma, 0.1)
y1 = (1/np.sqrt(2*np.pi*sigma)) * np.exp(-(x1-mu)**2/(2*sigma))
ax.fill_between(x1, y1, facecolor='c',alpha=0.3)

percent = yds/yd
print("percentage =", percent)

plt.show()
