::: {.titlepage}
.

::: {.center}
G 3

**C l a s s I n t e r f a c e S p e c i f i c a t i o n**

**Version 0.1 - Preliminary Draft**

**December 20, 1999**

**Frank McKenna and Gregory L. Fenves**

**PEER, University of California at Berkeley**
:::
:::

\
This document outlines the class interfaces currently provided by G3.
The main categories of classes are:

1.  Matrix Classes: These include the classes Matrix, Vector and ID
    (integer array). These classes are used in the framework for passing
    information between objects in a safe manner, and for small scale
    numerical calculations in element formulation.

2.  Domain Classes: These classes describe the finite element model and
    store the results of an analysis on the model. The classes include
    Domain, Element, Node, Load, SP_Constraint, MP_Constraint, and their
    subclasses.

3.  Analysis Classes: These classes perform the analysis of the finite
    element model. The classes include the Analysis, ConstraintHandler,
    DOF_Numberer, SolutionAlgorithm, Integrator, FE_Element, DOF_Group
    and AnalysisModel classes, and their subclasses.

4.  Modeling Classes: These include the abstract class ModelBuilder, and
    concrete subclasses of this class. An analyst will interact with a
    ModelBuilder object, to create the Element, Node, Load and
    Constraint objects that define the model.

5.  Numerical Classes: These include the abstract SystemOfEquation and
    Solver classes, and subclasses of these classes. These classes are
    provided for the solving of large scale systems of linear and
    eigenvalue equations.

6.  Data Storage These are classes used to store data. There are two
    abstract classes TaggedObjectStorage and FE_Datastore. Objects of
    type TaggedObjectStorage are used as containers to store and provide
    access to the TaggedObjects in memory during program execution.
    FE_Datastore objects are used to store/retrieve information from
    databases, containers which can permanently hold program data.

7.  Visualization Classes These are classes used to generate images of
    the model for the analyst. These classes include Renderer, ColorMap,
    and their subclasses.

8.  Graph Classes These are classes used to provide information about
    nodal and elemental connectivity and sparsity of systems of
    equations. The classes include Graph, Vertex, GraphNumberer,
    GraphPartitioner, and their subclasses. There is no Edge class
    provided at present. In current design each Vertex stores in an ID
    the tag of all it's adjacent Vertices. For graph numbering and
    partitioning this has proved sufficient.

9.  Parallel Classes To facilitate the development of parallel
    object-oriented finite element programs, classes are provided for
    parallel programming. The classes in the framework support the
    aggregate programming model. The classes include Actor, Shadow,
    Message, MachineBroker, FEM_ObjectBroker, Channel, and their
    subclasses.

As the design is very modular and most of the classes that are provided
can be subclassed, this allows for the contribution from many
researchers in different areas. The design will allow for contributions
in the fields of:

-   Element and material types.

-   Solution algorithms, integration procedures and constraint handling
    techniques.

-   Model generation.

-   Numerical analysis for solution of linear and eigenvalue problems.

-   Graph theory for numbering and partitioning graphs.

-   Data structures for container classes and database.

-   Graphics.

-   Message passing systems and load balancing in parallel environments.

# Matrix Classes

Numerical classes are used to pass numerical information between objects
and to handle the numerical operations in the solution procedure. The
classes provided include Matrix, Vector, and ID. The abstractions
provided by the Matrix and Vector classes are obvious. The ID class
provides the abstraction of an integer array.

## Matrix

## Vector

## ID

# Domain Classes

These are the classes that are used to describe the finite element model
and to store the results of an analysis on this model. The classes
provide include Domain, Element, Node, Load, Constraint and their
subclasses. Typically, a Domain object is used as a container object to
store and provide access to the Node, Element, Load and Constraint
objects created by the ModelBuilder object.

# Analysis Classes

To facilitate code re-use and to provide for a design which is both
flexible and extensible, object-oriented design principles can be
applied to the analysis algorithm. This is first done by identifying the
main tasks performed in a finite element analysis, abstracting them into
separate classes, and then specifying the interface for these classes.
It is important that the interfaces specified allow the classes to work
together to perform the analysis and allow new classes to be introduced
without the need to change existing classes. In this design an
**Analysis** object is an aggregation of objects of the following types:

1.  **SolnAlgorithm**: The solution algorithm object is responsible for
    orchestrating the steps performed in the analysis.

2.  **AnalysisModel**: The AnalysisModel object is a container class for
    storing and providing access to the following types of objects:

    1.  **DOF_Group**: The **DOF_Group** objects represent the
        degrees-of-freedom at the **Node**s or new degrees-of-freedom
        introduced into the analysis to enforce the constraints.

    2.  **FE_Element**: The **FE_Element** objects represent the
        **Elements** in the **Domain** or they are introduced to add
        stiffness and/or load to the system of equations in order to
        enforce the constraints.

    The **FE_Element**s and **DOF_Group**s are important to the design
    because:

    1.  They remove from the **Node** and **Element** objects the need
        to worry about the mapping between degrees-of-freedoms and
        equation numbers.

    2.  They also remove from the **Node** and **Element** class
        interfaces methods for forming tangent and residual vectors,
        that are used to form the system of equations.

    3.  The subclasses of **FE_Element** and **DOF_Group** are
        responsible for handling the constraints. This removes from the
        rest of the objects the analysis aggregation the need to deal
        with the constraints.

