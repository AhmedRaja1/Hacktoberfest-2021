import numpy as np

# Find the indexes where the value is 4:
arr = np.array([1, 2, 3, 4, 5, 4, 4])
a = np.where(arr == 4)
print(a)

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
a = np.where(arr%2 == 0)
print(a)

## Search Sorted
# The searchsorted() method is assumed to be used on sorted arrays.

arr = np.array([6, 7, 8, 9, 11])
a = np.searchsorted(arr, 10)
print(a)

# Search From the Right Side
a = np.searchsorted(arr, 10, side='right')
print(a)

# Multiple Values

a = np.searchsorted(arr, [5, 10, 4, 11])
print(a)