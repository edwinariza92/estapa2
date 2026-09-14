# 📊 Mis Apuntes — Estadística Inferencial

> **Propósito:** Documento de referencia con conceptos, fórmulas y ejemplos resueltos.
> **Formato:** Markdown con fórmulas en Unicode limpio (sin LaTeX)
> **Última actualización:** 2026-09-13

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
- **Notación extensión:** Listar elementos entre llaves → `A = {1, 2, 3}`
- **Notación comprensión:** Describir propiedad → `A = {x | x es par}`
- **Conjunto universo (`U`):** Todos los elementos posibles en un contexto.
- **Conjunto vacío (`∅`):** Conjunto sin elementos.

### Subconjuntos

- `A ⊆ B`: Todo elemento de A está en B.
- `A ⊂ B`: A es subpropio de B (A ≠ B).
- `P(A)`: Conjunto potencia (todos los subconjuntos de A). Si `|A| = n`, entonces `|P(A)| = 2ⁿ`.

### Operaciones

| Operación | Notación | Definición |
|-----------|----------|------------|
| Unión | `A ∪ B` | `{x | x ∈ A o x ∈ B}` |
| Intersección | `A ∩ B` | `{x | x ∈ A y x ∈ B}` |
| Diferencia | `A − B` | `{x | x ∈ A y x ∉ B}` |
| Complemento | `A^c` | `{x ∈ U | x ∉ A}` |

### Leyes de De Morgan

`(A ∪ B)^c = A^c ∩ B^c`

`(A ∩ B)^c = A^c ∪ B^c`

### Fórmula del teorema de la inclusión-exclusión (dos conjuntos)

`|A ∪ B| = |A| + |B| − |A ∩ B|`

### Fórmula del teorema de la inclusión-exclusión (tres conjuntos)

`|A ∪ B ∪ C| = |A| + |B| + |C| − |A ∩ B| − |A ∩ C| − |B ∩ C| + |A ∩ B ∩ C|`

---

## Tema 2: Funciones ✅

### Conceptos clave

- **Función** `f: A → B`: Relación que asocia cada elemento de A con **un único** elemento de B.
- **Dominio (`A`):** Conjunto de entrada (valores que acepta la función).
- **Codominio (`B`):** Conjunto de salida posible.
- **Rango:** Conjunto de valores que la función realmente produce (`⊆ B`).

### Clasificación de funciones

| Tipo | Condición | Ejemplo en `ℝ → ℝ` |
|------|-----------|----------------------------------------|
| **Inyectiva** (uno a uno) | Si `f(a) = f(b) ⇒ a = b` | `f(x) = 2x + 3` |
| **Sobreyectiva** (sobre) | Para todo `y ∈ B`, existe `x ∈ A` tal que `f(x) = y` | `f(x) = x³` |
| **Biyectiva** | Inyectiva + Sobreyectiva | `f(x) = 2x + 3`, `f(x) = x³` |

**Nota importante:** `f(x) = x²` en `ℝ → ℝ` **no** es inyectiva (f(−1) = f(1) = 1) y **no** es sobreyectiva (rango = `[0, ∞)`).

### Función inversa

Si `f` es **biyectiva**, existe `f⁻¹` tal que:
- `f⁻¹(f(x)) = x`
- `f(f⁻¹(y)) = y`

**Cómo encontrarla:**
1. Reemplaza `f(x)` por `y`
2. Despeja `x` en términos de `y`
3. Intercambia `x` e `y`

**Ejemplo:** `f(x) = 2x + 3`

`y = 2x + 3 → y − 3 = 2x → x = (y − 3)/2`

**Resultado:** `f⁻¹(x) = (x − 3)/2`

### Composición de funciones

`(f ∘ g)(x) = f(g(x))`

Primero aplicas `g`, luego `f` al resultado.

---

## Tema 3: Análisis combinatorio ✅

### Principios de conteo

#### Principio multiplicativo (regla del producto)

Si un evento A tiene **m** resultados posibles y un evento B tiene **n** resultados posibles, el número total del evento compuesto es:

`Total = m · n`

**Ejemplo:** 3 camisas · 2 pantalones = 6 combinaciones

