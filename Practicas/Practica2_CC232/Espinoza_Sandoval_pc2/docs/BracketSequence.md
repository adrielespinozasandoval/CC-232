# Documentación de `BracketSequence`

La clase `BracketSequence` está diseñada para representar y manipular eficientemente secuencias de paréntesis anidados, como por ejemplo `(())()` o `()(()())`.

## Representación Interna

Internamente, la secuencia no se almacena como una simple cadena de texto, sino como una estructura de **árbol** (o más precisamente, un bosque de árboles).

-   Cada par de paréntesis `()` en la secuencia se corresponde con un `Nodo` en el árbol.
-   Si un par de paréntesis se encuentra anidado dentro de otro, su `Nodo` se convierte en un **hijo** del `Nodo` que representa al par exterior.
-   Una secuencia como `()(())` se representa como dos árboles distintos en un "bosque", uno para `()` y otro para `(())`.

Esta representación en árbol permite que operaciones como encontrar el paréntesis de cierre correspondiente o eliminar un par completo sean mucho más eficientes que si se realizaran directamente sobre una cadena de texto.

## Funcionalidades Principales

La clase ofrece una interfaz clara para interactuar con la secuencia de paréntesis.

### Construcción

```cpp
BracketSequence(std::string seq);
```
El constructor recibe una cadena (`std::string`) que contiene la secuencia de paréntesis. Durante la construcción se valida que sea una secuencia válida (por ejemplo, que no empiece con un paréntesis de cierre). Si lo es, parsea la cadena y construye la estructura de árbol interna que representa la anidación de los paréntesis. Esto se logra principalmente con la función recursiva privada `build`.

### Eliminación de paréntesis
```cpp
size_t delBracketPos(size_t i);
```
Permite eliminar un par de paréntesis de la secuencia.

Recibe como argumento el índice `i` del paréntesis de apertura `(` que se desea eliminar.
La función localiza el Nodo correspondiente a ese paréntesis.
Elimina el Nodo (y con él, todo su subárbol de hijos), lo que equivale a eliminar el par de paréntesis () y todo su contenido. Actualiza las posiciones y los índices de los nodos hermanos para mantener la consistencia de la estructura.
Devuelve la posición en la secuencia donde comenzó la eliminación.