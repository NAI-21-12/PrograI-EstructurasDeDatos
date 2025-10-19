#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct país{
    struct país* sigt;
    struct país* ant;
    char* nombre;
    char* problema1;
    int problema1Valor;
    char* problema2;
    int problema2Valor;
    int jugador1;
    int jugador2;

    /*
    Para ver si está activo, muerto o inactivo
    0 = inactivo, valores de problemas en 0
    1 = activo, valores de problemas suben
    2 = muerto, muerto
    */
    int estado;
};

struct lista{
    struct país* inicio;
    struct país* final;
};


char* crearJugador(int número){
	int tamaño = 10;
	char* nuevoJugador = calloc(tamaño + 1, sizeof(char));
	char decisión  = '\0';
	
	if(número != 1){
		printf("\n");
	}
	
	printf("¡Bienvenido jugador %d!\n%s%d%s", número,
	       "¿Cuál es tu nombre? (Máximo ", tamaño, " letras sin espacios)\n");
	
	while(scanf("%[^\n]%*c", nuevoJugador) == 0){
		getchar();
	}

	nuevoJugador[tamaño] = '\0';
	printf("\nUn placer en conocerte %s\n", nuevoJugador);
	
	printf("%s\n", "¿Te informo de la situación actual (y/n)? (Leer las reglas)");
	scanf("%[^\n]%*c", &decisión);
	if(decisión == 'y' || decisión == 'Y'){
		printf("%s\n", "\n¡AQUÍ VA UNA INTRODUCCIÓN AL JUEGO PORQUE ES AURELIO!");
		
		printf("\nPresione ENTER para continuar");
		while(getchar() != '\n'){}
		
	} else if(decisión == 'n' || decisión == 'N'){
		printf("\nCool, buena suerte salvando el mundo!\n");
		
		printf("\nPresione ENTER para continuar");
		while(getchar() != '\n'){}
		
	} else{
		printf("\nGenial, me salió inteligente. No tengo que explicar nada.\n");
		
		printf("\nPresione ENTER para continuar");
		while(getchar() != '\n'){}

	}
	return nuevoJugador;
}


struct país* crearPaís(char* nombre, char* problema1,
                       int problema1Valor, char* problema2,
                       int problema2Valor, int estado,
                       int jugador1, int jugador2){

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
        nuevoPaís->jugador1 = jugador1;
        nuevoPaís->jugador2 = jugador2;
    }
    return nuevoPaís;
};


/* 
 * Esto imprime la lista de países
 * E: Un struct lista*
 * S: Los países impresos en pantalla
 * R: Lista debe ser diferente de null
 */
int imprimirPaíses(struct lista* lista, char* jugador1, char* jugador2){
    struct país* actual = lista->inicio;

    while (actual->sigt != NULL){
        if(actual -> estado == 0){
            printf("País: %s\t\t\tTodo bien\n",actual->nombre);
            
            if(actual->jugador1 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador1);
				
			} 
			if(actual->jugador2 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador2);
				
			}
			
            printf("\n---------------Frontera: %s/%s----------------\n\n",
                   actual->nombre, actual->sigt->nombre);
            
        } else if(actual->estado == 2){
            printf("País: %s\t\t\tEliminado\n",actual->nombre);
                        
            if(actual->jugador1 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador1);
				
			}
			if(actual->jugador2 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador2);
				
			}
			
            printf("\n---------------Frontera: %s/%s----------------\n\n",
                   actual->nombre, actual->sigt->nombre);
            
        }else {
            printf("País: %s\n", actual->nombre);
            printf("Problema 1: %s\t\tNivel: %d\n",
                   actual->problema1, actual->problema1Valor);
                   
            printf("Problema 2: %s\t\tNivel: %d\n",
                   actual->problema2, actual->problema2Valor);
                        
            if(actual->jugador1 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador1);
				
			}
			if(actual->jugador2 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador2);
				
			}
			
            printf("\n---------------Frontera: %s/%s----------------\n\n",
                   actual->nombre, actual->sigt->nombre);
                   
        }
        actual = actual->sigt;
    }
    
    //Caso final
    if(actual -> estado == 0){
        printf("País: %s\t\tTodo bien\n",actual->nombre);
        
        if(actual->jugador1 == 1){
			printf("\033[32m%s está aquí\033[0m\n", jugador1);
				
		} 
		if(actual->jugador2 == 1){
			printf("\033[32m%s está aquí\033[0m\n", jugador2);
				
		}
        
        printf("\n---------------Frontera: %s----------------\n\n",
               actual->nombre);
            
    } else if(actual->estado == 2){
        printf("País: %s\t\tEliminado\n",actual->nombre);
        
        if(actual->jugador1 == 1){
			printf("\033[32m%s está aquí\033[0m\n", jugador1);
				
		} 
		if(actual->jugador2 == 1){
			printf("\033[32m%s está aquí\033[0m\n", jugador2);
				
		}
		
        printf("\n---------------Frontera: %s----------------\n\n",
               actual->nombre);

            
    }else {
            printf("País: %s\n", actual->nombre);
            printf("Problema 1: %s\t\tNivel: %d\n",
                   actual->problema1, actual->problema1Valor);
                   
            printf("Problema 2: %s\t\tNivel: %d\n",
                   actual->problema2, actual->problema2Valor);
                   
            if(actual->jugador1 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador1);
				
			} 
			if(actual->jugador2 == 1){
				printf("\033[32m%s está aquí\033[0m\n", jugador2);
				
			}
            printf("\n---------------Frontera: %s----------------\n\n",
               actual->nombre);
        }
    return 0;
}


