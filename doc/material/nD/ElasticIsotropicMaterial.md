\
#include $<\tilde{ }$/material/nD/ElasticIsotropicMaterial.h$>$


class ElasticIsotropicMaterial : public NDMaterial


TaggedObject

MovableObject

Material\
NDMaterial

ElasticIsotropicMaterial is an abstract class. It provides the interface
to which all elastic isotropic material implementations must conform. It
also serves as a prototype for all elastic isotropic material
implementations, as described by the Prototype pattern in *Design
Patterns* by Gamma et al.
### Constructor


### Destructor


```{.cpp}
virtual $\tilde{ }$ElasticIsotropicMaterial ();
```

### Public Methods


```{.cpp}
virtual int setTrialStrain (const Vector &strain);
```



```{.cpp}
virtual const Vector &getStress (void);
```



```{.cpp}
virtual const Matrix &getTangent (void);
```



```{.cpp}
virtual int commitState (void);
```



```{.cpp}
virtual int revertToLastCommit (void);
```



```{.cpp}
virtual int revertToStart (void);
```



```{.cpp}
virtual NDMaterial \*getCopy (void);
```



```{.cpp}
virtual ElasticIsotropicMaterial \*getModel (const char \*type);
```




```{.cpp}
ElasticIsotropicMaterial (int tag, int classTag);
```


To construct an ElasticIsotropicMaterial whose unique integer tag among
NDMaterials in the domain is given by `tag`, and whose class tag is
given by *classTag*. These tags are passed to the NDMaterial class
constructor.

```{.cpp}
virtual $\tilde{ }$ElasticIsotropicMaterial ();
```


Does nothing.

```{.cpp}
virtual int setTrialStrain (const Vector &strain);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual const Vector &getStress (void);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual const Matrix &getTangent (void);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual int commitState (void);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual int revertToLastCommit (void);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual int revertToStart (void);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual NDMaterial \*getCopy (void);
```


Outputs an error indicating this method is a subclass responsibility.\

```{.cpp}
virtual ElasticIsotropicMaterial \*getModel (const char \*type);
```


Returns a specific implementation of an ElasticIsotropicMaterial by
switching on *type*. Outputs an error if *type* is not valid. This is
the prototype method.
