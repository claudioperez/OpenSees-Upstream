\
#include $<\tilde{ }$domain/pattern/LinearSeries.h$>$



```{.cpp}
class LinearSeries:
```
 public DomainComponent


MovableObject

TimeSeries

The LinearSeries class is a concrete subclass of TimeSeries. The
relationship between the pseudo time and the load factor is linear for
objects of this class.
### Constructor\

```{.cpp}
LinearSeries(double factor = 1.0);
```

### Destructor\

```{.cpp}
virtual $\tilde{ }$LinearSeries();
```

### Public Methods\

```{.cpp}
virtual double getFactor(double pseudoTime);
```



```{.cpp}
virtual int sendSelf(int commitTag, Channel &theChannel);
```




```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0);
```



The tag TSERIES_TAG_LinearSeries is passed to the TimeSeries
constructor. Sets the constant factor used in the relation to
*cFactor*.

Does nothing.

```{.cpp}
virtual double getFactor(double pseudoTime);
```


Returns the product of `cFactor`{.cpp} and *pseudoTime*.
Creates a vector of size 1 into which it places `cFactor`{.cpp} and invokes
*sendVector()* on the Channel object.
Does the mirror image of *sendSelf()*.\

```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0) =0;
```


Prints the string 'LinearSeries' and the factor*cFactor*.
