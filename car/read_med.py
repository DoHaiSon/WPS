import numpy as np
import pandas as pd
dataFrame = pd.read_excel('Med.xlsx')
data = dataFrame.values

C = data[:, 0:6]
