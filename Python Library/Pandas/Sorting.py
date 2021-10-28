import pandas as pd

Data = pd.read_csv('train.csv')

Age_Data = Data.groupby("Age").Fare.agg([len])


Age_Data = Age_Data.reset_index()
Age_Data = Age_Data.sort_values(by=['len'])
print(Age_Data)

Age_Data = Age_Data.sort_values(by='len', ascending=False)
print(Age_Data)

Age_Data = Age_Data.sort_index()
print(Age_Data)