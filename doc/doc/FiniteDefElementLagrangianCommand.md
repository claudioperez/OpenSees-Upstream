# Total Lagrangian Finite Deformation (TLFD) Twenty-Node Brick Element Commands 

    element TLFD20nBrick eleTag? nd01? nd02? ... nd20? bf1? bf2? bf3?

The TLFD20nBrick element is the the three dimensional element
implemented based on the tensor operation. The argument to construct the
element are its tag, `TLFD20nBrick`, element tag, `eleTag`, ordered
twenty nodes, `nd01` to `nd20`, and the body forces, `bf1`, `bf2`,
`bf3`. By default, $3 \times 3 \times 3$ integration points are used.
The valid material tags for this element are hyperelastic material (see
Tcl Commands for Hyperelastic Material Models) and hyperelasto-plastic
material (see Tcl Commands for Hyperelasto-Plastic Material Models).
