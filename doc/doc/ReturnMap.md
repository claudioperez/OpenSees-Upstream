::: {.center}
**Uniaxial Return Mapping Algorithm**

**August 21, 2001**

**Michael H. Scott**

**PEER, University of California, Berkeley**
:::

This document outlines the return mapping algorithm for a
rate-independent uniaxial material model with combined isotropic and
kinematic hardening. The algorithm and its derivation are given in Simo
and Hughes [@Simo:1998].

The material parameters are the elastic modulus, $E$, yield stress,
$\sigma_y$, isotropic hardening modulus, $H_{iso}$, and kinematic
hardening modulus, $H_{kin}$. Path dependence is tracked by the plastic
strain, $\varepsilon^p$, internal hardening variable, $\alpha$, and back
stress, $\kappa$.

# Model Description {#model-description .unnumbered}

The model assumes an elastic stress-strain relationship with elastic
modulus $E$. The onset of plastic flow occurs upon yielding, after which
the elastoplastic tangent is given by
$\frac{E(H_{iso}+H_{kin})}{E+H_{iso}+H_{kin}}$, as shown in
figure [\[fig:StressStrain\]](#fig:StressStrain){reference-type="ref"
reference="fig:StressStrain"}.

::: {.center}
:::

Isotropic hardening can be thought of as an "expansion" of the elastic
region. The internal hardening variable, $\alpha$, tracks the growth of
the elastic region. Kinematic hardening corresponds to a "translation"
of the elastic region. The back stress, $\kappa$, is the center of the
elastic region. When there is no kinematic hardening, $\kappa$ is zero.
These two hardening rules are shown in
figure [\[fig:HardeningBehavior\]](#fig:HardeningBehavior){reference-type="ref"
reference="fig:HardeningBehavior"}, and they can be combined to give
mixed hardening behavior.

::: {.center}
:::

# Continuum Equations {#continuum-equations .unnumbered}

1.  Elastic stress-strain relationship
    $$\sigma = E \left( \varepsilon-\varepsilon^p \right)$$

2.  Flow rule
    $$\dot{\varepsilon}^p = \gamma \mbox{sign}\left( \sigma-\kappa \right)$$

3.  Isotropic and kinematic hardening laws $$\begin{aligned}
    \dot{\alpha} &= \gamma \\
    \dot{\kappa} &= \gamma H_{kin} \mbox{sign}\left( \sigma-\kappa \right)\end{aligned}$$

4.  Yield condition
    $$f(\sigma, \kappa, \alpha) = \left| \sigma-\kappa \right| -
    \left( \sigma_y + H_{iso}\alpha \right) \leq 0$$

5.  Kuhn-Tucker complementary conditions $$\begin{aligned}
    \gamma &\geq 0 \\
    f(\sigma, \kappa, \alpha) &\leq 0 \\
    \gamma f(\sigma, \kappa, \alpha) &= 0\end{aligned}$$

6.  Consistency condition
    $$\gamma \dot{f}(\sigma, \kappa, \alpha) = 0 \:\:\:\:\:
    \mbox{(if $f(\sigma, \kappa, \alpha)$ = 0)}$$

# Return Mapping Algorithm {#return-mapping-algorithm .unnumbered}

1.  Committed state at time $t_n$
    $$\left\{ \varepsilon_n^p, \alpha_n, \kappa_n \right\}$$

2.  Given trial strain at time $t_{n+1}$,
    $$\varepsilon_{n+1} = \varepsilon_n + \Delta\varepsilon_n,$$

    determine the corresponding stress, $\sigma_{n+1}$, and tangent,
    $D_{n+1}$; proceed to step 3.

3.  Compute trial stress and test for plastic loading $$\begin{aligned}
    \sigma_{n+1}^{trial} &= E \left( \varepsilon_{n+1} - \varepsilon_n^p \right) \\
    \xi_{n+1}^{trial} &= \sigma_{n+1}^{trial} - \kappa_n \\
    f_{n+1}^{trial} &= \left| \xi_{n+1}^{trial} \right| -
                      \left( \sigma_y + H_{iso}\alpha_n \right)\end{aligned}$$

    ::: {.center}
    If $f_{n+1} \leq 0$, this is an elastic step; set
    $\sigma_{n+1} = \sigma_{n+1}^{trial}, D_{n+1} = E$, and exit.\
    Else, this is a plastic step; proceed to step 4.
    :::

4.  Return mapping $$\begin{aligned}
    \Delta\gamma &= \frac{f_{n+1}^{trial}}{E+H_{iso}+H_{kin}} \\
    \sigma_{n+1} &= \sigma_{n+1}^{trial} - \Delta\gamma E \mbox{sign}(\xi_{n+1}^{trial}) \\
    \varepsilon_{n+1}^p &= \varepsilon_n^p + \Delta\gamma \mbox{sign}(\xi_{n+1}^{trial}) \\
    \kappa_{n+1} &= \kappa_n + \Delta\gamma H_{kin} \mbox{sign}(\xi_{n+1}^{trial}) \\
    \alpha_{n+1} &= \alpha_n + \Delta\gamma \\
    D_{n+1} &= \frac{E(H_{iso}+H_{kin})}{E+H_{iso}+H_{kin}}\end{aligned}$$

::: {.thebibliography}
99 J.C. Simo and T.J.R. Hughes, *Computational Inelasticity*.
Springer-Verlag, 1998.
:::
