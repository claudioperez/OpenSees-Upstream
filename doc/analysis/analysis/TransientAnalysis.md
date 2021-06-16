\
#include $<\tilde{ }$/analysis/analysis/TransientAnalysis.h$>$



```{.cpp}
class TransientAnalysis:
```
 public Analysis;


Analysis


The TransientAnalysis class is an abstract class. Its purpose is to
define the interface common among all subclasses. A TransientAnalysis
object is responsible for performing a transient analysis on the
domain.
### Constructor


### Destructor


```{.cpp}
virtual $\tilde{}$TransientAnalysis();
```

### Public Methods


```{.cpp}
virtual void setTimeStart(double tStart);
```



```{.cpp}
virtual void setTimeFinish(double tFinish);
```

### Protected Data


```{.cpp}
double tStart
```



```{.cpp}
double tFinish
```



The Domain `theDomain`{.cpp} is passed to the Analysis classes constructor.
Sets the starting time and finishing time for the transient analysis to
*tStart* and *tFinish*.

Does nothing.

```{.cpp}
virtual int analyze(void) =0;
```


Invoked to perform a dynamic analysis on the model. The type of analysis
performed, depends on the type of the objects in the analysis
aggregation. Returns a $0$ if successful, otherwise a negative number is
returned; the value of which depends on the type of the analysis.\

```{.cpp}
virtual void setTimeStart(double tStart);
```

To set the starting time of the TransientAnalysis to *tStart*. It
invokes `setCurrntTime(tStart)`{.cpp} on the associated domain object.\

```{.cpp}
virtual void setTimeFinish(double tFinish);
```

To set the finishing time of the TransientAnalysis to *tFinish*.
