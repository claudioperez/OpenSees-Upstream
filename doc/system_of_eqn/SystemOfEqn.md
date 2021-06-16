\
#include $<\tilde{ }$/system_of_eqn/SystemOfEqn.h$>$



```{.cpp}
class SystemOfEqn:
```
 public MovableObject


MovableObject


LinearSOE\
EigenSOE
SystemOfEqn is an abstract class. A SystemOfEqn object is responsible
for storing the system of equations it represents. A Solver object,
which is associated with the SystemOfEqn object, is responsible for
performing the numerical operations to solve for the system of
equations.






```{.cpp}
SystemOfEqn(int classTag);
```


The integer `classTag`{.cpp} is provided to the constructor for the
MovableObject.

Does nothing. Declared to allow the subclass destructor to be called.

```{.cpp}
virtual int solve(void) =0;
```


Invoked to cause the system of equation object to solve itself. To
return $0$ if successful, negative number if not.
