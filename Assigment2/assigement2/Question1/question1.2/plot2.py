import numpy as np
import matplotlib.pyplot as plt
 
barWidth = 0.05
fig = plt.subplots(figsize =(10, 5))
f = open("data.txt","r")
con = f.read()
print(con)
lines = con.split()
print(lines)
lines = list(map( float, lines))
f.close()
other = []
fifo = []
rr =[]
other.append(lines[0])
fifo.append(lines[1])
rr.append(lines[2])

br1 = np.arange(len(other))
br2 = [x + barWidth for x in br1]
br3 = [x + barWidth for x in br2]
plt.bar(br1, other, color ='r', width = barWidth,
        edgecolor ='grey', label ='other')
plt.bar(br2, fifo, color ='g', width = barWidth,
        edgecolor ='grey', label ='fifo')
plt.bar(br3, rr, color ='b', width = barWidth,
        edgecolor ='grey', label ='rr')
plt.xlabel('priority to fifo and RR', fontweight ='bold', fontsize = 25)
plt.ylabel('time in seconds', fontweight ='bold', fontsize = 25)
plt.xticks([r + barWidth for r in range(len(other))],
        ['50'])
 
plt.legend()
plt.show()

    