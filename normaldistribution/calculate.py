import sympy as sp
from sympy import *
import numpy as np

xx, sigma, mu = sp.symbols("x, sigma, mu")
y = (1/sp.sqrt(2*sp.pi*sigma)) * sp.exp(-(xx-mu)**2/(2*sigma))   
yd = sp.integrate(y, (xx, -50, 50))
yds = sp.integrate(y, (xx, -3*sigma, 3*sigma))

percent = yds/yd
print("yd =", yd)
print("yds =", yds)
print("percentage =", percent)

