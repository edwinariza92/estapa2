#include <stdio.h>


float calcular_chi(int observados[], float esperados[], int n){
    float valorChi =0;
    for(int i=0; i<n; i++){
        float desviacion =(observados[i]- esperados[i]);
        if(esperados[i] == 0){
            printf("El valor de esperado es 0, no se puede realizar");
            return 0;
        }
        valorChi += (float)((desviacion*desviacion)/esperados[i]);
    }
    return valorChi;
}

int main(){
    int n=0;
    int observados[100];
    float esperados[100];

    printf("Escriba la cantidad de datos: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Escriba el dato %d observado: ", i+1);
        scanf("%d", &observados[i]);
    }
    printf("Escriba 1 si dato esperado es uniforme (igual para todos)");
    int uniforme = 0; 
    scanf("%d", &uniforme);
    if(uniforme !=1){
        for(int i=0; i<n; i++){
            printf("Escriba el dato %d esperado: ", i+1);
            scanf("%f", &esperados[i]);
        }       
    }
    if(uniforme == 1){
        printf("Escriba el dato esperado para todos: ");
        scanf("%f", &esperados[0]);
        for(int i=0; i<n; i++){
            esperados[i] = esperados[0];
        }
    }
    printf("el valor Chi-Cuadrado Calculado es: %.4f\n", calcular_chi(observados, esperados, n));

    return 0;
}


