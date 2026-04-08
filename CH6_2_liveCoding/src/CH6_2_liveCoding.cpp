#include
#include
using namespace std;

struct Infofood {
    string food;
    int calories;
};

class CalFood {

};

void CalFood::addFood(Infofood _eatfood) {

}
class Person {

};

void CalFood::printTotalCalories() {
    int i = 0;
    cout << "************* 누적된 칼로리 *************\n";
    cout << "지금 까지 먹은 음식 : ";
    while (i < cnt) {
        cout << food[i].food << " ";
        i++;
    }
    cout << endl;
    cout << "총 칼로리: " << totalCalories << " kcal" << endl;
    cout << endl;
}

int main() {
    Person human[3];
    int i = 0;

    while (i < 3) {
        Infofood eatfood;
        cin >> eatfood.food >> eatfood.calories;
        human[i].setfood(eatfood);
        i++;
    }
    CalFood::printTotalCalories();
}
