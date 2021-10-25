import pandas as pd
from pandas.core.dtypes.missing import isnull
from scipy.sparse.construct import random
from sklearn.tree import DecisionTreeRegressor
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer

address = 'train.csv'

Data = pd.read_csv(address)

y = Data.Survived
features = ['Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare', 'Embarked']
X = Data[features]

num_cols = [num for num in X.columns if X[num].dtype in ['int64', 'float64']]
cat_cols = [cat for cat in X.columns if X[cat].dtype == 'object']
print(cat_cols)


X = Data[num_cols]
X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, train_size=0.8)

imputer = SimpleImputer()

imputed_X_train = pd.DataFrame(imputer.fit_transform(X_train))
imputed_X_valid = pd.DataFrame(imputer.transform(X_valid))

imputed_X_train.columns = X_train.columns
imputed_X_valid.columns = X_valid.columns
cols_with_missing = [col for col in imputed_X_train.columns if imputed_X_train[col].isnull().any()]
#print(cols_with_missing)

model = RandomForestRegressor(n_estimators=100, random_state=0)

model.fit(imputed_X_train, y_train)

preds = model.predict(imputed_X_valid)
#print(preds)
#print(y_valid)
mae = mean_absolute_error(y_valid, preds)
print(mae)

