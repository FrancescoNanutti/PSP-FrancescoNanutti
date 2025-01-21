package Hilos1.Uno;

public class HiloParImparEjecutar {
    public static void main(String[] args) {

        HiloParImpar par = new HiloParImpar(1);
        HiloParImpar impar = new HiloParImpar(2);


        Thread hiloPar = new Thread(par);
        Thread hiloImpar = new Thread(impar);


        hiloPar.start();
        hiloImpar.start();
    }
}
/*Primero Impares
    public class HiloParImparEjecutar {
        public static void main(String[] args) {

            HiloParImpar impar = new HiloParImpar(2);
            HiloParImpar par = new HiloParImpar(1);


            Thread hiloImpar = new Thread(impar);
            Thread hiloPar = new Thread(par);


            hiloImpar.start();
            try {
                hiloImpar.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            hiloPar.start();
        }

    }*/