3.  **Integrator**: The **Integrator** object is responsible for
    defining the contributions of the **FE_Element**s and **DOF_Group**s
    to the system of equations and for updating the response quantities
    at the **DOF_Group**s with the appropriate values given the solution
    to the system of equations.

4.  **ConstraintHandler**: The **ConstraintHandler** object is
    responsible for handling the constraints. It does this by creating
    **FE_Element**s and **DOF_Group**s of the correct type.

5.  **DOF_Numberer**: The **DOF_Numberer** object is responsible for
    mapping equation numbers in the system of equations to the
    degrees-of-freedom in the **DOF_Group**s.

# Modeling Classes

Modeling classes are used to create the finite element model for a given
problem. The classes provided are subclasses of ModelBuilder. An analyst
will interact with a ModelBuilder object, to create the Element, Node,
Load and Constraint objects that define the model.

# Numerical Classes

Numerical classes are used to pass numerical information between objects
and to handle the numerical operations in the solution procedure. The
classes provided include Matrix, Vector, ID, SystemOfEquations, Solver
and subclasses of these classes.

# Material Classes

Material classes are used to provide information to the Elements about
the material. There is one main class MaterialModel. The Element objects
query the MaterialModel objects to obtain the current value of stress
and the tangent defining the stress-strain relationship for the current
value of strain at the point in the domain represented by the
MaterialModel object.

# Data Storage

In this work there are two general types of data storage classes
provided:

1.  Classes which can be used to store and provide access to the
    TaggedObjects during program execution. The abstract base class for
    these classes is TaggedObjectStorage. The concrete subclasses can
    implement the interface using the traditional CS data storage
    techniques, such as arrays, linked lists, hash tables, etc..

2.  Classes which can be used to store and retrieve information from
    permanent data archives, i.e. databases. The abstract base class
    defining the interface for these classes is FE_Datastore.

# Visualization Classes

These are classes used to present images of the model. These include the
abstract classes Renderer and ColorMap. There are two steps in the
creation of any graphical image: (1) create a model of the object to be
displayed; and (2) render the model to an image that is viewed on the
screen. The creation and rendering can be part of the same application,
or can be split into two separate applications, where a 3d description
of the model using a scene description language is o/p by the modeler
and i/p by the renderer.

In our finite element work **we have the model**, the domain. Though the
model we have is not typical, as it requires the displaying of scalar
and vector quantities and not just rgb values. **We need to develop an
interface for the renderer**. To do this we will introduce an abstract
class **Renderer** which defines this interface. Doing this will allow
full extensibility as it will allow concrete subclasses to be provided
which may render the model to the screen, or generate an SDL file which
can be read in by a rendering application or printed on a printer at a
later stage.

The interface for the Renderer class we introduce will be very simple.
It will only accept very simple primitive objects to be displayed (line
and polygon). As such, the Renderer will not be required to render the
components of the model, rather the components of the model will be
required to display themselves. This will allow both the introduction of
new component types, for example new element types, without existing
Renderer classes being required to be rewritten and also new Renderer
classes will be able to be introduced with the only requirement that
they be able to display the primitive object types. The drawback of
course is that the present design has to be modified to allow the
components to display themselves. On the otherhand, as the objects can
display themselves, it will allow complex images to be displayed, e.g.
3d beam elements with proper geometry and deformation along the length
or beam with plastic hinges at ends could indicate amount of rotation at
ends.

# Utility Classes

# Graph Classes

In this work Graphs are used for three purposes:

1.  to provide information on the sparsity of the system of equation to
    the SystemofEqn object,

2.  to provide the connectivity of the DOF_Group objects for determining
    a good mapping between degrees-of-freedom and equation numbers.

3.  to provide information on the connectivity both the Elements and
    Nodes in the Domain, which can be useful for example in
    partitioning.

The classes provided include Graph, Vertex, GraphNumberer and
GraphPartitioner. There is no Edge class provided at present. In current
design each Vertex stores in an ID the tag of all it's adjacent
Vertices, this may change. For graph numbering and partitioning this has
to date proved sufficient.

# Parallel Classes

To facilitate the development of parallel object-oriented finite element
programs, a new framework is presented in this section. The classes in
the framework support the aggregate programming model. The new classes
are:

-   **Shadow** - A Shadow object represents a remote actor object in the
    local actor process.

-   **Actor** - An Actor object is a local object in the remote actor
    process. It performs the operations requested of it by the Shadow
    object. The actor objects in an aggregation collectively perform the
    analysis operations by communicating between themselves.

-   **Channel** - The Shadow and Actor objects communicate with each
    other through Channel objects. A Channel object represents a point
    in a local actor process through which a local object can send and
    receive information.

-   **Address** - An Address object represents the location of a Channel
    object in the machine space. Channel objects send information to
    other Channel objects, whose locations are given by an Address
    object. Channel objects also receive information from other Channel
    objects, whose locations are given by an Address object.

-   **MovableObject** - A MovableObject is an object which can send its
    state from one actor process to another.

-   **ObjectBroker** - An ObjectBroker is an object in a local actor
    process for creating new objects.

-   **MachineBroker** - A MachineBroker is an object in a local actor
    process that is responsible for creating remote actor processes at
    the request of Shadow objects in the same local process.
