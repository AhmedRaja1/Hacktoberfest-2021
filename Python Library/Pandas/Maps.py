import pandas as pd

Data = pd.read_csv('train.csv')

mean_age = Data.Age.mean()
print(Data.Age.map(lambda p: p - mean_age))

### USING APPLY() METHOD

def score(row):
    row.Age =  row.Age - mean_age
    return row

print(Data.apply(score, axis="columns").Age)