# OJ Ch9_2

### 이번 문제의 목적: 추상 클래스
```
추상 클래스를 만들어 본다. 
추상 클래스를 파생 클래스에서 상속한 후 추상 클래스의 순수 가상 함수들을 구현하여 오버라이딩한다. 
추상 클래스의 포인터 변수를 사용하여 동일한 기능을 제공하는 다른 파생 클래스의 객체를 제어한다.
여기서는 추상 클래스인 SmartPhone을 상속한 GalaxyPhone과 IPhone 클래스 두 버전을 구현한다.
그런 후 이들 두 클래스의 객체를 생성한 후 SmartPhone 포인터로 이들 객체들을 통합하여 관리한다.
----------------------------------------------------------------------------

    (추상클래스)Calculator Phone(추상클래스) -----> BaseStation(추상클래스)
                  \      /                       |
                 SmartPhone(추상클래스)<--     PersonManager ------ persons[...]
                  /      \            |                                :
           GalaxyPhone  IPhone        ---------------------------------:

```
### 코드 추가 및 변경 1
```
Person, Student, Worker, StudentWorker 클래스의 생성자, 복사 생성자, 소멸자 내에서
더 이상 어떤 출력도 되지 않도록 출력 문장들을 모두 주석 처리하라. 
예를들어, Student 생성자에서는 아래 세 문장을 모두 주석 처리하여 아무것도 출력되지 않게 한다. 
```
```c++
    cout << "Student::Student(...):"; printMembers(cout); cout << endl;

```

### 코드 추가 및 변경 2
```
UI 클래스 내의 아래 두 함수의 리턴 데이타 타입이 static const string&으로
되어 있다면 아래처럼 static string&로 수정하라.
```
```c++
	static string& getNext(const string& msg);
	static string& getNextLine(const string& msg);
```

### 문제 1 설명
```
typeid()와 == 연산자 활용
아래 실행 결과를 참고하여 PersonManager에서 사용자로부터 새로운 인적정보를 입력 받아 
새 객체를 생성한 후 PersonManager에서 관리하는 persons 객체들 중 새 객체와 동일한 
종류(학생)의 객체들 중에서 == 연산자를 이용하여 같은 객체를 찾아 출력하라. 이를 위해 먼저 
```
```
1) PersonManager에 아래 멤버 함수 선언을 run() 앞에 추가하고 
    void find();         // ch9_2 추가
---------------------------------------------------------------------------
2) PersonManager::run()의 menuStr에 아래 문자열을 추가하고, 
   또한 func_arr[]에 위 find() 함수를 등록하라.
---------------------------------------------------------------------------
        "= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =\n"
---------------------------------------------------------------------------
3) 구현 영역에서 find() 함수 구현 시 아래 코드를 활용하고 설명된 부분을 구현하라.
---------------------------------------------------------------------------
```
```c++
void PersonManager::find() { // Menu item 9
    printNotice("Input", "to find by operator ==");

    Person* p = 새 객체를 동적으로 생성한 후 인적정보를 입력받고 p에 대입 [insert() 참고]
    인적정보가 잘못 입력되었으면 여기서 리턴 [insert() 함수 참고]

    bool found = false;

    for 문을 이용하여 persons 벡터의 모든 객체 포인터 persons[i]에 대해
        if (persons[i]가 p가 포인터하는 객체와 동일한 종류의 객체이고, (아래 설명 참고)
            == 연산자를 이용하여 p 객체와 비교하여 같으면)  
            cout << "[" << i << "] "; persons[i]->println();
            found를 true로 설정

    위 for에서 동일한 객체를 하나도 찾지 못했으면 아래와 같이 출력
        cout << "NOT found by operator ==";
}
```
```
참고: persons 벡터 내에는 Person, Student, Worker, StudentWorker 등의 다양한 
    종류의 객체들을 관리하고 있으므로 사용자가 입력한 객체와 동일한 종류의 객체하고만 비교해야 한다.
    따라서 두 객체 변수 a, b가 동일한 종류의 객체인지는 typeid(a) == typeid(b)와 같이
    typeid() 키워드를 사용하여 비교하면 된다. 단, typeid()의 인자는 [객체] 또는 [클래스이름]
    이어야 함. 만약 객체 포인터 p가 있다면 typeid(*p)로 인자를 주어야 한다. 
    typeid()를 사용하기 위해서는 아래 파일을 include 해야 함.
    < > 사이의 공백은 제거하라. oj에서 HTML tag로 인식되는 오류를 피하기 위함임. 

#include < typeinfo >   // ch9_2 추가: for typeid(*p)
```

### 문제 1 실행 결과
```
====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
= 5.Insert(6_2) 6.Delete(6_2) 7.CopyPersons(7_2) 8.Reset(7_2)   =
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =
=================================================================
Menu item number? 2
The number of persons to append? 2 // 테스트를 위해 2명의 학생 정보을 추가함 
Input 2 [delimiter(P, S, W, or A)] [person information] :
// 아래 2명의 인적 정보를 복사해서 입력하라.
S s1 1 67.4 true :Seoul: Physics 3.3 1
S s1 1 77.4 false :Jongno-gu: Physics 3.5 1
display(): count 10
...
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[3] s2 2 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
...
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] s1 1 67.4 true :Seoul: Physics 3.3 1
[9] s1 1 77.4 false :Jongno-gu: Physics 3.5 1
...
Menu item number? 9   // Find
Input [delimiter(P, S, W, or A)] [person information] to find by operator ==
S s1 1 0 false :: Physics 0 1   // 학생 인적 정보: 사용자 입력
//
// 기존의 학생 객체들 중 == 연산자를 이용해 위와 동일한 객체들을 모두 찾아 출력
// 학생의 경우 == 연산자는 이름, id, 학과, 학년이 같으면 같은 객체임
//
[2] s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[8] s1 1 67.4 true :Seoul: Physics 3.3 1
[9] s1 1 77.4 false :Jongno-gu: Physics 3.5 1
...
Menu item number? 9   // Find
Input [delimiter(P, S, W, or A)] [person information] to find by operator ==
S s1 1 0 false :: Physics 0 2
NOT found by operator ==
```

