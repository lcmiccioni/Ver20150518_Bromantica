#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main(int argc, char** argv) {
    ricetta elenco[N];
    
    //input delle ricette
    inputRicette(elenco, N);
    
    //ordinamento delle ricette
    ordinaRicette(elenco, N);
    
    //file ricette
    fileRicette(elenco, N);
    
    return (EXIT_SUCCESS);
}