/*
 * Function implementations for reflection simulator that uses mutual recursion.
 *
 * Remi Coussement
 * March 28, 2017
 */

#include <stdio.h>
#include <math.h>
#include "reflections.h"
#include "layers.h"

/*
 * Propagate a wave in the forward direction.
 *
 * @param currentTime The currentTime that the wave enters this layer
 * @param intensity The intensity of the incident wave
 * @param stopTime The currentTime that the simulation stops
 * @param toLayer The layer that this wave is entering
 * @param recursionDepth Depth of the function call stack (Informational only)
 */
void forward (double currentTime, double intensity, const double stopTime, const int toLayer, const int nLayers, int recursionDepth) {
  static int instances = 0;
  ++instances;
  int thisLayer = toLayer;
  DPRINT("Forward entering layer %2d at t=%12.5e I=%12.5e recursion:depth=%3d,instances=%3d\n", toLayer, currentTime, intensity, recursionDepth, instances);
  if (currentTime > stopTime) {
    DPRINT("Forward wave is too late. Terminated.\n");
    --instances;
    return;
  }
  if (thisLayer >= nLayers-1) {
    DPRINT("Forward wave passed all of the way through. Terminated.\n");
    --instances;
    return;
  }

  Layer m1 = getLayer(thisLayer);
  Layer m2 = getLayer(thisLayer+1);

  // Propagate in the forward direction through this layer
  currentTime = currentTime + m1.thickness / m1.velocity;;
  intensity = intensity * exp(-m1.alpha * m1.thickness);

  // Reflection and transmission when we reach the next interface
  double r = (m1.z -m2.z) / (m1.z + m2.z);
  double t = sqrt(1.0 - r*r);

  // Wave splits and propogates
  ++recursionDepth;
  reverse (currentTime, intensity*r, stopTime, thisLayer, nLayers, recursionDepth);
  forward (currentTime, intensity*t, stopTime, thisLayer+1, nLayers, recursionDepth);

  DPRINT("Completed a forward.\n");
  --instances;
}

void reverse (double currentTime, double intensity, const double stopTime, const int toLayer, const int nLayers, int recursionDepth){
  static int instances = 0;
  ++instances;
  int thisLayer = toLayer;
  DPRINT("Reverse entering layer %2d at t=%12.5e I=%12.5e recursion:depth=%3d,instances=%3d\n", toLayer, currentTime, intensity, recursionDepth, instances);

  // exits the current recursive instance if the time limit is exceeded
  if (currentTime > stopTime) {
    DPRINT("Reverse wave is too late. Terminated.\n");
    --instances;
    return;
  }

  // prints the echo time and intensity to the console in the event that the wave is in layer 0
  if (thisLayer == 0) {
    DPRINT("Echo at %12.5e seconds. Intensity = %12.5e.\n", currentTime, intensity);
    --instances;
    return;
  }

  Layer m1 = getLayer(thisLayer);
  Layer m2 = getLayer(thisLayer-1);

  // Propagate in the reverse direction through this layer
  currentTime = currentTime + m1.thickness / m1.velocity;;
  intensity = intensity * exp(-m1.alpha * m1.thickness);

  // Reflection and transmission when we reach the next interface
  double r = (m1.z -m2.z) / (m1.z + m2.z);
  double t = sqrt(1.0 - r*r);

  // Wave splits and propogates
  ++recursionDepth;
  reverse (currentTime, intensity*t, stopTime, thisLayer-1, nLayers, recursionDepth);
  forward (currentTime, intensity*r, stopTime, thisLayer, nLayers, recursionDepth);

  DPRINT("Completed a reverse.\n");
  --instances;
}