#### Principio aditivo (regla de la suma)

Si un evento puede ocurrir de **m** maneras **o** de **n** maneras (sin superposición):

`Total = m + n`

**Ejemplo:** 3 camisas azules + 2 camisas rojas = 5 camisas

| Situación | Principio | Palabra clave |
|-----------|-----------|---------------|
| "Y" (ambas cosas ocurren) | Multiplicativo | `·` |
| "O" (una u otra cosa) | Aditivo | `+` |

---

### Factorial

El factorial de n (`n!`) es el producto de todos los enteros positivos desde 1 hasta n:

`n! = n · (n−1) · (n−2) · … · 2 · 1`

**Ejemplos:**
- `1! = 1`
- `3! = 3 · 2 · 1 = 6`
- `5! = 5 · 4 · 3 · 2 · 1 = 120`
- `0! = 1` (caso especial)

---

### Producto cartesiano

El producto cartesiano de A y B (`A × B`) es el conjunto de pares ordenados:

`A × B = {(a, b) | a ∈ A y b ∈ B}`

**Tamaño:**

`|A × B| = |A| · |B| = n · m`

**Ejemplo:** `A = {1, 2, 3}`, `B = {a, b}` → `|A × B| = 3 · 2 = 6`

---

### Permutaciones

El **orden importa**. Seleccionar **r** elementos de **n**:

`P(n, r) = n! / (n − r)!`

**Ejemplo:** Elegir presidente, vicepresidente y tesorero de 5 personas:

`P(5, 3) = 5!/2! = 120/2 = 60`

---

### Combinaciones

El **orden NO importa**. Seleccionar **r** elementos de **n**:

`C(n, r) = n! / (r! · (n − r)!)`

**Ejemplo:** Elegir un equipo de 3 de 8 personas:

`C(8, 3) = 8!/(3! · 5!) = 40320/(6 · 120) = 56`

---

### Resumen: ¿Cuándo usar cada una?

| Tipo | ¿Cuándo? | Fórmula |
|------|----------|---------|
| **Permutación** | El orden SÍ importa | `P(n, r) = n! / (n−r)!` |
| **Combinación** | El orden NO importa | `C(n, r) = n! / (r!·(n−r)!)` |

---

## Tema 4: Probabilidad 🔶

### Conceptos fundamentales

#### Experimento aleatorio

Experimento cuyo resultado no se puede predecir con certeza.

**Ejemplos:** Lanzar un dado, lanzar una moneda, extraer una carta.

---

#### Espacio muestral (Ω)

Conjunto de todos los resultados posibles.

```
Dado: Ω = {1, 2, 3, 4, 5, 6}
Moneda: Ω = {Cara, Cruz}
Dos monedas: Ω = {(C,C), (C,V), (V,C), (V,V)}
```

---

#### Eventos

Subconjunto del espacio muestral (`A ⊆ Ω`).

| Tipo | Definición | Ejemplo (dado) |
|------|------------|----------------|
| **Simple** | Un solo resultado | {3} |
| **Compuesto** | Varios resultados | {2, 4, 6} |
| **Mutuamente excluyentes** | No pueden ocurrir al mismo tiempo | {1, 2} y {3, 4} |
| **Complemento** | Todos los resultados que NO están en A | Si A = {2, 4, 6}, Aᶜ = {1, 3, 5} |

---

### Regla de Laplace

`P(A) = casos favorables / casos posibles = |A| / |Ω|`

**Ejemplo:** Dado justo, número par: P(A) = 3/6 = 1/2

**Propiedades:**
- `0 ≤ P(A) ≤ 1`
- `P(Ω) = 1` (evento seguro)
- `P(∅) = 0` (evento imposible)

---

### Axiomas de Kolmogorov

| Axioma | Fórmula | Significado |
|--------|---------|-------------|
| **1. No negatividad** | `P(A) ≥ 0` | La probabilidad nunca es negativa |
| **2. P(Ω) = 1** | `P(Ω) = 1` | El seguro de que algo pase es 1 |
| **3. Aditividad** | Si `A ∩ B = ∅`: `P(A ∪ B) = P(A) + P(B)` | Mutuamente excluyentes se suman |

