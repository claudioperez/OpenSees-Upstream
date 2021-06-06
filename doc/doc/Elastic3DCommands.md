# OpenSees Command to Create Elastic Isotropic/Anisotropic 3D Material 

There are two types of 3D elastic isotropic material models (i.e. linear
elastic and nonlinear or pressure sensitive elastic materials) and one
cross anisotropic elastic material model that you can create.

## ElasticIsotropic3D command {#LinEla}

    nDMaterial ElasticIsotropic3D matTag? E0? nu? rho?

The `ElasticIsotropic3D` material is the standard linear elastic
isotropic three dimensional material implemented based on tensor
operation. The arguments to construct the material are its tag,
`matTag`, Young's Modulus at atmospheric pressure `E0`, Poisson's ratio
`nu`, and mass density `rho`.

## PressureDependentElastic3D command {#NonlEla}

    nDMaterial PressureDependentElastic3D matTag? E0? nu? rho? n? pr? pc? 

The `PressureDependentElastic3D` material is the standard nonlinear
elastic isotropic three dimensional material implemented based on tensor
operation. The first four arguments are the same as linear elastic
command described above. The pressure dependent elastic modulus is to be
determined using the following formula
[\[NonLineEl011\]](#NonLineEl011){reference-type="ref"
reference="NonLineEl011"} . There are three more arguments for this
command. `n` is the exponent, `pr` ($p_{ref}$) is the atmospheric
pressure, while `pc` ($p_{cut-off}$) is the cut-off pressure. When $p'$
( the mean effective normal stress) is less than $p_{cut-off}$, then
$p'~=~p_{cut-off}$. $$E = E_o \left(\frac{p'}{p_{ref}}\right)^{n}
\label{NonLineEl011}$$

## Elastic Cross Anisotropic 3D command {#ECA3D}

    nDMaterial ElasticCrossAnisotropic matTag? Eh? Ev? nuhv? nuhh? Ghv?

The `ElasticCrossAnisotropic` material is the standard linear elastic
cross anisotropic three dimensional material implemented based on tensor
operation. The arguments to construct the material are its tag,
`matTag`, the elastic modulus in the cross plane, `Eh`, the elastic
modulus in the plane vertical to the cross plane, `Ev`, Poisson's ratio
between the cross plane and its vertical plane, `nuhv`, Poisson's ratio
between in the cross plane, `nuhh`, and the shear modulus between the
cross plane and its vertical plane, `Ghv`.
