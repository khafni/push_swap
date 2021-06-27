from random import randint, seed
from random import random
import time
seed(time.time())

for i in range(500):
	print(randint(0, 10000), end=" ")
print()