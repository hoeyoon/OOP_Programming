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