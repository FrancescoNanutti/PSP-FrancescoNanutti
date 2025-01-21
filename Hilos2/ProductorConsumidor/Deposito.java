package Hilos2.ProductorConsumidor;

public class Deposito
{
    private double litrosdeposito;
    private boolean depositoLleno = false;


    public synchronized double llenarDepositoCamion(int numCamion)
    {
       while (!depositoLleno)
       {
           try {
               wait();
           }
           catch (InterruptedException e)
           {
               e.printStackTrace();
           }
       }
        System.out.println("Camion " + numCamion + " carga: " +litrosdeposito+ " litros");
       double litrosCargados = litrosdeposito;
       litrosdeposito = 0;
       depositoLleno = false;
       notifyAll();
       return litrosCargados;

    }

    public synchronized void prodLlenaDep(double litros)
    {
        while  (depositoLleno)
        {
            try {
                wait();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        litrosdeposito = litros;
        depositoLleno = true;
        System.out.println("Productor llena el depósito con => " + litros + " Litros");
        notifyAll();
    }
}