### 문제 2 설명
```
[문제 1]에서 사용한 typeid()를 이용해 PersonManager::persons 벡터에서 관리되는 객체들 중
StudentWorker 클래스 객체들만 찾아서 객체의 정보를 출력하라. 아래 프로그램 실행 결과 참고할 것.
이를 위해 PersonManager에 아래 함수를 추가하고 run() 함수 내의 func_arr[]에 아래 함수를 
등록하라. 그리고 함수 코드를 완성하라.
```
```c++
void PersonManager::dispStudentWorkers() { // Menu item 10
    cout << "dispStudentWorkers(): " << endl;
    for문을 이용하여 persons 벡터의 각 객체 포인터 persons[i]에 대해 
        persons[i]가 StudentWorker 클래스 객체이면 아래처럼 출력. 
        (참고로 typeid(...)의 인자(...)는 [객체] 또는 [클래스이름]이어야 함. 
         인자가 포인터면 인자 앞에 *를 붙여야만 함) 
            cout << "[" << i << "] "; persons[i]->println();
}
```

### 문제 2 실행 결과
```
====================== Person Management Menu ...
Menu item number? 2   // Append
The number of persons to append? 2 // 알바생 2명의 인적 정보를 추가함
Input 2 [delimiter(P, S, W, or A)] [person information] :     
// 아래 2명의 인적 정보를 복사해서 입력하라.
A a3 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
A a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
display(): count 10
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[5] w2 4 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[6] a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] a3 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[9] a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false

====================== Person Management Menu ...
Menu item number? 10   // DispAlbaStud
dispStudentWorkers(): 
[6] a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] a3 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[9] a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false

// 위 Person Management Menu에서 연속하여 아래 메뉴 항목을 계속 입력하라. 
// 인덱스 번호 6을 가진 원소를 연속적으로 3번 삭제함
6   // Delete
6   // Index to delete?
6   // Delete
6   // Index to delete?
6   // Delete
6   // Index to delete?
...
Menu item number? 10   // DispAlbaStud
dispStudentWorkers(): 
[6] a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
```

