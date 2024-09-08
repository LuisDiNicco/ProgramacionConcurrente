package Resolucion;

import java.util.List;
import java.util.concurrent.Callable;

public class Hilo extends Thread {
    
    String nombre;

    public Hilo(String nombre)
    {
        this.nombre=nombre;
    }

    public void run()
    {

    }

    public static class ContadorCaracteresEnRango implements Callable<Integer>
    {
        private final List<String> lineas;
        private final int inicio;
        private final int fin;

        public ContadorCaracteresEnRango(List<String> lineas, int inicio, int fin)
        {
            this.lineas = lineas;
            this.inicio = inicio;
            this.fin = fin;
        }

        @Override
        public Integer call() throws Exception
        {
            Thread.sleep(10000); // Simula el delay de 10 segundos
            int totalCaracteres = 0;
            for (int i = inicio; i <= fin; i++)
            {
                totalCaracteres += lineas.get(i).length();
            }
            System.out.println("Resultado Parcial: " + totalCaracteres);
            return totalCaracteres;
        }
    }
    
}
