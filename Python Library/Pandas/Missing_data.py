import pandas as pd

Data = pd.read_csv('train.csv')

# checking missing values
print(Data.Age.isnull())
print(Data.Age.notnull())

# Filling missing values

print(Data.Age.fillna(Data.Age.mean()))

#For Replacing values

print(Data.Survived.replace(1, "Alive"))
