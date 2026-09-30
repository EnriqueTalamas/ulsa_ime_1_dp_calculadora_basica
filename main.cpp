// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué funciones trae ahora utilerias.h? ¿Qué devuelve cada una?
#include "utilerias.h"

int main() {
double numero1;
double numero2;
int opcion;
std::cout << "Calculadora basica" << std::endl;
std::cout << "Menu: 1) Suma  2) Resta  3) Multiplicacion  4) Division" << std::endl;
std::cout << "Seleccione un numero del 1-4 para realizar su operacion: ";
std::cin >> opcion;

while (opcion < 1 || opcion > 4) {
    std::cout << "Error, no existe esa opcion. Seleccione un numero del 1-4 para realizar su operacion: ";
    std::cin >> opcion;
}

std::cout << "Seleccionaste la opcion " << opcion << std::endl;

switch (opcion) {
        case 1:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> numero1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> numero2;
            std::cout << "El resultado de la suma es: " << (numero1 + numero2) << std::endl;
            break;
        case 2:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> numero1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> numero2;
            std::cout << "El resultado de la resta es: " << (numero1 - numero2) << std::endl;
            break;
        case 3:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> numero1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> numero2;
            std::cout << "El resultado de la multiplicacion es: " << (numero1 * numero2) << std::endl;
            break;
        case 4:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> numero1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> numero2;
            if (numero2 == 0) {
                std::cout << "Error: No se puede dividir entre cero." << std::endl;
            } else {
                std::cout << "El resultado de la division es: " << (static_cast<double>(numero1) / numero2) << std::endl;
            }
        }
        


    // Variables (siempre inicializadas)
    // TODO: opcion, a, b, resultado y simbolo.
    //       ¿De qué tipo es cada una? Revisa la sección 2 de tu README.
    //       ¿Con qué valor empieza un char?

    // Pasos 1 y 2: título y menú
    // TODO

    // Paso 3: leer la opción con leerEntero y repetir si no está entre 1 y 4
    // TODO: ¿qué ciclo usaste en la Práctica 3 para volver a pedir un dato?

    // Pasos 4 y 5: leer los dos números con leerDecimal
    // TODO

    // Paso 6: SOLO si la opción es división, ¿qué haces si b es 0?
    // TODO

    // Paso 7: decisión múltiple
    // TODO: switch (opcion) { case 1: ... break; ... default: ... }
    //       ¿Qué pasa si olvidas un break? (Experimento A)

    // Paso 8: salida -> a simbolo b = resultado
    // TODO

    // ¿Qué significa return 0;?
    return 0;
}