package Hilos2.Ej2;

import java.util.concurrent.ArrayBlockingQueue;

public class ConsumidorProducto implements Runnable
{
    private final ArrayBlockingQueue<Integer> cola;
    private int productoAcumulado = 1;

    public ConsumidorProducto(ArrayBlockingQueue<Integer> cola)
    {
        this.cola = cola;
    }

    @Override
    public void run()
    {
        try
        {
            for (int i = 0; i<10; i++)
            {
                int num = cola.take();
                productoAcumulado *=num;
                System.out.println("ConsumidorProducto : consumido" +num+ ", producto acumulado: " +productoAcumulado);
                Thread.sleep((int) (Math.random() *500));
            }
            System.out.println("ConsumidorProducto : producto toal acumulado" +productoAcumulado);
        }catch (InterruptedException ie)
        {
          Thread.currentThread().interrupt();
        }
    }
}
