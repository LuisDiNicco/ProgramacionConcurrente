import os
import time

ERROR_CREACION_PROCESO = 2
TIEMPO_DE_ESPERA_PARA_CREACION = 10

def crearProceso(nombre):
    pid = os.fork()
    if pid < 0:
        return ERROR_CREACION_PROCESO
    if pid == 0:
        print("Proceso " + nombre + ": " + str(os.getpid()))
    time.sleep(TIEMPO_DE_ESPERA_PARA_CREACION)
    return pid

def crearJerarquiaDeProcesos():
    pidB = crearProceso("B")

    # Estoy en A
    if pidB != 0:
        print("Proceso A: ", os.getpid())
        os.wait()                       # Wait de A
        os._exit(0)                     # Exit de A
    # Estoy en B
    else:
        pidC = crearProceso("C")
        
        # Estoy en B
        if pidC != 0:
            pidD = crearProceso("D")

            # Estoy en D
            if pidD == 0:
                pidF = crearProceso("F")
                
                # Estoy en D
                if pidF != 0:
                    pidG = crearProceso("G")
                    
                    # Estoy en D
                    if pidG != 0:
                        os.wait()       # Wait de D
                        os._exit(0)     # Exit de D
                    else:
                        os._exit(0)     # Exit de G
                else:                     
                    os._exit(0)         # Exit de F
            os.wait()                   # Wait de B
            os._exit(0)                 # Exit de B      
        # Estoy en C
        else: 
            pidE = crearProceso("E")

            # Estoy en E
            if pidE == 0:   
                pidH = crearProceso("H")

                # Estoy en E
                if pidH != 0:           
                    pidI = crearProceso("I")

                    # Estoy en E
                    if pidI != 0:       
                        os.wait()       # Wait de E
                        os._exit(0)     # Exit de E
                    else:
                        os._exit(0)     # Exit de I
                else: 
                    os._exit(0)         # Exit de H
            else:
                os.wait()               # Wait de C
                os._exit(0)

if __name__ == "__main__":
    crearJerarquiaDeProcesos()
    time.sleep(20)
