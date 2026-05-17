# OJ CH9_1
### 이번 문제의 목적: 가상함수
```
최상위 클래스인 Person의 일부 함수를 가상함수로 선언하고 상속받은 클래스들인 Student, Worker, 
StudentWorker에서 가상함수들을 override한다.
여기서 우리가 주목해야 할 것은 PersonManager::persons은 VectorPerson형의 데이타이며
VectorPerson::pVector는 Person*의 배열인 pVector[]이다. 
즉, 각각의 pVector[i]는 Student, Worker, StudentWorker의 최상위 클래스인 Person*이다.
pVector[]는 Person*만 가지고 있을 뿐인데도 가상함수를 활용함으로써 
Student, Worker, StudentWorker의 override된 함수들을 호출할 수 있다는 것이다.
```

### 코드 추가 1
```
아래 문자열로 메뉴 문자열을 수정하라.

메인메뉴 첫줄 변경(", 9" 추가)
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9)                          *

PersonManger 메뉴 첫줄 변경(", ch9" 추가)
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
```

### 문제 1 설명
```
가상함수와 가상함수 재정의(오버라이딩)
                   Person
                  /      \
              Student  Worker
                  \      /
                 StudentWorker

---------------------------------------------------------------------------
1) 최상위 클래스인 Person 클래스 [선언부]에서 소멸자, clone(), print() 등 
   세 개의 함수 [원형]에서 이들을 가상함수로 선언하라. 예를 들어,
   virtual ~Person(); virtual void print(ostream& out);
   위에서 clone()은 객체들이 복사될 때 사용된다. 
---------------------------------------------------------------------------
2) Student, Worker, StudentWorker 클래스 [선언부]에서 위 세 함수들의 [원형]에 
   override를 추가하라. 예를 들어,
   ~Student() override; void print(ostream& out) override;
   이는 부모 클래스의 동일한 함수를 파생 클래스에서 재정의 한다는 것을 의미하며, 
   컴파일러는 자동으로 함수 리턴타입, 매개변수 등이 부모 클래스의 함수와 일치하는지 체크한다. 
---------------------------------------------------------------------------
3) Student, Worker, StudentWorker 클래스 내의 println() 함수들을 모두 삭제하라.
   이제 이 함수는 필요없는데 이유는 Person 클래스의 println()이 파생 클래스의 
   override된 print()를 호출해서 동일한 기능을 제공할 수 있기 때문이다. 
---------------------------------------------------------------------------
8장에서 메모리 반납시 문제 발생 가능성이 있었던 문장은 주석처리 했는데 
이제 가상함수로 이 문제를 해결했기 때문에 아래 지시대로 주석을 해제하라.  
---------------------------------------------------------------------------
4) Inheritance::student(), worker(), studentWorker()에 있는 아래 문장의 주석을 
   각각 해제하라. 이는 비록 이들이 Person *일지라도 Person의 소멸자가 가상함수이므로
   실행 시 파생클래스의 오버라딩된 소멸자를 찾아 호출하기 때문에 정상적으로 메모리가 반납된다. 
        //delete s3;
        //delete w3;
        //delete p3;
---------------------------------------------------------------------------
5) PersonManager::deleteElemets()내의 주석처리된 /* delete persons[i] */ ;
   문장을 주석 해제하라.
```

