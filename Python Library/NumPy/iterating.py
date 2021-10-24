import numpy as np

# iterating over 1D array
arr1 = np.array([1, 2, 3])
for x in arr1:
    print(x)

print('-'*20)

# iterating over 2D array
arr2 = np.array([[1, 2, 3], [1, 2, 3], [1, 2, 3]])
for x in arr2:
    print(x)

print('-'*20)

# iterate on each scaler element
for x in arr2:
    for y in x:
        print(y)

# iterating over 3D array
arr3 = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])

for x in arr3:
    print(x)
# Iterate down to the scalars:

for x in arr3:
    for y in x:
        for z in y:
            print(z)

## Iterating Arrays Using nditer()
arr3 = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
for x in np.nditer(arr3):
    print(x)

## Iterating Array With Different Data Types
arr1 = np.array([1, 2, 3])

for x in np.nditer(arr1, flags=['buffered'], op_dtypes=['S']):
    print(x)

## Iterating With Different Step Size

arr2 = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
for x in np.nditer(arr2[:, ::2]):
    print(x)

## Enumerated Iteration Using ndenumerate()

arr1 = np.array([[1, 2, 3, 4, 5, 6, 7, 8]])
for idx, x in np.ndenumerate(arr1):
    print(idx, " ", x)

## ndenumerate() a 2D array

arr2 = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
for idx, x in np.ndenumerate(arr2):
    print(idx, x)