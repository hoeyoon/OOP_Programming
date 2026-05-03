# OJ CH3_1

### 코드 추가 1
```plaintext
1) 기존에 작성했던 ch2.cpp의 내용을 모두 복사해서 ch3_1.cpp에 삽입하라.
2) 기존의 Person 구조체와 이 구조체를 조작하던 모든 함수들(print()부터 init()까지)을
   삭제하고 아래의 Person 클래스 선언부와 함수 구현부 부분을 새로 복사해서 삽입하라.
3) 기존의 namespace UI와 run(), main() 및 자동오류체크 부분은 그대로 남겨 두어라.
```
```c++
/******************************************************************************
 * Person class
 ******************************************************************************/

class Person 
{
    char   name[20];        // 이름
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char   address[40];     // 주소

protected:
    void printMembers(ostream* out);

public:
    Person();
    Person(const char *name);
    Person(const char *name, int id, double weight, 
           bool married, const char *address);
    ~Person();

    void setName(const char* pname)       { strcpy(name, pname); }
    void setAddress(const char* paddress) { /* TODO: [문제 2] */ }

    void input(istream* pin)  {  }
    void print(ostream* pout) { printMembers(pout); }
    void println()            { print(&cout); cout << endl; }
};

Person::Person(): name{}, id{}, weight{}, married{}, address{} {
    // 위 함수 서두(:와 함수 본체 사이)에서 각 멤버를 초기화하는데 이는 함수 진입하기 전에 
    // 각 멤버의 값을 초기화하는 것이다. {}는 각 데이타 타입별로 디폴트 값으로 초기화하라는 의미임. 
    // 즉, name[]={'\0'}="", id=0, weight=0.0, married=false, address[]={'\0'}=""
    cout << "Person::Person():"; println();
}

Person::Person(const char *name) /* : TODO [문제 2] */ {
    // TODO: [문제 2] 
    cout << "Person::Person(\"" << name << "\"):"; println();
}

Person::Person(const char *name, int id, double weight, bool married, 
               const char *address) :
        id{id}, weight{weight}, married{married} {
    // 위에서 각 멤버를 초기화하는 {}는 각 매개변수 값을 객체의 상응하는 멤버에 설정하는 것이다. 즉,
    // this->id=id, this->weight=weight, this->married=married와 동일하다.
    // 여기서 this는 해당 객체를 포인터하는 포인터 변수이며, (다음 장에서 설명될 예정임)
    // this->id는 해당 객체의 멤버 id를 지칭하며 =의 우측변수 id는 함수의 매개변수이다.
    // 값을 간단히 대입하는 것은 위처럼 하면 되지만 name[], address[]와 같은 배열 복사 함수 
    // 호출 또는 다른 함수를 호출할 때는 생성자 함수의 몸체 { } 내에서 호출해야 한다.
    
    // TODO: [문제 2] 
    cout << "Person::Person(...):"; println();
}

Person::~Person() {
    cout << "Person::~Person():"; println();
}

void Person::printMembers(ostream* pout)   {
    // TODO: [문제 1]
}
```

### 코드 추가 2
```plaintext
1) 기존의 namespace UI 내의 inputPerson(Person* p)을 아래 함수와 같이 수정하라.
   이 중에서 p->input(&cin), p->println() 부분이 수정된 내용이다.
   즉, 포인터 변수 p를 이용하여 객체 멤버에 접근할 경우 -> 를 사용한다. 
   (C 언어에서 구조체 멈버에 접근하는 방식과 동일하다.)
```
```c++
bool inputPerson(Person* p) {
    cout << "input person information:" << endl;
    p->input(&cin);
    if (checkDataFormatError(&cin)) return false;
    if (echo_input) p->println(); // 자동체크에서 사용됨
    return true;
}
```

