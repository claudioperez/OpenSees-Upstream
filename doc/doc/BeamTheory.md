::: {.center}
**Beam-Column Elements in OpenSees**

**August 22, 2001**

**Michael H. Scott**

**PEER, University of California, Berkeley**
:::

This document provides a brief description of the interaction between a
beam-column element and the SectionForceDeformation and
CoordTransformation classes in OpenSees. Material and geometric
nonlinearities are abstracted, or separated, from the element
formulation by using the SectionForceDeformation and CoordTransformation
classes. As a result, an element can be programmed in the "basic system"
to account for material nonlinearities, then use one of many
transformation types to pick up geometric nonlinearities. A displacement
based, distributed plasticity formulation is presented as an example of
how a beam-column element is formulated in the basic system.

# Geometric Nonlinearity

In general, the transformation of nodal displacements, **u**, in the
global system to deformations, **v**, in the basic system is described
by a nonlinear function,

$$\label{eq:v=v(u)}
{\bf v} = {\bf v}({\bf u}).$$

In a similar manner, the transformation of basic forces, **q**, to
forces **p** in the global frame of reference is given by

$$\label{eq:p=p(q,u)}
{\bf p} = {\bf p}({\bf q}({\bf u}), {\bf u}),$$

where **p** is implicitly a function of **u** via the basic forces,
**q**, as well as an explicit function of **u**. The explicit dependence
on **u** takes into account *approximate* geometric nonlinearities such
as P-$\Delta$. These transformations are shown schematically in
figure [\[fig:Transformation\]](#fig:Transformation){reference-type="ref"
reference="fig:Transformation"}.

::: {.center}
 
:::

As seen in
figure [\[fig:BeamClass\]](#fig:BeamClass){reference-type="ref"
reference="fig:BeamClass"}, a beam-column element acquires geometric
nonlinearity from the CoordTransformation class, and material
nonlinearity from the SectionForceDeformation class.

# Material Nonlinearity

At every cross-section along the element length, a force-deformation
relationship holds, providing section stress resultants, **s**, as a
function of section deformations, **e**,

$$\label{eq:s=s(e)}
{\bf s}(x) = {\bf s}({\bf e}(x)).$$

Linearizing the force-deformation relationship with respect to
deformations reveals the section tangent stiffness, ${\bf k}_s$,

$$\begin{aligned}
\Delta{\bf s} &= \frac{\partial{\bf s}}{\partial{\bf e}} \Delta{\bf e} \


\Delta{\bf s} &= {\bf k}_s \Delta{\bf e},\end{aligned}$$

where ${\bf k}_s = \frac{\partial{\bf s}}{\partial{\bf e}}$, the partial
derivative of the section stress resultants with respect to the section
deformations.

A beam-column element obtains material nonlinearity through use of the
SectionForceDeformation class, as seen in
figure [\[fig:BeamClass\]](#fig:BeamClass){reference-type="ref"
reference="fig:BeamClass"}.

# Class Hierarchy

Figure [\[fig:BeamClass\]](#fig:BeamClass){reference-type="ref"
reference="fig:BeamClass"} shows the class interaction between a
beam-column element and the CoordTransformation and
SectionForceDeformation classes. An element can use any one of Linear,
PDelta, or Corotational transformations; and any one of ElasticSection
or FiberSection constitutive models. When a new transformation or
section class is added to the framework, the element can use the new
class without modification.

::: {.center}
 
:::

# Displacement Based Element Formulation

This section describes the formulation of a displacement based,
distributed plasticity beam-column element. The governing compatibility
and equilibrium equations are covered along with the consistent element
stiffness. Bending deformations are assumed to be small, and shear
deformations are neglected.

## Compatibility

For displacement based elements, there is a strong form of compatibility
between basic displacements, **v**, and section deformations **e**,
satisfied pointwise along the element length,

$$\label{eq:e=av}
{\bf e}(x) =
\left[ \begin{array}{c} \varepsilon(x) \\ \kappa(x) \end{array} \right] =
{\bf a}(x) {\bf v},$$

where **a** is the strain-displacement matrix. The section deformations
are the axial strain, $\varepsilon$, and curvature, $\kappa$. Assuming
linear axial displacement and transverse displacement based on cubic
Hermitian polynomials, the shape functions in the basic system are

$$\label{eq:N}
{\bf N}(x) =
\left[ \begin{array}{c} N_1(x) \\ \\ N_2(x) \\ \\ N_3(x) \end{array} \right] =
\left[ \begin{array}{c} \frac{x}{L} \\ \


L\left( \frac{x}{L} - 2\frac{x^2}{L^2} + \frac{x^3}{L^3} \right) \\ \


L\left( -\frac{x^2}{L^2} + \frac{x^3}{L^3} \right)
\end{array}
\right].$$

The strain-displacement matrix contains the shape function derivatives.
Axial strain is the first derivative of the axial displacement, and
curvature is the second derivative of the transverse displacement,

$${\bf a}(x) = \left[ \begin{array}{ccc}
N_{1,x} & 0 & 0 \\ \


0 & N_{2,xx} & N_{3,xx}
\end{array}
\right].$$

