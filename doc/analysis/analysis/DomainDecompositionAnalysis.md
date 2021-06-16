UNDER CONSTRUCTION


#include $<\tilde{
}$/analysis/analysis/DomainDecompositionAnalysis.h$>$

```{.cpp}
class DomainDecompositionAnalysis:
```
 public Analysis, public
MovableObject;


Analysis

MovableObject


DomainDecompositionAnalysis is a subclass of Analysis, it is used when
performing an analysis using the domain decomposition method to solve
the equations. Its public member functions are all virtual to allow for
the generalization of the class. The following are the aggregates of
such an analysis type:

-   **AnalysisModel** - a container class holding the FE_Element and
    DOF_Group objects created by the ConstraintHandler object.

-   **ConstraintHandler** - a class which creates the DOF_Group and
    FE_Element objects, the type of objects created depending on how the
    specified constraints in the domain are to be handled.

-   **DOF_Numberer** - a class responsible for providing equation
    numbers to the individual degrees of freedom in each DOF_Group
    object.

-   **LinearSOE** - a numeric class responsible for the creation and
    subsequent solution of large systems of linear equations of the form
    $Ax = b$, where A is a matrix, and x and b are vectors.

-   **IncrementalIntegrator** - an algorithmic class which provides
    methods which are invoked by the FE_Element to determine their
    current tangent and residual matrices; that is this is the class
    that sets up the system of equations. It also provides the
    `update()`{.cpp} method which is invoked to set up the appropriate dof
    response values once the solution algorithm has formed and solved
    the system of equations.

-   **DomainDecompositionAlgo** - an algorithmic class specifying the
    sequence of operations to be performed in determining the response
    for the external dof and placing these in the system of equations.

-   **DomainSolver** - an algorithmic class specifying the sequence of
    operations to be performed in performing the numerical operations.



```{.cpp}

```{.cpp}
Constructors
```

```



```{.cpp}
DomainDecompositionAnalysis(Subdomain &theDomain,
```


ConstraintHandler &theHandler,\
DOF_Numberer &theNumberer,\
AnalysisModel &theModel,\
DomainDecompAlgo &theSolnAlgo,\
IncrementalIntegrator &theIntegrator,\
LinearSOE &theSOE,\
DomainDecompositionSolver &theSolver);



```{.cpp}
DomainDecompositionAnalysis(Subdomain &theDomain);
```



### Destructor


```{.cpp}
virtual  $\tilde{}$DomainDecompositionAnalysis();
```

### Public Methods


```{.cpp}
virtual int analyze(void);
```



```{.cpp}
virtual void domainChanged(void);
```



```{.cpp}
int getNumExternalEqn(void);
```



```{.cpp}
virtual int computeInternalResponse(void);
```



```{.cpp}
virtual int formTangent(void);
```



```{.cpp}
virtual int formResidual(void);
```



```{.cpp}
int formTangVectProduct(Vector &u);
```



```{.cpp}
virtual Matrix &getTangent();
```



```{.cpp}
virtual Vector &getResidual();
```



```{.cpp}
const Vector &getTangVectProduct();
```




### Protected Member Functions


```{.cpp}
Subdomain \*getSubdomainPtr(void) const;
```



```{.cpp}
ConstraintHandler \*getConstraintHandlerPtr(void) const;
```



```{.cpp}
DOF_Numberer \*getDOF_NumbererPtr(void) const;
```



```{.cpp}
AnalysisModel \*getAnalysisModelPtr(void) const;
```



```{.cpp}
DomainDecompAlgo \*getDomainDecompAlgoPtr(void) const;
```



```{.cpp}
IncrementalIntegrator \*getIncrementalIntegratorPtr(void) const;
```



```{.cpp}
LinearSOE \*getLinSOEPtr(void) const;
```



```{.cpp}
DomainSolver \*getDomainSolverPtr(void) const;
```





```{.cpp}
DomainDecompositionAnalysis(Subdomain &theDomain,
```


ConstraintHandler &theHandler,\
DOF_Numberer &theNumberer,\
AnalysisModel &theModel,\
DomainDecompAlgo &theSolnAlgo,\
IncrementalIntegrator &theIntegrator,\
LinearSOE &theSOE,\
DomainDecompositionSolver &theSolver);


