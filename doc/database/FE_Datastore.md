\
#include $<\tilde{ }$/database/FE_Datastore.h$>$



```{.cpp}
class FE_Datastore:
```
 public ModelBuilder, public Channel


ModelBuilder

Channel


FE_Datastore is an abstract class. An FE_Datastore object is used in the
program to store/restore the geometry and state information in the
domain at particular instances. How, where and how the data is stored
depends on the implementation provided by the concrete subclasses.
### Constructor


```{.cpp}
FE_Datastore(Domain &theDomain, FEM_ObjectBroker &theBroker);
```

### Destructor


```{.cpp}
virtual  $\tilde{}$FE_Datastore();
```

### Public Methods


```{.cpp}
virtual int getDbTag(void) =0;
```



```{.cpp}
virtual int commitState(int commitTag);
```



```{.cpp}
virtual int restoreState(int commitTag);
```


```{.cpp}
virtual int validateBaseRelationsWrite(int commitTag)=0;
```



```{.cpp}
virtual int validateBaseRelationsRead(int commitTag)=0;
```

### Protected Methods


```{.cpp}
FEM_ObjectBroker \*getObjectBroker(void);
```




```{.cpp}
FE_Datastore(Domain &theDomain);
```

The Domain object `theDomain`{.cpp} is passed to the ModelBuilder constructor.
A pointer is kept to `theBroker`{.cpp} object.

Does nothing.

```{.cpp}
virtual int getDbTag(void) =0;
```


To return a unique integer identifier at each call. This identifier will
be used by the objects to store/retrieve their information to/from the
database.\

```{.cpp}
virtual int commitState(int commitTag) = 0;
```


Invoked to store the current state of the domain in the database. The
integer `commitTag`{.cpp} is used to identify the state for subsequent calls
to restore the information from the database. To return $0$ if
successful, a negative number if not.

In the implementation for the FE_Datastore class, the object first
invokes `validateBaseRelationsWrite()`{.cpp} on itself. If this method returns
$0$, the object then loops over all the components of the Domain object
invoking `sendSelf(commitTag, this)`{.cpp} on each of these objects. Returns
$0$ if successful, a negative number if not. For each domain component
that could not send itself a warning message is printed.\

```{.cpp}
virtual int restoreState(int commitTag) = 0;
```


Invoked to restore the state of the domain from a database. The state of
the domain at the end of this call is to be the same as the state of the
domain when `commitState(commitTag)`{.cpp} was invoked. To return $0$ if
successful, a negative number if not.

In the implementation for the FE_Datastore class, the object first
invokes `validateBaseRelationsRead()`{.cpp} on itself. If this method returns
$0$, the object then loops over all the components of the Domain object
invoking `recvSelf(commitTag, this)`{.cpp} on each of these objects. Returns
$0$ if successful, a negative number if not. For each domain component
that could not send itself a warning message is printed.\

```{.cpp}
virtual int validateBaseRelationsWrite(int commitTag)=0;
```


This method is invoked before the information can be sent to the
database. It is required to ensure that:

1.  Each Node, Element, SP_Constraint, MP_Constraint, NodalLoad and
    ElementalLoad which is to save information in the database has a
    database tag.

2.  That the information in the base tables is up to date so that a
    later call to `validateBaseRelationsRead(commitTag)`{.cpp} will be
    successful.

To return $0$ if the base relations are up to date, to return $1$ if
they are up to date and the component data has been sent to the
database, and a negative number if the method fails.\

```{.cpp}
virtual int validateBaseRelationsRead(int commitTag) =0;
```


This method is invoked before the information can be extracted from the
database. It is required to ensure that the Domain has the same type of
DomainComponent objects and that each of these has the same database tag
as when `validateBaseRealationsWrie(commitTag)`{.cpp} was invoked. To return
$0$ if the base relations are up to date, to return $1$ if they are up
to date and the component data has been received from the database, and
a negative number if the method fails.\

```{.cpp}
FEM_ObjectBroker \*getObjectBroker(void);
```


Returns a pointer to `theBroker`{.cpp} object passed in the constructor.
