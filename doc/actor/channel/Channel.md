\
#include $<\tilde{ }$/actor/channel/Channel.h$>$


class Channel



```{.cpp}

```{.cpp}
Channel
```

```



Channel is an abstract class, i.e. no instances of Channel should exist.
A Channel is a point of communication in a program, a mailbox to/from
which data enters/leaves a program. Channels are objects through which
the objects in the current processes address space can interact with
objects in another processes address space. A channel in one process
space is associated with a channel in the address space of another
process space. The interaction is in the form of data sent between the
two processes along the connection line.\
### Constructor


```{.cpp}
Channel();
```

### Destructor


```{.cpp}
virtual  $\tilde{}$Channel();
```

### Public Methods


```{.cpp}
char \*addToProgram(void) =0;
```



```{.cpp}
virtual int setUpShadow(void) =0;
```



```{.cpp}
virtual int setUpActor(void) =0;
```



```{.cpp}
virtual int setNextAddress(ChannelAddress &theNextAddress) =0;
```



```{.cpp}
virtual ChannelAddress \*getLastSendersAddress(void) =0;
```



```{.cpp}
virtual int getDbTag(void);
```



```{.cpp}
int sendObj(int commitTag,
```


MovableObject &theObject,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int recvObj(int commitTag,
```


MovableObject &theObject,\
FEM_ObjectBroker &theBroker,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int sendMsg(int dbTag, int commitTag,
```


const Message &,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int recvMsg(int dbTag, int commitTag,
```


Message &,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int sendMatrix(int dbTag, int commitTag,
```


const Matrix &theMatrix,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int recvMatrix(int dbTag, int commitTag,
```


Matrix &theMatrix,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int sendVector(int dbTag, int commitTag,
```


const Vector &theVector,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int recvVector(int dbTag, int commitTag,
```


Vector &theVector,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int sendID(int dbTag, int commitTag,
```


const ID &theID,\
ChannelAddress \*theAddress =0) =0;




```{.cpp}
int recvID(int dbTag, int commitTag,
```


ID &theID,\
ChannelAddress \*theAddress =0) =0;



```{.cpp}
Channel();
```


Does nothing.

Does nothing. Provided so that a subclasses destructor will be invoked.

```{.cpp}
char \*addToProgram(void) =0;
```


When creating remote actors the channels created in the actor space need
to know how to contact the shadows channels. This information is
provided in the string returned from this method. It is used by the
machine broker when starting the remote process. It places this
information as the last arguments to the program.\

```{.cpp}
virtual int setUpShadow(void) =0;
```


A method invoked in the local address space by a shadow object. The
method is to be invoked concurrently with a `setUpShadow()`{.cpp} invocation
on a channel object in all the remote actor processes.\

```{.cpp}
virtual int setUpActor(void) =0;
```

A method invoked in the remote address space by the actor. The method is
invoked concurrently with a corresponding `setUpShadow()`{.cpp} invocation on
a channel in a local actor process by the shadow object that created the
running actor process. If the method fails returns a negative number.
For actors with only one Channel this should cause the termination of
the actor.\

```{.cpp}
virtual int setNextAddress(ChannelAddress &theNextAddress) =0;
```

A method invoked to set specify the next address that the next messages
to be sent if `sendMessage()* or received if *recvMessage()`{.cpp} is invoked
with a null pointer.\

```{.cpp}
virtual int getDbTag(void);
```


To return the next available database tag, must be an integer value
greater than $0$, $0$ is used my the objects to check if they have yet
been assigned a database tag. The method defined for the Channel base
class always returns $0$, only database channel objects need worry about
assigning unique integer values.\


```{.cpp}
int sendObj(int commitTag,
```


MovableObject &theObject,\
ChannelAddress \*theAddress =0) =0;


To send the object `theObject`{.cpp} and the commit tag `commitTag`{.cpp} to a
remote Channel whose address is given by *theAddress*. If *theAddress*
is $0$, the Channel sends to the Channel with the address last set in a
*send..()*, *recv..()*, or `setNextAddress()`{.cpp} operation. To return $0$
if successful, a negative number if not.\


```{.cpp}
int recvObj(int commitTag,
```


MovableObject &theObject,\
FEM_ObjectBroker &theBroker,\
ChannelAddress \*theAddress =0) =0;


To receive the object `theObject`{.cpp} with the commit tag `commitTag`{.cpp} from a
remote Channel whose address is given by *theAddress*. If *theAddress*
is $0$, the Channel receives from the Channel with the address last set
in a *send..()*, *recv..()*, or `setNextAddress()`{.cpp} operation. To return
$0$ if successful, a negative number if not.\