**Teoremas derivados:**
- `P(A^c) = 1 − P(A)`
- `P(∅) = 0`
- Si `A ⊆ B`, entonces `P(A) ≤ P(B)`

---

### Regla general de adición

`P(A ∪ B) = P(A) + P(B) − P(A ∩ B)`

**Si mutuamente excluyentes (A ∩ B = ∅):**

`P(A ∪ B) = P(A) + P(B)`

---

### Probabilidad condicional

`P(A|B) = P(A ∩ B) / P(B)`

**Interpretación:** "Si solo consideramos los casos donde B es cierto, ¿cuál es la probabilidad de A?"

**Ejemplo:** Dado, pares dado que menor que 4: P(A|B) = (1/6) / (1/2) = 1/3

---

### Regla de multiplicación

`P(A ∩ B) = P(A|B) · P(B)`

---

### Independencia

Dos eventos son **independientes** si:

`P(A ∩ B) = P(A) · P(B)`

O equivalentemente: `P(A|B) = P(A)`

---

### Teorema de la probabilidad total

Si `B₁, B₂, …, Bₙ` es una partición de Ω:

`P(A) = Σᵢ P(A|Bᵢ) · P(Bᵢ)`

---

### Teorema de Bayes

`P(Bⱼ|A) = (P(A|Bⱼ) · P(Bⱼ)) / P(A)`

Donde `P(A) = Σᵢ P(A|Bᵢ) · P(Bᵢ)`

**Ejemplo clásico:** Prueba médica con falsos positivos.

---

### Resumen del Tema 4

| Concepto | Fórmula |
|----------|---------|
| Laplace | `P(A) = |A| / |Ω|` |
| Complemento | `P(A^c) = 1 − P(A)` |
| Adición | `P(A ∪ B) = P(A) + P(B) − P(A ∩ B)` |
| Condicional | `P(A|B) = P(A ∩ B) / P(B)` |
| Multiplicación | `P(A ∩ B) = P(A|B) · P(B)` |
| Independencia | `P(A ∩ B) = P(A) · P(B)` |
| Probabilidad total | `P(A) = Σᵢ P(A|Bᵢ) · P(Bᵢ)` |
| Bayes | `P(Bⱼ|A) = P(A|Bⱼ) · P(Bⱼ) / P(A)` |

---

## Tema 5: Variables aleatorias ✅

### Concepto

**Variable aleatoria** es una función que asigna un número a cada resultado del espacio muestral:

`X: Ω → ℝ`

Transforma el resultado del experimento en un número que podemos manipular con probabilidad.

### Tipos

| Tipo | Valores | Ejemplo |
|------|---------|---------|
| **Discreta** | Contables (enteros): `X ∈ {x₁, x₂, …}` | Número de caras al lanzar 3 monedas |
| **Continua** | En un intervalo de ℝ: `X ∈ [a, b]` | Altura, peso, tiempo de espera |

### Función de masa de probabilidad (FMP) — discreta

`f(x) = P(X = x)`

- Da la probabilidad de cada valor exacto.
- Debe cumplir: `Σ f(x) = 1` y `0 ≤ f(x) ≤ 1`.

**Ejemplo:** dado justo, `f(x) = 1/6` para `x = 1, 2, …, 6`; `Σ f(x) = 6·(1/6) = 1`.

### Función de densidad de probabilidad (FDP) — continua

- La probabilidad de un **punto exacto es 0**; la probabilidad es el **área bajo la curva**.
- `P(a ≤ X ≤ b) = ∫` f(x) dx entre a y b.
- Debe cumplir: área total bajo la curva = 1.

**Ejemplo:** `U(0, 15)` tiene `f(x) = 1/15` constante; área total = base 15 · altura 1/15 = 1.

### Función de distribución acumulada (FDA)

`F(x) = P(X ≤ x)`

- Acumula la probabilidad hasta `x`.
- Va de 0 (en −∞) a 1 (en +∞) y nunca decrece.

---

## Tema 6: Distribuciones de probabilidad ✅

### Medidas de una variable aleatoria

