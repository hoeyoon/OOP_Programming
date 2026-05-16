# OJ CH8_1_Practice

```
이번 실습에서 상속을 구현할 수 있는지를 확인함.

****************************************************************************

여기서 다루고자 하는 각 클래스의 계층적 구조는 다음과 같다. 
Student와 Employee는 Person을 상속받는다.

                      Person
                        |
            --------------------------
            |                        |
         Student                 Employee

아래 코드는 Person 클래스를 활용하는 프로그램의 윤곽이다.
먼저 아래 코드([문제 1] 앞까지)를 마킹하여 복사한 후 소스 파일에 삽입하라.
```
```c++
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
```

### 문제 1 설명
```
print() 멤버함수
0) 적절한 입출력 및 문자열 헤드 파일을 include하라.
1) class Person, Employee와 Student 내의 접근 지정자를 지정하라.
2) 프로그램이 정상 컴파일될 수 있도록 Employee와 Student 클래스의 생성자 함수를 구현하라. 
3) 정상 컴파일 된다면 menu_switch() 함수 앞쪽에 있는 printPerson() 함수의 주석을 풀어라.
4) menu_switch(menu) 함수의 switch 문장에 아래 case 문장을 추가하라.
```
```c++
    case 1:
        cout << "e->print(cout): "; e->print(cout); cout << endl;
        cout << "e->println()  : "; e->println();
        cout << "printPerson(e): "; printPerson(e);
        cout << "s->print(cout): "; s->print(cout); cout << endl;
        cout << "s->println()  : "; s->println();
        cout << "printPerson(s): "; printPerson(s);
        break;
```
```
[문제 1] 실행 결과와 같이 출력되도록 해당 클래스에 print(), println() 멤버 함수를 구현하라.
print(), println()가 필요하지 않은 경우 굳이 구현하지 않아도 된다.
이 함수 구현 시 기존 Person::print(cout) 함수를 활용하라.
```

### 문제 1 실행 결과
```
------------------ Inheritance ----------------
  0.exit 1.print 2.addHours 3.whatAreYouDoing  
  4.whatIsYourPay 5.copyPerson 6.deletePerson  
-----------------------------------------------
menu item? 1
e->print(cout): n:e i:10001 h:50 c:Samsung p:30000 o:10
e->println()  : n:e i:10001 h:50
printPerson(e): n:e i:10001 h:50
s->print(cout): n:s i:10002 h:10 u:Chosun y:4 t:4000000
s->println()  : n:s i:10002 h:10
printPerson(s): n:s i:10002 h:10
```

### 문제 2 설명
```
+= 연산자 구현
menu_switch() 함수 앞쪽에 있는 addHours() 함수의 주석을 풀어라.
menu_switch(menu) 함수의 switch 문장에 아래 case 문장을 추가하라.
```
```c++
    case 2:
        cout << "e += 10    : "; (*e += 10).println();
        addHours(e);
        cout << "addHours(e): "; printPerson(e);
        cout << "s += 10    : "; (*s += 10).println();
        addHours(s);
        cout << "addHours(s): "; printPerson(s);
        break;
```
```
[문제 2] 실행 결과와 같이 출력되도록 필요한 경우 해당 클래스에 연산자 += 를 구현하라.
해당 연산자가 필요하지 않은 경우 굳이 구현하지 않아도 된다.
```
### 문제 2 실행 결과
```
...
menu item? 2
e += 10    : n:e i:10001 h:60
addHours(e): n:e i:10001 h:70
s += 10    : n:s i:10002 h:20
addHours(s): n:s i:10002 h:30
```

### 문제 3 설명
```
whatAreYouDoing() 멤버 함수: 재정의된 객체의 멤버함수 대신 부모 클래스의 멤버 함수 호출
menu_switch() 함수 앞쪽에 있는 whatAreYouDoing() 함수의 주석을 풀어라.
menu_switch(menu) 함수의 switch 문장에 아래 case 문장을 추가하라.
```
```c++
    case 3:
        cout << "e->whatAreYouDoing()          : "; e->whatAreYouDoing();
        cout << "whatAreYouDoing(e)            : "; whatAreYouDoing(e);
        cout << "e->Person::whatAreYouDoing()  : "; e->Person::whatAreYouDoing();
        cout << "s->whatAreYouDoing()          : "; s->whatAreYouDoing();
        cout << "whatAreYouDoing(s)            : "; whatAreYouDoing(s);
        cout << "(*s).Person::whatAreYouDoing(): "; (*s).Person::whatAreYouDoing();
        break;
```
```
[문제 3] 실행 결과와 같이 출력되도록 해당 클래스에 whatAreYouDoing() 멤버함수를 구현하라.
```

