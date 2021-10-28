import pandas as pd

# Creating a DataFrame
Data = pd.DataFrame({ 'yes' : [1, 2, 3, 3], 'No' : [0, 0, 0, 0]})
print(Data.head())

Data_2 = pd.DataFrame({'Jake' : ["fifty", "hundred"], 'Brittny' : ["five", "ten"]}, index=["First", "Second"])
print(Data_2.head())

# Reading a DataFrame

read = pd.read_csv('train.csv')
print(read.head())
