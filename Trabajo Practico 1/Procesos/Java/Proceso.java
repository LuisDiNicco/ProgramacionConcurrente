package Procesos;

import java.io.IOException;
import java.lang.management.ManagementFactory;

public class Proceso {
    
    String nombre;

    public Proceso(String nombre) {
        this.nombre = nombre;
    }

    public static void espera(int tiempo) {
        try {
            Thread.sleep(tiempo);
        } catch (InterruptedException ie) {
            return;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        if (args.length == 0) {
            System.err.println("No se proporcionó ningún argumento.");
            return;
        }

        //System.out.println("Proceso " + args[0] + ": " + ManagementFactory.getRuntimeMXBean().getPid());

        if (args[0].equals("B")) {
            Process procesoC = NuevoProcesoHijo("C");
            Process procesoD = NuevoProcesoHijo("D");

            int error = procesoC.waitFor();
            int error1 = procesoD.waitFor();

            if (error != 0 || error1 != 0) {
                System.out.println("Error al ejecutar");
            }

        } else if (args[0].equals("D")) {
            //System.out.println("Proceso " + args[0] + ": " + ManagementFactory.getRuntimeMXBean().getPid());
            Process procesoF = NuevoProcesoHijo("F");
            Process procesoG = NuevoProcesoHijo("G");

            int error = procesoF.waitFor();
            int error1 = procesoG.waitFor();

            if (error != 0 || error1 != 0) {
                System.out.println("Error al ejecutar");
            }

        } else if (args[0].equals("C")) {
            //System.out.println("Proceso " + args[0] + ": " + ManagementFactory.getRuntimeMXBean().getPid());
            Process procesoE = NuevoProcesoHijo("E");

            int error = procesoE.waitFor();

            if (error != 0) {
                System.out.println("Error al ejecutar");
            }
        } else if (args[0].equals("E")) {
            //System.out.println("Proceso " + args[0] + ": " + ManagementFactory.getRuntimeMXBean().getPid());
            Process procesoH = NuevoProcesoHijo("H");
            Process procesoI = NuevoProcesoHijo("I");

            int error = procesoH.waitFor();
            int error1 = procesoI.waitFor();

            if (error != 0 || error1 != 0) {
                System.out.println("Error al ejecutar");
            }

        } else {
            espera(5000); // Espera para simular un proceso que está ejecutándose
        }
    }

    private static Process NuevoProcesoHijo(String nombre) {
        Process proceso = null;
        try {
            // Cambia "Proceso.java" a "Proceso"
            ProcessBuilder pb = new ProcessBuilder("java", "Proceso.java", nombre);
            
            pb.redirectErrorStream(true);
            pb.inheritIO();

            proceso = pb.start();
            System.out.println("Proceso " + nombre + " : " + proceso.pid());

        } catch (IOException e) {
            System.err.println("Error al iniciar el proceso hijo " + nombre + ": " + e.getMessage());
            e.printStackTrace();
        }

        return proceso;
    }
}