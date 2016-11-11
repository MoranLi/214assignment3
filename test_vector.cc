 

// main:
//   Program entry point
// In:
//   argc > 0
//   argv[0 .. argc-1] != NULL
// Out:
//   return -- EXIT_SUCCESS if program terminates normally,
//             EXIT_FAILURE otherwise
bool main(int argc, char* argv[]){
#ifdef TESTING
        const int TEST_SIZE = 3;
        const float TEST_ELEM1 = 4;
        const float TEST_ELEM2 = 3.33333;
        const float TEST_ELEM3 = 2;
        const float TEST_PLUS = 2;
        const float TEST_MINUS = 1;
        const float TEST_MULT = 2;
        const float TEST_DIV = 3;

        // Testing for alloc_vec
        Vector *temp_vec = alloc_vec();

        // Testing for Vector if it is allocated
        assert(NULL != temp_vec);
        assert(NULL != temp_vec->Elements);

        //Testing for extend_vec
        temp_vec = extend_vec(temp_vec, TEST_ELEM1);
        assert(TEST_SIZE-2 == temp_vec->size);
        assert(TEST_ELEM1 == temp_vec->Elements[0]);
        temp_vec = extend_vec(temp_vec, TEST_ELEM2);
        assert(TEST_SIZE-1 == temp_vec->size);
        assert(TEST_ELEM2 == temp_vec->Elements[1]);
        temp_vec = extend_vec(temp_vec, TEST_ELEM3);
        assert(TEST_SIZE == temp_vec->size);
        assert(TEST_ELEM3 == temp_vec->Elements[2]);

        // Testing for print_vec
        assert(true == print_vec(temp_vec));
        // done
        dealloc_vec(temp_vec);
        //return success
        return true;
}
