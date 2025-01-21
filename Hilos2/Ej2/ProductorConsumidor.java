package Hilos2.Ej2;

import java.util.concurrent.ArrayBlockingQueue;

public class ProductorConsumidor
{
    public static void main(String[] args) {
        ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(5);

        Productor productor = new Productor(cola);
        ConsumidorSuma cs = new ConsumidorSuma(cola);
        ConsumidorProducto cp = new ConsumidorProducto(cola);

        Thread hiloproducto = new Thread(productor);
        Thread hiloCS = new Thread(cs);
        Thread hiloCP = new Thread(cp);

        hiloproducto.start();
        hiloCS.start();
        hiloCP.start();
    }
}
