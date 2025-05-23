#include <iostream>
#include <string>
#include <functional>

using namespace std;
class Product {
protected:
    string name;  
    double price; 
public:
    Product(const string& name, double price) : name(name), price(price) {}
    virtual double getPrice() const {
        return price;
    }
    virtual void display() const {
        cout << "Product: " << name << ", Price: " << price << " UAH\n";
    }
};
class DiscountedProduct : public Product {
private:
    double discountPrice; 
public:
    DiscountedProduct(const string& name, double price)
        : Product(name, price), discountPrice(price) {}
    void applyDiscount(const function<double(double)>& discountFunction) {
        discountPrice = discountFunction(price); 
    }
    double getPrice() const override {
        return discountPrice;
    }
    void display() const override {
        cout << "Product: " << name << ", Original Price: " << price 
             << " UAH, Discounted Price: " << discountPrice << " UAH\n";
    }
};

int main() 
{
    DiscountedProduct product1("Laptop", 20000.0);
    DiscountedProduct product2("Smartphone", 15000.0);
    product1.applyDiscount([](double price) {
        return price * 0.9; 
    });
    product2.applyDiscount([](double price) {
        return price * 0.8; 
    });
    product1.display();
    product2.display();
    return 0;
}