### 문제 1 실행 결과
```
******************************* Main Menu ...
Menu item number? 1
---------------------------------------------------------------------------
아래 출력은 MultiManager 클래스 내의 persons[], students[], workers[], albas[] 
배열의 각 원소의 생성자가 실행된 것임. (ch8-2 내용과 동일)
---------------------------------------------------------------------------
Person::Person(...):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
StudentWorker::StudentWorker(...): :Seven Eveven,eMart Jinju,CU Bongsun: true
---------------------------------------------------------------------------
아래는 PersonManager::PersonManager(생성자) -> pushArray() 내의 
array[i]->clone()에 의해 복제(복사생성자)될 때의 출력이다. 여기서 각 파생 클래스의 override된 
clone()이 실행되어 Person만 복제되는 것이 아니라 파생 클래스 객체 전체가 복제된다.
ch8-2의 [문제 8] 앞에 있는 [문제점] 부분의 출력과 비교해 보면 차이점을 알 수 있을 것임
---------------------------------------------------------------------------
Person::Person(const Person&):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:  // p0
Person::Person(const Person&):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul: // p1
Person::Person(const Person&):s1 1 65.4 true :Jongno-gu Seoul:    // s1
Student::Student(const Student& s): Physics 3.8 1
Person::Person(const Person&):s2 2 54.3 false :Yeonje-gu Busan:   // s2
Student::Student(const Student& s): Electronics 2.5 4
Person::Person(const Person&):w1 3 33.3 false :Kangnam-gu Seoul:  // w1
Worker::Worker(const Worker& w): Samsung Director
Person::Person(const Person&):w2 4 44.4 true :Dobong-gu Kwangju:  // w2
Worker::Worker(const Worker& w): Hyundai Manager
Person::Person(const Person&):a1 5 55.5 true :Dong-gu Incheon:    // a1
Student::Student(const Student& s): Computer 3.5 2
Worker::Worker(const Worker& w): Hyundai Labor
StudentWorker::StudentWorker(const StudentWorker& a): :CU KangNam,Seven Eleven,GSStore Suwon: false
Person::Person(const Person&):a2 6 66.6 false :Sasang-gu Sejong:  // a2
Student::Student(const Student& s): History 3.1 1
Worker::Worker(const Worker& w): Kia CEO
StudentWorker::StudentWorker(const StudentWorker& a): :Seven Eveven,eMart Jinju,CU Bongsun: true
PersonManager::run() starts

====================== Person Management Menu ...
Menu item number? 1
display(): count 8
---------------------------------------------------------------------------
아래에서 각 객체들의 모든 멤버들이 정상적으로 출력된다. (Person 객체 멤버들만 출력되는 것이 아니다.)
Person::println()이 가상함수인 print()를 호출하는데 
이 때 Person::print()가 호출되는 것이 아니라, 파생 클래스의 override된 print() 함수가 
대신 호출되어 파생 클래스의 멤버들이 출력되는 것이다.
---------------------------------------------------------------------------
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[3] s2 2 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[4] w1 3 33.3 false :Kangnam-gu Seoul: Samsung Director
[5] w2 4 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[6] a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true

====================== Person Management Menu ...
Menu item number? 0
PersonManager::run() returned
Person::~Person():p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
Student::~Student(): Electronics 2.5 4
Person::~Person():s2 2 54.3 false :Yeonje-gu Busan:
Worker::~Worker(): Samsung Director
Person::~Person():w1 3 33.3 false :Kangnam-gu Seoul:
Worker::~Worker(): Hyundai Manager
Person::~Person():w2 4 44.4 true :Dobong-gu Kwangju:
StudentWorker::~StudentWorker(): :CU KangNam,Seven Eleven,GSStore Suwon: false
Worker::~Worker(): Hyundai Labor
Student::~Student(): Computer 3.5 2
Person::~Person():a1 5 55.5 true :Dong-gu Incheon:
StudentWorker::~StudentWorker(): :Seven Eveven,eMart Jinju,CU Bongsun: true
Worker::~Worker(): Kia CEO
Student::~Student(): History 3.1 1
Person::~Person():a2 6 66.6 false :Sasang-gu Sejong:
---------------------------------------------------------------------------
이상의 소멸된 8개 객체는 Person Management Menu 종료 시 MultiManager::personMng 
객체가 소멸될 때 PersonManager::~PersonManager()가 호출되어 객체들이 소멸되면서 출력된 것임;
즉, delete persons[i]에 의해 각 객체가 소멸되는데 여기서 persons[i]는 Person*이지만 
이것이 포인트하는 실제 객체(파생 클래스)의 오버라이딩된 소멸자 함수가 실행되어 정상적으로 소멸된 것임;
---------------------------------------------------------------------------
아래 내용은 MultiManager의 MultiManager 클래스 내의 persons[], students[], 
workers[], albas[] 배열의 원소들이 소멸되는 것임
---------------------------------------------------------------------------
StudentWorker::~StudentWorker(): :Seven Eveven,eMart Jinju,CU Bongsun: true
Worker::~Worker(): Kia CEO
Student::~Student(): History 3.1 1
Person::~Person():a2 6 66.6 false :Sasang-gu Sejong:
StudentWorker::~StudentWorker(): :CU KangNam,Seven Eleven,GSStore Suwon: false
Worker::~Worker(): Hyundai Labor
Student::~Student(): Computer 3.5 2
Person::~Person():a1 5 55.5 true :Dong-gu Incheon:   // 이상은 albas[] 원소 소멸
Worker::~Worker(): Hyundai Manager
Person::~Person():w2 4 44.4 true :Dobong-gu Kwangju:
Worker::~Worker(): Samsung Director
Person::~Person():w1 3 33.3 false :Kangnam-gu Seoul: // 이상은 workers[] 원소 소멸
Student::~Student(): Electronics 2.5 4
Person::~Person():s2 2 54.3 false :Yeonje-gu Busan:
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:  // 이상은 students[] 원소 소멸
Person::~Person():p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
Person::~Person():p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
Person::~Person():p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
Person::~Person():p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::~Person():p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21: 
이상은 persons[] 배열 원소 소멸

---------------------------------------------------------------------------
다시 Person Management Menu에 들어간 후에 아래를 실행시켜라.
---------------------------------------------------------------------------

====================== Person Management Menu ...
Menu item number? 7   // CopyPersons
---------------------------------------------------------------------------
copyPersons(): 8개의 객체의 override된 clone()이 실행 되어 8개의 복사생성자가 실행됨.
---------------------------------------------------------------------------
Person::Person(const Person&):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(const Person&):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(const Person&):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(const Student& s): Physics 3.8 1
Person::Person(const Person&):s2 2 54.3 false :Yeonje-gu Busan:
Student::Student(const Student& s): Electronics 2.5 4
Person::Person(const Person&):w1 3 33.3 false :Kangnam-gu Seoul:
Worker::Worker(const Worker& w): Samsung Director
Person::Person(const Person&):w2 4 44.4 true :Dobong-gu Kwangju:
Worker::Worker(const Worker& w): Hyundai Manager
Person::Person(const Person&):a1 5 55.5 true :Dong-gu Incheon:
Student::Student(const Student& s): Computer 3.5 2
Worker::Worker(const Worker& w): Hyundai Labor
StudentWorker::StudentWorker(const StudentWorker& a): :CU KangNam,Seven Eleven,GSStore Suwon: false
Person::Person(const Person&):a2 6 66.6 false :Sasang-gu Sejong:
Student::Student(const Student& s): History 3.1 1
Worker::Worker(const Worker& w): Kia CEO
StudentWorker::StudentWorker(const StudentWorker& a): :Seven Eveven,eMart Jinju,CU Bongsun: true
---------------------------------------------------------------------------
이하는 copyPersons() 내의 display() 실행 결과
---------------------------------------------------------------------------
display(): count 16
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] pp0 30 71 true :Gwangju Nam-gu Bongseon-dong 21:
[9] pp1 31 62.1 false :Jong-ro 1-gil, Jongno-gu, Seoul:
[10] ss1 21 66.4 false :Jongno-gu Seoul: Physics 3.8 1
[11] ss2 22 55.3 true :Yeonje-gu Busan: Electronics 2.5 4
[12] ww1 23 34.3 true :Kangnam-gu Seoul: Samsung Director
[13] ww2 24 45.4 false :Dobong-gu Kwangju: Hyundai Manager
[14] aa1 25 56.5 false :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[15] aa2 26 67.6 true :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true

---------------------------------------------------------------------------
주목: PersonManager::persons[i]는 곧 VectorPerson::pVector[i]이고 이는 Person*이다.
    PersonManager::display() 내의 persons[i]->println(),
    PersonManager::copyPersons() 내의 persons[i]->clone(),
    PersonManager::~PersonManager() -> deleteElemets() -> delete persons[i]
    등에서 보는 것처럼 Person *인 persons[i]를 통해 print(), clone(), 소멸자들을 호출했는데 
    실제는 Student, Worker, StudentWorker의 override된 함수들이 호출된다는 것이다.
    이를 객체지향프로그래밍 언어의 꽃이라 할 수 있는 [다형성]이라 한다.
---------------------------------------------------------------------------
다형성(polymorphism):
    실제로 pVector[]에 저장되어 있는 것은 Student, Worker, StudentWorker의
    다양한 종류의 객체 포인터들인데 이들을 모두 최상위 클래스인 Person* 업캐스팅해서 관리하고 있다. 
    파생 클래스의 실제 객체가 무엇인든 업캐스팅된 기본(부모) 클래스의 포인터(Person*)만을 가지고도 
    실제 객체의 오버라이딩된 함수들을 호출할 수 있다. 동일한 함수 이름으로 서로 다르게 구현된 
    파생 클래스들의 오버라이딩된 함수를 호출할 수 있다는 것이다. 다형성(polymorphism).
    아래 문제들도 다형성 원리을 기반으로 하고 있다.
---------------------------------------------------------------------------
```

