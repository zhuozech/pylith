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

/**
 * @file unittests/libtests/materials/TestEffectiveStress.hh
 *
 * @brief C++ TestEffectiveStress object
 *
 * C++ unit testing for EffectiveStress.
 */

#if !defined(pylith_materials_testeffectivestress_hh)
#define pylith_materials_testeffectivestress_hh

#include <cppunit/extensions/HelperMacros.h>

/// Namespace for pylith package
namespace pylith {
  namespace materials {
    class TestEffectiveStress;
  } // materials
} // pylith

/// C++ unit testing for EffectiveStress
class pylith::materials::TestEffectiveStress : public CppUnit::TestFixture
{ // class TestEffectiveStress

  // CPPUNIT TEST SUITE /////////////////////////////////////////////////
  CPPUNIT_TEST_SUITE( TestEffectiveStress );

  CPPUNIT_TEST( testCalculateLinear );
  CPPUNIT_TEST( testCalculateCubic );

  CPPUNIT_TEST_SUITE_END();

  // PUBLIC METHODS /////////////////////////////////////////////////////
public :

  /// Test calculate() with linear function.
  void testCalculateLinear(void);

  /// Test calculate() with cubic function.
  void testCalculateCubic(void);

}; // class TestEffectiveStress

#endif // pylith_materials_testeffectivestress_hh

// End of file 
