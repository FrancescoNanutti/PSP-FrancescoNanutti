package Hilos2.ProductorConsumidor;

public class Camion extends Thread {
  private Deposito deposito;
  private int numeroCamion;
  private double totalRecogido = 0;

    //Constructor clase camión: n -> número de camión
    public Camion (Deposito dep, int n)
    {
        this.deposito = dep;
        this.numeroCamion =n;
    }
    public void run()
    {
        for (int i = 0; i < 5; i++) //Cada camión realiza 5 cargas
        {
            totalRecogido +=deposito.llenarDepositoCamion(numeroCamion);
        }
        System.out.println("Camion" +numeroCamion+ " => Volumen Total Recogido = " + totalRecogido + " Operación carga finalizada!!");
    }
}
