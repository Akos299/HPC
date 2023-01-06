#In this script we are going to learn how
#we can use the multiprocessing module in python
# utlis link : https://www.machinelearningplus.com/python/parallel-processing-python/

#Libraries
import multiprocessing as mp
import numpy as np
from time import time

""" How many processors do i have on my computer ?"""
print("Number of processors: ", mp.cpu_count())

# Data preparation
np.random.RandomState(100)
arr = np.random.randint(0, 10, size=[200000, 5])
data = arr.tolist()
print(data[:5])

#solution Without Parallelization

def Howmany_within_range(row, minimum=4, maximum=8):
    """Returns how namy numbers lie within 'maximum' and 'minimum' in a given 'row' """
    count = 0

    for n in row:
        if minimum <= n <= maximum:
            count +=1
    return count

#solution using Pool.map()
pool = mp.Pool(mp.cpu_count())    #initialisation with the number of cpu
results = pool.map(Howmany_within_range, [row for row in data])
pool.close()

print(results[:10])

#solution using Pool.starmap()
pool = mp.Pool(mp.cpu_count())
results = pool.starmap(Howmany_within_range,[(row,4,8) for row in data])
pool.close()
print(results[:10])
