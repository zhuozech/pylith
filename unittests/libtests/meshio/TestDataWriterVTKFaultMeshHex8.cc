// -*- C++ -*-
//
// ----------------------------------------------------------------------
//
//                           Brad T. Aagaard
//                        U.S. Geological Survey
//
// {LicenseText}
//
// ----------------------------------------------------------------------
//

#include <portinfo>

#include "TestDataWriterVTKFaultMeshHex8.hh" // Implementation of class methods

#include "data/DataWriterVTKDataFaultMeshHex8.hh" // USES DataWriterVTKDataFaultMeshHex8

// ----------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( pylith::meshio::TestDataWriterVTKFaultMeshHex8 );

// ----------------------------------------------------------------------
// Setup testing data.
void
pylith::meshio::TestDataWriterVTKFaultMeshHex8::setUp(void)
{ // setUp
  TestDataWriterVTKFaultMesh::setUp();
  _data = new DataWriterVTKDataFaultMeshHex8;
  _dataMesh = new DataWriterVTKDataFaultMeshHex8;
  _initialize();
} // setUp


// End of file 
