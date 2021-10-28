import pandas as pd

Data = pd.read_csv('train.csv')

print(Data.groupby("Age").Age.count())
print(Data.groupby("Fare").Fare.min())
print(Data.groupby("Name").apply(lambda df: df.iloc[0]))
print(Data.groupby(["Name", "Age"]).apply(lambda p: p.loc[p["Fare"].idxmax()]))
print(Data.groupby("Age").Fare.agg([len, min, max]))