### 문제 2 설명
```
1) 최상위 클래스인 Person 클래스 선언부에서 whatAreYouDoing() 함수를 가상함수로 선언하라.
2) Student, Worker, StudentWorker 클래스 선언부에서 위 함수의 원형에 override를 추가하라.
```

### 문제 2 실행 결과
```
******************************* Main Menu ...
Menu item number? 1   // PersonManager
...
PersonManager Menu에서 아래 메뉴 항목을 순서적으로 입력하라.

====================== Person Management Menu ...
Menu item number? 4   // Login
s1            // Student 객체로 로그인
              // 그냥 엔터 입력; 즉, 빈줄 입력해야 함
+++++++++++++++++++++ Current User Menu ...
Menu item number? 5   // WhatAreYouDoing
~~~~~~~~~~~~~~~~ Student::whatAreYouDoing() ~~~~~~~~~~~~~~~~
s1 is studying as a 1-year student in Physics
s1 took several courses and got GPA 3.8
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Menu item number? 0   // Logout
4             // Login
w1            // Worker 객체로 로그인
              // 그냥 엔터 입력; 즉, 빈줄 입력해야 함
5
!!!!!!!!!!!!!!!! Worker::whatAreYouDoing()!!!!!!!!!!!!!!!!!
w1 works in Samsung as Director
w1 is now enjoying his(her) vacation
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
0             // Logout
4             // Login
a1            // StudentWorker 객체로 로그인
              // 그냥 엔터 입력; 즉, 빈줄 입력해야 함
5             // WhatAreYouDoing
########### StudentWorker::whatAreYouDoing() ##############
a1 is studying as a 2-year student in Computer
a1 works in Hyundai as Labor
a1 took several courses and got GPA 3.5
a1 is now enjoying his(her) vacation
###########################################################
0             // Logout
4             // Login
p1            // Person 객체로 로그인
              // 그냥 엔터 입력; 즉, 빈줄 입력해야 함
5             // WhatAreYouDoing
p1 is taking a rest.

---------------------------------------------------------------------------
주목: 위 실행결과는 모두 CurrentUser::whatAreYouDoing() 내의 
    rUser.whatAreYouDoing();에 의해 출력된 결과이다. 즉, Person의 참조변수인 rUser의
    Person::whatAreYouDoing()를 호출했을 뿐이데, rUser가 참조하는 실제 객체의 종류에 따라
    오버라이딩된 함수가 실행되기 때문에 출력되는 내용은 모두 다르다는 것이다. (다형성)
---------------------------------------------------------------------------
```

