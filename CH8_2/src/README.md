# OJ CH8_2

### 이번 문제의 목적 : 다중 상속
```
Person을 상속 받은 두 클래스 Student, Worker 클래스 모두를 다중 상속 받는 
StudentWorker 클래스를 생성하고, 추가적으로 필요한 멤버 변수 및 멤버 함수를 새로 추가한다.
또한 부모 클래스의 멤버 함수들을 재정의하고자 한다.  
Student, Worker가 모두 Person을 상속 받기 때문에 StudentWorker 클래스에서는 Person
클래스를 중복하여 상속 받게 된다. 이러한 중복 상속 문제를 해결하기 위해 가상 상속을 받는다.
```

### 코드 추가 1
```
Student와 Worker를 다중 상속 받는 StudentWorker 클래스 코드를 Worker 클래스 뒤에 배치하라.
```
```c++
/******************************************************************************
 * ch8_2: StudentWorker class
 ******************************************************************************/
//                   Person
//                  /      \
//              Student  Worker
//                  \      /
//                 StudentWorker

class StudentWorker /* TODO: [문제 1]Student와 Worker 클래스들을 다중 상속 받아라. */ 
{
    string career;      // 알바경력
    bool   male;        // 남:true, 여:false

protected:
    void inputMembers(istream& in);
    void printMembers(ostream& out);

public:
    StudentWorker(
        const string& name={}, int id={}, double weight={},
        bool married={}, const char* address={},
        const string& department={}, double GPA={}, int year={},
        const string& company={}, const string& position={},
        const string& career={}, bool male={}
    );

    StudentWorker(const StudentWorker& a); // copy constructor
    ~StudentWorker();
    Person* clone();

    // Getter and Setter
    const string& getCareer()  const;
    bool          getMale()    const;

    void setCareer(const string& career);
    void setMale(bool male);

    // Redefined member functions
    void input(istream& in);
    void print(ostream& out);
    void println() { print(cout); cout << endl; }

    bool operator==(const StudentWorker& a);
    void whatAreYouDoing();
};

StudentWorker::StudentWorker(
    const string& name, int id, double weight,
    bool married, const char* address,
    const string& department, double GPA, int year,
    const string& company, const string& position,
    const string& career, bool male)
    /* TODO: 함수 서두에서 Person, Student, Worker 생성자 호출하기, 각 멤버 초기화 */ {
    cout << "StudentWorker::StudentWorker(...):";
    printMembers(cout); cout << endl;
}

StudentWorker::StudentWorker(const StudentWorker& a)
    /* TODO: 함수 서두에서 Person, Student, Worker의 [복사 생성자] 호출하기, 
             a의 각 멤버를 this의 멤버에 복사하여 초기화 */ { // 기존의 복사 생성자 참고할 것
    cout << "StudentWorker::StudentWorker(const StudentWorker& a):";
    printMembers(cout); cout << endl;
}

StudentWorker::~StudentWorker() {
    cout << "StudentWorker::~StudentWorker():"; printMembers(cout); cout << endl;
}

void StudentWorker::inputMembers(istream& in) {
    // Person::inputMembers()의 address 읽는 것 참고할 것 
    // 여기서는 char address[40]에 읽어 들이는 것이 아니라 string 객체인
    // career에 문자열을 읽어 들이기 위해 전역함수인 getline()을 사용함
    // 아래 문장은 경력의 앞쪽 ':'까지 모든 문자들을 읽어 들임(읽은 문자열은 그냥 버림)
    getline(cin, career, ':'); 
    /* TODO: 이번엔 경력의 뒤쪽 ':'까지 또 읽어서 career에 저장
             (':'는 입력 버퍼에서는 읽어 내지만 career에는 저장되지 않아 자동 제거됨)
             남여 성별 값을 읽어 male에 저장; */
}

void StudentWorker::printMembers(ostream& out)   {
    out << " :" << career << ": " << male;
}

void StudentWorker::whatAreYouDoing() {
    cout << "########### StudentWorker::whatAreYouDoing() ##############\n";
    /* TODO: 출력결과를 참고하여 Student와 Worker의 적절한 함수를 순서적으로 호출하라. */
    cout << "###########################################################\n";
}
```

