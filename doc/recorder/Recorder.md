\
#include $<\tilde{ }$/recorder/Recorder.h$>$


class Recorder



```{.cpp}

```{.cpp}
Recorder
```

```



The Recorder class is an abstract class which is introduced to allow
information to be saved during the analysis. The interface defines two
pure virtual methods `record()* and *playback()*. *record()`{.cpp} is a method
which is called by the Domain object during a *commit()*. The
*playback()* method can be called by the analyst after the analysis has
been performed.
### Constructor


```{.cpp}
Recorder();
```

### Destructor


```{.cpp}
virtual $\tilde{ }$Recorder();
```

### Public Methods


```{.cpp}
virtual int record(int commitTag) =0;
```



```{.cpp}
virtual int playback(int commitTag) =0;
```




Does nothing.

Does nothing.

```{.cpp}
virtual int record(int commitTag) =0;
```


Invoked by the Domain object after `commit()`{.cpp} has been invoked on all
the domain component objects. What the Recorder records depends on the
concrete subtype.\

```{.cpp}
virtual int playback(int commitTag) =0;
```


Invoked by the analyst after the analysis has been performed. What the
Recorder does depends on the concrete subtype.
Invoked by the Domain object when `revertToStart()`{.cpp} is invoked on the
Domain object. What the Recorder does depends on the concrete subtype.
