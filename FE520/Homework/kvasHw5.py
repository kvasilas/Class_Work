#---------------------------------------------------------------
#Kirk Vasilas - 10410943
#Homework 5
#Due December 8th 11:59 PM
#I pledge my honor that I have abided by the stevens honor code
#--------------------------------------------------------------

import pandas as pd
import pickle
from sklearn.tree import DecisionTreeRegressor

df = pd.read_csv('./pivot_table_data.csv')
#My computer was not finding the file in the directory sp below is my test
#df = pd.read_csv(r'C:\Users\USER\AppData\Local\Programs\Python\Python37-32\PythonCode\pivot_table_data.csv')
#print(df.head(5))

#Q1--------------------------------------------
def df_filter(x):
    return((x < 0.5) & (x > -0.5))

def max_min(x):
    return (x.max() - x.min())

df_filtered = df_filter(df)
#print(df_filtered.head(2))
df_crosstab = pd.crosstab(df.row, df.column)
print(df_crosstab.head(1))
m_m = max_min(df.value)
df_pivot_tale = pd.pivot_table(df, values ='value', index = ['row'], columns = ['column'])
#, aggfunc = max_min(df)
#print(m_m)
#print(df_pivot_tale.head(1))
#Q2---------------------------------------------
def Format_data():
    df_raw = pd.read_csv('./raw_data.csv')
    #df_raw = pd.read_csv(r'C:\Users\USER\AppData\Local\Programs\Python\Python37-32\PythonCode\raw_data.csv')
    #print(df_raw.head(3))
    df_raw.columns = ['Volume', 'Price' ,'Time']
    df_raw.sort_index( inplace = True)
    df_raw['Time'] = pd.to_datetime(df_raw.Time) \
                       .dt.tz_localize('US/Eastern')  \
                       .dt.tz_convert('America/New_York')
    #df_raw.rename(columns={"Volume":"Volume","times_of_trade":"Time"})
    df_raw.set_index('Time', inplace = True)

    return(df_raw.head(3))
#Bonus 1 - Column Number
def col_num(s):
    s = s.upper()
    LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    maps = {}
    for i in range(26):
        maps[LETTERS[i]] = i+ 1
    col = 0
    for letter in s:
        col = 26*col + maps[letter]
    return col
#Bonus 2 - Combination sum
class B2_Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        candidates.sort()
        res=set()
        intermedia=[]
        self.recursion(candidates,target,res,intermedia)
        return [list(i) for i in res]

    def recursion(self,candidates,target,res,intermedia):
        for i in candidates:
            if target==i:
                temp=intermedia+[i]
                temp.sort()
                if temp is not None:
                    res.add(tuple(temp))
                return
            elif target>i:
                self.recursion(candidates,target-i,res,intermedia+[i])
            else:
                return
#Outputs
#q1 and 2
print('Question 1 ', print(df_pivot_tale.head(3)), 'Question 2', Format_data(), sep='.\n')
B1 = input('Bonus 1 - ENter column letters: ' )
print(col_num(B1))
B2 = B2_Solution()
print('Bonus 2 - Running with [2,3,6,7],7.', B2.combinationSum([2,3,6,7],7), sep='.\n')
