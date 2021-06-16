\
#include $<\tilde{ }$/domain/load/Load.h$>$



```{.cpp}
class Load:
```
 public DomainComponent


TaggedObject

MovableObject

DomainComponent

Load is an abstract base class. A Load object is used to add load to the
domain. The Load class defines one method in its interface
*applyLoad()*, a method all subclasses must implement.
### Constructor


```{.cpp}
Load(tag, int classTag);
```

### Destructor


```{.cpp}
virtual $\tilde{ }$ Load();
```

### Public Methods


```{.cpp}
virtual void applyLoad(loadFactor) = 0;
```



```{.cpp}
virtual void setLoadPatternTag(int loadPaternTag);
```



```{.cpp}
virtual int getLoadPatternTag(void) const;
```




```{.cpp}
Load(tag, int classTag);
```


Constructs a load with a tag given by `tag` and a class tag is given by
*classTag*. These are passed to the DomainComponent constructor.

```{.cpp}
virtual $\tilde{}$ Load();
```




```{.cpp}
virtual void applyLoad(double loadFactor) = 0;
```


The load object is to add `loadFactor`{.cpp} times the load to the
corresponding residual value at its associated element(s) or node(s).\

```{.cpp}
virtual void setLoadPatternTag(int loadPaternTag);
```


To set the tag of the enclosing load pattern for the load to be
*loadPatternTag*.\

```{.cpp}
virtual int getLoadPatternTag(void) const;
```


To return the current load pattern tag associated with the load. If no
load pattern tag has been set $-1$ is returned.
