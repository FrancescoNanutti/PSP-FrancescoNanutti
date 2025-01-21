package ProdCons2;

public class Productor extends Thread {
    private Cola cola;
    private int n;

    //Constructor recibe la cola y un id para el hilo prodcutor
    public Productor(Cola c, int n) {
        cola = c;
        this.n = n;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            cola.put(i); //escribe el número en la coala
            System.out.println(i + "=>Productor : " + n
                    + ", produce: " + i);
            try {
                sleep(100);
            } catch (InterruptedException e) { }

        }
    }
}