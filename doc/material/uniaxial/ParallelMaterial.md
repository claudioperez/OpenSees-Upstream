UNDER CONSTRUCTION. POSSIBLE NAME CHANGE IF MATERIAL GENERAL.
#include $<\tilde{ }$/material/ParallelModel.h$>$



```{.cpp}
class ParallelModel:
```
 public MaterialModel


TaggedObject

MovableObject

MaterialModel\
UniaxialMaterial

A ParallelModel object is an aggregation of UniaxialMaterial objects all
considered acting in parallel. SOME THEORY.
### Constructor


### Destructor


```{.cpp}
$\tilde{ }$ParallelModel();
```

### Public Methods


```{.cpp}
int setTrialStrain(double strain);
```



```{.cpp}
double getStress(void);
```



```{.cpp}
double getTangent(void);
```



```{.cpp}
int commitState(void);
```



```{.cpp}
int revertToLastCommit(void);
```



```{.cpp}
int revertToStart(void);
```



```{.cpp}
UniaxialMaterial \*getCopy(void);
```

### Public Methods for Output


```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```




```{.cpp}
void Print(OPS_Stream &s, int flag =0);
```

