package Hilos1.Uno.EJ3;

public class HiloCajeroAutomatico
{
    public static void main(String[] args) {

        CuentaBancaria cuenta = new CuentaBancaria();


        HiloSacarDinero hilo1 = new HiloSacarDinero(cuenta, "Madre", 800);
        HiloSacarDinero hilo2 = new HiloSacarDinero(cuenta, "Hijo2", 800);
        HiloSacarDinero hilo5 = new HiloSacarDinero(cuenta, "Abuelo", 600);
        HiloIngresarDinero hilo3 = new HiloIngresarDinero(cuenta, "Hijo1", 300);
        HiloIngresarDinero hilo4 = new HiloIngresarDinero(cuenta, "Padre", 200);


        hilo1.start();
        hilo2.start();
        hilo3.start();
        hilo4.start();
        hilo5.start();





        System.out.println("Saldo final en la cuenta: " + cuenta.getSaldo() + " euros.");
    }
}
