package Hilos1.Uno.EJ2;

// Clase HiloSumasRestas que implementa Runnable
public class HiloSumasRestas implements Runnable {
    private static int numero = 900; 
    private int numveces;
    private String operacion;

    // Constructor de la clase
    public HiloSumasRestas(int numveces, String operacion) {
        this.numveces = numveces;
        this.operacion = operacion;
    }

    // Incrementará numero el numveces indicado
    private static void incrementar(int numveces) {
        synchronized (HiloSumasRestas.class) {
            for (int i = 0; i < numveces; i++) {
                numero++;
            }
        }
    }

    // Decrementará numero el numveces indicado
    private static void decrementar(int numveces) {
        synchronized (HiloSumasRestas.class) {
            for (int i = 0; i < numveces; i++) {
                numero--;
            }
        }
    }

    @Override
    public void run() {
        synchronized (HiloSumasRestas.class) {
            if ("+".equals(operacion)) {
                incrementar(numveces);
            } else if ("-".equals(operacion)) {
                decrementar(numveces);
            } else {
                System.out.println("Operación no válida");
            }
        }
    }

    public static int getNumero() {
        return numero;
    }
    }