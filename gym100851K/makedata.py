from cyaron import *
from random import randint
n = randint(2, 100000)
m = randint(n, n + 20)
gph = Graph.graph(n, m, directed=True)
print(n, m)
for i in gph.iterate_edges():
    print(i.start, i.end)