### 코드 추가 및 변경 3
```
// 이제 순수 가상 함수를 활용하는 추상 클래스를 만들고 이를 상속하는 새로운 클래스를 만들어 보자.
// 먼저 아래 헤드 파일을 추가한 후 공백은 삭제하라.
```
```c++
#include < sstream >    // ch9_2 추가: for istringstream iss(expr);
```
```
새로 추가될 추상 및 일반 클래스들의 계층 구조
---------------------------------------------------------------------------

    (추상클래스)Calculator Phone(추상클래스) -----> BaseStation(추상클래스)
                  \      /                       |
                 SmartPhone(추상클래스)<--     PersonManager ------ persons[...]
                  /      \            |                                :
           GalaxyPhone  IPhone        ---------------------------------:

---------------------------------------------------------------------------
아래 클래스들을 소스 파일 내의 class Person 보다 위쪽에 추가하라.
---------------------------------------------------------------------------
Phone과 Calculator는 전화기와 계산기의 표준 함수 스펙만을 정의하고 있다.
SmartPhone은 두 개의 추상 클래스 Phone과 Calculator를 다중 상속하는 추상 클래스이다.
SmartPhone 추상 클래스를 실제 구현하는 것이 GalaxyPhone과 IPhone이며, 
이들 두 클래스들은 Phone, Calculator, SmartPhone 등에서 표준 스펙으로 
정의된 함수들을 삼성과 애플에서 override 해서 구현한 것이라고 생각하면 됨
```
```c++
//----------------------------------------------------------------------------
// Phone class
//----------------------------------------------------------------------------
class Phone
{
public:
    virtual ~Phone() {} // 가상 소멸자
    
    virtual void sendCall(const string& callee) = 0;
    //------------------------------------------------------------------------
    // 위 메소드는 "made a call to 수신자_이름(callee)"라고 출력해야 하며 
    // 이 출력의 앞 또는 뒤에 발신자 이름도 함께 출력하되 메이커가 알아서 적절히 
    // 회사명, 모델명 등과 함께 표시하면 된다.
    // 그런 후 baseStation.connectTo(caller, callee)를 호출해야 한다.
    //------------------------------------------------------------------------
    
    virtual void receiveCall(const string& caller) = 0;
    //------------------------------------------------------------------------
    // 이 메소드는 "received a call from 송신자_이름(caller)"라고 출력해야 하며 
    // 이 출력의 앞 또는 뒤에 수신자 이름도 함께 출력하되 메이커가 알아서 적절히 
    // 회사명, 모델명 등과 함께 표시하면 된다.
    //------------------------------------------------------------------------
};

//----------------------------------------------------------------------------
// Calculator class
//----------------------------------------------------------------------------
class Calculator
{
public:
    virtual ~Calculator() {} // 가상 소멸자
    
    // +, -, *, / 사칙연산만 지원하고 그 외의 연산자일 경우 
    // "NOT supported operator" 에러 메시지를 출력한다.
    // 수식과 계산 결과 또는 에러 메시지를 출력해야 하며 이 출력의 앞 또는 뒤에
    // 계산기 소유주 이름도 함께 출력하되 메이커가 알아서 적절히 회사명, 모델명 등과 함께 표시하면 된다.
    
    virtual void calculate(double oprd1, char op, double oprd2) = 0; // 예: (3, '+', 2.0)
    virtual void calculate(const string& expr) = 0;                  // 예: ("3 + 2")
    virtual void calculate(istream& in) = 0; // 키보드로부터 수식을 읽어 위 두 메소드 중 하나를 호출함
};

//----------------------------------------------------------------------------
// SmartPhone class
//----------------------------------------------------------------------------
class SmartPhone: public Phone, public Calculator
{
protected:
    string owner;  // 스마트폰 소유주 이름
public:
    SmartPhone(const string& owner): owner(owner) {}
    virtual ~SmartPhone() {} // 가상 소멸자
    virtual SmartPhone* clone() = 0;
    virtual string getMaker() = 0;
    void print(ostream& out) { out << owner << "'s Phone: " << getMaker(); }
    void println() { print(cout); cout << endl; }
};

//----------------------------------------------------------------------------
// GalaxyPhone class
//----------------------------------------------------------------------------
class GalaxyPhone: public SmartPhone
{
    void printTradeMark(const string& appName) {
        cout << " @ " << owner << "'s Galaxy " << appName << endl;
    }

public:
    GalaxyPhone(const string& owner): SmartPhone(owner) {}

    // 동적으로 메모리를 할당 받는 멤버가 없기 때문에 소멸자, 복사 생성자를 구현하지 않아도 됨
    // 컴파일러에 의해 제공되는 기본 소멸자와 복사 생성자를 활용하면 됨

    void sendCall(const string& callee)    override {
        /* TODO */
    }

    void receiveCall(const string& caller) override {
        /* TODO */
    }

    void calculate(double oprd1, char op, double oprd2) override {
        /* TODO */
    }

    void calculate(istream& in) override {
        /* TODO */
    }

    void calculate(const string& expr) override {
        // 키보드가 아닌 string expr에서 데이타를 읽어 들일 수 있는 istringstream을 만든다. 
        istringstream iss(expr);  
        // istringstream는 istream을 상속 받았기 때문에 iss는 자동으로 istream으로 업캐스팅 됨
        calculate(iss); // calculate(istream& in)을 호출함
        // calculate(cin)는 키보드에서 수식을 읽어 계산하지만
        //   calculate(iss)는 키보드가 아닌 문자열 스트림 iss에서 수식을 읽어 계산함.
        // GalaxyPhone은 여기서 calculate(istream& in)를 호출하지만
        //   아래 IPhone의 경우 반대로 calculate(istream& in)에서 
        //   calculate(const string& expr)을 호출함 (회사마다 구현 방법이 다름)
    }

    SmartPhone* clone() override { return nullptr /* TODO */ ; }

    string getMaker() override { return "SAMSUNG Galaxy"; }
};

//----------------------------------------------------------------------------
// IPhone class
//----------------------------------------------------------------------------
class IPhone: public SmartPhone
{
    string model;

    double add(double oprd1, double oprd2) { return oprd1 + oprd2; }
    double sub(double oprd1, double oprd2) { return oprd1 - oprd2; }
    double mul(double oprd1, double oprd2) { return oprd1 * oprd2; }
    double div(double oprd1, double oprd2) { return oprd1 / oprd2; }

    void printTradeMark(const string& appName) {
        cout << owner << "'s IPhone " << model << " " << appName;
    }

public:
    IPhone(const string& owner, const string& model): SmartPhone(owner), model(model) {}

    // 동적으로 메모리를 할당 받는 멤버가 없기 때문에 소멸자, 복사 생성자를 구현하지 않아도 됨
    // 컴파일러에 의해 제공되는 기본 소멸자와 복사 생성자를 활용하면 됨
    
    void sendCall(const string& callee) override {
        /* TODO */
    }

    void receiveCall(const string& caller) override {
        /* TODO */
    }

    void calculate(double oprd1, char op, double oprd2) override {
        /* TODO */
    }

    void calculate(const string& expr) override {
        /* TODO */
    }

    void calculate(istream& in) override {
        string line;
        getline(in, line);
        calculate(line);   
        // IPhone의 경우 여기서 위 calculate(const string& expr)를 호출하지만
        // GalaxyPhone은 반대로 calculate(const string& expr)에서 
        //                    calculate(istream& in)를 호출함
    }

    SmartPhone* clone() override { return nullptr /* TODO */ ; }

    string getMaker() override { return "Apple IPhone " + model; }
};
```

