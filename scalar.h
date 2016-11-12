
// Author: Yukun LI
// NSID: yul040

#include "vector.h"

#ifndef _VECTOR_H_
#define _VECTOR_H_



// scalar_plus:
//   add a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will plus a
//   return -- modified vectorArray
Vector *scalar_plus(Vector *vectorArray, Elem a);

// scalar_minus:
//   minus a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will minus a
//   return -- modified vectorArray
Vector *scalar_minus(Vector *vectorArray, Elem a);

// scalar_mult:
//   multiple a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:#include<vector.h>
//   all value in array will multiply a
//   return -- modified vectorArray
Vector *scalar_mult(Vector *vectorArray, Elem a);

// scalar_div:
//   divide a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will divide a
//   return -- modified vectorArray if a != 0, otherwise return old vectorArray
Vector *scalar_div(Vector *vectorArray, Elem a);

#endif //SCALAR_H