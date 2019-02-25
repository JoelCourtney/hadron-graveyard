import time
start = time.time()

for i in range(10):
    a = 0
    for j in range(1000000):
        a += 1

print time.time() - start
