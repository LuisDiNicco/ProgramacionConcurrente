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
    long start = System.nanoTime();

    String nombreArchivo = args[0];
    int cantidadDeHilos = Integer.parseInt(args[1]);

    List<String> listaLineas = new ArrayList<>();
    ProcesadorArchivo.eliminarLineasVacias(nombreArchivo, listaLineas);

    if (listaLineas.size() < cantidadDeHilos)
    {
      System.out.println("La cantidad de hilos supera la cantidad de lineas no vacias del archivo.");
      System.exit(1);
    }

    int cantidadLineasPorThread=listaLineas.size()/cantidadDeHilos;
    Hilo[] hilos = new Hilo[cantidadDeHilos];
    int [] suma= new int[cantidadDeHilos];

    for (int i = 0; i < cantidadDeHilos; i++)
    {
      int indiceInferior = i*cantidadLineasPorThread;
      int indiceSuperior = ((i+1)*cantidadLineasPorThread) - 1;

      if(i == cantidadDeHilos-1 && (listaLineas.size() % cantidadDeHilos != 0))
      {
        indiceSuperior += (listaLineas.size() % cantidadDeHilos);
      }
      hilos[i]= new Hilo(i,listaLineas,indiceInferior,indiceSuperior,suma);
      hilos[i].start();
    }

    for (int i = 0; i < cantidadDeHilos; i++)
    {
      try
      {
        hilos[i].join();
      }
      catch (InterruptedException e)
      {
        e.printStackTrace();
      }
    }

    int total=0;
    for (int i = 0; i < cantidadDeHilos; i++)
    {
      total+=suma[i];
    }

    System.out.println("Total de Caracteres: " +  total);
    long end = System.nanoTime();
    double duracionMs = (end - start) / 1_000_000.0;

    //System.out.println("Resultado Total: " + total);
    System.out.println("Tiempo de ejecucion: " + duracionMs + " ms");
    }
}