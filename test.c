#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

int main(int argc, char const *argv[])
{
    char msg[]="Mensaje Oculto :o", msgEncrypt[2000], msgDecrypted[2000];
    system("cls");
    printf("---Encriptacion\n");

    printf("Mensaje Original: %s\n", msg);
    encrypt(msg, msgEncrypt);
    printf("Mensaje Encriptado: %s\n", msgEncrypt);

    printf("---Desencriptacion\n");
    
    printf("Mensaje Encriptado: %s\n", msgEncrypt);
    fflush(stdin);
    decrypt(msgEncrypt, msgDecrypted);
    printf("Mensaje Original: %s\n", msgDecrypted);
	
	system("pause");
    return 0;
}
