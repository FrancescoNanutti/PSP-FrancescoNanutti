package Hilos1.Uno.EJ2;

public class Main
{
    public static void main(String[] args) throws InterruptedException {

        HiloSumasRestas hiloSuma1 = new HiloSumasRestas(100, "+");
        HiloSumasRestas hiloResta2 = new HiloSumasRestas(100, "-");
        HiloSumasRestas hiloSuma3 = new HiloSumasRestas(1, "+");
        HiloSumasRestas hiloResta4 = new HiloSumasRestas(1, "-");


        Thread t1 = new Thread(hiloSuma1);
        Thread t2 = new Thread(hiloResta2);
        Thread t3 = new Thread(hiloSuma3);
        Thread t4 = new Thread(hiloResta4);


        t1.start();
        t2.start();
        t3.start();
        t4.start();


        t1.join();
        t2.join();
        t3.join();
        t4.join();


        System.out.println("Resultado final: " + hiloSuma1.getNumero());
    }
}


