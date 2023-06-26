import sys
import matplotlib.pyplot as plt
import numpy as np

def readData(r,f):
    ans = np.array([])
    
    for i in r:
        val = f.readline()
        print(i )
        if val == "":
            raise("Not enough data")
        val = float(val)
        ans = np.append(ans, val)
    
    return ans



if len(sys.argv) < 1:
   raise ("At least one argument is needed, the amount of data")
n = int(sys.argv[1])

interval = 1000
start = 0#interval // 2

x = np.array([])

# operaciones:
totalPoints = np.array([])
totalNodes = np.array([])
insert = np.array([])
listTime = np.array([])
countRegion = np.array([])
aggregatRegion = np.array([])

f = open("data.txt", "r")

# Reads data
r = range(start, n, interval)
#totalPoints = readData()
#totalNodes =  readData()
insert = readData(r,f)
#listTime = readData()
#countRegion = readData()
#aggregatRegion = readData()

f.close()

x = np.linspace(start, n-start, n//interval, endpoint=True)

print(insert)
# hacer plot
#plt.plot(x, totalPoints, label="Total points")
plt.plot(x, insert, label="Insert")
plt.title("insert time compared to ammount of data")
plt.xlabel("Input size")
plt.ylabel("Time in nanoseconds")
#plt.legend()
plt.show()