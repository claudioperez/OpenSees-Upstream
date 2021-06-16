\
#include

$$
<\tilde{ }$/system_of_eqn/linearSOE/bandGEN/BandGenLinSolver.h$>
$$




```{.cpp}
class BandGenLinSolver:
```
 public LinearSOESolver


MovableObject

Solver\
LinearSOESolver

BandGenLinSolver is an abstract class. The BandGenLinSolver class
provides access for each subclass to the BandGenLinSOE object through
the pointer *theSOE*, which is a protected pointer.
### Constructor

### Destructor

### Public Methods


```{.cpp}
BandGenLinSolver(int classTag);
```


The integer `classTag`{.cpp} is passed to the LinearSOESolver classes
constructor.

Does nothing, provided so the subclasses destructor will be called.

```{.cpp}
virtual int setLinearSOE(BandGenLinSOE &theSOE);
```


The method sets up the link between the BandGenLinSOE object and the
BandGenLinSolver, that it is sets the pointer the subclasses use.\
