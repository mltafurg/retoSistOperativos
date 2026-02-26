# Reto 1: Creación de la shell EAFITOS
## Link para el video: https://youtu.be/mHBHF6zUu0M
---
# INTEGRANTES:
1. Nawal Oriana Valoyes Rentería
2. Maria Laura Tafur
3. Ana Sofía Angarita
---
## DESCRIPCIÓN:
EAFITos es una shell interactiva desarrollada en C con fines educativos, diseñada para que los estudiantes puedan practicar y entender conceptos clave de **Sistemas Operativos**, como manejo de archivos, ejecución de comandos y gestión de procesos básicos.  
El proyecto simula un entorno real de línea de comandos, permitiendo ejecutar comandos tanto básicos como avanzados, y proporciona una plataforma segura para experimentar con operaciones sobre el sistema de archivos sin afectar el entorno principal.  

Entre sus objetivos principales se incluyen:
- Implementar comandos de manera modular, promoviendo buenas prácticas de programación en C.
- Facilitar la comprensión de estructuras de datos, flujo de control y manejo de errores en un shell.
- Fomentar el trabajo colaborativo en proyectos de software.

Esta shell incluye comandos básicos como listar archivos, leer contenido y calcular operaciones matemáticas, así como comandos avanzados de gestión de archivos (`crear`, `eliminar`, `renombrar`, `buscar`) que permiten a los usuarios interactuar con el sistema de forma más completa.

---

## Porcentajes

| Nombre        | Código | Rol        | Tareas Asignadas                                         | % Contribución |
|---------------|--------|------------|--------------------------------------------------------  |----------------|
| Oriana        | 1001   | Dev/doc    | Comandos: crear, eliminar y uso de Doxygen               | 34%            | 
| Laura         | 1002   | Dev/doc    | Comando buscar , documentación general y pruebas         | 33%            |
| Ana Sofía     | 1003   | Dev/doc    | Comando renombrar, README.md , documentación general     | 33%            |


**Total:** 100%
---

## Diagrama de Arquitectura del Proyecto:
```
eafitos/
├── build/ # Binarios y archivos generados
├── docs/ # Documentación del proyecto
│ ├── API.md
│ ├── DESIGN.md
│ ├── DOCUMENTATION.md
│ └── USER_GUIDE.md
├── include/ # Headers
│ ├── shell.h
│ ├── commands.h
│ └── utils.h
├── scripts/ # Scripts auxiliares
│ ├── build.sh
│ └── format.sh
├── src/ # Código fuente
│ ├── core/ # Núcleo del shell
│ │ ├── main.c
│ │ ├── shell_loop.c
│ │ └── parser.c
│ ├── commands/ # Comandos implementados
│ │ ├── basic_commands.c
│ │ ├── file_commands.c
│ │ ├── system_commands.c
│ │ └── advanced_commands.c
│ └── utils/ # Funciones auxiliares
│ ├── memory_manager.c
│ ├── error_handler.c
│ └── helpers.c
├── tests/ # Pruebas
│ ├── unit_tests.c
│ ├── integration_tests.c
│ └── test_runner.sh
├── CHANGELOG.md
├── CONTRIBUTORS.md
├── DOXYFILE
├── LICENSE
├── Makefile
└── README.md
```
---
## Para compilar:
Para ejecutar la shell **EAFITos** desde la terminal:

1. Abre la terminal y ubícate en la carpeta raíz del proyecto.
2. Ejecuta el binario dentro de la carpeta `build`:
./build/sistema_os

Veras algo como:
Iniciando EAFITos v1.0...
Escribe 'ayuda' para comenzar.

EAFITos>

---
## Guía de Uso

## Comandos Básicos (6):

1. listar : Lista los archivos del directorio actual.
2. leer <archivo> : Muestra el contenido de un archivo de texto.
3. tiempo : Muestra la fecha y hora actual.
4. calc <num1> <operador> <num2> : Calculadora básica (+, -, *, /).
5. ayuda : Lista todos los comandos disponibles.
6. salir : Termina la shell.

## Comandos Avanzados de Archivos (implementados):

1. crear <archivo> : Crea un archivo vacío.
2. eliminar <archivo> : Elimina un archivo con confirmación.
3. renombrar <viejo> <nuevo> : Renombra un archivo.
4. buscar <texto> <archivo> : Busca un texto dentro de un archivo.

---
## EJEMPLOS DE USO:
```
EAFITos> listar
archivo1.txt  archivo2.txt  README.md

EAFITos> crear nuevo.txt
Archivo 'nuevo.txt' creado correctamente.

EAFITos> renombrar nuevo.txt documento.txt
Archivo renombrado de 'nuevo.txt' a 'documento.txt'.

EAFITos> eliminar documento.txt
¿Está seguro de eliminar 'documento.txt'? (s/n): s
Archivo eliminado.
```






