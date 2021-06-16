\
#include $<\tilde{ }$/actor/machineBroker/MachineBroker.h$>$


class MachineBroker



```{.cpp}

```{.cpp}
MachineBroker
```

```



MachineBrokers are objects that are used to start remote processes
running on the parallel machine.
### Constructor


```{.cpp}
MachineBroker();
```

### Destructor


```{.cpp}
virtual $\tilde{ }$MachineBroker();
```

### Public Member Functions



```{.cpp}
MachineBroker();
```



Does nothing.

Invoked to start the program, *actorProgram*, on the parallel machine.
The remote actor process uses information supplied by `theChannel`{.cpp} to
allow the remote process to connect to the local process. The integer
*compDemand* provides an indication of the computational demands of the
remote process in a heterogeneous environment.
