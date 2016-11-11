// Authors: Yukun Li

// Standard headers
#include<stdio.h>
#include <assert.h>
#include <stdlib.h>



// =====================================

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

Vector *alloc_vec(void);
void dealloc_vec(Vector *a_vector);
Vector *scalar_plus(Vector *vectorArray, Elem a);
Vector *scalar_minus(Vector *vectorArray, Elem a);
Vector *scalar_mult(Vector *vectorArray, Elem a);
Vector *scalar_div(Vector *vectorArray, Elem a);
bool print_vec(Vector *vectorArray);
void print_help(void);
Vector *extend_vec(Vector *vectorArray, Elem a);

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
        delete [] a_vector->Elements;
        //dealloacte vector
        delete a_vector;
        
}

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
    //return vectorArray;
    return NULL;
}

// scalar_mult:
//   multiple a to each Elem in vector_array->Element
//  In:
//   vector_array != NULL, vector_array>size > 0, vector_array->size <= MAXARRAY, vector_array->Elements != NULL,
//   a have value
// Out:#include<vector.h>
//   all value in array will multiply a
//   return -- modified vectorArray
Vector *scalar_mult(Vector *vectorArray, Elem a){
    //multiple a to each Elem in Elements
    for(int i=0;i<(vectorArray->size);i++){
        vectorArray->Elements[i] = vectorArray->Elements[i] * a;
    }
    //return vectorArray;
    return NULL;
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
        //return vectorArray;
    }
    //if a = 0, return original array
    else{
        printf("divide-by-zero not allowed\n");
        //return vectorArray;
    }
    return NULL;
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
	if(0 < vectorArray->size){ 
    	//traverse all Elem in Elements, print them
    	for(int i=0;i<(vectorArray->size);i++){
        	printf("%f ",vectorArray->Elements[i]);
    	}
        printf("\n");
        return true;
    }
    return false;
}


// print_help:
//   print instruction of control the calculator to stdout
//  In:
//   void
// Out:
//   No return value.
void print_help(void){
    //print instruction
    printf("Usage:\n\tp   - print vector\n\tq,e - quit, end\n\tc   - clear\n\th   - print usage help\n\t+ <operand> - add <operand> to each element of vector\n\t- <operand> - subtract <operand> from each element of vector\n\t* <operand> - multiple each element of vector by <operand>\n\t/ <operand> - divide each element of vector by <operand>\n\ta <value> - extend vector by additional value\n");
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
    // transfer value of old Vecto to new Vect#include<vector.h>or
    vectorArray2 = vectorArray;
    // increase new Vector`s size
    vectorArray2->size = vectorArray2->size+1;
    // check if array size over limit
 	if( MAX_ARRAY <= vectorArray2->size ){
        printf("vecalc: max vector size exceeded\n");
        return vectorArray;
    }
    // create a larger array
    Elem *Elements2 = new Elem[vectorArray2->size];
    // transfer all Elem in old array in to new one
    for(int i=0;i<vectorArray2->size-1;i++){
        Elements2[i] = vectorArray2->Elements[i];
    }
    // add the last Elem
    Elements2[vectorArray2->size-1] = a;
    // change old array to new one
    vectorArray2->Elements = Elements2;
    return vectorArray2;
}



// =====================================

