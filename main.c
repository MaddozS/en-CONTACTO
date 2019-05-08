#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

//definicion del numero de las flechas
#define UP 72
#define DOWN 80
#define BLOCK 219
#define ENTER 13

//funcion para cambiar de color el texto
void color(char color);
void titulo();
int menu_principal(int opcion);
void imprimir_menu_principal();
void esconder_cursor();
void centrar_texto(int espacios);
void ejecutar_opcion_menu_principal(int opcion);
void crear_pin();
//void print_pin();
void verificar_pin();
void iniciar_sesion();

int posOpcion=0, i, salida=0, key=0, pinAsignado=0, size, numeroOpciones=3;
FILE *pinArchivo;

int main(){
    int opcion;
    do{
        //funcion para verificar si ya hay un pin generado
        verificar_pin();
        //Funcion que imprime las opciones
        opcion = menu_principal_opciones();
        //Funcion ejecuta la opcion seleccionada
        ejecutar_opcion_menu_principal(opcion);
    }
    while(salida!=1);
    return 0;
}
//funcion para cambiar de opcion seleccionada, usando las flechas del teclado
int menu_principal_opciones(){
    do{
        system("cls");
        esconder_cursor();
        titulo();
        imprimir_menu_principal(posOpcion);
        key = getch();
        switch (key){
            case UP:
                if(posOpcion==0){
                    posOpcion=numeroOpciones;
                }
                else{
                    posOpcion--;
                }
                break;
            case DOWN:
                if(posOpcion==numeroOpciones){
                    posOpcion=0;
                }
                else{
                    posOpcion++;
                }
                break;
        }
    }
    while(key != ENTER);
   
    return posOpcion;
}
//funcion para imprimir el titulo
void titulo(){
    color(6);
    centrar_texto(66);
    printf("   __    __        ___   ___    __  _____  _      ___  _____  ___ \n");
    centrar_texto(66);
    printf("  /__\\/\\ \\ \\      / __\\ /___\\/\\ \\ \\/__   \\/_\\    / __\\/__   \\/___\\\n");
    centrar_texto(66);
    printf(" /_\\ /  \\/ /____ / /   //  //  \\/ /  / /\\//_\\\\  / /     / /\\//  //\n");
    centrar_texto(66);
    printf("//__/ /\\  /_____/ /___/ \\_// /\\  /  / / /  _  \\/ /___  / / / \\_// \n");
    centrar_texto(66);
    printf("\\__/\\_\\ \\/      \\____/\\___/\\_\\ \\/   \\/  \\_/ \\_/\\____/  \\/  \\___/  \n\n\n");
}
//funcion que imprime n cantidad de espacios en blanco para correr el texto
void centrar_texto(int extensionString){
    int i;
    for(i = 1; i <= 60-(extensionString/2); i++){ printf(" "); }
}
//funcion para imprimir las opciones del programa
void imprimir_menu_principal(int opcionSelec){
    //Cambio de color si la opcion esta seleccionada
    if(pinAsignado == 1){
        if(opcionSelec == 0){color(4);} else{color(7);} 
        centrar_texto(14);
        printf("Iniciar sesi%cn\n", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSelec == numeroOpciones-2){color(4);} else{color(7);} 
        centrar_texto(8);
        printf("Opci%cn 2\n", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSelec == numeroOpciones-1){color(4);} else{color(7);}
        centrar_texto(8);
        printf("Opci%cn 3\n", 162);
    }
    else{
        if(opcionSelec == 0){color(4);} else{color(7);} 
        centrar_texto(9);
        printf("Crear PIN\n");
    }
    //Cambio de color si la opcion esta seleccionada
    if(opcionSelec == numeroOpciones){color(4);} else{color(7);}
    centrar_texto(18);
    printf("Salir del programa\n");
}
void crear_pin(){
    int i, j, error=0;
    char pinUsuario[5], pinEncriptado[2000];
    system("cls");
    //Do-While para volver a pedir el pin en caso que no cumpla con la extension pedida
    do{
        error=0;
        color(6);
        printf("\n\n\n\n");
        centrar_texto(66); printf("Ingresa PIN con el que vas a proteger tus contactos (de 4 digitos):\n");
        color(7);
        fflush(stdin);
        centrar_texto(4); gets(pinUsuario);
        if(strlen(pinUsuario) < 4 || strlen(pinUsuario) > 4){
            color(4);
            printf("\n\n\n\n");
            centrar_texto(46); printf("El pin debe tener 4 digitos, vuelve a ponerlo!\n\n");
            color(7);
            centrar_texto(46); printf("Pulsa cualquier tecla para intentarlo de nuevo");
            error=1;
            getch();
        }
        else{
            for(i=0; i<4; i++){
                if(pinUsuario[i] < '0' || pinUsuario[i]>'9'){
                    color(4);
                    printf("\n\n\n\n");
                    centrar_texto(52); printf("El pin debe contener solo numeros, vuelve a ponerlo!\n\n");
                    color(7);
                    centrar_texto(46); printf("Pulsa cualquier tecla para intentarlo de nuevo");
                    error=1;
                    getch();
                    break;
                }
            }
        }
        
        system("cls");
    }
    while (error==1);
    //funcion para encriptar el pin 
    encrypt(pinUsuario, pinEncriptado);
    //funcion para poner el pin encriptado en el archivo
    pinArchivo = fopen("pin.txt", "w");
    fputs(pinEncriptado, pinArchivo);
    fclose(pinArchivo);

    printf("\n\n\n\n");
    centrar_texto(21); printf("PIN Creado con exito!\n");
    centrar_texto(53); printf("Pulsa cualquier tecla para regresar al menu principal");
    getch();
}
// void print_pin(){
//     char pin[100];
//     int x, charDesencrip;
//     system("cls");
//     pinArchivo = fopen("pin.txt", "r");
//     while( fgets(pin, 100, pinArchivo)!= NULL){
//         printf("%s", pin);
//     }
//     char *ptr = strtok(pin, " "); 
// 	   while(ptr != NULL){
//          x = atoi(ptr);
//          charDesencrip = desencrip(x);
// 		    ptr = strtok(NULL, " ");
// 	    }
//     fclose(pinArchivo);
//     getch();
// }
void verificar_pin(){
    pinArchivo = fopen("pin.txt", "r");
    if (pinArchivo != NULL) {
        fseek (pinArchivo, 0, SEEK_END);
        size = ftell(pinArchivo);
        if (size != 0) {
            pinAsignado=1;
            numeroOpciones=3;
        }
        else{
            pinAsignado=0;
            numeroOpciones=1;
        }
    }
    else{
        pinAsignado=0;
        numeroOpciones=1;
    }
    fclose(pinArchivo);
}
void iniciar_sesion(){
    system("cls");
    pinArchivo = fopen("pin.txt", "r");
    
}
void ejecutar_opcion_menu_principal(int opcion){

    if(pinAsignado == 0){
        if(opcion == 0){
            crear_pin();
        }
        else if (opcion == numeroOpciones){
            salida=1;
        }
    }
    else{
        if(opcion == 0){
            iniciar_sesion();
        }
        else if(opcion == numeroOpciones-2){
            //print_pin();
        }
        else if (opcion == numeroOpciones){
            salida=1;
        }
    }
    
}

//funcion para esconger el puntero del cursor (donde se esta escribiendo el texto)
void esconder_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
//funcion para cambiar de color el texto
void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}