| Medida | Fórmula |
|--------|---------|
| Esperanza (media) | `E[X] = Σᵢ xᵢ · f(xᵢ)` (discreta) · `E[X] = ∫ x·f(x) dx` (continua) |
| Varianza | `Var(X) = E[X²] − (E[X])²` |
| Desviación estándar | `σ = √Var(X)` |

### Distribuciones discretas

| Distribución | Cuándo usarla | Fórmula | E[X] | Var(X) |
|--------------|---------------|---------|------|--------|
| **Bernoulli `Ber(p)`** | Un solo intento, dos resultados | `P(X=1)=p`, `P(X=0)=1−p` | `p` | `p(1−p)` |
| **Binomial `Bin(n, p)`** | n intentos independientes, contar éxitos | `P(X=k)=C(n,k)·p^k·(1−p)^(n−k)` | `np` | `np(1−p)` |
| **Poisson `Poi(λ)`** | Contar eventos raros a ritmo constante | `f(x)=e^(−λ)·λ^x/x!` | `λ` | `λ` |
| **Geométrica `Geom(p)`** | Intentos hasta el primer éxito | `f(x)=(1−p)^(x−1)·p` | `1/p` | `(1−p)/p²` |

### Distribuciones continuas

| Distribución | Cuándo usarla | Fórmula | E[X] | Var(X) |
|--------------|---------------|---------|------|--------|
| **Uniforme `U(a,b)`** | Igual probabilidad en un intervalo | `f(x)=1/(b−a)` | `(a+b)/2` | `(b−a)²/12` |
| **Exponencial `Exp(λ)`** | Tiempo hasta un evento a ritmo constante | `f(x)=λ·e^(−λx)` | `1/λ` | `1/λ²` |
| **Normal `N(μ, σ)`** | Muchos factores que se suman | `Z=(X−μ)/σ` | `μ` | `σ²` |

### Normal: regla 68-95-99.7

- `μ ± σ` → ~68%
- `μ ± 2σ` → ~95%
- `μ ± 3σ` → ~99.7%

Estandarización: `Z = (X − μ)/σ ~ N(0,1)` permite usar la tabla Z.

### Aproximación normal a la binomial

`Bin(n, p) ≈ N(np, √(np(1−p)))` si `n·p ≥ 10` y `n·(1−p) ≥ 10`.

**Corrección por continuidad** (la binomial es discreta, la normal continua):
- `P(X ≤ k)` → usar `P(X ≤ k + 0.5)`
- `P(X ≥ k)` → usar `P(X ≥ k − 0.5)`
- `P(X = k)` → usar `P(k − 0.5 ≤ X ≤ k + 0.5)`

### Clave para elegir distribución

| Pregunta | Distribución |
|----------|--------------|
| ¿1 intento, 2 resultados? | Bernoulli |
| ¿n intentos, contar éxitos? | Binomial |
| ¿Contar eventos raros en un intervalo? | Poisson |
| ¿Intentos hasta el primer éxito? | Geométrica |
| ¿Tiempo hasta el primer evento? | Exponencial |
| ¿Medida simétrica con media y dispersión dadas? | Normal |

---

## Tema 7: Distribuciones muestrales ✅

### Concepto fundamental

Una **distribución muestral** es la distribución de probabilidad de un estadístico (como la media x̄ o proporción p̂) obtenido de todas las muestras posibles de tamaño n de una población.

---

### Distribución muestral de la media

**Propiedades:**
- `E[X̄] = μ` (la media muestral es insesgada)
- `σ_X̄ = σ / √n` (error estándar)

**Interpretación:** A mayor tamaño de muestra, menor dispersión de las medias muestrales alrededor de μ.

**Ejemplo:** Si μ = 50, σ = 12, n = 36:
- E[X̄] = 50
- σ_X̄ = 12/√36 = 12/6 = 2

---

### Distribución muestral de la proporción

**Propiedades:**
- `E[p̂] = p`
- `σ_p̄ = √(p(1-p) / n)`

**Ejemplo:** Si p = 0.65, n = 200:
- E[p̂] = 0.65
- σ_p̄ = √(0.65 · 0.35 / 200) ≈ 0.034

