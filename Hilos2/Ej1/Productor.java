package Hilos2.Ej1;

import java.util.concurrent.ArrayBlockingQueue;


public class Productor implements Runnable
{
    private final ArrayBlockingQueue<Integer> cola;

    public Productor (ArrayBlockingQueue<Integer> cola)
    {
        this.cola=cola;
    }

    @Override
    public void run()
    {
        try {
            for (int i = 0; i < 10; i++)
            {
                int numRandom = (int) (Math.random() * 100);
                cola.put(numRandom);
                System.out.println("Productor: producido" +numRandom);
                Thread.sleep((int) (Math.random() * 500));
            }

        }
        catch (InterruptedException ie)
        {
            Thread.currentThread().interrupt();
        }
    }
}
