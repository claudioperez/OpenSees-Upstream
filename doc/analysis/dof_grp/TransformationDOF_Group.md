\
#include $<\tilde{ }$/analysis/dof_grp/TransformationDOF_Group.h$>$

UNDER CONSTRUCTION.

```{.cpp}
class TransformationDOF_Group:
```
 public DOF_Group;


DOF_Group


TransformationDOF_Group is a subclass of DOF_Group. This object stores
the transformation matrix $\T$ used by the TransformationFE objects when
a node has been constrained with an MP or SP_Constraint.


### Constructors



```{.cpp}
TransformationDOF_Group(int tag, Node \*theNode);
```

### Destructor


```{.cpp}
virtual  $\tilde{}$TransformationDOF_Group();
```

### Public Methods - dealing with the ID and Transformation matrix\

```{.cpp}
int doneID(void);
```



```{.cpp}
const ID &getID(void) const;
```



```{.cpp}
virtual void setID(int dof, int value);
```



```{.cpp}
Matrix \*getT(void);
```



```{.cpp}
virtual int getNumDOF(void) const;
```



```{.cpp}
virtual int getNumFreeDOF(void) const;
```



```{.cpp}
virtual int getNumConstrainedDOF(void) const;
```

### Public Methods - Tangent & Residual\

```{.cpp}
virtual const Matrix &getTangent(Integrator \*theIntegrator)
```



```{.cpp}
virtual const Vector &getUnbalance(Integrator \*theIntegrator);
```


### Public Methods - update trial response quantities\

```{.cpp}
virtual int setNodeDisp(const Vector &u);
```



```{.cpp}
virtual int setNodeVel(const Vector &$\dot u$);
```



```{.cpp}
virtual int setNodeAccel(const Vector &$\ddot u$);
```



```{.cpp}
virtual int incrNodeDisp(const Vector &u);
```



```{.cpp}
virtual int incrNodeVel(const Vector &$\dot u$);
```



```{.cpp}
virtual int incrNodeAccel(const Vector &$\ddot u$);
```

