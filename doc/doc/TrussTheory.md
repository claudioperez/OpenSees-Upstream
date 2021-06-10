::: {.center}
**The OpenSees Truss Element**

**August 22, 2001**

**Michael H. Scott**

**PEER, University of California, Berkeley**
:::

This document provides a brief description of the interaction between a
truss element and the UniaxialMaterial class in OpenSees. Material
nonlinearity is abstracted, or separated, from the element formulation
by using the UniaxialMaterial class.
Figure [\[fig:TrussClass\]](#fig:TrussClass){reference-type="ref"
reference="fig:TrussClass"} shows the class interaction between a truss
element and the UniaxialMaterial class. A truss element can use any one
of ElasticMaterial or HardeningMaterial models. When a new uniaxial
material class is added to the framework, the truss can use the new
class without modification.

::: {.center}
 
:::

The formulation of a linear geometry, material nonlinear truss element
is covered in the remainder of this document. First, the linear
transformation is described, followed by the truss element formulation.

# Geometric Transformation

A linear transformation of displacements and forces between the global
and basic frames of reference is assumed. The transformation of global
displacements,**u**, to a single axial displacement, $v_1$, is given by
the linear relation,

$$\label{eq:v=Tu}
{\bf v} = \left[ \begin{array}{c} v_1 \end{array} \right] = {\bf T}{\bf u}.$$

Based on force equilibrium, the transformation of axial force in the
basic system to global forces is also linear,

$$\label{eq:p=Tq}
{\bf p} = {\bf T}^T{\bf q} = {\bf T}^T \left[ \begin{array}{c} q_1 \end{array} \right].$$

The transformation between global and basic systems is shown
schematically in
figure [\[fig:TrussTransf\]](#fig:TrussTransf){reference-type="ref"
reference="fig:TrussTransf"}. The transformation matrix, **T**, is given
in terms of the element orientation, $\theta$, in the global system,

$${\bf T} = \left[ \begin{array}{cccc} -\cos\theta & -\sin\theta & \cos\theta & \sin\theta
\end{array} \right].$$

::: {.center}
 
:::

# Truss Element Formulation

This section describes the formulation of a displacement based truss
element. The governing compatibility and equilibrium equations are
covered along with the consistent element stiffness. Axial deformations
are assumed to be small.

## Compatibility

For the truss element, there is a strong form of compatibility between
basic displacements, **v**, and section deformations **e**, satisfied
pointwise along the element length,

$$\label{eq:e=av}
{\bf e}(x) =
\left[ \begin{array}{c} \varepsilon(x) \end{array} \right] =
{\bf a}(x) \: v_1,$$

where **a** is the strain-displacement matrix and $v_1$ is computed from
equation [\[eq:v=Tu\]](#eq:v=Tu){reference-type="ref"
reference="eq:v=Tu"}. There is one section deformation, the axial
strain, $\varepsilon$. Assuming linear axial displacement the shape
function in the basic system is

$$\label{eq:N}
{\bf N}(x) =
\left[ \begin{array}{c} N_1(x) \end{array} \right] =
\left[ \begin{array}{c} \frac{x}{L} \end{array}
\right].$$

The strain-displacement matrix contains the shape function derivative.
Axial strain is the first derivative of the axial displacement,

$${\bf a}(x) = \left[ \begin{array}{c}
N_{1,x} \end{array}
\right].$$

