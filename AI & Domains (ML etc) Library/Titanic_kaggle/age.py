import pandas as pd
import numpy as np
from pandas.core.dtypes.missing import isnull
from scipy.sparse.construct import random
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OrdinalEncoder
from sklearn.impute import SimpleImputer
from sklearn.tree import DecisionTreeRegressor

add_train = 'train.csv'
add_test = 'test.csv'

train_data = pd.read_csv(add_train)
test_data = pd.read_csv(add_test)

features = ['Pclass', 'Sex', 'Fare', 'Age']

y = train_data.Survived
X = train_data[features]
X_test = test_data[features]

cat_col = [cat for cat in X.columns if X[cat].dtype == 'object']
num_col = [num for num in X.columns if X[num].dtype in ['int64', 'float64']]

a = 0
for i in X.Age:
    if i>=0 or i <200 :
        pass
    else:
        X.Age[a] = 33
    a += 1

a = 0
for i in X_test.Age:
    if i>=0 or i <200 :
        pass
    else:
        X_test.Age[a] = 33
    a += 1

a = 0
for i in X_test.Fare:
    if i>=0 or i <550 :
        pass
    else:
        X_test.Fare[a] = 50
    a += 1

X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, train_size=0.8)


X_train1 = X_train.copy()
X_valid1 = X_valid.copy()
X_test1 = X_test.copy()

coder = OrdinalEncoder()

X_test1[cat_col] = coder.fit_transform(X_test[cat_col])
X_train1[cat_col] = coder.fit_transform(X_train[cat_col])
X_valid1[cat_col] = coder.transform(X_valid[cat_col])

col_missing = [col for col in X_test1.columns if X_test1[col].isnull().any()]


model = RandomForestRegressor(n_estimators=100, max_depth=20, random_state=1)

model.fit(X_train1, y_train)
pred = model.predict(X_valid1)

A = np.around(pred)
Predictions = A.astype(int)

mae = mean_absolute_error(y_valid, Predictions)
print(mae)

output = pd.DataFrame({'PassengerId' : test_data.PassengerId, 'Survived' : Predictions})
output.to_csv('Submission_titanic_2.csv', index=False)
print("Your submission was successfully saved!")
 