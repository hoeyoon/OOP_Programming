#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * class Cal
 ******************************************************************************/

class Cal {
    int x;
    int y;
    static int count;

public:
    Cal();
    Cal(int a);
    Cal(int a, int b);
    ~Cal();

    int add();
    int add(int a);
    int add(int a, int b);
    static void print_count();

};

int Cal::count = 0;

Cal::Cal() : Cal(100, 200){}

Cal::Cal(int a) : Cal(a, 200){}

Cal::Cal(int a, int b) : x(a), y(b){
	cout << "Cal::Cal(" << x << ", " << y << ")" << endl;
	count++;
}

Cal::~Cal(){
	cout << "Cal::~Cal(): " << "x=" << x << ", y=" << y << endl;
	count--;
}

int Cal::add(){
	return x + y;
}

int Cal::add(int a){
	return a + y;
}

int Cal::add(int a, int b){
	return a + b;
}

void Cal::print_count(){
	cout << endl << "total count: " << count << endl << endl;

}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void function_overload(int x, int y)
{
    Cal c1(100, 200);
    cout << "c1.add(): " << c1.add() << endl;
    cout << "c1.add(" << x << "): " << c1.add(x) << endl;
    cout << "c1.add(" << x << ", " << y << "): " << c1.add(x, y) << endl;
}

void default_parameter(int x, int y)
{
    Cal *c1 = new Cal();
    cout << "c1->add(): " << c1->add() << endl << endl;

    Cal *c2 = new Cal(x);
    cout << "c2->add(): " << c2->add() << endl << endl;

    Cal *c3 = new Cal(x, y);
    cout << "c3->add(): " << c3->add() << endl << endl;

    Cal::print_count();
    Cal *cal = new Cal[5];
    Cal::print_count();

    delete c2;
	delete c3;
	delete c1;

    Cal::print_count();
    delete []cal;
    Cal::print_count();
}
void printXY(int x = 0, int y = 0)
{
    cout << "x, y: " << x << ", " << y << endl;
}

/* 함수호출시 넘겨 준 main()의 원본 인자 값이 수정되도록 매개변수 선언을 적절히 수정하라.*/
void inputXY(int& x, int& y)
{
    /* 여기서 "x and y? "를 출력하고
       x, y 값을 입력 받는 코드를 삽입하라. */
	cout << "x and y? ";
	cin >> x >> y;
    printXY(x, y);
}

string menuStr =
"************************* Main Menu ************************\n"
"* 0.Exit 1.function_overload 2.default_parameter 3.inputXY *\n"
"************************************************************\n";

int main() {
    int x = 10, y = 20;

    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: function_overload(x, y); break;
        case 2: default_parameter(x, y); break;
        case 3: inputXY(x, y);
                cout << "X, Y: " << x << ", " << y  << endl;
                printXY(x);
                printXY();
                break;
        }
    }
    cout << "Good bye!!" << endl;
}
