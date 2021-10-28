import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6])
sarr = np.array(["Sudais", "Haidar", "Alam"])
print(arr.dtype)
print(sarr.dtype)

# We can also creat an array of specific data type
strarr = np.array([1, 2, 3, 4, 5], dtype='S')
print(strarr)
print(strarr.dtype)

# For i, u, f, S and U we can define size as well.

arr2 = np.array([1, 2, 3, 4], dtype='i4')
print(arr2)
print(arr2.dtype)

## Converting data types on existing arrays

arr3 = np.array([2.3, 3.2, 2.1, 2.2])
newarr = arr3.astype(int) #or .astype('i')
print(newarr)

arr4 = np.array([1, 0, 3, 4, 5, 6, 0])
newarr2 = arr4.astype(bool)
print(newarr2)
print(newarr2.dtype)

"""
i - integer
b - boolean
u - unsigned integer
f - float
c - complex float
m - timedelta
M - datetime
O - object
S - string
U - unicode string
V - fixed chunk of memory for other type ( void )
"""