#include <iostream>
#include <cstring>
using namespace std;

struct Person{
	char name[20];
	int id;
	double weight;
	bool married;
};

int main(){
	cin >> boolalpha;
	cout << boolalpha;

	cout << "Hello world!!" << endl;
	Person p;

	cout << "name? ";
	cin.getline(p.name, 20);
	cout << "name: " << p.name << endl;

	cout << "id? ";
	cin >> p.id;
	cout << "id: " << p.id << endl;

	cout << "weight? ";
	cin >> p.weight;
	cout << "weight: " << p.weight << endl;

	cout << "married? ";
	cin >> p.married;
	cout << "married: " << p.married << endl;

	cout << "name to find? ";
	char temp[20];
	cin.getline(temp, 20);
	cin.getline(temp, 20);
	if(strcmp(p.name, temp) == 0){
		cout << "name:" << p.name << ", id:" << p.id << ", weight:" << p.weight << ", married:" << p.married << endl;
 	}
	else{
		cout << temp << ": not found" << endl;
	}
	return 0;
}
