
'''

def F(x):
   return x*x

r=[1,2,3,4,5,6,7,8,9]
r=map(F,r)
print r
'''

'''
from functools import reduce

def MUL(x,y):
    return x*y

Result=reduce(MUL,[1,2,3,4])

print Result
'''

def Is_ODD(x):
    return x%2==0


ls=list(filter(Is_ODD,[1,2,3,4,5,6,7,8,9]))

print ls


