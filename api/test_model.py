## ################################################################## ##
#|    OpenSees - Open System for Earthquake Engineering Simulation    |#
#|          Pacific Earthquake Engineering Research Center            |#
#|                                                                    |#
#|                                                                    |#
#| (C) Copyright 1999, The Regents of the University of California    |#
#| All Rights Reserved.                                               |#
#|                                                                    |#
#| Commercial use of this program without express permission of the   |#
#| University of California, Berkeley, is strictly prohibited.  See   |#
#| file 'COPYRIGHT'  in main directory for information on usage and   |#
#| redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           |#
#|                                                                    |#
#| Developed by:                                                      |#
#|   Frank McKenna (fmckenna@ce.berkeley.edu)                         |#
#|   Gregory L. Fenves (fenves@ce.berkeley.edu)                       |#
#|   Filip C. Filippou (filippou@ce.berkeley.edu)                     |#
#|                                                                    |#
## ################################################################## */
                                                                        
## $Date: 2009-11-02 22:23:58 $
## $Source: /usr/local/cvs/OpenSees/EXAMPLES/Example1/main.cpp,v $


## File: ~/model/main.C
##
## Written: fmk 08/99
"""
Purpose: this file contains a Python main procedure to perform the analysis
of example1 (found in most documents). In the `main()` procedure:

1. each object of the domain, i.e. Nodes, Elements, Constraints,
   and LoadPattern objects are created and then added to the Domain.
2. the components of the analysis object are constructed and then
   the Analysis object is created.
3. the analysis is performed.
4. the results are printed - here the contents of Domain and end of
   the analysis operation.
"""

import pyg3


def main(argc:int, argv:list)->int:
    ##  create a domain and a modelbuilder
    ##  and build the model
    theDomain = pyg3.domain.Domain()
    print(theDomain)
    
    ## create the nodes using constructor: 
    ##        Node(tag, ndof, crd1, crd2)
    ## and then add them to the domain
    node1 = pyg3.domain.Node(1, 2,   0.0,  0.0)
    node2 = pyg3.domain.Node(2, 2, 144.0,  0.0)
    node3 = pyg3.domain.Node(3, 2, 168.0,  0.0)    
    node4 = pyg3.domain.Node(4, 2,  72.0, 96.0)        
    theDomain.addNode(node1)
    theDomain.addNode(node2)
    theDomain.addNode(node3)
    theDomain.addNode(node4)
    
    # create an elastic material using constriuctor:  
    #    ElasticMaterialModel(tag, E)
    #-- theMaterial = pyg3.ElasticMaterial(1, 3000)
    
    ## create the truss elements using constructor:
    ##        Truss(tag, dim, nd1, nd2, Material &,A)
    ## and then add them to the domain
    
    #-- Truss *truss1 = pyg3.Truss(1, 2, 1, 4, *theMaterial, 10.0)
    #-- Truss *truss2 = pyg3.Truss(2, 2, 2, 4, *theMaterial,  5.0)    
    #-- Truss *truss3 = pyg3.Truss(3, 2, 3, 4, *theMaterial,  5.0)        
    #-- theDomain.addElement(truss1)
    #-- theDomain.addElement(truss2)
    #-- theDomain.addElement(truss3)    
    
    # create the single-point constraint objects using constructor:
    #   SP_Constraint(tag, nodeTag, dofID, value)
    # and then add them to the domain
    
    sp1 = pyg3.domain.SP_Constraint(1, 1, 0, 0.0)
    sp2 = pyg3.domain.SP_Constraint(2, 1, 1, 0.0)    
    sp3 = pyg3.domain.SP_Constraint(3, 2, 0, 0.0)
    sp4 = pyg3.domain.SP_Constraint(4, 2, 1, 0.0)    
    sp5 = pyg3.domain.SP_Constraint(5, 3, 0, 0.0)
    sp6 = pyg3.domain.SP_Constraint(6, 3, 1, 0.0)        
    theDomain.addSP_Constraint(sp1)
    theDomain.addSP_Constraint(sp2)
    theDomain.addSP_Constraint(sp3)
    theDomain.addSP_Constraint(sp4)    
    theDomain.addSP_Constraint(sp5)    
    theDomain.addSP_Constraint(sp6)    

    # construct a linear time series object using constructor:
    #   LinearSeries()
    
    theSeries = pyg3.domain.LinearSeries()
    print(theSeries)
    
    # construct a load pattren using constructor:
    #     LoadPattern(tag)
    # and then set it's TimeSeries and add it to the domain
    
    theLoadPattern = pyg3.domain.LoadPattern(1)
    print(theLoadPattern)
    theLoadPattern.setTimeSeries(theSeries)
    theDomain.addLoadPattern(theLoadPattern)
    print(theDomain)
    
    # construct a nodal load using constructor:
    #        NodalLoad(tag, nodeID, Vector &)
    # first construct a Vector of size 2 and set the values
    # then construct the load and add it to the domain
    
    theLoadValues = pyg3.Vector([100, -50])
#    theLoadValues(0) = 100.0
#    theLoadValues(1) = -50.0
    theLoad = pyg3.domain.NodalLoad(1, 4, theLoadValues)
    #theLoad = pyg3.domain.NodalLoad(1, 4, [100, -50])
    print(theLoad)
    theDomain.addNodalLoad(theLoad, 1)

    # create an Analysis object to perform a static analysis of the model
    #  - constructs:
    #    AnalysisModel of type AnalysisModel,
    #      EquiSolnAlgo of type Linear
    #      StaticIntegrator of type LoadControl
    #      ConstraintHandler of type Penalty
    #    DOF_Numberer which uses RCM
    #    LinearSOE of type Band SPD
    # and then the StaticAnalysis object    
    theModel      = pyg3.analysis.AnalysisModel()
    print(theModel)
    theSolnAlgo   = pyg3.analysis.Linear()
    print(theSolnAlgo)
    theIntegrator = pyg3.analysis.LoadControl(1.0, 1, 1.0, 1.0)
    theHandler    = pyg3.analysis.PenaltyConstraintHandler(1.0e8,1.0e8)
    theRCM        = pyg3.graph.RCM()
    print(theRCM)
    theNumberer   = pyg3.analysis.DOF_Numberer(theRCM)
    print(theNumberer)
    theSolver     = pyg3.sys_of_eqn.BandSPDLinLapackSolver()
    print(theSolver)
    theSOE        = pyg3.sys_of_eqn.BandSPDLinSOE(theSolver)

    theAnalysis   = pyg3.analysis.StaticAnalysis(theDomain,
                         theHandler,
                         theNumberer,
                         theModel,
                         theSolnAlgo,
                         theSOE,
                         theIntegrator
                   )
    print(theAnalysis)

    # perform the analysis & print out the results for the domain
    numSteps = 1
    theAnalysis.analyze(numSteps)
    print("Analysis complete")
#    return 0
 
main(0,0)

