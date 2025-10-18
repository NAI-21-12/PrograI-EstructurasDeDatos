#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

struct país{
    struct país* sigt;
    char* nombre;
    char* problema1;
    int problema1Valor;
    char* problema2;
    int problema2Valor;

    /*
    Para ver si está activo, muerto o inactivo
    0 = inactivo, valores de problemas en 0
    1 = activo, valores de problemas suben
    2 = muerto, muerto
    */
    int estado;
    struct país* ant;
};

struct lista{
    struct país* inicio;
    struct país* jugador1;
    struct país* jugador2;
    struct país* final;
};

struct país* crearPaís(char* nombre, char* problema1, int problema1Valor, char* problema2, int problema2Valor, int estado){
    
    struct país* nuevoPaís = calloc(1,sizeof(struct país));
    if (nuevoPaís != NULL){
        nuevoPaís->nombre = nombre;
        nuevoPaís->problema1 = problema1;
        nuevoPaís->problema1Valor = problema1Valor;
        nuevoPaís->problema2 = problema2;
        nuevoPaís->problema2Valor = problema2Valor;
        nuevoPaís->estado = estado;
        nuevoPaís->sigt = NULL;
        nuevoPaís->ant = NULL;
    }
    return nuevoPaís;
};

int imprimirPaíses(struct lista* lista){
    struct país* actual = lista->inicio;
    while (actual != NULL){
        if(actual -> estado == 0){
            printf("País: %s\n",actual->nombre);
            printf("\n");
        } else if(actual->estado == 2){
            printf("País: %s         Eliminado\n",actual->nombre);
        }else {
            printf("País: %s, Problema 1: %s, Problema 2: %s\n",actual->nombre,actual->problema1,actual->problema2);
            printf("                 Nivel: %d,              Nivel: %d\n",actual->problema1Valor,actual->problema2Valor);
            printf("\n");
        }
        actual = actual->sigt;
    }
    return 0;
}


int insertarFinal(struct lista* lista, char* nombre, char* problema1, int problema1Valor, char* problema2, int problema2Valor, int estado){
    struct país* nuevoPaís = crearPaís(nombre,problema1,problema1Valor,problema2,problema2Valor,estado);
    struct país* actual = lista-> inicio;

    if (lista->inicio == NULL){
        lista->inicio = nuevoPaís;
        lista->final = nuevoPaís;
        return 0;
    }

    lista->final->sigt = nuevoPaís;
    nuevoPaís->ant = lista->final;
    lista->final = nuevoPaís;
    
    return 0;
}


void crearListaPaíses(struct lista* países){
    //ESTOS SON PROBLEMAS DE EJEMPLO, LA IDEA ES CAMBIARLOS DESPUÉS
    insertarFinal(países,"México","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Cuba","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Guatemala","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Belice","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Jamaica","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Haití","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"República Dominicana","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Puerto Rico","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"El Salvador","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Honduras","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Nicaragua","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Costa Rica","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Panamá","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Colombia","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Venezuela","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Guyanas","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Ecuador","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Perú","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Brasil","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Bolivia","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Paraguay","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Uruguay","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Chile","Corrupción",0,"Muerte",0,0);
    insertarFinal(países,"Argentina","Corrupción",0,"Muerte",0,0);
}





void activarIniciales(struct lista* países){
    //Genera los países que van a estar activos inicialmente
    //25 para que el índice concida, son 24 países, se ignora el 0
    bool escogidos[25] = {false};

    int generados = 0;
    int númeroActual;
    struct país* actual = países->inicio;

    while(generados < 9){
        //24 porque son 24 países, es el rango máximo
        númeroActual = (rand()%24)+1;

        if(escogidos[númeroActual] == false){
            generados++;
            escogidos[númeroActual] = true;
        }
    
    }

    //Para activar los países random
    int índice = 1;
    int cuenta = 8;
    while(actual != NULL){

        if(escogidos[índice] == true){
            actual->estado = 1;
        if(cuenta > 5){
            actual->problema1Valor = 3;
            actual->problema2Valor = 2;
            cuenta--;
        }else if(cuenta > 2){
            actual->problema1Valor = 2;
            actual->problema2Valor = 1;
            cuenta--;
        }else{
            actual->problema1Valor = 1;
            actual->problema2Valor = 1;
            cuenta--;
        }
        
        }
        índice++;


        actual = actual->sigt;
    }    

}

