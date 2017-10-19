import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()

x = np.arange(-20, 60, 0.1)
mu = [0, 0, 0, 4, 44]
si = [1, 4, 9, 4, 4]
y01 = (1/np.sqrt(2*np.pi*si[0])) * np.exp(-(x-mu[0])**2/(2*si[0]))   
y04 = (1/np.sqrt(2*np.pi*si[1])) * np.exp(-(x-mu[1])**2/(2*si[1]))   
y09 = (1/np.sqrt(2*np.pi*si[2])) * np.exp(-(x-mu[2])**2/(2*si[2]))   
y44 = (1/np.sqrt(2*np.pi*si[3])) * np.exp(-(x-mu[3])**2/(2*si[3]))   
y444 = (1/np.sqrt(2*np.pi*si[4])) * np.exp(-(x-mu[4])**2/(2*si[4]))   


plt.plot(x, y01, color='red', label="N(0, 1)")
plt.plot(x, y04, color='green', label="N(0, 4)")
plt.plot(x, y09, color='blue', label="N(0, 9)")
plt.plot(x, y44, color='indigo', label="N(4, 4)")
plt.plot(x, y444, color='black', label="N(44, 4)")

plt.legend()
plt.grid()
plt.title("graph of normal distribution ")
plt.xlabel('x')   
plt.ylabel('fx')


plt.show()
