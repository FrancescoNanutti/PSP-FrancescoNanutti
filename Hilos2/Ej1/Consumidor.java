package Hilos2.Ej1;

import java.util.concurrent.ArrayBlockingQueue;

public class Consumidor implements Runnable
{
    private final ArrayBlockingQueue<Integer> cola;
    private int suma = 0;

    public Consumidor(ArrayBlockingQueue<Integer> cola)
    {
        this.cola=cola;
    }

    @Override
    public void run()
    {
        try
        {
            for (int i = 0; i < 10; i++)
            {
                int num = cola.take();
                suma += num;
                System.out.println("Consumidor: consumido" + num + ", suma acumulada: " +suma);
                Thread.sleep((int) (Math.random() * 500));
            }
            System.out.println("Consumidor: suma total: " +suma);
        }
        catch (InterruptedException ie)
        {
            Thread.currentThread().interrupt();
        }
    }
}