### 문제 3 설명
```
1) 최상위 클래스인 Person 클래스 선언부에서 input() 함수를 가상함수로 선언하라.
2) Student, Worker, StudentWorker 클래스 선언부에서 위 함수의 원형에 override를 추가하라.
3) Factory 클래스를 아래 코드로 대체하라. 기존 코드와의 차이점은 무엇인가?
   아래 newPerson()에서는 Person*인 변수 p 하나만 사용한다. 그리고 클래스별로 객체를 생성한 후
   각 클래스별 input()을 호출하지 않고 바로 리턴한다. 
   그런 후 inputPerson()에서 대표로 한번만 p->input(in)을 호출하는데
   이 역시 생성된 객체의 파생 클래스에서 override된 input()이 호출된다.
```
```c++
class Factory
{
public:
    // 동적으로 Person 객체를 할당 받은 후 키보드로부터 새로 추가하고자 하는 사람의
    // 인적정보를 읽어 들여 해당 객체에 저장한 후 그 객체의 포인터를 반환한다.
	
    static Person* inputPerson(istream& in) {
        Person* p;
        string delimiter;

        in >> delimiter;              // 입력장치에서 사람구분자를 입력 받음

        if (in.eof())                 // 파일(입력장치가 파일인 경우)의 끝일 경우
        	return nullptr;
        else if (delimiter == "P") p = new Person(); 
        else if (delimiter == "S") p = new Student();
        else if (delimiter == "W") p = new Worker();
        else if (delimiter == "A") p = new StudentWorker();
        else {
            cout << delimiter << ": WRONG delimiter" << endl;
            getline(in, delimiter); // 엉뚱한 구분자일 경우 행 전체를 읽어서 버림
            return nullptr;
        }
        //---------------------------------------------------------------------
        // 주목: 아래 p->input(in)은 Person의 포인터 변수 p를 이용해 
        //      Person::input(istream&)을 호출했을 뿐이데 p가 포인트하는 실제 객체의  
        //      종류에 따라 오버라이딩된 파생 클래스의 input()이 호출된다. (다형성)
        //---------------------------------------------------------------------
        p->input(in);  // 각 클래스별 멤버들을 모두 입력 받음

        if (UI::checkDataFormatError(in)) { // 정수입력할 곳에 일반 문자 입력한 경우
            delete p;         // 할당된 메모리 반납
            return nullptr;   // nullptr 반환은 에러가 발생했다는 의미임
        }
        if (UI::echo_input) {  // 자동체크에서 사용됨
            cout << delimiter << " ";
            p->println();
        }
        return p;
    }
};
```

