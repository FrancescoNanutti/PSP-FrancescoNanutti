package Hilos1.Uno;

public class HiloParImpar implements Runnable
{
    private int tipo;

    // Constructor
    public HiloParImpar(int tipo)
    {
        this.tipo = tipo;
    }

    @Override
    public void run() {
        if (tipo == 1) {
            // Mostrar números pares del 1 al 100
            for (int i = 2; i <= 100; i += 2) {
                System.out.println("HILO " + Thread.currentThread().getId() + " generando número par " + i);
            }
        } else if (tipo == 2) {
            // Mostrar números impares del 101 al 200
            for (int i = 101; i <= 200; i += 2) {
                System.out.println("HILO " + Thread.currentThread().getId() + " generando número impar " + i);
            }
        } else {
            System.out.println("Tipo no válido");
        }
    }
}