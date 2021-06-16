UNDER CONSTRUCTION.
#include $<\tilde{ }$/material/ElasticPPModel.h$>$



```{.cpp}
class ElasticPPMaterial:
```
 public MaterialModel


TaggedObject

MovableObject

MaterialModel\
UniaxialMaterial

ElasticPPMaterial provides the abstraction of an elastic perfectly
plastic uniaxial material, i.e. the stress-strain relationship is given
by the linear equation $\sigma = E * \epsilon$ while the material is
elastic and $| \sigma = E * \epsilon_p |$ while the material is
undergoing plastic deformation. SOME MORE THEORY.
### Constructor


```{.cpp}
ElasticPPMaterial(int tag, double E, double ep);
```

### Destructor


```{.cpp}
$\tilde{ }$ElasticPPMaterial();
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

