import numpy as np
#A - Create a 1d array M with values ranging from 5to 21and print M
M = np.arange(5,21)
print(M)
print()

# B - Reshape M as a 4x4matrix and print M.
N = M.reshape(4,4)
print(N)
print()

# C - Set the value of “inner” elements of the matrix M to 0 and print M.
N[1:3, 1:3] = 0
print(N)
print()

# D - Assign M2 to the M and print M.
SQRD = N @ N
print(SQRD)
print()

# E - Let’s call the first row of the matrix M a vector v. Calculate the magnitude of the vector v and print it.
squared =np.square(SQRD[0]) 
magn = np.sqrt(np.sum(squared))
print(magn)
print()




