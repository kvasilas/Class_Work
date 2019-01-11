#---------------------------------------------------------------
#Kirk Vasilas - 10410943
#Homework 4
#Due November 19th 11:59 PM
#I pledge my honor that I have abided by the stevens honor code
#-------------------------------------------------------------
import math
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sqlite3

#question 1
def callOption(K, T, S0, r, sigma, m):
    units = np.random.randn(m)
    stock = S0*math.exp((r-.5*sigma**2)*T+sigma*math.sqrt(T))*units
    stock_price = np.where(stock > K, stock - K, 0)
    st_p_avg = np.sum(stock_price)/m
    return(math.exp(-r*T)*st_p_avg, stock)
#question 2
def bondValue(P, T, f, c, y):
    x = np.arange(1, f*T+1)/f
    return (P*np.exp(-y*T)+ (P*c/f) + np.sum(np.exp(-y*x) ))

def bondDuration(P, T, f, c, y):
    x = np.arrange(1, f*T+1)/f
    num = np.exp(-y*T)*T*P + (c * P / f ) * np.sum(np.exp(-y * x) * x)
    den =  bondValue(P, T, f, c, y)
    return (num/den)
def bondYield(y):
    return(bondValue(P, T, f, c, y) -pv)
def NewtonStep():
    return((bondValue(P, T, f, c, y) -pv)/bondValue(P, T, f, c, y))
#question 3
def kendall(a,b):
    import scipy.stats as stats
    if len(a) != len(b):
        return("Differnt Lengths, Cannot compute Kendall")
    else:
        tau, p = stats.kendalltau(a,b)
        return tau
#bonus 1
def arrayPart(a):
    a.sort()
    return sum(a[::2])
#bonus 2
def trans(A):
    B, C = len(A), len(A[0])
    ans = [[None] * B for i in range(C)]
    for r, row in enumerate(A):
        for c, val in enumerate(row):
            ans[c][r] = val
    return ans
#Q1-------------------------------------------
K = 105
T = 3
r = 0.05
sigma = 0.2
S0 = 100
m = 10000
value, stock = callOption(K, T, S0, r, sigma, m)
print('Question 1', "\n" 'Expected value of option = ', value)
#plot code
a = pd.Series(stock)
b = pd.cut(a, m)
c = b.value_counts()
temp = c.sort_index()
x = [entry.left for entry in temp.index]
y = temp.values
plt.bar(x,y, color = 'r')
plt.xlabel('stocks')
plt.ylabel('value')
plt.xlim([0,300])
#plt.ylim([0,100]) #skews graph
plt.title('Question 1')
plt.show()

#Q2----------------------------------------
P=100  #dollars
pv=90  #dollars
T=1  #years
f=4  #quarterly
c=0.05  #coupon
y = .2

print('Question 2',"\n" "Bond Yield = ", bondYield(y))

#Q3-------------------------------------------------------------------
appl = pd.read_csv('./APPL.csv')
micro = sqlite3.connest('./MSFT.db')
msft = pd.read_sql('SELECT CLOSE FROM MSFT', micro)
print('Question 3',"\n"'kendall Sattistic = ', kendall(appl['Close'], msft['Close']))

#Bonus 1
print('(Bonus 1) Enter numbers followed by space key to input array.')
x = input('Enter Numbers:' )
b1 = list(map(int, x.split()))
print(arrayPart(b1))
#Bonus 2
print('(Bonus 1) Enter numbers followed by space key to input array.')
y = input('Enter Numbers:' )
b2 = list(map(int, x.split()))
print(trans(b2))
    #Q1-------------------------------------------
K = 105
T = 3
r = 0.05
sigma = 0.2
S0 = 100
m = 10000
value, stock = callOption(K, T, S0, r, sigma, m)
print('Expected value of option = ', value)
#plot code
a = pd.Series(stock)
b = pd.cut(a, m)
c = b.value_counts()
temp = c.sort_index()
x = [entry.left for entry in temp.index]
y = temp.values
plt.bar(x,y, color = 'r')
plt.xlabel('stocks')
plt.ylabel('value')
plt.xlim([0,300])
#plt.ylim([0,100]) #skews graph
plt.title('Question 1')
plt.show()

#Q2----------------------------------------
P=100  #dollars
PV=90  #dollars
T=1  #years
f=4  #quarterly
c=0.05  #coupon
y = .2

print('Question 2',"\n" "Bond Yield = ", bondYield(y))

#Q3-------------------------------------------------------------------
appl = pd.read_csv('./APPL.csv')
micro = sqlite3.connest('./MSFT.db')
msft = pd.read_sql('SELECT CLOSE FROM MSFT', micro)
print('Question 3',"\n"'kendall Sattistic = ', kendall(appl['Close'], msft['Close']))

#Bonus 1
print('(Bonus 1) Enter numbers followed by space key to input array.')
x = input('Enter Numbers:' )
b1 = list(map(int, x.split()))
print(arrayPart(b1))
#Bonus 2
print('(Bonus 1) Enter numbers followed by space key to input array.')
y = input('Enter Numbers:' )
b2 = list(map(int, x.split()))
print(trans(b2))

#q1
K = 105
T = 3
r = 0.05
sigma = 0.2
S0 = 100
m = 10000
value, stock = callOption(K, T, S0, r, sigma, m)
print('Expected value of option = ', value)
#plot code
a = pd.Series(stock)
b = pd.cut(a, m)
c = b.value_counts()
temp = c.sort_index()
x = [entry.left for entry in temp.index]
y = temp.values
plt.bar(x,y, color = 'r')
plt.xlabel('stocks')
plt.ylabel('value')
plt.xlim([0,300])
#plt.ylim([0,100]) #skews graph
plt.title('Question 1')
plt.show()
    #Q2----------------------------------------
P=100  #dollars
PV=90  #dollars
T=1  #years
f=4  #quarterly
c=0.05  #coupon
y = .2
print('Question 2',"\n" "Bond Yield = ", bondYield(y))
    #Q3-------------------------------------------------------------------
appl = pd.read_csv('./APPL.csv')
micro = sqlite3.connest('./MSFT.db')
msft = pd.read_sql('SELECT CLOSE FROM MSFT', micro)
print('Question 3',"\n"'kendall Sattistic = ', kendall(appl['Close'], msft['Close']))
    #Bonus 1
print('(Bonus 1) Enter numbers followed by space key to input array.')
x = input('Enter Numbers:' )
b1 = list(map(int, x.split()))
print(arrayPart(b1))
    #Bonus 2
print('(Bonus 1) Enter numbers followed by space key to input array.')
y = input('Enter Numbers:' )
b2 = list(map(int, x.split()))
print(trans(b2))
