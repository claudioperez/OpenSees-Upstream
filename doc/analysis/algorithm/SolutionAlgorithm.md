\
#include $<\tilde{ }$/analysis/algorithm/SolutionAlgorithm.h$>$



```{.cpp}
class SolutionAlgorithm:
```
 public MovableObject


MovableObject


The SolutionAlgorithm class is an abstract base class. Its purpose is to
define the interface common among all its subclasses. A
SolutionAlgorithm object performs the steps in the analysis by
specifying the sequence of operations to be performed by members in the
analysis aggregation.
### Constructor


```{.cpp}
SolutionAlgorithm(int classTag);
```

### Destructor


```{.cpp}
virtual  $\tilde{}$SolutionAlgorithm();
```

### Public Methods


```{.cpp}
virtual int domainChanged(void);
```



```{.cpp}
virtual int addRecorder(Recorder &theRecorder);
```



```{.cpp}
virtual int record(int track);
```



```{.cpp}
virtual int playback(int track);
```




```{.cpp}
SolutionAlgorithm(int classTag);
```


The integer `classTag`{.cpp} is passed to the MovableObject classes
constructor.

```{.cpp}
virtual  $\tilde{}$SolutionAlgorithm();
```


Invokes the destructor on any recorder object added to the
SolutionAlgorithm and releases memory used to hold pointers to the
recorder objects.

```{.cpp}
virtual int domainChanged(void);
```


Is called by the Analysis if the domain changes. It is called after
*domainChange()* has been called on the ConstraintHandler, DOF_Numberer
and the Integrator and after `setSize()`{.cpp} has been called on the
SystemOfEqn object. For base class nothing is done and $0$ is returned.
The subclasses can provide their own implementation of this method if
anything needs to be done, e.g. memory allocation, To return $0$ if
successful, a negative number if not.\

```{.cpp}
virtual int addRecorder(Recorder &theRecorder);
```


To add a recorder object `theRecorder`{.cpp} to the SolutionAlgorithm. returns
$0$ if successful, a warning message and a $-1$ is returned if not
enough memory is available.\

```{.cpp}
virtual int record(int track);
```


To invoke `record(track)`{.cpp} on any Recorder objects which have been added
to the SolutionAlgorithm.\

```{.cpp}
virtual int playback(int track);
```


To invoke `playback(track)`{.cpp} on any Recorder objects which have been
added to the SolutionAlgorithm.\
