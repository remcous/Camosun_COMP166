#ifndef LAYERS_H
#define LAYERS_H

#define N_LAYERS 4

typedef struct {
  char *name;
  double thickness;
  double alpha;
  double density;
  double velocity;
  double z;
} Layer;

const Layer getLayer(const int layer);

#endif
