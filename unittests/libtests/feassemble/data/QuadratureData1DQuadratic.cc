// -*- C++ -*-
//
// ======================================================================
//
//                           Brad T. Aagaard
//                        U.S. Geological Survey
//
// {LicenseText}
//
// ======================================================================
//

// DO NOT EDIT THIS FILE
// This file was generated from python application quadrature1dquadratic.

#include "QuadratureData1DQuadratic.hh"

const int pylith::feassemble::QuadratureData1DQuadratic::_numVertices = 3;

const int pylith::feassemble::QuadratureData1DQuadratic::_spaceDim = 1;

const int pylith::feassemble::QuadratureData1DQuadratic::_numCells = 1;

const int pylith::feassemble::QuadratureData1DQuadratic::_cellDim = 1;

const int pylith::feassemble::QuadratureData1DQuadratic::_numBasis = 3;

const int pylith::feassemble::QuadratureData1DQuadratic::_numQuadPts = 2;

const double pylith::feassemble::QuadratureData1DQuadratic::_vertices[] = {
 -2.50000000e-01,
  8.75000000e-01,
  2.00000000e+00,
};

const int pylith::feassemble::QuadratureData1DQuadratic::_cells[] = {
       0,       1,       2,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_quadPtsRef[] = {
 -5.77350269e-01,
  5.77350269e-01,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_quadWts[] = {
  1.00000000e+00,  1.00000000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_quadPts[] = {
  2.25480947e-01,
  1.52451905e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_basisVert[] = {
  1.00000000e+00,
  0.00000000e+00,
 -0.00000000e+00,
 -0.00000000e+00,
  1.00000000e+00,
  0.00000000e+00,
 -0.00000000e+00,
  0.00000000e+00,
  1.00000000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_basisDerivVert[] = {
 -1.50000000e+00,
  2.00000000e+00,
 -5.00000000e-01,
 -5.00000000e-01,
 -0.00000000e+00,
  5.00000000e-01,
  5.00000000e-01,
 -2.00000000e+00,
  1.50000000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_jacobianVert[] = {
  1.12500000e+00,
  1.12500000e+00,
  1.12500000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_jacobianDetVert[] = {
  1.12500000e+00,  1.12500000e+00,  1.12500000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_basisQuad[] = {
  4.55341801e-01,
  6.66666667e-01,
 -1.22008468e-01,
 -1.22008468e-01,
  6.66666667e-01,
  4.55341801e-01,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_basisDerivQuad[] = {
 -1.07735027e+00,
  1.15470054e+00,
 -7.73502692e-02,
  7.73502692e-02,
 -1.15470054e+00,
  1.07735027e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_jacobianQuad[] = {
  1.12500000e+00,
  1.12500000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_jacobianDetQuad[] = {
  1.12500000e+00,  1.12500000e+00,
};

const double pylith::feassemble::QuadratureData1DQuadratic::_jacobianInvQuad[] = {
  8.88888889e-01,
  8.88888889e-01,
};

pylith::feassemble::QuadratureData1DQuadratic::QuadratureData1DQuadratic(void)
{ // constructor
  numVertices = _numVertices;
  spaceDim = _spaceDim;
  numCells = _numCells;
  cellDim = _cellDim;
  numBasis = _numBasis;
  numQuadPts = _numQuadPts;
  vertices = const_cast<double*>(_vertices);
  cells = const_cast<int*>(_cells);
  quadPtsRef = const_cast<double*>(_quadPtsRef);
  quadWts = const_cast<double*>(_quadWts);
  quadPts = const_cast<double*>(_quadPts);
  basisVert = const_cast<double*>(_basisVert);
  basisDerivVert = const_cast<double*>(_basisDerivVert);
  jacobianVert = const_cast<double*>(_jacobianVert);
  jacobianDetVert = const_cast<double*>(_jacobianDetVert);
  basisQuad = const_cast<double*>(_basisQuad);
  basisDerivQuad = const_cast<double*>(_basisDerivQuad);
  jacobianQuad = const_cast<double*>(_jacobianQuad);
  jacobianDetQuad = const_cast<double*>(_jacobianDetQuad);
  jacobianInvQuad = const_cast<double*>(_jacobianInvQuad);
} // constructor

pylith::feassemble::QuadratureData1DQuadratic::~QuadratureData1DQuadratic(void)
{}


// End of file
