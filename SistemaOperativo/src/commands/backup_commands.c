/**
 * @file backup_commands.c
 * @brief Comando de respaldo integrado en la shell EAFITos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void cmd_respaldo(char **args) {
    if (args[1] == NULL) {
        printf("Uso:\n");
        printf("  respaldo --iniciar <origen> <destino>\n");
        return;
    }

    if (strcmp(args[1], "--iniciar") == 0) {
        if (args[2] == NULL || args[3] == NULL) {
            printf("Error: debes indicar origen y destino.\n");
            printf("Uso: respaldo --iniciar <origen> <destino>\n");
            return;
        }

        FILE *yaml = fopen("/tmp/respaldo_temp.yaml", "w");
        if (!yaml) {
            printf("Error: no se pudo crear configuracion temporal.\n");
            return;
        }
        fprintf(yaml, "interval: 10\n");
        fprintf(yaml, "files:\n");
        fprintf(yaml, "  - source: %s\n", args[2]);
        fprintf(yaml, "    destination: %s\n", args[3]);
        fclose(yaml);

        printf("Iniciando respaldo de '%s' en '%s'...\n", args[2], args[3]);

        char comando[512];
        snprintf(comando, sizeof(comando),
                 "../../Backup_Filter_SO_Delivery2/backup_app /tmp/respaldo_temp.yaml");
        system(comando);

    } else {
        printf("Opción no reconocida: %s\n", args[1]);
        printf("Uso: respaldo --iniciar <origen> <destino>\n");
    }
}
