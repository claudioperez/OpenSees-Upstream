\
#include $<\tilde{ }$/material/section/ElasticSection3D.h$>$


class ElasticSection3D : public SectionForceDeformation


TaggedObject

MovableObject

Material\
SectionForceDeformation

ElasticSection3D provides the implementation of a section which exhibits
uncoupled elastic behavior in axial, moment, shear, and torsion
response.
### Constructor



```{.cpp}
ElasticSection3D ();
```

### Destructor


```{.cpp}
$\tilde{ }$ElasticSection3D ();
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
int sendSelf (int commitTag, Channel &theChannel);
```




```{.cpp}
void Print (OPS_Stream &s, int flag = 0);
```



To construct an ElasticSection3D with an integer identifier `tag`, an
elastic modulus of $E$, a second moment of area about the local z-axis,
$I_z$, a second moment of area about the local y-axis, $I_y$, a polar
moment of intertia of $J$, a section area of $A$, an elastic shear
modulus of $G$, and a shape factor of $\alpha$. The integers `tag` and
MAT_TAG_ElasticSection3D, defined in $<$classTags.h$>$, are passed to
the SectionForceDeformation class constructor.\

```{.cpp}
ElasticSection3D ();
```


Constructs a blank ElasticSection3D object.

Does nothing.

```{.cpp}
int setTrialSectionDeformation (const Vector &def);
```


Sets the value of the section deformation vector, $\esec$ to be *def*.
The section deformation vector, $\esec$, is defined by

$$\esec := \left[
   \begin{array}{c}
       \epsilon_a \\
       \kappa_z   \\
       \kappa_y   \\
       \gamma_y   \\
       \gamma_z   \\
       \phi
   \end{array} 
 \right]$$

where $\epsilon_a$ is the axial strain, $\kappa_z$ is the curvature
about the local z-axis, $\kappa_z$ is the curvature about the local
z-axis, $\gamma_y$ is the shear strain along the local y-axis,
$\gamma_z$ is the shear strain along the local z-axis, and $\phi$ is the
angle of twist. Returns $0$.\

```{.cpp}
const Vector &getSectionDeformation (void);
```


Returns the current value of the section deformation vector, $\esec$.\

```{.cpp}
const Vector &getStressResultant (void);
```


Returns the section stress resultants, $\ssec$, the product of the
section stiffness matrix, $\ksec$, and the section deformation vector,
$\esec$,

$$\ssec = \ksec \esec = \left[
   \begin{array}{c}
       P     \\
       M_z   \\
       M_z   \\
       V_y   \\
       V_y   \\
       T
   \end{array} 
 \right]$$

where $P$ is the axial force, $M_z$ is the bending moment about the
local z-axis, $M_y$ is the bending moment about the local y-axis, $V_y$
is the shear force along the local y-axis, $V_z$ is the shear force
along the local z-axis, and $T$ is the torque.\

```{.cpp}
const Vector &getPrevStressResultant (void);
```


Returns the value of $\ssec$ calculated at the previous state
determination.\

```{.cpp}
const Matrix &getSectionTangent (void);
```


Returns the section stiffness matrix, $\ksec$, where

$$\ksec = \left[
   \begin{array}{cccccc}
       EA &  0 &  0 & 0 & 0 & 0  \\
        0 & EI_z & 0 & 0 & 0 & 0 \\
        0 & 0 & EI_y & 0 & 0 & 0 \\
        0 & 0 & 0 & \alpha GA & 0 & 0 \\
        0 & 0 & 0 & 0 & \alpha GA & 0 \\
        0 & 0 & 0 & 0 & 0 & GJ
   \end{array} 
 \right]$$\

```{.cpp}
const Matrix &getPrevSectionTangent (void);
```


Returns the section stiffness matrix, $\ksec$.\

```{.cpp}
const Matrix &getSectionFlexibility (void);
```


Overrides the base class implementation and returns the section
flexibility matrix, $\fsec$, where

$$\fsec = \left[
   \begin{array}{cccccc}
       \frac{1}{EA} & 0 & 0 & 0 & 0 & 0 \\
       0 & \frac{1}{EI_z} & 0 & 0 & 0 & 0 \\
       0 & 0 & \frac{1}{EI_y} & 0 & 0 & 0 \\
       0 & 0 & 0 & \frac{1}{\alpha GA} & 0 & 0 \\ 
       0 & 0 & 0 & 0 & \frac{1}{\alpha GA} & 0 \\
       0 & 0 & 0 & 0 & 0 & \frac{1}{GJ}
   \end{array} 
 \right]$$\

```{.cpp}
const Matrix &getPrevSectionFlexibility (void);
```


Overrides the base class implementation and returns the section
flexibility matrix, $\fsec$.\

```{.cpp}
int commitState (void);
```


Returns $0$.\

```{.cpp}
int revertToLastCommit (void);
```


Returns $0$.\

```{.cpp}
int revertToStart (void);
```


Returns $0$.\

```{.cpp}
SectionForceDeformation \*getCopy (void);
```


Returns a pointer to a new ElasticSection3D object, constructed using
the same values of `tag`, $E$, $A$, $I_z$, $I_y$, $J$, $G$, and
$\alpha$. It is up to the caller to ensure that the destructor is
invoked.\

```{.cpp}
const ID &getType (void);
```


Returns the section ID code that indicates the ordering of section
response quantities. For this section, axial response is the first
quantity, bending about the local z-axis is the second, bending about
the local y-axis is the third, shear along the local y-axis is the
fourth, shear along the local z-axis is the fifth, and torsion is the
sixth.\
$$code := \left[
   \begin{array}{c}
       2 \\
       1 \\
       4 \\
       3 \\
       5 \\
       6
   \end{array} 
 \right]$$\

```{.cpp}
int getOrder (void);
```


Returns 6.\

```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```


Creates a Vector of size $8$ into which it places `tag`, $E$, $A$,
$I_z$, $I_y$, $J$, $G$, and $\alpha$. Invokes `sendVector()`{.cpp} on
*theChannel* using the ElasticSection3D objects *dbTag*, the integer
*commitTag* and the Vector as arguments. Returns $0$ if successful, a
warning message and a negative number are returned if the Channel object
fails to send the Vector.
Creates a Vector of size $8$. Invokes `recvVector()`{.cpp} on *theChannel*
using the ElasticSection3D objects *dbTag*, the integer `commitTag`{.cpp} and
the Vector as arguments. Using the data in the Vector to set its `tag`,
$E$, $A$, $I_z$, $I_y$, $J$, $G$, and $\alpha$. Returns $0$ if
successful, a warning message is printed and a negative number is
returned if the Channel object fails to receive the Vector.\

```{.cpp}
void Print(OPS_Stream &s, int flag =0);
```


Prints to the stream *s* the object's `tag`, $E$, $A$, $I_z$, $I_y$,
$J$, $G$, and $\alpha$ values.\
