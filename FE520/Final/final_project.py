import timeit
import matplotlib.pyplot as plt

from openpyxl import load_workbook
import xlrd

#also test pandas and csv
import pandas as pd

def csv_test():
    #filepath = "C:\Users\USER\AppData\Local\Programs\Python\Python37-32\PythonCode\FE520\Homework\files\final_sample.csv"
    #appl = pd.read_csv(filepath)
    appl = pd.read_csv(r"C:\Users\USER\AppData\Local\Programs\Python\Python37-32\PythonCode\FE520\Homework\files\final_sample.csv")
    a1 = appl.iat[0,0]
    return(a1)

def pyxl_test():
    wb = load_workbook(r'C:\Users\USER\AppData\Local\Programs\Python\Python37-32\PythonCode\FE520\Homework\files\final_sample.xlsx')
    sheet = wb.active
    a1 = sheet['A1']
    return(a1)

def xlrd_test():
    workbook = xlrd.open_workbook(r'C:\Users\USER\AppData\Local\Programs\Python\Python37-32\PythonCode\FE520\Homework\files\final_sample.xlsx')
    worksheet = workbook.sheet_by_name('Sheet1')
    curr_row = 0
    row = worksheet.row(curr_row)
    return(row)

def avg(list):
    return(sum(list) / len(list))

def graph(avg_list, max_list, min_list):
    plt.plot(['csv','pyxl','xlrd'], avg_list, 'b.--', label = 'avg')
    plt.plot(['csv','pyxl','xlrd'], max_list, 'r.--', label = 'max')
    plt.plot(['csv','pyxl','xlrd'], min_list, 'g.--', label = 'min')
    plt.xlabel('Import Method')
    plt.ylabel('Time (s)')
    plt.title("Average Time")
    plt.grid(True)
    plt.legend()
    return(plt.show())


csv_result = timeit.repeat("csv_test()", setup='from __main__ import csv_test', repeat = 10, number =10)
pyxl_result = timeit.repeat("pyxl_test()", setup='from __main__ import pyxl_test', repeat = 10, number =10)
xlrd_result = timeit.repeat("xlrd_test()", setup='from __main__ import xlrd_test', repeat = 10, number =10)

avg_list = [avg(csv_result), avg(pyxl_result), avg(xlrd_result)]
max_list = [max(csv_result), max(pyxl_result), max(xlrd_result)]
min_list = [min(csv_result), min(pyxl_result), min(xlrd_result)]

graph(avg_list, max_list, min_list )

min_avg = min(avg_list)
max_avg = max(avg_list)
abs_max = max(max_list)
abs_min = min(min_list)

print("Min Average:", min_avg, "Max Average:" max_avg, "Max:"abs_max, "Min:"abs_min, sep='.\n')
