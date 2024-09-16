import java.util.concurrent.Semaphore;

public class Main {
    static int productos = 0;
    static final int CAPACIDAD_MAXIMA = 10;

    static Semaphore accesoProductos = new Semaphore(1); 
    static int salida=1;

    static class Cliente extends Thread {
        private int nombre;
        private int cantidadAComprar;

        public Cliente(int nombre, int cantidadAComprar) {
            this.nombre = nombre;
            this.cantidadAComprar = cantidadAComprar;
        }

        public void run() {
            try {
                while(true){
                accesoProductos.acquire();
                    if(productos >= cantidadAComprar){
                        productos -= cantidadAComprar;
                        System.out.println("-----------------------------------------------------------");
                        System.out.println("Cliente: " + nombre + " esta comprando " + cantidadAComprar + " productos.");
                        System.out.println("Productos en gondola despues de la compra: " + productos);
                        System.out.println("-----------------------------------------------------------");
                        accesoProductos.release();
                        break;
                    }else{
                        accesoProductos.release();
                        this.sleep(1000);
                    }
                }

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class Repositores extends Thread {
        private int nombre;
        private int cantidadAReponer;
        private static int turno=1;

        public Repositores(int nombre, int cantidadAReponer) {
            this.nombre = nombre;
            this.cantidadAReponer = cantidadAReponer;
        }

        public void cambiarTurno()
        {
            if(Repositores.turno==1){
                turno=2;
            }else{
                turno=1;
            }
        }

        public void run() {
            try {
                while(salida==1){
                    accesoProductos.acquire();
                    if(productos < CAPACIDAD_MAXIMA && turno == nombre){
                        int cantidadReponer = Math.min(CAPACIDAD_MAXIMA - productos, cantidadAReponer);
                        productos += cantidadReponer;
                        System.out.println("-----------------------------------------------------------");
                        System.out.println("Repositor: " + nombre + " esta reponiendo " + cantidadReponer + " productos.");
                        System.out.println("Productos en gondola despues de la reposición: " + productos);
                        System.out.println("-----------------------------------------------------------");
                        cambiarTurno();
                        accesoProductos.release();
                    }else{
                        accesoProductos.release();
                        this.sleep(1000);
                    }
                }


            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        if (args.length < 1 || Integer.parseInt(args[0]) < 0) {
            System.out.println("La cantidad de Clientes debe ser positiva");
            return;
        }

        int numClientes = Integer.parseInt(args[0]);

        Repositores repo1 = new Repositores(1, 10);
        Repositores repo2 = new Repositores(2, 10);

        repo1.start();
        repo2.start();

        Cliente[] clientes = new Cliente[numClientes];
        for (int i = 0; i < numClientes; i++) {
            clientes[i] = new Cliente(i, 5);
            clientes[i].start();
        }

        for (int i = 0; i < numClientes; i++) {
            clientes[i].join();
        }

        salida=0;

        repo1.join();
        repo2.join();
    }
}
