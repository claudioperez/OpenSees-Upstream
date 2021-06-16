\
#include $<\tilde{ }$domain/pattern/LoadPattern.h$>$



```{.cpp}
class LoadPattern:
```
 public DomainComponent


TaggedObject

MovableObject

DomainComponent

The LoadPattern class is a concrete base class. A LoadPattern is a
container class for Load and SP_Constraint objects. Each LoadPattern
object is associated with a TimeSeries object which, for a given pseudo
time, will return the appropriate load factor to be applied to th load
in the LoadPattern.
### Constructors

```{.cpp}
LoadPattern(int tag, int classTag);
```

### Destructor\

```{.cpp}
virtual $\tilde{ }$LoadPattern();
```

### Public Methods\

```{.cpp}
virtual void setTimeSeries(TimeSeries \*theSeries);
```



```{.cpp}
virtual void setDomain(Domain \*theDomain);
```


```{.cpp}
### Public Methods to add loads
```



```{.cpp}
virtual bool addNodalLoad(NodalLoad \*);
```



```{.cpp}
virtual bool addElementalLoad(ElementalLoad \*);
```




```{.cpp}
virtual NodalLoadIter &getNodalLoads(void);
```



```{.cpp}
virtual ElementalLoadIter &getElementalLoads(void);
```



```{.cpp}
virtual SP_ConstraintIter &getSPs(void);
```


```{.cpp}
### Public Methods to remove loads
```



```{.cpp}
virtual NodalLoad \*removeNodalLoad(int tag);
```



```{.cpp}
virtual ElementalLoad \*removeElementalLoad(int tag);
```



```{.cpp}
virtual SP_Constraint \*removeSP_Constraint(int tag);
```


```{.cpp}
### Public Methods to apply loads
```



```{.cpp}
virtual void applyLoad(double pseudoTime = 0.0);
```



```{.cpp}
virtual void setLoadConstant(void);
```


```{.cpp}
### Public Methods for o/p
```



```{.cpp}
virtual int sendSelf(int commitTag, Channel &theChannel);
```




```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0);
```



The integer `tag` is passed to the DomainComponent classes constructor.
Creates three ArrayOftaggedObjects objects to store pointers to the
NodalLoad, ElementalLoad and SP_Constraints and three iters. If not
enough memory is available for these objects an error message is printed
and the program is terminated.
This is the constructor provided for subclasses to use. The integers
`tag` and `classTag`{.cpp} are passed to the DomainComponent classes
constructor.

Invokes the destructor on the TimeSeries object. Also invokes the
destructor on any objects created in the constructor for storage of the
pointers and for iters. It does not invoke the destructor on these
objects, the Domain object is responsible for doing this.

```{.cpp}
virtual void setTimeSeries(TimeSeries \*theSeries);
```


If a TimeSeries object is associated with the pattern, the destructor is
invoked on that TimeSeries object. It then sets the TimeSeries object
associated with the LoadPattern to *theSeries*.
If any loads or constraint objects exist in the LoadPattern, the
LoadPattern will invoke `setDomain()`{.cpp} on those objects. Finally invokes
the DomainComponent classes `setDomain()`{.cpp} method.\

```{.cpp}
virtual bool addNodalLoad(NodalLoad \*theLoad);
```


Adds the NodalLoad object pointed to by `theLoad`{.cpp} to the LoadPattern. If
the LoadPattern could add the pointer to its storage object for nodal
loads, it will invoke `setDomain()* and *setLoadPattern()`{.cpp} on the load
object if a Domain has been set.\

```{.cpp}
virtual bool addElementalLoad(ElementalLoad \*theLoad);
```


Adds the ElementalLoad pointed to by `theLoad`{.cpp} to the LoadPattern. If
the LoadPattern could add the pointer to its storage object for
elemental loads, it will invoke `setDomain()* and *setLoadPattern()`{.cpp} on
the load object if a Domain has been set.
Adds the SP_Constraint pointed to by `theSp`{.cpp} to the LoadPattern. If the
LoadPattern could add the pointer to its storage object for single-point
constraints, it will invoke `setDomain()* and *setLoadPattern()`{.cpp} on the
constraint object if a Domain has been set.\

```{.cpp}
virtual NodalLoadIter &getNodalLoads(void);
```


Returns an iter to the nodal loads in the LoadPattern.\

```{.cpp}
virtual ElementalLoadIter &getElementalLoads(void);
```


Returns an iter to the elemental loads in the LoadPattern.
Returns an iter to the single-point constraints in the LoadPattern.\

```{.cpp}
virtual NodalLoad \*removeNodalLoad(int tag);
```


To remove the nodal load whose identifier is given by `tag` from the
LoadPattern and sets the loads associated Domain object to $0$. Returns
a pointer to the load if successfully removed, otherwise $0$ is
returned.\

```{.cpp}
virtual ElementalLoad \*removeElementalLoad(int tag);
```


To remove the elemental load whose identifier is given by `tag` from the
LoadPattern and set the loads associated Domain object to $0$. Returns a
pointer to the load if successfully removed, otherwise $0$ is returned.
To remove the single-point constraint whose identifier is given by `tag`
from the LoadPattern and st its associated Domain object to $0$. Returns
a pointer to the load if successfully removed, otherwise $0$ is
returned.\

```{.cpp}
virtual void applyLoad(double pseudoTime = 0.0);
```


To apply the load for the pseudo time *pseudoTime*. From the associated
TimeSeries object the LoadPattern will obtain a current load factor for
the pseudo time. It will then invoke `applyLoad(load factor)`{.cpp} on the
loads and `applyConstraint(load factor)`{.cpp} on the single-point constraints
in the LoadPattern. If `setLoadConstant()`{.cpp} has been invoked, the saved
load factor is used and no call is made to the TimeSeries object. If no
TimeSeries is associated with the object a load factor of $0.0$ is
used.
Marks the LoadPattern as being constant. Subsequent calls to
*applyLoad()* will use the current load factor.
Creates a vector of size 4 into which it places the current load factor,
the mark indicating whether LoadPattern is constant, and the database
tag and class tag of the TimeSeris object. Invokes `sendVector()`{.cpp} on the
Channel object and `sendSelf()`{.cpp} on the TimeSeries object.
Does the mirror image of *sendSelf()*.\

```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0);
```


Invokes `Print(s, flag)`{.cpp} on the TimeSeries, NodalLoads, ElementalLoads
and SP_Constraints.
