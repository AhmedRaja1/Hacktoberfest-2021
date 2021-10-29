import pandas as pd

Data = pd.read_csv('train.csv')

print(Data.describe())
print(Data.Name.describe())
print(Data.Survived.mean())
print(Data.Embarked.unique())
print(Data.Sex.value_counts())