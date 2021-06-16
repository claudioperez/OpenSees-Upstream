\
#include $<\tilde{ }$/element/zeroLength/ZeroLengthSection.h$>$


class ZeroLengthSection : public Element


TaggedObject

MovableObject

DomainComponent\
Element

The ZeroLengthSection class represents an element defined by two nodes
at the same geometric location, hence it has zero length. The nodes are
connected by a SectionForceDeformation object which represents the
force-deformation relationship for the element.

ZeroLengthSection elements are constructed with a `tag` in a domain of

```{.cpp}
dimension* 2 or 3, connected by nodes *Nd1* and *Nd2*. The vector *x
```

defines the local x-axis for the element and the vector *yprime* lies in
the local x-y plane for the element. The local z-axis is the cross
product between *x* and *yprime*, and the local y-axis is the cross
product between the local z-axis and *x*.
### Constructors



```{.cpp}
ZeroLengthSection();
```

### Destructor


```{.cpp}
 ZeroLengthSection();
```

### public methods to obtain information about dof & connectivity


```{.cpp}
int getNumExternalNodes(void) const;
```



```{.cpp}
const ID &getExternalNodes(void);
```




```{.cpp}
void setDomain(Domain \*theDomain);
```


### public methods to set the state of the element


```{.cpp}
int commitState(void);
```



### public methods to obtain stiffness, mass, damping and residual
information


```{.cpp}
const Matrix &getTangentStiff(void);
```





```{.cpp}
int addLoad(const Vector &addP);
```




```{.cpp}
const Vector &getResistingForce(void);
```



### public methods for element output


```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```


*int recvSelf(int commitTag, Channel &theChannel, FEM_ObjectBroker
&theBroker);*



```{.cpp}
int setResponse(char \*\*argv, int argc, Information &eleInformation);
```



```{.cpp}
int getResponse(int responseID, Information &eleInformation);
```



Construct a ZeroLengthSection element with `tag` . The force-deformation
relationship for the element is obtained by invoking `getCopy()`{.cpp} on the
**SectionForceDeformation** pointer *theSection*. The section model acts
in the local space defined by the *x* and *yprime* vectors. The section
axial force-deformation acts along the element local x-axis and the
section y-z axes directly corresponsd to the local element y-z axes.
This is the constructor invoked by an **FEM_ObjectBroker** object. It
constructs an empty ZeroLengthSection element with two nodes. The
*recvSelf()* method is invoked on the object for it to set the internal
data.

Element destructor deletes memory for storing the section model
pointer.

```{.cpp}
int getNumExternalNodes(void) const;
```


Returns 2.\

```{.cpp}
const ID &getExternalNodes(void);
```


Return **ID** of size $2$ with the node tags defining the element.
Return the number of DOF for the element, which depends on the dimension
of the problem and the number of DOF associated with each node.\

```{.cpp}
void setDomain(Domain \*theDomain);
```


Initialize element and define data structures. Sets up the element
transformation matrix, $A$, which defines the kinematic relationship
between nodal displacements and section deformations.\

```{.cpp}
int commitState(void);
```


Commit state of element by committing state of the section. Return 0 if
successful, !0 otherwise.
Revert state of element to last commit by reverting to last committed
state of the section. Return 0 if successful, !0 otherwise.
Revert state of element to initial state by reverting to initial state
of the section. Return 0 if successful, !0 otherwise.\

```{.cpp}
const Matrix &getTangentStiff(void);
```


Return tangent stiffness matrix for element. The element tangent is
computed from the section tangent matrix, $k_b$, as $K_e = A^T k_b A$.
The section tangent is obtained by calling *getSectionTangent()*.
Returns the tangent stiffness matrix for the element as the secant
stiffness is not defined for SectionForceDeformation objects.
Return a zero damping matrix.
Return a zero mass matrix.
The element has no loads, so this operation has no effect.\

```{.cpp}
int addLoad(const Vector &addP);
```


The element has no loads, so this operation has no effect and returns
0.
The element has no mass, so this operation has no effect and returns 0.\

```{.cpp}
const Vector &getResistingForce(void);
```


Return resisting force vector for element. The element resisting force
is computed from the section stress resultants, $s$, as $P_e = A^T s$.
The section stress resulant is obtained by calling
*getStressResultant()*.
Returns the result of `getResistingForce()`{.cpp} as there is no element
mass.\

```{.cpp}
int sendSelf(int commitTag, Channel &theChannel);
```


Send information about element and the section over a channel.\
*int recvSelf(int commitTag, Channel &theChannel, FEM_ObjectBroker
&theBroker);*

Receive information about element and section from a channel.
Display element.
Prints the element node tags and section model to the stream em s.\

```{.cpp}
int setResponse(char \*\*argv, int argc, Information &eleInformation);
```


Currently returns -1.\

```{.cpp}
int getResponse(int responseID, Information &eleInformation);
```


Currently returns -1.\
