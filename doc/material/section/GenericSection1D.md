\
#include $<\tilde{ }$/material/section/GenericSection1D.h$>$


class GenericSection1D : public SectionForceDeformation


TaggedObject

MovableObject

Material\
SectionForceDeformation

GenericSection1D provides a wrapper around a UniaxialMaterial so that
any UniaxialMaterial may be used to model section response. The design
of this class follows the Object Adapter pattern in *Design Patterns* by
Gamma et al.
### Constructor


### Destructor


```{.cpp}
$\tilde{ }$GenericSection1D ();
```

### Public Methods


```{.cpp}
int setTrialSectionDeformation (const Vector &def);
```



```{.cpp}
const Vector &getSectionDeformation (void);
```



```{.cpp}
const Vector &getStressResultant (void);
```



```{.cpp}
const Vector &getPrevStressResultant (void);
```



```{.cpp}
const Matrix &getSectionTangent (void);
```



```{.cpp}
const Matrix &getPrevSectionTangent (void);
```



```{.cpp}
const Matrix &getSectionFlexibility (void);
```



```{.cpp}
const Matrix &getPrevSectionFlexibility (void);
```



```{.cpp}
int commitState (void);
```



```{.cpp}
int revertToLastCommit (void);
```



```{.cpp}
int revertToStart (void);
```



```{.cpp}
SectionForceDeformation \*getCopy (void);
```



```{.cpp}
const ID &getType (void);
```



```{.cpp}
int getOrder (void);
```

### Public Methods for Output



```{.cpp}
void Print (OPS_Stream &s, int flag = 0);
```



Constructs a GenericSection1D whose unique integer tag among
SectionForceDeformation objects in the domain is given by `tag`. Obtains
a copy of the UniaxialMaterial *m* via a call to *getCopy()*. The
section code is set to be *code*.

Invokes the destructor of the UniaxialMaterial.

```{.cpp}
int setTrialSectionDeformation (const Vector &def);
```


Sets the trial section deformation vector, $\esec$, to be *def*, then
invokes `setTrialStrain()`{.cpp} on the UniaxialMaterial.\

```{.cpp}
const Vector &getSectionDeformation (void);
```


Returns the trial section deformation vector, $\esec$.\

```{.cpp}
const Vector &getStressResultant (void);
```


Sets the section resisting force, $\ssec$, to be the result of invoking
*getStress()* on the UniaxialMaterial, then returns $\ssec$.\

```{.cpp}
const Vector &getPrevStressResultant (void);
```


Returns the section resisting force, $\ssec$, from the previous trial
state.\

```{.cpp}
const Matrix &getSectionTangent (void);
```


Sets the section tangent stiffness matrix, $\ksec$, to be the result of
invoking `getTangent()`{.cpp} on the UniaxialMaterial, then returns $\ksec$.\

```{.cpp}
const Matrix &getPrevSectionTangent (void);
```


Returns the section tangent stiffness matrix, $\ksec$ from the previous
trial state.\

```{.cpp}
const Matrix &getSectionFlexibility (void);
```


Sets the section flexibility matrix, $\fsec$, to be the inverse of the
result of invoking `getTangent()`{.cpp} on the UniaxialMaterial, then returns
$\fsec$. This function overrides the base class implementation.\

```{.cpp}
const Matrix &getPrevSectionFlexibility (void);
```


Returns the section flexibility matrix, $\fsec$, from the previous trial
state.\
This function overrides the base class implementation.\

```{.cpp}
int commitState (void);
```


Invokes `commitState()`{.cpp} on the UniaxialMaterial and returns the result
of that invocation.\

```{.cpp}
int revertToLastCommit (void);
```


Invokes `revertToLastCommit()`{.cpp} on the UniaxialMaterial and returns the
result of that invocation.\

```{.cpp}
int revertToStart (void);
```


Invokes `revertToStart()`{.cpp} on the UniaxialMaterial and returns the result
of that invocation.\

```{.cpp}
SectionForceDeformation \*getCopy (void);
```


Returns a pointer to a new instance of GenericSection1D, using the same
tag, UniaxialMaterial reference, and code. It is up to the caller to
ensure that the destructor is invoked.\

```{.cpp}
const ID &getType (void);
```


Returns the section ID code that indicates the type of response quantity
returned by this instance of GenericSection1D.\

```{.cpp}
int getOrder (void);
```


Returns 1.\

```{.cpp}
int sendSelf (int commitTag, Channel &theChannel);
```


FILL IN.
FILL IN.\

```{.cpp}
void Print (OPS_Stream &s, int flag = 0);
```


Prints to the stream *s* the object's `tag`, then invokes `Print()`{.cpp} on
the UniaxialMaterial using the same values of *s* and *flag*.\
