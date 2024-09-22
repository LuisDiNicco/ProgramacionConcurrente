import java.util.concurrent.Semaphore;

public class Main {

  public static int productos = 0;

  static Semaphore accesoProductos = new Semaphore(1);
  static boolean reposicionActiva = true;

  public static void main(String[] args) throws InterruptedException {

    if (args.length < 1 || Integer.parseInt(args[0]) < 0) {
      System.out.println("La cantidad de clientes debe ser positiva");
      return;
    }

    int numClientes = Integer.parseInt(args[0]);

    Repositor repo1 = new Repositor(1, Constantes.CANTIDAD_MAXIMA_PRODUCTOS);
    Repositor repo2 = new Repositor(2, Constantes.CANTIDAD_MAXIMA_PRODUCTOS);

    repo1.start();
    repo2.start();

    Cliente[] clientes = obtenerClientes(numClientes);

    for (int i = 0; i < numClientes; i++) {
      clientes[i].join();
    }

    reposicionActiva = false;

    repo1.join();
    repo2.join();
  }

  public static Cliente[] obtenerClientes(int cantidadClientes) {
    Cliente[] clientes = new Cliente[cantidadClientes];
    for (int i = 0; i < cantidadClientes; i++) {
      clientes[i] = new Cliente(i, Constantes.CANTIDAD_A_COMPRAR);
      clientes[i].start();
    }
    return clientes;
  }
}
