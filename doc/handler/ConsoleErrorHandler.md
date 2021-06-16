\
#include $<\tilde{ }$/handler/ConsoleErrorHandler.h$>$


class ConsoleErrorHandler


ErrorHandler


The ConsoleErrorHandler class is a concrete subclass of error handler
which sends the error messages to the opserr stream.
### Constructor


```{.cpp}
ConsoleErrorHandler();
```

### Destructor


```{.cpp}
$\tilde{ }$ConsoleErrorHandler();
```

### Public Methods


```{.cpp}
void warning(const char \*msg, \...);
```




Does nothing.

Does nothing.

```{.cpp}
void warning(const char \*msg, \...) =0;
```


Creates a va_list using `va_start()`{.cpp} on the ellipses arguments and
invokes the `outputMessage(opserr, msg, va_list)`{.cpp} routine in the parent
class. It then invokes `va_end()`{.cpp} on this va_list and returns.\

```{.cpp}
void fatal(const char \*msg, \...) =0;
```


Creates a va_list using `va_start()`{.cpp} on the ellipses arguments and
invokes the `outputMessage(opserr, msg, va_list)`{.cpp} routine in the parent
class. It then invokes `va_end()`{.cpp} on this va_list, and finally
terminates the program with an *exit()*.
