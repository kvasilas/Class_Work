#Kirk Vasilas - 10410943
#Homework 1
#Due September 21st 11:59 PM
#I pledge my honor that I have abided by the stevens honor code


#Functions
#question 1
def removeDuplicates(list):
    NewList = []
    for num in list:
        if num not in NewList:
            NewList.append(num)
    return(NewList)
#question 2
def subset(q2):
    for i in range(len(q2)):
        for j in range(len(q2)):
            if j!=i:
                print('(',q2[i],',', q2[j],')', sep='')
#question 3
def removeSpace(words):
    words = words.replace(" ", "")
    return(words)
#question 4
dict = {'a':1, 'b': 2}
def changeDict(d,key, x):
    eval(d)[key] = x
    return(dict)
#Bonus A
    # 2 sum problem - make a loop that adds each sequentially
    # give each input a number value 1-4.  When hit target return the numbers

#Bonus B
def revInt(num):
    orig = num  #make it input
    num = abs(num)
    rev = 0

    while(num>0):
        rem = num%10
        rev = (rev*10)+rem
        num = num//10
    if (orig < 0):
        rev *= -1
    return (rev)


#------------------main code-----------------------
#Q1
print('(Question 1) Enter numbers followed by space key to input array.', 'Example 3 4 5  = [3, 4, 5]')
x = input('Enter Numbers:' )
q1 = list(map(int, x.split()))
print('Your list: ', q1)
print('Removed Duplicates: ', removeDuplicates(q1))

#Q2
y = input('(Question 2) Enter Numbers:' )
q2 = list(map(int, y.split()))
print (subset(q2))

#Q3
words = input('(Question 3) Enter Words: ')
print('Without spaces: ', removeSpace(words))

#Q4
print("(Question 4) current Dictionary")
print('dict = ', dict)
d = input('Dictionary name: ')
key = input('Enter Key: ')
x = int(input('Enter Value: '))
print(changeDict(d,key,x))

#Bonus A
print('Bonus A, couldnt get it to fully work')
#Bonus B
num = int(input('(Bonus B) Number Reverser, Enter Number: '))
print('Reversed: ', revInt(num))
print('Goodbye')
