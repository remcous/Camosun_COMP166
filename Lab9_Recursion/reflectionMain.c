/*
 * Simulation that launches a pulse into a layered medium and uses
 * recursion to find the times/intensities for the reflections
 * that return to the surface.
 * Could be used for ultrasound or seismic.
 *
 * Dale Shpak
 * March 28, 2017
 */

#include <stdio.h>
#include "layers.h"
#include "reflections.h"

int main (int argc, char *argv[]) {
  // Since layer 0 is the transducer, the wave is entering layer 1.
  forward(0.0, 1.0, 1.3e-6, 1, N_LAYERS, 0);
}
