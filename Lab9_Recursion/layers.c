#include "layers.h"

/* Material properties in SI units.
 * From https://www.nde-ed.org/EducationResources/CommunityCollege/Ultrasonics/cc_ut_index.htm
 */

/* The layers through which the signal will propagate.
 * Layer 0 is the acoustic transducer so thickness and alpha are irrelevant.
 * The final layer should have infinite thickness (e.g., 1.0 m is very thick in this example
 * You could make the last layer "air" if appropriate
 */

// Note that thickness and alpha are irrelevant for layer 0.  Only used for computing reverse reflection.
static const Layer layers[N_LAYERS] = {
  //  Name          Thickness Alpha   Density Velocity Impedance
  { "PZT Transducer", 0.0,    0.0,    7.6e3,  0.441e4, 31.30e8 },
  { "Aluminum",       0.001,  1.0e-9, 2.70e3, 0.632e4, 17.10e8 },
  { "Brass",          0.002,  1.0e-9, 8.56e3, 0.428e4, 36.70e8 },
  { "Steel (4340)",   1.000,  1.0e-9, 7.80e3, 0.585e4, 45.63e8 }
};

const Layer getLayer (const int layer) {
  return layers[layer];
}

    
