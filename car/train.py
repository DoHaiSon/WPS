import sklearn
from sklearn.utils import shuffle
from sklearn.neighbors import KNeighborsClassifier
from sklearn import linear_model, preprocessing
import pandas as pd 
import numpy as np 
from pandas import ExcelWriter, ExcelFile
from sklearn.cluster import KMeans

data = pd.read_excel('C:/Users/dohai/Desktop/car/KNN_Med.xlsx', sheet_name = 'Sheet1')

print (data)
print("\n")
le = preprocessing.LabelEncoder()
X1 = le.fit_transform(list(data["X1"]))
X2 = le.fit_transform(list(data["X2"]))
X3 = le.fit_transform(list(data["X3"]))
X4 = le.fit_transform(list(data["X4"]))
X5 = le.fit_transform(list(data["X5"]))
X6 = le.fit_transform(list(data["X6"]))

label = le.fit_transform(list(data["Label"]))

predict = "Label"

X = list(zip(X1, X2, X3, X4, X5, X6))
Y = list(label)
x_train, x_test, y_train, y_test = sklearn.model_selection.train_test_split(X, Y, test_size = 2123, train_size = 20, shuffle = True)

model = KNeighborsClassifier(n_neighbors = 1)
model.fit(x_train, y_train)
acc = model.score(x_test, y_test)
print(acc)

predicted = model.predict(x_test)
name = ["P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10", "P11", "P12", "P13", "P14", "P15", "P16", "P17", "P18", "P19", "P20"]

# for i in range(len(x_train)):
#     print(i)
#     print("Training data:")
#     print(x_train[i])
#     print(y_train[i])
#     print("\n")

# for i in range(len(x_test)):
#     print(i)
#     print("Testing data:")
#     print(x_test[i])
#     print(y_test[i])
#     print("\n")

for x in range(len(predicted)):
    print(x)
    print("Predicted: ", name[predicted[x]], "; Data: ", x_test[x], "; Actual: ", name[y_test[x]])
    n = model.kneighbors([x_test[x]], 5 , True )
    print("N: ", n)
    print("\n")

i=0
for x in range(len(predicted)):
    if (abs(predicted[x]-y_test[x]) == 0):
        i = i+1
        print("Predicted: ", name[predicted[x]], "; Actual: ", name[y_test[x]])
        # print (i)
        # print("perfect")

j=0
for x in range(len(predicted)):
    if (abs(predicted[x]-y_test[x]) == 1 ):
        j = j+1
        print("Predicted: ", name[predicted[x]], "; Actual: ", name[y_test[x]])
        # print (j)
        # print("du doan lech 1 don vi")
print("Perfect: ", i, "Proper: ", j)