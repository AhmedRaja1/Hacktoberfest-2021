import numpy as np
from numpy.core.fromnumeric import ndim


## Creating a NumPy array
numarray = np.array([1, 2, 3, 4])
print(numarray)


## 0-Dimention
arr0 = np.array(23)
## 1-Dimension
arr1 = np.array([1, 2, 3, 4, 5])
## 2-Dimension
arr2 = np.array([[1, 2, 3], [1, 2, 3]])
## 3-Dimension
arr3 = np.array([[[1, 2], [ 2, 3]], [[ 2, 2], [ 2, 3]]])

print(arr0.ndim)
print(arr1.ndim)
print(arr2.ndim)
print(arr3.ndim)

## For Higher Dimensions
higher = np.array([1,2,3,4,5], ndmin=5)
print(higher)
print(higher.ndim)