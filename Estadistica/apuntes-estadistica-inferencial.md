# 📊 Mis Apuntes — Estadística Inferencial

> **Propósito:** Documento de referencia con conceptos, fórmulas y ejemplos resueltos.
> **Formato:** Markdown con fórmulas LaTeX
> **Última actualización:** 2026-09-10

---

## 📖 Índice

1. [Conjuntos](#tema-1-conjuntos)
2. [Funciones](#tema-2-funciones)
3. [Análisis combinatorio](#tema-3-análisis-combinatorio)
4. [Probabilidad](#tema-4-probabilidad)
5. [Variables aleatorias](#tema-5-variables-aleatorias)
6. [Distribuciones de probabilidad](#tema-6-distribuciones-de-probabilidad)
7. [Distribuciones muestrales](#tema-7-distribuciones-muestrales)
8. [Ley de los números grandes y TLC](#tema-8-ley-de-los-números-grandes-y-tlc)
9. [Muestreo](#tema-9-muestreo)
10. [Hipótesis, significancia, valor p, potencia y errores](#tema-10-hipótesis-significancia-valor-p-potencia-y-errores)
11. [Pruebas paramétricas](#tema-11-pruebas-paramétricas)
12. [Pruebas no paramétricas](#tema-12-pruebas-no-paramétricas)
13. [Distribución Chi-cuadrado](#tema-13-distribución-chi-cuadrado)
14. [Método de mínimos cuadrados](#tema-14-método-de-mínimos-cuadrados)
15. [Teorema de Bayes](#tema-15-teorema-de-bayes)

---

## Tema 1: Conjuntos ✅

### Conceptos clave

- **Conjunto:** Colección bien definida de elementos.
- **Notación extensión:** Listar elementos entre llaves → $A = \{1, 2, 3\}$
- **Notación comprensión:** Describir propiedad → $A = \{x \mid x \text{ es par}\}$
- **Conjunto universo ($U$):** Todos los elementos posibles en un contexto.
- **Conjunto vacío ($\emptyset$):** Conjunto sin elementos.

### Subconjuntos

- $A \subseteq B$: Todo elemento de A está en B.
- $A \subset B$: A es subpropio de B (A ≠ B).
- $\mathcal{P}(A)$: Conjunto potencia (todos los subconjuntos de A). Si $|A| = n$, entonces $|\mathcal{P}(A)| = 2^n$.

### Operaciones

| Operación | Notación | Definición |
|-----------|----------|------------|
| Unión | $A \cup B$ | $\{x \mid x \in A \text{ o } x \in B\}$ |
| Intersección | $A \cap B$ | $\{x \mid x \in A \text{ y } x \in B\}$ |
| Diferencia | $A \setminus B$ | $\{x \mid x \in A \text{ y } x \notin B\}$ |
| Complemento | $A^c$ | $\{x \in U \mid x \notin A\}$ |

### Leyes de De Morgan

$$(A \cup B)^c = A^c \cap B^c$$

$$(A \cap B)^c = A^c \cup B^c$$

### Fórmula del teorema de la inclusión-exclusión (dos conjuntos)

$$|A \cup B| = |A| + |B| - |A \cap B|$$

### Fórmula del teorema de la inclusión-exclusión (tres conjuntos)

$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

---

## Tema 2: Funciones 🔶

### Conceptos clave

- **Función** $f: A \to B$: Relación que asocia cada elemento de $A$ con **un único** elemento de $B$.
- **Dominio ($A$):** Conjunto de entrada (valores que acepta la función).
- **Codominio ($B$):** Conjunto de salida posible.
- **Rango:** Conjunto de valores que la función realmente produce ($\subseteq B$).

### Clasificación de funciones

| Tipo | Condición | Ejemplo en $\mathbb{R} \to \mathbb{R}$ |
|------|-----------|----------------------------------------|
| **Inyectiva** (uno a uno) | Si $f(a) = f(b) \Rightarrow a = b$ | $f(x) = 2x + 3$ |
| **Sobreyectiva** (sobre) | Para todo $y \in B$, existe $x \in A$ tal que $f(x) = y$ | $f(x) = x^3$ |
| **Biyectiva** | Inyectiva + Sobreyectiva | $f(x) = 2x + 3$, $f(x) = x^3$ |

**Nota importante:** $f(x) = x^2$ en $\mathbb{R} \to \mathbb{R}$ **no** es inyectiva (f(-1) = f(1) = 1) y **no** es sobreyectiva (rango = $[0, \infty)$).

### Función inversa

Si $f$ es **biyectiva**, existe $f^{-1}$ tal que:
- $f^{-1}(f(x)) = x$
- $f(f^{-1}(y)) = y$

**Cómo encontrarla:**
1. Reemplaza $f(x)$ por $y$
2. Despeja $x$ en términos de $y$
3. Intercambia $x$ e $y$

**Ejemplo:** $f(x) = 2x + 3$

$$y = 2x + 3 \Rightarrow y - 3 = 2x \Rightarrow x = \frac{y - 3}{2}$$

$$\boxed{f^{-1}(x) = \frac{x - 3}{2}}$$

### Composición de funciones

$$(f \circ g)(x) = f(g(x))$$

Primero aplicas $g$, luego $f$ al resultado.

---

## Tema 3: Análisis combinatorio ✅

### Principios de conteo

#### Principio multiplicativo (regla del producto)

Si un evento A tiene **m** resultados posibles y un evento B tiene **n** resultados posibles, el número total del evento compuesto es:

$$\text{Total} = m \times n$$

**Ejemplo:** 3 camisas × 2 pantalones = 6 combinaciones

#### Principio aditivo (regla de la suma)

Si un evento puede ocurrir de **m** maneras **o** de **n** maneras (sin superposición):

$$\text{Total} = m + n$$

**Ejemplo:** 3 camisas azules + 2 camisas rojas = 5 camisas

| Situación | Principio | Palabra clave |
|-----------|-----------|---------------|
| "Y" (ambas cosas ocurren) | Multiplicativo | $\times$ |
| "O" (una u otra cosa) | Aditivo | $+$ |

---

### Factorial

El factorial de n ($n!$) es el producto de todos los enteros positivos desde 1 hasta n:

$$n! = n \times (n-1) \times (n-2) \times \dots \times 2 \times 1$$

**Ejemplos:**
- $1! = 1$
- $3! = 3 \times 2 \times 1 = 6$
- $5! = 5 \times 4 \times 3 \times 2 \times 1 = 120$
- $0! = 1$ (caso especial)

---

### Producto cartesiano

El producto cartesiano de A y B ($A \times B$) es el conjunto de pares ordenados:

$$A \times B = \{(a, b) \mid a \in A \text{ y } b \in B\}$$

**Tamaño:**

$$|A \times B| = |A| \times |B| = n \times m$$

**Ejemplo:** $A = \{1, 2, 3\}$, $B = \{a, b\}$ → $|A \times B| = 3 \times 2 = 6$

---

### Permutaciones

El **orden importa**. Seleccionar **r** elementos de **n**:

$$P(n, r) = \frac{n!}{(n - r)!}$$

**Ejemplo:** Elegir presidente, vicepresidente y tesorero de 5 personas:

$$P(5, 3) = \frac{5!}{2!} = \frac{120}{2} = 60$$

---

### Combinaciones

El **orden NO importa**. Seleccionar **r** elementos de **n**:

$$C(n, r) = \frac{n!}{r! \times (n - r)!}$$

**Ejemplo:** Elegir un equipo de 3 de 8 personas:

$$C(8, 3) = \frac{8!}{3! \times 5!} = \frac{40320}{6 \times 120} = 56$$

---

### Resumen: ¿Cuándo usar cada una?

| Tipo | ¿Cuándo? | Fórmula |
|------|----------|---------|
| **Permutación** | El orden SÍ importa | $P(n, r) = \frac{n!}{(n-r)!}$ |
| **Combinación** | El orden NO importa | $C(n, r) = \frac{n!}{r!(n-r)!}$ |

---

## Tema 4: Probabilidad ⬜

*Por agregar...*

---

## Tema 5: Variables aleatorias ⬜

*Por agregar...*

---

## Tema 6: Distribuciones de probabilidad ⬜

*Por agregar...*

---

## Tema 7: Distribuciones muestrales ⬜

*Por agregar...*

---

## Tema 8: Ley de los números grandes y TLC ⬜

*Por agregar...*

---

## Tema 9: Muestreo ⬜

*Por agregar...*

---

## Tema 10: Hipótesis, significancia, valor p, potencia y errores ⬜

*Por agregar...*

---

## Tema 11: Pruebas paramétricas ⬜

*Por agregar...*

---

## Tema 12: Pruebas no paramétricas ⬜

*Por agregar...*

---

## Tema 13: Distribución Chi-cuadrado ⬜

*Por agregar...*

---

## Tema 14: Método de mínimos cuadrados ⬜

*Por agregar...*

---

## Tema 15: Teorema de Bayes ⬜

*Por agregar...*

---

## 📊 Registro de sesiones

| Fecha | Tema estudiado | Avance |
|-------|----------------|--------|
| 2026-09-10 | Tema 1 (Completado), Tema 2 (En progreso) | Conceptos de funciones, reto pendiente |
| 2026-09-10 | Tema 3 (Completado) | Principios de conteo, factorial, permutaciones, combinaciones |

---

*Este documento se actualiza después de cada tema completado.*
