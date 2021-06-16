\
#include

$$
<\tilde{ }$/system_of_eqn/linearSOE/bandSPD/BandSPDLinSolver.h$>
$$




```{.cpp}
class BandSPDLinSolver:
```
 public LinearSOESolver


MovableObject

Solver\
LinearSOESolver

BandSPDLinSolver is an abstract class. The BandSPDLinSolver class
provides access for each subclass to the BandSPDLinSOE object through
the pointer *theSOE*, which is a protected pointer.
### Constructor

### Destructor

### Public Methods


```{.cpp}
BandSPDLinSolver(int classTag);
```


The integer `classTag`{.cpp} is passed to the LinearSOESolver classes
constructor.

Does nothing. Provided so the subclasses destructor will be called.

```{.cpp}
virtual int setLinearSOE(BandSPDLinSOE &theSOE);
```


The method sets up the link between the BandSPDLinSOE object and the
BandSPDLinSolver, that it is sets the pointer the subclasses use.\