### 코드 추가 2
```
1) class Inheritance에 아래 sw 멤버를 w 멤버 뒤에 추가하고,
   또한 studentWorker() 멤버 함수를 worker() 함수 뒤에 추가하라.
```
```c++
    StudentWorker sw { "a1", 5, 55.5, true, "Dong-gu Incheon",
                       "Computer", 3.5, 2, "Hyundai", "Labor",
                       "CU KangNam,Seven Eleven,GSStore Suwon", false };

    void studentWorker() {
    }
```
```
2) Inheritance::run()의 func_arr[]에 위 studentWorker() 함수의 주소를 등록하라.
3) Inheritance::run()의 메뉴 문자열 중 일부를 아래와 같이 변경하라.
```
```c++
            "+ 0.Exit 1.Student 2.Worker 3.StudentWorker +\n"
```
```
4) Inheritance::student()와 worker()에 있는 아래 문장을 
```
```c++
        Student *s3 = (Student *)s2.clone();  // 다운 캐스팅
        Worker *w3 = (Worker *)w2.clone();  // 다운 캐스팅
```
```
   각각 아래처럼 변경하라. 위 문장은 Student와 Worker에서 Person 클래스를 가상 상속을 하지 않는다면 
   정상 작동하지만, 가상상속을 할 경우 여러가지 문제로 인해 다운 캐스팅할 수 없다는 컴파일 에러가 발생한다.
   따라서 아래처럼 변경해야 정상 컴파일될 수 있다.
```
```c++
        Person *s3 = s2.clone();
        Person *w3 = w2.clone();
```
```
   s3와 w3가 Student *와 Worker *가 아니라 둘 다 Person *로 변경되었다. 위처럼 변경할 경우
   객체를 출력할 때 지금은 Person 정보만 출력되지만 9장에서 가상함수를 이용하여
   복제된 원래의 Student와 Worker 객체 정보가 정상 출력될 수 있도록 할 예정이다.
5) student()와 worker() 함수에 있는 아래 문장을 주석처리하라. s3와 w3가 Person에 
   대한 포인터이므로 메모리 반납시 프로그램이 비 정상적으로 종료될 수 있기 때문이다. 
   (지금은 s3와 w3를 메모리 반납하지 않지만 이 역시 9장에서 주석을 풀고 정상 해결할 예정임)
```
```c++
        //delete s3;
        //delete w3;
```

### 초기 프로그램 실행 결과
```
******************************* Main Menu ...
Menu item number? 6
// class Inheritance의 멤버 s, w, sw의 생성자 출력
Person::Person(...):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(...): Physics 3.8 1
Person::Person(...):w1 3 33.3 false :Kangnam-gu Seoul:
Worker::Worker(...): Samsung Director
// StudentWorker만 출력됨 (상속받지 않았기 때문에)
StudentWorker::StudentWorker(...): :: false   

+++++++++++++ Inheritance Menu ++++++++++++++
+ 0.Exit 1.Student 2.Worker 3.StudentWorker +
+++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0
// class Inheritance의 멤버 s, w, sw의 소멸자 출력
StudentWorker::~StudentWorker(): :: false
Worker::~Worker(): Samsung Director
Person::~Person():w1 3 33.3 false :Kangnam-gu Seoul:
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
```

### 문제 1 설명
```
1) StudentWorker 클래스 선언의 시작 부분에 있는 /* TODO: */를 적절히 수정하여
   Student와 Worker 클래스를 다중 상속 받도록 하라.
2) Student와 Worker 둘 다 Person을 상속 받기 때문에 StudentWorker는 Person을 중복하여 상속
   받게 되는 문제를 가지게 된다. Student와 Worker 클래스 선언할 때 
   Person을 [가상 상속]을 받도록 하여 중복 상속 문제를 해결하라. [교제 p.408 참고]
   가상상속 시 주의점: 가상상속을 받을 경우 위 [코드 추가 3] 4)처럼 포인터 변수를 다운 캐스팅할 경우 
                  컴파일 문제가 발생할 수 있는데 이 문제는 9장에서 해결된다.
3) Student와 Worker 클래스의 생성자를 참고하여 StudentWorker의 생성자를 완성하시오.
   생성자 서두에서 부모 클래스인 Person, Student, Worker의 생성자를 순서적으로 호출하고
   또한 서두에서 StudentWorker 멤버 변수들도 초기화하라.
```

