\
#include $<\tilde{ }$domain/pattern/TimeSeries.h$>$



```{.cpp}
class TimeSeries:
```
 public DomainComponent


MovableObject


The TimeSeries class is an abstract base class. A TimeSeries object is
used in a LoadPattern to determine the current load factor to be applied
to the loads and constraints for the time specified.
### Constructor\

```{.cpp}
TimeSeries(int classTag);
```

### Destructor\

```{.cpp}
virtual $\tilde{ }$TimeSeries();
```

### Pure Virtual Public Methods\

```{.cpp}
virtual double getFactor(double pseudoTime) =0;
```



```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0) =0;
```



The integer `classTag`{.cpp} is passed to the MovableObject classes
constructor.

Does nothing.

```{.cpp}
virtual double getFactor(double pseudoTime) =0;
```


To return the current load factor for the given value of `pseudoTime`{.cpp} to
be applied to the loads and single-point constraints in a LoadPattern
based on the value of *pseudoTime*.\

```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0) =0;
```


To print to the stream *s* output based on the value of *flag*.