---

### Distribución t de Student

**Cuándo se usa:** σ desconocida, población normal, muestra pequeña (n < 30).

**Estadístico:**
`t = (x̄ − μ) / (s / √n)` con `gl = n − 1`

**Comparación con Z:**
- t tiene colas más pesadas (más dispersa)
- Converge a Z cuando n → ∞

---

### Distribución Chi-cuadrado (χ²)

**Uso:** Inferencias sobre la varianza poblacional σ².

**Estadístico:**
`χ² = (n − 1) · s² / σ²` con `gl = n − 1`

**Propiedades:**
- Solo valores positivos
- Asimétrica (cola derecha más larga)

**Ejemplo:** n = 16, s² = 6, σ² = 4:
- χ² = 15 · 6 / 4 = 22.5
- gl = 15

---

### Distribución F (Fisher)

**Uso:** Comparar dos varianzas de poblaciones normales independientes.

**Estadístico:**
`F = s₁² / s₂²` con `gl₁ = n₁ − 1`, `gl₂ = n₂ − 1`

**Propiedades:**
- Solo valores positivos
- Asimétrica
- Si σ₁² = σ₂², entonces F ≈ 1

**Ejemplo:** s₁² = 4.2 (n₁ = 15), s₂² = 2.8 (n₂ = 12):
- F = 4.2 / 2.8 = 1.5
- gl₁ = 14, gl₂ = 11

---

### Resumen de distribuciones muestrales

| Distribución | Usa cuando | Estadístico | gl |
|--------------|------------|-------------|-----|
| Normal (Z) | σ conocida | `Z = (x̄ − μ) / (σ/√n)` | — |
| t de Student | σ desconocida | `t = (x̄ − μ) / (s/√n)` | n − 1 |
| χ² | Inferir σ² | `χ² = (n−1)s² / σ²` | n − 1 |
| F | Comparar σ₁² y σ₂² | `F = s₁² / s₂²` | n₁−1, n₂−1

---

## Tema 8: Ley de los números grandes y TLC ✅

### Ley de los números grandes (LNN)

**Enunciado:** Cuando el tamaño de muestra n tiende a infinito, la media muestral X̄ converge a la media poblacional μ.

**Interpretación:** A mayor número de ensayos, más preciso es el estimador.

**Propiedades:**
- `E[X̄] = μ` (insesgado)
- `σ_X̄ = σ/√n` (disminuye cuando n crece)

**Ejemplo:** Si μ = 70 kg:
- n = 10 → X̄ = 72 kg
- n = 100 → X̄ = 69 kg
- n = 1000 → X̄ = 70.2 kg

---

### Teorema del Límite Central (TLC)

**Enunciado:** Si n ≥ 30, la distribución de las medias muestrales se aproxima a una normal, sin importar la distribución de la población original.

**Fórmula:**
`X̄ ~ N(μ, σ/√n)` (aproximadamente, cuando n ≥ 30)

**Condiciones de aplicación:**
1. Independencia de las observaciones (muestra aleatoria simple)
2. n ≥ 30 (regla general)
   - Si la población es normal, n puede ser menor
   - Si la población es muy asimétrica, se necesita n más grande

| Población | n necesario | Resultado |
|-----------|-------------|-----------|
| Normal | Cualquier n | X̄ es normal |
| No normal | n ≥ 30 | X̄ es **aproximadamente** normal |

---

### Ejemplo completo

**Problema:** Los ingresos mensuales tienen distribución asimétrica con μ = 1500 y σ = 300. Se toma una muestra de n = 50.

**a) ¿Se aplica el TLC?**
Sí, porque n = 50 ≥ 30.

**b) ¿Qué distribución sigue X̄?**
`X̄ ~ N(1500, 300/√50) ≈ N(1500, 42.43)`

**c) Calcular P(X̄ > 1550):**
1. `Z = (1550 − 1500) / 42.43 = 50 / 42.43 ≈ 1.18`
2. Buscar en tabla Z: P(Z < 1.18) = 0.8810
3. `P(X̄ > 1550) = 1 − 0.8810 = 0.1190`