### 문제 1 실행 결과
```
******************************* Main Menu ...
Menu item number? 6
// Inheritance의 멤버 Student s와 Worker w의 생성자에 의한 출력임
Person::Person(...):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(...): Physics 3.8 1
Person::Person(...):w1 3 33.3 false :Kangnam-gu Seoul:
Worker::Worker(...): Samsung Director
// 여기서부터 Inheritance의 멤버 StudentWorker sw의 생성자에 의한 출력임
Person::Person(...):a1 5 55.5 true :Dong-gu Incheon: 
Student::Student(...): Computer 3.5 2
Worker::Worker(...): Hyundai Labor
StudentWorker::StudentWorker(...): :CU KangNam,Seven Eleven,GSStore Suwon: false

+++++++++++++ Inheritance Menu ...
Menu item number? 0
StudentWorker::~StudentWorker(): :CU KangNam,Seven Eleven,GSStore Suwon: false
Worker::~Worker(): Hyundai Labor
Student::~Student(): Computer 3.5 2
Person::~Person():a1 5 55.5 true :Dong-gu Incheon: 
// 여기까지가 Inheritance의 멤버 StudentWorker sw 소멸자에 의한 출력임
// 아래는 멤버 Worker w와 Student s의 소멸자에 의한 출력임
Worker::~Worker(): Samsung Director
Person::~Person():w1 3 33.3 false :Kangnam-gu Seoul:
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
```

### 문제 2 설명
```
Inheritance::studentWorker()에 아래 코드를 삽입하라.
```
```c++
        StudentWorker sw1(sw); // 복사생성자
        cout << "sw1: " ; sw1.println();
        StudentWorker sw2 = sw1; // 묵시적으로 복사생성자 호출
        cout << "sw2: "; sw2.println();
```
```
1) 위 코드가 정상적으로 실행될 수 있도록 StudentWorker의 복사 생성자를 완성하라.
   구현 시 StudentWorker의 생성자처럼 [함수 서두]에서 조부모, 부모 클래스의 [복사 생성자]를 
   먼저 호출하고 각 멤버를 매개변수 a의 상응하는 멤버로 초기화시키면 된다. 
2) StudentWorker::print() 함수도 구현하라. 
   구현 시 먼저 상위 클래스인 Person, Student, Worker의 ::printMembers()를 호출하여
   상위 클래스의 모든 멤버들을 출력한 후 StudentWorker의 모든 멤버들을 출력하면 된다.
```

### 문제 2 실행 결과
```
// Main Menu item 6 실행 후

+++++++++++++ Inheritance Menu ++++++++++++++
+ 0.Exit 1.Student 2.Worker 3.StudentWorker +
+++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 3
Person::Person(const Person&):a1 5 55.5 true :Dong-gu Incheon:
Student::Student(const Student& s): Computer 3.5 2
Worker::Worker(const Worker& w): Hyundai Labor
StudentWorker::StudentWorker(const StudentWorker& a): :CU KangNam,Seven Eleven,GSStore Suwon: false
// 이상은 StudentWorker sw1(sw)에 의한 복사생성자 실행 결과
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
// 이상은 sw1.println() 실행 결과
Person::Person(const Person&):a1 5 55.5 true :Dong-gu Incheon:
Student::Student(const Student& s): Computer 3.5 2
Worker::Worker(const Worker& w): Hyundai Labor
StudentWorker::StudentWorker(const StudentWorker& a): :CU KangNam,Seven Eleven,GSStore Suwon: false
// 이상은 StudentWorker sw2 = sw1에 의한 복사생성자 실행 결과
sw2: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
// 이상은 sw2.println() 실행 결과
StudentWorker::~StudentWorker(): :CU KangNam,Seven Eleven,GSStore Suwon: false
Worker::~Worker(): Hyundai Labor
Student::~Student(): Computer 3.5 2
Person::~Person():a1 5 55.5 true :Dong-gu Incheon:
// 이상은 sw2 소멸자 실행 결과
StudentWorker::~StudentWorker(): :CU KangNam,Seven Eleven,GSStore Suwon: false
Worker::~Worker(): Hyundai Labor
Student::~Student(): Computer 3.5 2
Person::~Person():a1 5 55.5 true :Dong-gu Incheon:
// 이상은 sw1 소멸자 실행 결과
```

