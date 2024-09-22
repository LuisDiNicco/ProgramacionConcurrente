#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERROR_CREACION_PROCESO 2
#define TIEMPO_DE_ESPERA_PARA_MOSTRAR_ARBOL 10

pid_t crearProceso(char nombre);
void manejarProcesoA();
void manejarProcesoB();
void manejarProcesoC();
void manejarProcesoD();
void manejarProcesoE();
void manejarProcesoHoja();
int main();

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

void manejarProcesoC()
{
  pid_t pid_e = crearProceso('E');
  if (pid_e == 0)  // Estoy en E
  {
    manejarProcesoE();
  }
  else
  {
    wait(NULL);      // Wait de C
    exit(0);
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
        wait(NULL);
        exit(0);     // Exit de D
      }
      else
      {
        manejarProcesoHoja(); // Exit de G   
      }
    }
    else
    {
        manejarProcesoHoja(); // Exit de F
    }
  }
}

void manejarProcesoE()
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
      manejarProcesoHoja(); // Exit de I
    }
  }
  else
  {
    manejarProcesoHoja(); // Exit de H      
  }
}

void manejarProcesoHoja()
{
  sleep(TIEMPO_DE_ESPERA_PARA_MOSTRAR_ARBOL);
  exit(0);
}

int main()
{
  manejarProcesoA();
  return 0;
}