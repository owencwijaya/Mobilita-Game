#ifndef GAME_MATRIX
#define GAME_MATRIX
#include "Matrix/matrix.h"
typedef struct {
    Matrix map;
    Matrix AdjM;
    Matrix OrderM; 
} gameMatrix ;

#endif