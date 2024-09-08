#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERROR_CREACION_PROCESO 2
#define TIEMPO_DE_ESPERA_PARA_CREACION 2

pid_t crearProceso(char nombre);
void crearJerarquiaDeProcesos();

pid_t crearProceso(char nombre)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        return ERROR_CREACION_PROCESO;
    }
    if (pid == 0)
    {
        printf("Proceso %c: %d\n",nombre,getpid());
    }
    sleep(TIEMPO_DE_ESPERA_PARA_CREACION);
    return pid;
}

void crearJerarquiaDeProcesos()
{
    pid_t pidB = crearProceso('B');

     // Estoy en A
    if (pidB != 0)
    {
        printf("Proceso A: %d\n",getpid());
        wait(NULL);                        // Wait de A
        exit(0)   ;                   // Exit de A
     // Estoy en B
    }
    else
    {
        pid_t pidC = crearProceso('C');

         // Estoy en B
        if (pidC != 0)
        {
            pid_t pidD = crearProceso('D');

             // Estoy en D
            if (pidD == 0)
            {
                pid_t pidF = crearProceso('F');

                 // Estoy en D
                if (pidF != 0)
                {
                    pid_t pidG = crearProceso('G');

                     // Estoy en D
                    if (pidG != 0)
                    {
                        wait(NULL);        // Wait de D
                        exit(0);      // Exit de D
                    }
                    else
                    {
                        exit(0);      // Exit de G
                    }
                }
                else
                {
                    exit(0);          // Exit de F
                }
            }
            wait(NULL);                   // Wait de B
            wait(NULL);
            exit(0);                // Exit de B
         // Estoy en C
        }
        else
        {
            pid_t pidE = crearProceso('E');

             // Estoy en E
            if (pidE == 0)
            {
                pid_t pidH = crearProceso('H');

                 // Estoy en E
                if (pidH != 0)
                {
                    pid_t pidI = crearProceso('I');

                     // Estoy en E
                    if (pidI != 0)
                    {
                        wait(NULL);         // Wait de E
                        wait(NULL);
                        exit(0);      // Exit de E
                    }
                    else
                    {
                        exit(0);      // Exit de I
                    }
                }
                else
                {
                    exit(0);          // Exit de H
                }
            }
            else
            {
                wait(NULL);                  // Wait de C
                exit(0);
            }
        }
    }
}

void main()
{
    crearJerarquiaDeProcesos();
    sleep(20);
}