int insertarFinal(struct lista* lista, char* nombre, char* problema1,
                  int problema1Valor, char* problema2,
                  int problema2Valor, int estado,
                  int jugador1, int jugador2){

    struct país* nuevoPaís = crearPaís(nombre,problema1,problema1Valor,problema2,problema2Valor,estado,jugador1,jugador2);
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
    insertarFinal(países,"México","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Cuba","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Guatemala","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Belice","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Jamaica","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Haití","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"República Dominicana","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Puerto Rico","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"El Salvador","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Honduras","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Nicaragua","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Costa Rica","Corrupción",0,"Muerte",0,0,1,1);
    insertarFinal(países,"Panamá","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Colombia","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Venezuela","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Guyanas","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Ecuador","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Perú","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Brasil","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Bolivia","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Paraguay","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Uruguay","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Chile","Corrupción",0,"Muerte",0,0,0,0);
    insertarFinal(países,"Argentina","Corrupción",0,"Muerte",0,0,0,0);
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
				
			} else if(cuenta > 2){
				actual->problema1Valor = 2;
				actual->problema2Valor = 1;
				cuenta--;
				
			} else{
				actual->problema1Valor = 1;
				actual->problema2Valor = 1;
				cuenta--;
				
			}
        }
 
        índice++;
        actual = actual->sigt;
    }    
}


/* IDEA
 * Ponerle un parámetro extra a esta función con el paísSalado desde fuera y hacerla
 * tipo recursiva para no tener 100 ifs y para poder extenderla todo lo
 * que haga falta hacia los lados con recursividad y un puntero al
 * vecino que haya que infectar
 */
