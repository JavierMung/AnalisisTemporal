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
int BusquedaBinaria(int n, int toSearch, int numeros[]);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int i,j,h; //Variables para loops
int temporal;  
int contador=1;//contador para el llenado del arreglo
int *bin;//arreglo nuevo para el ordenamiento
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{
        //******************************************************************    
        //Variables del main
        //******************************************************************    
        double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
        FILE *f;  //APuntador al fichero
        // struct Nodo *raiz;
	    int n;  //n determina el tamaño del algorito dado por argumento al ejecutar
        int *numeros;
        int toSearch; //Valor a buscar
        //******************************************************************    
        //Recepción y decodificación de argumentos
        //******************************************************************    

        //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
        if (argc < 3)
        {
                printf("\nIndique el tamanio del algoritmo y valor a buscar - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
                exit(1);
        }
        //Tomar el segundo argumento como tamaño del algoritmo
        else
        {
                n=atoi(argv[1]);
                toSearch = atoi(argv[2]);
        }

        numeros = (int *)calloc(n,sizeof(int)); //Funcion calloc para el arreglo dinamico
	    bin = (int *)calloc(n,sizeof(int)); //Funcion calloc para el arreglo dinamico

        if(numeros==NULL){
                perror("ERROR AL RESERVAR MEMORIA");
                exit(-2);
        }else{
                f=fopen("10millones.txt", "r");
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


         //******************************************************************    
        ////Iniciar el conteo del tiempo para las evaluaciones de rendimiento 
        ////******************************************************************  
        uswtime(&utime0, &stime0, &wtime0);
        //******************************************************************

        //******************************************************************    
        //Algoritmo
        //******************************************************************    

        		
		printf("Valor: %d \tPosición: %d\n", toSearch, BusquedaBinaria(n, toSearch, numeros));    
       
        

        //******************************************************************

        //******************************************************************    
        //Evaluar los tiempos de ejecución 
        //******************************************************************
        uswtime(&utime1, &stime1, &wtime1);

        //Cálculo del tiempo de ejecución del programa
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
        /*printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");

        //Mostrar los tiempos en formato exponecial
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        */
        printf("\n");
        //******************************************************************

        //Terminar programa normalmente 
        exit (0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
int BusquedaBinaria(int n, int toSearch, int numeros[]){
    int inicio = 0, fin = n-1, mitad = (inicio+fin)/2;

    while(inicio <= fin){
        if(numeros[mitad] < toSearch)
            inicio = mitad + 1;
        else if(numeros[mitad] == toSearch)
            return mitad+1;
        else
            fin = mitad - 1;

        mitad = (inicio+fin)/2;
    }

    return -1;
}