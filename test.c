#include <stdio.h>
#include <stdlib.h>
#include "encrypt.h"

int main(int argc, char const *argv[])
{
    char msg[]="Mensaje Oculto :o", msgEncrypt[1000]="", msgDecrypted[1000]="";
    printf("---Encriptacion\n");
    printf("Mensaje Original: %s\n", msg);
    encrypt(msg, msgEncrypt);
    printf("Mensaje Encriptado:%s\n", msgEncrypt);

    printf("---Desencriptacion\n");
    printf("Mensaje Encriptado:%s\n", msgEncrypt);
    decrypt(msgEncrypt, msgDecrypted);
    printf("Mensaje Original: %s\n", msgDecrypted);

    return 0;
}
