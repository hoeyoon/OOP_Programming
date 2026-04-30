#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * Class Person
 ******************************************************************************/
class Person {
    string name;    // 이름
    string address; // 주소
public:
    Person(string name = "", string address = "") { set(name, address); }

    void set(const string& name, const string& address) {
        this->name = name;
        this->address = address;
    }
    void show() const {
        cout << name << ": " << address << endl;
    }
    char operator [] (int idx) { return address[idx]; }
    bool operator ! ();
    friend Person operator + (const char c, const Person &p);
};

// 여기에 필요한 연산자를 구현하시오.
bool Person::operator ! (){
	if(name == "" && address == ""){
		return true;
	}
	return false;
}

Person operator + (const char c, const Person &p){
	Person temp;
	temp.name = c + ("+" + p.name);
	temp.address = c + p.address;
	return temp;
}


//------------------------------------------------------
// 경고: 아래 함수들은 주석을 제거하는 것 외는 수정하지 마시오.
//      만약 본인의 임의대로 아래 함수를 수정할 경우 0점 처리함.
//------------------------------------------------------

int main()
{
    int menu;
    string name1("p1"), address1("seoul"), name2("p2"), address2("XYZ");

    while (true) {
        cout << "menu item? ";
        cin >> menu;
        if (menu == 0) break;

        Person p1(name1, address1), p2(name2, address2);
        p1.show();
        p2.show();
        cout << "+++++++++" << endl;
        if (menu == 1) {
            if (!p1) p1 = p2;
            p1.show();
            Person p3;
            if (!p3) p1 = p2;
        }
        else if (menu == 2) {
            (p2[0] + p1).show();
            (p2[0] + (p2[1] + p1)).show();
            (p2[0] + (p2[1] + (p2[2] + p1))).show();
        }
        else if (menu == 3) {
            //(p1 << p2[0]).show();
            //(p1 << p2[1]).show();
            //(p1 << p2[2]).show();
        }
        else if (menu == 4) {
            //(p1--).show();
            p1.show();
            cout << "***" << endl;
            //(p1--).show();
        }
        else if (menu == 5) {
            cin.ignore();
            cout << "name? ";    getline(cin, name1);
            cout << "address? "; getline(cin, address1);
            p1.set(name1, address1);
        }
        p1.show();
        cout << endl;
    }
    cout << "\nGood bye!!" << endl;
}
