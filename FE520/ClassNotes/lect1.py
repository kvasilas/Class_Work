#for loop and print

for i in [1,2,3,4]:
    if i<=2:
        print("i is smaller than 2")
        print(i)
    else:
        print("i is bigger")
        print("loop is done")
print("all over")


import random

words = " hello Mr Vasilas"
words = words.replace(" ", "")
print(words)

list = [-1, 2, 2, 5, 6, 6, 7, 6]
#print(list)
NewList = []
for num in list:
    if num not in NewList:
        NewList.append(num)
print(NewList)


print(list, words, sep="\n")


print("kenny is gay")

print(1,2,3,4,5 sep="\n") #prints on new lines
#-----------------------------------------

dict = {'a':1, 'b': 2}
print(dict)

def changeDict(d,key, x):
    eval(d)[key] = x
    return(dict)

d = input('Dictionary name: ')
key = input('Enter Key: ')
x = int(input('Enter Value: '))
print(changeDict(d,key,x))

#-----------------------
a = (1, 2, 3)
print(len(a))
print(a[0])

def subset(a):
    for i in range(len(a)):
        for j in range(len(a)):
            if j!=i:
                print('(',a[i],',', a[j],')', sep='')


print (subset(a))
