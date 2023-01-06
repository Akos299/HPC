#This is about Asynchronious methods

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

# Parallel processing using Pool.apply_async()
pool = mp.Pool(mp.cpu_count())
results = []

# utils function
def howmany_within_range2(i,row,minimum,maximum):
    """Returns how many numbers lie within 'maximum' and 'minimum' in a given 'row'"""
    count = 0
    for n in row:
        if minimum <= n<=maximum:
            count +=1
    return(i,count)

#callback function to collect the output in 'results'
def collect_result(result):
    global results
    results.append(result)

#parallel loop
for i,row in enumerate(data):
    pool.apply_async(howmany_within_range2,args=(i,row,4,8), callback=collect_result)

#close and wait all processes complete
pool.close()
pool.join()

#sorting
results.sort(key=lambda x: x[0])
results_final = [r for i, r in results]

print(results_final[:10])