### 문제 3 설명
```
Person 클래스에 아래 멤버들을 추가하라.
1) 아래 멤버를 private 영역의 마지막에 추가하라.
```
```c++
    SmartPhone* smartPhone; // 스마트폰: 9_1에서 추가
```
```
2) 아래 멤버를 protected 영역의 마지막에 추가하라.
```
```c++
    SmartPhone* newSmartPhone();           // 9_1에서 추가
```
```
    위 함수는 아래처럼 구현하라.
    사람 id가 홀수(id % 2)면 GalaxyPhone 객체를, 짝수면 IPhone 객체를 동적으로 생성하여 
    리턴한다. 이때 각 스마트폰의 owner를 Person의 name으로 설정하고 
    IPhone의 경우 모델을 "13"으로 지정하라.
```
```
3) Person::Person(...) 생성자의 copyAddress(address); 다음에 아래 문장을 추가하라.
    smartPhone이 포인터하는 실제 객체는 GalaxyPhone 또는 IPhone 객체이다.
```
```c++
    smartPhone = newSmartPhone();
```
```
4) Person::~Person()에 아래 내용을 추가하라.
    smartPhone 멤버가 nullptr이 아니면 smartPhone이 포인터하는 객체 메모리를 반납하라.
    그리고 마지막 문장으로 smartPhone을 nullptr로 설정하라.
```
```
5) 아래 멤버 함수 선언을 public 영역의 setMemo(const char* c_str) 뒤에 추가하라.
```
```c++
    void setSmartPhone(SmartPhone* smPhone={}); // 9_1에서 추가
```
```
    위 함수를 아래처럼 구현하되 구현부의 맨 마지막에 배치하라.
    기존의 smartPhone 멤버가 nullptr이 아니면 이 변수가 포인트하는 메모리를 먼저 반납한다.
    매개변수 smPhone이 nullptr이면 newSmartPhone()을 호출한 후 리턴 값을, 
    nullptr이 아니면 smPhone 값을, smartPhone에 저장한다. smartPhone = ? :
```
```
6) 아래 멤버들을 public 영역의 getMemo() 선언 뒤에 추가하라.
```
```c++
    SmartPhone*   getSmartPhone() const { return smartPhone; }
    Phone*        getPhone()      const { return nullptr /* TODO */; }
    Calculator*   getCalculator() const { return nullptr /* TODO */; }
```
```
7) Person::Person(const Person& p) 복사 생성자의 맨 마지막에 아래 문장을 추가하라.
```
```c++
    smartPhone = p.smartPhone->clone(); // 기존 p.smartPhone 객체를 복제해서 대입
```
```
    위 코드가 정상적으로 작동할 수 있도록 GalaxyPhone과 IPhone 클래스의 clone()을 
    구현하라. 이 함수는 새로운 객체를 동적으로 할당한 후 포인터를 반환한다. 단, 동적 생성 시 
    복사 생성자를 호출하여 초기화하도록 해야 한다. 원본 객체를 복제하는 것임.
    Student 또는 Worker의 clone() 함수를 참고하라.
```
```
8) PersonManager에 아래 멤버함수와 함수 선언을 추가한 후 아래 코드를 완성하라.
    또한 PersonManager::run()내의 func_arr[]에 아래 함수를 등록하라.
```
```c++
void PersonManager::dispPhones() { // Menu item 11
    cout << "dispPhones(): count " << count << endl;
    for를 이용하여 persons 벡터의 각 객체 포인터 persons[i]에 대해 
        cout << "[" << i << "] "; persons[i]->getSmartPhone()->println();
        // 추상클래스 SmartPhone::println()->print()->가상함수 getMaker()-> 
        // 파생클래스(Galaxy 또는 IPhone)의 override된 getMaker() 함수가 실제 호출됨  
}
```

### 문제 3 실행 결과
```
====================== Person Management Menu ...
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2) ...
Menu item number? 11
dispPhones(): count 8
[0] p0's Phone: Apple IPhone 13
[1] p1's Phone: SAMSUNG Galaxy
[2] s1's Phone: SAMSUNG Galaxy
[3] s2's Phone: Apple IPhone 13
[4] w1's Phone: SAMSUNG Galaxy
[5] w2's Phone: Apple IPhone 13
[6] a1's Phone: SAMSUNG Galaxy
[7] a2's Phone: Apple IPhone 13
```

### 문제 3-1 설명
```
1) Person::operator = (const Person& p) 함수의 맨 마지막에 아래 문장을 추가하라.

    Person(const Person& p) 복사생성자에서는 멤버를 처음 초기화하는 것이기 때문에 
    smartPhone = p.smartPhone->clone()처럼 복제해서 바로 smartPhone에 대입함.
    그러나 = 연산자의 경우 기존 smartPhone 멤버가 포인터하고 있는 메모리가 이미 있으므로
    이를 먼저 반납하고 복제된 객체로 smartPhone을 설정해야 한다. 그래서 아래 함수를 호출함.
    setSmartPhone(p.smartPhone->clone()); 
```
```
2) OperatorOverload::personAssign() 함수의 내용을 아래 내용으로 교체하라.
    아래에서 기존 코드에서 Person의 = 연산자 앞뒤에 스마트 폰과 관련된 출력 문장이 추가되었다.  
```
```c++
    void personAssign() { // Memu item 4
        cout << "p:  "; p.println();
        cout << "p  smartPhone: "; p .getSmartPhone()->println();
        cout << "Person p2;" << endl;
        Person p2;
        cout << "p2: "; p2.println();
        cout << "p2 smartPhone: "; p2.getSmartPhone()->println();
        cout << "p2 = p" << endl;
        p2 = p;
        cout << "p2: "; p2.println();
        cout << "p2 smartPhone: "; p2.getSmartPhone()->println();
        cout << "Person p3(...);" << endl;
        Person p3("Hong",  0, 72.1, false, "Gwangju Nam-gu Bongseon-dong 21");
        cout << "p3: "; p3.println();
        cout << "p3 smartPhone: "; p3.getSmartPhone()->println();
        cout << "p3 = 20.0 + p2 + 30.5" << endl;
        p3 = 20.0 + p2 + 30.5;
        cout << "p3: "; p3.println();
        cout << "p3 smartPhone: "; p3.getSmartPhone()->println();
        cout << "p == p3 : " << (p == p3) << endl;
    }
```

### 문제 3-1 실행 결과
```
******************************* Main Menu ...
Menu item number? 5   // OperatorOverload

+++++++++++++++++++ Operator Overload ...
Menu item number? 4   // Assign
p:  p 1 65.4 true :Jong-ro 1-gil, Jongno-gu, Seoul:
p  smartPhone: p's Phone: SAMSUNG Galaxy
Person p2;
p2:  0 0 false ::
p2 smartPhone: 's Phone: Apple IPhone 13     // id가 0이므로 IPhone
p2 = p
p2: p 1 65.4 true :Jong-ro 1-gil, Jongno-gu, Seoul:
p2 smartPhone: p's Phone: SAMSUNG Galaxy     // p의 스마트폰 복제
Person p3(...);
p3: Hong 0 72.1 false :Gwangju Nam-gu Bongseon-dong 21:
p3 smartPhone: Hong's Phone: Apple IPhone 13 // id가 0이므로 IPhone
p3 = 20.0 + p2 + 30.5
p3: p 1 115.9 true :Jong-ro 1-gil, Jongno-gu, Seoul:
p3 smartPhone: p's Phone: SAMSUNG Galaxy     // p2의 스마트폰 복제
p == p3 : true
```

