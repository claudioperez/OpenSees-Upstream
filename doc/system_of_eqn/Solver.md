\
#include $<\tilde{ }$/system_of_eqn/Solver.h$>$



```{.cpp}
class Solver:
```
 public MovableObject


MovableObject


Solver is an abstract class. A Solver object is responsible for
performing the numerical operations on its associated SystemOfEqn
object.






```{.cpp}
Solver(int classTag);
```


The integer `classTag`{.cpp} is passed to the MovableObject classes
constructor.

Does nothing. Provided so the subclasses destructor will be called.

```{.cpp}
virtual int solve(void) =0;
```


Causes the solver to solve the system of equations. Returns $0$ if
successful , negative number if not; the actual value depending on the
type of Solver.\
