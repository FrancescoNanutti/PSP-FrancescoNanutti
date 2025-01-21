package Hilos2.Ej2;

import java.util.concurrent.ArrayBlockingQueue;

public class Productor implements Runnable
{
    private final ArrayBlockingQueue<Integer> cola;

    public Productor(ArrayBlockingQueue<Integer> cola)
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
                int num = (int) (Math.random() *10 +1);
                cola.put(num);
                System.out.println("Producto: producido" +num);
                Thread.sleep((int) (Math.random() * 500));
            }
        }
        catch (InterruptedException ie)
        {
            Thread.currentThread().interrupt();
        }
    }
}
