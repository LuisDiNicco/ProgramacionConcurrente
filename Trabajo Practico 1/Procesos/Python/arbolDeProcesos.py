import os
import time
import sys

# Constantes Descriptivas
ERROR_CREACION_PROCESO = 2
TIEMPO_DE_ESPERA_PARA_MOSTRAR_ARBOL = 10

def crear_proceso(nombre):
  """Crea un proceso hijo con el nombre especificado."""
  pid = os.fork()
  if pid < 0:
    return ERROR_CREACION_PROCESO
  if pid == 0:
    print(f"Proceso {nombre}: {os.getpid()}")
    sys.stdout.flush()
  return pid

def proceso_b():
  """Crea los procesos D y C."""
  pid_d = crear_proceso("D")
  if pid_d == 0:
    proceso_d()
  os.wait()           # Wait de B
  os._exit(0)         # Exit de B

def proceso_c():
  """Crea los procesos E y C."""
  pid_e = crear_proceso("E")
  if pid_e == 0:
    proceso_e()
  os.wait()           # Wait de C
  os._exit(0)         # Exit de C

def proceso_d():
  """Crea los procesos F y G."""
  pid_f = crear_proceso("F")
  if pid_f != 0:
    pid_g = crear_proceso("G")
    if pid_g != 0:
      os.wait()       # Wait de D
      os.wait()
      os._exit(0)     # Exit de D
    else:
      proceso_hoja()  # Exit de G
  else:
    proceso_hoja()    # Exit de F 

def proceso_e():
  """Crea los procesos H e I."""
  pid_h = crear_proceso("H")
  if pid_h != 0:
    pid_i = crear_proceso("I")
    if pid_i != 0:
      os.wait()       # Wait de E
      os.wait()
      os._exit(0)     # Exit de E
    else:
      proceso_hoja()  # Exit de I
  else:
    proceso_hoja()    # Exit de H

def proceso_hoja():
  time.sleep(TIEMPO_DE_ESPERA_PARA_MOSTRAR_ARBOL)
  os._exit(0) 

def crear_jerarquia_de_procesos():
  """Crea una jerarquía de procesos (A, B, C, D, E, F, G, H, I)."""
  pid_b = crear_proceso("B")
  if pid_b != 0:      # Estoy en A
    print("Proceso A:", os.getpid())
    sys.stdout.flush()
    os.wait()         # Wait de A
    os._exit(0)       # Exit de A
  else:               # Estoy en B
    pid_c = crear_proceso("C")
    if pid_c != 0:
      proceso_b()     # Estoy en B
    else:
      proceso_c()     # Estoy en C

if __name__ == "__main__":
  crear_jerarquia_de_procesos()
