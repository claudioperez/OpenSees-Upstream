# OpenSees Commands for u--p--U Elements {#Tcl commands for upU elements}

There are two different node elements:

-   8 node brick u-p-U element `Brick8N_u_p_U` and

-   20 node brick u-p-U element `Brick20N_u_p_U`

Due to the coexistence of the solid and fluid, there are 7 degrees of
freedom at each node. The changes in the model building, analysis
procedure commands are explained as below.

## The model Command {#The model Command}

The model command defines the ModelBuilder object to be constructed.

    model BasicBuilder -ndm ndm? <-ndf ndf?>

The string -ndm that followed by an integer defines the dimension of the
problem,i.e. one, two or three dimensional problem. The string -ndf that
followed by an integer defines the number of degree-of-freedom at a
node. The angle bracket around the -ndf ndf? mean these arguments are
optional. By default, the number of degree-of-freedom at a node depends
on the dimension of the problem. For ndm=1, ndf=1;for ndm=2,ndf=3;for
ndm=3, ndf=6.

For upU element,each node has 3 solid displacements, one pore pressure,
and 3 fluid displacements, so the degree-of-freedom of each node is 7.
The ModelBuilder command for upU element is:

    model BasicBuilder -ndm 3 -ndf 7

## The fix Command {#The fix Command}

The fix command is used to construct the single-point boundary
conditions.

    fix nodeTag? (ndf values?)

where the nodeTag is the node needs to be constrained. The ndf values
can be 1 or 0. If the value of i-th ndf is specified as 1, then the
degree-of-freedom at the DOF is constrained. Otherwise 0 means that it
is left free..

The fix command for upU element is:

    fix nodeTag (7 values (1 or 0))

for example

    fix 1 1 1 1 1 1 1 1

fix all the degree-of-freedom of Node 1.

    fix 5 1 1 0 0 1 1 0

fix the solid and fluid displacement for Node 5 in x and y directions,
while the z direction of solid ,fluid and pore pressure are left free.

## The element Command {#The element Command}

The element command is used to construct an Element object.

    element eleType <specific element type args>

The second argument is the element type. The element names for the upU
are given as Brick8N_u\_p_U (for 8-node-brick-upU element) and
Brick20N_u\_p_U(for 20 node brick u-p-U element). The arguments in the
angle bracket specify the properties of each type of element.

For upU element, the element command is:(for example 20-node-upU
element):

    element Brick20N_u_p_U eleTag? 1st_node? 2nd_node?...20th_node materialID?
    x_body_force? y_body_force? z_body_force? porosity? alpha? solid_density?
    fluid_density? x_permeability? y_permeability? z_permeability?
    solid_bulk_modulus? fluid_bulk_modulus? pressure?

One upU element command might look like:

    element Brick20N_u_p_U 1 5 6 7 8 1 2 3 4 13 14 15 16 9 10 11 12 17 18 19
    20 1 0.0 0.0 -9.81 0.4 1.0 2.0 1.0 1.0e-5 1.0e-5 1.0e-5 1.0e5 1.0e5 0

The element is 20-node-brick-upU element Brick20N_u\_p_U. The element
tag is 1.The node numbers of the element is 5 6 7 8 1 2 3 4 13 14 15 16
9 10 11 12 17 18 19 20. The material tag is 1. The body forces in x and
y directions are zeros, while in z direction is -9.81. The porosity of
the element is 0.4, and alpha is 1.0. The solid density is 2.0, and
fluid density is 1.0. The permeability in x, y and z directions are all
1.0e-5. The bulk moduli of solid and fluid are both 1.0e5, and the
pressure is zero.

## The pattern Command {#The pattern Command}

The pattern command is used to construct the LoadPattern object. There
are Load and Constraint objects for the pattern.

    pattern patternType patternTag? <arguments for pattern type>

Currently, there are three valid types of pattern: Plain,
UniformExcitation and MultipleSupport. The Plain pattern has the form:

    pattern Plain patternTag? {TimeSeriesType and Args}{
    load ...
    sp ...
    }

The arguments Plain is used to construct an ordinary LoadPattern object
with a unique patterTag. The fourth argument is a list to construct the
TimeSeries object associated with the LoadPattern object. The arguments
load and sp are used to create a nodal load and single-point constraint.

In upU example, the Plain pattern of Linear type:

    pattern Plain 2 Linear{
    load 5  0 0 $p 0 0 0 0
    load 6  0 0 $p 0 0 0 0
    load 7  0 0 $p 0 0 0 0
    load 8  0 0 $p 0 0 0 0
    load 13 0 0 $np 0 0 0 0
    load 14 0 0 $np 0 0 0 0
    load 15 0 0 $np 0 0 0 0
    load 16 0 0 $np 0 0 0 0
    }

create a load pattern with vertical load \$p(depends on the value p and
np, if use command set p 5, then \$p=5 and set np 10, then \$np=10)
acting on nodes 5 6 7 8 ,and \$np acting on node 13 14 15 16.

After careful inspecting the derivations and resulting equations,
following recommendations are made for application of loads on coupled
systems:

-   For drained (vertical) distributed load $f$: all of the load $f$
    must be loaded to the solid matrix, no load goes to the fluid part
    and the fluid DOF must remain free. That is, the loading may be
    considered as only effective load without any pore pressure load.

-   For undrained (vertical) distributed load $f$: $(1-n) f$ is to be
    loaded to the solid matrix, $n f$ is to be loaded load to the fluid
    part and the fluid DOF must be constrained.
