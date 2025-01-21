package Hilos1.Uno.EJ3;

public class CuentaBancaria
{

    private int saldo = 1000;

    public synchronized void sacarDinero(String nombre, int importe)
    {
        if (importe <= saldo) {
            System.out.println(nombre + " va a sacar " + importe + " euros.");
            saldo -= importe;
            System.out.println("Nuevo saldo después de la retirada: " + saldo);
        } else {
            System.out.println(nombre + " intentó sacar " + importe + " euros, pero el saldo es insuficiente.");
        }

        // Hace un sleep para la operación
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }


    public synchronized void ingresarDinero(String nombre, int importe) {
        System.out.println(nombre + " va a ingresar " + importe + " euros.");
        saldo += importe;
        System.out.println("Nuevo saldo después del ingreso: " + saldo);

        // Otro sleep para simular el tiempo de la operación
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    // Obtiene el saldo actual
    public int getSaldo() {
        return saldo;
    }
}