The constructor sets all the links required by the objects in the
aggregation. To do this it invokes `setLinks(theDomain)`{.cpp} on *theModel*,
*setLinks(theSubdomain,theModel,theIntegrator)* on *theHandler*,
*setLinks(theModel)* on *theNumberer*, it invokes *setLinks(theModel,
theSOE)* on *theIntegrator*, and it invokes
*setLinks(theModel,theIntegrator, theSOE,theSolver,theSubdomain)* on
*theSolnAlgo*. Finally it invokes `setAnalysis(\*this)`{.cpp} on
*theSubdomain*.\

```{.cpp}
DomainDecompositionAnalysis(Subdomain &theDomain);
```


A constructor that is used when creating a DomainDecompositionObject
which is to receive itself afterwards. Sets the links to the Subdomain.
It is essential that this object `recvSelf()`{.cpp} before
DomainDecompositionAnalysis methods are invoked as their invocation will
cause segmentation faults. Invokes `setAnalysis(this)`{.cpp} on the
Subdomain.\

```{.cpp}
DomainDecompositionAnalysis(int classTag, Subdomain &theDomain);
```

Provided for subclasses to use. Invokes `setAnalysis(this)`{.cpp} on the
Subdomain.


```{.cpp}
virtual int analyze(void);
```


Causes an error message to be output and returns $-1$.\

```{.cpp}
virtual void domainChanged(void);
```

Method used to inform the object that the domain has changed. The
DomainDecompositionAnalysis object then performs the following:\
*theAnalysisModel-$>$clearAll(), theConstraintHandler-$>$clearAll();\
numExtEqn =
theConstraintHandler-$>$handle(theSubdomain-$>$getExternalNodes());\
theDOFnumberer-$>$number(theExternalDOFsDOFGrps);\
theLinSysOfEqn-$>$setSize(theAnalysisModel-$>$getDOFGraph);\
theIntegrator-$>$domainChanged();\
theAlgorithm-$>$domainChanged();\
* Finally `tangFormed`{.cpp} is marked as *false*.\

```{.cpp}
int getNumExternalEqn(void);
```

A method to return the number of external degrees-of-freedom on the
Subdomain interface, this information is returned when `handle()`{.cpp} is
invoked on *theConstraintHandler*.\

```{.cpp}
virtual int computeInternalResponse(void);
```

A method which invokes `solveCurrentStep()`{.cpp} on *theAlgorithm*.\

```{.cpp}
virtual int formTangent(void);
```

A method to form the condensed tangent matrix, given the current number
of internal dof. It first checks to see if the Subdomain has changed, by
invoking `hasDomainChanged()`{.cpp} on the Subdomain; if it has
*invokeChangeOnAnalysis()* is invoked on the *Subdomain*. It then checks
to see if *counter* is equal to $-1$ or not; a $-1$ indicating the
tangent has already been formed in order that the residual could be
determined. If this is not the case `formTangent()`{.cpp} is invoked on
*theIntegrator*, `condenseA()`{.cpp} is invoked on `theSolver`{.cpp} object, a flag
is set to indicate that the tangent has been formed, and the *counter*
is incremented. Returns a $0$ if successful, if either the
*formTangent()* or `condenseA()`{.cpp} method returns a negative number this
number is returned.\

```{.cpp}
virtual int formResidual(void);
```

A method to form the condensed residual vector, given the current number
of internal dof. A check to see if the Subdomain has changed is first
made, this is done by invoking `hasDomainChanged()`{.cpp} on the Subdomain; if
it has been modified `invokeChangeOnAnalysis()`{.cpp} is invoked on the
*Subdomain*. If the tangent has not yet been formed it invokes
*formTangent()* on itself and sets the *counter* to $-1$. To form the
residual `formUnbalance()`{.cpp} is invoked on `theIntegrator`{.cpp} and
*condenseRHS(numInt)* is invoked on *theSolver*. Returns $0$ or the
negative number that was returned if either `formUnbalance()`{.cpp} or
*condenseRHS()* failed.\

```{.cpp}
int formTangVectProduct(Vector &u);
```

