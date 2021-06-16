\
#include $<\tilde{ }$/recorder/DatastoreRecorder.h$>$



```{.cpp}
class DatastoreRecorder:
```
 public Recorder


Recorder


A DatastoreRecorder object is used in the program to invoke
*commitState()* on an FE_Datastore object when `commit()`{.cpp} is invoked on
a Domain. The class is included in the framework so that the Domain
class does not have to be modified for FE_Datastore objects.
### Constructor


### Destructor


```{.cpp}
$\tilde{ }$DatastoreRecorder();
```

### Public Methods


```{.cpp}
int record(int commitTag);
```



```{.cpp}
int playback(int commitTag);
```




Saves a pointer to the object *theDatastore*.

Does nothing.

```{.cpp}
int record(int commitTag);
```


Returns the result of invoking `commitState(commitTag)`{.cpp} on
*theDatastore* object.\

```{.cpp}
int playback(int commitTag);
```


Returns the result of invoking `restoreState(commitTag)`{.cpp} on
*theDatastore* object.
Does nothing.
