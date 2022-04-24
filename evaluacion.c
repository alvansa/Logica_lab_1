#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int *impl(unsigned int bin1, unsigned int bin2);

unsigned int **evaluar(unsigned int **matriz,unsigned int *prop,int cant);

unsigned int **asignar_matriz(int n, int m);                         // Reservar la memoria y crear una matriz nula

void imprimir_matriz(unsigned int **array, int filas, int columnas);
long elevado(int base,int potencia);
int contar_columnas(int cant);
int main(){

    unsigned int bin1 = 0b1,bin2 = 0b1,aux = 0b1;

    unsigned int **matriz;

    int filas,columnas;
    unsigned int *prop;
    int i,j,k,m ,cant_prep,rep = 1;
    //1 - 5 1 columna
    //6     2 columnas
    //7     4 columnas
    // 8    8 columnas

    columnas = 6;
    //prop = (int *)malloc(fil*sizeof(int));

    filas = contar_columnas(columnas);
    matriz = asignar_matriz(filas,columnas);
    
    printf("\nCantidad de columnas -> %i\n",columnas);
    /*
    for(int i = 0 ; i < columnas; i++){
        prop[i] = 0b1;
    }
    */
    cant_prep = elevado(2,columnas);
    /*
    //for(i = 0; i < cant; i++){
        for(j = 0; j < cant_prep/2; j++){
            matriz[0][0] = matriz[0][0] << 1;
            matriz[0][0] = matriz[0][0] | aux;
        }
    matriz[0][1] = matriz[0][1] << cant_prep / 2; 
    //}
    */
   m= 0;
    
    for(m = 0;m < filas; m++){
        for(k = 0; k < rep ; k++){
            for( i = 0;i < columnas;i++){            
                for(j = 0;j < cant_prep / 2; j++){
                    matriz[m][i] = matriz[m][i] << 1;
                    matriz[m][i] = matriz[m][i] | aux;
                }
                matriz[m][i] = matriz[m][i] << cant_prep / 2;
                
            }
            rep *= 2;
            cant_prep = cant_prep / 2;
        }
    }
    imprimir_matriz(matriz,filas,columnas);

    //printf("\nVariable 1 -> %u\nVarable 2 -> %u\n jajajajaj",matriz[0][0],matriz[0][1]);

    /*
    for(int i = 0 ; i < cant; i++){
        matriz[i][0] = 0b1;
    }
    imprimir_matriz(matriz,cant,columnas);
*/
    //matriz = evaluar(matriz,prop,cant);
    
}   


int *impl(unsigned int bin1, unsigned int bin2){



    return 0;
}


unsigned int **evaluar(unsigned int **matriz,unsigned int *prop,int cant){
    
    unsigned int aux;
    unsigned int p;
    int i,j,k;
    long cant_prep,rep;
    cant_prep = elevado(2,cant);
    aux = 0b1;
    rep = 1;
    printf("\n2 elvado a la cantidad -> %li\n",cant_prep);



    for(i = 0;i < cant; i++){
        for(k = 0; k < rep ; k++){
            for(j = 0;j < cant_prep / 2; j++){
                prop[i] = prop[i] << 1;
                prop[i] = prop[i] | aux;
            }
            prop[i] = prop[i] << cant_prep / 2;
            }
        rep *= 2;
        cant_prep = cant_prep / 2;
    }
    
    //11111111111111110000000000000000
    //11111111000000001111111100000000


    //10101010101010101010101010101010
    printf("\nproposicion 0 -> %u\nProposision 1 -> %u\nProposision 5 -> %u\n",prop[0],prop[1],prop[4]);

}   

long elevado(int base,int potencia){
    long resultado;
    int i;
    resultado = 1;
    for(i = 0;i < potencia ; i++)
        resultado *= base;
    return resultado;
}


int contar_columnas(int cant){
    int cont,col;
    if(cant < 6){
        return 1;
    }
    else{
        cont = cant - 5;
        col = elevado(2,cont);
        return col;
    }
}

unsigned int **asignar_matriz(int n, int m) //n filas, m columnas
{
    int i, j;
    unsigned int **array;
    array = (unsigned int **)calloc(n, sizeof(unsigned int *)); // se reserva memoria  para la matriz de x filas que contiene direcciones de memoria a las segundas dimensiones.
    if (array == NULL)
    {
        printf("\nMemoria alocada incorrectamente....\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        array[i] = (unsigned int *)malloc(m * sizeof(unsigned int)); // se reserva memoria para las segundas dimensiones , x columnas
    }
    if (array == NULL)
    {
        printf("\nMemoria alocada incorrectamente....\n");
        exit(0);
    }
    // en memoria ya tenemos reservado espacio para una matriz de x por x --> array[x][x]
    return &*array; // retorno de un puntero doble
}


void imprimir_matriz(unsigned int **array, int filas, int columnas)
{
    int i, j;
    printf("\nIMPRIMIENDO MATRIZ\n");
    printf("\n==================\n");
    for (i = 0; i < filas; i++)
    {
        printf("\n");
        for (j = 0; j < columnas; j++)
        {
            printf("%u ", array[i][j]);
        }
    }
}