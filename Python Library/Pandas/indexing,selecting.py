import pandas as pd

Data = pd.read_csv('train.csv')

# The Native way
#it actually offers quite simple ways

#like if want to select a column(Fare)
print(Data.Fare.head()) # or Data["Fare"]

#if i want to be more specific

print(Data.Fare[0]) # or Data["Fare"][0]

####  INDEXING IN PANDAS ####

#1- Index Based Selection
#Using iloc()

print(Data.iloc[0]) #Returns the first row

### in native python it's column first and row second, but here it's vice versa

print(Data.iloc[:, 1])
print(Data.iloc[1:3, 1])
print(Data.iloc[[0, 1, 2], 1])
print(Data.iloc[-5:])

#2- Label-Based Selection
#Using loc()
print(Data.loc[0, "Fare"])
print(Data.loc[1:3, "Survived"])
print(Data.loc[:, ["Fare", "Age", "Sex"]])

#### MANIPULATING INDEXES

print(Data.set_index("Name"))

#### CONDITIONAL SELECTION

print(Data.Survived == 1)
print(Data.loc[Data.Survived == 1])
print(Data.loc[(Data.Survived == 1) & (Data.Sex == "female")])
print(Data.loc[(Data.Survived == 1) | (Data.Sex == "female")])
print(Data.loc[Data.Embarked.isin(["S", "C"])])
print(Data.Age.notnull())

#### ASSINGING DATA

Data['critic'] = 'everyone'
print(Data['critic'])

Data['reverse_indexing'] = range(len(Data), 0, -1)
print(Data["reverse_indexing"])