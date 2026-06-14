```
/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch3_1.cpp의 내용을 모두 복사해서 ch3_2.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + CurrentUser 클래스 추가
 *     Person 클래스의 멤버 함수 호출 및 구현 여부 파악
 *  + MultiManager 클래스 추가
 */

/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 아래 Person 클래스 선언부를 새로 복사하여 삽입하라.

class Person
{
    char   name[20];        // 이름
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char   address[40];     // 주소

protected:
    void inputMembers(istream* in);
    void printMembers(ostream* out);

public:
    Person();
    Person(const char *name);
    Person(const char *name, int id, double weight, bool married, const char *address);
    ~Person();

    void set(const char *pname, int pid, double pweight, bool pmarried, const char *paddress);
    void setName(const char* pname)       { strcpy(name, pname); }
    void setId(int pid)                   { id = pid; }
    void setWeight(double pweight)        { /* TODO: [문제 3] */ }
    void setMarried(bool pmarried)        { /* TODO: [문제 3] */ }
    void setAddress(const char* paddress) { /* ch3_1.cpp의 동일 함수를 복사하라. */ }

    const char* getName()    { return name; }
    int         getId()      { return id; }
    double      getWeight()  { /* TODO: [문제 2] */ return 0; }  // 구현 시
    bool        getMarried() { /* TODO: [문제 2] */ return 0; }  // 리턴 값들을
    const char* getAddress() { /* TODO: [문제 2] */ return ""; } // 수정하시오.

    void input(istream* pin)  { inputMembers(pin); } // ch3_2에서 추가
    void print(ostream* pout) { printMembers(pout); }
    void println()            { print(&cout); cout << endl; }
    void whatAreYouDoing();                          // ch3_2에서 추가
    bool isSame(const char* pname, int pid);         // ch3_2에서 추가
};

/******************************************************************************
 * 코드 추가 2
 ******************************************************************************/
// 아래 Person 클래스의 구현 영역에 있는 함수들은 기존과 동일하다.
//----------------------------------------------------------------------------

Person::Person()
Person::Person(const char *name)
Person::Person(const char *name, int id, double weight, bool married, const char *address)
Person::~Person()
void Person::printMembers(ostream* pout)

//----------------------------------------------------------------------------
// 아래 Person 클래스의 멤버 구현 함수들을 새로 복사하여 삽입하라.
//----------------------------------------------------------------------------

void Person::set(const char *pname, int pid, double pweight,
    bool pmarried, const char *paddress) {
    // TODO: [문제 4]
}

void Person::inputMembers(istream* pin)   {
    // TODO: [문제 7] 
}

void Person::whatAreYouDoing() {
    // TODO: [문제 5]
}

bool Person::isSame(const char* pname, int pid) {
    // TODO: [문제 6]
    return false; // 구현 시 수정하라.
}

/******************************************************************************
 * 코드 추가 3
 ******************************************************************************/
// 아래 CurrentUser 클래스와 MultiManager 클래스 코드를 
// namespace UI와 ClassAndObject 클래스 사이에 복사하여 삽입하라.
//----------------------------------------------------------------------------

/******************************************************************************
 * ch3_2: CurrentUser class
 ******************************************************************************/

class CurrentUser
{
    Person user;

public:
    CurrentUser(Person u): user(u) { }  // user(u)는 this->user = u 와 동일한 기능
    void display();
    void setter();
    void getter();
    void set();
    void whatAreYouDoing();
    void isSame();
    void inputPerson();
    void run();
};

void CurrentUser::display() { // Menu item 1
    user.println();
}

void CurrentUser::getter() { // Menu item 2
    cout << "name:" << user.getName() << ", id:" << user.getId() << ", weight:" <<
            user.getWeight() << ", married:" << user.getMarried() <<
            ", address:" << user.getAddress() << endl;
}

void CurrentUser::setter() { // Menu item 3
    Person ps("ps");
    ps.setName(ps.getName());
    ps.setId(user.getId());
    ps.setWeight(user.getWeight());
    ps.setMarried(user.getMarried());
    ps.setAddress(user.getAddress());
    cout << "ps.setMembers():"; ps.println();
}

void CurrentUser::set() { // Menu item 4
    Person ps("ps");
    ps.set(ps.getName(), user.getId(), user.getWeight(),
              !user.getMarried(), user.getAddress());
    cout << "ps.set():"; ps.println();
}

void CurrentUser::whatAreYouDoing() {  // Menu item 5
    user.whatAreYouDoing();
}

void CurrentUser::isSame() { // Menu item 6
    user.println();
    Person ps("user"); ps.setId(1);
    cout << "user.isSame(): "
         << user.isSame(ps.getName(), ps.getId()) << endl;
}

void CurrentUser::inputPerson() { // Menu item 7
    if (UI::inputPerson(&user)) // GilDong 1 70.5 true :Jongno-gu, Seoul:
        display();              // user 1 71.1 true :Gwangju Nam-ro 21:
}

void CurrentUser::run() {
    using func_t = void (CurrentUser::*)();
    func_t func_arr[] = {
        nullptr, &CurrentUser::display, &CurrentUser::getter, &CurrentUser::setter,
        &CurrentUser::set, &CurrentUser::whatAreYouDoing,
        &CurrentUser::isSame, &CurrentUser::inputPerson,
    };
    int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 배열의 길이
    string menuStr =
        "+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++\n"
        "+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +\n"
        "+ 6.IsSame 7.InputPerson                                       +\n"
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this->*func_arr[menuItem])();
    }
}
// ch3_2: CurrentUser class

/******************************************************************************
 * ch3_2: MultiManager class
 ******************************************************************************/

class MultiManager
{
    Person person {"p0", 0, 70.0, false, "Gwangju Nam-gu Bongseon-dong 21"};

public:
    void currentUser() {
        CurrentUser(person).run();
    }
}; // ch3_2: MultiManager class



/******************************************************************************
 * 코드 추가 4
 ******************************************************************************/
// 기존의 MainMenu 클래스를 아래 코드로 교체하라.
//----------------------------------------------------------------------------

class MainMenu
{
public:
    void run() {
        int menuCount = 3; // 상수 정의
        string menuStr =
"******************************* Main Menu *********************************\n"
"* 0.Exit 1.CurrentUser(ch3_2)                                             *\n"
"* 2.Class:Object(ch3_1)                                                   *\n"
"***************************************************************************\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount);
            if (menuItem == 0) break;

            switch(menuItem) {
            case 1: MultiManager().currentUser();     break;
            case 2: ClassAndObject().run();           break;
            }
        }
        cout << "Good bye!!" << endl;
    }
}; // class MainMenu

/******************************************************************************
 * 초기 프로그램 실행
 ******************************************************************************/
// 1) ch3_2.cpp을 저장하라.(Ctrl+S)
// 2) 컴파일한 후 실행파일을 만들어라. (메뉴 [Project] -> [Build Project])
//    Debug 폴더가 만들어지고 그 밑에 src 폴더가 만들어지고 그 밑에 
//    정상적으로 컴파일된 경우 ch3_2.o가 생성되고 그리고 Debug 폴더 밑에 ch3_2.exe가 생성됨
// 3) 반드시 exe 파일이 생성된 후 프로그램을 실행하라. 
//    툴바에서 오른쪽으로 누운 초록색의 삼각형 버튼 실행 또는 Ctrl+F11 또는 메뉴 [Run] -> [Run]
//    (처음에 한번은 "Local C/C++ Appication"를 선택해 주어야 함)
// 4) 프로그램의 실행결과는 아래와 같다.

===============================================================================
== 초기 프로그램 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.CurrentUser(ch3_2)                                             *
* 2.Class:Object(ch3_1)                                                   *
***************************************************************************
Menu item number? 1
Person::Person(...):p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

//----------------------------------------------------------------------------
// 위는 MainMenu에서 1번 메뉴을 선택할 경우 MultiManager().currentUser()가 실행되는데
// MultiManager() 의해 MultiManager 임시 객체가 생성되면서 디폴트 생성자가 실행된다. 
// 이 디폴트 생성자에 의해 MultiManager의 멤버 person 생성자기 실행되어 출력된 것임
//----------------------------------------------------------------------------
// 이후 MultiManager() 임시 객체의 currentUser() 멤버 함수가 실행되면서 함수 내의
// CurrentUser(person)의 임시객체가 생성되고 생성자가 호출되는데  
// 1) 이때 함수 인자인 person이 생성자 CurrentUser(Person u)의 
//    매개변수 u에게 복사되어 u가 먼저 생성되고 
// 2) 그 다음의 : user(u) {}에 의해 매개변수 u가 CurrentUser 클래스의 멤버 
//    user에게 복사되어 초기화된다.
// 이 두번의 복사는 생성자가 실행되지 않고 내부적으로 객체가 자동 복사되어 생성된다.
// 어쨌든 두 객체는 자동 생성되지만 생성자가 실행되지 않고 복사되어 생성된다. 
// 이때 복사 생성자가 실행되는데 이는 5장에서 자세히 다룰 예정이다.
//----------------------------------------------------------------------------
// CurrentUser(person)에 의해 임시 객체 생성, 생성자 실행이 끝나면
// CurrentUser(person).run()에 의해 임시 객체의 run() 멤버 함수가 실행된다.
//----------------------------------------------------------------------------

+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +
+ 6.IsSame 7.InputPerson                                       +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0
Person::~Person():p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21: // CurrentUser::user 멤버 소멸
Person::~Person():p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21: // CurrentUser(Person u)의 매개변수 u 소멸
Person::~Person():p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21: // MultiManager::person 소멸

//----------------------------------------------------------------------------
// 위는 Current User Menu에서 빠져 나올 때 세 개의 객체가 소멸되면서 소멸자가 실행된 것이다.
//----------------------------------------------------------------------------

******************************* Main Menu *********************************
* 0.Exit 1.CurrentUser(ch3_2)                                             *
* 2.Class:Object(ch3_1)                                                   *
***************************************************************************
Menu item number? 0
Good bye!!


/******************************************************************************
 * 문제 1
 ******************************************************************************/
// CurrentUser의 1번 메뉴항목을 실행하라. 
// Person 객체 출력은 이미 CH3_1에서 구현 했기에 정상적으로 출력되어야 한다.
===============================================================================
== 문제 1 실행 결과
=============================================================================== 
...
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +
+ 6.IsSame 7.InputPerson                                       +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1
p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * 문제 2
 ******************************************************************************/
// Person의 멤버함수 getName()과 getId()를 참조하여 
// getWeight(), getMarried(), getAddress()을 구현하라.
===============================================================================
== 문제 2 실행 결과
=============================================================================== 
...
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
...
Menu item number? 2
name:p0, id:0, weight:70, married:false, address:Gwangju Nam-gu Bongseon-dong 21


/******************************************************************************
 * 문제 3
 ******************************************************************************/
// Person의 멤버함수 setName()과 setId()를 참조하여 setWeight(), setMarried()을 구현하라.
===============================================================================
== 문제 3 실행 결과
=============================================================================== 
...
Menu item number? 3
Person::Person("ps"):ps 0 0 false ::
ps.setMembers():ps 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():ps 0 70 false :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * 문제 4
 ******************************************************************************/
// Person의 멤버함수 set(const char *pname, ...)을 구현하라. 구현 시 
// 멤버 id, weight, married는 상응하는 매개변수 값을 해당 멤버에 직접 = 연산자를 이용해 설정하고
// name과 address 멤버의 경우 Person::Person(const char *name, int id, ...) 생성자처럼 
// setName()과 setAddress()를 호출하여 초기화하라.

===============================================================================
== 문제 4 실행 결과
=============================================================================== 
...
Menu item number? 4
Person::Person("ps"):ps 0 0 false ::
ps.set():ps 0 70 true :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():ps 0 70 true :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * 문제 5
 ******************************************************************************/
// ch2.cpp의 whatAreYouDoing()의 함수 내용만(함수 몸체만) 복사해와 Person의 멤버함수 
// whatAreYouDoing()에 삽입하라. 그런 후 기존 p->name의 p->는 제거하라.
===============================================================================
== 문제 5 실행 결과
=============================================================================== 
...
Menu item number? 5
p0 is taking a rest.


/******************************************************************************
 * 문제 6
 ******************************************************************************/
// ch2.cpp의 isSame()의 함수 내용만(함수 몸체만) 복사해와 Person의 멤버함수 isSame()에 삽입하라.
// 그런 후 기존의 p->name, p->id에서 p->는 제거하라.
// isSame(): 객체의 이름과 id가 각각 매개변수인 pname과 pid와 같으면 true를 리턴한다.

===============================================================================
== 문제 6 실행 결과
===============================================================================
Menu item number? 6
p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person("user"):user 0 0 false ::
user.isSame(): false
Person::~Person():user 1 0 false ::


/******************************************************************************
 * 문제 7
 ******************************************************************************/
// ch2.cpp의 input() 함수의 내용을 복사해와 inputMembers(istream* pin) { }에 추가하라. 
// 멤버 변수 앞의 p->는 제거하라. 매개변수 pin은 cin을 포인터하는 포인터 변수이다.
// (이 함수 호출할 때 UI::inputPerson(Person* p)에서 인자로 &cin을 넘겨 준다.)
// 따라서 기존 코드 중에 cin은 매개변수 *pin과 동일하므로 
// cin >> 대신 *pin >> 로, if (!cin) 대신 if (!(*pin))으로 변경하라.
// cin.getline 대신에 pin->getline으로 변경하라.
//-----------------------------------------------------------------------------

===============================================================================
== 문제 7 실행 결과
== 7번 메뉴항목 실행은 궁극적으로 inputMembers(istream* pin)를 호출한다.
=============================================================================== 
...
Menu item number? 7
input person information:
user 1 71.1 true :Gwangju Nam-ro 21: // 사용자 입력
user 1 71.1 true :Gwangju Nam-ro 21: // display() 출력

...
Menu item number? 6
user 1 71.1 true :Gwangju Nam-ro 21:
Person::Person("user"):user 0 0 false ::
user.isSame(): true                  // true로 출력되어야 한다.
Person::~Person():user 1 0 false ::


/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH3_2 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH3_2] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH3_2 프로젝트의 
//    src 폴더로 복사하라. (파일 선택 후 [Ctrl+C], src 폴더를 선택 후 [Ctrl+V])
// 3. 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 true로 설정하라.
// 4. main() 함수 내의 evaluate(true)가 true로 설정되어 있는지 확인하라.
// 5. 프로그램 테스트를 위한 입출력 파일이 test 폴더에 다운로드 되어 있는지 확인하라.
// 6. 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.

===============================================================================
== 1. 정상적인 프로그램 실행 결과
==    아래 각 테스트 번호는 위 문제 번호와는 관련 없습니다.
=============================================================================== 
test 1 : O
test 2 : O
test 3 : O
test 4 : O
test 5 : O
test 6 : O
test 7 : O
test 8 : O // 메뉴 7을 통해 새로 인적 정보를 입력한 후 1~6까지 다시 실행함
Good bye!!

===============================================================================
== 2. 비정상적인 경우의 프로그램 실행방법은 CH2의 실습과제 설명의 마지막 부분을 참조하기 바란다.  
=============================================================================== 

/******************************************************************************
 * 프로그램 제출
 ******************************************************************************/
// 1. 중요: 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 false로 설정하라.
// 2. 프로그램을 oj.chosun.ac.kr에 제출하라. 
//-----------------------------------------------------------------------------
```