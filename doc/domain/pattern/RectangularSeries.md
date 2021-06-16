\
#include $<\tilde{ }$domain/pattern/RectangularSeries.h$>$



```{.cpp}
class RectangularSeries:
```
 public DomainComponent


MovableObject

TimeSeries

The RectangularSeries class is a concrete subclass of TimeSeries. The
relationship between the pseudo time and the load factor is defined by
the simple relationship: factor $=$ cFactor when tStart $<=$ pseudo time
$<=$ tFinish, otherwise factor $=0.0$.
### Constructor\
*RectangularSeries(double tStart, double tFinish, double factor =
1.0);*\
### Destructor\

```{.cpp}
virtual $\tilde{ }$RectangularSeries();
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



The tag TSERIES_TAG_RectangularSeries is passed to the TimeSeries
constructor. Saves the values *tStart*, `tFinish`{.cpp} and *cfactor*.

Does nothing.

```{.cpp}
virtual double getFactor(double pseudoTime);
```


Returns cFactor if tStart $<=$ pseudo time $<=$ tFinish, otherwise
returns $0.0$.
Creates a vector of size 3 into which it places *tStart*, `tFinish`{.cpp} and
*cFactor*, and it then invokes `sendVector()`{.cpp} on the Channel object.
Does the mirror image of *sendSelf()*.\

```{.cpp}
virtual void Print(OPS_Stream &s, int flag =0) =0;
```


Prints the string 'RectangularSeries' and the values *tStart*, *tFinish*
and *factor*.
