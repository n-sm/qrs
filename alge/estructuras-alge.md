---
title: Estructuras Algebraicas
---

## Grupos y Anillos
Sea $A \neq \emptyset$.

Llamamos __operación binaria__ en $A$ o también __ley de composición
binaria__ en $A$ al dar, a cada par $(a, b) \in A$ un elemento $a\circ b \in A$


### Definición (Operación Asociativa)
Sean $(A,\circ)$ un conjunto detado de una operación binaria. Diremos que $\circ$
es asociativa si:
$$ a \circ (b \circ c) = (a \circ b) \circ c $$

Un conjunto $A$ dotado de una operación se denomina un _monoide_. Se suele decir
sobre $A$ que está definida una estructura de monoide.

### Definición (Semigrupo)
Un monoide asociativo (o sea donde la operación es asociativa) se denomina _semigrupo_.

### Definición (Operación conmutativa)
Sea $(A,\circ)$ un conjunto dotado de una operación binaria. Diremos que $\circ$ es
_conmutativa_ si:
$$ a \circ b = b \circ a$$
Para todo $a,b \in A$.

### Definición (Elemento Neutro)
Sea $(A,\circ)$ un conjunto dotado de una operación binaria.
Se denomina _elemento neutro de $\circ$_ (o también elemento __identidad__)
de $(A,\circ)$ a todo elemento $e\in A$ tal que
$$ a\circ e = e\circ a = a $$
para cualquier $a \in A$.

### Definición (Inversible)
Diremos que $a$ es inversible a izquierda (en $A$), o que tiene un opuesto (o un inverso)
a izquierda en $A$ si existe $c \in A$ tal que
$$ c \circ a = e $$.
Análogamente para inversible a derecha.

Asimismo, decimos que es _inversible_ si 
$$ \exists t \in A : a \circ t = t \circ a = e$$

### Proposición
Sea $(A,\circ)$ un semigrupo con elemento neutro $e$. Entonces $a\in A$ es inversible
si y sólo si es inversible a izquierda y a derecha.

### Corolario
Si $a$ es inversible, su inverso en único.

### Notación
$a'$ es el opuesto de $a$

### Proposición
(i) si $a,c \in A$ son inversibles también lo es su producto y vale la igualdad:
$$(a\circ b)' = c' \circ a'$$
(ii) si $a$ es inversible, entonces:
$$(a')' = a$$.

### Definición (Grupo)
