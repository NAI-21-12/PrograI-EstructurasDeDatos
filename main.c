#include <stdio.h>

struct país{
    struct país* sigt;
    int nombre;
    int problema1;
    int problema2;
    struct país* ant;
};

struct lista{
    struct país* inicio;
    struct país* final;
};

struct país* crearPaís(int nombre, int problema1, int problema2){
    struct país* nuevoPaís = calloc(1,sizeof(struct país));
    if (nuevoPaís != NULL){
        nuevoPaís->nombre = nombre;
        nuevoPaís->problema1 = problema1;
        nuevoPaís->problema2 = problema2;
        nuevoPaís->sigt = NULL;
        nuevoPaís->ant = NULL;
    }
    return nuevoPaís;
};



//Función main que corre el programa
int main(){
    printf("Proyecto de Estructuras de Datos\n");
    return 0;
}

