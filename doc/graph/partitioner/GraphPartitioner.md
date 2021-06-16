\
#include $<\tilde{ }$/graph/partitioner/GraphPartitioner.h$>$



```{.cpp}
class GraphPartitioner:
```




```{.cpp}

```{.cpp}
GraphPartitioner
```

```


Metis
GraphPartitioner is an abstract class. The GraphPartitioner class
defines the interface that all programmers must provide when introducing
new GraphPartitioner subclasses. A GraphPartitioner is an algorithm for
partitioning (coloring) the vertices of a graph; that is assigning a
color (1 through the number of partitions) to each vertex of the graph.
### Constructor

### Destructor

### Public Methods


```{.cpp}
GraphPartitioner();
```


To construct a GraphPartitioner.

```{.cpp}
virtual $\tilde{}$GraphPartitioner();
```




```{.cpp}
virtual int partition(Graph &theGraph, int numPart) =0;
```


This is the method invoked to partition the graph into *numPart*
partitions. On completion of the routine each vertex will be assigned a
color $1$ through *numPart*, the color assigned indicating the partition
to which the vertex belongs. Returns a $0$ if successful, a negative
number if not; the value depending on the subclass.\
