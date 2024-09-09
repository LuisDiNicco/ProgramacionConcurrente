import java.util.List;
import java.util.ArrayList;
import java.util.concurrent.*;

public class Main {

    public static void main(String[] args)
    {
        if (args.length != 2)
        {
            System.err.println("Uso: java Main <archivo> <numero de threads>");
            System.exit(1);
        }

        String nombreArchivo = args[0];
        int cantidadDeHilos = Integer.parseInt(args[1]);

        List<String> listaLineas = new ArrayList<>();
        ProcesadorArchivo.eliminarLineasVacias(nombreArchivo, listaLineas);

        if (listaLineas.size() < cantidadDeHilos)
        {
            System.out.println("La cantidad de hilos supera la cantidad de lineas no vacias del archivo.");
            System.exit(1);
        }

        long start = System.nanoTime();

        try
        {
            ProcesadorArchivo.procesarArchivo(listaLineas, cantidadDeHilos);
        }
        catch (InterruptedException | ExecutionException e)
        {
            e.printStackTrace();
            System.exit(1);
        }

        long end = System.nanoTime();
        double duracionMs = (end - start) / 1_000_000.0;

        //System.out.println("Resultado Total: " + total);
        System.out.println("Tiempo de ejecucion: " + duracionMs + " ms");

        try
        {
            Thread.sleep(5000); // Simula el sleep de 5 segundos
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}