### 문제 3-2 설명
```
Person::set(const string& name, ..., const char* address) 함수와 
Person::inputMembers(istream& in) 함수의 맨 마지막에 아래 문장을 추가하라.

    아래 함수호출시 인자가 없기 때문에 이 함수의 매개변수 smPhone는 디폴트인 nullptr로 설정됨.
    따라서 이 함수 내에서 newSmartPhone()를 호출하여 smartPhone 객체를 새로 생성함 
    즉, set(...) 또는 키보드에서 Person을 입력 받을 경우, smartPhone은 새로 생성됨
    setSmartPhone();
```

### 문제 3-2 실행 결과
```
====================== Person Management Menu ...

Menu item number? 2   // Append
The number of persons to append? 7
Input 7 [delimiter(P, S, W, or A)] [person information] :    
// 아래 7명의 정보를 복사해서 한번에 입력
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
S s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
W w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
A a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
S s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan: Biology 3.8 3
W w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul: Naver Department-Head
A a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false
display(): count 15
... // 생략
[8] p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[9] s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
[10] w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
[11] a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
[12] s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan: Biology 3.8 3
[13] w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul: Naver Department-Head
[14] a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false

Menu item number? 11   // DispPhones
dispPhones(): count 15
... // 위 [문제 3]의 결과와 동일
[8] p3's Phone: SAMSUNG Galaxy
[9] s3's Phone: Apple IPhone 13
[10] w3's Phone: SAMSUNG Galaxy
[11] a3's Phone: Apple IPhone 13
[12] s4's Phone: SAMSUNG Galaxy
[13] w4's Phone: Apple IPhone 13
[14] a4's Phone: SAMSUNG Galaxy
```

### 문제 4 설명
```
위 문제에서 각 사람들에게 주어진 스마트폰은 Person의 id 값에 의해 스마트폰 종류가 결정되어진다.
이제 내가 원하는 메이커의 스마트폰을 지정할 수 있도록 해 보자.
---------------------------------------------------------------------------
먼저 CurrentUser::run() 내의 menuStr에 아래 문자열을 추가하라. 
공간을 줄이기 위해 메뉴 [메뉴 항목 15]가 [메뉴 항목 11] 뒤에 있음을 유의하라.
---------------------------------------------------------------------------
        "+ 10.DefaultParameter(6_1) 11.StaticMember(6_1) 15.CalExp(9_2) +\n"
        "+ 12.ChangeSmartPhone(9_2) 13.Calculate(9_2) 14.PhoneCall(9_2) +\n"
---------------------------------------------------------------------------
그리고 CurrentUser 클래스에 아래 멤버 함수를 추가한 후 구현하고 
CurrentUser::run()내의 func_arr[]에 아래 함수를 등록하라.
```
```c++
// 사용자로부터 생성할 스마트폰 종류를 입력받고 해당 스마트폰 객체를 생성한 후 
// 기존 rUser의 smartPhone 멤버를 새로 생성된 스마트폰 객체로 변경한다.
void CurrentUser::changeSmartPhone() {
    string& maker = UI::getNext("Maker of phone to change(ex: Samsung or Apple)? ");
    maker가 "Samsung"이면 GalaxyPhone 객체를
            "Apple" 이면 IPhone 객체를 동적으로 할당하여 생성한 후, 
            (위 각 스마트폰 객체 생성 시 owner는 rUser의 이름으로 지정하고 
             IPhone인 경우 모델명은 "14"로 하라.)
           생성된 스마트폰 객체를 rUser.setSmartPhone(...)을 호출하여 등록한다.
    else { // maker가 "Samsung" 또는 "Apple"이 아닌 경우
        cout << maker << ": WRONG phone's maker" << endl;
        return;
    }
    display();
}
```

### 문제 4 실행 결과
```
====================== Person Management Menu ...
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2) ...
Menu item number? 11
dispPhones(): count 8
...
[5] w2's Phone: Apple IPhone 13
[6] a1's Phone: SAMSUNG Galaxy
[7] a2's Phone: Apple IPhone 13

// 아래 메뉴 항목을 순서적으로 입력하라.
4     // Login 
a1
      // 입력 없이 그냥 엔터: 빈줄 입력
+++++++++++++++++++++ Current User Menu ...
+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +
+ 12.ChangeSmartPhone(9_2) 13.Calculate(9_2) 14.PhoneCall(9_2) +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 12
Maker of phone to change(ex: Samsung or Apple)? ssanm
ssanm: WRONG phone's maker

// 아래 메뉴 항목을 순서적으로 입력하라.
12    // ChangeSmartPhone
Apple
0     // Logout
4     // Login
a2

12    // ChangeSmartPhone
Samsung
0     // Logout

====================== Person Management Menu ...
Menu item number? 11   // DispPhones
dispPhones(): count 8
...
[5] w2's Phone: Apple IPhone 13
[6] a1's Phone: Apple IPhone 14    // SAMSUNG -> Apple
[7] a2's Phone: SAMSUNG Galaxy     // Apple   -> SAMSUNG
```

