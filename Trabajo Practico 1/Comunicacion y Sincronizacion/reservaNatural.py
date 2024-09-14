from multiprocessing import Pipe
import os
import sys
import threading

proceso_hijo = 0
cantidad_maxima_soga = 5

mutex_direccion = threading.Lock()
mutex_region_critica= threading.Lock()
mutex_imprimir_mensaje = threading.Lock() 
semaforo_soga = threading.Semaphore(cantidad_maxima_soga)
cantidad_monos_lado_izq
cantidad_monos_lado_der
contador_monos_viajaron_lado_der = 0

def comenzar_viaje_hacia_izquierda():
  mutex_direccion.acquire()
  if(cantidad_monos_lado_izq > 0):
    mutex_region_critica.acquire()
    cantidad_maxima_soga--
    cantidad_monos_lado_der--
    viajar_hacia_lado_izq():
    #contador_monos_viajaron_lado_der++
    mutex_region_critica.release()

def comenzar_viaje_hacia_derecha():
  mutex_direccion.acquire()
  if(cantidad_monos_lado_der > 0):
     mutex_region_critica.adquire()
  mutex_region_critica.acquire()
  print("Recibido: ", recepcion.recv())
  contadorLadoB++
  recepcion.close()
  os._exit(0)
  mutex_direccion.acquire()
  contadorLadoA--
  envio.send()
  envio.close()
  os.wait()

def viajar_hacia_lado_der():
   print("- - ->")
   print("Viajando hacia el Lado Derecho...")

def viajar_hacia_lado_izq():
   print("<- - -")
   print("Viajando hacia el Lado Izquierdo...")

def main():
    cantidad_monos_lado_izq = sys.argv[1]
    if(cantidad_monos_lado_izq < 0):
      sys.exit("La cantidad de monos del lado izquierdo no puede ser negativa")  

    cantidad_monos_lado_der = sys.argv[2]
    if(cantidad_monos_lado_der < 0):
      sys.exit("La cantidad de monos del lado derecho no puede ser negativa")  
    
    threadsMonosIzquierda = []

    threadsMonosDerecha = []

    for i in range(cantidad_monos_lado_izq):
        threadMono = threading.Thread(target=comenzar_viaje_hacia_izquierda, name="Thread " + i)
        threadsMonosIzquierda.append(threadMono)
        threadMono.start()

    for i in range(cantidad_monos_lado_der):
        threadMono = threading.Thread(target=comenzar_viaje_hacia_derecha, name="Thread " + i)
        threadsMonosDerecha.append(threadMono)
        threadMono.start()

    recepcion, envio = Pipe(True)
    
if __name__ == "__main__":
    main()
