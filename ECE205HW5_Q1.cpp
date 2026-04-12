// ECE205HW5_Q1.cpp
#include <iostream>
using namespace std;

class BicycleSpeedometer
{
public:

	//mutator functions

	void set_distance(double distance1) //Sets the distance varible

	{
		distance = distance1;
	}

	void set_time(double time1) //Sets the time varible
	{
		time = time1;
	}

	double get_distance() //Returns the distance varible
	{
		return distance;
	}

	double get_time() //Returs the time varible
	{
		return time;
	}

	double average_speed() //Computes average speed in mph
	{
		avg_speed = distance / (time / 60.0);
		return avg_speed;
	}

	void display() //Displays the results
	{
		cout << "Distance is " << distance << " miles" << endl;
		cout << "Time is " << time << " minutes" << endl;
		cout << "Average speed is " << avg_speed << " mph" << endl;
	}


private:

	double distance; //stores distance 
	double time; //stores time
	double avg_speed; //stores average speed
};




int main() {

	BicycleSpeedometer B1; //Creates BicycleSpeedometer object
	double distance1;
	double time1;

	cout << "Enter distance traveled in miles: ";
	cin >> distance1;

	cout << "Enter time traveled in minutes: ";
	cin >> time1;

	//Set the varibles using mutator functions 
	B1.set_distance(distance1);
	B1.set_time(time1);
	//Computes average speed and display the results
	B1.average_speed();
	B1.display();

	return 0;
}