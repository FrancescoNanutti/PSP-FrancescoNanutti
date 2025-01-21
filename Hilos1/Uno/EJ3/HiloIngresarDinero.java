package Hilos1.Uno.EJ3;

public class HiloIngresarDinero extends Thread
{
    private CuentaBancaria cuenta;
    private String nombre;
    private int cantidad;


    public HiloIngresarDinero(CuentaBancaria cuenta, String nombre, int cantidad)
    {
        this.cuenta = cuenta;
        this.nombre = nombre;
        this.cantidad = cantidad;
    }

    public void run() {
        cuenta.ingresarDinero(nombre, cantidad);
    }
}

