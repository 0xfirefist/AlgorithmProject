from numpy.random import randint
data = open('dataset.txt','w')
a = ''
from random import randint as rand
for j in range(1000):
    i = rand(0,100)
    if i%9 == 0:
        a = str(1000) + ' ' + ' '.join([str(i) for i in range(2543*j%354,2543*j%354+1000)]) + '\n'
    if i%5==0 or i%7==0:
        a =  str(1000)+' '+' '.join([str(i) for i in range(1000-j)]) +' '+' '.join((str(randint(1000,size = j).tolist()))[1:-1].split(', '))+'\n'
    if i%2==0:
        a =  str(1000)+' '+ ' '.join((str(randint(1000,size = 1000).tolist()))[1:-1].split(', '))+'\n'
    #a = str(1000) + ' ' + ' '.join([str(i) for i in range(2543*j%354,2543*j%354+1000)]) + '\n'
    data.write(a)
data.close()
