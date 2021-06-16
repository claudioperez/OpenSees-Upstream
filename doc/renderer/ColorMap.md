THIS INTERFACE IS GONNA CHANGE. 1) MOVABLE_OBJECT SO CAN RENDER IN
PARALLEL, 2) SET_MINMAX() and 3) ONLY ONE CALL TO GET RGB VALUES, i.e.
getRGB(value, &r, &g, &b)
#include $<\tilde{ }$/earthquake/ColorMap.h$>$


class ColorMap



```{.cpp}

```{.cpp}
ColorMap
```

```



The ColorMap is an abstract class, it defines the interface all concrete
subclasses must provide. A ColorMap object is used to determine the
mapping between scalar quantities to be displayed in an image and the
rgb values that are displayed.
### Constructor\

```{.cpp}
ColorMap();
```

### Destructor\

```{.cpp}
virtual $\tilde{ }$ColorMap();
```

### Public Methods\

```{.cpp}
virtual float getRed(float value) =0;
```



```{.cpp}
virtual float getGreen(float value) =0;
```



```{.cpp}
virtual float getBlue(float value) =0;
```



Does nothing.

Does Noting.

```{.cpp}
virtual float getRed(float value) =0;
```


To return the red intensity of the rgb triple for the scalar quantity
*value*.\

```{.cpp}
virtual float getGreen(float value) =0;
```


To return the green intensity of the rgb triple for the scalar quantity
*value*.\

```{.cpp}
virtual float getBlue(float value) =0;
```


To return the blue intensity of the rgb triple for the scalar quantity
*value*.\
