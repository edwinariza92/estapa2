# Ejercicio 5: Analisis de Redes Sociales usando Matematicas Discretas

## Descripcion del Problema

Se modela una red social como un grafo no dirigido donde las personas son vertices y las amistades son aristas. El objetivo es implementar funciones que analizan propiedades matematicas de la red usando conceptos de conjuntos, relaciones, teoria de grafos y logica booleana.

---

## Funciones Auxiliares

### `son_amigos`

**Enfoque:** Recorre el array de amistades y verifica si existe el par (persona_a, persona_b) en cualquier orden, ya que la relacion es bidireccional.

**Logica:**
1. Iterar por cada amistad en el array `amistades`
2. Verificar si el par coincide en orden directo `(a, b)` o inverso `(b, a)`
3. Si se encuentra coincidencia, retornar 1; si el bucle termina sin encontrar, retornar 0

**Complejidad:** O(m) donde m es el numero de amistades.

```c
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
```

---

### `obtener_amigos`

**Enfoque:** Recorre todas las amistades, identifica en que posicion aparece la persona solicitada, y agrega al amigo correspondiente. Incluye verificacion de duplicados para evitar contar la misma amistad dos veces.

**Logica:**
1. Por cada amistad, verificar si la persona aparece en `[0]` o `[1]`
2. El amigo es la otra posicion del par
3. Antes de agregar, verificar que el amigo no este ya en la lista (deduplicacion)
4. Retornar el conteo final de amigos unicos

**Complejidad:** O(m * k) donde m es el numero de amistades y k es el numero promedio de amigos (por la verificacion de duplicados).

```c
int obtener_amigos(int amistades[][2], int m, int persona, int amigos[])
{
    int conteo = 0;
    for (int i = 0; i < m; i++)
    {
        int candidato = -1;
        if (amistades[i][0] == persona)
            candidato = amistades[i][1];
        else if (amistades[i][1] == persona)
            candidato = amistades[i][0];

        if (candidato != -1)
        {
            int duplicado = 0;
            for (int j = 0; j < conteo; j++)
            {
                if (amigos[j] == candidato) { duplicado = 1; break; }
            }
            if (!duplicado) { amigos[conteo] = candidato; conteo++; }
        }
    }
    return conteo;
}
```

---

## Funciones Principales

### Funcion 1: `es_reflexiva`

**Concepto matematico:** Una relacion R sobre un conjunto A es reflexiva si para todo a en A, (a,a) pertenece a R.

**Enfoque:** Para cada persona i desde 0 hasta n-1, verificar si es amiga de si misma usando `son_amigos(i, i)`.

**Logica:**
1. Recorrer todas las personas (0 a n-1)
2. Para cada persona, verificar si existe la amistad (i, i)
3. Si alguna persona NO es amiga de si misma, retornar 0 (no es reflexiva)
4. Si todas son amigas de si mismas, retornar 1

**Complejidad:** O(n * m) — n personas, cada una busca en m amistades.

```c
int es_reflexiva(int n, int amistades[][2], int m)
{
    for (int i = 0; i < n; i++)
    {
        if (!son_amigos(amistades, m, i, i))
            return 0;
    }
    return 1;
}
```

---

### Funcion 2: `es_simetrica`

**Concepto matematico:** Una relacion R es simetrica si para todo a,b en A, si (a,b) pertenece a R entonces (b,a) tambien pertenece a R.

**Enfoque:** Para cada amistad registrada (a, b), verificar que la amistad inversa (b, a) exista en la lista.

**Logica:**
1. Recorrer cada amistad del array
2. Para cada par (a, b), verificar si (b, a) existe usando `son_amigos(b, a)`
3. Si alguna amistad no tiene su inversa, retornar 0
4. Si todas tienen inversa, retornar 1

**Complejidad:** O(m^2) — m amistades, cada una busca en m amistades.

```c
int es_simetrica(int n, int amistades[][2], int m)
{
    for (int i = 0; i < m; i++)
    {
        int a = amistades[i][0];
        int b = amistades[i][1];
        if (!son_amigos(amistades, m, b, a))
            return 0;
    }
    return 1;
}
```

---

### Funcion 3: `encontrar_clique_de_tamano`

**Concepto matematico:** Un clique es un subconjunto de vertices donde cada par esta conectado por una arista. Para k=3, se busca un triangulo en el grafo.

