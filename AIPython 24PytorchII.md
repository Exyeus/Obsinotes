Codin in this way: style advocated by those authors.

describ: Having reached the final step, then using `backward` for those tensors whose attr `req-grad=True`, get its prl func value for all tensors as its arguments.

This makes it easy for us to imple't those training needing back propagation?/?.

> [!info] 
> keys:
> - data
> - tsk
> - model - inherit nn.Module. The instance is callable as functions. Models can be combined to form more cplex models. Models recv inputs and outputs.
> 	Parameter class: instances can be used in models, in trainin process.


`layer.parameters` is a iterator!

`__call__` sp method shod be implemented for `model` s.
defining is not enough, and we need algos more!

we need loss function to train the model, and we can attain those loss funcs provided inside pytorch.
After setting the loss function, we need to *train* the model.

> [!important] 
> needed:
> - optimizer
> - model.parameters

the process will be recorded in Model.parameter. Paramtr have `require_grad` intrinsically.

### Coding to realize the process.

1. implmt `Linear_Model` class.
2. 1
3. 2
4. 4

`SGD` in the code repr a type of optimizer.

### Exploration into Autograd


$$\frac{dy}{dx}=\left( \frac{\partial}{\partial z_{1}}y, \frac{\partial}{\partial z_{2}} y \right)\cdot \begin{pmatrix}
\frac{\partial}{\partial x} z_{1} \\ 
\frac{\partial}{\partial x} z_{2}
\end{pmatrix}$$
Amazing formulae: There seems to exist some LINALG principles behind!

*vector calculus*?
$\mathbf{y} =f(\mathbf{x})$
Jacobian Mat': Not Jacobian Determinant!
the input and output may come from diff *vector spaces*! so this mat' is not necessarily a square!
Please refer to this formula in PPT.
Based on linearity in mat multi'tn, the elements in J MAT can repr the results from operating partial derivatives on the *output valuable*, with each *x*'s from the *input space*.
$$\mathbf{v}\cdot \mathbf{J}_f=\frac{\partial}{\partial x's}\text{Loss}$$ *Example*.
$\mathbf{y}=f(\mathbf{u}),\mathbf{u}=g(\mathbf{x}), l=g(\mathbf{y})$

> [!info]
> Relu Function
> $$f(x)=\begin{cases}
> 0,x<0 \\
> x, x\geq {0}
> \end{cases}$$


### Computation Graph

Ongoing naturally until reaching the leaf nodes.

... Complement this part using gemini

### Code practice







