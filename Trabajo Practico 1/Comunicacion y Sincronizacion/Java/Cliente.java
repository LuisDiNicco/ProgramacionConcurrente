public class Cliente extends Thread {

  private int nombre;
  private int cantidadAComprar;

  public Cliente(int nombre, int cantidadAComprar) {
    this.nombre = nombre;
    this.cantidadAComprar = cantidadAComprar;
  }

  public void run() {
    try {
      while (true) {
        Main.accesoProductos.acquire();
        if (Main.productos >= cantidadAComprar) {
          Main.productos -= cantidadAComprar;
          System.out.println("-----------------------------------------------------------");
          System.out.println(
              "Cliente: " + nombre + " esta comprando " + cantidadAComprar + " productos.");
          System.out.println("Productos en gondola despues de la compra: " + Main.productos);
          System.out.println("-----------------------------------------------------------");
          Main.accesoProductos.release();
          break;
        } else {
          Main.accesoProductos.release();
          sleep(1000);
        }
      }

    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}
