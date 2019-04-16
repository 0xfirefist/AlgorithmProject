import os

dataset = open('dataset.txt').read().split('\n')
q = []
iq = []
for i in dataset:
    iq = iq + [int((os.popen('echo '+i+' | ./iqsort' ).read())[:-1])]
    q = q + [int((os.popen('echo '+i+' | ./qsort' ).read())[:-1])]
print(len(iq))
from matplotlib import pyplot as plt
from matplotlib import style
import numpy as n
style.use('ggplot')
y1 = n.array(q) 
y2 = n.array(iq)
x = n.array([i for i in range(1000)])

plt.plot(x,y1,'g',label='quicksort', linewidth=1.5)
plt.plot(x,y2,'c',label='improvised',linewidth=1.5)
plt.title('Improvised Quicksort')
plt.ylabel('Y axis')
plt.xlabel('X axis')
plt.legend() # basically it print labels of the two lines (on the top left corner)
# also to add legend to upper left corner use plt.legend(loc='upper left')
# plt.grid(True,color='k')
plt.show()
