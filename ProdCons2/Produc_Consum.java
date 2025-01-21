package ProdCons2;

public class Produc_Consum {
    public static void main(String[] args) {

        Cola cola = new Cola();

        Productor prod = new Productor(cola, 1);
        Consumidor cons = new Consumidor(cola, 1000);
        Consumidor cons2 = new Consumidor(cola, 2000);


        prod.start();
        cons.start();
        cons2.start();


    }
}