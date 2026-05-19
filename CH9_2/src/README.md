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