### 문제 3 설명
```
Inheritance::studentWorker() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        cout << "sw1 == sw2 : " << (sw1 == sw2) << endl;
```
```
위 코드가 정상적으로 실행될 수 있도록 StudentWorker 클래스의 == 연산자를 구현하라. 이 연산자
구현 시 (현 객체의 부모 클래스인 Student 객체와 매개변수 a의 부모 Student 클래스 객체가 같고 
       현 객체의 부모 클래스인 Worker  객체와 매개변수 a의 부모 Worker  클래스 객체가 같고 
       현 객체의 성별과 a 객체의 성별이 같으면) true를 반환하면 된다.
      예를 들어, 부모 클래스 Student 객체를 서로 비교할 때는 *(Student*)this == a 로 
      하면 된다. 이 경우 *(Student*)this에 의해 Student의 연산자 ==가 호출된다.
      또 다른 부모 클래스인 Worker의 경우에도 이처럼 비교하라.
```

### 문제 3 실행 결과
```
// Main Menu item 6: Inheritance Menu item: 3 실행
...
sw1 == sw2 : true
...
```

### 문제 4 설명
```
1) Inheritance::studentWorker() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        // Person 조부모 클래스의 멤버 함수 호출
        sw2.set("a2", sw1.getId()+1, sw1.getWeight()*1.1, !sw1.getMarried(), sw1.getAddress());
        // Student 부모 클래스의 멤버 함수 호출
        sw2.setDepartment(sw1.getDepartment()+"-Electronics");
        sw2.setGPA(sw1.getGPA()+1);
        sw2.setYear(sw1.getYear()+1);
        // Worker 부모 클래스의 멤버 함수 호출
        sw2.setCompany(sw1.getCompany()+"-Hyundai");
        sw2.setPosition(sw1.getPosition()+"-Manager");
        // sw2 객체의 멤버 값 얻어오기 및 수정하기
        sw2.setCareer(sw1.getCareer()+", Hi-Mart");
        sw2.setMale(!sw1.getMale());
        cout << "sw2: "; sw2.println();;
        cout << "sw1: "; sw1.println();
        cout << "sw1 == sw2 : " << (sw1 == sw2) << endl;
```
```
2) 위 코드가 정상적으로 실행될 수 있도록 Student 클래스의 새로운 멤버함수들인
   setCareer(), setMale()와 getCareer(), getMale() 등을 구현하라.
```

### 문제 4 실행 결과
```
// Main Menu item 6: Inheritance Menu item: 3 실행
...
sw2: a2 6 61.05 false :Dong-gu Incheon: Computer-Electronics 4.5 3 Hyundai-Hyundai Labor-Manager :CU KangNam,Seven Eleven,GSStore Suwon, Hi-Mart: true
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
sw1 == sw2 : false
...
```

### 문제 5 설명
```
1) Inheritance::studentWorker() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        sw2.whatAreYouDoing();
```
```
2) 위 코드가 정상적으로 실행될 수 있도록 아래 실행 결과를 참고하여 
   부모 클래스인 Student와 Worker의 적절한 멤버 함수들을 순서적으로 호출하라.
```

### 문제 5 실행 결과
```
// Main Menu item 6: Inheritance Menu item: 3 실행
...
########### StudentWorker::whatAreYouDoing() ##############
a2 is studying as a 3-year student in Computer-Electronics
a2 works in Hyundai-Hyundai as Labor-Manager
a2 took several courses and got GPA 4.5
a2 is now enjoying his(her) vacation
###########################################################
...
```

### 문제 6 설명
```
Inheritance::studentWorker() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        Person* p3 = sw1.clone();
        cout << "p3 : "; p3->println();
        cout << "sw1: "; sw1.println();
        cout << "p3 == sw1 : " << (*p3 == sw1) << endl; // Person 정보만 비교함
        // 위의 경우 p3가 Person* 이므로 Person 클래스의 ==연산자가 호출된다.
        //delete p3; 
        // 위 문장의 주석은 p3가 Person에 대한 포인터이므로 메모리 반납시 프로그램이 비 정상적으로 
        // 종료될 수 있어서 주석 처리한 것임; 9장에서 해결
```
```
2) 위 코드가 정상적으로 실행될 수 있도록 아래 실행 결과와 Student::clone()을 참고하여 
   Person* StudentWorker::clone()을 구현하라. 
   ------------------------------------------------------------------------
   이 함수는 새로운 객체를 동적으로 생성하되 복사생성자를 활용하여 자기(*this) 자신을 복제한다.
   복제된 것은 StudentWorker 객체일지라도 Person*를 반환해야 한다.
   StudentWorker*를 반환해도 컴파일러가 자동으로 Person*로 [업캐스팅]해서 반환한다.
```

