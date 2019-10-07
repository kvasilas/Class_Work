import pandas as pd
import numpy as np

a = pd.read_csv(r'C:\Users\USER\Documents\coding\Class_Work\CPE490\hw\hw2\cut_data.csv', header=None)
print("a ", a)
print(type(a))
b = a.to_numpy()
print("b ", b)
print(type(b))

c = a.values.flatten()
print("C ", c)
print(type(c))