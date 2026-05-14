#include < iostream>
#include < string>
using namespace std;

/******************************************************************************
 * Person class
 ******************************************************************************/
class Person {
// TODO: 멤버 변수: 상속받은 자식 클래스에서 접근할 수 있도록 적절한 접근 지정자를 지정하라. 
    string *name;  // 사람 이름
    int id;        // 고유한 ID 번호
    int hours;     // 일한 시간

// TODO: 멤버 함수: 외부에서 접근할 수 있어야 한다.
    Person(const string& name="", int id=0, int hour=0); // 생성자
    ~Person();                                           // 소멸자

    void print(ostream& out) const;
    void whatAreYouDoing() const;    // 현재하고 있는 일을 출력
    int  operator () () const;       // 임금 계산
    Person* clone() const;           // 자기 자신을 복제

    void println() const { print(cout); cout << endl; }
    Person& operator += (int hours); // 매개변수(일한 시간) hours을 멤버 hours에 더함
    void setName(const string& name) { *this->name = name; }
};

Person::Person(const string& name, int id, int hours) {
    this->id = id;
    this->name = new string(name);
    this->hours = hours;
}

Person::~Person() {
    cout << "~Person(): delete " << *name << endl;
    delete name;
}

void Person::print(ostream& out) const {
    out << "n:" << *name << " i:" << id << " h:" << hours;
}

int Person::operator () () const {
    return 8600 * hours;
}

Person & Person::operator += (int hours) {
    this->hours += hours;
    return *this;
}

void Person::whatAreYouDoing() const {
// TODO: 출력결과를 보고 적절한 문자열을 출력하라.
}

Person* Person::clone() const {
// TODO: 아래 nullptr 대신 구현하라. 자신을 복제한 새로운 객체의 포인터를 반환하라. 
    return nullptr;
}

/******************************************************************************
 * Class Employee
 ******************************************************************************/
Person 클래스를 상속받은 Employee 클래스 선언

// 멤버 변수
    string company;  // 근무회사
    int payPerHour;  // 시간당임금
    int overtime;    // 초과근무시간 설정

public:
    Employee(const string& name, int id, int hours,
             const string& company, int payPerHour, int overtime);
    ~Employee() { cout << "~Employee(): n:" << *name << "   "; }

/******************************************************************************
 * Class Student
 ******************************************************************************/
Person 클래스를 상속받은 Student 클래스 선언

// 멤버 변수
    string university; // 학생이 다니는 대학교 이름
    int year;          // 학년
    int tuition;       // 한 학기당 등록금 액수

public:
    Student(const string& name, int id, int hours,
            const string& university, int year, int tuition);
    ~Student() { cout << "~Student() : n:" << *name << "   "; }

/******************************************************************************
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
 ******************************************************************************/
string menuStr =
    "------------------ Inheritance ----------------\n"
    "  0.exit 1.print 2.addHours 3.whatAreYouDoing  \n"
    "  4.whatIsYourPay 5.copyPerson 6.deletePerson  \n"
    "-----------------------------------------------\n"
    "menu item? ";

//void printPerson(Person *p)     { p->println(); }
//void addHours(Person *p)        { *p += 10; }
//void whatAreYouDoing(Person *p) { p->whatAreYouDoing(); }
//int  whatIsYourPay(Person *p)   { return (*p)(); } // return p->operator()();와 동일
//Person* copyPerson(Person *p)   { return p->clone(); }
//void deletePerson(Person *p)    { delete p; }

void menu_switch(int menu)
{
    Employee *e = new Employee("e", 10001, 50, "Samsung", 30000, 10);
    Student  *s = new Student ("s", 10002, 10, "Chosun",  4, 4000000);
    Person   *p;

    switch (menu) {
    }
    cout << endl;
}

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main()
{
    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;
        menu_switch(menu);
    }
    cout << "\nGood bye!!" << endl;
}
