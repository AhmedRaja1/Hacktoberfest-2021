import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
from sklearn.impute import SimpleImputer

address = 'train.csv'
address2 = 'test.csv'
Data = pd.read_csv(address)
Test_data = pd.read_csv(address2)

features = ['Pclass', 'Sex', 'Fare']

y = Data.Survived
X = Data[features]
X_test = Test_data[features]


cat_col = [cat for cat in X.columns if X[cat].nunique() < 10 and X[cat].dtype == 'object']
num_col = [num for num in X.columns if X[num].dtype in ['int64', 'float64']]
cat_col2 = [cat for cat in X_test.columns if X_test[cat].nunique() < 10 and X[cat].dtype == 'object']
num_col2 = [num for num in X_test.columns if X_test[num].dtype in ['int64', 'float64']]

X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, train_size=0.8, random_state=0)

num_trans = SimpleImputer(strategy='constant')

cat_trans = Pipeline(
    steps=[
        ('imputer', SimpleImputer(strategy='most_frequent')),
        ('onehot', OneHotEncoder(handle_unknown='ignore'))
    ]
)

preprocessor = ColumnTransformer(
    transformers=[
        ('num', num_trans, num_col),
        ('cat', cat_trans, cat_col)
    ]
)
preprocessor = ColumnTransformer(
    transformers=[
        ('num2', num_trans, num_col2),
        ('cat2', cat_trans, cat_col2)
    ]
)

model = RandomForestRegressor(n_estimators=100, max_depth=20, random_state=0)

mypip = Pipeline(
    steps=[
        ('preprocessing', preprocessor),
        ('model', model)
    ]
)

mypip.fit(X_train, y_train)

preds = mypip.predict(X_test)

A = np.around(preds)
prediction = A.astype(int)


output = pd.DataFrame({'PassengerId' : Test_data.PassengerId, 'Survived' : prediction})
output.to_csv('Submission_pipeline.csv', index=False)
print("Your submission was successfully saved!")
