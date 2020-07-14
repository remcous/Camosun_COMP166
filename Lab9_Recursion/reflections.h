/*
 * Header file for reflection simulator that uses mutual recursion.
 *
 * Dale Shpak
 * March 28, 2017
 */

#ifndef REFLECTIONS_H
#define REFLECTIONS_H

//#define DEBUG
#ifdef DEBUG
#define DPRINT(...) printf(__VA_ARGS__)
#else
#define DPRINT(...) 
#endif
/*
 * Propagate a wave in the forward direction.
 *
 * @param currentTime The time that the wave enters this layer
 * @param intensity The intensity of the incident wave
 * @param stopTime The time that the simulation stops
 * @param toLayer The layer that this wave is entering
 * @param recursionDepth Depth of the function call stack (Informational only)
 */
void forward (double time, double intensity, const double stopTime, const int toLayer, const int nLayers, int recursionDepth);

/*
 * Propagate a wave in the reverse direction.
 *
 * @param currentTime The time that the wave enters this layer
 * @param intensity The intensity of the incident wave
 * @param stopTime The time that the simulation stops
 * @param toLayer The layer that this wave is entering
 * @param recursionDepth Depth of the function call stack (Informational only)
 */
void reverse (double time, double intensity, const double stopTime, const int toLayer, const int nLayers, int recursionDepth);


#endif
