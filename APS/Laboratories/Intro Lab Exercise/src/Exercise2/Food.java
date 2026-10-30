package Exercise2;




public class Food extends Product {
    private int daysToExpiry;

    public Food(String name, double price, int daysToExpiry) {
        super(name, price);
        this.daysToExpiry = daysToExpiry;
    }

    @Override
    public double finalPrice() {
        double price = super.finalPrice();
        if(daysToExpiry <= 3) {
            price *= 0.5;
        }
        return price;
    }

    public int getDaysToExpiry() {
        return daysToExpiry;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" days=%d", daysToExpiry);
    }
}
