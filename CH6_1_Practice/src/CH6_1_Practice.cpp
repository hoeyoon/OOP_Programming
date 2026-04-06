#include <iostream>
#include <string>

/******************************************************************************
 * class Cal
 ******************************************************************************/

class Cal {
    int x;
    int y;
};

/******************************************************************************
 * Global functions
 ******************************************************************************/

void function_overload(int x, int y)
{
    Cal c1(100, 200);
}

void default_parameter(int x, int y)
{
}

void printXY(int x, int y)
{
    cout << "x, y: " << x << ", " << y << endl;
}

/* 함수호출시 넘겨 준 main()의 원본 인자 값이 수정되도록 매개변수 선언을 적절히 수정하라.*/
void inputXY(int x, int y)
{
    /* 여기서 "x and y? "를 출력하고
       x, y 값을 입력 받는 코드를 삽입하라. */
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
                //printXY(x);
                //printXY();
                break;
        }
    }
    cout << "Good bye!!" << endl;
}
