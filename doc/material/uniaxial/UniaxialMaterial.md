INTERFACE MAY CHANGE IF MAKE MATERIAL MORE GENERAL.
#include $<\tilde{ }$/material/UniaxialMaterial.h$>$



```{.cpp}
class UniaxialMaterial:
```
 public Material


TaggedObject

MovableObject

Material

UniaxialMaterial is an abstract class. The UniaxialMaterial class
provides the interface that all UniaxialMaterial writers must provide
when introducing new UniaxialMaterial subclasses. A UniaxialMaterial
object is responsible for keeping track of stress, strain and the
constitution for a particular point in the domain.
### Constructor


```{.cpp}
UniaxialMaterial (int tag, int classTag);
```

### Destructor


```{.cpp}
virtual $\tilde{ }$UniaxialMaterial ();
```

### Public Methods


```{.cpp}
virtual int setTrialStrain (double strain) = 0;
```



```{.cpp}
virtual double getStress (void) = 0;
```



```{.cpp}
virtual double getTangent (void) = 0;
```



```{.cpp}
virtual int commitState (void) = 0;
```



```{.cpp}
virtual int revertToLastCommit (void) = 0;
```



```{.cpp}
virtual int revertToStart (void) = 0;
```



```{.cpp}
virtual UniaxialMaterial \*getCopy (void) = 0;
```




```{.cpp}
UniaxialMaterial (int tag, int classTag);
```


To construct a UniaxialMaterial whose unique integer among
UniaxialMaterials in the domain is given by `tag`, and whose class
identifier is given by *classTag*. These integers are passed to the
Material class constructor.

```{.cpp}
virtual $\tilde{ }$UniaxialMaterial ();
```


Does nothing.

```{.cpp}
virtual int setTrialStrain (double strain) = 0;
```


Sets the value of the trial strain, that value used by `getStress()`{.cpp} and
*getTangent()*, to be *strain*. To return $0$ if successful, a negative
number if not.\

```{.cpp}
virtual double getStress (void) = 0;
```


To return the current value of stress for the trial strain.\

```{.cpp}
virtual double getTangent (void) = 0;
```


To return the current value of the tangent for the trial strain.\

```{.cpp}
virtual int commitState (void) = 0;
```


To accept the current value of the trial strain as being on the solution
path. To return $0$ if successful, a negative number if not.\

```{.cpp}
virtual int revertToLastCommit (void) = 0;
```


To cause the material to revert to the state at the last commit. To
return $0$ if successful, a negative number if not.\

```{.cpp}
virtual int revertToStart (void) = 0;
```


Invoked to cause the material to revert to its original state in its
undeformed configuration. To return $0$ if successful, a negative number
if not.\

```{.cpp}
virtual UniaxialMaterial \*getCopy (void) = 0;
```


To return an exact copy of the material.\
