#!/usr/bin/env python
#
# ----------------------------------------------------------------------
#
#                           Brad T. Aagaard
#                        U.S. Geological Survey
#
# <LicenseText>
#
# ----------------------------------------------------------------------
#

## @file unittests/libtests/feassemble/data/Quadrature2DQuadratic.py

## @brief Python application for generating C++ data files for testing
## C++ Quadrature2D object w/quadratic basis functions.

from QuadratureApp import QuadratureApp

import numpy

# ----------------------------------------------------------------------
def N0(p):
  return (1.0-p[0]-p[1])*(1-2.0*p[0]-2.0*p[1])

def N0p(p):
  return 4.0*p[0]+4.0*p[1]-3.0

def N0q(p):
  return 4.0*p[0]+4.0*p[1]-3.0

def N1(p):
  return p[0]*(2.0*p[0]-1.0)

def N1p(p):
  return 4.0*p[0]-1.0

def N1q(p):
  return 0.0

def N2(p):
  return p[1]*(2.0*p[1]-1.0)

def N2p(p):
  return 0.0

def N2q(p):
  return 4.0*p[1]-1.0

def N3(p):
  return 4.0*p[0]*(1.0-p[0]-p[1])

def N3p(p):
  return -8.0*p[0]-4.0*p[1]+4.0

def N3q(p):
  return -4.0*p[0]

def N4(p):
  return 4.0*p[0]*p[1]

def N4p(p):
  return 4.0*p[1]

def N4q(p):
  return 4.0*p[0]

def N5(p):
  return 4.0*p[1]*(1.0-p[0]-p[1])

def N5p(p):
  return -4.0*p[1]

def N5q(p):
  return -8.0*p[1]-4.0*p[0]+4.0

def verticesRef():
  return [ [0.0, 0.0],
           [1.0, 0.0],
           [0.0, 1.0],
           [0.5, 0.0],
           [0.0, 0.5],
           [0.5, 0.5] ]

# ----------------------------------------------------------------------

# Quadrature2DQuadratic class
class Quadrature2DQuadratic(QuadratureApp):
  """
  Python application for generating C++ data files for testing C++
  Quadrature2D object w/quadratic basis functions.
  """
  
  # PUBLIC METHODS /////////////////////////////////////////////////////

  def __init__(self, name="quadrature2dquadratic"):
    """
    Constructor.
    """
    QuadratureApp.__init__(self, name)
    
    self.numVertices = 6
    self.spaceDim = 2
    self.numCells = 1
    self.cellDim = 2
    self.numBasis = 6
    self.numQuadPts = 3
    
    self.quadPtsRef = numpy.array( [[2.0/3.0, 1.0/6.0],
                                    [1.0/6.0, 2.0/3.0],
                                    [1.0/6.0, 1.0/6.0]],
                                   dtype=numpy.float64)
    self.quadWts = numpy.array([1.0/6.0, 1.0/6.0, 1.0/6.0],
                               dtype=numpy.float64)
    self.vertices = numpy.array( [[-1.0, -1.0],
                                  [+1.0, +0.2],
                                  [-1.5, +0.5],
                                  [+0.0, -0.6],
                                  [+0.25, +0.35],
                                  [-1.25, -0.25]],
                                 dtype=numpy.float64)
    self.cells = numpy.array( [[0, 1, 2, 3, 4, 5]], dtype=numpy.int32)
    
    return


  def calculateBasisVert(self):
    """
    Calculate basis functions and their derivatives at vertices.
    """

    self.basisVert = numpy.zeros( (self.numBasis, self.numBasis),
                                  dtype=numpy.float64)
    self.basisDerivVert = numpy.zeros( (self.numBasis,
                                        self.numBasis, self.cellDim),
                                       dtype=numpy.float64)

    iVertex = 0
    for v in verticesRef():
      # Basis functions at vertices
      basis = numpy.array([N0(v), N1(v), N2(v), N3(v), N4(v), N5(v)],
                          dtype=numpy.float64)
      self.basisVert[iVertex] = basis.reshape( (self.numBasis,) )
      
      # Derivatives of basis functions at vertices
      deriv = numpy.array([[N0p(v), N0q(v)],
                           [N1p(v), N1q(v)],
                           [N2p(v), N2q(v)],
                           [N3p(v), N3q(v)],
                           [N4p(v), N4q(v)],
                           [N5p(v), N5q(v)]],
                          dtype=numpy.float64)      
      self.basisDerivVert[iVertex] = deriv.reshape((self.numBasis,
                                                    self.cellDim))
      
      iVertex += 1
    return
    

  def calculateBasisQuad(self):
    """
    Calculate basis functions and their derivatives at quadrature points.
    """

    self.basisQuad = numpy.zeros( (self.numQuadPts, self.numBasis),
                                  dtype=numpy.float64)
    self.basisDerivQuad = numpy.zeros( (self.numQuadPts,
                                        self.numBasis, self.cellDim),
                                       dtype=numpy.float64)

    iQuad = 0
    for q in self.quadPtsRef:
      # Basis functions at quadrature points
      basis = numpy.array([N0(q), N1(q), N2(q), N3(q), N4(q), N5(q)],
                          dtype=numpy.float64)
      self.basisQuad[iQuad] = basis.reshape( (self.numBasis,) )
      
      # Derivatives of basis functions at quadrature points
      deriv = numpy.array([[N0p(q), N0q(q)],
                           [N1p(q), N1q(q)],
                           [N2p(q), N2q(q)],
                           [N3p(q), N3q(q)],
                           [N4p(q), N4q(q)],
                           [N5p(q), N5q(q)]],
                          dtype=numpy.float64)      
      self.basisDerivQuad[iQuad] = deriv.reshape((self.numBasis, self.cellDim))
      
      iQuad += 1
    return
    

# MAIN /////////////////////////////////////////////////////////////////
if __name__ == "__main__":

  app = Quadrature2DQuadratic()
  app.run()


# End of file 