### 문제 3 실행 결과
```
ch8-2의 [문제 8] 실행 결과와 동일하게 아래처럼 입력해 보라. 7개의 인적정보가 정상적으로 입력되어야 한다.
그리고 display()가 실행될 때 아래처럼 객체 종류마다 다르게, 그리고 모든 멤버가 출력되어야 한다.

******************************* Main Menu ...
Menu item number? 1
...
====================== Person Management Menu ...
Menu item number? 2
The number of persons to append? 7
Input 7 [delimiter(P, S, W, or A)] [person information] : 
// 아래 7개의 인적 정보를 한번에 복사해서 입력할 것
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
S s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
W w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
A a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
S s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan: Biology 3.8 3
W w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul: Naver Department-Head
A a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false
Person::Person(...): 0 0 false :: // new에 의해 각 객체가 생성될 때 기본 생성자에 의해 출력됨
...
StudentWorker::StudentWorker(...): :: false
// PersonManager::append() -> display()
display(): count 15
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
// 아래는 새로 입력된 객체들의 정보임
[8] p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[9] s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
[10] w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
[11] a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
[12] s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan: Biology 3.8 3
[13] w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul: Naver Department-Head
[14] a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false
```

### 문제 4 설명
```
1) 최상위 클래스인 Person 클래스 선언부에서 operator==() 함수를 가상함수로 선언하라.
---------------------------------------------------------------------------
2) Student, Worker, StudentWorker 클래스 선언부에서 위 함수의 원형에 override를 추가하라.
   그런데 override를 추가하려면 Student, Worker, StudentWorker 클래스의 == 연산자 함수의
   매개변수 타입이 Person::operator==(const Person& p)의 매개변수 타입과 동일해야 한다.
   따라서 기존 Student, Worker, StudentWorker 클래스의 == 연산자 함수의 매개변수 타입을 모두
   const Person& p로 통일하라. 그런 후 함수의 [원형]에 override를 추가하라.
   매개변수 수정으로 인한 변수 에러는 다음 단계에서 수정될 것이다.
---------------------------------------------------------------------------
3) Student::operator==(const Person& p) 구현 시 함수 [처음]에 아래 변수를 선언하라.
    const Student& s = dynamic_cast< const Student& >(p); // 다운 캐스팅
---------------------------------------------------------------------------
   위 변수 s는 if(s1 == s2)와 같이 == 함수 호출 시 함수 인자인 Student 객체 s2가 
   업캐스딩되어 자동으로 매개변수인 Person& p로 타입으로 변경된 것을 이 함수에서 원래 타입인 
   Student 타입으로 복구시키는 것이다.
---------------------------------------------------------------------------
   참고로 위 타입 변경 문장인 dynamic_cast< const Student& >(p)는
   const Student& s = (const Student&)p;와 같은 의미인데, 문제는
   Student 클래스가 Person을 virtual로 상속 받았고 또한 virtual 함수를 오버라이딩하고 있기
   때문에 바로 (const Student&)로 타입을 변경할 수 없다. 이 경우 dynamic_cast< >를 
   사용해야 하는데 이 때 p로 업캐스팅된 원래 객체가 Student 또는 StudentWorker 객체이어야 한다.
   만약에 p가 원래 Person의 객체였다면 위처럼 dynamic_cast< const Student& >(p)
   하면 프로그램 실행 도중 에러로 인해 중단하게 된다. 
   이러한 것을 실행 중 자동 체크해 주는 것이 dynamic_cast< >이다.
---------------------------------------------------------------------------
4) Student::operator==(const Person& p) 함수 내의 
    기존 *(Person*)this == s 를 아래처럼 수정하라.
        Person::operator==(p)
---------------------------------------------------------------------------
    기존 *(Person*)this == s 방식은 Person의 operator==(...)를 호출하는데 이 연산자가 
    이제는 가상 함수이므로 결국 파생클래스 Student의 오버라이딩된 operator==(...)를
    다시 호출하게 되어 무한반복 호출될 수 있기 때문이다.
    이를 방지하기 위해서는 오버라이딩된 함수가 아닌 Person의 operator==(...)를 직접 호출해야 
    해야 한다. 수정된 문장 Person::operator==(p)는 오버라이딩된 함수가 아닌 
    Person에서 구현된 연산자 함수를 직접 호출하는 방식이다. 
---------------------------------------------------------------------------
5) Worker::operator==(const Person& p) 도 위 3), 4) 방식으로 변경하라.
    단 Student을 Worker로 교체하라.
---------------------------------------------------------------------------
6) StudentWorker::operator==(const Person& p) 역시 위 3), 4) 방식으로 변경하라. 
    즉, 아래와 같이 구현하면 된다. 
---------------------------------------------------------------------------
    const StudentWorker& a = dynamic_cast< const StudentWorker& >(p);
    return Student::operator==(a) && Worker::operator==(a) && male == a.male;
```

