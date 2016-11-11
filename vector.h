// Author: Yukun LI
// NSID: yul040

#ifndef _VECTOR_H_
#define _VECTOR_H_

// A Elem is a float point data
typedef float Elem;
// ... (Elem e, ...) {
//   return e;
// }



// =====================================

// A state of N-Queens consists of the board size and board's data.
typedef struct{
    int size;
    Elem *Elements;
}Vector;
// ... (Vector *v, int order... ) {
//  ... v->Elem[oeder] ...
// }
const int MAX_ARRAY = 65536; // Value chosen based on needs
                             // type int chosen because the constant
                             // is used to compare against variables of
                             // type int.

const int MIN_ARRAY = 0;     // Value chosen based on needs
                             // type int chosen because the constant
                             // is used to compare against variables of
                             // type int.

// alloca_vec:
//   Allocate a new Vector.
// In:
//  nothing
// Out:
//   return -- pointer to the new vector
//          -- NULL on error                            
Vector *alloc_vec(void);

// dealloc_vec:
//   frees the memory used by Vector *a_vector.
// In:
//   a_vector != NULL, a_vector>size > 0, a_vector->size <= MAXARRAY, a_vector->Elements != NULL
// Out:
//   No return value.
//   effect -- all memory used by Vector *a_vector is deallocated.
void dealloc_vec(Vector *a_vector);

// print_vec:
//   print Vector *a_vector to stdout
//  In:
//   a_vector != NULL, a_vector>size > 0, a_vector->size <= MAXARRAY, a_vector->Elements != NULL
// Out:
//   No return value.
//   effect -- print the content of a_vector
bool print_vec(Vector *vectorArray);

// extend_vec:
//   etend the size of vector array and add an new Elem in to it
//  In:
//   a_vector != NULL, a_vector>size > 0, a_vector->size <= MAXARRAY, a_vector->Elements != NULL,
//   a != NULL
// Out:
//   return -- new vector which contain modified array
Vector *extend_vec(Vector *vectorArray, Elem a);


#endif // _VECTOR_H_