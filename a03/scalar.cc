// Author: Yukun Li
// NSID: yul040
#include <stdio.h>

#include "vector.h"     // for MAX_ELEM, Vector, Elem
#include "scalar.h"     // for scalar_plus(), scalar_minus(), etc.


/*
 * Internal functions to scalar.cc
 */


// scalar_plus:
//   add a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will plus a
//   return -- modified vectorArray
Vector *scalar_plus(Vector *vectorArray, Elem a){
    //add a to each Elem in Elements
    for(int i=0;i<(vectorArray->size);i++){
        vectorArray->Elements[i] = vectorArray->Elements[i] + a;
    }
    return vectorArray;
}

// scalar_minus:
//   minus a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will minus a
//   return -- modified vectorArray
Vector *scalar_minus(Vector *vectorArray, Elem a){
    //minus a to each Elem in Elements
    for(int i=0;i<(vectorArray->size);i++){
        vectorArray->Elements[i] = vectorArray->Elements[i] - a;
    }
    return vectorArray;
}

// scalar_mult:
//   multiple a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will multiply a
//   return -- modified vectorArray
Vector *scalar_mult(Vector *vectorArray, Elem a){
    //multiple a to each Elem in Elements
    for(int i=0;i<(vectorArray->size);i++){
        vectorArray->Elements[i] = (vectorArray->Elements[i]) * a;
    }
    return vectorArray;
}

// scalar_div:
//   divide a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:
//   all value in array will divide a
//   return -- modified vectorArray if a != 0, otherwise return old vectorArray
Vector *scalar_div(Vector *vectorArray, Elem a){
    //only works for a != 0
    if( a != 0){
        //divide a to each Elem in Elements
        for(int i=0;i<(vectorArray->size);i++){
            vectorArray->Elements[i] = vectorArray->Elements[i] / a;
        }
        return vectorArray;
    }
    //if a = 0, return original array
    else{
        printf("divide-by-zero not allowed\n");
        return vectorArray;
    }
}

