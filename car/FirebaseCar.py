import numpy as np
import pandas as pd
from firebase import firebase
dataFrame_W7 = pd.read_excel (r'W_excel.xlsx', sheet_name=2)
data_W7 = dataFrame_W7.values

def detect_pos_7var(W, ssid):
    label = []
    W_T = W
    arr = np.asarray(ssid)

    arr_label = arr.dot(W_T)

    
    return np.argmax(arr_label)

firebase = firebase.FirebaseApplication('https://wpsfirebaseproject-1dbb2.firebaseio.com', None)
while 1:
    Data = firebase.get('Data', None)
    RSSIA = Data.get("RSSIA")
    RSSIB = Data.get("RSSIB")
    RSSIC = Data.get("RSSIC")
    RSSID = Data.get("RSSID")
    RSSIE = Data.get("RSSIE")
    RSSIF = Data.get("RSSIF")


    W_7 = data_W7[0:7, :]
    W = W_7
    ssid = [RSSIA,  RSSIB,  RSSIC,  RSSID,  RSSIE,  RSSIF]
    ssid.append(1);
    ssid = [ssid]
    pos = detect_pos_7var(W, ssid)
    firebase.put('/', 'Position', {'Line':1, 'Pos':int(pos)})