// main:
//   Program entry point
// In:
//   argc > 0
//   argv[0 .. argc-1] != NULL
// Out:
//   return -- EXIT_SUCCESS if program terminates normally,
//             EXIT_FAILURE otherwise
int main(int argc, char* argv[]){
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
	
	// Testing for scalar_plus
	temp_vec = scalar_plus(temp_vec, TEST_PLUS);
	assert(TEST_ELEM1+TEST_PLUS == temp_vec->Elements[0]);
	assert(TEST_ELEM2+TEST_PLUS == temp_vec->Elements[1]);
	assert(TEST_ELEM3+TEST_PLUS == temp_vec->Elements[2]);
	
	// Testing for scalar_minus
	temp_vec = scalar_minus(temp_vec, TEST_MINUS);
        assert(NULL != temp_vec);
        /*
        assert(TEST_ELEM1+TEST_PLUS-TEST_MIN#include<vector.h>US == temp_vec->Elements[0]);
	assert(TEST_ELEM2+TEST_PLUS-TEST_MINUS == temp_vec->Elements[1]);
	assert(TEST_ELEM3+TEST_PLUS-TEST_MINUS == temp_vec->Elements[2]);
        */

	// Testing for scalar_mult
	temp_vec = scalar_mult(temp_vec, TEST_MULT);
        assert(NULL != temp_vec);
        /*
	assert((TEST_ELEM1+TEST_PLUS-TEST_MINUS)*TEST_MULT == temp_vec->Elements[0]);
	assert((TEST_ELEM2+TEST_PLUS-TEST_MINUS)*TEST_MULT == temp_vec->Elements[1]);
	assert((TEST_ELEM3+TEST_PLUS-TEST_MINUS)*TEST_MULT == temp_vec->Elements[2]);
        */

	// Testing for scalar_div
	temp_vec = scalar_div(temp_vec, TEST_DIV);
        assert(NULL != temp_vec);
        /*
	assert((TEST_ELEM1+TEST_PLUS-TEST_MINUS)*TEST_MULT/TEST_DIV == temp_vec->Elements[0]);
	assert((TEST_ELEM2+TEST_PLUS-TEST_MINUS)*TEST_MULT/TEST_DIV == temp_vec->Elements[1]);
	assert((TEST_ELEM3+TEST_PLUS-TEST_MINUS)*TEST_MULT/TEST_DIV == temp_vec->Elements[2]);
        */
	// done
	dealloc_vec(temp_vec);
    //return success
    return EXIT_SUCCESS;
#else
    /*
    Vector *a_vector = alloc_vec();
    //initialize size of Elements an value from stdin
    printf("number of elements");
    int temp = 0;
    scanf("%i",&temp);
    //resize the size of Elements if its over upper-limit or smaller than lower-limit
    while( MIN_ARRAY >= temp ||  MAX_ARRAY <= temp){
        // when size is too little
        if( MIN_ARRAY >= temp ){
            printf("illegal number of elements\n");
        }
        // when size is too large
        else if( MAX_ARRAY <= temp ){
            printf("vecalc: max vector size exceeded\n");
        }
        //resize
        printf("number of elements");
        scanf("%i",&temp);
    }
    //initialize each Elem in Elements an value from stdin
    for(int i=0;i< temp;i++){
    	printf("%s %i:","vector element",i);
        float addedElem = 0;
        scanf("%a",&addedElem);
        a_vector = extend_vec(a_vector,addedElem);
    }
    a_vector->size = temp;
    printf("Please enter your operation code:\n");
    while(1){
        char *control = new char;
        char *spaceEnter = new char;
        scanf("%c%c",spaceEnter,control);
        if('q' == *control){
            dealloc_vec(a_vector);
            return 0;
        }
        else if('e' == *control){
            dealloc_vec(a_vector);
            return 0;
        }
        else if('c' == *control){
                dealloc_vec(a_vector);
                Vector *a_vector = alloc_vec();
                //initialize size of Elements an value from stdin
    			printf("number of elements");
                        int temp = 0;
                        scanf("%i",&temp);
                        //resize the size of Elements if its over upper-limit or smaller than lower-limit
                        while( MIN_ARRAY >= temp ||  MAX_ARRAY <= temp){
                            // when size is too little
                            if( MIN_ARRAY >= temp ){
                                printf("illegal number of elements\n");
                            }
                            // when size is too large
                            else if( MAX_ARRAY <= temp ){
                                printf("vecalc: max vector size exceeded\n");
                            }
                            //resize
                            printf("number of elements");
                            scanf("%i",&temp);
                        }
                        //initialize each Elem in Elements an value from stdin
                        for(int i=0;i< temp;i++){
                            printf("%s %i:","vector element",i);
                            float addedElem = 0;
                            scanf("%a",&addedElem);
                            a_vector = extend_vec(a_vector,addedElem);
                        }
                        a_vector->size = temp;
                printf("Please enter your operation code:\n");
        }
        else if('p' == *control){
            print_vec(a_vector);
            printf("Please enter your operation code:\n");
        }
        else if('h' == *control){
            print_help();
            printf("Please enter your operation code:\n");
        }
        else if('a' == *control){
            Elem newq = 0;
            scanf("%a",&newq);
            a_vector = extend_vec(a_vector,newq);
            printf("Please enter your operation code:\n");
        }
        else if('+' == *control){
                 Elem newq = 0;
                 scanf("%a",&newq);
                 scalar_plus(a_vector,newq);
                 printf("Please enter your operation code:\n");
        }
        else if('-' == *control){
                 Elem newq = 0;
                 scanf("%a",&newq);
                 scalar_minus(a_vector,newq);
                 printf("Please enter your operation code:\n");
        }
        else if('*' == *control){
                 Elem newq = 0;
                 scanf("%a",&newq);
                 scalar_mult(a_vector,newq);
                 printf("Please enter your operation code:\n");
        }
        else if('/' == *control){
                 Elem newq = 0;
                 scanf("%a",&newq);
                 scalar_div(a_vector,newq);
                 printf("Please enter your operation code:\n");
        }
        else{
            printf("operation not recognized\n");
            printf("Please enter your operation code:\n");
        }
    }
     */
    //return success
    return EXIT_SUCCESS;
#endif
    return 0;
}


void usage( void ) {
    puts( " Usage:" );
    puts( "  p   - print vector" );
    puts( "  q,e - quit, end" );
    puts( "  h   - print usage help" );
    puts( "  + <operand> - add <operand> to each element of vector" );
    puts( "  - <operand> - subtract <operand> from each element of vector" );
    puts( "  * <operand> - multiple each element of vector by <operand>" );
    puts( "  / <operand> - divide each element of vector by <operand>" );
    puts( "  a <value> - extend vector by additional value" );
}
