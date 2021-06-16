\
#include $<\tilde{ }$/recorder/MaxNodeDispRecorder.h$>$



```{.cpp}
class MaxNodeDispRecorder:
```
 public Recorder


Recorder


The MaxNodeDispRecorder class is used to store information about the
absolute maximum nodal displacement at a number of specified Nodes for a
specified degree of freedom during an analysis.
### Constructor


### Destructor


```{.cpp}
$\tilde{ }$MaxNodeDispRecorder();
```

### Public Methods


```{.cpp}
int record(int commitTag);
```



```{.cpp}
int playback(int commitTag);
```




Creates a $0$ Vector object of size equal to the size of `nodeTags`{.cpp} to
store the maximum nodal displacements and creates an ID object equal to
*nodeTags* to store the Node tags.

Does nothing.

```{.cpp}
int record(int commitTag);
```


For each node in `nodeTags`{.cpp} the value of the *dof*'th committed
displacement is obtained. If the absolute value of this is greater than
the value currently stored in the Vector of max displacements, the value
in the Vector is updated. If no Node exists in `theDomain`{.cpp} with the tag
or the Node does not have a *dof*'th degree-of-freedom associated with
it $0$ is entered in the Vector. Returns $0$.\

```{.cpp}
int playback(int commitTag);
```


Prints to *opserr* the Vector containing the maximum absolute nodal
displacements. Note, at the end of the analysis, what is printed is
independent of *commitTag*. Returns $0$.
Zeros the Vector of maximum nodal displacements.