```{.cpp}
int sendMsg(int dbTag, int commitTag,
```


const Message &theMessage,\
ChannelAddress \*theAddress =0) =0;


A method which is invoked to send the data in the Message object
*theMessage* to another Channel object. The object will obtain the data
and size of the data to be sent by invoking `getData()`{.cpp} and *getSize()*
on *theMessage*. The channel object is then responsible for sending that
data to the remote channel address given by *theAddress*. If
*theAddress* is $0$, the Channel sends to the Channel with the address
last set in a *send..()*, *recv..()*, or `setNextAddress()`{.cpp} operation.
To return $0$ if successful, a negative number if not.\


```{.cpp}
int recvMsg(int dbTag, int commitTag,
```


Message & theMessage,\
ChannelAddress \*theAddress =0) =0;


A method which is invoked to send the data in the Message object
*theMessage* to another Channel object. The object will obtain the the
size of the data that is being received by invoking `getSize()`{.cpp} on
*theMessage*. The channel object is then responsible for receiving that
amount of data from the channel whose address is given by *theAddress*.
If `theAddress`{.cpp} is $0$, the Channel receives from the Channel with the
address last set in a *send..()*, *recv..()*, or *setNextAddress()*
operation. To return $0$ if successful, a negative number if not.\


```{.cpp}
int sendMatrix(int dbTag, int commitTag,
```


const Matrix &theMatrix,\
ChannelAddress \*theAddress =0) =0;


A method for sending a Matrix `theMatrix`{.cpp} to a remote Channel, whose
address is given by *theAddress*, with the integer identifiers *dbTag*
and *commitTag*. If `theAddress`{.cpp} is $0$, the Channel sends to the
Channel with the address last set in a *send..()*, *recv..()*, or
*setNextAddress()* operation. To return $0$ if successful, a negative
number if not.\


```{.cpp}
int recvMatrix(int dbTag, int commitTag,
```


Matrix &theMatrix,\
ChannelAddress \*theAddress =0) =0;


A method for receiving a Matrix `theMatrix`{.cpp} from a remote Channel, whose
address is given by *theAddress*, with the integer identifiers *dbTag*
and *commitTag*. If `theAddress`{.cpp} is $0$, the Channel receives from the
Channel at the address last set in a *send..()*, *recv..()*, or
*setNextAddress()* operation. To return $0$ if successful, a negative
number if not.\


```{.cpp}
int sendVector(int dbTag, int commitTag,
```


const Vector &theVector,\
ChannelAddress \*theAddress =0) =0;


A method for sending a Vector `theVector`{.cpp} to a remote Channel, whose
address is given by *theAddress*, with the integer identifiers *dbTag*
and *commitTag*. If `theAddress`{.cpp} is $0$, the Channel sends to the
Channel with the address last set in a *send..()*, *recv..()*, or
*setNextAddress()* operation. To return $0$ if successful, a negative
number if not.\


```{.cpp}
int recvVector(int dbTag, int commitTag,
```


Vector &theVector,\
ChannelAddress \*theAddress =0) =0;


A method for receiving a Vector `theVector`{.cpp} from a remote Channel, whose
address is given by *theAddress*, with the integer identifiers *dbTag*
and *commitTag*. If `theAddress`{.cpp} is $0$, the Channel receives from the
Channel at the address last set in a *send..()*, *recv..()*, or
*setNextAddress()* operation. To return $0$ if successful, a negative
number if not.\


```{.cpp}
int sendID(int dbTag, int commitTag,
```


const ID &theID,\
ChannelAddress \*theAddress =0) =0;


A method for sending a ID `theID`{.cpp} to a remote Channel, whose address is
given by *theAddress*, with the integer identifiers `dbTag`{.cpp} and
*commitTag*. If `theAddress`{.cpp} is $0$, the Channel sends to the Channel
with the address last set in a *send..()*, *recv..()*, or
*setNextAddress()* operation. To return $0$ if successful, a negative
number if not.\


```{.cpp}
int recvID(int dbTag, int commitTag,
```


ID &theID,\
ChannelAddress \*theAddress =0) =0;


A method for receiving a ID `theID`{.cpp} from a remote Channel, whose address
is given by *theAddress*, with the integer identifiers `dbTag`{.cpp} and
*commitTag*. If `theAddress`{.cpp} is $0$, the Channel receives from the
Channel at the address last set in a *send..()*, *recv..()*, or
*setNextAddress()* operation. To return $0$ if successful, a negative
number if not.
