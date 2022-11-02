/*
	Author: LeeTuah
	Word: Dirt
	Time: 01:30 P.M. IST
	Team Dillusioners
	For: League against Jonathan Alex, Titan, Ekectrodrags, King and Dillusioners
*/

# include <iostream>
# include <map>

// class declaration
class MyDirtBike{
	public:
		MyDirtBike();
		void main();
		int cities_count, bikes_per_city, total_dirt_bikes, bikes_cost, broken_bikes, most_dirt_bikes, biggest_city;
		std::map<int, int> DirtBikes;
};

// constructor for initialising welcome message and bikes cound
MyDirtBike::MyDirtBike(){
	std::cout << "\n\n\t\t\tWelcome to the Dirt Bike Counting Simulator\n\n";
	most_dirt_bikes = 0;
}

// main method
void MyDirtBike::main(){
	std::cout << "How many cities are having dirt bikes? ";
	std::cin >> cities_count;

	// gets input for dirt bikes per city
	for(int i = 1; i <= cities_count; ++i){
		std::cout << "How many dirt bikes in city #" << i << ": ";
		std::cin >> bikes_per_city;
		DirtBikes.insert(std::pair<int, int>(i, bikes_per_city));
	}

	// counts total dirt bikes and finds largest amount of dirt bikes in a city
	for(auto i = DirtBikes.begin(); i != DirtBikes.end(); ++i){
		total_dirt_bikes += i->second;

		if(i->second > most_dirt_bikes){most_dirt_bikes = i->second; biggest_city = i->first;}
	}

	// rest of the information
	std::cout << "\nTotal number of dirt bikes: " << total_dirt_bikes << '\n';
	std::cout << "Average amount of dirt bikes per city: " << total_dirt_bikes / cities_count << '\n';

	std::cout << "\nEnter the cost of each dirt bike in USD: ";
	std::cin >> bikes_cost;

	std::cout << "Total cost of every dirt bike is $" << bikes_cost * total_dirt_bikes << '\n';

	std::cout << "\nEnter the amount of broken dirt bikes: ";
	std::cin >> broken_bikes;

	if(broken_bikes > total_dirt_bikes) std::cout << "How do you have more broken bikes than the total amount of bikes?\n";
	else std::cout << "Total amount of healthy bikes: " << total_dirt_bikes - broken_bikes << '\n';

	std::cout << "City #"<< biggest_city <<" has the most amount of dirt bikes with " << most_dirt_bikes << " bikes\n\n";

	std::cout << "Thanks for checking the program out!"; 
}

int main(int argc, char const *argv[]){
	MyDirtBike bike;
	// program starts here
	bike.main();
	return 0;
}
