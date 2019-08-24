import sklearn
from sklearn.utils import shuffle
from sklearn.neighbors import KNeighborsClassifier
from sklearn import linear_model, preprocessing
import pandas as pd
import numpy as np
from pandas import ExcelWriter, ExcelFile
from sklearn.cluster import KMeans
import array as arr
import math

data = pd.read_excel(
    'C:/Users/dohai/Desktop/car/car.xlsx', sheet_name='Sheet1')

X1 = list(data["X1"])
X2 = list(data["X2"])
X3 = list(data["X3"])
X4 = list(data["X4"])
X5 = list(data["X5"])
X6 = list(data["X6"])

label = list(data["Label"])

length = len(label)

sum = float(X1[0])
count = 1.00
avgX1 = []

for i in range(1, length):
    if i == length - 1:
        lastele = (sum + X1[length - 1]) / (count + 1.0)
        avgX1.append(lastele)
    else:
        if label[i] == label[i-1]:
            sum += X1[i]
            count += 1.00
        else:
            try:
                avgX1.append(sum/count)
                sum = X1[i]
                count = 1
            except ZeroDivisionError:
                avgX1.append(0.0)
                sum = X1[i]
                count = 1.00

sum = float(X2[0])
count = 1.00
avgX2 = []

for i in range(1, length):
    if i == length - 1:
        lastele = (sum + X2[length - 1]) / (count + 1.0)
        avgX2.append(lastele)
    else:
        if label[i] == label[i-1]:
            sum += X2[i]
            count += 1.00
        else:
            try:
                avgX2.append(sum/count)
                sum = X2[i]
                count = 1
            except ZeroDivisionError:
                avgX2.append(0.0)
                sum = X2[i]
                count = 1.00

sum = float(X3[0])
count = 1.00
avgX3 = []

for i in range(1, length):
    if i == length - 1:
        lastele = (sum + X3[length - 1]) / (count + 1.0)
        avgX3.append(lastele)
    else:
        if label[i] == label[i-1]:
            sum += X3[i]
            count += 1.00
        else:
            try:
                avgX3.append(sum/count)
                sum = X3[i]
                count = 1
            except ZeroDivisionError:
                avgX3.append(0.0)
                sum = X3[i]
                count = 1.00

sum = float(X4[0])
count = 1.00
avgX4 = []

for i in range(1, length):
    if i == length - 1:
        lastele = (sum + X4[length - 1]) / (count + 1.0)
        avgX4.append(lastele)
    else:
        if label[i] == label[i-1]:
            sum += X4[i]
            count += 1.00
        else:
            try:
                avgX4.append(sum/count)
                sum = X4[i]
                count = 1
            except ZeroDivisionError:
                avgX4.append(0.0)
                sum = X4[i]
                count = 1.00

sum = float(X5[0])
count = 1.00
avgX5 = []

for i in range(1, length):
    if i == length - 1:
        lastele = (sum + X5[length - 1]) / (count + 1.0)
        avgX5.append(lastele)
    else:
        if label[i] == label[i-1]:
            sum += X5[i]
            count += 1.00
        else:
            try:
                avgX5.append(sum/count)
                sum = X5[i]
                count = 1
            except ZeroDivisionError:
                avgX5.append(0.0)
                sum = X5[i]
                count = 1.00

sum = float(X6[0])
count = 1.00
avgX6 = []

for i in range(1, length):
    if i == length - 1:
        lastele = (sum + X6[length - 1]) / (count + 1.0)
        avgX6.append(lastele)
    else:
        if label[i] == label[i-1]:
            sum += X6[i]
            count += 1.00
        else:
            try:
                avgX6.append(sum/count)
                sum = X6[i]
                count = 1
            except ZeroDivisionError:
                avgX6.append(0.0)
                sum = X6[i]
                count = 1.00

def std(arr, med):
    std = 0.0
    temp1 = 0.0
    temp2 = 0.0
    for i in range(6):
        temp1 = math.pow(arr[i] - med[i], 2)
        temp2 += temp1
    std = math.sqrt(temp2)    
    return std


data_med = pd.read_excel(
    'C:/Users/dohai/Desktop/car/Med.xlsx', sheet_name='Sheet1')

X1_med = list(data_med["X1"])
X2_med = list(data_med["X2"])
X3_med = list(data_med["X3"])
X4_med = list(data_med["X4"])
X5_med = list(data_med["X5"])
X6_med = list(data_med["X6"])

label_med = list(data_med["label"])

med_raw = [X1_med, X2_med, X3_med, X4_med, X5_med, X6_med]

arr_raw = [avgX1, avgX2, avgX3, avgX4, avgX5, avgX6]

med = [list(x) for x in zip(*med_raw)]
arr = [list(x) for x in zip(*arr_raw)]

# print(arr[0], med[0])

# test = std(arr[0], med[0])
# print(test)

result = []
fo = 0
perfect = 0
proper = 0

for i in range(8, 18):
    for m in range(20):
        for j in range(20):
            result.append(std(arr[i* 20 + m], med[j]))
            fo += 1
        minstd = min(result)
        for k in range(20):
            if minstd == result[k]:
                if k == m:
                    print("True:", k, "Mẫu: ", i)
                    perfect += 1
                    break
                if (k == m + 1) | (k == m - 1):
                    print("Proper:", k, "Mẫu: ", i)
                    proper += 1
                    break
        del result[:]
print(perfect, proper)