### 문제 5 설명
```
이제 스마트폰에 계산기 기능을 추가 해 보자.
---------------------------------------------------------------------------
먼저 CurrentUser 클래스에 아래 멤버 함수를 추가한 후 
CurrentUser::run()내의 func_arr[]에 아래 함수를 등록하라.
```
```c++
void CurrentUser::calculate() {
    cout << "Expression: ";
    Calculator* cal = rUser.getCalculator();
    cal->calculate(cin); 
    // 추상클래스 포인트 변수 cal을 이용해 가상함수 calculate(cin) 호출 -> 
    // 파생클래스(GalaxyPhone or IPhone)의 override된 함수가 실제 호출됨
}
```
```
// 1) 위 코드가 정상적으로 작동할 수 있도록 Person::getCalculator()를 구현하라.
//    Calculator가 SmartPhone의 부모 클래스이기 때문에 Person::getSmartPhone()처럼 
//    값을 리턴하라. (SmartPhone*에서 Calculator*로 자동으로 업캐스팅 되어 리턴됨)
//----------------------------------------------------------------------------
2) 동일한 방법을 사용하여 Person::getPhone() 함수도 구현하라.
---------------------------------------------------------------------------
위 CurrentUser::calculate() 내의 cal->calculate(cin)는 현재 Person의 
smartPhone에 등록된 실제 스마트 폰이 GalaxyPhone 또는 IPhone 객체냐에 따라 
해당 객체의 오버라딩된 calculate(istream& in) 함수가 호출된다.
---------------------------------------------------------------------------
3) GalaxyPhone의 calculate(double oprd1, ...)와 calculate(istream& in)을
    아래 코드로 교체하라. 
    GalaxyPhone은 switch 문장 내에서 직접 계산한다. IPhone의 경우 다른 방식으로 구현.
```
```c++
    void calculate(double oprd1, char op, double oprd2) override {
        cout << oprd1 << " " << op << " " << oprd2 << " = ";
        switch (op) { // switch 문장 내에서 직접 계산함
        case '+': cout << oprd1 + oprd2; break;
        case '-': cout << oprd1 - oprd2; break;
        case '*': cout << oprd1 * oprd2; break;
        case '/': cout << oprd1 / oprd2; break;
        default:  cout << "NOT supported operator"; break;
        }
        printTradeMark("Calculator");
    }

    // istream& in에서 각 토큰을 분리한다. 여기서 in은 키보드인 cin일 수도 있고, 
    // 또는 문자열 스트림(키보드가 아닌 문자열에서 읽음)일 수도 있다.
    void calculate(istream& in) override {
        double oprd1, oprd2;
        string op, soprd2;
        in >> oprd1 >> op;   // 2* 또는 2 * 로 입력해도 oprd1와 op가 구분되어 입력 됨
        if (op.size() > 1) { // *3 처럼 연산자와 피연산자가 붙어 있는 경우
            soprd2 = op.substr(1); // substring 발췌(피연산자): "*3"의 경우 "3"
            oprd2 = stod(soprd2);  // 문자열 숫자 "3" -> double 3.0으로 변환
        }
        else                 // * 3 처럼 연산자와 피연산자가 떨어져 있는 경우
            in >> oprd2;
        calculate(oprd1, op[0], oprd2);
    }
```

### 문제 5 실행 결과
```
// Person Management Menu에서 [ w1 ]로 로그인한 후 아래를 실행하라.
+++++++++++++++++++++ Current User Menu ...
+ 12.ChangeSmartPhone(9_2) 13.Calculate(9_2) 14.PhoneCall(9_2) ...
Menu item number? 13   // Calculate
Expression: 2 + 3
2 + 3 = 5 @ w1's Galaxy Calculator

13    // Calculate
2- 3
2 - 3 = -1 @ w1's Galaxy Calculator

13    // Calculate
2 *3
2 * 3 = 6 @ w1's Galaxy Calculator

13    // Calculate
3/2
3 / 2 = 1.5 @ w1's Galaxy Calculator

13    // Calculate
1 % 2
1 % 2 = NOT supported operator @ w1's Galaxy Calculator
```

### 문제 6 설명
```
IPhone의 calculate(double oprd1, ...)와 calculate(const string& expr)을
아래 코드로 교체하라. GalaxyPhone의 경우 switch 문장 내에서 직접 계산했지만
IPhone은 switch 문장 내에서 직접 계산하지 않고 각 함수를 호출하여 계산한다.
```
```c++
    void calculate(double oprd1, char op, double oprd2) override {
        string printMsg;
        double ret = 0;
        switch (op) { // switch 문장 내에서 직접 계산하지 않고 각 함수를 호출함
        case '+': ret = add(oprd1, oprd2); break;
        case '-': ret = sub(oprd1, oprd2); break;
        case '*': ret = mul(oprd1, oprd2); break;
        case '/': ret = div(oprd1, oprd2); break;
        default : printMsg = "NOT supported operator"; break;
        }
        printTradeMark("Calculator"); cout << ": ";
        if (printMsg == "") // 정상적으로 계산되었을 경우
            cout << oprd1 <<" "<< op << " "<< oprd2 <<" = "<< ret << endl;
        else                // 연산자가 잘못 되었을 경우
            cout << printMsg << endl;
    }

    // 문자열 expr에서 연산자를 찾은 다음 연산자의 좌우 피연산자를 별도의 문자열로 발췌한다.
    void calculate(const string& expr) override {
        string oprs[] = { "+", "-", "*", "/" }; // 연산자 종류
        size_t pos, i, length = sizeof(oprs) / sizeof(oprs[0]); // 연산자 개수
        for (i = 0; i < length; i++)
            if ((pos=expr.find(oprs[i])) != string::npos) 
                break;   // 수식에서 연산자를 찾은 경우
        if (i >= length) // 수식에서 연산자를 찾지 못한 경우
            calculate(0, '\0', 0); // op 값으로 '\0'를 설정하여 에러가 발생하게 함
        else {
            string soprd1 = expr.substr(0, pos); // 왼쪽 피연산자 발췌
            string soprd2 = expr.substr(pos+1);  // 오른쪽 피연산자 발췌
            double oprd1 = stod(soprd1); // 문자열로 된 피연산자를 실수 값으로 변경
            double oprd2 = stod(soprd2); // 문자열로 된 피연산자를 실수 값으로 변경
            calculate(oprd1, expr[pos], oprd2);
        }
    }
```
```
주의: GalaxyPhone이든 IPhone이든 결국 SmartPhone 클래스의 표준에 따라 구현해야 한다.
    다만 구현 방법은 각 회사별로 서로 다르게 구현해도 상관 없지만, 
    함수 원형, 계산 결과 출력 형식, 오류 메시지 등은 표준에 따라야 한다
```

