UNDER CONSTRUCTION

\
\#include $<\tilde{
}$/system_of_eqn/linearSOE/profileSPD/ProfileSPDLinSubstrSolver.h$>$\
\
class ProfileSPDLinSubstrSolver: public DomainSolver, public
ProfileSPDLinSubstrSolver\
\
MovableObject\
Solver\
LinearSOESolver\
DomainSolver\
ProfileSPDLinDirectSolver\
\
\
A ProfileSPDLinSubstrSolver object will perform the numerical
substructuring operations on a ProfileSPDLinSOE object. EXPAND.\
\
// Constructor\
\
\
// Destructor\
\
\
// Public Methods\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
Causes the condenser to form
$A_{ee}^* = A_{ee} -A_{ei} A_{ii}^{-1} A_{ie}$, where $A_{ii}$ is the
first *numInt* rows of the $A$ matrix. The original $A$ is changed as a
result. $A_{ee}^*$ is to be stored in $A_{ee}$.\
*int condenseRHS(int numInt);*\
Causes the condenser to form $B_e^* = B_e - A_{ei} A_{ii}^{-1} B_i$,
where $A_{ii}$ is the first *numInt* rows of $A$. The original $B$ is
changed as a result. $B_e^*$ is to be stored in $B_e$.\
*int computeCondensedMatVect(Vector &u, int numInt);*\
Causes the condenser to form $A_{ee} u$.\
*Matrix &getCondensedA(void);*\
Returns the contents of $A_{ee}$ as a matrix.\
*Vector &getCondensedRHS(void);*\
Returns the contents of $B_e$ as a Vector.\
*Vector &getCondensedMatVect(void);*\
Returns the contents of the last call to *computeCondensedMatVect()*.\
*int setComputedXext(const Vector &u);*\
Sets the computed value of the unknowns in $X_e$ corresponding to the
external equations to *u*. The number of external equations is given by
the size of vector $u$.\
*int solveXint(void);*\
To compute the internal equation numbers $X_i$ given the value set for
the external equations in the last call to *setComputedXext()*.\
