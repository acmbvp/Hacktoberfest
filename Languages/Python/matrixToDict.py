# importing numpy
import numpy as np

# creating a numpy array
array = np.array([['a','b','c'],
                   ['d','e','f'],
                   ['g','h','i']])

# convert nympy array to dictionary
d = dict(enumerate(array.flatten(), 0))

# print numpy array 
print(array)

print(type(array))

# print dictionary 
print(d)
print(type(d))