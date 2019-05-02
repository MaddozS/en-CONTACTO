#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
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
void verificar_pin();
void iniciar_sesion();

int posOpcion=0, i, salida=0, key=0, pinAsignado=0, size, numeroOpciones=3, opcion;
FILE *pinArchivo;

int main(){
    //funcion para verificar si ya hay un pin generado
    verificar_pin();
    //Funcion que imprime las opciones
    opcion = menu_principal_opciones();
    //Funcion ejecuta la opcion seleccionada
    ejecutar_opcion_menu_principal(opcion);
    return 0;
}
//funcion para cambiar de opcion seleccionada, usando las flechas del teclado
int menu_principal_opciones(){
    do{
        system("cls");
        printf("%d\n", key);
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
    centrar_texto(68);
    printf("   __    __        ___   ___    __  _____  _      ___  _____  ___ \n");
    centrar_texto(68);
    printf("  /__\\/\\ \\ \\      / __\\ /___\\/\\ \\ \\/__   \\/_\\    / __\\/__   \\/___\\\n");
    centrar_texto(68);
    printf(" /_\\ /  \\/ /____ / /   //  //  \\/ /  / /\\//_\\\\  / /     / /\\//  //\n");
    centrar_texto(68);
    printf("//__/ /\\  /_____/ /___/ \\_// /\\  /  / / /  _  \\/ /___  / / / \\_// \n");
    centrar_texto(68);
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
        if(opcionSelec == numeroOpciones-3){color(4);} else{color(7);} 
        centrar_texto(15);
        printf("Iniciar sesi%cn\n", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSelec == numeroOpciones-2){color(4);} else{color(7);} 
        centrar_texto(9);
        printf("Opci%cn 2\n", 162);
        //Cambio de color si la opcion esta seleccionada
        if(opcionSelec == numeroOpciones-1){color(4);} else{color(7);}
        centrar_texto(9);
        printf("Opci%cn 3\n", 162);
    }
    else{
        if(opcionSelec == 0){color(4);} else{color(7);} 
        centrar_texto(10);
        printf("Crear PIN\n");
    }
    //Cambio de color si la opcion esta seleccionada
    if(opcionSelec == numeroOpciones){color(4);} else{color(7);}
    centrar_texto(19);
    printf("Salir del programa\n");
}
void crear_pin(){
    char pinUsuario[5];
    system("cls");
    pinArchivo = fopen("pin.txt", "w+");
    color(6);
    printf("Ingresa PIN con el que vas a proteger tus contactos (de 4 digitos): ");
    color(7);
    fflush(stdin);
    gets(pinUsuario);
    fputs(pinUsuario, pinArchivo);
    fflush(pinArchivo);
    fclose(pinArchivo);
    printf("\n");
    centrar_texto(22); printf("PIN Creado con exito!", 130);
    centrar_texto(54); printf("Pulsa cualquier tecla para regresar al menu principal");
    //"Regreso" al menu principal

    //funcion para verificar si ya hay un pin generado
    verificar_pin();
    //Funcion que imprime las opciones
    opcion = menu_principal_opciones();
    //Funcion ejecuta la opcion seleccionada
    ejecutar_opcion_menu_principal(opcion);
    
}
void verificar_pin(){
    pinArchivo = fopen("pin.txt", "r");
    if (pinArchivo != NULL) {
        fseek (pinArchivo, 0, SEEK_END);
        size = ftell(pinArchivo);
        if (size != 0) {
            pinAsignado=1;
            numeroOpciones=3;
        }
    }
    else{
        pinAsignado=0;
        numeroOpciones=1;
    }
    fclose(pinArchivo);
}
void iniciar_sesion(){
    // system("cls");
    // pin = fopen("pin.txt", "r");
    // if (pin != NULL){
    //     printf("No hay ningun pin asignado\n");
    // }
    // else{
    //     printf("no se puede abrir el archivo\n");
    // }
}
void ejecutar_opcion_menu_principal(int opcion){
    if(opcion == 0){
        if(pinAsignado==1){
            iniciar_sesion();
        }
        else{
            crear_pin();
        }
    }
    else if (opcion == numeroOpciones){
        exit(0);
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