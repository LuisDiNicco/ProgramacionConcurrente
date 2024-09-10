#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERROR_CREACION_PROCESO 2
#define TIEMPO_DE_ESPERA_PARA_CREACION 10
#define TIEMPO_ESPERA_FINAL 10

pid_t crearProceso(char nombre);
<<<<<<< HEAD
void manejarProcesoA();
void manejarProcesoB();
void manejarProcesoC();
void manejarProcesoD();

pid_t crearProceso(char nombre)
{
  pid_t pid = fork();
  if (pid < 0)
  {
    return ERROR_CREACION_PROCESO;
  }
  if (pid == 0)
  {
    printf("Proceso %c: %d\n", nombre, getpid());
    fflush(stdout);
  }
  sleep(TIEMPO_DE_ESPERA_PARA_CREACION);
  return pid;
}

void manejarProcesoA()
{
  pid_t pid_b = crearProceso('B');
  if (pid_b != 0)  // Estoy en A
  {
    printf("Proceso A: %d\n", getpid());
    wait(NULL);  // Wait de A
    exit(0);     // Exit de A
  }
  else
  {
    manejarProcesoB();  // Estoy en B
  }
}
=======
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
>>>>>>> 256366eb0cce9987e935f7b194fb2baf8203122d

void manejarProcesoB()
{
  pid_t pid_c = crearProceso('C');
  if (pid_c != 0)  // Estoy en B
  {
    manejarProcesoD();  // Estoy en D
    wait(NULL);         // Wait de B
    wait(NULL);
    exit(0);            // Exit de B
  }
  else
  {
    manejarProcesoC();  // Estoy en C
  }
}

void manejarProcesoD()
{
  pid_t pid_d = crearProceso('D');
  if (pid_d == 0)  // Estoy en D
  {
    pid_t pid_f = crearProceso('F');
    if (pid_f != 0)
    {
      pid_t pid_g = crearProceso('G');
      if (pid_g != 0)
      {
        wait(NULL);  // Wait de D
        exit(0);     // Exit de D
      }
      else
      {
        exit(0);     // Exit de G
      }
    }
    else
    {
<<<<<<< HEAD
      exit(0);       // Exit de F
=======
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
>>>>>>> 256366eb0cce9987e935f7b194fb2baf8203122d
    }
  }
}

<<<<<<< HEAD
void manejarProcesoC()
{
  pid_t pid_e = crearProceso('E');
  if (pid_e == 0)  // Estoy en E
  {
    pid_t pid_h = crearProceso('H');
    if (pid_h != 0)
    {
      pid_t pid_i = crearProceso('I');
      if (pid_i != 0)
      {
        wait(NULL);  // Wait de E
        wait(NULL);
        exit(0);     // Exit de E
      }
      else
      {
        exit(0);     // Exit de I
      }
    }
    else
    {
      exit(0);       // Exit de H
    }
  }
  else
  {
    wait(NULL);      // Wait de C
    exit(0);
  }
=======
void main()
{
    crearJerarquiaDeProcesos();
    sleep(20);
>>>>>>> 256366eb0cce9987e935f7b194fb2baf8203122d
}

int main()
{
  manejarProcesoA();
  sleep(TIEMPO_ESPERA_FINAL);
  return 0;
}