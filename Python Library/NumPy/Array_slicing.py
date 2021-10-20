import numpy as np

### 1-Dimension
arr = np.array([1, 2, 3, 4, 5, 6, 7])

print(arr[1:5])
#Note: The result includes the start index, but excludes the end index.
print(arr[3:])
print(arr[:5])

# Using Negative indexing
print(arr[-5:-1])

# Slicing Using Steps
#Return every other element from index 1 to index 5
print(arr[1:5:2])
print(arr[0::3])


### 2-Dimension

arr2 = np.array([[1, 2, 3, 4, 5, 6, 7], [8, 9, 10, 11, 12, 13, 14]])
print(arr2[1, 1:4])
print(arr2[:, 1:4])
print(arr2[0, :])