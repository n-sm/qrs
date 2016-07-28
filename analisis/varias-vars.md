---
title: "Gradiente, Diferencial y Plano tangente"
output: pdf_document
fontsize: 16pt

---

Sea $f: A \to \mathbb{R}$, $A \in \mathbb{R}^n$ abierto.

### Gradiente

El gradiente de $f$ en el punto $p$, $\nabla f_p$ es el vector con
todas las _derivadas parciales_, o sea:

$$ \nabla f_p = (\frac{\partial f}{\partial x_1}, \dots, 
\frac{\partial f}{\partial x_n}) $$

### Diferencial

Las diferencial de $f$ en $p$, $Df_p(x)$ es una **_transformación lineal_** de 
$\mathbb{R}^n \to \mathbb{R}$.

En concreto, la diferencial de $f$ en $p$ es el producto entre el
gradiente de $f$ y $\mathbf{x}$, donde $\mathbf{x} \in A$. Es decir:

$$ \langle\nabla f_p,\mathbf{x} \rangle $$

O, de otra forma:

$$ \frac{\partial f}{\partial x_1}  x_1 + \dots + 
	\frac{\partial f}{\partial x_n}  x_n$$
	
### (Hiper) plano tangente (si existe, claro)

Si existe el plano (o hiperplano) tangente a la función $f$ en el
punto $\bold{p}$, su ecuación es:

$$ x_{n+1} = f(\bold{p}) + \langle \nabla f, \bold{x-p}\rangle$$

O, lo que es lo mismo,

$$ x_{n+1} = f(\bold{p}) + \sum_{i=1}^n 
\frac{\partial f}{\partial x_i}(\bold{p}) (x_i - p_i)
$$

Y más desarrollado:

$$ x_{n+1} = f(\bold{p}) + \frac{\partial f}{\partial
x_1}(\bold{p}) (x_1 - p_1) + \dots + \frac{\partial f}{\partial
x_n}(\bold{p}) (x_n - p_n) $$

### Diferenciabilidad

$f$ es diferenciable en $\bold{p}$ si y sólo si:


$$ \lim_{\bold{x}\to \bold{p}} \frac{|f(x) - f(p) - \langle \nabla f_p,
\bold{x}-\bold{p}\rangle|}{||\bold{x}-\bold{p}||}$$

Lo cual también puede expresarse:

$$ \lim_{\bold{x}\to \bold{p}} \frac{|f(x) - f(p) - Df_p(\bold{x}-\bold{p})|}{||\bold{x}-\bold{p}||}$$

#### Criterio de diferenciabilidad:

> **Teorema** Si: \
> 1. $A \subset \mathbb{R}^n$ es abierto \
> 2. todas las derivadas de $f: A \to \mathbb{R}$ existen en $A$ \
> 3. todas estas derivadas son contínuas en $A$, \
> <center> **_entonces_** $f$ es diferenciable en $A$.</center>

