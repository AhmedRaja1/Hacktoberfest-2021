import pandas as pd
import numpy as np
from pandas._libs import missing
from pandas.core.dtypes.missing import isnull
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OrdinalEncoder
from sklearn.impute import SimpleImputer

add = 'train.csv'
add2 = 'test.csv'
Data = pd.read_csv(add)
test_data = pd.read_csv(add2)

features = ['Pclass', 'Sex', 'Fare']

y = Data.Survived
X = Data[features]
X_test = test_data[features]
col_missing = [col for col in X_test.columns if X_test[col].isnull().any()]
num_col_train = [num for num in X.columns if X[num].dtype in ['int64', 'float64']]
num_col_test = [num for num in X_test.columns if X_test[num].dtype in ['int64', 'float64']]
cat_col_train = [cat for cat in X.columns if X[cat].dtype == 'object']
cat_col_test = [cat for cat in X_test.columns if X_test[cat].dtype == 'object']


X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, train_size=0.8, random_state=1)


cat_col = ['Sex']
X_test2 = X_test.copy()
X_train2 = X_train.copy()
X_valid2 = X_valid.copy()
encoder = OrdinalEncoder()
X_test2[cat_col] = encoder.fit_transform(X_test[cat_col])
X_train2[cat_col] = encoder.fit_transform(X_train[cat_col])
X_valid2[cat_col] = encoder.transform(X_valid[cat_col])

X_test1 = X_test2.copy()
X_train1 = X_train2.copy()
X_valid1 = X_valid2.copy()
num = ['Fare']
simple = SimpleImputer()
X_train1[num] = pd.DataFrame(simple.fit_transform(X_train2[num]))
X_valid1[num] = pd.DataFrame(simple.transform(X_valid2[num]))
X_test1[num] = pd.DataFrame(simple.fit_transform(X_test2[num]))
X_test1[num].columns = X_test[num].columns
X_train1[num].columns = X_train[num].columns
X_valid1[num].columns = X_valid[num].columns
col_missing = [col for col in X_test1.columns if X_test1[col].isnull().any()]
print(col_missing)

model = RandomForestRegressor(n_estimators=100, max_depth=25 ,random_state=0)
model.fit(X_train2, y_train)
preds = model.predict(X_test1)
A = np.around(preds)
predictions = A.astype(int)
output = pd.DataFrame({'PassengerId' : test_data.PassengerId, 'Survived' : predictions})
output.to_csv('Submission.csv', index=False)
print("Your submission was successfully saved!")