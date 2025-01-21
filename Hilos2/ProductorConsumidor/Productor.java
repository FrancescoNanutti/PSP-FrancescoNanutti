package Hilos2.ProductorConsumidor;

public class Productor extends Thread
{
    private Deposito deposito;
    //Constructor clase productor
    public Productor(Deposito dep)
    {
       this.deposito = dep;
    }
    public void run()
    {
        for (int i = 0; i < 15; i++)
        {
            double litros = Math.random() * 1000;
            deposito.prodLlenaDep(litros);
            try {
                Thread.sleep(500);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }

}
