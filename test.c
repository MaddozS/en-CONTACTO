#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

int main(){
    char mensaje[]="Mensaje chido", mensajeEncriptado1[1000], mensajeEncriptado2[1000], entrada[100];

    encrypt(mensaje, mensajeEncriptado1);
    printf("%s\n", mensajeEncriptado1);

    fflush(stdin);
    gets(entrada);

    encrypt(entrada, mensajeEncriptado2);
    printf("%s\n", mensajeEncriptado2);


    if(compare(entrada, mensajeEncriptado1)){
        printf("\nmensaje valido");
    }
    else{
        printf("\nmensaje invalido");
    }

    return 0;
}