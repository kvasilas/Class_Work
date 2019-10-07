import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
ewma = pd.Series.ewm

x = np.linspace(0, 2000, 10000)
y = pd.read_csv(r'C:\Users\USER\Documents\coding\Class_Work\CPE490\hw\hw2\cut_data.csv', header=None)
#print(type(y))
a = y.values.flatten()
df = pd.Series(a)

fwd = ewma(df, span=1.5).mean()  # span = 1.5 -> 0.8 alpha
plt.title('Round Trip Times')
plt.plot(df, 'r', label='Real')
plt.plot(fwd, 'b--', label='EWMA')
plt.xlabel('Samples')
plt.ylabel('Delay')
plt.legend()
plt.show()
