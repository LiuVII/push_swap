import random
import sys

if len(sys.argv) > 1:
	x = int((sys.argv)[1])
else:
	x = input('specify n in range from 1 to n: ')
#print x
numlist = range (1, x)
random.shuffle(numlist)
strlist = [str(i) for i in numlist]
print " ".join(strlist)
