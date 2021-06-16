\
#include $<\tilde{ }$/domain/pattern/EarthquakePattern.h$>$

NEEDS MODIFICATION TO ALLOW MULTIPLE EARTHQUAKE PATTERNS, SO DON"T HAVE
TO SET R IN NODES EACH APPLYLOAD.

```{.cpp}
class EarthquakePattern:
```
 public LoadPattern


TaggedObject

MovableObject

DomainComponent\
LoadPattern

The EarthquakePattern class is an abstract class. An EarthquakePattern
is an object which adds earthquake loads to models. This abstract class
keeps track of the GroundMotion objects and implements the *applyLoad()*
method. It is up to the concrete subclasses to set the appropriate
values of `R`{.cpp} at each node in the model.
### Constructor\

```{.cpp}
EarthquakePattern(int tag, int classTag);
```

### Destructor\

```{.cpp}
virtual $\tilde{ }$EarthquakePattern();
```

### Public Methods
### Protected Methods\

```{.cpp}
int addMotion(GroundMotion &theMotion)
```



The integers `tag` and `classTag`{.cpp} are passed to the LoadPattern classes
constructor.

Invokes the destructor on all GroundMotions added to the
Earthquakepattern. It then invokes the destructor on the array holding
pointers to the GroundMotion objects.
Obtains from each GroundMotion, the velocity and acceleration for the
time specified. These values are placed in two Vectors of size equal to
the number of GroundMotion objects. For each node in the Domain
*addInertiaLoadToUnbalance()* is invoked with the acceleration Vector
objects. SIMILAR OPERATION WITH VEL and ACCEL NEEDS TO BE INVOKED ON
ELEMENTS .. NEED TO MODIFY ELEMENT INTERFACE\

```{.cpp}
int addMotion(GroundMotion &theMotion)
```


Adds the GroundMotion, `theMotion`{.cpp} to the list of GroundMotion objects.\