### 문제 4 실행 결과
```
******************************* Main Menu ...
Menu item number? 6   // Inheritance

+++++++++++++ Inheritance Menu ...
Menu item number? 3   // StudentWorker
//
// 아래 == 연산자 실행 결과와 일치하는지 확인하기 바란다.
...
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
...
sw2: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
sw1 == sw2 : true
sw2: a2 6 61.05 false :Dong-gu Incheon: Computer-Electronics 4.5 3 Hyundai-Hyundai Labor-Manager :CU KangNam,Seven Eleven,GSStore Suwon, Hi-Mart: true
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
sw1 == sw2 : false
########### StudentWorker::whatAreYouDoing() ...
p3 : a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
p3 == sw1 : true
...
//
// 아래 input alba: 값으로 아래 내용을 복사해서 입력하라.
input alba: a1 5 66.6 false :Nam-gu Busan: Computer 2.0 2 Hyundai Labor :CU,Emart,GS: false
sw2: a1 5 66.6 false :Nam-gu Busan: Computer 2 2 Hyundai Labor :CU,Emart,GS: false
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
sw2 == sw1 : true
...
// Inheritance Menu의 3번 메뉴를 반복 수행하되 위 input alba: 값으로 아래 값들을 
// 입력했을 때도 sw1의 내용과 다르므로 == 값이 false가 나와야 함; 
// 3번 메뉴를 반복 수행하여 각각을 따로 따로 입력해 보라.
a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 3 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false // 학년 다름
a1 6 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false // id 다름
a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Kia     Labor :CU KangNam,Seven Eleven,GSStore Suwon: false // 회사명 다름
// input alba: 값으로 아래를 입력했을 때 sw1과 동일하므로 == 값이 true가 출력되어야 함
a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
```

