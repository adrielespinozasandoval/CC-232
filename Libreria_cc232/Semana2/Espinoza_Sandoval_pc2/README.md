## PC2 - CC232

### Estudiante
- Nombre: Espinoza Sandoval, Adriel Alejandro
- Código: 20243502F
- Problema asignado: Codeforces 670E - Correct Bracket Sequence Editor
- Enlace: https://codeforces.com/problemset/problem/670/E,adriel.espinoza.s@uni.pe

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana: 4
- Estructura o técnica principal: `Stack` (según lo visto en clase), Árbol (según implementación principal)

### Resumen de la solución
La solución es en identificar el grupo de paréntesis a borrar. Esto se puede lograr de varias maneras, pero esta en concreto usó en principio un árbol cuyos nodos representan un grupo y sus hijos los que están dentro de él. La clase `BracketSequence` implementa y maneja la parte algorítmica más complicada. 

### Complejidad
#### `BracketSequence`:
- Tiempo: $O(n)$ (varía en el caso de borrado)
- Espacio: $O(n)$ en creación y conversión, $O(1)$ en borrado

### Invariante o idea clave
- En la solución del árbol solo se necesita borrar el nodo padre para que todos los descendientes queden sueltos del árbol.

### Archivos relevantes
- `include/BracketSequence.h` declara la clase
- `src/BracketSequence.cpp` implementa la clase
- `docs/BracketSequence.md` documenta la API pública de la clase
- `demos/demo_bracketsequence.md`

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```bash
./build/tu_programa
```

### Casos de prueba
Describe al menos 3 casos:
1. Caso `(()(()))` con cursor posición 2.
- La cadena vuelve a `((()))` y el cursor está en la posición 2.
2. Caso `(()(()))` con cursor posición 7.
- La cadena se vuelve `(())` y el cursor está en la posición 4
3. Caso `()` con cursor posición 2.
- La cadena se vuelve vacía.

**Nota:** En C++ por defecto el cursor se inicia 0 y no desde 1.

### Historial de commits
Indica que el historial debe verse en el video.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.