#include <stdio.h>
#include <math.h>

#define MAX_CATEGORIAS 20

// ============================================================
// EJERCICIO 1: Calcular chi-cuadrado manualmente
// ============================================================
// Dado un array de frecuencias observadas y otro de frecuencias
// esperadas, calcular el estadistico chi-cuadrado.
//
// Formula: chi2 = SUMA( (obs[i] - esp[i])^2 / esp[i] )
//
// Parametros:
//   observadas[] - frecuencias observadas en cada categoria
//   esperadas[]  - frecuencias esperadas en cada categoria
//   n            - numero de categorias
//
// Retorna: el valor chi-cuadrado
// ============================================================
float calcular_chi_cuadrado(float observadas[], float esperadas[], int n)
{
    float chi2 = 0.0;

    // TODO: Implementar
    // Pista: Recorrer cada categoria y acumular (obs - esp)^2 / esp

    return chi2;
}

// ============================================================
// EJERCICIO 2: Calcular frecuencias esperadas con distribucion uniforme
// ============================================================
// Si la hipotesis nula dice que todas las categorias son igual de
// probables, la frecuencia esperada es: total / numero_categorias
//
// Parametros:
//   observadas[] - frecuencias observadas
//   esperadas[]  - aqui se guarda el resultado
//   n            - numero de categorias
//
// Retorna: nada (modifica esperadas[] por referencia)
// ============================================================
void frecuencias_esperadas_uniforme(float observadas[], float esperadas[], int n)
{
    float total = 0;

    // TODO: Calcular el total de observaciones

    // TODO: Asignar a cada categoria: esperada = total / n
}

// ============================================================
// EJERCICIO 3: Calcular frecuencias esperadas con distribucion personalizada
// ============================================================
// Las probabilidades teoricas se pasan como parametro.
// frecuencia_esperada[i] = total_observaciones * probabilidad[i]
//
// Parametros:
//   observadas[]     - frecuencias observadas
//   probabilidades[] - probabilidad teorica de cada categoria (suman 1.0)
//   esperadas[]      - aqui se guarda el resultado
//   n                - numero de categorias
//
// Retorna: nada (modifica esperadas[] por referencia)
// ============================================================
void frecuencias_esperadas_personalizadas(float observadas[], float probabilidades[], 
                                          float esperadas[], int n)
{
    float total = 0;

    // TODO: Calcular el total de observaciones

    // TODO: Para cada categoria: esperada[i] = total * probabilidad[i]
}

// ============================================================
// EJERCICIO 4: Encontrar valor critico de chi-cuadrado
// ============================================================
// Tabla simplificada de valores criticos (nivel de significancia 0.05)
// Para otros niveles, se usaria una tabla completa o funcion estadistica
//
// Grados de libertad = numero_categorias - 1
//
// Parametros:
//   grados_libertad - numero de categorias - 1
//
// Retorna: el valor critico para alpha = 0.05
// ============================================================
float valor_critico_chi2(int grados_libertad)
{
    // TODO: Retornar el valor critico segun los grados de libertad
    // Tabla para alpha = 0.05:
    //   gl=1 -> 3.841
    //   gl=2 -> 5.991
    //   gl=3 -> 7.815
    //   gl=4 -> 9.488
    //   gl=5 -> 11.070
    //   gl=6 -> 12.592
    //   gl=7 -> 14.067
    //   gl=8 -> 15.507
    //   gl=9 -> 16.919
    //   gl=10 -> 18.307
    // Si el gl no esta en la tabla, retornar 0

    return 0;
}

// ============================================================
// EJERCICIO 5: Decidir si se rechaza la hipotesis nula
// ============================================================
// Si chi2_calculado > valor_critico, se rechaza H0
//
// Parametros:
//   chi2        - estadistico chi-cuadrado calculado
//   valor_crit  - valor critico de la tabla
//
// Retorna: 1 si se rechaza H0, 0 si se acepta
// ============================================================
int decidir_hipotesis(float chi2, float valor_crit)
{
    // TODO: Comparar y retornar decision

    return 0;
}

// ============================================================
// Funcion auxiliar: imprimir tabla comparativa
// ============================================================
void imprimir_tabla(float observadas[], float esperadas[], int n)
{
    printf("\n%-12s %-12s %-12s %-15s\n", "Categoria", "Observado", "Esperado", "(O-E)^2/E");
    printf("----------------------------------------------\n");
    
    float chi2 = 0;
    for (int i = 0; i < n; i++)
    {
        float diff = observadas[i] - esperadas[i];
        float termino = (diff * diff) / esperadas[i];
        chi2 += termino;
        printf("%-12d %-12.1f %-12.1f %-15.4f\n", i + 1, observadas[i], esperadas[i], termino);
    }
    printf("----------------------------------------------\n");
    printf("%-12s %-12s %-12s %-15.4f\n", "", "", "Chi2 =", chi2);
}