### 문제 3 실행 결과
```
...
menu item? 3
e->whatAreYouDoing()          : I am working.
whatAreYouDoing(e)            : I am taking a rest.
e->Person::whatAreYouDoing()  : I am taking a rest.
s->whatAreYouDoing()          : I am studying.
whatAreYouDoing(s)            : I am taking a rest.
(*s).Person::whatAreYouDoing(): I am taking a rest.
```

### 문제 4 설명
```
operator () 구현
menu_switch() 함수 앞쪽에 있는 whatIsYourPay() 함수의 주석을 풀어라.
menu_switch(menu) 함수의 switch 문장에 아래 case 문장을 추가하라.
```
```c++
    case 4:
        cout << "(*e)()          : " << (*e)() << endl;
        cout << "whatIsYourPay(e): " << whatIsYourPay(e) << endl;
        cout << "s->operator()() : " << s->operator()() << endl; // (*s)()와 동일
        cout << "whatIsYourPay(s): " << whatIsYourPay(s) << endl;
        break;
```
```
[문제 4 실행 결과]와 같이 출력되도록 해당 클래스에 연산자 () 를 구현하라.
이 연산자는 일한 시간에 대한 임금(pay)을 계산하여 반환한다. 
직원의 경우 임금은 (일한시간*시간당임금+초과근무시간*시간당임금*1.5)이다. 
학생의 경우 단위 시간당 임금을 1000원으로 하고 임금을 계산하라.
```

### 문제 4 실행 결과
```
...
menu item? 4
(*e)()          : 1950000
whatIsYourPay(e): 430000
s->operator()() : 10000
whatIsYourPay(s): 86000
```

### 문제 5 설명
```
clone() 멤버함수 구현
menu_switch() 함수 앞쪽에 있는 copyPerson() 함수의 주석을 풀어라.
menu_switch(menu) 함수의 switch 문장에 아래 case 문장을 추가하라.
```
```c++
    case 5:
        cout << "e->print(cout) : "; e->print(cout); cout << endl;
        cout << "printPerson(e) : "; printPerson(e);
        p = copyPerson(e);
        cout << "p=copyPerson(e): "; printPerson(p);
        cout << "((Employee*)e->clone())->print(cout): " << endl;
        cout << "               : "; ((Employee*)e->clone())->print(cout); cout << endl;
        cout << "s->print(cout) : "; s->print(cout); cout << endl;
        cout << "printPerson(s) : "; printPerson(s);
        p = copyPerson(s);
        cout << "p=copyPerson(s): "; printPerson(p);
        cout << "((Student*)s->clone())->print(cout): " << endl;
        cout << "               : "; ((Student*)s->clone())->print(cout); cout << endl;
        break;
```
```
[문제 5 실행 결과]와 같이 출력되도록 해당 클래스에 자신을 복제하는 clone() 멤버함수를 구현하라.
동적으로 객체를 생성한 후 현재 객체(this)의 내용을 복사생성자를 이용하여 복사해 주면 된다.
예를 들어 Person::clone()의 경우 return new Person(*this); 으로 하면 된다.
그런 후 파생 클래스에서 동일한 함수를 재정의하여야 한다.
이때 함수이름, 매개변수, 리턴 데이타 타입을 Person::clone()과 동일하게 유지해야 한다.
그러나 복제하는 내용은 Person::clone()와는 다르게 파생 클래스마다 자신의 클래스 객체를 복제해야 한다.
```

### 문제 5 실행 결과
```
...
menu item? 5
e->print(cout) : n:e i:10001 h:50 c:Samsung p:30000 o:10
printPerson(e) : n:e i:10001 h:50
p=copyPerson(e): n:e i:10001 h:50
((Employee*)e->clone())->print(cout): 
               : n:e i:10001 h:50 c:Samsung p:30000 o:10
s->print(cout) : n:s i:10002 h:10 u:Chosun y:4 t:4000000
printPerson(s) : n:s i:10002 h:10
p=copyPerson(s): n:s i:10002 h:10
((Student*)s->clone())->print(cout): 
               : n:s i:10002 h:10 u:Chosun y:4 t:4000000
```