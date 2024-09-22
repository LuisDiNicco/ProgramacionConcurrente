import sys
import threading
import time

cantidad_maxima_soga = 5

mutex_cuerda = threading.Lock()
mutex_region_critica = threading.Lock()

cantidad_monos = 0
lado_cuerda = 0
dueño = None  

def cambiar_de_lado(direccion):
    global lado_cuerda, cantidad_monos, dueño

    while True:
      if direccion == lado_cuerda:
        #mutex_region_critica.acquire()
        if cantidad_monos < cantidad_maxima_soga:
          #mutex_region_critica.release()
          with mutex_region_critica:  
            cantidad_monos += 1
            print(f"Viajando hacia la {'derecha' if 1+direccion%2 == 1 else 'izquierda'}, "
                  f"cantidad de monos en cuerda: {cantidad_monos}")
            if dueño==threading.get_ident():
              mutex_cuerda.release()

          time.sleep(2)

          with mutex_region_critica:
            cantidad_monos -= 1
            print(f"Mono llegó a la {'derecha' if 1+direccion%2 == 1 else 'izquierda'}, "
            f"cantidad de monos en cuerda: {cantidad_monos}")

            if cantidad_monos == 0:
                print("No hay más monos en la cuerda, se libera.")
            return
        else:
          #mutex_region_critica.release()
          continue
      else:
        mutex_region_critica.acquire()
        if (cantidad_monos == 0):
          lado_cuerda=direccion
          mutex_cuerda.acquire()
          dueño=threading.get_ident()
          print("-------------------------------------------------------------------------------------")
          print(f"Cambiando la dirección de la cuerda hacia la {'derecha' if direccion == 1 else 'izquierda'}")
          mutex_region_critica.release()
        else:
          mutex_region_critica.release()


def main():
    if len(sys.argv) < 2:
        sys.exit("Se debe indicar la cantidad de monos")
        return
    cantidad_monos_a_generar = int(sys.argv[1])
    if cantidad_monos_a_generar < 0:
        sys.exit("La cantidad de monos no puede ser negativa")

    threads = []

    lado = 1
    for i in range(cantidad_monos_a_generar):
        babuino = threading.Thread(target=cambiar_de_lado, args=(lado,))
        threads.append(babuino)
        lado = 1 + lado % 2  

    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()


if __name__ == "__main__":
    main()
