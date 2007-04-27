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

## @file unittests/libtests/feassemble/data/Quadrature3DLinear.py

## @brief Python application for generating C++ data files for testing
## C++ Quadrature3D object w/linear basis functions.

from QuadratureApp import QuadratureApp

import numpy

# ----------------------------------------------------------------------
def N0(p):
  return 1.0-p[0]-p[1]-p[2]

def N0p(p):
  return -1.0

def N0q(p):
  return -1.0

def N0r(p):
  return -1.0

def N1(p):
  return p[0]

def N1p(p):
  return 1.0

def N1q(p):
  return 0.0

def N1r(p):
  return 0.0

def N2(p):
  return p[1]

def N2p(p):
  return 0.0

def N2q(p):
  return 1.0

def N2r(p):
  return 0.0

def N3(p):
  return p[2]

def N3p(p):
  return 0.0

def N3q(p):
  return 0.0

def N3r(p):
  return 1.0

def verticesRef():
  return [ [0.0, 0.0, 0.0],
           [1.0, 0.0, 0.0],
           [0.0, 1.0, 0.0],
           [0.0, 0.0, 1.0] ]


# ----------------------------------------------------------------------

# Quadrature3DLinear class
class Quadrature3DLinear(QuadratureApp):
  """
  Python application for generating C++ data files for testing C++
  Quadrature3D object w/linear basis functions.
  """
  
  # PUBLIC METHODS /////////////////////////////////////////////////////
  
  def __init__(self, name="quadrature1dlinear"):
    """
    Constructor.
    """
    QuadratureApp.__init__(self, name)
    
    self.numVertices = 4
    self.spaceDim = 3
    self.numCells = 1
    self.cellDim = 3
    self.numBasis = 4
    self.numQuadPts = 1
    
    self.quadPtsRef = numpy.array( [[1.0/4.0, 1.0/4.0, 1.0/4.0]],
                                   dtype=numpy.float64)
    self.quadWts = numpy.array([1.0/6.0], dtype=numpy.float64)
    self.vertices = numpy.array( [[-0.5, -1.0, -0.5],
                                  [ 2.0, -0.5, -0.4],
                                  [ 1.0, -0.1, -0.3],
                                  [-0.2,  0.5,  2.0]], dtype=numpy.float64)
    self.cells = numpy.array( [[0, 1, 2, 3]], dtype=numpy.int32)
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
      basis = numpy.array([N0(v), N1(v), N2(v), N3(v)], dtype=numpy.float64)
      self.basisVert[iVertex] = basis.reshape( (self.numBasis,) )

      # Derivatives of basis functions at vertices
      deriv = numpy.array([[N0p(v), N0q(v), N0r(v)],
                           [N1p(v), N1q(v), N1r(v)],
                           [N2p(v), N2q(v), N2r(v)],
                           [N3p(v), N3q(v), N3r(v)]],
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
      basis = numpy.array([N0(q), N1(q), N2(q), N3(q)], dtype=numpy.float64)
      self.basisQuad[iQuad] = basis.reshape( (self.numBasis,) )

      # Derivatives of basis functions at quadrature points
      deriv = numpy.array([[N0p(q), N0q(q), N0r(q)],
                           [N1p(q), N1q(q), N1r(q)],
                           [N2p(q), N2q(q), N2r(q)],
                           [N3p(q), N3q(q), N3r(q)]],
                          dtype=numpy.float64)      
      self.basisDerivQuad[iQuad] = deriv.reshape((self.numBasis, self.cellDim))

      iQuad += 1
    return
    

# MAIN /////////////////////////////////////////////////////////////////
if __name__ == "__main__":

  app = Quadrature3DLinear()
  app.run()


# End of file 