### 문제 6 실행 결과
```
// Main Menu item 6: Inheritance Menu item: 3 실행
...
Person::Person(const Person&):a1 5 55.5 true :Dong-gu Incheon:
Student::Student(const Student& s): Computer 3.5 2
Worker::Worker(const Worker& w): Hyundai Labor
StudentWorker::StudentWorker(const StudentWorker& a): :CU KangNam,Seven Eleven,GSStore Suwon: false
// 이상는 Person* p3 = sw1.clone() 실행 시 복사생성자 실행 결과임
p3 : a1 5 55.5 true :Dong-gu Incheon:
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
p3 == sw1 : true // p3가 Person* 이므로 Person의 ==연산자가 호출되어 Person의 멤버들만 비교한 것임
Person::~Person():a1 5 55.5 true :Dong-gu Incheon: // Person의 소멸자만 실행되었음
                                                   // 9장에서는 모두 정상 수행될 것임
...
```

### 문제 7 설명
```
1) Inheritance::studentWorker() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        cout << "input alba: ";
        sw2.input(cin);
// a1 5 66.6 false :Nam-gu Busan: Computer 2.0 2 Hyundai Labor :CU,Emart,GS: true
        if (UI::echo_input) sw2.println(); // 자동체크에서 사용됨
        cout << "sw2: "; sw2.println();
        cout << "sw1: "; sw1.println();
        cout << "sw2 == sw1 : " << (sw2 == sw1) << endl; // Person의 == 연산자 호출
```
```
2) 위 코드가 정상적으로 실행될 수 있도록 StudentWorker::input(istream& in) 함수를 구현하라.
   이 함수 구현 시 (StudentWorker::print() 구현을 참고할 것)
     먼저 상위 클래스인 Person, Student, Worker의 ::inputMembers()를 호출하여 상위  
     클래스의 모든 멤버들을 입력 받는다. 이때 각 클래스의 inputMembers() 함수가 리턴할 때마다
     if (!in) return; 를 호출하여 에러가 발생한 경우 바로 리턴할 수 있도록 해야 한다. 
     마지막으로 StudentWorker의 inputMembers()를 호출하여 
     StudentWorker에서 추가된 멤버들을 입력 받는다.
---------------------------------------------------------------------------
3) 또한 아래 실행 결과를 참고하고 또한 StudentWorker::inputMembers(istream& in)에  
   기술된 설명을 참고하여 이 함수를 완성하라. 이 함수 구현 시, 
     입력 스트림 in에서 ":경력리스트: true" 순서로 멤버들을 입력 받으면 된다.
     즉, ":CU KangNam,Seven Eleven,GSStore Suwon: false" 처럼 입력되는 값을 읽는다.
     경력과 경력은 ','로 구분하고 각 경력은 여러 단어("CU KangNam")로 구성될 수 있다. 
     : ... : 사이의 경력 리스트 "CU KangNam,Seven Eleven,GSStore Suwon"  
     문자열을 멤버 career에 저장하고, false를 male에 저장해야 함
```

### 문제 7 실행 결과
```
// Main Menu item 6: Inheritance Menu item: 3 실행

... // 아래 인적 정보를 복사해서 입력하면 편할 것이다.
input alba: a1 5 66.6 false :Nam-gu Busan: Computer 2.0 2 Hyundai Labor :CU,Emart,GS: false
sw2: a1 5 66.6 false :Nam-gu Busan: Computer 2 2 Hyundai Labor :CU,Emart,GS: false
sw1: a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
sw2 == sw1 : true   // sw1과 sw2의 모든 멤버가 같은 것은 아님; 
                    // 이름,id,학과,학년,부서,직급,남녀들 중 하나라도 다르면 false가 나와야 함
...
```

