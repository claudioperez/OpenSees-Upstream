\
#include

$$
<\tilde{ }$/domain/loadBalancer/SwapHeavierToLighterNeighbours.h$>
$$




```{.cpp}
class SwapHeavierToLighterNeighbours:
```
 public LoadBalancer


LoadBalancer


A SwapHeavierToLighterNeighbours is an object used to balance a
PartitionedDomain. It does this by shedding the boundary vertices on the
heaviest loaded partition (subdomain).
### Constructors

### Destructor

### Public Methods


Sets `numRealeases`{.cpp} to $1$ and `factorGreater`{.cpp} to $1.0$. These are the
paramemeters used in the `balance()`{.cpp} method.
Sets the parameters used in the `balance()`{.cpp} method.

Does nothing.

For `numRelease`{.cpp} times the Vertices of `theWeightedGraph`{.cpp} are iterated
through. For each Vertex, $i$, the weight of the Vertex is compared to
those of it's adjacent Vertices, $other$, (this is done by looping
through the adjacency ID of the Vertex), if the vertex weight is
*factorGreater* times greater than the other Vertices load then
*swapBoundary(i, other)* is invoked on the DomainPartitioner. Returns
$0$ if successful, otherwise a negative number and a warning message are
returned if either no link has been set to the DomainPartitioner or
*swapBoundary()* returns a negative number.\
