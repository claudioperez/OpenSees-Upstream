\
#include $<\tilde{ }$/system_of_eqn/linearSOE/LinearSOESolver.h$>$



```{.cpp}
class LinearSOESolver:
```
 public Solver


MovableObject

Solver

LinearSOESolver is an abstract class. A LinearSOESolver object is
responsible for solving the LinearSOE object that it is associated with.
That is, to find $x$ such that the matrix equation $Ax=b$ is satisfied.






```{.cpp}
LinearSOESolver(int classTag);
```


The integer `classTag`{.cpp} is passed to the Solver.

Does nothing. Provided so the subclasses destructor will be called.

```{.cpp}
virtual int solve(void) =0;
```


Causes the LinearSOESolver to solve the system of equations $Ax=b$ for
$x$. Returns $0$ if successful , negative number if not; the actual
value depending on the type of LinearSOESolver. The result of the solve
are to be stored in the $x$ vector of the LinearSOE by the object.\

```{.cpp}
virtual int setSize(void) =0;
```


This is invoked by the `LinearSOE`{.cpp} object when `setSize()`{.cpp} has been
invoked on it. Solvers may sometimes need to store additional data that
needs to be updated if the size of the system of equation changes.\
