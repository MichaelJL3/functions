
import random

fp=open('testGraph.txt', 'w')
fp.write(str(random.randint(0, 10000))+"\n")

edges=random.randint(10, 50000)

for i in range(edges):
	nodeA=random.randint(0, 10000)
	
	while True:
		nodeB=random.randint(0, 10000)
		if nodeA!=nodeB:
			break
	
	strength=random.random()*100
	fp.write(str(nodeA)+" "+str(nodeB)+" "+str(strength)+"\n")

fp.close()