### 코드 추가 3
```plaintext
1) 기존의 [simple test] 영역을 모두 삭제하라. 즉,
      Person p, printlnTest() ~ dataTypeSize() 까지 삭제하라.

2) 그런 후 그 자리에 아래 "Class And Object" 영역의 코드를 삽입하라.
```
```c++
/******************************************************************************
 * ch3_1: Class And Object
 ******************************************************************************/

//Person gps("gps", 1000, 100, true, "gps adress");

class ClassAndObject
{
    void defualConstructor() { // Menu item 1
    }

    void constructor() { // Menu item 2: 지역객체의 다양한 생성자 및 소멸자 실행
    }

    void construcor_destructor_inner_inner() {
    }

    void construcor_destructor_inner() {
    }

    void construcorDestructor() { // Menu item 3
    }

    void global_static_local_objects_inner() {
    }

    void globalStaticLocalObjects() { // Menu item 4
    }

public:
    // 사용자가 선택한 메뉴 항목을 실행하는 멤버 함수(func_arr[menuItem]에 등록된 함수)를 호출
    void run() {
        // ClassAndObject의 멤버 함수에 대한 포인터 타입인 새로운 데이타 타입 func_t를 정의함
        using func_t = void (ClassAndObject::*)();
        // 위 using 문은 ClassAndObject 클래스의 멤버 함수(리턴 타입이 void 이면서 매개변수가 없는)에
        // 대한 포인터 타입을 앞으로는 간단히 func_t로 사용하겠다는 의미이다.

        // ClassAndObject의 멤버 함수 포인터들의 배열
        // 나중에 호출하기 위해 멤버 함수의 이름을 미리 배열에 저장(등록) 
        //     함수 이름이 곧 함수에 대한 포인터임: 즉, 함수의 첫번째 명령어의 주소를 저장함
        // 등록된 이 멤버 함수들은 나중에 run()에서 호출됨
        //     (즉, 함수 주소로 jump 해 가서 함수를 실행함)

        func_t func_arr[] = { // 메뉴항목을 실행하는 멤버 함수를 배열에 미리 저장(등록)해 둠
            nullptr, &ClassAndObject::defualConstructor, &ClassAndObject::constructor,
            &ClassAndObject::construcorDestructor, &ClassAndObject::globalStaticLocalObjects,
        };
        int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); 
        // func_arr[]의 원소의 개수 = 배열 전체 크기 / 한 배열 원소의 크기

        // 화면에 보여 줄 메뉴
        string menuStr =
            "+++++++++++ Person Class And Object Menu ++++++++++++\n"
            "+ 0.Exit 1.DefualConstructor 2.Constructor          +\n"
            "+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount); // 메뉴 번호 입력 받음
            if (menuItem == 0) return;
            (this->*func_arr[menuItem])(); // 선택된 메뉴 항목을 실행할 멤버 함수를 호출함
            /* 위 문장은 다음을 간단히 한 것이다. 앞으로 계속 나올테니 잘 이해하기 바란다.
               func_t f = func_arr[menuItem];// 배열에 저장된 멤버 함수 포인터
               (this->*f)();                 // 멤버함수 포인터를 이용하여 해당 함수를 호출함
            */
        }
    }
}; // ch3_1: class ClassAndObject


/******************************************************************************
 * Main Menu
 ******************************************************************************/

class MainMenu
{
public:
    void run() {
        int menuCount = 2; // 상수 정의
        string menuStr =
"******************************* Main Menu *********************************\n"
"* 0.Exit 1.Class:Object(ch3_1)                                            *\n"
"***************************************************************************\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount);
            if (menuItem == 0) break;

            switch(menuItem) {
            case 1: ClassAndObject().run();           break;
            // 위 ClassAndObject()는 임시객체(이름없는 객체)를 생성하하는 코드이고 
            // 이후 바로 해당 객체의 멤버 run()을 호출하고 run()에서 리턴된 후에는 객체 자동 소멸됨
            // 위는 다음과 같다. ClassAndObject tmp; tmp.run();
            }
        }
        cout << "Good bye!!" << endl;
    }
}; // class MainMenu
```

### 코드 추가 4
```plaintext
기존의 run() 함수 영역을 아래 코드로 대체하라.
```
```c++
void run() {
    MainMenu().run();
    // MainMenu 타입의 이름 없는 임시객체를 생성한 후 
    // 그 객체의 run() 멤버함수를 호출함; run()에서 리턴한 후에는 임시객체가 자동 소멸됨
    // 즉, 위 문장은 아래 두 문장과 동일한 기능임
    // MainMenu mm;
    // mm.run();
}
```

### 코드 추가 5
```plaintext
기존의 main() 함수 앞쪽에 cout과 cin에 boolalpha를 설정하는 코드를 삽입하라.
```
```c++
int main() {
    cout << boolalpha;  // 11장에서 배움; bool 타입 값을 0, 1 대신 true, false로 출력하도록 설정
    cin >> boolalpha;   // bool 타입 값을 0, 1 대신 true, false로 입력 받도록 설정

#if AUTOMATIC_ERROR_CHECK
    evaluate(false);   // 각 문제에 대해 단순히 O, X만 확인하고자 할 때는 false
#else
    run();
#endif
}
```

### 초기 프로그램 실행 결과
```plaintext
******************************* Main Menu *********************************
* 0.Exit 1.Class:Object(ch3_1)                                            *
***************************************************************************
Menu item number? 1

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1 // 실행하는 내용이 없다.

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 2

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0

******************************* Main Menu *********************************
* 0.Exit 1.Class:Object(ch3_1)                                            *
***************************************************************************
Menu item number? 0
Good bye!!
```

