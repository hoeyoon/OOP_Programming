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