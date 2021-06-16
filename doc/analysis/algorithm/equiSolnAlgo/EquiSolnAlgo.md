\
#include $<\tilde{
}$/analysis/algorithm/equiSolnAlgo/EquiSolnAlgo.h$>$

```{.cpp}
class EquiSolnAlg:
```
 public SolutionAlgo;


MovableObject

SolutionAlgorithm

The EquiSolnAlgo class is an abstract base class. Its purpose is to
define the interface common among all subtypes. An EquiSolnAlgo object
defines the sequence of operations performed by the the Integrator and
the LinearSOE objects in solving the equilibrium equation $R(U) = 0$
given the current state of the domain at each time step in a direct
integration analysis or load increment in a static analysis.
### Constructor

### Destructor

### Public Methods

### Public Methods for Output

### Public Methods for Pointers - not Protected for ConvergenceTest


The integer `classTag`{.cpp} is passed to the SolutionAlgorithm classes
constructor.

Does nothing.


```{.cpp}
void setLinks(AnalysisModel &theModel,
```


IncrementalIntegrator &theIntegrator,\
LinearSOE &theSOE);


Sets up the links needed by an object of this class, or a derived class,
to an AnalysisMode, IncrementalIntegrator and LinearSOE object. Pointers
to these objects can be obtained by subtypes using the protected methods
defined below.\

```{.cpp}
virtual int solveCurrentStep(void) = 0;
```


A method implemented by each subclass which specifies the steps taken in
order to get the system into an equilibrium state. It is a pure virtual
function, i.e. all subclasses or their descendents must implement this
routine. To return $0$ if algorithm succeeds, a negative value
otherwise.\

```{.cpp}
virtual void Print(OPS_Stream &s, int flag = 0) =0;
```


The Integrator is to send information to the stream based on the integer
*flag*.\

```{.cpp}
AnalysisModel \*getAnalysisModelPtr(void) const;
```


A const member function which returns a pointer to the AnalysisModel
associated with the EquiSolnAlgo object, `theModel`{.cpp} passed in
*setLinks()*. $0$ returned if one not yet associated.\

```{.cpp}
IncrementalIntegrator \*getIncrementalIntegratorPtr(void) const;
```

A const member function which returns a pointer to the StaticMethod
associated with the StaticSolnAlgo object, `theIntegrator`{.cpp} passed in
*setLinks()*. $0$ returned if one not yet associated.\

```{.cpp}
LinSysOfEqn \*getLinearSOEptr(void) const;
```

A const member function which returns a pointer to the LinearSOE
associated with the EquiSolnAlgo object, `theLinearSOE`{.cpp} passed in
*setLinks()*. $0$ returned if one not yet associated.\
