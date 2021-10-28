import pandas as pd
from sklearn import impute
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer
address = 'train.csv'

Data = pd.read_csv(address)

y = Data.Survived
features = ['Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Ticket', 'Fare', 'Embarked']
X = Data[features]

num_cols = [num for num in X.columns if X[num].dtype in ['int64', 'float64']]
cat_cols = [cat for cat in X.columns if X[cat].dtype == 'object']
print(cat_cols)


X = Data[num_cols]
X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, train_size=0.8)
imputer = SimpleImputer()
imputed_X_train = pd.DataFrame(imputer.fit_transform(X_train))
imputed_X_valid = pd.DataFrame(imputer.transform(X_valid))



for max in [500, 100, 150, 200, 250, 300]:
    model = RandomForestRegressor(max_leaf_nodes=max, random_state=0)
    model.fit(imputed_X_train, y_train)
    pred = model.predict(imputed_X_valid)
    mae = mean_absolute_error(y_valid, pred)
    print("leaf nodes:", max, "\t\tmae:", mae)
