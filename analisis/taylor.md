En una variable tenemos el **polinomio de taylor**:
</br>

$$P_{n,p}(x) = \sum_{k=0}^n \frac{f^{(k)}(p)}{k!}(x-p)^k $$

La forma de Lagrange del resto:

$$ R_{n,p}(x) = \frac{f^{(n+1)}(c)}{(n+1)!}(x-p)^{(n+1)}$$
 c entre x y p.

Y el **teorema de taylor**:

$$ f(x) = P_{n,p}(x) + R_{n,p}(x) $$

En campos escalares tenemos la **_fórmula de Taylor de primer orden_**:

$$ f(x) = f(p) +  \langle \nabla f , x-p\rangle + R_{1,p}(x) $$

Y la **_fórmula de Taylor de segudo orden_**:

$$ f(x) = f(p) +  \langle \nabla f_p , x-p\rangle
   + (x-p)^T Hf_p (x-p)
   + R_{2,p}(x) $$

Donde:

$$ Hf_p
= \left( \begin{array}{cccc}
f_{x_1x_1} & f_{x_1x_2} & \dots & f_{x_1x_n} \\
f_{x_2x_1} & \dots & \dots & f_{x_2x_n}\\
\vdots & \vdots & \ddots & \vdots \\
f_{x_nx_1} & f_{x_nx_2} & \dots & f_{x_nx_n}\end{array} \right)
$$

Con otra notación:


$$ Hf_p
= \left( \begin{array}{cccc}
\frac{\partial^2f}{\partial^2x_1} & \frac{\partial^2f}{\partial x_1x_2}
& \dots &  \frac{\partial^2f}{\partial x_1x_n} \\
\frac{\partial^2f}{\partial x_2x_1}
& \dots & \dots & \frac{\partial^2f}{\partial x_2x_n} \\
\vdots & \vdots & \ddots & \vdots \\
\frac{\partial^2f}{\partial x_nx_1} &
\frac{\partial^2f}{\partial x_nx_2} &
\dots &
\frac{\partial^2f}{\partial x_nx_n} 
\end{array} \right)
$$
