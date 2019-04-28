#include <stdio.h>
#include <Windows.h>
#include <conio.h>
//definicion del numero de las flechas
#define UP 72
#define DOWN 80
#define BLOCK 219

//funcion para cambiar de color el texto
void color(char color);
int menu_principal(int opcion);
void imprimir_menu_principal(int opcionSelec);
void titulo();
void esconder_cursor();
int i=0;
int main(){
    int key=0, exit=0, opcion;

    do{ 
        esconder_cursor();
        titulo();
        opcion = menu_principal_opciones(key);
        imprimir_menu_principal(opcion);
        
        key = getch();
        system("cls");
    }
    while(exit!=1);
    return 0;
}
int menu_principal_opciones(int opcion){
    switch (opcion){
        case UP:
            if(i==0){
                i=3;
            }
            else{
                i--;
            }
            break;
        case DOWN:
            if(i==3){
                i=0;
            }
            else{
                i++;
            }
            break;
    }
    return i;
}
void titulo(){
    color(6);
    printf("   __    __        ___   ___    __  _____  _      ___  _____  ___ \n");
    printf("  /__\\/\\ \\ \\      / __\\ /___\\/\\ \\ \\/__   \\/_\\    / __\\/__   \\/___\\\n");
    printf(" /_\\ /  \\/ /____ / /   //  //  \\/ /  / /\\//_\\\\  / /     / /\\//  //\n");
    printf("//__/ /\\  /_____/ /___/ \\_// /\\  /  / / /  _  \\/ /___  / / / \\_// \n");
    printf("\\__/\\_\\ \\/      \\____/\\___/\\_\\ \\/   \\/  \\_/ \\_/\\____/  \\/  \\___/  \n");
}
void imprimir_menu_principal(int opcionSelec){
    if(opcionSelec==0){
        color(4);
    }
    else{
        color(7);
    }
    printf("\nOpci%cn 1", 162);
    if(opcionSelec==1){
        color(4);
    }
    else{
        color(7);
    }
    printf("\nOpci%cn 2", 162);
    if(opcionSelec==2){
        color(4);
    }
    else{
        color(7);
    }
    printf("\nOpci%cn 3", 162);
    if(opcionSelec==3){
        color(4);
    }
    else{
        color(7);
    }
    printf("\nOpci%cn 4", 162);
}


void esconder_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}