import java.util.List;
import java.util.concurrent.Callable;

public class Hilo extends Thread {
    
    int numero;
    int indiceInferior;
    int indiceSuperior;
    List<String> listaLineas;
    static int total=0;

    public Hilo(int numero,List<String> listaLineas,int indiceInferior,int indiceSuperior)
    {
        this.numero=numero;
        this.indiceInferior=indiceInferior;
        this.indiceSuperior=indiceSuperior;
        this.listaLineas=listaLineas;
    }

    public static int getTotal()
    {
        return Hilo.total;
    }

    public void run()
    {
        this.ContadorCaracteresEnRango(listaLineas, this.indiceInferior, this.indiceSuperior);
    }

    private void ContadorCaracteresEnRango(List<String> lineas, int inicio, int fin)
    {
        int totalCaracteres=0;
        for (int i = inicio; i <= fin; i++)
        {
            totalCaracteres += lineas.get(i).length();
        }
        System.out.println("Resultado Parcial: " + totalCaracteres);
        Hilo.total += totalCaracteres;
    }
    
}
