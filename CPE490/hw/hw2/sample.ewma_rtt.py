import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
ewma = pd.Series.ewm

x = np.linspace(0, 2 * np.pi, 100)
#x = np.linspace(0, 2000, 10000)
y = 2 * np.sin(x) + 0.1 * np.random.normal(x)
df = pd.Series(y)
print(type(y))
print(y)
print(type(df))

# take EWMA in both directions then average them
fwd = ewma(df, span=10).mean()  # take EWMA in fwd direction
bwd = ewma(df[::-1], span=10).mean()  # take EWMA in bwd direction
filtered = np.vstack((fwd, bwd[::-1]))  # lump fwd and bwd together
filtered = np.mean(filtered, axis=0)  # average
plt.title('filtered and raw data')
plt.plot(y, color='orange')
plt.plot(filtered, color='green')
plt.plot(fwd, color='red')
plt.plot(bwd, color='blue')
plt.xlabel('Samples')
plt.ylabel('Delay')
#plt.show()
