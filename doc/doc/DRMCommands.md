# OpenSees Command for the Domain Reduction Method

The syntax of the DRM command is :

`pattern PBowlLoading` loadpattrnTag? `-pbele` PBElmentFile? `-acce`
acceFile? `-disp` dispFile? `-dt` dt? $<$`-factor` factor?$>$ `-xp` +X?
`-xm` -X? `-yp` -Y? `-ym` -Y? `-zp` +Z? `-zm` -Z?\
where pattern and PBowlLoading are key words. loadpattrnTag? is the tag
for this loadPattern. A user needs to supply an element file,
acceleration file, displacement file following the identifiers `-pbele`,
`-acce` and `-disp`, respectively. dt? is the time increment in the
input data and is a parameter following identifier `-dt`. factor? is an
optional parameter for scaling the equivalent forces. If not supplied, a
default value 1.0 will be used. In particular, the interior boundary of
the boundary layer is input by a set of coordinates, i.e. +X, -X, +Y,
-Y, +Z and -Z, as shown in Figure
[1](#PBDefinition){reference-type="ref" reference="PBDefinition"}.

::: {.center}
![[\[PBDefinition\]]{#PBDefinition label="PBDefinition"} Sketch showing
coordinates of the interior
boundary.](/home/jeremic/tex/works/Thesis/JinxiuLiao/newthesis/figures/PB_Command.eps){#PBDefinition
width="8.5cm" style="margin:auto; display: block; max-width: 75%"}
:::
