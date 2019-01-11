#Kirk Vasilas - 10410943
#Homework 2
#Due October 8th 11:59 PM
#I pledge my honor that I have abided by the stevens honor code
import re
import enum


#Q1
def wordSearch(l):
    for i in range(len(l)-1):
        if(l[i] >= chr(48) and l[i] <= chr(57) and l[i+1] > chr(96)):
            print(l[i], l[i+1], sep='')
#Q2
def iterator(f, r):
    l = []
    for i in range(r):
        a = lambda x: eval(f)
        l.append(a(i))
    return(l)
#Q3
class Enum:
    def __init__(self, list):
        self.list = list
        #for i in range(len(list)):
            #list[i] = i +1
    def cast(self,x):
        if(x < 0 or x > len(self.list)):
            print('not in the dict')
        else:
            print(self.list[x-1])
#q4
class Inner:
    def __init__(self,a):
        self.a = a

class Outer(Inner):
    def switch():
        pass

#Bonus 1
def prefix(list):
    a = list[0]
    b = list[1]
    c = list[2]
    ans = []

    if (len(a) >len(b) and len(a) > len(c)):
        r = len(a)
    elif (len(b) >len(a) and len(b) > len(c)):
        r = len(b)
    else:
        r = len(c)

    if (a[0] != b[0] or a[0] != c[0]):
        print('no common prefix')
    else:
        for i in range(r):
            if (a[i] == b[i] and a[i] == c[i]):
                ans.append(a[i])
            else:
                break
    answer = ''.join(ans)
    print(answer)
#Bonus 2
#merge sorted list

# main
#q1
q1 = input('Question 1 - enter random series of lower case letters and numbers [0−9][a−z]')
wordSearch(q1)
#q2
print('Question 2')
q2f = input('Enter function in terms of x: ')
q2r = input('enter range: ')
print(iterator(q2f, q2r))
#q3
x = input('Question 3 - input words followed by spaces: ' )
q3 = list(map(str, x.split()))
a = Enum(q3)
num  = input('enter number to cast: ')
a.cast(num)

#bonus1
y = input('Bonus 1 - input 3 words followed by spaces: ' )
b1 = list(map(str, x.split()))
prefix(b1)

#b2