### 코드 추가 및 변경 3
```
1) 아래 코드를 MultiManager 클래스의 Person persons[personCount] 뒤쪽에 삽입하라.
```
```c++
// 1) 아래 코드를 MultiManager 클래스의 Person persons[personCount] 뒤쪽에 삽입하라.
//----------------------------------------------------------------------------
    static const int studentCount = 2;
    Student students[studentCount] = {
        Student("s1", 1, 65.4, true,  "Jongno-gu Seoul", "Physics", 3.8, 1),
        Student("s2", 2, 54.3, false, "Yeonje-gu Busan", "Electronics", 2.5, 4),
    };

    static const int workerCount = 2;
    Worker workers[workerCount] = {
        Worker("w1", 3, 33.3, false, "Kangnam-gu Seoul",  "Samsung", "Director"),
        Worker("w2", 4, 44.4, true,  "Dobong-gu Kwangju", "Hyundai", "Manager"),
    };

    static const int albaCount = 2;
    StudentWorker albas[albaCount] = {
        StudentWorker("a1", 5, 55.5, true, "Dong-gu Incheon",
                      "Computer", 3.5, 2, "Hyundai", "Labor",
                      "CU KangNam,Seven Eleven,GSStore Suwon", false),
        StudentWorker("a2", 6, 66.6, false, "Sasang-gu Sejong",
                      "History", 3.1, 1, "Kia", "CEO",
                      "Seven Eveven,eMart Jinju,CU Bongsun", true),
    };
```
```
2) MultiManager 클래스의 기존 allPersons[allPersonCount] 배열 원소를 아래 원소들로 교체하라.
```
```c++
    static const int allPersonCount = 8;
    Person* allPersons[allPersonCount] = {
            &persons[0], &persons[1], &students[0], &students[1],
            &workers[0], &workers[1], &albas[0],    &albas[1],
    };
```
```
3) PersonManager(Person* array[], int len) 생성자에서 // display();를 주석처리하라.
```

### 문제점
```
MainMenu에서 PersonManager에 들어가 보자.
```
```
******************************* Main Menu ...
Menu item number? 1
Person::Person(...):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(...):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(...):p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
Person::Person(...):p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
Person::Person(...):p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
// 이상은 MultiManager::persons[]의 각 원소의 생성자 실행
Person::Person(...):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(...): Physics 3.8 1
Person::Person(...):s2 2 54.3 false :Yeonje-gu Busan:
Student::Student(...): Electronics 2.5 4
// 이상은 MultiManager::students[] 의 각 원소의 생성자 실행
Person::Person(...):w1 3 33.3 false :Kangnam-gu Seoul:
Worker::Worker(...): Samsung Director
Person::Person(...):w2 4 44.4 true :Dobong-gu Kwangju:
Worker::Worker(...): Hyundai Manager
// 이상은 MultiManager::workers[] 의 각 원소의 생성자 실행
Person::Person(...):a1 5 55.5 true :Dong-gu Incheon:
Student::Student(...): Computer 3.5 2
Worker::Worker(...): Hyundai Labor
StudentWorker::StudentWorker(...): :CU KangNam,Seven Eleven,GSStore Suwon: false
Person::Person(...):a2 6 66.6 false :Sasang-gu Sejong:
Student::Student(...): History 3.1 1
Worker::Worker(...): Kia CEO
StudentWorker::StudentWorker(...): :Seven Eveven,eMart Jinju,CU Bongsun: true
// 이상은 MultiManager::albas[] 의 각 원소의 생성자 실행
```
```
아래는 PersonManager::PersonManager(생성자)의 
pushArray() 내의 array[i]->clone()에 의해 객체생성시 복사생성자의 실행결과이다.
```
```
Person::Person(const Person&):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(const Person&):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(const Person&):s1 1 65.4 true :Jongno-gu Seoul:
Person::Person(const Person&):s2 2 54.3 false :Yeonje-gu Busan:
Person::Person(const Person&):w1 3 33.3 false :Kangnam-gu Seoul:
Person::Person(const Person&):w2 4 44.4 true :Dobong-gu Kwangju:
Person::Person(const Person&):a1 5 55.5 true :Dong-gu Incheon:
Person::Person(const Person&):a2 6 66.6 false :Sasang-gu Sejong:
PersonManager::run() starts
```
```
문제점: array[i]가 Person* 이므로 Person 클래스의 clone()이 실행되어 Student, Worker, 
  StudentWorker 객체의 전체가 복제되는 것이 아니라, 각 객체의 상위 클래스인 Person 객체만
  복제되어 생성된다는 것이다. 
해결: 이러한 문제는 9장에서 가상함수를 통해 해결될 것이다.
---------------------------------------------------------------------------
PersonManger의 1.Display 메뉴를 실행시켜도 아래처럼 Person 객체의 정보만 출력된다.
---------------------------------------------------------------------------
```
```
====================== Person Management Menu ...
Menu item number? 1
display(): count 8
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] s1 1 65.4 true :Jongno-gu Seoul:
[3] s2 2 54.3 false :Yeonje-gu Busan:
[4] w1 3 33.3 false :Kangnam-gu Seoul:
[5] w2 4 44.4 true :Dobong-gu Kwangju:
[6] a1 5 55.5 true :Dong-gu Incheon:
[7] a2 6 66.6 false :Sasang-gu Sejong:
```
```
이 역시 PersonManager::display() 내의 persons[i]->println()에 의해 출력되었는데
persons[i]가 Person* 이므로 Person 클래스의 println()이 실행되어 Person 객체의 정보만 
출력되었다. 이 문제 역시 9장에서 가상함수를 통해 해결될 것이다.
참고로 persons[i]는 VectorPerson::pVector[i]와 동일한다.
```

