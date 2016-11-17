// Authors: Yukun Li
// NSID: yul040
// Standard headers
#include<stdio.h>
#include <stdlib.h>

#include"vector.h"      // for MAX_ELEM, Vector, Elem


// alloca_vec:
//   Allocate a new Vector.
// In:
//  nothing
// Out:
//   return -- pointer to the new vector
//          -- NULL on error
Vector *alloc_vec(void){
         // allocate main structure
         Vector *vectorArray = new Vector;
        // when do not allocate right
         if( NULL == vectorArray){
             return NULL;
         }
         vectorArray->size = 0;
         // allocate space for array
         vectorArray->Elements = new Elem[vectorArray->size];
         // on error, free up space allocated so far
         if(NULL == vectorArray->Elements){
             delete vectorArray;
             return NULL;
         }
         return vectorArray;
}

// dealloc_vec:
//   frees the memory used by Vector *a_vector.
// In:
//   a_vector != NULL, a_vector>size > 0, a_vector->size <= MAXARRAY, a_vector->Elements != NULL
// Out:
//   No return value.
//   effect -- all memory used by Vector *a_vector is deallocated.
void dealloc_vec(Vector *a_vector){
        //deallocate vector pointing to array
        delete a_vector->Elements;
        //dealloacte vector
        delete a_vector;

}

// print_vec:
//   print Vector *a_vector to stdout
//  In:
//   a_vector != NULL, a_vector>size > 0, a_vector->size <= MAXARRAY, a_vector->Elements != NULL
// Out:
//   No return value.
//   effect -- print the content of a_vector
bool print_vec(Vector *vectorArray){
        //check if parameter is empty or null
        if(0 < vectorArray->size || vectorArray == NULL){
        //traverse all Elem in Elements, print them
        for(int i=0;i<(vectorArray->size);i++){
                printf("%f ",vectorArray->Elements[i]);
        }
        printf("\n");
        return true;
    }
    return false;
}

// extend_vec:
//   etend the size of vector array and add an new Elem in to it
//  In:
//   a_vector != NULL, a_vector>size > 0, a_vector->size <= MAXARRAY, a_vector->Elements != NULL,
//   a != NULL
// Out:
//   return -- new vector which contain modified array
Vector *extend_vec(Vector *vectorArray, Elem a){
    // allocate new Vector
    Vector *vectorArray2 = new Vector;
    // increase new Vector`s size
    vectorArray2->size = vectorArray->size+1;
    // check if array size over limit
	printf("%d\n",vectorArray2->size);
    if( MAX_ELEMS <= vectorArray2->size ){
        printf("vecalc: max vector size exceeded\n");
        return vectorArray;
    }
    // create a larger array
    vectorArray2->Elements = new Elem[vectorArray2->size];
    // transfer all Elem in old array in to new one
    for(int i=0;i<vectorArray2->size-1;i++){
        vectorArray2->Elements[i] = vectorArray->Elements[i];
    }
    // add the last Elem
    vectorArray2->Elements[vectorArray2->size-1] = a;
    return vectorArray2;
}

