import numpy as np

## Changing array from 1D to 2D
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
arr = arr.reshape(4, 3)
print(arr)
print(arr.shape)

## From 1D to 3D

arr2 = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
arr2 = arr2.reshape(2, 3, 2)
print(arr2)
print(arr2.ndim)

## Unknown Dimension

arr3 = np.array([1, 2, 3, 4, 5, 6, 7, 8])
arr3 = arr3.reshape(2, 2, -1)
print(arr3)
print(arr3.ndim)

## Reshaping array from multidimension is by -1
arr3 = arr3.reshape(-1)
print(arr3)
print(arr3.ndim)