**Enfoque:** Fuerza bruta con tres bucles anidados que prueban todas las posibles ternas de personas.

**Logica:**
1. Para cada combinacion de tres personas (i, j, k) donde i < j < k
2. Verificar que los tres pares sean amigos: (i,j), (i,k), (j,k)
3. Si se encuentra alguna terna que cumpla, retornar 1
4. Si no se encuentra ninguna, retornar 0

**Analisis de complejidad temporal:**

- El algoritmo usa tres bucles anidados que recorren las personas
- El bucle externo va de 0 a n-1
- El bucle medio va de i+1 a n-1
- El bucle interno va de j+1 a n-1
- En cada iteracion del bucle interno, se hacen 3 llamadas a `son_amigos` que son O(m)

**Complejidad total:** O(n^3 * m)

- En el peor caso (cuando no hay clique), se prueban todas las combinaciones de 3 personas: C(n,3) = n*(n-1)*(n-2)/6
- Para cada combinacion, se hacen 3 verificaciones de amistad, cada una O(m)
- Por lo tanto: O(n^3 * m)

**Nota:** Para n <= 50 y m <= 500, esto es perfectamente viable (50^3 * 500 = 62,500,000 operaciones).

```c
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
```

---

### Funcion 4: `contar_amigos_mutuos`

**Concepto matematico:** Interseccion de conjuntos — A interseccion B contiene los elementos que estan en ambos conjuntos.

**Enfoque:** Obtener la lista de amigos de cada persona y contar cuantos aparecen en ambas listas.

**Logica:**
1. Usar `obtener_amigos` para obtener la lista de amigos de persona_a y persona_b
2. Recorrer la lista de amigos de persona_a
3. Para cada amigo, verificar si tambien esta en la lista de persona_b
4. Contar las coincidencias

**Complejidad:** O(m * k_a * k_b) donde k_a y k_b son los numeros de amigos de cada persona.

```c
int contar_amigos_mutuos(int n, int amistades[][2], int m, int persona_a, int persona_b)
{
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
                conteo_mutuo++;
        }
    }
    return conteo_mutuo;
}
```

---

### Funcion 5: `puede_alcanzar`

**Concepto matematico:** Cierre transitivo y conectividad de caminos en grafos. Determina si existe un camino (directo o a traves de intermediarios) entre dos personas.

**Enfoque:** Busqueda en Anchura (BFS) usando una cola implementada con un arreglo.

**Algoritmo BFS paso a paso:**
1. Si inicio == fin, retornar 1 (ya estamos en el destino)
2. Marcar inicio como visitado y agregarlo a la cola
3. Mientras la cola no este vacia:
   a. Sacar una persona de la cola (frente)
   b. Obtener todos sus amigos
   c. Para cada amigo:
      - Si es el destino, retornar 1 (encontramos camino)
      - Si no esta visitado, marcarlo y agregarlo a la cola
4. Si la cola se vacia sin encontrar el destino, retornar 0

**Analisis de complejidad temporal:**

- **Visitar cada vertice:** Cada persona se encola y se desencola exactamente una vez -> O(n)
- **Explorar aristas:** Para cada persona desencolada, se obtienen sus amigos con `obtener_amigos` -> O(m) por cada persona
- **Verificar visitados:** Cada verificacion de `visitado[]` es O(1)

**Complejidad total:** O(n * m)

- En el peor caso, se visitan todas las n personas
- Para cada una, se recorren las m amistades para obtener amigos
- La cola y el arreglo de visitados son O(n) en espacio

**Comparacion con DFS:** BFS y DFS tienen la misma complejidad temporal O(n + m) para grafos representados con listas de adyacencia. Con nuestra representacion de aristas, es O(n * m) porque obtener_amigos recorre todas las aristas.

```c
int puede_alcanzar(int n, int amistades[][2], int m, int inicio, int fin)
{
    if (inicio == fin) return 1;

    int visitado[MAX_PERSONAS] = {0};
    int cola[MAX_PERSONAS];
    int frente = 0, atras = 0;

    visitado[inicio] = 1;
    cola[atras++] = inicio;

    while (frente < atras)
    {
        int actual = cola[frente++];
        int amigos[MAX_PERSONAS];
        int num_amigos = obtener_amigos(amistades, m, actual, amigos);

        for (int i = 0; i < num_amigos; i++)
        {
            if (amigos[i] == fin) return 1;
            if (!visitado[amigos[i]])
            {
                visitado[amigos[i]] = 1;
                cola[atras++] = amigos[i];
            }
        }
    }
    return 0;
}
```

