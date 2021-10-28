import pandas as pd

# creating a series

Data = pd.Series([1, 2, 3, 4, 5])
print(Data)

Data2 = pd.Series([30, 40, 50], index=['Sales 2019', 'Sales 2020', 'Sales 2021'], name="Product A")
print(Data2)
