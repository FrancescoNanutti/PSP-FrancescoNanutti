package Hilos1.Uno.EJ3;


public class HiloSacarDinero extends Thread {
    private CuentaBancaria cuenta;
    private String nombre;
    private int cantidad;


    public HiloSacarDinero(CuentaBancaria cuenta, String nombre, int cantidad) {
        this.cuenta = cuenta;
        this.nombre = nombre;
        this.cantidad = cantidad;
    }

    public void run() {
        cuenta.sacarDinero(nombre, cantidad);
    }
}
