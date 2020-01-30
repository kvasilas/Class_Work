# 
# Kirk Vasilas
# 
# EE-605 WS 
# Homework 1
# Question 3a 
# 

import random
nine_count = 0
ten_count = 0

for i in list(range(1000)):
    a = random.randint(1,6)
    b = random.randint(1,6)
    c = random.randint(1,6)
    x = a + b + c
    #print(x)
    if(x == 9):
        nine_count += 1
    elif(x == 10):
        ten_count += 1
    else:
        pass

print("Times rolled 9:", nine_count,"Times rolled 10:", ten_count, sep='\n')