**Resultado:** ~11.9% de probabilidad.

---

### Diferencia entre LNN y TLC

| Ley de los números grandes | Teorema del Límite Central |
|---------------------------|---------------------------|
| X̄ converge a μ cuando n → ∞ | X̄ sigue distribución normal cuando n ≥ 30 |
| Habla de **convergencia** | Habla de **distribución** |
| Se cumple con muchos ensayos | Se cumple cuando n ≥ 30 |

---

## Tema 9: Muestreo ✅

### Población vs. Muestra

| Concepto | Definición | Ejemplo |
|----------|------------|---------|
| **Población** | Todos los elementos de interés | Todos los estudiantes de una universidad |
| **Muestra** | Subconjunto de la población | 200 estudiantes encuestados |
| **Parámetro** | Valor de la población (μ, σ) | Promedio de calificaciones de todos |
| **Estadístico** | Valor de la muestra (x̄, s) | Promedio de los 200 encuestados |

---

### Tipos de muestreo

#### Muestreo aleatorio simple (MAS)
Cada elemento tiene la **misma probabilidad** de ser seleccionado.

#### Muestreo estratificado
La población se divide en **grupos homogéneos** (estratos) y se toma una muestra de **cada uno**.

**Ejemplo:** Universidades con 60% mujeres y 40% hombres → muestra de 200: 120 mujeres, 80 hombres.

#### Muestreo por conglomerados
La población se divide en **grupos heterogéneos** (conglomerados) y se seleccionan algunos grupos **completos**.

**Ejemplo:** Elegir 5 hospitales al azar y encuestar a **todos** los pacientes de esos hospitales.

#### Muestreo sistemático
Se elige un punto de inicio aleatorio y se toma cada k-ésimo elemento.

**Fórmula:** `k = N / n`

---

### Diferencia clave: estratificado vs. conglomerados

| Tipo | Cuándo usarlo |
|------|---------------|
| **Estratificado** | Grupos homogéneos **dentro** pero heterogéneos **entre sí** → quieres representar a todos |
| **Conglomerados** | Grupos heterogéneos **dentro** pero homogéneos **entre sí** → seleccionas algunos grupos completos |

---

### Sesgo de muestreo

El **sesgo** ocurre cuando la muestra **no representa fielmente** a la población.

| Tipo | Descripción | Ejemplo |
|------|-------------|---------|
| **De selección** | El método favorece a ciertos grupos | Solo encuestar en un centro comercial los sábados por la mañana |
| **De no respuesta** | Algunos elegidos no participan | Personas con opiniones extremas son más propensas a responder |
| **De supervivencia** | Solo se estudia a quienes "sobreviven" | Estudiar solo empresas exitosas, ignorando las que quebraron |

---

### Error de muestreo

Es la **diferencia** entre el valor del estadístico muestral y el valor real del parámetro poblacional.

**Se mide con el error estándar:**
- Para la media: `σ_X̄ = σ / √n`
- Para la proporción: `σ_p̄ = √(p(1-p) / n)`

**Importancia:** Nos dice qué tan precisa es la estimación. Disminuye cuando aumenta n.

---

### Tamaño de muestra

**Fórmula para estimar la media con error máximo E:**

`n = (Z · σ / E)²`

**Valores de Z según nivel de confianza:**

| Nivel de confianza | Z |
|--------------------|-----|
| 90% | 1.645 |
| 95% | 1.96 |
| 98% | 2.33 |
| 99% | 2.576 |

**Ejemplo:** σ = 10, error máximo E = 2, 95% confianza:
`n = (1.96 · 10 / 2)² ≈ 96`

---

## Tema 10: Hipótesis, significancia, valor p, potencia y errores ✅

### Hipótesis nula (H₀) e hipótesis alternativa (H₁)

Las pruebas de hipótesis son como un "juicio" estadístico:

- **H₀ (hipótesis nula):** Lo que asumimos como verdadero hasta tener evidencia en contra. **Siempre incluye igualdad** (=, ≤, ≥).
- **H₁ (hipótesis alternativa):** Lo que queremos probar. Es lo contrario de H₀.

