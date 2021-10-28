import numpy as np

arr = np.array([1, 2, 3, 4, 5])

## copy()
x = arr.copy()
arr[2] = 43
print(arr)
print(x)

## view()
x = arr.view()
arr[2] = 23
print(arr)
print(x)
#making changes in view
x[0] = 100
print(arr)
print(x)

## Check if array owns it's data
x = arr.copy()
y = arr.view()

print(x.base)
print(y.base)