// ECE205HW5_Q2.cpp
#include <iostream>
using namespace std;

class pizza
{
public:

	//define const parameter
	static const int deep_dish = 1;
	static const int hand_tossed = 2;
	static const int pan = 3;
	static const int small = 1;
	static const int medium = 2;
	static const int big = 3;

	//static helps to keep the value same in every object/function of this class

	//mutator sets the type member varible
	void set_type(int type1)
	{
		type = type1;
	}
	//mutator sets the size member varible
	void set_size(int size1)
	{
		size = size1;
	}
	//mutator sets the topppings member varible
	void set_toppings(int toppings1)
	{
		toppings = toppings1;
	}

	//accessor returns the type member varible
	int get_type()
	{
		return type;
	}
	//accessor returns the size member varible
	int get_size()
	{
		return size;
	}
	//accessor returns the toppings member varible
	int get_topppings()
	{
		return toppings;
	}
	
	double compute_price();
	void output_description();

private:

	int type; //deep_dish, hand_tossed, pan
	int size;//small, medium, big
	int toppings; //number of toppings
};

double pizza::compute_price()

{
	double cost;
	if (size == small)
	{
		cost = 10 + 2 * toppings; //small is $10 base plus $2 per topping

	}
	else if (size == medium) 
	{
		cost = 14 + 2 * toppings; //medium is $14 base plus $2 per topping
	}
	else 
	{
		cost = 17 + 2 * toppings; //large is $10 base plus $2 per topping
	}
	return cost;

}
void pizza::output_description()

{
	//Prints the size
	if (size == small)
	{
		cout << "pizza size is small" << endl;
	}
	else if (size == medium)
	{
		cout << "pizza size is medium" << endl;
	}
	else 
	{
		cout << "pizza size is big" << endl;
	}
		
	//Prints the type
	if (type == deep_dish)
	{
		cout << "pizza type is deep dish" << endl;
	}
	else if (type == hand_tossed)
	{
		cout << "pizza type is hand tossed" << endl;
	}
	else
		cout << "pizza type is pan" << endl;
	//Print number of toppings
	cout << "number of toppings is " << toppings << endl;


}

int main() {
	//Pizza 1
	pizza p1;
	p1.set_type(pizza::deep_dish);
	p1.set_size(pizza::small);
	p1.set_toppings(2);
	p1.output_description();
	cout << "my total cost is " << p1.compute_price() << " dollars" << endl;

	cout << endl;
	//Pizza 2
	pizza p2;
	p2.set_type(pizza::hand_tossed);
	p2.set_size(pizza::medium);
	p2.set_toppings(3);
	p2.output_description();
	cout << "my total cost is " << p2.compute_price() << " dollars" << endl;

	cout << endl;
	//Pizza 3
	pizza p3;
	p3.set_type(pizza::pan);
	p3.set_size(pizza::big);
	p3.set_toppings(1);
	p3.output_description();
	cout << "my total cost is " << p3.compute_price() << " dollars" << endl;

	cout << endl;

	return 0;
}