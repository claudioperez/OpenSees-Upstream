\
#include $<\tilde{ }$/actor/shadow/Shadow.h$>$


class Shadow



```{.cpp}

```{.cpp}
Shadow
```

```



Shadow is meant as an abstract class, i.e. no instances of Shadow should
exist. A Shadow object is associated with an Actor object which may
exist in another process. The Shadow acts like a normal object in the
users address space, data and processing that is done by the Shadow may
be stored and processed in a remote process, the Actor object resides in
this remote address space. The Actor and the Shadow both have a Channel,
a communication port. This allows the two to communicate with each
other.
### Constructors



### Destructor

### Protected Methods for Sending Objects to Remote Actor









```{.cpp}
Shadow(Channel &theChannel,
```


FEM_ObjectBroker &theBroker,\
ChannelAddress &theActorsAddress);


This constructor is used when the actor process is already up and
running. The constructor sets its channel to be *theChannel*, its
associated object broker to be *theBroker*, and the address to which it
will send data to be *thaActorsAddress*.\


```{.cpp}
Shadow(char \*program,
```


Channel &theChannel,\
FEM_ObjectBroker &theBroker,\
MachineBroker &theMachineBroker,\
int compDemand,\
bool startShadow);


This constructor is used to get an actor process up and running. If
*startShadow* is *true*, the constructor invokes

```{.cpp}
startActor(program,theChannel,compDemand)* on *theMachineBroker
```

object. It then invokes `setUpShadow()`{.cpp} on `theChannel`{.cpp} and
*getLastSendersAddress()* on `theChannel`{.cpp} to set up store the address of
the actors channel, *theActorsAddress*; this is done in case multiple
shadow objects use a single channel. If an error occurs an error message
is printed and the program terminated.

Does nothing.


```{.cpp}
virtual void sendObject(MovableObject &theObject);
```


A method which will send the MovableObject `theObject`{.cpp} to the actor
object through the shadows channel. It returns the result of invoking
*sendObj(0,0,theObject, theBroker, theActorsAddress)* on the shadow's
associated channel *theChannel*.\

```{.cpp}
virtual void recvObject(MovableObject &theObject);
```

A method which will cause the object to read the MovableObject
*theObject* from the channel. It will return the result of invoking
*recvObj(0,0,theObject, theBroker, theActorsAddress)* on the shadows
associated channel *theChannel*.\

```{.cpp}
virtual void sendMessage(Message &theMessage);
```


A method which will send the message `theMessage`{.cpp} to the actor object
through the shadows channel. It will return the result of invoking
*sendMsg(0,0,theMessage, theActorsAddress)* on the shadows associated
channel *theChannel*.\

```{.cpp}
virtual void recvMessage(Message &theMessage);
```

A method which will cause the object to read the message *theMessage*
from the channel. It will return the result of invoking
*recvMsg(0,0,theMessage, theActorsAddress)* on the shadows associated
channel *theChannel*.\

```{.cpp}
virtual void sendMatrix(Matrix &theMatrix);
```


A method which will send the Matrix `theMatrix`{.cpp} to the actor object
through the shadows channel. It will return the result of invoking
*sendMatrix(0,0,theMatrix, theActorsAddress)* on the shadows associated
channel *theChannel*.\

```{.cpp}
virtual void recvMatrix(Matrix &theMatrix);
```

A method which will cause the object to read the Matrix `theMatrix`{.cpp} from
the channel. It will return the result of invoking
*recvMatrix(0,0,theMatrix, theActorsAddress)* on the shadows associated
channel *theChannel*.\

```{.cpp}
virtual void sendVector(Vector &theVector);
```


A method which will send the Vector `theVector`{.cpp} to the actor object
through the shadows channel. It will return the result of invoking
*sendVector(0,0,theVector, theActorsAddress)* on the shadows associated
channel *theChannel*.\

```{.cpp}
virtual void recvVector(Vector &theVector);
```

A method which will cause the object to read the Vector `theVector`{.cpp} from
the channel. It will return the result of invoking
*recvVector(0,0,theVector, theActorsAddress)* on the shadows associated
channel *theChannel*.\

```{.cpp}
virtual void sendID(ID &theID);
```


A method which will send the ID `theID`{.cpp} to the actor object through the
shadows channel. It will return the result of invoking
*sendID(0,0,theID, theActorsAddress)* on the shadows associated channel
*theChannel*.\

```{.cpp}
virtual void recvID(ID &theID);
```

A method which will cause the object to read the ID `theID`{.cpp} from the
channel. It will return the result of invoking *recvID(0,0,theID,
theActorsAddress)* on the shadows associated channel *theChannel*.\

```{.cpp}
void Channel \*getChannelPtr(void) const;
```

A method which returns a pointer to the channel currently set.\

```{.cpp}
void FEM_ObjectBroker \*getObjectBrokerPtr(void) const;
```

A method which returns a pointer to the FEM_ObjectBroker passed in the
constructor.\

```{.cpp}
void ObjectBroker \*getActorAddressPtr(void) const;
```

A method which returns a pointer to the channel in the actors address
space.\
