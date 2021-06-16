\
#include $<\tilde{ }$/tagged/storage/MapOfTaggedObjects.h$>$


class MapOfTaggedObjects


TaggedObjectStorage


A MapOfTaggedObjects object is used as a container to store and provide
access to objects of type TaggedObject. A MapOfTaggedObjects creates a
map object to store the pointers to these objects. A map is created
using a template provided by the standard template library. The key used
to identify the pointers stored in the map object is the TaggedObjects
tag. Each MapOfTaggedObject object also contains a
MapOfTaggedObjectsIter object to iterate through the objects which have
been added.
### Constructor


```{.cpp}
MapOfTaggedObjects();
```

### Destructor


```{.cpp}
 MapOfTaggedObjects();
```

### Pure Public Methods


```{.cpp}
int setSize(int newSize);
```




```{.cpp}
TaggedObject \*removeComponent(int tag);
```



```{.cpp}
int getNumComponents(void) const;
```



```{.cpp}
TaggedObject \*getComponentPtr(int tag);
```



```{.cpp}
TaggedObjectIter &getComponents(void);
```



```{.cpp}
TaggedObjectStorage \*getEmptyCopy(void)
```



```{.cpp}
void clearAll(void);
```



```{.cpp}
void Print(OPS_Stream &s, int flag);
```




```{.cpp}
MapOfTaggedObjects();
```


Creates the map object and an iter for iterating through the objects
that are added to the map.

Does nothing.

```{.cpp}
int setSize(int newSize);
```


Checks to see that max size for the map (which is a built in value
defined for the template class) is larger than *newSize*. Returns $0$ if
successful. If not successful, the warning method is invoked on the
global ErrorHandler and $-1$ is returned.
To add the object `newComponent`{.cpp} to the container. First checks to see
if an element with a similar tag already exists in the map. If not, the
pointer to `newElement`{.cpp} is added to the map using the `insert()`{.cpp} method.
A check is then made to ensure that the object has been added. (This is
done as `insert()`{.cpp} returns no error flag). Returns *true* if successful.
If not successful, the warning method is invoked on the global
ErrorHandler and *false* is returned. Note that the map template does
not allow items with duplicate keys to be added.\

```{.cpp}
TaggedObject \*removeComponent(int tag);
```


To remove the component whose tag is given by `tag` from the container
and return a pointer to the object. Invokes `find(tag)`{.cpp} on the map to
first see if the element is there. If it is `erase(tag)`{.cpp} is invoked on
the map to remove the item. $0$ is returned if the component is not in
the map, otherwise a pointer to the component is returned.\

```{.cpp}
int getNumComponents(void) const;
```


Returns the number of components currently stored in the container. This
is found by invoking `size()`{.cpp} on the map object.\

```{.cpp}
TaggedObject \*getComponentPtr(int tag);
```


To return a pointer to the TaggedObject whose identifier is given by
`tag`. Invokes `find(tag)`{.cpp} on the map to determine if the component is
in the container. If it is a pointer to the component is returned. If it
is not in the map $0$ is returned.\

```{.cpp}
TaggedObjectIter &getComponents(void);
```


To return an iter for iterating through the objects that have been added
to the container. Each MapOfTaggedObjects object has its own iter. This
iter() is first reset and a reference to this iter is then returned.\

```{.cpp}
TaggedObjectStorage \*getEmptyCopy(void)
```


Returns a pointer to a new MapOfTaggedObjects which was created using
*new()*. The new container that is returned is an empty container. If
not enough memory is available to create this object the warning method
on the global ErrorHandler is invoked and $0$ is returned. Note that it
is the responsibility of the caller to invoke the destructor on the
object that is returned.\

```{.cpp}
void clearAll(void);
```


To remove all objects from the container and **to invoke the destructor
on these objects**. Goes through the container, invoking the destructor
on any object in the map. It then invokes `clear()`{.cpp} on the map object to
clear it.\

```{.cpp}
void Print(OPS_Stream &s, int flag =0);
```


Invokes `Print(s,flag)`{.cpp} on all objects which have been added to the
container.
