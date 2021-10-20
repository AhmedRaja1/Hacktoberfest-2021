import numpy as np

arr1 = np.array([1, 2, 3, 4, 5, 6, 7, 8])
new_arr = np.array_split(arr1, 3)
print(new_arr)

## Note: We also have the method split() available but it will not adjust the elements when elements are less in source array for 
#  splitting like in example above, array_split() worked properly but split() would fail.

## Accessing into the splitted arrays

print(new_arr[0])
print(new_arr[1])
print(new_arr[2])

## Splitting 2D Array
arr2 = np.array([[1, 2], [3, 4], [5, 6], [7, 8], [9, 10], [11, 12]])
new_arr2 = np.array_split(arr2, 3)
print(new_arr2)

#Split the 2-D array into three 2-D arrays along rows.
new_arr2 = np.array_split(arr2, 3, axis=1)
print(new_arr2)
# An alternate solution is hsplit()
new_arr2 = np.hsplit(arr2, 2)
print(new_arr2)

#Note: Similar alternates to vstack() and dstack() are available as vsplit() and dsplit().
