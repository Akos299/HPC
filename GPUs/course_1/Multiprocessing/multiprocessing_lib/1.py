#In this script we are going to learn how
#we can use the multiprocessing module in python
# utlis link : https://www.machinelearningplus.com/python/parallel-processing-python/

#Libraries
import multiprocessing as mp
import numpy as np
from time import time

""" How many processors do i have on my computer ?"""
print("Number of processors: ", mp.cpu_count())


#********** PACTICE CASE 1 : ***********

#How many numbers exist between a given range in each row of a matrix ?

# Data preparation
np.random.RandomState(100)
arr = np.random.randint(0, 10, size=[200000, 5])
data = arr.tolist()
print(data[:5])

#solution Without Parallelization

def Howmany_within_range(row, minimum, maximum):
    """Returns how namy numbers lie within 'maximum' and 'minimum' in a given 'row' """
    count = 0

    for n in row:
        if minimum <= n <= maximum:
            count +=1
    return count

#solution with Pool.apply()

pool = mp.Pool(mp.cpu_count())                  #initialisation
results = [pool.apply(Howmany_within_range,\
          args=(row,4,8)) for row in data]    #application to the concerned function

pool.close()                                  #close the pool

print(results[:10])


"""

#*************** Tests**************

#Test case1 : Sequential
results = []
for row in data:
    results.append(Howmany_within_range(row,4,8))

print(results[:10])

"""