import numpy as np

arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
print(arr)
print(arr.shape)

arr2 = np.array([1, 2, 3, 4, 5], ndmin=5)
print(arr2.shape)
