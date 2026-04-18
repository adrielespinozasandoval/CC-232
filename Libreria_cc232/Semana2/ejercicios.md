# Ejercicio 6

1. - `insert(r, e)` inserta un valor e a la posición `r`.
    1. Revisa que `r` sea una posición valida para insertar.
    2. Llama a `expand()`, que expande el vector si es necesario.
    3. Realiza un bucle que mueve los elementos de `_size` a `r` una posición hacia la derecha.
    4. Coloca el elemento en su posición.
    5. Añade 1 al tamaño.
    6. Devuelve la posición.
   - `add(i, x)` añade un valor `x` a la posición `i`.
    1. Si el nuevo tamaño no cabe en el arreglo, expandir.
    2. Realiza el bucle que mueve elementos de `_size` a `r` una posición hacia la derecha.
    3. Coloca el elemento en su posición
    5. Añade 1 al tamaño
2. Porque la inserción requiere de poner entre medio ese valor, requiriendo el desplazamiento de todos los elementos posteriores.
3. Porque se está añadiendo un nuevo elemento desde atrás, moviendo todos los demás hacia adelante. Se empieza desde la última posición para no perder los anteriores.
4. Porque el desplazamiento requiere un bucle de n - i pasadas, siendo i de 0 a n. Si se distribuye uniformemente, en promedio i es n/2. (n-n/2)*O(1) = O(n).
5. Insertar al inicio requiere n - 0 = n pasadas. Insertar al final requiere n - n = 0 pasadas, solo modificar el elemento n