**Regla:** Si la afirmación original incluye igualdad (≥, ≤, =) → va en H₀. Si no incluye (<, >, ≠) → va en H₁.

---

### Tipos de prueba

| Tipo | H₁ | Cola | Ejemplo |
|------|-----|------|---------|
| **Bilateral** | μ ≠ valor | Ambas colas | "¿El promedio CAMBIÓ?" |
| **Cola izquierda** | μ < valor | Izquierda | "¿El promedio es MENOR?" |
| **Cola derecha** | μ > valor | Derecha | "¿El promedio es MAYOR?" |

**Ejemplo:** Tablets con batería de "al menos 10 horas":
- H₀: μ ≥ 10
- H₁: μ < 10
- Tipo: cola izquierda

**Ejemplo:** Hospital con tasa de infección del 5%:
- H₀: μ = 5% (o μ ≤ 5%)
- H₁: μ > 5%
- Tipo: cola derecha

---

### Nivel de significancia (α)

Es la probabilidad de **rechazar H₀ cuando en realidad es verdadera** (Error Tipo I).

| α | Nivel de confianza | Interpretación |
|----|-------------------|----------------|
| 0.10 | 90% | 10% de riesgo |
| 0.05 | 95% | 5% de riesgo (más común) |
| 0.01 | 99% | 1% de riesgo |

---

### Tipos de error

| Error | Qué ocurre | Probabilidad |
|-------|------------|--------------|
| **Tipo I** | Rechazas H₀ siendo verdadera | α |
| **Tipo II** | No rechazas H₀ siendo falsa | β |

| Decisión | H₀ es verdadera | H₀ es falsa |
|----------|-----------------|-------------|
| **Rechazar H₀** | Error Tipo I (α) | ✅ Correcto |
| **No rechazar H₀** | ✅ Correcto | Error Tipo II (β) |

---

### Potencia

**Potencia = 1 − β**

Es la probabilidad de **rechazar H₀ correctamente** cuando H₀ es falsa.

**Cómo aumentar la potencia:**
- Aumentar n (tamaño de muestra)
- Aumentar α (pero aumenta riesgo de Error Tipo I)
- Reducir la variabilidad (σ)

**Ejemplo:** Si potencia = 0.90, entonces β = 0.10. Tienes 90% de probabilidad de detectar el efecto si existe.

---

### Valor p

Es la probabilidad de obtener un resultado igual o más extremo que el observado, **asumiendo que H₀ es verdadera**.

**Regla de decisión:**
- Si **p ≤ α** → Rechazas H₀ (resultado significativo)
- Si **p > α** → No rechazas H₀ (no hay evidencia suficiente)

**Ejemplo:** p = 0.03, α = 0.05 → 0.03 ≤ 0.05 → Rechazas H₀

---

### Resumen

| Concepto | Definición | Regla |
|----------|------------|-------|
| H₀ | Hipótesis nula | Incluye igualdad |
| H₁ | Hipótesis alternativa | Contrario de H₀ |
| α | Nivel de significancia | P(Error Tipo I) |
| β | Error Tipo II | P(No rechazar H₀ siendo falsa) |
| Potencia | Detectar efecto real | 1 − β |
| Valor p | P(result extremo \| H₀ verdadera) | Rechazar si p ≤ α |

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

## Tema 15: Teorema de Bayes ✅

### Fórmula de Bayes

`P(Bⱼ|A) = P(Bⱼ) · P(A|Bⱼ) / Σᵢ P(Bᵢ) · P(A|Bᵢ)`

### Probabilidad total (denominador)

`P(A) = Σᵢ P(Bᵢ) · P(A|Bᵢ)`

### Probabilidad a priori vs. a posteriori

- **A priori `P(Bⱼ)`:** tu creencia inicial antes de ver la evidencia.
- **A posteriori `P(Bⱼ|A)`:** tu creencia actualizada después de observar la evidencia A.

### Paso a paso para resolver un problema de Bayes

