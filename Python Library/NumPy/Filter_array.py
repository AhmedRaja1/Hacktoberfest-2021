import numpy as np

arr = np.array([21, 23, 12, 3])
x = [True, False, True, False]

new_arr = arr[x]
print(new_arr)
a = []
for e in arr:
    if e < 22:
        a.append(True)
    else:
        a.append(False)

new2_arr = arr[a]
print(new2_arr)