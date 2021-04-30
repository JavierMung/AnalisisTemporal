//*****************************************************************
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
struct Nodo *nuevoNodo(int);
void insertar(struct Nodo *,int);
void inorden(struct Nodo*);
void arbolbinario(int , int []);
struct Nodo* arbolbinarioBusqueda(struct Nodo*, int);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int i,j,h; //Variables para loops
int temporal;
int contador=1;//contador para el llenado del arreglo
int *bin;//arreglo nuevo para el ordenamiento
struct Nodo* raiz;

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[]){	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	FILE *f;  //APuntador al fichero
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
        int *numeros;
	int datos[20]={322486,14700764,3128036,6337399,61396,10393545,2147445644,125390003,450057883,187645041,1980098116,152503,5000,1493283650,214826,1843349527,1360839354,2109248666,2147470852,0};

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}


	numeros = (int *)calloc(n,sizeof(int)); //Funcion calloc para el arreglo dinamico
        bin = (int*)calloc(n,sizeof(int)); //Funcion calloc para el arreglo dinamico

        if(numeros==NULL){
                perror("ERROR AL RESERVAR MEMORIA");
                exit(-2);
        }else{
                f=fopen("/home/javier/Practica2/desordenados.txt", "r");
                if(f==NULL){
                perror("ERORR EN LA LECTURA DEL ARCHIVO");
                }else{
                        while(contador<=n){
                        fscanf(f,"%d",&numeros[h]);
                        h++;
                        contador++;
                        }
                }

        }
	arbolbinario(n,numeros);

	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	i = 0;
	for(i=0;i<20;i++){
		arbolbinarioBusqueda(raiz,datos[i]);
	}

	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	return 0;
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

//PRACTICA 2
//ANALISIS DE ALGORITMOS
//EQUIPO AA 29/04/2021
/*****       Juarez Vargas Leo Daniel 
	     Miranda Quijano Manuel Alejandro
	     Munguia Galeana Francisco Javier 	
******/

struct Nodo *nuevoNodo(int dato) { //FUNCION PARA CREAR UN NUEVO NODO
    struct Nodo *nodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    nodo->dato = dato; //Se le asigana el valor a la estructura
    nodo->izquierda = nodo->derecha = NULL; //SE CREAN LOS APUNTADORES A NULL
    return nodo;
}
void insertar(struct Nodo *nodo, int dato) { //FUNCION PARA INSERTAR LOS NUMEROS DESORDENADOS
    if (dato > nodo->dato) { //AQUI SE ELIGE EN QUE PARTE DEL ARBOL DERECHA O IZQUIERDA 
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            insertar(nodo->derecha, dato);
        }
    } else {
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            insertar(nodo->izquierda, dato);
        }
    }
}

void arbolbinario(int n, int numeros[]){ //FUNCION PRINCIPAL DEL ARBOL
        i=0;
        contador=0;
        raiz=nuevoNodo(numeros[i]); //SE CREA EL ARBOL CON EL PRIMER DATO DEL ARREGLO 
        while(i<n){
        	insertar(raiz,numeros[i]); //SE INSERTA EL NUMERO EN EL ARBOL
        	i++;
        }
}

struct Nodo* arbolbinarioBusqueda(struct Nodo* raiz, int dato){ // FUNCION QUE AYUDA A LA BUSQUEDA 

        if(raiz == NULL){
                return NULL;
        }else{
                if(dato == raiz->dato){
                        return raiz;
                }else{
                        if(dato < raiz->dato){
                                return arbolbinarioBusqueda(raiz->izquierda,dato);
                        }else{
                                return arbolbinarioBusqueda(raiz->derecha,dato);
                        }
                }
        }
	return NULL;
}
                                                                                                                                                
