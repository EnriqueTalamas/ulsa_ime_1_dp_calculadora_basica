# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
Calculadora basica
Menu: 1) Suma  2) Resta  3) Multiplicacion  4) Division
Seleccione un numero del 1-4 para realizar su operacion
4
Seleccionaste la opcion 4
Ingrese el primer numero: 5
Ingrese el segundo numero: 0
Error, no se puede dividir entre cero


## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | __std::cout <<"  "<<endl;___ |
| 3. Leer y validar la opción | __std::cin >>___ |
| 4 y 5. Leer `a` y `b` | __int leerEntero___ |
| 6. Validar el divisor | __(static_cast<double>(numero1) / numero2)___ |
| 7. Decisión múltiple (un `case`) | _switch, case y el brake____ |
| 8. Mostrar el resultado | _<< (numero1 + numero2)____ |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
__Si el paso 6 porque no lograba que se repitiera la funcion___

## 9. Experimentos (Fase 3)

**Experimento A: sin el `break` del `case 1`, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó?**
_Mostro 3, paso porque continuo con el siguiente caso____

**Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido?**
_Marco error por que no es posible la division de 5/0.____

**Experimento C (opcional): con `a` y `b` de tipo `int`, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?**
__mostro 3 y no me aviso de nada el compilador.___

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | __13___ | __si___ | 
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | ___-2__ | __si___ |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 | ___10__ | ___si__ |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | ____-12_ | __si___ |
| División | 4, 7, 2 | 7 / 2 = 3.5 | ___3.5__ | __si___ |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | ___error__ | ___si__ |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | ____2.5_ | _si____ |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | __escribe otro numero___ | __si___ |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | __13___ | __si___ |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | __13___ | __si___ |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 | __-2___ | _si____ |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 | __13___ | ___si__ |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | __13___ | __si___ |
| Caso propio 1 | ___sumar 100,  200__ | __300___ | _300____ | ___si__ |
| Caso propio 2 | _dividir 500 / 45 ____ | ___11.1111__ | ___11.1111__ | ___si__ |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | __Que cuando escribiera un numero que no es valido de las opciones volviera a preguntar.___ | __con un while___ | __si__ |
| 2 | _Mejorar la forma que aparece en la pantalla____ | ___mover los renglones __ | __si___ |

**¿Encontré algo que la receta no contemplaba? ¿Qué?**
_si que repita las funciones si es que no son correctas____

**Reto elegido (opcional):** _Identificar cuando va un while un for y un if____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| __Para que es el if else___ | ___para poner una condicion en un entonces__ |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
_A utilizar el while____

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
___El usar un if else pra facilitar e codigo__

**¿Qué fue lo más difícil y cómo lo resolví?**
__El repetir una pregunta si da una respuesta invalida___

**¿Qué pregunta me quedó sin responder?**
__Cuando se utiliza un else?___

**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
___Si, porque me puedo dar cuenta de cosas que no tenia pensadas__

**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
__Las preguntas de If o si porque es mas facil hacerlo con while___

## 14. Lista de verificación antes de entregar (Fase 5)

- [si ] Llené las secciones 7 a 13 (no quedan `_no____`)
- [si ] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [si ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [si ] Mi programa compila sin advertencias
- [si ] Probé todos los casos de la tabla
- [si ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [si ] No modifiqué `utilerias.h`
- [si ] Hice al menos 4 commits con mensajes claros
- [si ] Hice `git push` y verifiqué mi fork en GitHub
- [si ] Entregué el enlace de mi fork en Classroom