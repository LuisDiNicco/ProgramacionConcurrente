import argparse
import os
import time
import threading

VALIDACION_PARAMETROS_OK = 0
ERROR_PARAMETROS = -1
ERROR_ARCHIVO_INVALIDO = -2
ERROR_HILOS = -3

listaSubtotal = []

def validarParametros():
    parser = argparse.ArgumentParser(description="Contador de caracteres dado un archivo usando múltiples hilos.")
    parser.add_argument("rutaArchivo", type=str, help="Ruta del archivo.")
    parser.add_argument("cantidadDeHilos", type=int, help="Cantidad de hilos para procesar el archivo.")
    
    args = parser.parse_args()
    
    if not os.path.isfile(args.rutaArchivo):
        print(f"Error: El archivo '{args.rutaArchivo}' no existe o la ruta es inválida.")
        return None, None, ERROR_ARCHIVO_INVALIDO

    if args.cantidadDeHilos <= 0:
        print("Error: La cantidad de hilos debe ser un número positivo.")
        return None, None, ERROR_PARAMETROS
    
    return args.rutaArchivo, args.cantidadDeHilos, VALIDACION_PARAMETROS_OK

def eliminarLineasVacias(archivo, vectorLineas):
    with open(archivo, 'r') as f:
        for linea in f:
            if linea:
                vectorLineas.append(linea.strip()) # Elimina saltos de linea
                #vectorLineas.append(linea)

def contarCaracteresEnRango(vectorLineas, indiceSuperior, indiceInferior):
    subtotal = 0
    for i in range(indiceSuperior, indiceInferior + 1):
        subtotal += len(vectorLineas[i])
    listaSubtotal.append(subtotal)
    print(f"Resultado Parcial: {subtotal}")

def procesarArchivo(vectorLineas, cantidadDeHilos):
    cantidadDeLineasPorHilo = len(vectorLineas) // cantidadDeHilos
    threads = []
    
    for i in range(cantidadDeHilos):
        indiceInferior = i * cantidadDeLineasPorHilo
        indiceSuperior = ((i + 1) * cantidadDeLineasPorHilo) - 1
        if i == cantidadDeHilos - 1 and len(vectorLineas) % cantidadDeHilos:
            indiceSuperior += len(vectorLineas) % cantidadDeHilos
        thread = threading.Thread(target=contarCaracteresEnRango, args=(vectorLineas, indiceInferior, indiceSuperior))
        threads.append(thread)
        thread.start()
    
    for thread in threads:
        thread.join()

def main():
    pid = os.getpid()
    print(f"PID: {pid}")
    
    rutaArchivo, cantidadDeHilos, resultado = validarParametros()
    
    if resultado != VALIDACION_PARAMETROS_OK:
        return resultado
    
    vectorLineas = []
    eliminarLineasVacias(rutaArchivo, vectorLineas)
    
    if len(vectorLineas) < cantidadDeHilos:
        print("La cantidad de hilos supera la cantidad de lineas no vacias del archivo")
        return ERROR_HILOS
    
    inicio = time.time()
    
    procesarArchivo(vectorLineas, cantidadDeHilos)

    fin = time.time()

    duracion_milisegundos = (fin - inicio) * 1000 
    
    print(f"Tiempo de ejecución: {duracion_milisegundos:.2f} ms")

    print(f"Resultado Total: {sum(listaSubtotal)}")

if __name__ == "__main__":
    main()
