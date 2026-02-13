/**
 * @file file_commands.c
 * @brief Comandos para manipulación y visualización de archivos.
 * 
 * Implementa funcionalidades similares a 'ls' (listar) y 'cat' (leer) de Unix,
 * interactuando con las APIs del sistema de archivos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // Librería POSIX para manejo de directorios
#include "commands.h"
#include <unistd.h>  // Para el comando rename()


/**
 * @brief Comando LISTAR (ls)
 * 
 * Abre el directorio actual (".") e itera sobre sus entradas para mostrar los nombres.
 * 
 * @param args Argumentos del comando (ignorados en esta versión simple).
 */
void cmd_listar(char **args) {
    DIR *d;               // Puntero al flujo del directorio
    struct dirent *dir;   // Estructura que representa una entrada (archivo/carpeta)

    // opendir(): Abre un flujo de directorio correspondiente al directorio dado.
    d = opendir(".");
    
    if (d) {
        printf("Archivos en el directorio actual:\n");
        // readdir(): Lee la siguiente entrada del directorio. Retorna NULL al final.
        while ((dir = readdir(d)) != NULL) {
            // Filtramos las entradas especiales "." (actual) y ".." (padre) para limpiar la salida
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                printf("  %s\n", dir->d_name);
            }
        }
        // closedir(): Cierra el flujo y libera recursos asociados.
        closedir(d);
    } else {
        // perror(): Imprime un mensaje de error descriptivo basado en el valor global 'errno'
        perror("Error al abrir directorio");
    }
    (void)args;
}

/**
 * @brief Comando LEER (cat)
 * 
 * Abre un archivo en modo lectura, lee su contenido caracter por caracter
 * y lo imprime en la terminal.
 * 
 * @param args args[1] debe contener la ruta o nombre del archivo a leer.
 */
void cmd_leer(char **args) {
    // Validación básica: ¿El usuario pasó el nombre del archivo?
    if (args[1] == NULL) {
        printf("Error: Debes especificar un archivo para leer.\nUso: leer <nombre_archivo>\n");
        return;
    }

    // fopen(): Abre el archivo especificado en modo lectura ("r").
    // Retorna un puntero a FILE o NULL si falla (ej. archivo no existe).
    FILE *fp = fopen(args[1], "r");
    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo '%s'. Verifique que exista.\n", args[1]);
        return;
    }

    char ch;
    // fgetc(): Lee el siguiente caracter del flujo.
    // El bucle continúa hasta encontrar EOF (End Of File).
    while ((ch = fgetc(fp)) != EOF) {
        // putchar(): Escribe un caracter en la salida estándar (consola).
        putchar(ch);
    }
    printf("\n"); // Salto de línea estético al final

    // fclose(): Es crítico cerrar los archivos para evitar fugas de recursos.
    fclose(fp);
}
/**
 * @brief Comando RENOMBRAR
 * 
 * Cambia el nombre de un archivo existente utilizando la función estándar
 * rename() de la librería POSIX.
 * 
 * Este comando recibe dos argumentos:
 * - args[1]: nombre actual del archivo.
 * - args[2]: nuevo nombre que se desea asignar.
 * 
 * Si la operación falla (por ejemplo, si el archivo no existe o no hay
 * permisos suficientes), se muestra un mensaje descriptivo del error.
 * 
 * @param args Arreglo de argumentos ingresados por el usuario.
 */
void cmd_renombrar(char **args) {
    // Validación básica: verificar que se hayan proporcionado ambos argumentos.
    if (args[1] == NULL || args[2] == NULL) {
        printf("Error: Uso incorrecto.\nUso: renombrar <archivo_viejo> <archivo_nuevo>\n");
        return;
    }

    // rename(): Cambia el nombre del archivo especificado.
    // Retorna 0 si la operación fue exitosa.
    // Retorna -1 en caso de error y establece errno.
    if (rename(args[1], args[2]) == 0) {
        printf("Archivo '%s' renombrado a '%s' exitosamente.\n", args[1], args[2]);
    } else {
        perror("Error al renombrar el archivo");
    }
}

/**
 * @brief Comando BUSCAR
 * 
 * Busca una cadena de texto dentro de un archivo.
 * 
 * Este comando recibe dos argumentos:
 * - args[1]: texto a buscar.
 * - args[2]: nombre del archivo donde buscar.
 * 
 * Si la operación falla (por ejemplo, si el archivo no existe o no hay
 * permisos suficientes), se muestra un mensaje descriptivo del error.
 * 
 * @param args Arreglo de argumentos ingresados por el usuario.
 */


void cmd_buscar(char **args){
    // Validación básica: verificar que se hayan proporcionado ambos argumentos.
     if (args[1] == NULL || args[2] == NULL) {
        printf("Error: Uso incorrecto.\nUso: buscar <texto> <archivo>\n");
        return;
    }
    //declaracion de un puntero tipo archivo y un array para almacenar el contenido del archivo
    FILE *ptr;
    char contentFile[1000];
    // funcion para abrir el archivo en modo lectura (r es read), devuelve null si no se pudo abrir el archivo
    ptr = fopen(args[2],"r");
    // condicional donde si se abre el archivo (no hay null) 
    if(ptr != NULL){
        // si entramos al if, el archivo se lee con fgets y lo guarda en un array (contenFile), 
        // fgets lee una linea del archivo (es linea por linea), el ciclo se repite hasta que no haya mas lineas (fgets devuelve null)
        while(fgets(contentFile,1000,ptr) != NULL){
            // en este ciclo revisamos con strstr (que es la funcion que permite buscar un substring dentro de un string)
            // si el texto que el user dio esta en el archivo, si no lo encuentra sigue al siguiente ciclo
             if(strstr(contentFile, args[1])!=NULL){
                // si lo encuntra imprime la linea del archivo donde se encuentra el texto
            printf("%s", contentFile);
        }
        }
     fclose(ptr);   
    }else{
        printf("Error: no se pudo abrir el archivo '%s'. Verifique que exista.\n", args[2]);
    }
}
