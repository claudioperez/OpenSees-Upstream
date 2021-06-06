# Large Deformation Hyperelastic Material Model Commands

## Compressible Neo-Hookean Material Commands {#CompNH}

    nDMaterial NeoHookean3D matTag? K? G? <rho?> 

or

    nDMaterial NeoHookeanCompressible3D matTag? K? G? <rho?> 

This model is the traditional compressible Neo-Hookean material model. A
compressible Neo-Hookean material is constructed using `nDMaterial`
command. The argument `matTag` is used to uniquely identify this
nDMaterial object among nDMaterial objects in the BasicBuilder object.
The parameter `K` defines the material reference bulk modulus. The
parameter `G` defines the material reference shear modulus. The optional
parameter `rho` defines the material reference density, the default
value of rho is zero.

Although this is named compressible Neo-Hookean material, it can also be
used for near-compressible or incompressible material. In this case,
make `K` a value far bigger than `G`.

## Decoupled Neo-Hookean Material Commands {#DNH}

    nDMaterial DecoupledNH3D matTag? K? G? <rho?> 

or

    nDMaterial DecoupledNeoHookean3D matTag? K? G? <rho?> 

This model is a decoupled model for its volumetric and isochoric parts.
A decoupled Neo-Hookean material is constructed using `nDMaterial`
command. The argument `matTag` is used to uniquely identify this
nDMaterial object among nDMaterial objects in the BasicBuilder object.
The parameter `K` defines the material reference bulk modulus. The
parameter `G` defines the material reference shear modulus. The optional
parameter `rho` defines the material reference density, the default
value of rho is zero.

## Decoupled Logarithmic Material Commands {#DLog}

    nDMaterial DecoupledLog3D matTag? K? G? <rho?> 

or

    nDMaterial DecoupledLogarithmic3D matTag? K? G? <rho?> 

This model is a decoupled model for its volumetric and isochoric parts.
A decoupled logarithmic material is constructed using `nDMaterial`
command. The argument `matTag` is used to uniquely identify this
nDMaterial object among nDMaterial objects in the BasicBuilder object.
The parameter `K` defines the material reference bulk modulus. The
parameter `G` defines the material reference shear modulus. The optional
parameter `rho` defines the material reference density, the default
value of rho is zero.

## Decoupled Mooney-Rivlin-Simo Material Commands {#DMRS}

    nDMaterial DecoupledMRS3D matTag? c1? c2? K? <rho?> 

or

    nDMaterial DecoupledMooneyRivlinSimo3D matTag? c1? c2? K? <rho?> 

This model is a decoupled model for its volumetric and isochoric parts.
Its isochoric part is Mooney-Rivlin model and its volumetric part is
Simo-Pister model. A decoupled Mooney-Rivlin-Simo material is
constructed using `nDMaterial` command. The argument `matTag` is used to
uniquely identify this nDMaterial object among nDMaterial objects in the
BasicBuilder object. The parameter `c1` and `c2` define the material
constants. The parameter `K` defines the material reference bulk
modulus. The optional parameter `rho` defines the material reference
density, the default value of rho is zero.

## Decoupled Ogden-Simo Material Commands {#DOS}

    nDMaterial DecoupledOS3D matTag? N? c1? ... cN? m1? ... mN? K? <rho?> 

or

    nDMaterial DecoupledOgdenSimo3D matTag? N? c1? ... cN? m1? ... mN? K? <rho?> 

This model is a decoupled model for its volumetric and isochoric parts.
Its isochoric part is Ogden model and its volumetric part is Simo-Pister
model. A decoupled Ogden-Simo material is constructed using `nDMaterial`
command. The argument `matTag` is used to uniquely identify this
nDMaterial object among nDMaterial objects in the BasicBuilder object.
The parameter `N`, `c1`, \..., `cN`, and `m1`, \..., `mN` define the
material constants. The parameter `K` defines the material reference
bulk modulus. The optional parameter `rho` defines the material
reference density, the default value of rho is zero.

## Decoupled Mooney-Rivlin Material Commands {#DMR}

    nDMaterial DecoupledMR3D matTag? c1? c2? <rho?> 

or

    nDMaterial DecoupledMooneyRivlin3D matTag? c1? c2? <rho?> 

This model is a decoupled isochoric model. A decoupled
Mooney-Rivlin-Simo material is constructed using `nDMaterial` command.
The argument `matTag` is used to uniquely identify this nDMaterial
object among nDMaterial objects in the BasicBuilder object. The
parameter `c1` and `c2` define the material constants. The optional
parameter `rho` defines the material reference density, the default
value of rho is zero.

## Decoupled Ogden Material Commands {#DO}

    nDMaterial DecoupledOgden3D matTag? N? c1? ... cN? m1? ... mN? <rho?> 

This model is a decoupled isochoric model. A decoupled Ogden-Simo
material is constructed using `nDMaterial` command. The argument
`matTag` is used to uniquely identify this nDMaterial object among
nDMaterial objects in the BasicBuilder object. The parameter `N`, `c1`,
\..., `cN`, and `m1`, \..., `mN` define the material constants. The
optional parameter `rho` defines the material reference density, the
default value of rho is zero.

## Decoupled Simo-Pister Material Commands {#DSP}

    nDMaterial DecoupledSP3D matTag? K? <rho?> 

or

    nDMaterial DecoupledSimoPister3D matTag? K? <rho?> 

This model is a decoupled volumetric model. A decoupled Simo-Pister
material is constructed using `nDMaterial` command. The argument
`matTag` is used to uniquely identify this nDMaterial object among
nDMaterial objects in the BasicBuilder object. The parameter `K` defines
the material reference bulk modulus. The optional parameter `rho`
defines the material reference density, the default value of rho is
zero.