Using the shape functions defined in
equation [\[eq:N\]](#eq:N){reference-type="ref" reference="eq:N"}, the
strain-displacement matrix is then,

$${\bf a}(x) = \frac{1}{L} \left[ \begin{array}{ccc}
1 & 0 & 0 \\ \


0 & -4+6\frac{x}{L} & -2+6\frac{x}{L}
\end{array}
\right].$$

The basic displacements, **v**, can be obtained by invoking the method
`getBasicTrialDisp()`. After computing section deformations from basic
displacements via equation [\[eq:e=av\]](#eq:e=av){reference-type="ref"
reference="eq:e=av"}, the method `setTrialSectionDeformation()` may be
invoked with the updated deformations, **e**.

## Equilibrium

Using the principle of virtual displacements (virtual work), equilibrium
between element end forces, **q**, and section stress resultants, **s**,
is satisfied weakly, or in an average sense, along the element length,

$$\label{eq:q}
{\bf q} = \int_0^L {\bf a}(x)^T {\bf s}(x) \: dx,$$

where the section stress resultants are the axial force, $P$, and
bending moment, $M$,

$${\bf s}(x) =
\left[ \begin{array}{c} P(x) \\ M(x) \end{array} \right].$$

To obtain the current value of section stress resultants, **s**, the
method `getStressResultant()` must be invoked. To perform the
transformation from basic to global resisting force
(equation [\[eq:p=p(q,u)\]](#eq:p=p(q,u)){reference-type="ref"
reference="eq:p=p(q,u)"}), the method `getGlobalResistingForce()` should
be invoked.

## Element Stiffness

To solve the structural system of equations, the element stiffness must
be assembled along with the resisting force. The element stiffness is
obtained by taking the partial derivative of
equation [\[eq:p=p(q,u)\]](#eq:p=p(q,u)){reference-type="ref"
reference="eq:p=p(q,u)"} with respect to displacements, **u**.

$$\begin{aligned}
{\bf k} &= \frac{\partial{\bf p}}{\partial{\bf q}}\frac{\partial{\bf q}}{\partial{\bf u}} + \left.\frac{\partial{\bf p}}{\partial{\bf u}}\right|_{\bf q} \


&= \frac{\partial{\bf p}}{\partial{\bf q}} \frac{\partial{\bf q}}{\partial{\bf v}} \frac{\partial{\bf v}}{\partial{\bf u}} +
\left.\frac{\partial{\bf p}}{\partial{\bf u}}\right|_{\bf q} \


{\bf k} &= \label{eq:stiff} \frac{\partial{\bf p}}{\partial{\bf q}} {\bf k}_b \frac{\partial{\bf v}}{\partial{\bf u}} +
\left.\frac{\partial{\bf p}}{\partial{\bf u}}\right|_{\bf q}\end{aligned}$$

The basic element stiffness, ${\bf k}_b$, is the partial derivative of
the basic forces, **q**, with respect to the basic displacements,
${\bf v}$. Differentiating
equation [\[eq:q\]](#eq:q){reference-type="ref" reference="eq:q"} gives,

$$\begin{aligned}
{\bf k}_b &= \frac{\partial{\bf q}}{\partial{\bf v}} \


&= \int_0^L {\bf a}(x)^T \frac{\partial{\bf s}}{\partial{\bf v}} \: dx \


&= \int_0^L {\bf a}(x)^T \frac{\partial{\bf s}}{\partial{\bf e}} \frac{\partial{\bf e}}{\partial{\bf v}} \: dx \


{\bf k}_b &= \label{eq:kb} \int_0^L {\bf a}(x)^T {\bf k}_s(x) {\bf a}(x) \: dx\end{aligned}$$

The section tangent stiffness matrix, ${\bf k}_s$, is returned upon
invoking the method `getSectionTangent()`. After computing the basic
stiffness, ${\bf k}_b$, the method `getGlobalStiffMatrix()` should be
invoked to perform the transformation in
equation [\[eq:stiff\]](#eq:stiff){reference-type="ref"
reference="eq:stiff"}. The remaining partial derivatives in
equation [\[eq:stiff\]](#eq:stiff){reference-type="ref"
reference="eq:stiff"} are computed by the `getGlobalStiffMatrix()`
method.

## Numerical Quadrature

In general, the element integrals,
equations [\[eq:q\]](#eq:q){reference-type="ref" reference="eq:q"}
and [\[eq:kb\]](#eq:kb){reference-type="ref" reference="eq:kb"}, cannot
be evaluated in closed form due to nonlinearities in the section
constitutive model. These integrals must be approximately evaluated by
numerical quadrature,

$$\begin{aligned}
\label{eq:qapprox} {\bf q} &\approx
\sum_{i=1}^{N_s} {\bf a}(x_i)^T {\bf s}(x_i) \: W_i \


\label{eq:kbapprox}{\bf k}_b &\approx
\sum_{i=1}^{N_s} {\bf a}(x_i)^T {\bf k}_s(x_i) {\bf a}(x_i) \: W_i ,\end{aligned}$$

where $N_s$ is the number of integration points, i.e., the number of
section sample points along the element length.

Integration points, $\xi_i$, and weights, $\omega_i$, are typically
defined over a fixed domain such as $\left[-1,1\right]$ or
$\left[0,1\right]$, then mapped to the element domain
$\left[0,L\right]$, where $L$ is the element length. Assuming points and
weights defined on $\left[-1,1\right]$, the following relationships
hold,

$$\begin{aligned}
x_i &= \frac{L}{2} \left( \xi_i+1 \right) \


W_i &= \frac{L}{2} \: \omega_i .\end{aligned}$$

After mapping the points and weights to the element domain,
equations [\[eq:qapprox\]](#eq:qapprox){reference-type="ref"
reference="eq:qapprox"}
and [\[eq:kbapprox\]](#eq:kbapprox){reference-type="ref"
reference="eq:kbapprox"} can be evaluated.