### 문제 8 설명
```
지금까지는 PersonManager 메뉴의 2.Append 메뉴를 통해 Person 객체만 입력할 수 있었다.
이제 2.Append 메뉴에서 Person, Student, Worker, StudentWorker 객체 모두의 인적정보를
입력 받을 수 있게 수정해 보자.
```
```
1) 기존 PersonManager::printNotice(...)의 cout << " [person information] "을
   아래 문장으로 대체하라. 추가할 사람 구분자를 먼저 입력하고 인적정보를 입력하라는 메시지이다.
```
```c++
    cout << " [delimiter(P, S, W, or A)] [person information] ";
```
```
PersonManager::append() 함수를 보면 factory.inputPerson(cin)을 호출하여 새로운
객체를 생성하고 인적정보를 입력 받는다. 
아래의 기존 Factory::inputPerson(istream& in)은 
        Person* p = new Person();
        p->input(in);
를 통해 직접 new Person()을 호출하여 무조건 Person 객체를 생성하였고, 
또한 Person의 인적정보만 입력 받을 수 있었다.
---------------------------------------------------------------------------
그런데 이제는 사용자가 다양한 클래스의 인적정보를 입력할 수 있으므로 인적정보를 입력하기 전에 
먼저 어떤 사람의 정보를 입력할지 [구분자]를 먼저 입력해 주어야 한다. 
즉, Person, Student, Worker, StudentWorker를 구분하는 [구분자]로 각각 P, S, W, A를 
먼저 입력한 후 그 다음에 해당 클래스의 인적정보를 입력해야 한다. 
예를 들어, 아래와 같이 입력해야 한다.
---------------------------------------------------------------------------
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
S s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
W w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
A a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
---------------------------------------------------------------------------
2) Factory 클래스를 아래와 같이 수정하라.
   아래 inputPerson()은 무조건 Person 객체를 생성하지 않고 클래스 구분자에 따라 
   각각의 클래스의 새로운 객체를 동적으로 생성하고 생성된 객체의 input(in) 함수을 호출한다. 
   즉, 클래스별 전용 입력 함수 input(in)를 호출하여 해당 클래스의 멤버 정보를 입력 받는다.
---------------------------------------------------------------------------
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
        else if (delimiter == "P") {
            p = new Person();  p->input(in);
        }
        else if (delimiter == "S") {
            Student* s = new Student();
            s->input(in);
            p = s;
        }
        else if (delimiter == "W") {
            Worker* w = new Worker();
            w->input(in);
            p = w;
        }
        else if (delimiter == "A") {
            StudentWorker* sw = new StudentWorker();
            sw->input(in);
            p = sw;
        }
        else {
            cout << delimiter << ": WRONG delimiter" << endl;
            getline(in, delimiter); // 엉뚱한 구분자일 경우 행 전체를 읽어서 버림
            return nullptr;
        }

        // p->input(in);  // 멤버들을 입력 받음: 9장에서 이 주석을 다시 해제할 예정이다.

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

### 문제 8 실행 결과
```
...
====================== Person Management Menu ...
Menu item number? 2
The number of persons to append? 7
Input 7 [delimiter(P, S, W, or A)] [person information] : 
//----------------------------------------------------------------------------
// 위 출력문이 새로 변경되었음; "[delimiter(P, S, W, or A)] "가 추가 되었음
// 아래 7개의 인적 정보를 한번에 복사해서 입력할 것
// 입력시 항상 사람 구분자를 먼저 입력하고 그에 상응하는 인적정보를 입력해야 한다.
//----------------------------------------------------------------------------
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
S s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
W w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
A a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
S s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan: Biology 3.8 3
W w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul: Naver Department-Head
A a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false
// 아래는 Factory::newPerson(istream& in)의 new 에 의해 각 객체가 생성될 때 생성자에 의해 출력됨
Person::Person(...): 0 0 false :: 
...
StudentWorker::StudentWorker(...): :: false
// 아래는 PersonManager::append() 내의 마지막 문장 display()
display(): count 15
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[7] a2 6 66.6 false :Sasang-gu Sejong:
[8] p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[9] s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
[10] w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[11] a3 14 54 false :Dong-gu, Incheon:
[12] s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
[13] w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul:
[14] a4 17 88 true :Kangdong-gu, Daejeon:
// 위의 [8] ~ [14]까지 새로 입력된 7개의 객체는 정상적으로 생성되고 입력된 것이며, 다만 출력시 
// Person 클래스의 인적사항만 출력된 것임; 이유는 display()의 persons[i]가 Person*이므로.
// 이 역시 9장에서 정상 출력될 것임
...
```

### 문제 9 설명
```
PersonManager::persons[i]는 VectorPerson::pVector[i]와 동일하다.
persons[i]는 Person* 변수이인데 
이는 실제 서로 다른 파생 클래스(Student, Worker, StudentWorker)의 객체들을
최상위 클래스인 Person의 포인터로 객체들의 주소를 관리하고 있다. 
---------------------------------------------------------------------------
그런데 Person Management Menu를 종료하면 MultiManager내의 
PersonManager personMng 객체가 소멸되면서 순서적으로 PersonManager::~PersonManager()
-> PersonManager::deleteElemets() -> delete persons[i];가 호출된다.
---------------------------------------------------------------------------
문제는 persons[i]가 포인터하는 객체들은 실제로 Student, Worker 등의 객체들이라 소멸시 
각 객체별로 ~Student(), ~Worker()가 호출되어야 하는데 persons[i]가 Person*이므로 
컴파러는 모든 객체를 ~Person()을 호출하여 소멸하므로 문제가 발생한다.
---------------------------------------------------------------------------
따라서 당분간 PersonManager::deleteElemets()내의 delete persons[i];를 
for 문 내에서 아래처럼 주석 처리하라. 이 역시 9장에서 주석을 해제할 예정임.
---------------------------------------------------------------------------
   /* delete persons[i] */  ;
