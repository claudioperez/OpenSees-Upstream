NEEDS FINISHING.
#include $<\tilde{ }$/domain/pattern/UniformExcitation.h$>$



```{.cpp}
class UniformExcitation:
```
 public EarthquakeLoad


TaggedObject

MovableObject

DomainComponent\
LoadPattern\
EarthquakePattern

A UniformExcitation is an object which adds the loads imposed by a
single ground excitation to the model. For a UniformExcitation this
means that the `R`{.cpp} matrix at each node will have $1$ column and all
entries but those corresponding to the degree of freedom direction will
be set to $0$, the value for the degree of freedom direction will be set
to $1$.
### Constructor\

```{.cpp}
UniformExcitation(GroundMotion &theMotion, int dof, int tag);
```

### Destructor\

```{.cpp}
$\tilde{ }$UniformExcitation();
```

### Public Methods

```{.cpp}
void Print(OPS_Stream &s, int flag);
```



```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```




```{.cpp}
UniformExcitation(GroundMotion &theMotion, int dof, int tag);
```

The integers `LOAD_TAG_UniformExcitation`{.cpp} and `classTag`{.cpp} are passed to
the Load classes constructor.

Does nothing.
Checks to see if the number of nodes in the domain has changed, if there
has been a change it invokes `setNumColR(1)`{.cpp} and then *setR(theDof, 0,
1.0)* on each Node. It then invokes the base classes *applyLoad()*
method. THIS SHOULD BE CHANGED TO USE LATEST domainChanged().\

```{.cpp}
void Print(OPS_Stream &s, int flag);
```


Does nothing. NEEDS WORK.\

```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```


Does nothing. NEEDS WORK.
Does nothing. NEEDS WORK.