A method to form the product of the condensed tangent matrix times the
vector $u$. A check to see if the Subdomain has changed is first made,
this is done by invoking `hasDomainChanged()`{.cpp} on the Subdomain; if it
has been modified `invokeChangeOnAnalysis()`{.cpp} is invoked on the
*Subdomain*. If the tangent has not yet been formed it invokes
*formTangent()* on itself and sets the *counter* to $-1$. Finally the
result of invoking `computeCondensedMatVect(numInt, u)`{.cpp} on *theSolver*
is returned.\

```{.cpp}
virtual Matrix &getTangent();
```

A method which returns the portion of A corresponding to internal
equation numbers. A check to see if the Subdomain has changed is first
made, this is done by invoking `hasDomainChanged()`{.cpp} on the Subdomain; if
it has been modified `invokeChangeOnAnalysis()`{.cpp} is invoked on the
*Subdomain*. If the tangent has not yet been formed `formTangent()`{.cpp} is
invoked. The method returns the result of invoking `getCondensedA()`{.cpp} on
*theSolver()*.\

```{.cpp}
virtual Vector &getResidual();
```

A method which returns the portion of the $b$ corresponding to the
external equation numbers. A check to see if the Subdomain has changed
is first made, this is done by invoking `hasDomainChanged()`{.cpp} on the
Subdomain; if it has been modified `invokeChangeOnAnalysis()`{.cpp} is invoked
on the `Subdomain`{.cpp} and `formResidual()`{.cpp} is called. The object returns
the Vector obtained from invoking `getCondensedRHS()`{.cpp} on the solver.\

```{.cpp}
const Vector &getTangVectProduct();
```

Returns the result of invoking `getCondensedMatVect()`{.cpp} on the solver. A
check to see if the Subdomain has changed is first made, this is done by
invoking `hasDomainChanged()`{.cpp} on the Subdomain; if it has been modified
*invokeChangeOnAnalysis()* is invoked on the *Subdomain*. The object
returns the Vector obtained from invoking `getCondensedMatVect()`{.cpp} on
*theSolver*.\

```{.cpp}
int sendSelf(Channel &theChannel, FEM_ObjectBroker &theBroker);
```

Creates an ID and populates the ID with the class tags of the aggregates
in the aggregation. This ID is sent and then
*sendSelf(theChannel,theBroker)* is invoked on each of the aggregates.
Returns 0.\

```{.cpp}
int recvSelf(Channel &theChannel, FEM_ObjectBroker &theBroker);
```

Creates an ID and receives data into it from *theChannel*. Based on the
class tags in the ID `theBroker`{.cpp} is then asked to return pointers to new
objects required in the aggregation. `sendSelf(theChannel,theBroker)`{.cpp} is
invoked on each of these new aggregate objects. Finally `setLinks`{.cpp} is
invoked on each of these objects with the correct arguments and
*setAnalysis(this)* is invoked on the *Subdomain*. Returns 0.

```{.cpp}
Subdomain \*getSubdomainPtr(void) const;
```


A const member function which returns a pointer to *theSubdomain*.\

```{.cpp}
ConstraintHandler \*getConstraintHandlerPtr(void) const;
```

A const member function which returns a pointer to *theSubdomain*.\

```{.cpp}
DOF_Numberer \*getDOF_NumbererPtr(void) const;
```

A const member function which returns a pointer to *theNumberer*.\

```{.cpp}
AnalysisModel \*getAnalysisModelPtr(void) const;
```

A const member function which returns a pointer to *theModel*.\

```{.cpp}
DomainDecompAlgo \*getDomainDecompAlgoPtr(void) const;
```

A const member function which returns a pointer to *theAlgorithm*.\

```{.cpp}
IncrementalIntegrator \*getIncrementalIntegratorPtr(void) const;
```

A const member function which returns a pointer to *theIntegrator*.\

```{.cpp}
LinearSOE \*getLinSOEPtr(void) const;
```

A const member function which returns a pointer to *theSOE*.\

```{.cpp}
DomainSolver \*getDomainSolverPtr(void) const;
```


A const member function which returns a pointer to *theSolver*.
associated with the DomainDecompositionAnalysis object.\