### 문제 5 설명
```
1) 기존의 CurrentUser::isSame()의 코드를 아래 코드로 대체하라.
```
```c++
void CurrentUser::isSame() { // Menu item 6
    Person* p = rUser.clone(); // 현재 로그인한 객체를 동일하게 복사함
    cout << "rUser: "; rUser.println();
    cout << "p    : "; p->println();
    cout << "(rUser == p): " << (rUser == *p) << endl; // 같아야 함
    // 아래 입력 시 현재 로그인한 객체와 동일한 양식으로 인적정보를 입력해야 함
    UI::inputPerson(*p);
    // 즉, 현재 Student(or Worker)으로 로그인했다면 [구분자] 없이 학생(or 노동자)정보를 입력해야 함
    // 현 객체의 오버라이딩된 input(istream& in) 함수가 바로 호출되므로 구분자가 필요없다.
    cout << "rUser: "; rUser.println();
    cout << "p    : "; p->println();
    cout << "(rUser == p): " << (rUser == *p) << endl;
    delete p;
}
```
```
실행 시 아래 인적 정보 중 현재 로그인한 객체와 동일한 종류의 인적정보을 골라 입력 해 보라.
p0 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:  // 현 객체가 Person인 경우: 이름 다름
s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 2     // Student: 학년 다름
w1 3 33.3 false :Kangnam-gu Seoul: Kia Director    // Worker: 회사 다름
a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: true // male 다름
```

### 문제 5 실행 결과
```
******************************* Main Menu ...
Menu item number? 1

// 아래 항목을 순서적으로 입력하면 위 isSame()이 여러번 실행되는데 
// 매번 실행 시 복제된 객체의 비교(==)는 true, 인적 정보 입력 후의 비교는 false가 출력되어야 함  

4   // Login
p1
    // 이 줄은 빈 줄로 입력: 비번 없음: 즉, 그냥 엔터
Menu item number? 6
Person::Person(const Person&):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
rUser: p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
p    : p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
(rUser == p): true                                // 항상 true
input person information:
p0 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul: // 사용자 입력: 이름이 rUser와 다름
rUser: p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
p    : p0 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
(rUser == p): false                               // 항상 false 출력되어야 함
Person::~Person():p0 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
...
Menu item number? 0   // Logout
4   // Login
s1  // Student

6   // IsSame: Student
s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 2 // Student: 학년 다름
0   // Logout
4   // Login
w1  // Worker

6   // IsSame: Worker
w1 3 33.3 false :Kangnam-gu Seoul: Kia Director // Worker: 회사 다름
0   // Logout
4   // Login
a1  // StudentWorker

6   // IsSame: StudentWorker
a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: true // male 다름
0   // Logout
```