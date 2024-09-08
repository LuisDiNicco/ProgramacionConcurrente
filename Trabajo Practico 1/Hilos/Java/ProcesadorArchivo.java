package Resolucion;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;

public class ProcesadorArchivo {

    public static final int total = 0;

    public static void eliminarLineasVacias(String archivoOriginal, List<String> listaLineas)
    {
        File archivo = null;
        Scanner sc = null;
        try
        {
            archivo = new File(archivoOriginal);
            sc = new Scanner(archivo);
            String linea;
            while (sc.hasNext())
            {
                linea=sc.nextLine();
                if (!linea.isEmpty())
                {
                    listaLineas.add(linea);
                }
            }
        } catch (IOException e)
        {
            System.err.println("Error al abrir el archivo de entrada.");
            e.printStackTrace();
        }
        sc.close();
    }

    public static void procesarArchivo(List<String> lineas, int cantidadDeHilos) throws InterruptedException, ExecutionException
    {
        //int cantidadLineasPorArchivo = lineas.size() / cantidadDeHilos;
        //ExecutorService executor = Executors.newFixedThreadPool(cantidadDeHilos);
        //List<Future<Integer>> resultados = new ArrayList<>();
        List<Hilo> hilos = new ArrayList<Hilo>();
        
        for (int i = 0; i < cantidadDeHilos; i++)
        {
            //int indiceInferior = i * cantidadLineasPorArchivo;
            //int indiceSuperior = ((i + 1) * cantidadLineasPorArchivo) - 1;

            if (i == cantidadDeHilos - 1 && (lineas.size() % cantidadDeHilos != 0)) {
                //indiceSuperior += (lineas.size() % cantidadDeHilos);
            }
            
            hilos.add(new Hilo("Hilo_" + i));

            //resultados.add(executor.submit(new ContadorCaracteresEnRango(lineas, indiceInferior, indiceSuperior)));
        }

        //executor.shutdown();

        //for (Future<Integer> resultado : resultados)
        //{
        //    total += resultado.get();
        //}
    }

}
