import numpy as np

# Accessing 1-D
arr = np.array([1, 2, 3, 4])
print(arr[0])
print(arr[2]+arr[3])

# Accessing 2-D
arr2 = np.array([[1,2,3,4,5], [6,7,8,9,10]])
print(arr2[0,1])
print(arr2[1, 3])

#Accessing 3_D
arr3 = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])

print(arr3[0, 1, 0])
print(arr3[1, 0, 2])