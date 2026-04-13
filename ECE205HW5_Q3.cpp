#include <iostream>
#include <vector>
using namespace std;

class Pizza
{
private:
    int type;       // 1 = deep dish, 2 = hand tossed, 3 = pan
    int size;       // 1 = small, 2 = medium, 3 = large
    int toppings;   // number of toppings

public:
    // Constants for type
    static const int DEEP_DISH = 1;
    static const int HAND_TOSSED = 2;
    static const int PAN = 3;

    // Constants for size
    static const int SMALL = 1;
    static const int MEDIUM = 2;
    static const int LARGE = 3;

    // Default constructor
    Pizza()
    {
        type = HAND_TOSSED;
        size = SMALL;
        toppings = 0;

    }

    // Parameterized constructor sets the type, size, and toppings
    Pizza(int t, int s, int top)
    {
        type = t; size = s; toppings = top;
    }

    // Mutators (setters): sets the type member varible
    void setType(int t)
    {
        type = t;
    }

    void setSize(int s) //sets the size member varible
    {
        size = s;
    }

    void setToppings(int t) //sets the toppings memeber varible 
    {
        toppings = t;
    }

    // Accessors (getters): returns the type member varible
    int getType()
    {
        return type;
    }

    int getSize() //returns the size member varible
    {
        return size;
    }

    int getToppings() //returns the toppings member varible
    {
        return toppings;
    }
    double computePrice() const;
    void outputDescription() const;

};
double Pizza::computePrice() const
{
    double cost;
    if (size == SMALL)
    {
        cost = 10 + 2 * toppings; //small is $10 base plus $2 per topping

    }
    else if (size == MEDIUM)
    {
        cost = 14 + 2 * toppings; //medium is $14 base plus $2 per topping
    }
    else
    {
        cost = 17 + 2 * toppings; //large is $10 base plus $2 per topping
    }
    return cost;
}

void Pizza::outputDescription() const

{
    //Prints the size
    if (size == SMALL)
    {
        cout << "pizza size is small" << endl;
    }
    else if (size == MEDIUM)
    {
        cout << "pizza size is medium" << endl;
    }
    else
    {
        cout << "pizza size is big" << endl;
    }

    //Prints the type
    if (type == DEEP_DISH)
    {
        cout << "pizza type is deep dish" << endl;
    }
    else if (type == HAND_TOSSED)
    {
        cout << "pizza type is hand tossed" << endl;
    }
    else
        cout << "pizza type is pan" << endl;
    //Print number of toppings
    cout << "number of toppings is " << toppings << endl;
}


class order {
    vector <Pizza> Pizzas; //private vector to store pizza objects in order
public:
    //Adds a pizza object directly to the order
    void add_pizza(const Pizza& p)
    {
        Pizzas.push_back(p);
    }
    //Adds a pizza by specifying type, size, and toppings
    void add_pizza(int type, int size, int toppings)
    {
        Pizza p(type, size, toppings);
        Pizzas.push_back(p);
    }
    //Outputs all the pizzas in order and the total price
    void outputOrder() const
    {
        double totalPrice = 0.0;
        if (Pizzas.empty())
        {
            cout << "No pizzas in the order." << endl;

        }
        //Loop through each pizza and display its description and price
        for (size_t i = 0; i < Pizzas.size(); i++)
        {
            cout << "Pizza #" << i + 1 << ": ";
            Pizzas[i].outputDescription();
            cout << "Price: $" << Pizzas[i].computePrice() << endl << endl;
            totalPrice += Pizzas[i].computePrice();
        }
        //Display the total price of the order
        cout << "Total Order Price: $" << totalPrice << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    // Create pizza objects
    Pizza pizza1(1, 1, 1);
    Pizza pizza2(2, 2, 2);


    // Output details for pizza1
    cout << "---- Pizza 1 ----\n";
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;

    cout << endl;

    // Output details for pizza2
    cout << "---- Pizza 2 ----\n";
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;
    //Order 1 contains pizza1 and pizza2
    order order1;
    order1.add_pizza(pizza1);
    order1.add_pizza(pizza2);
    //Order 2 contains pizza1, pizza2, and pizza1
    order order2;
    order2.add_pizza(pizza1);
    order2.add_pizza(pizza2);
    order2.add_pizza(pizza1);

    order1.outputOrder();
    order2.outputOrder();

    return 0;
}