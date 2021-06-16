\
#include $<\tilde{ }$/database/FileDatastore.h$>$



```{.cpp}
class FileDatastore:
```
 public FE_Datastore


ModelBuilder

Channel

FE_Datastore

FileDatastore is a concrete class. An FileDatastore object is used in
the program to store/restore the geometry and state information in the
domain at particular instances. This information is stored in binary
form in files. As no standard format is used for the storage of integers
and double values, files used to store the data on one type of machine,
may not be read by a FileDatastore object on another type of machine
where the storage of integers and doubles is different.\
For each of the base relations, i.e. Domain, Nodes, Elements,
SP_Constraints, MP_Constraints, NodalLoads and ElementalLoads, a
separate file is used to store the information. Files are also used for
each size of ID, Vector and Matrix stored. At present, Messages are not
stored, only ID and Vector objects of size $<= 200$ can be stored, the
max $noRows * noCols$ of Matrices that can be stored is $<= 2000$, and
only a single relation is created for Matrices which have similar sizes
but differing dimensions. The data is stored in the files following the
schema outlined previously.
### Constructor

*FileDatastore(char \*name, Domain &theDomain, FEM_ObjectBroker
&theBroker);*\
### Destructor


```{.cpp}
$\tilde{ }$FileDatastore();
```

### Public Methods inherited from the ModelBuilder Class


```{.cpp}
int buildFE_Model(void);
```

### Public Methods inherited from the FE_Datastore Class


```{.cpp}
int getDbTag(void);
```



```{.cpp}
int validateBaseRelationsWrite(int commitTag);
```



```{.cpp}
int validateBaseRelationsRead(int commitTag);
```

### Public Methods inherited from the Channel Class\

```{.cpp}
char \*addToProgram(void);
```



```{.cpp}
int setUpShadow(void);
```



```{.cpp}
int setUpActor(void);
```



```{.cpp}
int setNextAddress(const ChannelAddress &otherChannelAddress);
```



```{.cpp}
ChannelAddress \*getLastSendersAddress(void);
```



```{.cpp}
int sendObj(int commitTag,
```


MovableObject &theObject,\
ChannelAddress \*theAddress =0);




```{.cpp}
int recvObj(int commitTag,
```


MovableObject &theObject,\
FEM_ObjectBroker &theBroker,\
ChannelAddress \*theAddress =0);




```{.cpp}
int sendMsg(int dbTag, int commitTag,
```


const Message &,\
ChannelAddress \*theAddress =0);




```{.cpp}
int recvMsg(int dbTag, int commitTag,
```


Message &,\
ChannelAddress \*theAddress =0);




```{.cpp}
int sendMatrix(int dbTag, int commitTag,
```


const Matrix &theMatrix,\
ChannelAddress \*theAddress =0);




```{.cpp}
int recvMatrix(int dbTag, int commitTag,
```


Matrix &theMatrix,\
ChannelAddress \*theAddress =0);




```{.cpp}
int sendVector(int dbTag, int commitTag,
```


const Vector &theVector,\
ChannelAddress \*theAddress =0);




```{.cpp}
int recvVector(int dbTag, int commitTag,
```


Vector &theVector,\
ChannelAddress \*theAddress =0);




```{.cpp}
int sendID(int dbTag, int commitTag,
```


const ID &theID,\
ChannelAddress \*theAddress =0);




```{.cpp}
int recvID(int dbTag, int commitTag,
```


ID &theID,\
ChannelAddress \*theAddress =0);



Opens the files for the domain and base component relations, files have
names *name.relation*, and stores the end of file locations. Creates
three arrays of file pointers for the ID, Vector and Matrix files and
then zeros these arrays. If the files could not be opened, or there is
not enough memory for the arrays an error message is printed and the
program is terminated.

Each file that is opened is closed and the arrays of file pointers
obtained from the heap in the constructor are returned to the heap.

To build the finite element model from data in the database. It does
this by invoking `restor(0)`{.cpp} on itself.\

```{.cpp}
int getDbTag(void);
```


Increments the integer containing the current dbTag and returns this
integer.\

```{.cpp}
int validateBaseRelationsWrite(int commitTag);
```


The object first checks to see if the Domain has already been committed
to the database with a similar *commitTag*. If it has, a check is made
to ensure that the current domain stamp and the one at the time of this
last commit are the same. If they are different, an error message is
printed and $-1$ is returned. A check is then made to see if the
component base relations have been updated for this current domain
stamp. If they have not been the base relations are updated, and each
domain component is asked to send its data to the database. Finally the
Domain relation is updated with the current time, load factor and domain
stamp. Returns $1$ if the component base relations needed to be updated
and the component information sent, $0$ if just the Domain relation
needed to be updated. A warning message and a negative number is printed
if an error occurs.
The object first obtains from the Domain relation the information for
*commitTag*. If no information exists, an error message is printed and a
$-1$ is returned. A check is then made to see if the domain stamp for
this entity and the Domain objects current stamp are the same. If
different, `clearAll()`{.cpp} is invoked on the Domain, and from the component
base relations new domain components are created, are asked to
*recvSelf()* from *this* and these new components are added to the
Domain. Finally the current time, domain stamp and load factor are set
using the information in the entity. Returns $1$ if the domain needed to
be cleared and new component objects created, $0$ if just the Domain
object needed to be updated with current time and load factor. A warning
message and a negative number is printed if an error occurs.\

