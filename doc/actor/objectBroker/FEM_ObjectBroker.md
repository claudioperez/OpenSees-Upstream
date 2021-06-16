\
#include $<\tilde{ }$/actor/objectBroker/FEM_ObjectBroker.h$>$


class FEM_ObjectBroker



```{.cpp}

```{.cpp}
FEM_ObjectBroker
```

```



FEM_ObjectBrokers is an object used to create a new blank of a certain
type in a process. The explicit type of object created depends on the
method invoked and the integer `classTag`{.cpp} passed as an argument to the
method. Once the object has been created, `recvSelf()`{.cpp} can be invoked on
the object to instantiate the object with it's data.
### Constructor


```{.cpp}
FEM_ObjectBroker();
```

### Destructor


```{.cpp}
virtual $\tilde{ }$FEM_ObjectBroker();
```

### Public Methods to get new Domain objects


```{.cpp}
virtual Element \*getNewElement(int classTag);
```



```{.cpp}
virtual Node \*getNewNode(int classTag);
```



```{.cpp}
virtual MP_Constraint \*getNewMP(int classTag);
```



```{.cpp}
virtual SP_Constraint \*getNewSP(int classTag);
```



```{.cpp}
virtual NodalLoad \*getNewNodalLoad(int classTag);
```



```{.cpp}
virtual ElementalLoad \*getNewElementalLoad(int classTag);
```



### Public Methods to get New Matrix,Vector and ID objects - NOT USED

```{.cpp}
virtual Vector \*getPtrNewVector(int classTag, int size);
```



```{.cpp}
virtual ID \*getPtrNewID(int classTag, int size);
```

### Public Methods to get new Analysis objects - NOT NEEDED SEQUENTIAL



```{.cpp}
virtual ConstraintHandler \*getNewConstraintHandler(int classTag);
```



```{.cpp}
virtual DOF_Numberer \*getNewNumberer(int classTag);
```






```{.cpp}
virtual LinearSOESolver \*getNewLinearSolver(void);
```




```{.cpp}
virtual DomainSolver \*getNewDomainSolver(void);
```




```{.cpp}
virtual Subdomain \*getSubdomainPtr(int classTag);
```

### Public Methods for Parallel Model Generation



```{.cpp}
virtual GraphNumberer \*getPtrNewGraphNumberer(int classTag);
```




```{.cpp}
FEM_ObjectBroker();
```


Does nothing.

Does nothing.