1. **Identificar las causas (partición):** los eventos `B₁, B₂, …, Bₙ` que se reparten todo el espacio muestral. Son las "causas" posibles de la evidencia.
2. **Anotar las probabilidades a priori** `P(Bᵢ)`: proporción/cantidad de cada causa (en % de producción, % de la población, etc.).
3. **Anotar las verosimilitudes** `P(A|Bᵢ)`: probabilidad de la evidencia A dado cada causa (tasa de defectos, sensibilidad de la prueba, etc.).
4. **Calcular la probabilidad total** del denominador:
   `P(A) = Σᵢ P(Bᵢ) · P(A|Bᵢ)`
5. **Aplicar Bayes** para cada causa de interés `Bⱼ`:
   `P(Bⱼ|A) = P(Bⱼ) · P(A|Bⱼ) / P(A)`
6. **Interpretar** el resultado en contexto y verificar que `Σⱼ P(Bⱼ|A) = 1`.

### Ejemplo paso a paso (fábrica con 3 máquinas)

Tres máquinas: M1 50% (6% defectuosas), M2 30% (3% defectuosas), M3 20% (4% defectuosas).

**Paso 1 — Causas:** `M1, M2, M3` forman una partición (toda pieza sale de una de ellas).

**Paso 2 — A priori:**
`P(M1) = 0.50`, `P(M2) = 0.30`, `P(M3) = 0.20`

**Paso 3 — Verosimilitudes:**
`P(D|M1) = 0.06`, `P(D|M2) = 0.03`, `P(D|M3) = 0.04`

**Paso 4 — Probabilidad total de defecto:**
`P(D) = 0.50·0.06 + 0.30·0.03 + 0.20·0.04 = 0.03 + 0.009 + 0.008 = 0.047`

**Paso 5 — Bayes para cada máquina:**
- `P(M1|D) = 0.50·0.06 / 0.047 = 0.03/0.047 ≈ 0.638`
- `P(M2|D) = 0.30·0.03 / 0.047 = 0.009/0.047 ≈ 0.1915`
- `P(M3|D) = 0.20·0.04 / 0.047 = 0.008/0.047 ≈ 0.170`

**Paso 6 — Comprobación:** `0.638 + 0.1915 + 0.170 ≈ 1` ✓

**Interpretación:** aunque M2 produce pocos defectos en % (3%), solo el ~19% de las piezas defectuosas vienen de ella; la mayoría (~64%) vienen de M1, que produce la mitad de todas las piezas.

### Aplicaciones prácticas

- **Diagnóstico médico:** la prueba positiva se interpreta con la prevalencia.
- **Clasificación y filtros de spam:** actualizar la probabilidad de spam según las palabras del correo.
- **Aprendizaje automático:** los "naive Bayes" se basan directamente en este teorema.

---

## 📊 Registro de sesiones

| Fecha | Tema estudiado | Avance |
|-------|----------------|--------|
| 2026-09-10 | Tema 1 (Completado), Tema 2 (En progreso) | Conceptos de funciones, reto pendiente |
| 2026-09-10 | Tema 3 (Completado) | Principios de conteo, factorial, permutaciones, combinaciones |
| 2026-09-10 | Tema 2 (Completado), Tema 4 (Conceptos vistos) | Reto de funciones completado, conceptos de probabilidad (reto pendiente) |
| 2026-09-13 | Tema 6 (Completado), Tema 15 (Bayes, repaso) | Reto de distribuciones superado; apuntes migrados a Unicode; repaso de Bayes con ejercicio |
| 2026-09-14 | Tema 7 (Completado) | Distribuciones muestrales: media, proporción, t de Student, Chi-cuadrado y F; reto superado (6/7) |
| 2026-09-14 | Tema 8 (Completado) | LNN y TLC: convergencia, distribución aproximada normal, ejemplos con tabla Z; reto superado (8/9) |
| 2026-09-14 | Tema 9 (Completado) | Muestreo: tipos (aleatorio, estratificado, conglomerados, sistemático), sesgo y error; reto superado (9/9) |
| 2026-09-14 | Tema 10 (Completado) | Hipótesis: H₀/H₁, tipos de prueba (cola izq, der, bilateral), α, β, potencia, valor p; reto superado (6/9) |

---

*Este documento se actualiza después de cada tema completado.*