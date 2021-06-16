\
#include

$$
<\tilde{ }$/system_of_eqn/linearSOE/fullGEN/FullGenLinSolver.h$>
$$




```{.cpp}
class FullGenLinSolver:
```
 public LinearSOESolver


MovableObject

Solver\
LinearSOESolver

FullGenLinSolver is an abstract class. The FullGEnLinSolver class
provides access for each subclass to the FullGenLinSOE object through
the pointer *theSOE*, which is a protected pointer.
### Constructor

### Destructor

### Public Methods


```{.cpp}
FullGenLinSolver(int classTag);
```


The integer `classTag`{.cpp} is passed to the LinearSOESolver classes
constructor.

Does nothing, provided so the subclasses destructor will be called.

```{.cpp}
virtual int setLinearSOE(FullGenLinSOE &theSOE);
```


Sets the link to the FullGEnLinSOE object *theSOE*. This is the object
on which the solver will perform the numerical computations.\