// ============================================================
// MAIN - Casos de prueba
// ============================================================
int main()
{
    printf("========================================\n");
    printf("  CALCULADORA DE CHI-CUADRADO\n");
    printf("  (Modo practica para examen)\n");
    printf("========================================\n");

    // --- CASO 1: Dados ---
    printf("\n--- CASO 1: Prueba de dados (60 lanzamientos) ---\n");
    printf("Hipotesis: Todos los resultados son igual de probables (1/6)\n\n");

    float observadas_dados[] = {8, 12, 10, 9, 11, 10};  // Frecuencias observadas
    float esperadas_dados[6];
    int num_categorias_dados = 6;

    // Calcular esperadas con distribucion uniforme
    frecuencias_esperadas_uniforme(observadas_dados, esperadas_dados, num_categorias_dados);

    // Imprimir tabla
    imprimir_tabla(observadas_dados, esperadas_dados, num_categorias_dados);

    // Calcular chi-cuadrado
    float chi2_dados = calcular_chi_cuadrado(observadas_dados, esperadas_dados, num_categorias_dados);
    int gl_dados = num_categorias_dados - 1;
    float critico_dados = valor_critico_chi2(gl_dados);
    int decision_dados = decidir_hipotesis(chi2_dados, critico_dados);

    printf("\nGrados de libertad: %d\n", gl_dados);
    printf("Valor critico (alpha=0.05): %.3f\n", critico_dados);
    printf("Chi2 calculado: %.4f\n", chi2_dados);
    printf("Decision: %s\n", decision_dados ? "Se rechaza H0" : "No se rechaza H0");


    // --- CASO 2: Colores de M&Ms ---
    printf("\n\n--- CASO 2: Colores de M&Ms ---\n");
    printf("Distribucion estandar chocolate:\n");
    printf("  Marron=13%%, Amarillo=14%%, Rojo=13%%, Naranja=20%%, Verde=16%%, Azul=24%%\n\n");

    float observadas_mms[] = {15, 12, 14, 22, 17, 20};  // Tu muestra
    float probabilidades[] = {0.13, 0.14, 0.13, 0.20, 0.16, 0.24};
    float esperadas_mms[6];
    int num_categorias_mms = 6;

    // Calcular esperadas con distribucion personalizada
    frecuencias_esperadas_personalizadas(observadas_mms, probabilidades, esperadas_mms, num_categorias_mms);

    // Imprimir tabla
    imprimir_tabla(observadas_mms, esperadas_mms, num_categorias_mms);

    // Calcular chi-cuadrado
    float chi2_mms = calcular_chi_cuadrado(observadas_mms, esperadas_mms, num_categorias_mms);
    int gl_mms = num_categorias_mms - 1;
    float critico_mms = valor_critico_chi2(gl_mms);
    int decision_mms = decidir_hipotesis(chi2_mms, critico_mms);

    printf("\nGrados de libertad: %d\n", gl_mms);
    printf("Valor critico (alpha=0.05): %.3f\n", critico_mms);
    printf("Chi2 calculado: %.4f\n", chi2_mms);
    printf("Decision: %s\n", decision_mms ? "Se rechaza H0" : "No se rechaza H0");


    // --- CASO 3: Dados con resultado esperado 7 ---
    printf("\n\n--- CASO 3: Suma de dados = 7 (60 lanzamientos) ---\n");
    printf("Hipotesis: La probabilidad de suma 7 es 1/6 (16.67%%)\n\n");

    float observadas_suma[] = {12, 48};  // suma=7, suma!=7
    float probabilidades_suma[] = {1.0/6.0, 5.0/6.0};
    float esperadas_suma[2];
    int num_categorias_suma = 2;

    frecuencias_esperadas_personalizadas(observadas_suma, probabilidades_suma, 
                                          esperadas_suma, num_categorias_suma);

    imprimir_tabla(observadas_suma, esperadas_suma, num_categorias_suma);

    float chi2_suma = calcular_chi_cuadrado(observadas_suma, esperadas_suma, num_categorias_suma);
    int gl_suma = num_categorias_suma - 1;
    float critico_suma = valor_critico_chi2(gl_suma);
    int decision_suma = decidir_hipotesis(chi2_suma, critico_suma);

    printf("\nGrados de libertad: %d\n", gl_suma);
    printf("Valor critico (alpha=0.05): %.3f\n", critico_suma);
    printf("Chi2 calculado: %.4f\n", chi2_suma);
    printf("Decision: %s\n", decision_suma ? "Se rechaza H0" : "No se rechaza H0");


    return 0;
}
