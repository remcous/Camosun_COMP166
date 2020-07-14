#include <stdio.h>
#include "layers.h"
#include "reflections.h"

int main(int argc, char *argv[]){
	forward(0.0, 1.0, 1.3e-6, 1, N_LAYERS, 0);
	return 0;
}