\
#include $<\tilde{ }$/material/ElasticMaterial.h$>$



```{.cpp}
class ElasticMaterial:
```
 public MaterialModel


TaggedObject

MovableObject

MaterialModel\
UniaxialMaterial

ElasticMaterial provides the abstraction of an elastic uniaxial
material, i.e. the stress-strain relationship is given by the linear
equation $\sigma = E * \epsilon$.
### Constructor


```{.cpp}
ElasticMaterial(int tag, double E);
```

### Destructor


```{.cpp}
$\tilde{ }$ElasticMaterial();
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




```{.cpp}
ElasticMaterial(int tag, int classTag);
```


To construct an ElasticMaterial with an integer identifier `tag`, an
elastic tangent modulus of $E$ and a current strain $\epsilon$ of $0.0$.
The integers `tag` and MAT_TAG_ElasticMaterial, defined in
$<$classTags.h$>$, are passed to the UniaxialMaterial classes
constructor.

Does nothing.

```{.cpp}
int setTrialStrain(double strain);
```


Sets the value of the trial strain, $\epsilon$ to be *strain*. Returns
$0$.\

```{.cpp}
double getStress(void);
```


Returns the product of $E * \epsilon$, where $\epsilon$ is the current
trial strain.\

```{.cpp}
double getTangent(void);
```


Returns the value of $E$ passed in the constructor.\

```{.cpp}
int commitState(void);
```


Returns $0$.\

```{.cpp}
int revertToLastCommit(void);
```


Returns $0$.\

```{.cpp}
int revertToStart(void);
```


Returns $0$.\

```{.cpp}
UniaxialMaterial \*getCopy(void);
```


returns a pointer to a new ElasticMaterial object, constructed using the
same values of `tag` and $E$. It is up to the caller to ensure that the
destructor is invoked.\

```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```


Creates a Vector of size $2$ into which it places `tag` and *E*. Invokes
*sendVector()* on `theChannel`{.cpp} using the ElasticMaterialObjects *dbTag*,
the integer `commitTag`{.cpp} and the Vector as arguments. Returns $0$ if
successful, a warning message and a negative number are returned if the
Channel object fails to send the Vector.
Creates a Vector of size $2$. Invokes `recvVector()`{.cpp} on *theChannel*
using the ElasticMaterialObjects *dbTag*, the integer `commitTag`{.cpp} and
the Vector as arguments. Using the data in the Vector to set it's `tag`
and $E$. Returns $0$ if successful, a warning message is printed, `tag`
and $E$ are set to $0.0$, and a negative number is returned if the
Channel object fails to receive the Vector.\

```{.cpp}
void Print(OPS_Stream &s, int flag =0);
```


Prints to the stream *s* the objects `tag` and $E$ values.\