```{.cpp}
char \*addToProgram(void);
```


Returns $0$.\

```{.cpp}
int setUpShadow(void);
```


Returns $0$.\

```{.cpp}
int setUpActor(void);
```


Returns $0$.\

```{.cpp}
int setNextAddress(const ChannelAddress &otherChannelAddress);
```


Returns $0$.\

```{.cpp}
ChannelAddress \*getLastSendersAddress(void);
```


Returns $0$.\


```{.cpp}
int sendObj(int commitTag,
```


MovableObject &theObject,\
ChannelAddress \*theAddress =0);


Returns the result of invoking `sendSelf(commitTag, \*this)`{.cpp} on
*theObject*.\


```{.cpp}
int recvObj(int commitTag,
```


MovableObject &theObject,\
FEM_ObjectBroker &theBroker,\
ChannelAddress \*theAddress =0);


Returns the result of invoking *recvSelf(commitTag, \*this, theBroker)*
on *theObject*.\


```{.cpp}
int sendMsg(int dbTag, int commitTag,
```


const Message &,\
ChannelAddress \*theAddress =0);


Prints an error message and returns $-1$ as not yet implemented.\


```{.cpp}
int recvMsg(int dbTag, int commitTag,
```


Message &,\
ChannelAddress \*theAddress =0);


Prints an error message and returns $-1$ as not yet implemented.\


```{.cpp}
int sendMatrix(int dbTag, int commitTag,
```


const Matrix &theMatrix,\
ChannelAddress \*theAddress =0);


First determines the size of the matrix, $noRows * noCols$. If a files
for matrices of this size has not yet been created, one is created now
and the cell in the array of file pointers is set. If file can not be
created a warning message is printed and program is terminated. A
sequential search is made in the file to see if information is already
stored for a Matrix with this `dbTag`{.cpp} and *commitTag*. The data is then
written at this location, or eof if no location was found. The end of
file location for Matrices of this size is updated. If successful $0$ is
returned. A warning message and a negative number is returned if the
operation fails: $-1$ if Matrix size is too large.\


```{.cpp}
int recvMatrix(int dbTag, int commitTag,
```


Matrix &theMatrix,\
ChannelAddress \*theAddress =0);


First determines the size of the matrix, $noRows * noCols$. If a files
for matrices of this size has not yet been created, an error message is
printed and $-1$ is returned. A sequential search is made in the file to
see if information is already stored for a Matrix with this `dbTag`{.cpp} and
*commitTag*. If no information is stored a $-1$ is returned. If
information is stored, the information is retrieved and the data in the
Matrix is set. returns $0$ if successful.\


```{.cpp}
int sendVector(int dbTag, int commitTag,
```


const Vector &theVector,\
ChannelAddress \*theAddress =0);


If a file for Vectors of this size has not yet been created, one is
created now and the cell in the array of file pointers is set. If file
can not be created a warning message is printed and program is
terminated. A sequential search is made in the file to see if
information is already stored for a Vector with this `dbTag`{.cpp} and
*commitTag*. The data is then written at this location, or eof if no
location was found. The end of file location for Vectors of this size is
updated. If successful $0$ is returned. A warning message and a negative
number is returned if the operation fails: $-1$ if Vector size is too
large.\


```{.cpp}
int recvVector(int dbTag, int commitTag,
```


Vector &theVector,\
ChannelAddress \*theAddress =0);


If a file for Vectors of this size has not yet been created, an error
message is printed and $-1$ is returned. A sequential search is made in
the file to see if information is already stored for a Vector with this
*dbTag* and *commitTag*. If no information is stored a $-1$ is returned.
If information is stored, the information is retrieved and the data in
the Vector is set. Returns $0$ if successful.\


```{.cpp}
int sendID(int dbTag, int commitTag,
```


const ID &theID,\
ChannelAddress \*theAddress =0);


If a file for IDs of this size has not yet been created, one is created
now and the cell in the array of file pointers is set. If file can not
be created a warning message is printed and program is terminated. A
sequential search is made in the file to see if information is already
stored for a ID with this `dbTag`{.cpp} and *commitTag*. The data is then
written at this location, or eof if no location was found. The end of
file location for IDss of this size is updated. If successful $0$ is
returned. A warning message and a negative number is returned if the
operation fails: $-1$ if ID size is too large.\


```{.cpp}
int recvID(int dbTag, int commitTag,
```


ID &theID,\
ChannelAddress \*theAddress =0);


If a file for IDs of this size has not yet been created, an error
message is printed and $-1$ is returned. A sequential search is made in
the file to see if information is already stored for a ID with this
*dbTag* and *commitTag*. If no information is stored a $-1$ is returned.
If information is stored, the information is retrieved and the data in
the ID is set. Returns $0$ if successful.