### 문제 1 설명
```plaintext
ch2.cpp의 print() 함수의 내용을 복사해서 printMembers(ostream* pout) { }에
추가하라. cout 대신에 매개변수인 pout을 활용하고, 기존의 p->는 모두 제거하라.
pout은 ostream* 포인터 변수인데 println()에서 print() 호출 시 &cout을 넘겨 준다.
따라서 기존 코드 중에 cout은 매개변수 *pout과 동일하므로 *pout << ...로 하면 된다.
```
```plaintext
기존 defualConstructor() 함수를 아래 함수로 교체하라. 
```
```c++
    void defualConstructor() { // Menu item 1
        Person ps;    // Person::Person() 기본 생성자 및 소멸자 실행
    }
```

### 문제 1 실행 결과
```plaintext
아래와 같이 출력되지 않았다면 printMembers(ostream* pout) 함수를 점검하라.
```
```plaintext
... // 생략
+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1
Person::Person(): 0 0 false ::     // 이름과 주소가 ""임
Person::~Person(): 0 0 false ::
... // 생략
```

### 문제 2 설명
```plaintext
1) Person의 멤버함수 setName()을 참조하여 setAddress()을 구현하라.
   즉, 문자열 매개변수 paddress를 클래스 멤버 변수 address로 복사하라.
2) Person::Person(const char *name) 생성자의 id, weight, married, address 멤버의 
   초기화는 기존 Person::Person()를 참고하여 동일하게 초기화하라.
   단, name 멤버의 경우 생성자의 함수 몸체 { } 내에서 setName()을 호출하여 초기화하라.
3) Person::Person(const char *name, int id, ... ) 생성자의 경우 id, weight, 
   married 멤버를 초기화하는 것은 이미 구현되어 있다. name과 address 멤버의 경우 
   이 생성자의 함수 몸체 { } 내에서 setName()과 setAddress()를 호출하여 초기화하라.
```
```plaintext
기존 constructor() 함수를 아래 함수로 교체하라.
```
```c++
    void constructor() { // Menu item 2: 지역객체의 다양한 생성자 및 소멸자 실행
        Person ps1;
        Person ps2("ps2");
        Person ps3("ps3", 3, 70.3, true, "ps3 address");
    }
```

### 문제 2 실행 결과
```plaintext
...
+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
...
Menu item number? 2
Person::Person(): 0 0 false ::
Person::Person("ps2"):ps2 0 0 false ::
Person::Person(...):ps3 3 70.3 true :ps3 address:
Person::~Person():ps3 3 70.3 true :ps3 address:
Person::~Person():ps2 0 0 false ::
Person::~Person(): 0 0 false ::
...
```

### 문제 3 설명
```plaintext
기존 construcorDestructor() 관련 함수들을 아래 함수로 교체하라. 
```
```c++
    void construcor_destructor_inner_inner() {
        cout << "\n--- construcor_destructor_inner_inner() begins ---" << endl;
        Person ps3("ps3");
        cout << "\n- if begins -" << endl;
        if (true) {
            Person ps4("ps4");
        }
        cout << "- if ends -\n" << endl;
        cout << "- temporary object begins -" << endl;
        Person("temp_ps_1"); // 임시객체(이름 없는 객체) 성성 및 소멸
        cout << endl;
        Person("temp_ps_2").setName("TEMP_PS_2"); // 임시객체 생성, 
                                                  // setName() 호출, 임시객체 소멸
        cout << "- temporary object ends -\n" << endl;
        Person ps5("ps5");
    }

    void construcor_destructor_inner() {
        cout << "\n--- construcor_destructor_inner() begins ---" << endl;
        Person ps2("ps2");
        construcor_destructor_inner_inner();
        cout << "--- construcor_destructor_inner_inner() returned ---\n" << endl;
        Person ps6("ps6");
    }

    void construcorDestructor() { // Menu item 3
        Person ps1("ps1");
        construcor_destructor_inner();
        cout << "--- construcor_destructor_inner() returned ---\n" << endl;
    }
```

