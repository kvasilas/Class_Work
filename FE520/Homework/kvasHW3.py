#Kirk Vasilas - 10410943
#Homework 3
#Due October 19th 11:59 PM
#I pledge my honor that I have abided by the stevens honor code
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import types


#Question 1
test = np.random.randint(-100,100,100)
def buckets(listIn, num):
    g = max(listIn)
    h = min(listIn)
    _range = g - h
    size_b = _range/num
    listIn.sort()
    temp = h
    p = []
    for x in range(num):
        p.append(temp)
        temp = temp + size_b
    plength = len(p)
    totals = []
    for i in range(plength-1):
        count = 0
        for j in range(len(listIn)):
            if (listIn[j] >= p[i] and listIn[j] < p[i+1]):
                count = count + 1
        totals.append(count)
    z = sum(totals)
    totals.append(100-z)
    #sum[plength - 1] = sum[plength -1] + 1

    plt.bar(p, totals, color = 'r', width = 10)
    plt.grid(True)
    return(plt.show())

#Question 2
class abstractRandom(object):
    def __init__(self, seed):
        self.current = seed

    def __iter__(self):
        return(self)

    def __next__(self):
        self.current = self.generator(self.current)
        return(self.current)

class Random(abstractRandom):
    def __init__(self, seed, generator):
        super().__init__(seed)
        self.generator = generator
#Bonus 1
def valid(strin):
    boolOut = True
    stack = []

    for char in strin:
        if char == '[' or char == '(' or char == '{':
            stack.append(char)
        else:
            if char == ']' and stack[-1] == '[':
                stack.pop()
            elif char == ')' and stack[-1] == '(':
                stack.pop()
            elif char == '}' and stack[-1] == '{':
                stack.pop()
            else:
                boolOut = False
                break
    return (boolOut)


#Bonus 2
def long(strin):
    odd = enumerate(list(strin))
    even = []
    cnt = 0
    while (cnt < len(strin)-1):
        if list(strin)[cnt] == list(strin)[cnt + 1]:
            even.append((cnt, strin[cnt] + strin[cnt + 1] ))
        cnt = cnt + 1
        return(even)

#main
q1 = int(input('Ques 1 - Input Number of buckets: '))
buckets(test, q1)

m = 771
a = 331
b = 17
f = lambda x: ((a*int(m*x) + b) % m)/m

instance = Random(.5, f)
instanceIter = iter(instance)
next(instanceIter)

temp = [next(instanceIter) for _ in range(200)]
aryTemp = np.array(temp)
y = np.where(aryTemp > .5,1,-1)
import time
plt.plot(np.cumsum(y), 'b-*')
plt.title('Question 2')
plt.grid(True)
time.sleep(3)
plt.show()

b1 = input('Bonus 1: Enter a string including ({[]}): ')
print(valid(b1))

b2 = input('Bonus-2: enter a string: ', )
print(long(b2))
