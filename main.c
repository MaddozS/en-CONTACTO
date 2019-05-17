#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

//definicion del codigo ASCII de ciertas teclas
#define UP 72
#define DOWN 80
#define BLOCK 219
#define ENTER 13

//FUNCIONES
void color(char color);
void titulo();
void imprimir_menu_principal(int opcionSeleccionada);
void esconder_cursor();
void centrar_texto(int espacios);
void ejecutar_opcion_menu_principal(int opcion);
void crear_pin();
void verificar_pin(int statusPin);
int menu_abc();
void imprimir_menu_abc(int opcionSeleccionada);
void ejecutar_opcion_menu_abc(int opcionSeleccionada);
int verificar_archivo(char *rutaDelArchivo);
int iniciar_sesion();
void crear_contacto();

//Variables globales
int salida=0, salidaABC=0, existePin, totalOpcMenuPrin;

//Funcion main
//Es la que lleva el proceso del todo el programa
int main(int argc, char const *argv[])
{
    int opcion, statusPin;
    do{
        esconder_cursor();
        //Se verifica que ya haya un pin generado
        statusPin = verificar_archivo("pin.txt");
        verificar_pin(statusPin);
        //Se imprimen las opciones del menu principal
        opcion = menu_principal_opciones();
        //Se ejecuta la opcion seleccionada
        ejecutar_opcion_menu_principal(opcion);
    }
    while(salida!=1);
    return 0;
}
void verificar_pin(int statusPin){
     if(statusPin != 2){
        totalOpcMenuPrin=1;
        existePin=0;
    }
    else{
        totalOpcMenuPrin=3;
        existePin=1;
    }
}
//Funcion que ejecuta la opcion seleccionada en el menu de Altas Bajas y Cambios
void ejecutar_opcion_menu_abc(int opcionSeleccionada){
    if(opcionSeleccionada == 0){
        crear_contacto();
    }
    else if(opcionSeleccionada == 4){
        salidaABC=1;
    }
}
void crear_contacto(){

}
//Imprime las opciones disponibles dentro del menu de Altas Bajas y Cambios, si la opcion esta seleccionada, se imprimira de un color diferente
void imprimir_menu_abc(int opcionSeleccionada){
    if(opcionSeleccionada == 0){color(4);} else{color(7);} 
    centrar_texto(14);
    printf("\nAgregar contactos");
    if(opcionSeleccionada == 1){color(4);} else{color(7);} 
    centrar_texto(14);
    printf("\nEditar un contacto");
    if(opcionSeleccionada == 2){color(4);} else{color(7);} 
    centrar_texto(14);
    printf("\nEliminar un contacto");
    if(opcionSeleccionada == 3){color(4);} else{color(7);} 
    centrar_texto(14);
    printf("\nVer todos los contactos");
    if(opcionSeleccionada == 4){color(4);} else{color(7);} 
    centrar_texto(14);
    printf("\nRegresar al menu principal");
}
//Funcion que itera, mediante el teclado, la opcion seleccionada en el menu de Altas Bajas y Cambios
//@SALIDA: Si se aprieta la tecla ENTER, el ciclo se rompe y la funcion devolvera la opcion seleccionada del menu de ABC
int menu_abc(){
    int posOpcionABC=0, key=0;
    do{
        system("cls");
        imprimir_menu_abc(posOpcionABC);
        key = getch();
        switch (key){
            case UP:
                if(posOpcionABC==0){
                    posOpcionABC=4;
                }
                else{
                    posOpcionABC--;
                }
                break;
            case DOWN:
                if(posOpcionABC==4){
                    posOpcionABC=0;
                }
                else{
                    posOpcionABC++;
                }
                break;
        }
    }
    while(key != ENTER);

    return posOpcionABC;
}

