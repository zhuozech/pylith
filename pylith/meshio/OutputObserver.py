# ----------------------------------------------------------------------
#
# Brad T. Aagaard, U.S. Geological Survey
# Charles A. Williams, GNS Science
# Matthew G. Knepley, University at Buffalo
#
# This code was developed as part of the Computational Infrastructure
# for Geodynamics (http://geodynamics.org).
#
# Copyright (c) 2010-2022 University of California, Davis
#
# See LICENSE.md for license information.
#
# ----------------------------------------------------------------------

from pylith.utils.PetscComponent import PetscComponent
from .meshio import OutputObserver as ModuleOutputObserver


class OutputObserver(PetscComponent, ModuleOutputObserver):
    """
    Abstract base class for managing output of solution information.
    """

    import pythia.pyre.inventory

    from .OutputTriggerStep import OutputTriggerStep
    trigger = pythia.pyre.inventory.facility("trigger", family="output_trigger", factory=OutputTriggerStep)
    trigger.meta['tip'] = "Trigger defining how often output is written."

    from .DataWriterHDF5 import DataWriterHDF5
    writer = pythia.pyre.inventory.facility("writer", factory=DataWriterHDF5, family="data_writer")
    writer.meta['tip'] = "Writer for data."

    outputBasisOrder = pythia.pyre.inventory.int("output_basis_order", default=1, validator=pythia.pyre.inventory.choice([0,1]))
    outputBasisOrder.meta['tip'] = "Basis order for output."

    def __init__(self, name="outputobserver"):
        """Constructor.
        """
        PetscComponent.__init__(self, name, facility="outputobserver")

    def preinitialize(self, problem):
        """Setup output manager.
        """
        self._createModuleObj()
        ModuleOutputObserver.setIdentifier(self, self.aliases[-1])

        self.trigger.preinitialize()
        ModuleOutputObserver.setTrigger(self, self.trigger)

        descriptor = self.getTraitDescriptor("output_basis_order")
        if hasattr(descriptor.locator, "source") and descriptor.locator.source == "default":
            outputBasisOrder = problem.defaults.outputBasisOrder
        else:
            outputBasisOrder = self.outputBasisOrder
        ModuleOutputObserver.setOutputBasisOrder(self, outputBasisOrder)

        self.writer.preinitialize()
        ModuleOutputObserver.setWriter(self, self.writer)

    def _configure(self):
        """Set members based using inventory.
        """
        PetscComponent._configure(self)

    def _createModuleObj(self):
        """Create handle to C++ object.
        """
        raise NotImplementedError("Implement in subclass.")


# End of file