---

### Funcion 6: `todos_grados_pares`

**Concepto matematico:** El grado de un vertice es el numero de aristas incidentes. Un grafo tiene todos los grados pares si cada vertice tiene un numero par de vecinos (relacionado con grafos eulerianos).

**Enfoque:** Para cada persona, contar sus amigos y verificar si ese numero es par.

**Logica:**
1. Para cada persona i desde 0 hasta n-1
2. Usar `obtener_amigos` para contar sus amigos
3. Si alguno tiene grado impar (% 2 != 0), retornar 0
4. Si todos tienen grado par, retornar 1

**Complejidad:** O(n * m) — n personas, cada una busca en m amistades.

```c
int todos_grados_pares(int n, int amistades[][2], int m)
{
    for (int i = 0; i < n; i++)
    {
        int amigos[MAX_PERSONAS];
        int num_amigos = obtener_amigos(amistades, m, i, amigos);
        if (num_amigos % 2 != 0)
            return 0;
    }
    return 1;
}
```

---

## Resumen de Complejidades

| Funcion | Complejidad Temporal | Espacio |
|---------|---------------------|---------|
| `son_amigos` | O(m) | O(1) |
| `obtener_amigos` | O(m * k) | O(k) |
| `es_reflexiva` | O(n * m) | O(1) |
| `es_simetrica` | O(m^2) | O(1) |
| `encontrar_clique_de_tamano` | **O(n^3 * m)** | O(1) |
| `contar_amigos_mutuos` | O(m * k_a * k_b) | O(n) |
| `puede_alcanzar` | **O(n * m)** | O(n) |
| `todos_grados_pares` | O(n * m) | O(n) |

Donde: n = personas, m = amistades, k = amigos por persona

---

## Casos de Prueba

### Caso 1: Red Pequeña
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
Simetrica: Si
Tiene clique triangular (tamano 3): Si (0,1,2)
Amigos mutuos entre 1 y 4: 1 (persona 2)
Se puede alcanzar desde 0 hasta 4: Si
Todos los grados pares: Si
```

**Verificacion manual:**
- Reflexiva: No porque nadie es amigo de si mismo (no hay pares (0,0), (1,1), etc.)
- Simetrica: Si porque cada amistad (a,b) tiene su inversa (b,a)
- Clique: Si, el grupo {0, 1, 2} donde todos son amigos entre si
- Amigos mutuos de 1 y 4: Solo persona 2 (1 es amigo de {0,2}, 4 es amigo de {2,3})
- Alcanzabilidad: Si, hay camino 0->2->4
- Grados pares: 0 grado 2, 1 grado 2, 2 grado 4, 3 grado 2, 4 grado 2 — todos pares

### Caso 2: Red Desconectada
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
Simetrica: Si
Tiene clique triangular (tamano 3): No
Amigos mutuos entre 0 y 2: 1 (persona 1)
Se puede alcanzar desde 0 hasta 5: No
Todos los grados pares: No
```

**Verificacion manual:**
- Clique: No hay ningun grupo de 3 donde todos sean amigos
- Amigos mutuos de 0 y 2: Solo persona 1
- Alcanzabilidad: No hay camino de 0 a 5 (estan en componentes desconectadas)
- Grados: Persona 0 grado 1 (impar) -> No todos pares

---

## Bugs Aprendidos

1. **Condiciones con `||`:** Agregar parentesis claros para evitar ambiguedad en la precedencia de operadores
2. **Acceso a arrays:** Usar el indice correcto del bucle, no valores fijos
3. **Retornos invertidos:** Verificar que 0 signifique "no cumple" y 1 signifique "si cumple"
4. **Deduplicacion:** Cuando la entrada incluye amistades bidireccionales, `obtener_amigos` debe evitar duplicados
5. **Cola BFS:** El indice `atras` se incrementa despues de asignar, no antes
6. **Variable vs parametro:** En `encontrar_clique_de_tamano`, usar `k_persona` (variable del bucle) no `k` (parametro)
