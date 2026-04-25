# Actividad 3 - CC232

### Integrantes
- Espinoza Sandoval, Adriel Alejandro

## Bloque 1

1. En vez de que los elementos se guarden de forma contigua físicamente en memoria, se guardan punteros que pueden dirigir a distintos puntos de ella.
2. El acceso por rango es por la contigüidad, mientras que por posición accede a cualquier posición arbitraria de la memoria física.
3. Porque al insertar o eliminar solamente se necesitan actualizar los enlaces de los elementos anterior y siguiente (complejidad O(1)), pero al acceder por índice se requiere hacer un bucle para acceder a los enlaces hasta llegar a esa posición (complejidad promedio O(n))
4. Porque implementa de la misma forma que un stack push y pop (haciéndolo del inicio), y de un queue add y pop.
5. Porque para remover un elemento del final se requiere el enlace del anterior elemento, teniendo que acceder a los enlaces de todos los elementos anteriores.
6. El nodo aporta la cabeza y cola de la lista enlazada.
7. Porque dependiendo de si está cerca del inicio o final de la lista, procede por allí.
8. SEList usa ArrayDeque enlazadas.
9. Para adaptar sus funcionalidades para la implementación de SEList.
10. Es un adaptador de los métodos de `CleanList`. No reemplaza ya que es solamente una implementación una estructura de lista doblemente enlazada.