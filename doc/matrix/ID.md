\
#include $<\tilde{ }$/matrix/ID.h$>$



```{.cpp}
class ID:
```




```{.cpp}

```{.cpp}
ID
```

```



The ID class provides the abstraction for an integer Vector. The class
is introduced in addition to the Vector class, to save memory and
casting when integer arrays are required. An ID of order *size* is an
ordered 1d array of *size* integer values. For example an ID id of order
5:\
$id = [id_0$ $id_1$ $id_2$ $id_3$ $id_4]$\
In the ID class, the data is stored in a 1d integer array of length
equal to arraySize, where order \<= arraySize. Creating an ID with
storage capacity greater than that required allows the ID object to grow
without the need to deallocate and allocate more memory. At present time
none of the methods are declared as being virtual. THIS MAY CHANGE.


```{.cpp}
ID();
```



```{.cpp}
ID(int idSize);
```



```{.cpp}
ID(int idSize, int arraySize);
```



```{.cpp}
ID(const ID &M);
```

### Destructor


```{.cpp}
virtual  $\tilde{}$ID();
```

### Public Methods


```{.cpp}
virtual int Size() const;
```



```{.cpp}
virtual void Zero();
```



```{.cpp}
virtual int getLocation(int x) const;
```



```{.cpp}
virtual int removeValue(int x);
```

### Overloaded Operator Functions


```{.cpp}
virtual double &operator()(int x);
```



```{.cpp}
virtual double &operator\[\](int x);
```



```{.cpp}
virtual ID &operator=(const ID &M);
```





```{.cpp}
ID();
```


To construct an ID of size $0$. No memory is allocated for the storage
of the data.\

```{.cpp}
ID(int idSize);
```


To construct a ID of size *idSize*. The constructor creates an integer
array of size `idSize`{.cpp} to store the data and zeroes this array by
invoking `Zero()`{.cpp} on itself. If not enough memory is available an error
message is printed and an ID of size $0$ is returned.\

```{.cpp}
ID(int idSize, int arraySize);
```


To construct a ID of size *idSize*. The constructor creates an integer
array of size `arraySize`{.cpp} to store the data and zeroes this array. If
*arraySize* is less than *idSize*, the new `arraySize`{.cpp} is set equal to
*idSize*. If not enough memory is available an error message is printed
and the program is terminated. This constructor is provided to allow an
ID to grow.\

```{.cpp}
ID(const ID &M);
```


To construct an ID using another ID *M*. The new ID will be identical to
the ID $M$, same order and same size of array to hold the integer
values. If not enough memory is available a warning message is printed
and both the order and arraySize of the ID are set to $0$.

Will invoke delete on the integer array used to store the components.

```{.cpp}
virtual int Size() const;
```


Returns the order of the ID.\

```{.cpp}
virtual void Zero();
```


Zeros out the ID, i.e. sets all the components of the ID to $0$. This is
accomplished by zeroing the first *this.Size()* components of the
array.\

```{.cpp}
virtual int getLocation(int x) const;
```


Will return the location the first location in the ID of the integer
*x*. If *x* is not in the ID a $-1$ is returned.\

```{.cpp}
virtual int removeValue(int x);
```


Will return the last location in the ID of the integer *x*. If *x* is
not in the ID a $-1$ is returned. All the integer components *x* are
removed from the ID and the length of the ID is reduced by the number of
the removed components. The `arraySize`{.cpp} remains unchanged.

```{.cpp}
virtual virtual double &operator()(int x) const;
```


Returns the data at location *x* in the ID. Assumes (*x*) is a valid
location in the ID, a segmentation fault or erroneous results can occur
if this is not the case.\

```{.cpp}
virtual double &operator()(int x);
```


Used to set the data at location(*x*) in the ID. Assumes (*x*) is a
valid location in the ID, a segmentation fault or erroneous results can
occur if this is not the case.\

```{.cpp}
virtual double &operator\[\](int x);
```


Used to set the data at location(*x*) in the ID. If *x* is outside the
order of the ID the ID is order of the ID is enlarged to *x+1*. When
increasing the order, a check is first made to see if the current array
is large enough; if it is the components between the old end and the new
component are set to $0$ and the order of the ID is set to *x+1*, if not
a new array is created. The size of this array is max($2*$old array
size, x). A copy of the components of the old array into the new array
is made, with any new components set to $0$. If not enough space is
available or *x* is less than $0$, a warning message is printed and the
contents of ID_ERROR returned.\

```{.cpp}
virtual ID &operator=(const ID &M);
```


Sets the current ID to be equal to the ID given by *M*. If the IDs are
of different sizes, the current data is deallocated and more space
allocated before the contents are copied. If not enough memory is
available, the order and `arraySize`{.cpp} of the current ID is set to $0$ and
the ID is returned without copying the components.\

```{.cpp}
friend OPS_Stream &operator$<<$(OPS_Stream &s, const ID &id);
```

A function to print out the contents of the ID *id* to the output stream
*s*. Prints out the components into the stream and then sends a newline
character.\

```{.cpp}
friend istream &operator$>>$(istream &s, const ID &id);
```

A function to read the contents of the ID *id* from the input stream
*s*. Sets the components of *id* equal to the next *id.Size()* entries
in the stream.\
