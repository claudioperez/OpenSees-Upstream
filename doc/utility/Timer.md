\
#include $<\tilde{}$/Timer/Timer.h$>$



```{.cpp}
class Timer:
```
 public MovableObject


MovableObject


A Timer object is an object which can be used to measure system
resources, i.e. cpu time and memory usage. Currently for Unix systems
only. COMPILE FLAG NEEDED.


```{.cpp}
Timer(int classTag);
```



```{.cpp}
virtual $\tilde{}$Timer();
```



```{.cpp}
void start(void);
```



```{.cpp}
void pause(void);
```



```{.cpp}
double getReal(void) const;
```



```{.cpp}
double getCPU(void) const;
```



```{.cpp}
int getNumPageFaults(void) const;
```



```{.cpp}
virtual void Print(OPS_Stream &s) const;
```



```{.cpp}
friend OPS_Stream &operator$<<$(OPS_Stream &s, const Timer &E);
```




```{.cpp}
Timer();
```


Does nothing.

Does nothing.

```{.cpp}
void start(void);
```


Sets the accounting variables to mark the start of accounting period
using the unix functions `times()`{.cpp} and *getrusage*.\

```{.cpp}
void pause(void);
```


Sets the accounting variables to mark the end of accounting period using
the unix functions `times()`{.cpp} and *getrusage*.\
 Uses the difference between the starting and ending accounting
variables to determine the elapsed real time between the last calls to
*start()* and *pause()*. Returns this value in units of seconds.\

```{.cpp}
double getCPU(void) const;
```


Uses the difference between the starting and ending accounting variables
to determine the CPU time allocated the process between the last calls
to `start()`{.cpp} and *pause()*. Returns this value in units of seconds.\

```{.cpp}
int getNumPageFaults(void) const;
```


Uses the difference between the starting and ending accounting variables
to determine the number of page faults that required reading of pages
from disk between the last calls to `start()`{.cpp} and *pause()*. Returns
this value.\

```{.cpp}
virtual void Print(OPS_Stream &s) const;
```


Uses the difference between the starting and ending accounting variables
to determine the real time, CPU time, operating system time allocate the
process, total number of page faults, number of page faults that
required reading of pages from memory, and number of page faults that
required no reading from disk between the last calls to `start()`{.cpp} and
*pause()*. Send these values to *s*.\

```{.cpp}
friend OPS_Stream &operator$<<$(OPS_Stream &s, const Timer &E);
```


Invokes `Print(s)`{.cpp} on the Timer object *E*.