```

### 문제 9 실행 결과
```
******************************* Main Menu ...
Menu item number? 1
...
====================== Person Management Menu ...
Menu item number? 0
PersonManager::run() returned
//----------------------------------------------------------------------------
// 원래는 여기에 delete persons[i]에 의한 소멸자 출력이 있어야 하지만 
// 지금은 주석처리되어 출력되지 않았음
//----------------------------------------------------------------------------
// 아래는 MultiManager 클래스 내의 persons[], students[], workers[], albas[] 
// 배열의 각 원소의 소멸자가 [역순]으로 실행된 것임.
//----------------------------------------------------------------------------
StudentWorker::~StudentWorker(): :Seven Eveven,eMart Jinju,CU Bongsun: true
Worker::~Worker(): Kia CEO
Student::~Student(): History 3.1 1
Person::~Person():a2 6 66.6 false :Sasang-gu Sejong:
StudentWorker::~StudentWorker(): :CU KangNam,Seven Eleven,GSStore Suwon: false
Worker::~Worker(): Hyundai Labor
Student::~Student(): Computer 3.5 2
Person::~Person():a1 5 55.5 true :Dong-gu Incheon:
Worker::~Worker(): Hyundai Manager
Person::~Person():w2 4 44.4 true :Dobong-gu Kwangju:
Worker::~Worker(): Samsung Director
Person::~Person():w1 3 33.3 false :Kangnam-gu Seoul:
Student::~Student(): Electronics 2.5 4
Person::~Person():s2 2 54.3 false :Yeonje-gu Busan:
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
Person::~Person():p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
Person::~Person():p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
Person::~Person():p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
Person::~Person():p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::~Person():p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
```