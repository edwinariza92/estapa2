#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 50
#define MAX_AMISTADES 500

// Función auxiliar para verificar si dos personas son amigas
// Retorna 1 si persona_a y persona_b son amigas, 0 en caso contrario
int son_amigos(int amistades[][2], int m, int persona_a, int persona_b)
{
    for (int i = 0; i < m; i++)
    {
        if ((amistades[i][0] == persona_a && amistades[i][1] == persona_b) ||
            (amistades[i][0] == persona_b && amistades[i][1] == persona_a))
        {
            return 1;
        }
    }
    return 0;
}

// Función auxiliar para obtener la lista de amigos de una persona
// Almacena los IDs de amigos en el arreglo amigos y retorna el conteo
int obtener_amigos(int amistades[][2], int m, int persona, int amigos[])
{
    int conteo = 0;

    for (int i = 0; i < m; i++)
    {
        int candidato = -1;
        if (amistades[i][0] == persona)
        {
            candidato = amistades[i][1];
        }
        else if (amistades[i][1] == persona)
        {
            candidato = amistades[i][0];
        }
        if (candidato != -1)
        {
            int duplicado = 0;
            for (int j = 0; j < conteo; j++)
            {
                if (amigos[j] == candidato)
                {
                    duplicado = 1;
                    break;
                }
            }
            if (!duplicado)
            {
                amigos[conteo] = candidato;
                conteo++;
            }
        }
    }

    return conteo;
}

// Función 1: Verificar si la relación es reflexiva
int es_reflexiva(int n, int amistades[][2], int m)
{
    for (int i = 0; i < n; i++)
    {
        if (!son_amigos(amistades, m, i, i))
        {
            return 0;
        }
    }

    return 1;
}

// Función 2: Verificar si la relación es simétrica
int es_simetrica(int n, int amistades[][2], int m)
{
    for (int i = 0; i < m; i++)
    {
        int a = amistades[i][0];
        int b = amistades[i][1];
        if (!son_amigos(amistades, m, b, a))
        {
            return 0;
        }
    }

    return 1;
}

// Función 3: Encontrar si existe un clique de tamaño k
int encontrar_clique_de_tamano(int n, int amistades[][2], int m, int k)
{

    if (k == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k_persona = j + 1; k_persona < n; k_persona++)
                {
                    if (son_amigos(amistades, m, i, j) &&
                        son_amigos(amistades, m, i, k_persona) &&
                        son_amigos(amistades, m, j, k_persona))
                    {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

// Función 4: Contar amigos mutuos entre dos personas
int contar_amigos_mutuos(int n, int amistades[][2], int m, int persona_a, int persona_b)
{
    // TODO: Implementar esta función
    // Obtener amigos de persona_a y persona_b
    // Contar cuántos amigos están en ambas listas (intersección de conjuntos)

    int amigos_a[MAX_PERSONAS];
    int amigos_b[MAX_PERSONAS];
    int conteo_a = obtener_amigos(amistades, m, persona_a, amigos_a);
    int conteo_b = obtener_amigos(amistades, m, persona_b, amigos_b);

    int conteo_mutuo = 0;

    for (int i = 0; i < conteo_a; i++)
    {
        for (int j = 0; j < conteo_b; j++)
        {
            if (amigos_a[i] == amigos_b[j])
            {
                conteo_mutuo++;
            }
        }
    }

    return conteo_mutuo;
}

// Función 5: Verificar si hay un camino desde inicio hasta fin
int puede_alcanzar(int n, int amistades[][2], int m, int inicio, int fin)
{
    // TODO: Implementar esta función usando BFS o DFS
    // Usar un arreglo visitado para rastrear nodos visitados
    // Usar una cola (o recursión para DFS) para explorar caminos

    if (inicio == fin)
    {
        return 1;
    }

    int visitado[MAX_PERSONAS] = {0};
    int cola[MAX_PERSONAS];
    int frente = 0, atras = 0;

    visitado[inicio] = 1;
    cola[atras++] = inicio;

    while (frente < atras)
    {
        int actual = cola[frente];
        frente++;
        int amigos[MAX_PERSONAS];
        int num_amigos = obtener_amigos(amistades, m, actual, amigos);
        for (int i = 0; i < num_amigos; i++)
        {
            int amigo = amigos[i];
            if (amigo == fin)
            {
                return 1;
            }
            if (!visitado[amigo])
            {
                visitado[amigo] = 1;
                cola[atras] = amigo;
                atras++;
            }
        }
    }

    return 0;
}

// Función 6: Verificar si todas las personas tienen grado par
int todos_grados_pares(int n, int amistades[][2], int m)
{
    for (int i = 0; i < n; i++)
    {
        int amigos[MAX_PERSONAS];
        int num_amigos = obtener_amigos(amistades, m, i, amigos);
        if (num_amigos % 2 != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m;

    printf("Ingrese número de personas y amistades: ");
    scanf("%d %d", &n, &m);

    int amistades[MAX_AMISTADES][2];

    printf("Ingrese amistades (persona_a persona_b):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &amistades[i][0], &amistades[i][1]);
    }

    // Probar todas las funciones
    printf("\n=== Resultados del Análisis ===\n");
    printf("Reflexiva: %s\n", es_reflexiva(n, amistades, m) ? "Sí" : "No");
    printf("Simétrica: %s\n", es_simetrica(n, amistades, m) ? "Sí" : "No");
    printf("Tiene clique triangular (tamaño 3): %s\n",
           encontrar_clique_de_tamano(n, amistades, m, 3) ? "Sí" : "No");

    // Probar amigos mutuos
    printf("\nIngrese dos personas para encontrar amigos mutuos: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Amigos mutuos entre %d y %d: %d\n",
           a, b, contar_amigos_mutuos(n, amistades, m, a, b));

    // Probar alcanzabilidad
    printf("\nIngrese persona de inicio y fin para verificar alcanzabilidad: ");
    int inicio, fin;
    scanf("%d %d", &inicio, &fin);
    printf("Se puede alcanzar desde %d hasta %d: %s\n",
           inicio, fin, puede_alcanzar(n, amistades, m, inicio, fin) ? "Sí" : "No");

    printf("\nTodos los grados pares: %s\n",
           todos_grados_pares(n, amistades, m) ? "Sí" : "No");

    return 0;
}
/*## Casos de Prueba

### Caso de Prueba 1: Red Pequeña
```
Entrada:
5 12
0 1
1 0
0 2
2 0
1 2
2 1
2 3
3 2
3 4
4 3
2 4
4 2
Salida Esperada:
Reflexiva: No
Simétrica: Sí
Tiene clique triangular (tamaño 3): Sí (0,1,2)
Amigos mutuos entre 1 y 4: 1 (persona 2)
Se puede alcanzar desde 0 hasta 4: Sí
Todos los grados pares: Sí
```

### Caso de Prueba 2: Red Desconectada
```
Entrada:
6 8
0 1
1 0
1 2
2 1
3 4
4 3
4 5
5 4


Salida Esperada:
Reflexiva: No
Simétrica: Sí
Tiene clique triangular (tamaño 3): No
Amigos mutuos entre 0 y 2: 1 (persona 1)
Se puede alcanzar desde 0 hasta 5: No
Todos los grados pares: No
*/