void aumentarProblemas(struct lista* países){
    //esto aumenta los problemas en un país aleatorio
    int aumentado = 0;
    //Este while es para que sí o sí aumente un valor en alguno
    while(aumentado == 0){
        int paísSalado = (rand() % 24);	//paísSalado 💀
        struct país* actual = países->inicio;
        int índice = 0;
        
        //si es 1, sube problema1, si es 2, sube problema2
        int valorASubir = (rand() % (2)) + 1;
        while(índice < 23){
            if(índice == paísSalado && actual->estado == 1){

                //Para problema1
                if(valorASubir == 1){
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
                                
                            }else if(actual->ant->problema1Valor != 3){
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

				// Parte que puede funcionar como activarNuevo
            } else if(índice == paísSalado && actual->estado == 0){
				if(valorASubir == 1){
					actual->estado = 1;
					actual->problema1Valor++;
					
				} else {
					actual->estado = 1;
					actual->problema2Valor++;
				}
			}
        índice++;
        actual = actual->sigt;
        }
    }
}


/*
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
}*/

void paísEliminado(struct lista* países){
    //Pone un país en eliminado
    //Para esto, mejor no borrarlo de la lista para evitar enredos
    //Con otras funciones

    struct país* actual = países->inicio;

    while(actual->sigt != NULL){
        if(actual->problema1Valor == 3 && actual->problema2Valor == 3){
			printf("El país %s ha sido eliminado.\n", actual -> nombre);
			while(getchar() != '\n'){}
            actual -> estado = 2;
            actual -> problema1Valor = -1;
            actual -> problema2Valor = -1;
            
        }
        actual = actual->sigt;
    }
}


int ayudarPaís(struct lista* países, int numJugador){
    /*
    Casos posibles:
    - país muerto o inactivo                       devuelve 1
    - que un valor sea 0 y trate de disminuirlo    devuelve 1
    - opción inválida                              devuelve 1
    - un caso normal                               devuelve 0
    */
    struct país* actual = países->inicio;
    int decisión;
    //Busca los jugadores en la lista
	if(numJugador == 1){
		while(actual->jugador1 != 1){
			actual = actual->sigt;
		}

	} else if(numJugador == 2){
		while(actual->jugador2 != 1){
			actual = actual->sigt;
		}
	}

    //Caso 1: país muerto o inactivo
    if(actual->estado == 1 || actual->estado == 0){
        printf("\033[31mPaís no válido\033[0m\n");
        return 1;
    }

    printf("%s ¿Qué tipo de proyecto quiere realizar? 1 o 2.\n");

	scanf("%d", &decisión);
    if(decisión == 1){
        if(actual->problema1Valor == 0){
            printf("El valor del problema 1 ya estaba en 0.\n");
            return 1;
        } else{
            printf("Ha disminuido el valor del problema 1 en un nivel.\n");
            actual->problema1Valor--;
            return 0;
        }
    } else if(decisión == 2){
        if(actual->problema2Valor == 0){
            printf("El valor del problema 2 ya estaba en 0.\n");
            return 1;
        } else{
            printf("Ha disminuido el valor del problema 2 en un nivel.\n");
            actual->problema2Valor--;
            return 0;
        }
    } else {
        printf("Esa no es una opción válida.\n");
        return 1;
    }
}




int turnoJugador(int numJugador, char* jugador, struct lista* países, int acciones){
	struct país* actual = países->inicio;
	int decisión;
    //Para ver si sí hizo bien el aporte al país
	int resultadoAyuda = 0;
    //Busca los jugadores en la lista
	if(numJugador == 1){
		while(actual->jugador1 != 1){
			actual = actual->sigt;
		}

	} else if(numJugador == 2){
		while(actual->jugador2 != 1){
			actual = actual->sigt;
		}
	}

	printf("%s ¿Qué deseas realizar ahora? (Te quedan %d acciones)\n%s%s%s",
	       jugador, acciones, "1. Moverse al país vecino norte\n",
	       "2. Moverse al país vecino sur\n", "3. Implementar un proyecto aquí\n");

	scanf("%d", &decisión);
	
	if (actual->nombre == "México"){
		if(decisión == 1 && numJugador == 1){
			printf("México no tiene vecinos norte, perdiste tu tiempo y un turno\n");
		
		} else if(decisión == 2 && numJugador == 1){
			actual->sigt->jugador1 = 1;
			actual->jugador1 = 0;
		
		} else	if(decisión == 1 && numJugador == 2){
			printf("México no tiene vecinos norte, perdiste tu tiempo y un turno\n");
		
		} else if(decisión == 2 && numJugador == 2){
			actual->sigt->jugador2 = 1;
			actual->jugador2 = 0;
	
		} else if(decisión == 3){
            //Si da error la función esta, se repite
            if(ayudarPaís(&países,numJugador) == 1){
                turnoJugador(numJugador,jugador,&países,acciones);
            }
				
		} else{
			printf("Esa opción no es válida, perdiste tu turno\n");
		}
			
	} else if (actual->nombre == "Argentina"){
		if(decisión == 1 && numJugador == 1){
			actual->ant->jugador1 = 1;
			actual->jugador1 = 0;
		
		} else if(decisión == 2 && numJugador == 1){
			printf("Argentina no tiene vecinos sur, perdiste tu tiempo y un turno\n");
		
		} else if(decisión == 1 && numJugador == 2){
			actual->ant->jugador2 = 1;
			actual->jugador2 = 0;
		
		} else if(decisión == 2 && numJugador == 2){
			printf("Argentina no tiene vecinos sur, perdiste tu tiempo y un turno\n");
		
		} else if(decisión == 3){
			//Si da error la función esta, se repite
            if(ayudarPaís(&países,numJugador) == 1){
                turnoJugador(numJugador,jugador,&países,acciones);
            }	
		} else{
			printf("Esa opción no es válida, perdiste tu turno\n");
		}
			
	} else{
		if(decisión == 1 && numJugador == 1){
			actual->ant->jugador1 = 1;
			actual->jugador1 = 0;
		
		} else if(decisión == 2 && numJugador == 1){
			actual->sigt->jugador1 = 1;
			actual->jugador1 = 0;
		
		} else if(decisión == 1 && numJugador == 2){
			actual->ant->jugador2 = 1;
			actual->jugador2 = 0;
		
		} else if(decisión == 2 && numJugador == 2){
			actual->sigt->jugador2 = 1;
			actual->jugador2 = 0;
		
		} else if(decisión == 3){
			//Si da error la función esta, se repite
            if(ayudarPaís(&países,numJugador) == 1){
                turnoJugador(numJugador,jugador,&países,acciones);
            }
				
		} else{
			printf("Esa opción no es válida, perdiste tu turno\n");
		}
	}
		

	if(acciones == 1){
		return 0;
		
	} else{
		return turnoJugador(numJugador, jugador, países, acciones - 1);

	}
}


/*
 * Esto cuenta la cantidad de países que quedan vivos
 * E: Una lista
 * S: Un número entero positivo
 * R: Deben ingresar una lísta no vacía
 */
int contarVivos(struct lista* países){
	int vivos = 0;
	struct país* actual = países->inicio;
	
	while(actual -> sigt != NULL){
		if(actual->estado == 0 || actual->estado == 1){
			vivos++;
		}
		actual = actual->sigt;
	}
	
	//Caso final
	if(actual->estado == 0 || actual->estado == 1){
		vivos++;
	}
	return vivos;
}


/*
 * Esto cuenta la cantidad de problemas1 que tienen los países
 * E: Una lista
 * S: Un número entero positivo
 * R: Deben ingresar una lísta no vacía
 */
int contarProblemas1(struct lista* países){
	int problemas = 0;
	struct país* actual = países->inicio;
	
	while(actual -> sigt != NULL){
		if(actual -> problema1Valor > 0){
			problemas += actual -> problema1Valor;
		}
		actual = actual->sigt;
	}
	
	//Caso final
	if(actual -> problema1Valor > 0){
		problemas += actual -> problema1Valor;
	}
	return problemas;
}


/*
 * Esto cuenta la cantidad de problemas2 que tienen los países
 * E: Una lista
 * S: Un número entero positivo
 * R: Deben ingresar una lísta no vacía
 */
int contarProblemas2(struct lista* países){
	int problemas = 0;
	struct país* actual = países->inicio;
	
	while(actual -> sigt != NULL){
		if(actual -> problema2Valor != 0){
			problemas += actual -> problema2Valor;
		}
		actual = actual->sigt;
	}
	
	//Caso final
	if(actual -> problema2Valor != 0){
		problemas += actual -> problema2Valor;
	}
	return problemas;
}


//Función main que corre el programa
int main(){
    //Para el random, dejar acá arriba
    //un número random se genera así:
    // int numero_random = (rand() % (max - min + 1)) + min;

    /*
    Orden: crearLista, activarIniciales, imprimir,
    turnoJugador1, aumentarProblemas, paísEliminado, turnoJugador2 (después de ciertos
    turnos, activarNuevo)
    */
    srand(time(NULL));
    struct lista países = {NULL,NULL};
    crearListaPaíses(&países);
    activarIniciales(&países);
    char* jugador1 = crearJugador(1);
    char* jugador2 = crearJugador(2);
    //Para pruebas sin introducción comentar esas 2 líneas y descomentar estas
    //char* jugador1 = "Jugador1";
    //char* jugador2 = "Jugador2";
    
    int ronda = 1;
    printf("\n");
    while(contarVivos(&países) > 3 && contarProblemas1(&países) != 0
          && contarProblemas2(&países) != 0){

		printf("\033[31mRonda: %d\033[0m\n%s\n", ronda,
		       "--------------------------------------------------");
		imprimirPaíses(&países, jugador1, jugador2);
		while(getchar() != '\n'){}
		turnoJugador(1, jugador1, &países, 4);
		turnoJugador(2, jugador2, &países, 4);
		aumentarProblemas(&países);
		paísEliminado(&países);
		ronda++;
	}
	
	if(contarVivos(&países) <= 3){
		printf("\n\033[31mPerdiste\033[0m\n");
		return 0;

	} else{
		printf("\n\033[32mGanaste\033[0m\n");
		return 0;
	}
}
