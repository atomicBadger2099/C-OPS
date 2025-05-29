//PROGRAM FOR DEMONSTRATING VARIABLES IN GNU C99


//PREPROCESSOR DECLARATIONS SECTION
#include <stdio.h>


// VARIABLE DECLARATION AND INITIATION SECTION SECTION
// File scope (Global scope) is defined here

const int FILE_CONST = 100;      // File-scope constant
int global_var = 10;             // File-scope variable
static int static_global = 50;   // Internal linkage

#define PI 3.14159               // Preprocessor constant (macro)


// FUNCTION PROTOTYPE SECTION
void function_scope_demo(int param);


//START OF MAIN: EVERYTHING RUNS IN AND FROM ONE AND ONE ONLY MAIN FUNCTION
int main(void) {
    // Function scope
    const int FUNCTION_CONST = 20;    // Function-scope constant
    int function_var = 5;             // Function-scope variable

    printf("File-scope constant FILE_CONST = %d\n", FILE_CONST);
    printf("File-scope variable global_var = %d\n", global_var);
    printf("File-scope static variable static_global = %d\n", static_global);
    printf("Function-scope constant FUNCTION_CONST = %d\n", FUNCTION_CONST);
    printf("Function-scope variable function_var = %d\n", function_var);
    printf("Preprocessor constant PI = %.5f\n", PI);

    // Block scope
    {
        const int BLOCK_CONST = 99;   // Block-scope constant
        int function_var = 999;       // Shadowing function_var
        printf("Block-scope constant BLOCK_CONST = %d\n", BLOCK_CONST);
        printf("Block-scope shadowed function_var = %d\n", function_var);
    }

    // Loop scope
    for (int i = 0; i < 3; i++) {
        const int LOOP_CONST = i + 1; // Loop-scope constant
        printf("Loop iteration %d: LOOP_CONST = %d\n", i, LOOP_CONST);
    }

    function_scope_demo(42);

    return 0;
}


// Function demonstrating parameter and local scope
void function_scope_demo(int param) {
    // param is in function parameter scope
    printf("Function parameter param = %d\n", param);

    // Function local scope
    const int LOCAL_CONST = 7;
    int local_var = 21;

    printf("Function local constant LOCAL_CONST = %d\n", LOCAL_CONST);
    printf("Function local variable local_var = %d\n", local_var);
}
