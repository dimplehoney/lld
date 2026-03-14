#include<iostream>
#include<vector>

using namespace std;

class product{
    public:
        string name;
        double price;
    public:
        product(string name, double price)
        {
            this->name=name;
            this->price=price;
        }
};

class shoppingCart
{
    private:
        vector<product*> products;
    public:
        void addProduct(product* p)
        {
            products.push_back(p);
        }

        const vector<product*>& getProduct()
        {
            return products;
        }

        double calcTotal()
        {
            int sum=0;
            for(auto it : products)
            {
                sum+=it->price;
            }
            return sum;
        }
};

class shoppingCartPrinter
{
    private:
        shoppingCart* cart;
    public:
        shoppingCartPrinter(shoppingCart* cart)
        {
            this->cart=cart;
        }

        void printInvoice()
        {
            cout << "invoice generated:" << endl;

            for(auto &it : cart->getProduct())
            {
                cout << "name " << it->name << "price " << it->price << endl;
            }
            cout << "total price is " << cart->calcTotal() << endl;
        }

};

class shoppingCartStorage
{
    private:
        shoppingCart* cart;
    public:
        shoppingCartStorage(shoppingCart* cart)
        {
            this->cart=cart;
        }

        void saveToDB()
        {
            cout << "saving to DB....." << endl;
        }

};

int main()
{      
    product* prod1=new product("laptop" , 80000);
    product* prod2=new product("mouse" , 500);
    product* prod3=new product("keyboard" , 2000);

    shoppingCart* myCart=new shoppingCart();
    myCart->addProduct(prod1);
    myCart->addProduct(prod2);
    myCart->addProduct(prod3);

    shoppingCartPrinter* cartPrinter=new  shoppingCartPrinter(myCart);
    cartPrinter->printInvoice(); 

    shoppingCartStorage* store=new shoppingCartStorage(myCart);
    store->saveToDB(); 


}

