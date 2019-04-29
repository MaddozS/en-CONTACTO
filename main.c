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
int menu_principal(int opcion);
void imprimir_menu_principal();
void titulo();
void esconder_cursor();
void centrar_texto(int espacios);
void ejecutar_opcion_menu_principal(int opcion);

int posOpcion=0, i, salida=0, key=0;

int main(){
    int opcion, tecla = key;
    opcion = menu_principal_opciones();

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
                    posOpcion=3;
                }
                else{
                    posOpcion--;
                }
                break;
            case DOWN:
                if(posOpcion==3){
                    posOpcion=0;
                }
                else{
                    posOpcion++;
                }
                break;
            default:
                posOpcion=posOpcion;
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
    if(opcionSelec==0){color(4);} else{color(7);} 
    centrar_texto(14);
    printf("Iniciar sesi%cn\n", 162);
    //Cambio de color si la opcion esta seleccionada
    if(opcionSelec==1){color(4);} else{color(7);} 
    centrar_texto(8);
    printf("Opci%cn 2\n", 162);
    //Cambio de color si la opcion esta seleccionada
    if(opcionSelec==2){color(4);} else{color(7);}
    centrar_texto(8);
    printf("Opci%cn 3\n", 162);
    //Cambio de color si la opcion esta seleccionada
    if(opcionSelec==3){color(4);} else{color(7);}
    centrar_texto(18);
    printf("Salir del programa\n");
}
void ejecutar_opcion_menu_principal(int opcion){
    switch (opcion)
    {
        case 1:
        
        case 4:
            exit(0);
            break;
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