### 문제 3 실행 결과
```plaintext
실행 결과를 통해 함수들이 충첩해서 계속 호출될 때 
언제 각 객체의 생성자가 호출되고 언제 자동으로 소멸되는지를 정확히 인지하기 바란다.  
```
```plaintext
...
Menu item number? 3
Person::Person("ps1"):ps1 0 0 false ::

--- construcor_destructor_inner() begins ---
Person::Person("ps2"):ps2 0 0 false ::

--- construcor_destructor_inner_inner() begins ---
Person::Person("ps3"):ps3 0 0 false ::

- if begins -
Person::Person("ps4"):ps4 0 0 false ::
Person::~Person():ps4 0 0 false ::
- if ends -

- temporary object begins -
Person::Person("temp_ps_1"):temp_ps_1 0 0 false ::
Person::~Person():temp_ps_1 0 0 false ::

Person::Person("temp_ps_2"):temp_ps_2 0 0 false ::
Person::~Person():TEMP_PS_2 0 0 false ::
- temporary object ends -

Person::Person("ps5"):ps5 0 0 false ::
Person::~Person():ps5 0 0 false ::
Person::~Person():ps3 0 0 false ::
--- construcor_destructor_inner_inner() returned ---

Person::Person("ps6"):ps6 0 0 false ::
Person::~Person():ps6 0 0 false ::
Person::~Person():ps2 0 0 false ::
--- construcor_destructor_inner() returned ---

Person::~Person():ps1 0 0 false ::
...
```

### 문제 4 설명
```plaintext
ClassAndObject 클래스 선언 위쪽의 전역 객체 gps의 주석을 아래처럼 풀어라. 
```
```c++
Person gps("gps", 1000, 100, true, "gps adress");

class ClassAndObject { ... }
```
```plaintext
기존 globalStaticLocalObjects() 관련 함수들을 아래 함수로 교체하라
```
```c++
    void global_static_local_objects_inner() {
        cout << "\n--- global_static_local_objects_inner() begins ---" << endl;
        static Person sps("sps", 2000, 200, false, "sps adress");
    }

    void globalStaticLocalObjects() { // Menu item 4
        global_static_local_objects_inner();
        cout << "--- global_static_local_objects_inner() returned ---" << endl;
        global_static_local_objects_inner();
        cout << "--- global_static_local_objects_inner() returned ---" << endl;
    }
```

### 문제 4 실행 결과
```plaintext
아래 실행 결과에서 main()이 실행하기 전에 전역 객체 gps의 생성자가 먼저 실행되어 초기화된다.
그 후 global_static_local_objects_inner()가 처음 호출될 때 static 객체인 sps의 생성자가
딱 한번만 호출된다. 두번째 global_static_local_objects_inner()가 호출될 때는 
sps의 생성자가 실행되지 않음을 확인할 수 있다.
sps 및 gps와 같은 전역 및 static 객체는 main() 함수가 리턴된 후 소멸자가 호출된다. 
생성자가 호출되는 역순으로 소멸자가 호출된다.
```
```c++
Person::Person(...):gps 1000 100 1 :gps adress:  // main() 호출이전에 전역객체 초기화
                            // 아직 main()이 실행 전이라 married가 true가 아닌 1로 출력됨
```
```plaintext
******************************* Main Menu *********************************
* 0.Exit 1.Class:Object(ch3_1)                                            *
***************************************************************************
Menu item number? 1

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 4

--- global_static_local_objects_inner() begins ---
Person::Person(...):sps 2000 200 false :sps adress:   // 처음 호출할 때만 sps 초기화함
--- global_static_local_objects_inner() returned ---

--- global_static_local_objects_inner() begins --- //두번째 호출에서는 sps 초기화하지 않음
--- global_static_local_objects_inner() returned ---

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0

******************************* Main Menu *********************************
* 0.Exit 1.Class:Object(ch3_1)                                            *
***************************************************************************
Menu item number? 0
Good bye!!                            // main()에서 리턴한 후 전역객체와 static 객체 소멸
Person::~Person():sps 2000 200 false :sps adress:
Person::~Person():gps 1000 100 true :gps adress:
```

### 문제 4-1 설명
```plaintext
1) 위 문제 4의 실행결과를 확인한 후 전역변수 gps를 아래처럼 주석처리하라.
//Person gps("gps", 1000, 100, true, "gps adress");

2) static 변수 sps를 아래처럼 주석처리하라.
    void global_static_local_objects_inner() {
        cout << "\n--- global_static_local_objects_inner() begins ---" << endl;
        //static Person sps("sps", 2000, 200, false, "sps adress");
    }
```

### 문제 4-1 실행 결과
```plaintext
...
Menu item number? 4

--- global_static_local_objects_inner() begins ---
--- global_static_local_objects_inner() returned ---

--- global_static_local_objects_inner() begins ---
--- global_static_local_objects_inner() returned ---

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0

******************************* Main Menu *********************************
* 0.Exit 1.Class:Object(ch3_1)                                            *
***************************************************************************
Menu item number? 0
Good bye!!
```