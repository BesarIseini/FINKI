package Exercise2;




public class Electronics extends Product {
    private int warrantyMonths;

    public Electronics(String name, double price, int warrantyMonths) {
        super(name, price);
        this.warrantyMonths = warrantyMonths;
    }

    @Override
    public double finalPrice() {
        double price = super.finalPrice();
        if(warrantyMonths > 24) {
            price *= 1.15;
        }
        return price;
    }

    public int getWarrantyMonths() {
        return warrantyMonths;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(" warranty=%d", warrantyMonths);
    }
}
