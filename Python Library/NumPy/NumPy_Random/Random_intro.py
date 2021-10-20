from numpy import random
from numpy.core.fromnumeric import size

# Generate a random integer from 0 to 100:

x = random.randint(100)
print(x)

# Generate a random float from 0 to 1:

x = random.rand()
print(x)

# Generate a 1-D array containing 5 random integers from 0 to 100:

x = random.randint(100, size=(5))
print(x)

# Generate a 2-D array with 3 rows, each row containing 5 random integers from 0 to 100:

x = random.randint(100, size=(3, 5))
print(x)

# Generate a 1-D array containing 5 random floats:

x = random.rand(5)
print(x)

# Generate a 2-D array with 3 rows, each row containing 5 random numbers:

x = random.rand(3, 5)
print(x)


###    Generate Random Number From Array

x = random.choice([1, 2, 3, 4, 5, 6])
print(x)

# Generate a 2-D array that consists of the values in the array parameter (3, 5, 7, and 9):

x = random.choice([3, 5, 7, 9], size=(3, 5))
print(x)