//Funcion que imprime las opciones del menu principal y las itera dependiendo de la tecla que se presione, asi como ejecutar la opcion seleccionada cuando se presione ENTER
int menu_principal_opciones(){
    int posOpcionPrincipal=0, key=0;
   
    do{
        system("cls");
        titulo();
        imprimir_menu_principal(posOpcionPrincipal);
        key = getch();
        switch (key){
            case UP:
                if(posOpcionPrincipal==0){
                    posOpcionPrincipal=totalOpcMenuPrin;
                }
                else{
                    posOpcionPrincipal--;
                }
                break;
            case DOWN:
                if(posOpcionPrincipal==totalOpcMenuPrin){
                    posOpcionPrincipal=0;
                }
                else{
                    posOpcionPrincipal++;
                }
                break;
        }
    }
    while(key != ENTER);

    return posOpcionPrincipal;
}
//Funcion que imprime el titulo del programa
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
//Funcion que imprime n cantidad de espacios para correr el texto, para que centre el texto
void centrar_texto(int extensionString){
    int i;
    for(i = 1; i <= 60-(extensionString/2); i++){ printf(" "); }
}
//Funcion que unicamente imprime las opciones del programa, dependiendo si hay o no hay pin
void imprimir_menu_principal(int opcionSeleccionada){
    //Cambio de color si la opcion esta seleccionada
    if(existePin == 1){
        if(opcionSeleccionada == 0){color(4);} else{color(7);} 
        centrar_texto(14);
        printf("Iniciar sesi%cn\n", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSeleccionada == totalOpcMenuPrin-2){color(4);} else{color(7);} 
        centrar_texto(8);
        printf("Opci%cn 2\n", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSeleccionada == totalOpcMenuPrin-1){color(4);} else{color(7);}
        centrar_texto(8);
        printf("Opci%cn 3\n", 162);
    }
    else{
        if(opcionSeleccionada == 0){color(4);} else{color(7);} 
        centrar_texto(9);
        printf("Crear PIN\n");
    }
    //Cambio de color si la opcion esta seleccionada
    if(opcionSeleccionada == totalOpcMenuPrin){color(4);} else{color(7);}
    centrar_texto(18);
    printf("Salir del programa\n");
}
//Funcion que lee le un pin que ingrese el usuario, en caso de no cumplir con las caracteristicas requeridas, se le pedira de nuevo.
void crear_pin(){
    int i, j, error=0;
    char pinUsuario[5], pinEncriptado[2000];
    FILE *pinArchivo;
    system("cls");
    //Do-While para volver a pedir el pin en caso que no cumpla con la extension pedida
    do{
        error=0;
        color(6);
        printf("\n\n\n\n");
        centrar_texto(66); printf("Ingresa PIN con el que vas a proteger tus contactos (de 4 digitos):\n");
        color(7);
        fflush(stdin);
        centrar_texto(4);
        gets(pinUsuario);
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
    //Funcion para encriptar el pin 
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

//Funcion que recibe la ruta del archivo, y verifica si existe, si tiene informacion o no
//ENTRADA: 
//@rutaDelArchivo: es la ruta del archivo a verificar.
//SALIDA:
//@status: retorna 0 si el archivo no existe.
//         retorna 1 si el archivo existe, pero no tiene informacion.
//         retorna 2 si el archivo existe y tiene informacion dentro.
int verificar_archivo(char *rutaDelArchivo){
    FILE *archivo;
    int status, size;

    archivo = fopen(rutaDelArchivo, "r");
    if (archivo != NULL) {
        fseek (archivo, 0, SEEK_END);
        size = ftell(archivo);
        if (size != 0) {
            status=2;
        }
        else{
            status=1;
        }
    }
    else{
        status = 0;
    }
    fclose(archivo);

    return status;
}


//Funcion que busca el pin ya creado, compara con el que esta ingresando el usuario, y, en caso de ser iguales, se inicia la sesion
//ENTRADA:
//(dentro de la funcion) @pinIngresado: el pin que el usuario da
//SALIDA:
//@sesion: el estatus de la sesion, en caso de que el pin ya creado sea igual al pin que ingreso el usuario, se retorna 1, sino, se retorna 0
int iniciar_sesion(){
    char pinIngresado[5], pinPrograma[100];
    int intentos=4, fallo, i=0, c, sesion;
    FILE *pinArchivo;
    pinArchivo = fopen("pin.txt", "r");
    while (c != EOF){
        c = fgetc(pinArchivo);
        pinPrograma[i] = (char)c;
        i++;
    }
    pinPrograma[i]='\0';
    fclose(pinArchivo);
    do{
        fallo=0;
        system("cls");
        color(6);
        printf("\n\n\n\n");
        centrar_texto(18); printf("Ingresa el tu PIN:\n");
        color(7);
        centrar_texto(4);
        gets(pinIngresado);
        if(!compare(pinIngresado, pinPrograma)){
            color(4);
            intentos--;
            centrar_texto(42); printf("El pin es incorrecto! Te quedan %d intentos\n", intentos);
            fallo=1;
        }
        else{
            color(2);
            centrar_texto(32); printf("PIN ingresado de manera exitosa!\n");
        }
        centrar_texto(39); printf("Pulsa cualquier tecla para continuar...\n");
        getch();
    }
    while(intentos > 0 && fallo == 1);
    if(intentos == 0){
        centrar_texto(30); printf("Has fallado todos los intentos\n");
        sesion=0;
        getch();
    }
    else{
        sesion=1;
    }

    return sesion;
}


//Funcion que ejecuta la opcion seleccionada del menu principal, dependiendo si hay o no un pin asignado
//ENTRADA:
//@opcion: es el numero de opcion que se ha seleccionado
void ejecutar_opcion_menu_principal(int opcion){
    int sesion = 0, opcionABC; 
    if(existePin != 1){
        if(opcion == 0){
            crear_pin();
        }
        else if (opcion == totalOpcMenuPrin){
            salida=1;
        }
    }
    else{
        if(opcion == 0){
            sesion = iniciar_sesion();
            if(sesion != 0){
                do{
                    system("cls");
                    opcionABC = menu_abc();
                    ejecutar_opcion_menu_abc(opcionABC);
                }
                while(salidaABC==0);
            }
            else{
                exit(0);
            }
        }
        else if(opcion == totalOpcMenuPrin-2){
            //print_pin();
        }
        else if (opcion == totalOpcMenuPrin){
            salida=1;
        }
    }
    
}

//Funcion para esconder el puntero del cursor (donde se esta escribiendo el texto)
void esconder_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
//funcion para cambiar de color el texto
//ENTRADA:
//@color: es el codigo del color que se quiere
void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}