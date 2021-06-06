# Large Deformation Hyperelasto-Plastic Material Model Commands 

## Yield Surface Commands {#fdys}

    set fdy "-fdYieldSurfaceType <parameter list>" 

This command sets the yield surface variables `fdY` or `fdYield` to be
the specific type. A list of parameters can be defined the yield surface
and the number of parameters depend on the type of yield surface.
Currently, fdYieldSurfaceType cab be Von-Mises and Druker-Prager yield
surfaces, which are described in the following subsections.

### Von-Mises Yield Surface Commands {#fdVMys}

    set fdy "-VM Y0?" 

`VM` stands for Von-Mises type, i.e. cylinder shaped yield surface. The
parameter `Y0` defines the material yielding strength, i.e. when
uniaxial loading, `Y0` is then the uniaxial yielding strength.

### Druker-Prager Yield Surface Commands {#fdDPys}

    set fdy "-DP fa? c? <ConeIndex?>" 

`DP` stands for Druker-Prager type, i.e. cone shaped yield surface. The
parameter `fa` defines the material friction angle with the unit of
degree. The parameter `c` defines the material cohesion strength. The
optional parameter `ConeIndex` is the index to show what the type of
cone is used:

-   `ConeIndex` = 0, compressive (outer) cone;

-   `ConeIndex` = 1, tensile (inner) cone;

-   `ConeIndex` = 2, mean cone;

-   `ConeIndex` = 3, inner-tangent cone;

-   default, compressive (outer) cone.

## Potential Surface Commands {#fdps}

    set fdf "-fdPotentialSurfaceType <parameter list>" 

This command sets the potential surface variables `fdY` or `fdYield` to
be the specific type. A list of parameters can be defined the potential
surface and the number of parameters depend on the type of potential
surface. Currently, fdPotentialSurfaceType cab be Von-Mises and
Druker-Prager potential surfaces, which are described in the following
section.

### Von-Mises Potential Surface Commands {#fdVMps}

    set fdf "-VM Y0?" 

`VM` stands for Von-Mises type, i.e. cylinder shaped potential surface.
The parameter `Y0` equals to the material yielding strength, i.e. when
uniaxial loading, `Y0` is then the uniaxial yielding strength.

### Druker-Prager Potential Surface Commands {#fdDPps}

    set fdf "-DP da? <ConeIndex?>" 

`DP` stands for Druker-Prager type, i.e. cone shaped yield surface. The
parameter `da` equals to the material dilatant angle with the unit of
degree. The optional parameter `ConeIndex` is the index to show what the
type of cone is used:

-   `ConeIndex` = 0, compressive (outer) cone;

-   `ConeIndex` = 1, tensile (inner) cone;

-   `ConeIndex` = 2, mean cone;

-   `ConeIndex` = 3, inner-tangent cone;

-   default, compressive (outer) cone.

## Evolution Law Commands {#fdEL}

There are two types of evolution laws:

-   Isotropic (scalar) evolution law: `fdES` or `fdEvolution_S`;

-   Kinematic (tensor) evolution law: `fdET` or `fdEvolution_T`.

### Linear and/or Saturated Isotropic Evolution Law {#fdLSES}

    set fdes "-LS H? <qs? beta?>"

`LS` stands for Linear and/or Saturated Isotropic Evolution Law. The
parameter `H` is the linear isotropic hardening modulus. The optional
parameters `qs` and `beta` are saturated type isotropic hardening
constants; if they are used, then it is the combination of linear and
saturated isotropic hardening. This hardening rule can be applied to any
scalar internal variable, such as the diameter of Von-Mises yield
surface.

### Linear Kinematic Evolution Law {#fdLET}

    set fdet "-Linear H?"

`Linear` stands for Linear kinematic Evolution Law. The parameter `H` is
the linear isotropic hardening modulus. This hardening rule can be
applied to any tensorial internal variable, such as the center of
Von-Mises yield surface.

## Hyperelasto-Plastic (Finite Deformation EP) Material Commands {#HEP_Command}

    nDMaterial FDEP3D mTag? hTag? -fdY $fdy -fdF $fdf <-fdES $fdes> <-fdET $fdet> 

A hyperelasto-plastic material is constructed using `nDMaterial`
command. The argument `mTag` is used to uniquely identify this
nDMaterial object among nDMaterial objects in the BasicBuilder object.
The key word `FDEP3D` cab be replaced by `FiniteDeformationEP3D`. The
argument `hTag` is the previously defined hyperelastic material tag. The
other parameters include previously defined yield surface object `fdY`,
potential surface object `fdF`, optional isotropic evolution law object
`fdES`, and optional kinematic evolution law object `fdET`. The key word
`fdY` can be replaced by `fdYield`, and `fdF` can be replaced by
`fdFlow`.
