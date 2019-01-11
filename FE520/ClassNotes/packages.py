#many packages to import
#import os or sys allows for cpu info
#visit https://docs.python.org/3.0/library/os.html

#Collections
#counter
cnt = dict()
word_list = ['red', 'blue', 'red', 'green', 'blue', 'blue']
for word in word_list:
    if word in cnt:
        cnt[word] += 1
    else:
        cnt[word] = 1
#print(cnt)
from collections import Counter
dict(Counter(word_list)) #does what the entire for loop and print does

#Ordered dict
from collections import OrderedDict
d = OrderedDict(bananna=3, apple=4, pear=1, orange=2)
print(d)

#itertools https://docs.python.org/3/library/itertools.html------------------
#product
from itertools import product
a = [1,2,3]
b = ['a','b']
print(list(product(a,b)))

#permutations
from itertools import permutations
print(list(permutations([1,2,3], r=3))) #r is the number of items per lsit
print(list(permutations(['a','b','c'], r=2)))
print(list(permutations([1,2,3], r=1)))

#combinations
from itertools import combinations
print(list(combinations([1,2,3,4], r=3))) #r is the number of items per lsit


#multiprocessing and threading

#sleep
import time
def fun(x):
    print('\nsleeping')
    time.sleep(2) #2 seconf pause
    print('\n'+str(2*x))

for x in [1,10]:
    fun(x)

#threading
import time
def myFun(x):
    print('\nsleeping')
    time.sleep(2) # Pause for 2 seconds
    print('\n'+str(2*x))
import threading
myThr1 = threading.Thread(target = myFun, args = (1,))
myThr2 = threading.Thread(target = myFun, args = (10,))
myThr1.start()
myThr2.start()
print('\nmain threading finished')
