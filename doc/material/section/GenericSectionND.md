\
#include $<\tilde{ }$/material/section/GenericSectionND.h$>$


class GenericSectionND : public SectionForceDeformation


TaggedObject

MovableObject

Material\
SectionForceDeformation

GenericSectionND provides a wrapper around a NDMaterial so that any
NDMaterial may be used to model section response. The design of this
class follows the Object Adapter pattern in *Design Patterns* by Gamma
et al.
### Constructor


### Destructor


```{.cpp}
$\tilde{ }$GenericSectionND ();
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



Constructs a GenericSectionND whose unique integer tag among
SectionForceDeformation objects in the domain is given by `tag`. Obtains
a copy of the NDMaterial *m* via a call to *getCopy()*. The section code
is set to be *code*.

Invokes the destructor of the NDMaterial.

```{.cpp}
int setTrialSectionDeformation (const Vector &def);
```


Sets the trial section deformation vector, $\esec$, to be *def*, then
invokes `setTrialStrain()`{.cpp} on the NDMaterial.\

```{.cpp}
const Vector &getSectionDeformation (void);
```


Returns the trial section deformation vector, $\esec$.\

```{.cpp}
const Vector &getStressResultant (void);
```


Sets the section resisting force, $\ssec$, to be the result of invoking
*getStress()* on the NDMaterial, then returns $\ssec$.\

```{.cpp}
const Vector &getPrevStressResultant (void);
```


Returns the section resisting force, $\ssec$, from the previous trial
state.\

```{.cpp}
const Matrix &getSectionTangent (void);
```


Sets the section tangent stiffness matrix, $\ksec$, to be the result of
invoking `getTangent()`{.cpp} on the NDMaterial, then returns $\ksec$.\

```{.cpp}
const Matrix &getPrevSectionTangent (void);
```


Returns the section tangent stiffness matrix, $\ksec$ from the previous
trial state.\

```{.cpp}
int commitState (void);
```


Invokes `commitState()`{.cpp} on the NDMaterial and returns the result of that
invocation.\

```{.cpp}
int revertToLastCommit (void);
```


Invokes `revertToLastCommit()`{.cpp} on the NDMaterial and returns the result
of that invocation.\

```{.cpp}
int revertToStart (void);
```


Invokes `revertToStart()`{.cpp} on the NDMaterial and returns the result of
that invocation.\

```{.cpp}
SectionForceDeformation \*getCopy (void);
```


Returns a pointer to a new instance of GenericSectionND, using the same
tag, NDMaterial reference, and code. It is up to the caller to ensure
that the destructor is invoked.\

```{.cpp}
const ID &getType (void);
```


Returns the section ID code that indicates the type of response
quantities returned by this instance of GenericSectionND.\

```{.cpp}
int getOrder (void);
```


Returns the result of invoking `getOrder()`{.cpp} on the NDMaterial.\

```{.cpp}
int sendSelf (int commitTag, Channel &theChannel);
```


FILL IN.
FILL IN.\

```{.cpp}
void Print (OPS_Stream &s, int flag = 0);
```


Prints to the stream *s* the object's `tag`, then invokes `Print()`{.cpp} on
the NDMaterial using the same values of *s* and *flag*.\
