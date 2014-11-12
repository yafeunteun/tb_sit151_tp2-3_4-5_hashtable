#include <stdio.h>
#include "hashing.h"

int hash1(char* mot) {

    if(mot != NULL){
        return mot[0];
    } else {
        return -1;
    }
}
