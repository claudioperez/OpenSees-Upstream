NEED TO ADD ADD_INERTIA_LOAD TO INTERFACE .. SEE EARTHQUAKE_PATTERN
CLASS.
#include $<\tilde{ }$/element/Element.h$>$



```{.cpp}
class Element:
```
 public DomainComponent


TaggedObject

MovableObject

DomainComponent

Element is an abstract class, i.e. no instances of Element will exist.
The element class provides the interface that all element writers must
provide when introducing new element classes.
### Constructor


```{.cpp}
Element(int tag, int classTag);
```

### Destructor


```{.cpp}
virtual  $\tilde{}$Element();
```

### Public Methods dealing with Nodes and dof


```{.cpp}
virtual int getNumExternalNodes(void) const =0;
```



```{.cpp}
virtual const ID &getExternalNodes(void) =0;
```



```{.cpp}
virtual int getNumDOF(void) =0;
```

### Public Methods dealing with State




```{.cpp}
virtual bool isSubdomain(void);
```

### Public Methods for obtaining Linearized Stiffness, Mass and Damping
Matrices\

```{.cpp}
virtual Matrix &getTangentStiff(void) =0;
```



```{.cpp}
virtual Matrix &getSecantStiff(void) =0;
```



```{.cpp}
virtual Matrix &getDamp(void) =0;
```



```{.cpp}
virtual Matrix &getMass(void) =0;
```

### Public Methods for obtaining Resisting Forces


```{.cpp}
virtual void zeroLoad(void) =0;
```



```{.cpp}
virtual Vector &getResistingForce(void) =0;
```



```{.cpp}
virtual Vector &getResistingForceIncInertia(void) =0;
```

### methods for obtaining information specific to an element

*virtual int setResponse(char \*\*argv, int argc, Information
&eleInformation);*


```{.cpp}
virtual int getResponse(int responseID, Information &eleInformation);
```




```{.cpp}
Element(int tag, int classTag);
```


To construct an element whose unique integer among elements in the
domain is given by `tag`, and whose class identifier is given by
*classTag*. Both of these integers are passed to the DomainComponent
constructor.

The destructor. Declared as virtual to allow subclass destructors to be
invoked.

```{.cpp}
virtual int getNumExternalNodes(void) const =0;
```


To return the number of external nodes associated with the element.\

```{.cpp}
virtual const ID &getExternalNodes(void) =0;
```


To return an ID containing the tags of the external nodes for the
element.\

```{.cpp}
virtual int getNumDOF(void) =0;
```


To return the number of dof associated with the element. This should
equal the sum of the dofs at each of the external nodes. To ensure this,
each subclass can overwrite the DomainComponent classes *setDomain()*
method.\

```{.cpp}
virtual int commitState(void) =0;
```

The element is to commit its current state. To return $0$ if successful,
a negative number if not.\

```{.cpp}
virtual int revertToLastCommit(void) =0;
```

The element is to set it's current state to the last committed state. To
return $0$ if successful, a negative number if not.\

```{.cpp}
virtual int revertToStart(void) =0;
```

The element is to set it's current state to the state it was at before
the analysis started. To return $0$ if successful, a negative number if
not.\

```{.cpp}
virtual int update(void);
```

This method is invoked after the response quantities have been updated
in the Domain, but not necessarily committed, e.g. during a non-linear
Newton-Raphson solution algorithm. To return $0$ if successful, a
negative number if not. This base class implementation returns $0$.\

```{.cpp}
virtual bool isSubdomain(void);
```

The element is to return true if the element is of type (or subtype)
Subdomain, else the element should return false. This base class
implementation returns $false$.\

```{.cpp}
virtual Matrix &getTangentStiff(void) =0;
```

To return the tangent stiffness matrix. The element is to compute its
stiffness matrix based on the original location of the nodes and the
current trial displacement at the nodes.\
$$\K_e = {\frac{\partial \f_{R_i}}{\partial \U}
\vert}_{\U_{trial}}$$


```{.cpp}
virtual Matrix &getSecantStiff(void) =0;
```

To return the elements secant stiffness matrix. The element is to
compute its stiffness matrix based on the original location of the nodes
and the current trial displacement at the nodes. THIS SECANT MAY BE
REMOVED.\

```{.cpp}
virtual Matrix &getDamp(void) =0;
```

To return the damping matrix. The element is to compute its damping
matrix based on the original location of the nodes and the current trial
response quantities at the nodes.\
$$\C_e = {\frac{\partial \f_{R_i}}{\partial \dot \U}
\vert}_{\U_{trial}}$$


```{.cpp}
virtual Matrix &getMass(void) =0;
```

To return the mass matrix. The element is to compute its mass matrix
based on the original location of the nodes and the current trial
response quantities at the nodes.\
$$\M_e  = {\frac{\partial \f_{I_i}}{\partial \ddot \U}
\vert}_{\U_{trial}}$$


```{.cpp}
virtual void zeroLoad(void) =0;
```

This is a method invoked to zero the element load contributions to the
residual, i.e. $\P_e = \zero$\

```{.cpp}
virtual Vector &getResistingForce(void) =0;
```

Returns the resisting force vector for the element. This is equal to the
applied load due to element loads minus the loads at the nodes due to
internal stresses in the element due to the current trial displacement,
i.e. $$\R_e = 
\P_{e} - \f_{R_e}(\U_{trial})$$


```{.cpp}
virtual Vector &getResistingForceIncInertia(void) =0;
```

Returns the resisting force vector for the element with inertia forces
included. This is equal to the applied load due to element loads (loads
set using *addLoad()*, minus the loads at the nodes due to internal
stresses in the element due to the current trial response quantities,
i.e. $$\R_e = 
\P_e -  \f_{I_e} (\ddot \U_{trial}) - \f_{R_e}(\dot
\U_{trial}, \U_{trial})$$

*virtual int setResponse(char \*\*argv, int argc, Information
&eleInformation);*

*setResponse()* is a method invoked to determine if the element will
respond to a request for a certain of information. The information
requested of the element is passed in the array of char pointers *argv*
of length em argc. If the element does not respond to the request a $-1$
is returned. If it does respond, an integer value greater than or equal
to $0$ is returned. This is the `responseID`{.cpp} passed in the
*getResponse()* method. In addition the Element object is responsible
for setting the Information object `eleInformation`{.cpp} with the type of the
return, i.e. *IntType, DoubleType, MatrixType, VectorType, IDType*, and
for creating a Matrix, Vector or ID object for the Information object,
if the information to be returned is of any of these types. The
information object is responsible for invoking the destructor on these
objects. The base class responds to no requests and will always return
$-1$.
getResponse is a method invoked to obtain information from an analysis.
The method is invoked with the integer argument returned and the
Information object that was prepared in a successful *setResponse()*
method invocation. To return $0$ if successful, a negative number if
not. The base class implementation will always return $-1$.
