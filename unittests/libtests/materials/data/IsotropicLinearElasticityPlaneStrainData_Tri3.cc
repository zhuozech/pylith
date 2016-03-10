// -*- C++ -*-
//
// ======================================================================
//
// Brad T. Aagaard, U.S. Geological Survey
// Charles A. Williams, GNS Science
// Matthew G. Knepley, University of Chicago
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010-2015 University of California, Davis
//
// See COPYING for license information.
//
// ======================================================================
//

#include "IsotropicLinearElasticityPlaneStrainData_Tri3.hh"

extern "C" {
#include "pylith/fekernels/dispvel.h" // USES DispVel kernels
#include "pylith/fekernels/elasticity.h" // USES Elasticity kernels
#include "pylith/fekernels/linearelasticityplanestrain.h" // USES IsotropicLinearElasticityPlaneStrain kernels
}

const char* pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_meshFilename = "data/tri3_small.mesh";
const char* pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_materialLabel = "IsotropicLinearElascitity";
const int pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_materialId = 24;
const char* pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_boundaryLabel = "boundary";

const PylithReal pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_lengthScale =   1.00000000e+03;
const PylithReal pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_timeScale =   2.00000000e+00;
const PylithReal pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_densityScale =   9.00000000e+04;
const PylithReal pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_pressureScale =   2.25000000e+10;

const PylithReal pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_t = 1.0;
const PylithReal pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_dt = 0.01;

const pylith::topology::Field::DiscretizeInfo pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_solnDiscretizations[2] = {
  {1, 1, true}, // displacement
  {1, 1, true}, // velocity
};

const int pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_numAuxFields = 3;
const char* pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_auxFields[3] = {
  "density", "mu", "lambda",
};
const pylith::topology::Field::DiscretizeInfo pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_auxDiscretizations[3] = {
  {0, 1, true}, // density
  {0, 1, true}, // mu
  {0, 1, true}, // lambda
};

const int pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_dimension = 2;
const int pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_numSolnFields = 1;

const PetscPointFunc pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_kernelsRHSResidual[2*2] =
  {
    // displacement
    NULL,
    pylith_fekernels_IsotropicLinearElasticityPlaneStrain_g1,
    // velocity
    pylith_fekernels_DispVel_g0,
    NULL,
  };

const PetscPointJac pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_kernelsRHSJacobian[2*2*4] = 
  {
    // disp/disp
    NULL,
    NULL,
    NULL,
    pylith_fekernels_IsotropicLinearElasticityPlaneStrain_Jg3_uu,
    // disp/vel
    NULL,
    NULL,
    NULL,
    NULL,
    // vel/disp
    NULL,
    NULL,
    NULL,
    NULL,
    // vel/vel
    pylith_fekernels_DispVel_Jg0_vv,
    NULL,
    NULL,
    NULL,
};

const PetscPointFunc pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_kernelsLHSResidual[2*2] = 
  {
    // displacement
    NULL,
    NULL,
    // velocity
    pylith_fekernels_DispVel_f0,
    NULL,
  };

const PetscPointJac pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_kernelsLHSJacobianImplicit[2*2*4] = 
  {
    // disp/disp
    NULL,
    NULL,
    NULL,
    NULL,
    // disp/vel
    NULL,
    NULL,
    NULL,
    NULL,
    // vel/disp
    pylith_fekernels_DispVel_Jf0_vu_implicit,
    NULL,
    NULL,
    NULL,
    // vel/vel
    NULL,
    NULL,
    NULL,
    NULL,
  };
const PetscPointJac pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_kernelsLHSJacobianExplicit[2*2*4] = 
  {
    // disp/disp
    NULL,
    NULL,
    NULL,
    NULL,
    // disp/vel
    NULL,
    NULL,
    NULL,
    NULL,
    // vel/disp
    pylith_fekernels_DispVel_Jf0_vu_explicit,
    NULL,
    NULL,
    NULL,
    // vel/vel
    NULL,
    NULL,
    NULL,
    NULL,
  };

const char* pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_filenameAuxFieldsDB = "data/isotropiclinearelasticityplanestrain_tri3.spatialdb";

const bool pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_useInertia = false;
const bool pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::_useBodyForce = false;



pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::IsotropicLinearElasticityPlaneStrainData_Tri3(void)
{ // constructor
  meshFilename = const_cast<char*>(_meshFilename);
  materialLabel = const_cast<char*>(_materialLabel);
  materialId = _materialId;

  lengthScale = _lengthScale;
  timeScale = _timeScale;
  densityScale = _densityScale;
  pressureScale = _pressureScale;

  t = _t;
  dt = _dt;
  
  solnDiscretizations = const_cast<pylith::topology::Field::DiscretizeInfo*>(_solnDiscretizations);

  numAuxFields = _numAuxFields;
  auxFields = const_cast<char**>(_auxFields);
  auxDiscretizations = const_cast<pylith::topology::Field::DiscretizeInfo*>(_auxDiscretizations);
  filenameAuxFieldsDB = const_cast<char*>(_filenameAuxFieldsDB);

  dimension = _dimension;
  numSolnFields = _numSolnFields;

  kernelsRHSResidual = const_cast<PetscPointFunc*>(_kernelsRHSResidual);
  kernelsRHSJacobian = const_cast<PetscPointJac*>(_kernelsRHSJacobian);
  kernelsLHSResidual = const_cast<PetscPointFunc*>( _kernelsLHSResidual);
  kernelsLHSJacobianImplicit = const_cast<PetscPointJac*>(_kernelsLHSJacobianImplicit);
  kernelsLHSJacobianExplicit = const_cast<PetscPointJac*>( _kernelsLHSJacobianExplicit);

  useInertia = _useInertia;
  useBodyForce = _useBodyForce;

} // constructor

pylith::materials::IsotropicLinearElasticityPlaneStrainData_Tri3::~IsotropicLinearElasticityPlaneStrainData_Tri3(void)
{}



// End of file
