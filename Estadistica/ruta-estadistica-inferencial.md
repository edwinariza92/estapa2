# 📊 Ruta de Aprendizaje — Estadística Inferencial

> **Fuente de verdad:** Sesiones con tutor (explicaciones, ejemplos, retos) + Akousa (práctica interactiva extra).
> **URL Akousa:** [akousa.net/es/learning-hub/data](https://akousa.net/es/learning-hub/data)
> Marca cada casilla `[ ]` → `[x]` conforme completes cada concepto, ejercicio o evaluación.

## 🗺️ Estructura general

| # | Tema | Estado |
|---|------|--------|
| 1 | Conjuntos | [x] |
| 2 | Funciones | [x] |
| 3 | Análisis combinatorio | [x] |
| 4 | Probabilidad | [x] |
| 5 | Variables aleatorias | [ ] |
| 6 | Distribuciones de probabilidad | [ ] |
| 7 | Distribuciones muestrales | [ ] |
| 8 | Ley de los números grandes y TLC | [ ] |
| 9 | Muestreo | [ ] |
| 10 | Hipótesis, significancia, valor p, potencia, errores | [ ] |
| 11 | Pruebas paramétricas | [ ] |
| 12 | Pruebas no paramétricas | [ ] |
| 13 | Distribución Chi-cuadrado | [ ] |
| 14 | Método de mínimos cuadrados | [ ] |
| 15 | Teorema de Bayes | [ ] |

---

## Tema 1: Conjuntos  [x]

**Objetivo:** Dominar la teoría de conjuntos como base del lenguaje estadístico.

- [x] Concepto de conjunto, elementos y notación (extensión y comprensión)
- [x] Subconjuntos, conjunto universo y conjunto vacío
- [x] Operaciones: unión, intersección, diferencia, complemento
- [x] Leyes de De Morgan: `(A ∪ B)^c = A^c ∩ B^c` y `(A ∩ B)^c = A^c ∪ B^c`
- [x] Diagramas de Venn (dos y tres conjuntos)
- [x] Reto/evaluación: resolver operaciones combinadas y representarlas con diagramas de Venn

---

## Tema 2: Funciones  [x]

**Objetivo:** Comprender el concepto de función, dominio, codominio e imágenes, esenciales para las variables aleatorias.

- [x] Definición de función como relación entre conjuntos; dominio, codominio y rango
- [x] Funciones inyectivas, sobreyectivas y biyectivas
- [x] Función inversa y composición de funciones
- [x] Funciones reales de variable real y su representación
- [x] Reto/evaluación: identificar dominio/rango e imágenes de funciones dadas y clasificarlas

---

## Tema 3: Análisis combinatorio  [x]

**Objetivo:** Aplicar los principios de conteo y las técnicas de permutaciones y combinaciones.

- [x] Principio multiplicativo y principio aditivo
- [x] Factorial, producto cartesiano (`|A × B| = n × m`)
- [x] Permutaciones: `P(n, r) = n! / (n - r)!`
- [x] Combinaciones: `C(n, r) = n! / (r! · (n - r)!)`
- [x] Reto/evaluación: resolver problemas de conteo mixtos (permutaciones y combinaciones)

---

## Tema 4: Probabilidad  [ ]

**Objetivo:** Comprender la teoría de probabilidad: espacio muestral, eventos, regla de Laplace, axiomas y teoremas.

- [x] Experimento aleatorio, espacio muestral (Ω) y eventos (A ⊆ Ω)
- [x] Tipos de eventos: simple, compuesto, mutuamente excluyentes
- [x] Regla de Laplace: `P(A) = casos favorables / casos posibles`
- [x] Axiomas de Kolmogorov
- [x] Teoremas: `P(A^c) = 1 − P(A)`, `P(∅) = 0`, monotonía
- [x] Regla general de adición: `P(A ∪ B) = P(A) + P(B) − P(A ∩ B)`
- [x] Probabilidad condicional: `P(A|B) = P(A ∩ B) / P(B)`
- [x] Regla de multiplicación e independencia de eventos
- [x] Teorema de la probabilidad total y Teorema de Bayes
- [x] Reto/evaluación: aplicar Laplace, adición y Bayes a problemas contextualizados

---

## Tema 5: Variables aleatorias  [ ]

**Objetivo:** Entender las variables aleatorias discretas y continuas y sus funciones de probabilidad.

- [ ] Variable aleatoria: `X: Ω → ℝ`
- [ ] Variables aleatorias discretas y continuas
- [ ] Función de masa de probabilidad (FMP): `f(x) = P(X = x)`, con `Σ f(x) = 1`
- [ ] Función de densidad de probabilidad (FDP) y área bajo la curva
- [ ] Función de distribución acumulada (FDA): `F(x) = P(X ≤ x)`
- [ ] Reto/evaluación: dada una FMP/FDA, calcular probabilidades y verificar propiedades

---

## Tema 6: Distribuciones de probabilidad  [ ]

**Objetivo:** Conocer las principales distribuciones discretas y continuas, su esperanza y varianza.

**Discretas**
- [ ] Distribución de Bernoulli (éxito `p`, fracaso `q = 1 − p`)
- [ ] Distribución binomial: `X ~ Bin(n, p)`; `E[X] = np`, `Var(X) = np(1 − p)`
- [ ] Distribución de Poisson: `f(x) = e^(−λ) λ^x / x!`; `E[X] = Var(X) = λ`
- [ ] Distribución geométrica: `f(x) = (1 − p)^(x−1) p`; propiedad de falta de memoria

**Continuas**
- [ ] Distribución uniforme continua: `U(a, b)`; `f(x) = 1/(b−a)`
- [ ] Distribución exponencial: `f(x) = λ e^(−λx)`; `E[X] = 1/λ`, `Var(X) = 1/λ²`
- [ ] Distribución normal: `N(μ, σ)` y estandarización `Z = (X − μ)/σ ~ N(0,1)`
- [ ] Aproximación normal a la binomial (con corrección por continuidad)

**Medidas**
- [ ] Esperanza matemática: `E[X] = Σ xᵢ f(xᵢ)`
- [ ] Varianza y desviación estándar: `Var(X) = E[X²] − (E[X])²`
- [ ] Reto/evaluación: identificar la distribución adecuada para un problema y calcular esperanza y varianza

---

## Tema 7: Distribuciones muestrales  [ ]

**Objetivo:** Comprender cómo se distribuye la media muestral y su error estándar.

- [ ] Distribución muestral de la media: `μ_X̄ = μ`, error estándar `σ_X̄ = σ/√n`
- [ ] Distribución muestral de la proporción
- [ ] Distribución `t` de Student (σ desconocida, `df = n − 1`)
- [ ] Distribución Chi-cuadrado y F (para varianzas)
- [ ] Reto/evaluación: calcular la distribución muestral y el error estándar de un caso dado

---

## Tema 8: Ley de los números grandes y TLC  [ ]

**Objetivo:** Entender la ley de los números grandes y el Teorema del Límite Central como fundamento de la inferencia.

- [ ] Ley de los números grandes (convergencia de la media muestral a la esperanza)
- [ ] Teorema del Límite Central (TLC): para muestras grandes (`n ≥ 30`) la media muestral se aproxima a una normal
- [ ] Condiciones de aplicación y supuestos del TLC
- [ ] Reto/evaluación: explicar cuándo y por qué aplica el TLC en un caso real

---

## Tema 9: Muestreo  [ ]

**Objetivo:** Conocer los tipos de muestreo y su impacto en la validez de la inferencia.

- [ ] Población vs. muestra; muestreo aleatorio simple
- [ ] Muestreo estratificado, por conglomerados y sistemático
- [ ] Sesgo de muestreo y error de muestreo
- [ ] Tamaño de muestra y su relación con el error estándar
- [ ] Reto/evaluación: determinar el método de muestreo adecuado para un estudio

---

## Tema 10: Hipótesis, significancia, valor p, potencia y tipos de error  [ ]

**Objetivo:** Dominar la lógica de las pruebas de hipótesis y la interpretación de errores y significancia.

- [ ] Hipótesis nula (`H₀`) e hipótesis alternativa (`H₁`)
- [ ] Nivel de significancia (α) y nivel de confianza
- [ ] Tipos de error: Error Tipo I (α) y Error Tipo II (β); potencia `1 − β`
- [ ] Criterio del valor p: rechazar `H₀` si `p ≤ α`
- [ ] Reto/evaluación: plantear `H₀`/`H₁`, identificar tipos de error y decidir con el valor p para un caso

---

## Tema 11: Pruebas paramétricas  [ ]

**Objetivo:** Aplicar pruebas de hipótesis paramétricas para medias, proporciones y diferencias, e intervalo de confianza.

- [ ] Intervalo de confianza para la media (σ conocida y σ desconocida) y para la proporción
- [ ] Prueba de hipótesis para una media: `Z` o `t`
- [ ] Prueba de hipótesis para una proporción
- [ ] Muestras pareadas (datos dependientes): prueba `t` para diferencias
- [ ] Comparación de dos medias (independientes) y análisis de varianza (ANOVA)
- [ ] Regresión lineal simple: `Y = β₀ + β₁X + ε`; MCO
- [ ] Correlación de Pearson (`r`) y coeficiente de determinación (`R²`)
- [ ] Reto/evaluación: realizar una prueba paramétrica completa (hipótesis → estadístico → valor p → decisión) e interpretar su intervalo de confianza

---

## Tema 12: Pruebas no paramétricas  [ ]

**Objetivo:** Conocer pruebas que no requieren supuestos de normalidad ni parámetros poblacionales.

- [ ] Cuándo usar pruebas no paramétricas (vs. paramétricas)
- [ ] Prueba Chi-cuadrado (bondad de ajuste e independencia)
- [ ] Prueba de los signos y de rangos (Wilcoxon)
- [ ] Prueba de Mann-Whitney U (dos muestras independientes)
- [ ] Prueba de Kruskal-Wallis (varias muestras)
- [ ] Reto/evaluación: elegir la prueba no paramétrica adecuada para un caso de datos ordinales o no normales

---

## Tema 13: Distribución Chi-cuadrado  [ ]

**Objetivo:** Dominar la distribución Chi-cuadrado, su tabla de valores y su aplicación en pruebas de bondad de ajuste e independencia.

- [ ] Definición de la distribución Chi-cuadrado: `χ² = Σ (Oᵢ − Eᵢ)² / Eᵢ` con `df = k − 1`
- [ ] Propiedades: asimétrica, solo valores positivos, forma depende de los grados de libertad
- [ ] Uso en pruebas de bondad de ajuste (¿los datos siguen una distribución esperada?)
- [ ] Uso en pruebas de independencia (¿dos variables categóricas son independientes?)
- [ ] Cálculo de valores críticos con tablas de Chi-cuadrado
- [ ] Reto/evaluación: plantear y resolver una prueba Chi-cuadrado de bondad de ajuste paso a paso

---

## Tema 14: Método de mínimos cuadrados  [ ]

**Objetivo:** Comprender el método de mínimos cuadrados ordinarios (MCO) para estimar parámetros de regresión lineal.

- [ ] Idea central: minimizar la suma de los cuadrados de los residuos `Σ(yᵢ − ŷᵢ)²`
- [ ] Estimadores MCO: `β̂₁ = Σ(xᵢ − x̄)(yᵢ − ȳ) / Σ(xᵢ − x̄)²` y `β̂₀ = ȳ − β̂₁x̄`
- [ ] Supuestos del modelo: linealidad, independencia, homocedasticidad, normalidad de residuos
- [ ] Interpretación de `β₀` (intercepto) y `β₁` (pendiente) en contexto
- [ ] Coeficiente de determinación `R²`: proporción de varianza de Y explicada por X
- [ ] Reto/evaluación: calcular β̂₀ y β̂₁ a partir de datos, interpretar y calcular R²

---

## Tema 15: Teorema de Bayes  [ ]

**Objetivo:** Dominar el Teorema de Bayes y su aplicación para actualizar probabilidades a partir de nueva evidencia.

- [ ] Fórmula de Bayes: `P(Bⱼ|A) = P(Bⱼ) · P(A|Bⱼ) / Σ P(Bᵢ) · P(A|Bᵢ)`
- [ ] Probabilidad a priori vs. a posteriori: cómo la evidencia actualiza la creencia inicial
- [ ] Probabilidad total como denominador: `P(A) = Σ P(Bᵢ) · P(A|Bᵢ)`
- [ ] Ejemplo clásico: prueba médica con falsos positivos/negativos
- [ ] Aplicación práctica: clasificación, diagnóstico, filtros de spam
- [ ] Reto/evaluación: resolver un problema de Bayes completo (prior → evidencia → posterior) e interpretar el resultado en contexto

---

## 📊 Progreso

- [x] Definido el plan de la ruta
- [x] Tema 1: Conjuntos
- [x] Tema 2: Funciones
- [x] Tema 3: Análisis combinatorio
- [x] Tema 4: Probabilidad
- [ ] Tema 5: Variables aleatorias
- [ ] Tema 6: Distribuciones de probabilidad
- [ ] Tema 7: Distribuciones muestrales
- [ ] Tema 8: Ley de los números grandes y TLC
- [ ] Tema 9: Muestreo
- [ ] Tema 10: Hipótesis, significancia, valor p, potencia, errores
- [ ] Tema 11: Pruebas paramétricas
- [ ] Tema 12: Pruebas no paramétricas
- [ ] Tema 13: Distribución Chi-cuadrado
- [ ] Tema 14: Método de mínimos cuadrados
- [ ] Tema 15: Teorema de Bayes

---

## ➕ Agregar más temas

¿Quieres ampliar esta ruta? Copia la plantilla siguiente al final del archivo y rellénala. Puedes añadir tantos temas como necesites.

```
## Tema X: <Nombre del tema>  [ ]

**Objetivo:** <Describe brevemente qué se logrará con este tema>

- [ ] <Concepto o subtema 1>
- [ ] <Concepto o subtema 2>
- [ ] <Concepto o subtema 3>
- [ ] Reto/evaluación: <Actividad para verificar comprensión>

---
```

**Nota:** cuando agregues un tema, actualiza también la sección `## 📊 Progreso` y la tabla `## 🗺️ Estructura general`.
