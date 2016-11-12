// Author: Yukun Li

#include <assert.h>     // for assert()
#include <ctype.h>      // for isspace()
#include <stdio.h>      // for fputs(), puts(), sscanf(), fprintf

#include "vector.h"     // for MAX_ELEM, Vector, Elem
#include "scalar.h"     // for scalar_plus(), scalar_minus(), etc.
#include "vecalc.h"     // for MAX_INPUT_BUF_SIZE, wrk_vec_p

/*
 * Internal functions to test_scalar.cc
 */

int main( int argc, char *argv[] ){
#ifdef TESTING
    const int TEST_SIZE = 3;
    const float TEST_ELEM1 = 4;
    const float TEST_ELEM2 = 3.33333;
    const float TEST_ELEM3 = 2;
    const float TEST_PLUS = 2;
    const float TEST_MINUS = 1;
    const float TEST_MULT = 2;
    const float TEST_DIV = 3;

    Vector *temp_vec = alloc_vec();

    temp_vec = extend_vec(temp_vec, TEST_ELEM1);
    assert(TEST_SIZE-2 == temp_vec->size);
    assert(TEST_ELEM1 == temp_vec->Elements[0]);
    temp_vec = extend_vec(temp_vec, TEST_ELEM2);
    assert(TEST_SIZE-1 == temp_vec->size);
    assert(TEST_ELEM2 == temp_vec->Elements[1]);
    temp_vec = extend_vec(temp_vec, TEST_ELEM3);
    assert(TEST_SIZE == temp_vec->size);
    assert(TEST_ELEM3 == temp_vec->Elements[2]);

    // Testing for scalar_plus
    temp_vec = scalar_plus(temp_vec, TEST_PLUS);
    assert(TEST_ELEM1+TEST_PLUS == temp_vec->Elements[0]);
    assert(TEST_ELEM2+TEST_PLUS == temp_vec->Elements[1]);
    assert(TEST_ELEM3+TEST_PLUS == temp_vec->Elements[2]);



    // Testing for scalar_minus
    temp_vec = scalar_minus(temp_vec, TEST_MINUS);
    assert((TEST_ELEM1+TEST_PLUS-TEST_MINUS) == temp_vec->Elements[0]);
    assert(TEST_ELEM2+TEST_PLUS-TEST_MINUS == temp_vec->Elements[1]);
    assert(TEST_ELEM3+TEST_PLUS-TEST_MINUS == temp_vec->Elements[2]);

    // Testing for scalar_mult
    temp_vec = scalar_mult(temp_vec, TEST_MULT);
    assert((TEST_ELEM1+TEST_PLUS-TEST_MINUS)*TEST_MULT == temp_vec->Elements[0]);
    assert((TEST_ELEM2+TEST_PLUS-TEST_MINUS)*TEST_MULT == temp_vec->Elements[1]);
    assert((TEST_ELEM3+TEST_PLUS-TEST_MINUS)*TEST_MULT == temp_vec->Elements[2]);


    // Testing for scalar_div
    temp_vec = scalar_div(temp_vec, TEST_DIV);
    assert((TEST_ELEM1+TEST_PLUS-TEST_MINUS)*TEST_MULT/TEST_DIV == temp_vec->Elements[0]);
    assert((TEST_ELEM2+TEST_PLUS-TEST_MINUS)*TEST_MULT/TEST_DIV == temp_vec->Elements[1]);
    assert((TEST_ELEM3+TEST_PLUS-TEST_MINUS)*TEST_MULT/TEST_DIV == temp_vec->Elements[2]);

    //exit success
    return 0;
#endif
}