Using the shape function defined in
equation [\[eq:N\]](#eq:N){reference-type="ref" reference="eq:N"}, the
strain-displacement matrix is then,

$${\bf a}(x) = \left[ \begin{array}{c} \frac{1}{L}
\end{array}
\right].$$

Thus, the axial strain, $\varepsilon$, is constant along the element
length and equation [\[eq:e=av\]](#eq:e=av){reference-type="ref"
reference="eq:e=av"} reduces to

$$\varepsilon(x) = \frac{v_1}{L}.$$

After computing the axial strain, the method `setTrialStrain()` should
be invoked with the updated strain.

## Equilibrium

Using the principle of virtual displacements (virtual work), equilibrium
between element end force, **q**, and section stress resultant, **s**,
is satisfied weakly, or in an average sense, along the element length,

$$\label{eq:q}
{\bf q} =  \left[ \begin{array}{c} q_1 \end{array} \right] =
\int_0^L {\bf a}(x)^T {\bf s}(x) \: dx,$$

where the section stress resultant is the axial force, $P$. For the
truss element, the stress resultant is computed by integrating constant
material stress, $\sigma$, over the cross-section area, $A$,

$${\bf s}(x) =
\left[ \begin{array}{c} P(x) \end{array} \right] =
\left[ \begin{array}{c} \sigma A \end{array} \right],$$

where $\sigma$ is constant since the axial strain does not vary along
the element length. The integral in
equation [\[eq:q\]](#eq:q){reference-type="ref" reference="eq:q"}
reduces to

$$q_1 = \sigma A,$$

since ${\bf a}(x) = \frac{1}{L}$. To obtain the current value of
material stress, $\sigma$, the method `getStress()` must be invoked.
Then the truss force can be transformed to the global system via
equation [\[eq:p=Tq\]](#eq:p=Tq){reference-type="ref"
reference="eq:p=Tq"}, i.e.,

$${\bf p} = {\bf T}^T q_1.$$

## Element Stiffness

To solve the structural system of equations, the element stiffness must
be assembled along with the resisting force. The element stiffness is
obtained by taking the partial derivative of
equation [\[eq:p=Tq\]](#eq:p=Tq){reference-type="ref"
reference="eq:p=Tq"} with respect to displacements, **u**.

$$\begin{aligned}
{\bf k} &= \frac{\partial{\bf p}}{\partial{\bf u}}\


&= \frac{\partial{\bf p}}{\partial{\bf q}} \frac{\partial{\bf q}}{\partial{\bf v}} \frac{\partial{\bf v}}{\partial{\bf u}} \


{\bf k} &= \label{eq:k} {\bf T}^T {\bf k}_b {\bf T}\end{aligned}$$

The basic element stiffness, ${\bf k}_b$, is the partial derivative of
the basic forces, **q**, with respect to the basic displacements,
${\bf v}$. Differentiating
equation [\[eq:q\]](#eq:q){reference-type="ref" reference="eq:q"} gives,

$$\begin{aligned}
{\bf k}_b &= \frac{\partial{\bf q}}{\partial{\bf v}} \


&= \int_0^L {\bf a}(x)^T \frac{\partial{\bf s}}{\partial{\bf v}} \: dx \


&= \int_0^L {\bf a}(x)^T \frac{\partial{\bf s}}{\partial{\bf e}} \frac{\partial{\bf e}}{\partial{\bf v}} \: dx \


{\bf k}_b &= \int_0^L {\bf a}(x)^T {\bf k}_s(x) {\bf a}(x) \: dx \\\end{aligned}$$

Recalling that ${\bf a}(x) = \frac{1}{L}$, integration along the element
length gives,

$${\bf k}_b = \label{eq:kb} \frac{{\bf k}_s}{L},$$

for a prismatic element where ${\bf k}_s$ is constant.

The section tangent stiffness matrix can be manipulated further and put
in terms of the material tangent. Recalling that ${\bf s} = \sigma A$
and ${\bf e} = \varepsilon$,

$$\begin{aligned}
{\bf k}_s &= \frac{\partial{\bf s}}{\partial{\bf e}} \


&= \frac{\partial{\bf s}}{\partial{\varepsilon}}\frac{\partial{\varepsilon}}{\partial{\bf e}} \


&= \frac{\partial{\sigma}}{\partial{\varepsilon}} A \


{\bf k}_s &= \label{eq:ks} D_t A,\end{aligned}$$

where $D_t$ is the material tangent, which is returned upon invoking the
method `getTangent()`. Combining
equations [\[eq:k\]](#eq:k){reference-type="ref"
reference="eq:k"}, [\[eq:kb\]](#eq:kb){reference-type="ref"
reference="eq:kb"}, and [\[eq:ks\]](#eq:ks){reference-type="ref"
reference="eq:ks"}, the familiar truss stiffness equation is recovered,

$${\bf k} = {\bf T}^T \frac{D_t A}{L} {\bf T}.$$
