import numpy as np

arr = np.array([2, 4, 5, 1, 6, 3])
print(np.sort(arr))
# Note: This method returns a copy of the array, leaving the original array unchanged.

## You can also sort arrays of strings, or any other data type:

arr1 = np.array(['Sudais', 'Apple', 'Banana'])
print(np.sort(arr1))

#Sort a boolean array:
arr3 = np.array([True, False, True])
print(np.sort(arr3))

## Sorting a 2-D Array

arr21 = np.array([[5, 0, 1], [3, 5, 1]])
print(np.sort(arr21))
