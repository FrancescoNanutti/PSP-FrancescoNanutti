package Hilos2.Ej1;

import java.util.concurrent.ArrayBlockingQueue;

public class ProductorConsumidor
{
    public static void main(String[] args) {
        ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(5);

        Productor p1 = new Productor(cola);
        Consumidor cons1 = new Consumidor(cola);

        Thread hiloP1 = new Thread(p1);
        Thread hiloP2 = new Thread(cons1);

        hiloP1.start();
        hiloP2.start();
    }
}
