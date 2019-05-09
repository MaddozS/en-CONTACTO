#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcion que encripta un string que se le de
//@origin: texto que se va a encriptar
//@destination: variable donde se almacenara el texto encriptado
void encrypt(char *origin, char *destination){
    destination[0]='\0';
    int i, iChar, charEncrypted;
    char x[128];
    for(i = 0; i < strlen(origin); i++){
        int iChar = (int)origin[i];
        charEncrypted = (iChar-10)*13;
        itoa(charEncrypted, x, 10);
        strcat(destination, x);
        if (i<strlen(origin)-1) {
            strcat(destination,"-");
        }
    }
}
//Funcion que desencripta un string que se le de
//@encrypted: texto que esta previamente encriptado
//@destination: variable donde se almacenara el texto desencriptado
void decrypt(char *encrypted, char *destination){
    int x, originalChar, i=0;
    char *ptr = strtok(encrypted, "-"); 
	while(ptr != NULL){
        x = atoi(ptr);
        originalChar = (x/13)+10;
        destination[i]= (char)originalChar;
		ptr = strtok(NULL, "-");
        i++;
	}
    destination[i+1]='\0';
}
//Funcion que compara un texto dado con uno ya encriptado, para saber si son iguales.
//ENTRADA:
//@encrypted: texto sin encriptar
//@destination: texto encriptado
//SALIDA:
//@status: retorna 1 si los 2 strings comparadaros son iguales, en caso de no serlo, retorna 0
int compare(char *str1, char *strEncrypted){
    char decryptedStr[2048];
    int status;

    decrypt(strEncrypted, decryptedStr);
    if(strcmp(decryptedStr, str1) == 0){
        status = 1;
    }
    else{
        status = 0;
    }
    return status;
}