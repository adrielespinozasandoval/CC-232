### Semana 3 · Listas enlazadas, pilas, colas y deques

Esta carpeta contiene una implementación **funcional y autocontenida** de los contenidos centrales de la semana 3 del curso: **listas enlazadas simples y dobles, pilas, colas y deques**, junto con demos, pruebas públicas y un benchmark corto.

El objetivo principal es comparar **representaciones enlazadas** y **representaciones contiguas**, entendiendo cómo cambian la interfaz, la complejidad temporal, el uso de memoria y la localidad de referencia.

#### Contenido principal

La carpeta incluye las siguientes estructuras y adaptadores:

- `SLList.h`: lista simplemente enlazada
- `DLList.h`: lista doblemente enlazada
- `SEList.h`: lista enlazada por bloques
- `ArrayDeque.h`: deque contiguo usado para comparación
- `LinkedStack.h`: adaptador de pila sobre `SLList`
- `LinkedQueue.h`: adaptador de cola FIFO sobre `SLList`
- `LinkedDeque.h`: adaptador de deque sobre `DLList`
- `MinStack.h`, `MinQueue.h`, `MinDeque.h`
- `XorList.h`

#### Nota sobre `Capitulo3.h`

El header `include/Capitulo3.h` **no reexporta** `DengList.h` ni `MorinDengBridge.h`.

Esto se hizo para que `Semana3` pueda compilarse y usarse de forma independiente, sin obligar a depender del wrapper de Deng. En otras palabras, el núcleo de esta carpeta queda centrado en:

- Listas enlazadas de Morin
- Adaptadores enlazados `Stack`, `Queue` y `Deque`
- Comparación con una estructura contigua (`ArrayDeque`).

Las piezas relacionadas con Deng pueden seguir existiendo, pero quedan como **componentes opcionales**.

#### Organización práctica

Además de los headers, esta carpeta incluye:

- Demostraciones de uso básico
- Pruebas públicas
- Un benchmark corto para comparación experimental.

