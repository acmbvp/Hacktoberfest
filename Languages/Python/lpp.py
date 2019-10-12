import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0,100,2000)

y8 = -300

y1 = (200-5*x)/4
y2 = (150-3*x)/5
y3 = (100-5*x)/4
y4 = (80-8*x)/4
y5 = x*0
corners = [(0,30),(0,25),(30.769,11.538),(40,0),(20,0)]
for c in corners:
    plt.plot(c[0],c[1],label = "("+str(c[1])+","+str(c[0])+")",marker = 'o')
    plt.text(c[0],c[1], "("+str(c[0])+","+str(c[1])+")")
plt.plot(x,y1)
plt.plot(x,y2)
plt.plot(x,y3)
plt.plot(x,y4)
plt.plot(x,y5)
plt.ylim(0,70)
plt.xlim(0,70)

y6 = np.minimum(y1,y2)
y7 = np.maximum(y3,y5)

plt.fill_between(x,y6,y7,where=y7<y6,color = "grey",alpha=0.5)

plt.show()

corners = [(0,30),(0,25),(30.769,11.538),(40,0),(20,0)]

for c in corners:
    z = 400*c[1]+300*c[0]
    print("y:",c[1],"x:",c[0],"z:",z)