### 문제 6 실행 결과
```
// Person Management Menu에서 [ w2 ]로 로그인한 후 아래를 실행하라.

13    // Calculate
2 + 3
w2's IPhone 13 Calculator: 2 + 3 = 5

13    // Calculate
2- 3
w2's IPhone 13 Calculator: 2 - 3 = -1


13    // Calculate
2 *3
 w2's IPhone 13 Calculator: 2 * 3 = 6
 
13    // Calculate
3/2
w2's IPhone 13 Calculator: 3 / 2 = 1.5

13    // Calculate
1 % 2
w2's IPhone 13 Calculator: NOT supported operator
```

### 코드 추가 및 변경 4
```
이제 스마트폰에 전화 기능을 추가 해 보자. 이를 위해 먼저 
1) 휴대폰 기지국 역할을 하는 추상 BaseStation 클래스를 class Phone 앞쪽에 배치하라.
```
```c++
//----------------------------------------------------------------------------
// 휴대폰 기지국
//----------------------------------------------------------------------------
class BaseStation
{
public:
    virtual ~BaseStation() {}

    virtual bool connectTo(const string& caller, const string& callee) = 0;
    //------------------------------------------------------------------------
    // 이 메소드는 Phone::sendCall(const string& callee)에서 호출되어야 한다.
    // 수신자 callee라는 사람이 존재할 경우
    //    cout << "Base station: sends a call signal of " << caller <<
    //              " to " << callee << endl;를 출력하고
    //    이 사람의 등록된 Phone의 receiveCall(caller, callee)을 호출하고 true 리턴
    // 존재하지 않을 경우 
    //    "callee_name: NOT found"라는 에러 메시지 출력하고 false 리턴
    //------------------------------------------------------------------------
};
```
```
2) PersonManager 클래스가 BaseStation을 상속하도록 아래처럼 코드를 수정하라.
    이는 특정 사용자가 전화를 걸때 수신자를 찾아 상호 연결해 주는 무선 기지국 기능을 
    PersonManager가 제공하기 위함이다. 
    그리고 추상 클래스인 BaseStation의 순수 가상 함수인 connectTo(...)를 오버라이딩하는 
    아래 connectTo() 함수 선언을 기존 run() 함수 앞에 추가하라. 
```
```c++
class PersonManager: public BaseStation  //ch9_2 상속
{
    ....
    bool connectTo(const string& caller, const string& callee) override; //ch9_2 추가
    void run();
};
```
```
3) 아래의 baseStation, initBaseStation() 등의 static 멤버를 기존 Phone 클래스에 추가하고,
    baseStation의 실제 static 변수 정의를 클래스 바깥에 선언하라.
```
```c++
class Phone
{
    // 아래 static 멤버는 모든 Phone 객체에서 사용(공유)할 수 있다.
protected:
    // static 변수 선언이며 실제 메모리 확보을 위해선 클래스 바깥에서 별도로 선언해야 함
    static BaseStation* baseStation;
public:
    static void initBaseStation(BaseStation* bs) { baseStation = bs; }
    
    ... // 기존 멤버들
};

// 아래 전역변수는 PersonManager 생성자에서 initBaseStation(...)을 호출하여 초기화해야 함
BaseStation* Phone::baseStation; // 실제 static 멤버 변수 메모리 확보
```
```
4) 아래 코드를 PersonManager::PersonManager(...) 생성자의 마지막에 추가하라.
    이 코드에서 PersonManager의 this를 initBaseStation()의 함수 인자로 넘겨 주었는데, 
    이는 PersonManager가 BaseStation을 상속 받았기 때문에 this는 BaseStation* 으로  
    컴파일러에 의해 자동으로 업캐스팅 된다. 
    따라서 Phone::baseStation static 멤버는 곧 PersonManager를 포인터 한다.
```
```c++
    Phone::initBaseStation(this);
    // 추상클래스 BaseStation이 PersonManager의 부모 클래스이므로
    // this 포인터가 자동으로 업캐스팅되어 BaseStation*로 변경됨
```
```
5) CurrentUser 클래스에 아래 멤버 함수를 추가한 후
    CurrentUser::run()내의 func_arr[]에 아래 함수를 등록하라.
```
```c++
void CurrentUser::phoneCall() {
    string& callee = UI::getNext("Name to call? "); // 수신자 이름
    rUser.getPhone()->sendCall(callee);             // rUer가 송신자임
    // 궁극적으로 파생 클래스인 Galaxy 또는 IPhone의 오버라이딩된 sendCall()이 호출된다.
}
```
```
6) 위 코드가 정상적으로 작동할 수 있도록 Person::getPhone()를 구현하라.
    [문제 5]의 2)에서 이미 구현하였지만 한번 더 코드를 자동 업캐스딩되는 것을 복습하라.
    Phone 클래스가 SmartPhone의 부모 클래스이기 때문에 Person::getSmartPhone()처럼 
    값을 리턴하라. (SmartPhone*에서 자동으로 Calculator*로 업캐스팅 되어 리턴된다.)
```