void aumentarProblemas(struct lista* países){
    //esto aumenta los problemas en un país aleatorio
    int aumentado = 0;
    //Este while es para que sí o sí aumente un valor en alguno
    while(aumentado == 0){
        int paísSalado = (rand() % (23 - 0 + 1)) + 0;
        struct país* actual = países->inicio;
        int índice = 0;
        //si es 1, sube problema1, si es 2, sube problema2
        int valorASubir = (rand() % (2 - 1 + 1)) + 1;
        while(índice < 23){
            if(índice == paísSalado && actual->estado == 1){

                //Para problema1
                if( valorASubir == 1){
                    //Si no es 3
                    if(actual->problema1Valor < 3){
                        actual->problema1Valor++;
                        aumentado++;
                    }

                    //ahora sí, problemas.
                    //si es 3
                    if(actual->problema1Valor == 3){
                        if(índice == 0 && actual->sigt->problema1Valor != 3){
                            actual->sigt->problema1Valor++;
                            aumentado++;
                        } else if(índice == 23 && actual->ant->problema1Valor != 3){
                            actual->ant->problema1Valor++;
                            aumentado++;
                        } else{
                            if(actual->sigt->problema1Valor != 3){
                                actual->sigt->problema1Valor++;
                                aumentado++;
                            }
                            if(actual->ant->problema1Valor != 3){
                                actual->ant->problema1Valor++;
                                aumentado++;
                            }
                        }
                    }

                }

                //Ahora para problema2
                if( valorASubir == 2){
                    //Si no es 3
                    if(actual->problema2Valor < 3){
                        actual->problema2Valor++;
                        aumentado++;
                    }

                    //ahora sí, problemas.
                    //si es 3
                    if(actual->problema2Valor == 3){
                        if(índice == 0 && actual->sigt->problema2Valor != 3){
                            actual->sigt->problema2Valor++;
                            aumentado++;
                        } else if(índice == 23 && actual->ant->problema2Valor != 3){
                            actual->ant->problema2Valor++;
                            aumentado++;
                        } else{
                            if(actual->sigt->problema2Valor != 3){
                                actual->sigt->problema2Valor++;
                                aumentado++;
                            }
                            if(actual->ant->problema2Valor != 3){
                                actual->ant->problema2Valor++;
                                aumentado++;
                            }
                        }
                    }

                }

            }
        índice++;
        actual = actual->sigt;
        }
    }
}



int activarNuevo(struct lista* países){
    //activa un país que no lo estaba
    int activado = 0;
    //Si se repite 20 veces y no se activa ninguno, queda así
    //Para eso este valor
    int contador = 0;
    //Este while es para que sí o sí aumente un valor en alguno
    while(activado == 0){
        int paísSalado = (rand() % (23 - 0 + 1)) + 0;
        struct país* actual = países->inicio;
        int índice = 0;
        //si es 1, sube problema1, si es 2, sube problema2
        int valorASubir = (rand() % (2 - 1 + 1)) + 1;
        while(índice < 23){
            if(índice == paísSalado && actual->estado == 0){

                //Para problema1
                if( valorASubir == 1){
                    actual->estado = 1;
                    actual->problema1Valor++;
                    activado++;
                    return 0;
                }

                //Ahora para problema2
                if( valorASubir == 2){
                    actual->estado = 0;
                    actual->problema2Valor++;
                    activado++;
                    return 0;
            }
        }
        índice++;
        actual = actual->sigt;
        contador++;
    }
    if(contador == 20){
        return 0;
    }
    }
}

void paísEliminado(struct lista* países){
    //Pone un país en eliminado
    //Para esto, mejor no borrarlo de la lista para evitar enredos
    //Con otras funciones

    struct país* actual = países->inicio;

    while(actual->sigt != NULL){
        if(actual->problema1Valor == 3 && actual->problema2Valor == 3){
            actual->estado = 2;
        }
        actual = actual->sigt;
    }
}


//Función main que corre el programa
int main(){
    //Para el random, dejar acá arriba
    //un número random se genera así:
    // int numero_random = (rand() % (max - min + 1)) + min;
    srand(time(NULL));
    struct lista países = {NULL,NULL};
    crearListaPaíses(&países);
    activarIniciales(&países);
    imprimirPaíses(&países);
    return 0;
}
