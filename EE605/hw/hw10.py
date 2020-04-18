from random import randint
import numpy as np

def problem3():
    trials = 10000
    p_succ = .3
    p_fail = .7
    conf_int - 95
    for i in range(0,trials):
        pass

def problem4():
    nums = []
    for i in range(0,1000):
        nums.append(randint(0,9))
    avg = np.mean(nums)
    std_dev = np.std(nums)
    #print(nums,avg, std_dev)
    if(avg - std_dev < 4.5 or avg + std_dev > 4.5):
        return(True)
    else:
        return(False)

def problem5():
    pass

if __name__ == "__main__":
    p4_total = 1000
    p4_count = 0
    for i in range (0,p4_total):
        if(problem4()):
            p4_count+=1
    print('Problem 4:', p4_total, 'tries and', p4_count,'passes', sep=' ')