### 문제 7 설명
```
1) 아래 코드를 GalaxyPhone 클래스에 추가하고 코드를 완성하라. Phone 클래스에 기술한 
    함수들의 표준 기능을 다시 한번 읽어 본 후 아래 함수를 구현하기 바란다.
```
```c++
    void sendCall(const string& callee)    override {
        아래 실행 결과를 참고해서 "Made a call to "와 callee를 출력한 후 TradeMark를 출력하라.
        Phone 클래스로부터 상속 받은 static 포인트 멤버 변수의 baseStation->connectTo()
        멤버 함수를 호출하여 수신자에게 신호를 전송하라. 이 함수의 인자로 
        SmartPhone에 저장되어 있는 송신자 owner와 매개변수인 수신자 callee를 지정하라.
    }

    void receiveCall(const string& caller) override {
        실행 결과를 참고해서 "Recieved a call from "와 caller를 출력한 후 TradeMark를 출력하라.
        // 위 "Recieved" 단어가 오타인데 그래도 일단 이렇게 입력하세요.^^
    }
```
```
2) PersonManager 클래스에 아래 함수를 추가하고 코드를 완성하라.
    이 함수는 PersonManager가 상속받은 BaseStation의 순수 가상 함수를 오버라이딩하는 것이다.
    sendCall(const string& callee)에서 이 함수를 호출한다.
```
```c++
// PersonManager::persons 벡터에 관리 중인 여러 사람들 중에서 
// 수신자를 찾아서 그 수신자의 스마트 폰의 receiveCall()을 호출한다.
bool PersonManager::connectTo(const string& caller, const string& callee) {
    Person* p = callee라는 이름을 가진 사람을 찾아 p에 저장; 
    (사람 찾기는 기존 멤버 함수 이용할 것: login() 참조)
    if (p == nullptr) return false; // 수신자를 찾지 못한 경우
    실행 결과를 참고하여 "Base station: sends a call signal of "와 caller, 그리고
        " to "와 callee를 출력하라.
    p의 Phone을 구한 후 그 폰의 receiveCall() 호출 (p와 폰이 모두 포인터임)
    (Phone 구하는 것은 위 CurrentUser::phoneCall() 참고)
    return true;
}
```

### 문제 7 실행 결과
```
// Person Management Menu에서 [ s1 ]으로 로그인한 후 아래를 실행하라.

+++++++++++++++++++++ Current User Menu ...
+ 12.ChangeSmartPhone(9_2) 13.Calculate(9_2) 14.PhoneCall(9_2) ...
Menu item number? 14    // PhoneCall
Name to call? w1                                 // 송신자 s1, 수신자 w1
Made a call to w1 @ s1's Galaxy Phone            // sendCall()의 출력
Base station: sends a call signal of s1 to w1    // connectTo()의 출력
Recieved a call from s1 @ w1's Galaxy Phone      // receiveCall()의 출력
...
Menu item number? 14    // PhoneCall
Name to call? w4
Made a call to w4 @ s1's Galaxy Phone
w4: NOT found
```

### 문제 8 설명
```
1) 아래 코드를 IPhone 클래스에 추가하고 코드를 완성하라.
```
```c++
    void sendCall(const string& callee) override {
        TradeMark를 출력한 후 ": made a call to " 와 callee를 출력하라.
        (아래 실행 결과를 참고)
        baseStation의 connectTo(...)를 호출하라. (GalaxyPhone::sendCall() 참고)
    }

    void receiveCall(const string& caller) override {
        TradeMark를 출력한 후 ": received a call from " 와 caller를 출력하라.
        (아래 실행 결과를 참고)
    }
```

### 문제 8 실행 결과
```
// Person Management Menu에서 [ s2 ]으로 로그인한 후 아래를 실행하라.

Menu item number? 14    // PhoneCall: IPhone -> IPhone
Name to call? w2                                 // 송신자 s2, 수신자 w2
s2's IPhone 13 Phone: made a call to w2          // sendCall()의 출력
Base station: sends a call signal of s2 to w2    // connectToo()의 출력
w2's IPhone 13 Phone: received a call from s2    // receiveCall()의 출력

...
Menu item number? 14    // PhoneCall: IPhone -> Galaxy
Name to call? w1
s2's IPhone 13 Phone: made a call to w1
Base station: sends a call signal of s2 to w1
Recieved a call from s2 @ w1's Galaxy Phone

// 0 4 이 메뉴에서 빠져 나갔다 다시 [ s1 ]로 로그인 한 후 아래를 실행하라.
Menu item number? 14    // PhoneCall: Galaxy -> IPhone
Name to call? w2
Made a call to w2 @ s1's Galaxy Phone
Base station: sends a call signal of s1 to w2
w2's IPhone 13 Phone: received a call from s1
```

### 문제 9 설명
```
CurrentUser 클래스에 아래 멤버 함수를 추가한 후 
CurrentUser::run()내의 func_arr[]에 아래 함수를 등록하라.
---------------------------------------------------------------------------
아래 함수와 [문제 5]의 CurrentUser::calculate() 함수와의 차이점은 무엇인가?
[문제 5]에선 Calculator::calculate(istream& in) 호출
    즉, cal->calculate(cin) 호출 => 키보드에서 직접 수식을 읽어 계산함
[문제 9]에선 Calculator::calculate(const string& expr) 호출
    즉, 키보드에서 한 line을 읽은 후 
        cal->calculate(line) 호출 => 문자열(line)에서 수식을 읽어 계산함
```
```c++
void CurrentUser::calExpr() {
    cout << "Expression: ";
    string line;
    getline(cin, line);   // 키보드에서 한 줄 입력 받아 line에 저장
    Calculator* cal = rUser.getCalculator();
    cal->calculate(line); 
    // Calculator::calculate(string& expr) 호출 => 문자열 expr에서 수식을 읽어 계산함
    // cal->calculate("2+3") 형식으로 문자열을 주고 계산할 수 있음; 예) "2 / 3", "3 *2"
    // 추상클래스 포인트 변수 cal을 통해 가상함수 Calculator::calculate("2+3") 호출 =>
    // 파생클래스(Galaxy 또는 IPone)의 override된 상응하는 함수가 실제 호출됨
}
```
### 문제 9 실행 결과
```
[문제 5]와 [문제 6]의 입력 데이타와 동일하게 입력한 후 결과가 동일하게 나오는지 확인하라.
```