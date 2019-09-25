import numpy as np
import matplotlib.pyplot as plt

#np.random.seed(19680801)

mu = 200
sigma = 3
n_bins = 72
x = np.random.normal(mu, sigma, size=72)
#x = np.ndarray(17.427, 15.960, 22.998, dtype=float)
print(x)
fig, ax = plt.subplots(figsize=(8, 4))


#n, bins, patches = 
ax.hist(x, n_bins, density=True, histtype='step', cumulative=True, label='Time')

# tidy up the figure
ax.grid(True)
ax.legend(loc='right')
ax.set_title('HW1 Traceroute')
ax.set_xlabel('Delay (ms)')
ax.set_ylabel('Probability (0-1)')

plt.show()
