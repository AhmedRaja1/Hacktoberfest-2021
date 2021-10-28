import numpy as np


arr1 = np.array([1, 2, 3, 4])
arr2 = np.array([5, 6, 7, 8])
arr3 = np.concatenate((arr1, arr2))
#print(arr3)

## Join two 2-D arrays along rows (axis=1)

arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[5, 6], [7, 8]])
arr3 = np.concatenate((arr1, arr2), axis=1)
#print(arr3)

## Joining Arrays Using Stack Functions
#Stacking is same as concatenation, the only difference is that stacking is done along a new axis.

arr3 = np.stack((arr1, arr2), axis=1)
#print(arr3)

## Stacking Along Rows

arr3 = np.hstack((arr1, arr2))
#print(arr3)

## Stacking Along Columns
arr3 = np.vstack((arr1, arr2))
print(arr3)

## Stacking Along Height (depth)
arr3 = np.dstack((arr1, arr2))
print(arr3)