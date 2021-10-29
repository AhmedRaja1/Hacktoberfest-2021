import pandas as pd

Data = pd.read_csv('train.csv')

print(Data.rename(columns={"Survived" : "Status"}))
print(Data.rename(index={0 : "first", 1: "Second"}))
print(Data.rename_axis("No.", axis="rows").rename_axis("Fields", axis="columns"))