# Actividad 3 - CC232

### Integrantes
- Espinoza Sandoval, Adriel Alejandro

## Bloque 1

1. En vez de que los elementos se guarden de forma contigua físicamente en memoria, se guardan punteros que pueden dirigir a distintos puntos de ella.
2. El acceso por rango es por la contigüidad, mientras que por posición accede a cualquier posición arbitraria de la memoria física.
3. Porque al insertar o eliminar solamente se necesitan actualizar los enlaces de los elementos anterior y siguiente (complejidad $O(1)$), pero al acceder por índice se requiere hacer un bucle para acceder a los enlaces hasta llegar a esa posición (complejidad promedio $O(n)$)
4. Porque implementa de la misma forma que un stack push y pop (haciéndolo del inicio), y de un queue add y pop.
5. Porque para remover un elemento del final se requiere el enlace del anterior elemento, teniendo que acceder a los enlaces de todos los elementos anteriores.
6. El nodo aporta la cabeza y cola de la lista enlazada.
7. Porque dependiendo de si está cerca del inicio o final de la lista, procede por allí.
8. SEList usa ArrayDeque enlazadas.
9. Para adaptar sus funcionalidades para la implementación de SEList.
10. Es un adaptador de los métodos de `CleanList`. No reemplaza ya que es solamente una implementación una estructura de lista doblemente enlazada.

## Bloque 2

|Archivo|Salida y observable importante|Idea estructural|Argumento de costo, espacio o diseño|
|---|---|---|----|
|`Semana3/demos/demo_sllist.cpp`|`size = 3,peek = 5, pop = 5, remove = 10`|Lista enlazada simple||
|`Semana3/demos/demo_dllist.cpp`|`DLList: 10 20 30`|Lista enlazada doble|`add`: $O(1)$ `get`: $O(n)$|
|`Semana3/demos/demo_selist.cpp`|`0 10 20 30 40 50 60 70 80 90`|Lista de ArrayDeque enlazada|||`Semana3/demos/demo_deng_list.cpp`||Lista de Deng||
|`Semana3/demos/demo_morin_deng_bridge.cpp`||Lista enlazada de Deng||
|`Semana3/demos/demo_capitulo3_panorama.cpp`||Panorama de las distintas estructuras||
|`Semana3/demos/demo_min_structures.cpp`|`MinStack min=3 top=7, Min Queue min=2 front=4, MinDeque min=1 front=3 back=1`|Estructuras mínimas||
|`Semana3/demos/demo_xor_list.cpp`|`XorList: 5 10 20, front=5 back=20`|Lista XOR||
|`Semana3/demos/demo_linked_adapters.cpp`||Adaptadores de estructas con enlaces||
|`Semana3/demos/demo_contiguous_vs_linked.cpp`||Lista contigua vs enlazada||

## Bloque 3

1. Valida el comportamiento de `add`, `push`, `size`, `peek`, `pop`, `remove` y `size`.
2. Valida el comportamiento de `add`, `size`, `get`, `remove` y `size`
3. Valida el comportamiento de `add`, `size`, `get`, `remove` y `size`
4. `to_vector`, `secondLast`, `checkSize`, `rotate`, `isPalindrome`, `remove `, `front`
5. Los comportamientos de un `Stack`, `LinkedStack`, `LinkQueue` y `LinkDeque`.
6. La reutilización de la funciónes de ordenamiento y conversión a vector.
7. Se estresa su estabilidad por medio de la ocupación de la lista en memoria, haciendola crecer y decrecer.
8. Un comportamiento mínimo esperado de las funciones.
9. No demuestra comportamientos más internos, como invariantes, costos, casos bordes, etc.
10. Porque comportamientos internos requieren de análisis del algoritmo.