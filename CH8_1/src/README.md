# OJ CH8_1

### 코드 추가 1
```
Person을 상속 받는 아래 두 클래스 Student와 Worker 클래스를 Person 클래스 뒤에 배치하라.
```
```c++
/******************************************************************************
 * ch8_1: Student class
 ******************************************************************************/

class Student /* TODO: Person 클래스 상속 받기 */ {
    string department; // 학과
    double GPA;        // 평균평점
    int    year;       // 학년

protected:
    void inputMembers(istream& in);
    void printMembers(ostream& out);

public:
    Student(const string& name={}, int id={}, double weight={},
            bool married={}, const char* address={},
            const string& department={}, double GPA={}, int year={});
    Student(const Student& s); // copy constructor
    ~Student();
    Person* clone();  // 자동 업캐스팅

    // Getter and Setter
    int           getYear()       const;
    double        getGPA()        const;
    const string& getDepartment() const;

    void setDepartment(const string& department);
    void setYear(int year);
    void setGPA(double GPA);

    // 부모(기본) 클래스의 멤버 함수 재정의: Redefined member functions
    void input(istream& in);
    void print(ostream& out);
    void println() { print(cout); cout << endl; }

    bool operator==(const Student& s);
    void whatAreYouDoing();

    // 새로 추가된 멤버 함수: Member functions added in Student
    void study();
    void takeClass();
};

Student::Student(const string& name, int id, double weight,
        bool married, const char* address,
        const string& department, double GPA, int year):
    Person(name, id, weight, married, address),          // 부모 클래스 생성자 호출
    department(department), GPA{GPA}, year{year} {       // 멤버 초기화
    cout << "Student::Student(...):"; printMembers(cout); cout << endl;
}

Student::Student(const Student& s) {
    cout << "Student::Student(const Student& s):"; printMembers(cout); cout << endl;
}

Student::~Student() {
    cout << "Student::~Student():"; printMembers(cout); cout << endl;
}

void Student::printMembers(ostream& out)   {             // 멤버 출력
    out << " " << department << " " << GPA << " " << year;
}

void Student::whatAreYouDoing() {
    cout << "~~~~~~~~~~~~~~~~ Student::whatAreYouDoing() ~~~~~~~~~~~~~~~~\n";
    study();
    takeClass();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Student::study() { }
void Student::takeClass() { }

/******************************************************************************
 * ch8_1: Worker class
 ******************************************************************************/

class Worker /* TODO: Person 클래스 상속 받기 */ {
    string company;    // 회사명
    string position;   // 직급

protected:
    void inputMembers(istream& in);
    void printMembers(ostream& out);

public:
    Worker(const string& name={}, int id={}, double weight={},
            bool married={}, const char* address={},
            const string& company={}, const string& position={});
    Worker(const Worker& w); // copy constructor
    ~Worker();
    Person* clone();

    // Getter and Setter
    const string& getCompany()  const;
    const string& getPosition() const;

    void setCompany(const string& company);
    void setPosition(const string& position);

    // 부모(기본) 클래스의 멤버 함수 재정의: Redefined member functions
    void input(istream& in);
    void print(ostream& out);
    void println() { print(cout); cout << endl; }

    bool operator==(const Worker& w);
    void whatAreYouDoing();

    // 새로 추가된 멤버 함수: Member functions added in Worker
    void work();
    void goOnVacation();
};

Worker::Worker(const string& name, int id, double weight,
        bool married, const char* address,
        const string& company, const string& position) {
    cout << "Worker::Worker(...):"; printMembers(cout); cout << endl;
}

Worker::~Worker() {
    cout << "Worker::~Worker():"; printMembers(cout); cout << endl;
}

void Worker::printMembers(ostream& out)   {
    out << " " << company << " " << position;
}

void Worker::whatAreYouDoing() {
    cout << "!!!!!!!!!!!!!!!! Worker::whatAreYouDoing()!!!!!!!!!!!!!!!!!\n";
    work();
    goOnVacation();
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
}

void Worker::work() { }
void Worker::goOnVacation() { }
```

### 코드 추가 2
```
아래 class Inheritance를 class MainMenu 앞쪽에 배치하라.  
이 클래스는 Student와 Worker 클래스를 테스트한다.
```
```c++
/******************************************************************************
 * ch8_1, ch8_2: Inheritance class
 ******************************************************************************/
class Inheritance
{
    Student s { "s1", 1, 65.4, true,  "Jongno-gu Seoul", "Physics", 3.8, 1 };
    Worker  w { "w1", 3, 33.3, false, "Kangnam-gu Seoul",  "Samsung", "Director" };

    void student() {
    }

    void worker() {
    }

public:
    void run() {
        using func_t = void (Inheritance::*)();
        func_t func_arr[] = {
            nullptr, &Inheritance::student, &Inheritance::worker,
        };
        int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 길이
        string menuStr =
            "+++++++++++++ Inheritance Menu ++++++++++++++\n"
            "+ 0.Exit 1.Student 2.Worker                 +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount);
            if (menuItem == 0) return;
            (this->*func_arr[menuItem])();
        }
    }

};
// ch8_1, ch8_2: Inheritance class
```

### 코드 추가 3
```
MainMenu::run()의 메뉴 문자열의 일부를 아래처럼 수정하라.
그리고 switch 문장에 Inheritance().run();을 추가하라.
```
```c++
"* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8)                             *\n"
...
"* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8)                            *\n"
```

### 코드 추가 4
```
1) VectorPerson::operator=() 와 VectorPerson::extend_capacity() 내의 출력문을 주석 처리하라.  
2) Person의 생성자, 복사생성자, 소멸자 내의 주석 처리된 출력문의 주석을 풀어 다시 출력되게 하라.
```
### Warming up 문제
```
Student와 Worker 클래스 선언의 시작 부분에 있는 /* TODO: */를 적절히 수정하여
두 클래스 모두 Person 클래스를 상속하도록 하라. 
```

### 초기 프로그램 실행 결과
```
******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8)                             *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8)                            *
***************************************************************************
Menu item number? 6
// Inheritance의 멤버 Student s와 Worker w의 생성자에 의한 출력임
Person::Person(...):s1 1 65.4 true :Jongno-gu Seoul: // Student의 부모 클래스 생성자
Student::Student(...): Physics 3.8 1     // Inheritance내의 Student s 멤버의 생성자
Person::Person(...): 0 0 false ::        // Worker의 부모 클래스 생성자
Worker::Worker(...):                     // Inheritance내의 Worker w 멤버의 생성자

+++++++++++++ Inheritance Menu ++++++++++++++
+ 0.Exit 1.Student 2.Worker                 +
+++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0
// Inheritance의 멤버 Worker w와 Student s의 소멸자에 의한 출력임
Worker::~Worker():                                 // Worker w 멤버의 소멸자
Person::~Person(): 0 0 false ::                    // Worker의 부모 클래스 소멸자
Student::~Student(): Physics 3.8 1                 // Student s 멤버의 소멸자
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul: // Student의 부모 클래스 소멸자
```

### 문제 1 설명
```
Student 클래스의 생성자를 참고하여 Worker의 생성자를 완성하시오.
```

### 문제 1 실행 결과
```
******************************* Main Menu ...
Menu item number? 6
Person::Person(...):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(...): Physics 3.8 1
Person::Person(...):w1 3 33.3 false :Kangnam-gu Seoul:
Worker::Worker(...): Samsung Director

+++++++++++++ Inheritance Menu ...
Menu item number? 0
Worker::~Worker(): Samsung Director
Person::~Person():w1 3 33.3 false :Kangnam-gu Seoul:
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
```

### 문제 2 설명
```
Inheritance::student()에 아래 코드를 삽입하라.
```
```c++
        Student s1(s); // 복사생성자 호출
        cout << "s1: "; s1.println();
        Student s2 = s1; // 묵시적 복사생성자 호출
        cout << "s2: "; s2.println();
```
```
1) 위 코드가 정상적으로 실행될 수 있도록 Student의 복사 생성자를 완성하라.
   구현 시 Student의 생성자처럼 함수 서두에서 부모 클래스의 [복사 생성자]를 먼저 호출한 후
   Student 멤버들을 매개변수 s의 상응하는 멤버들의 값으로 초기화시키면 된다. 
2) Student::print() 함수도 구현하라. 
   구현 시 먼저 부모 클래스의 Person::printMembers()를 호출하여 
   부모 클래스의 모든 멤버들을 먼저 출력한 후 Student의 printMembers()를 호출하여 
   Student의 멤버들만 출력하면 된다.
```

### 문제 2 실행 결과
```
=============================================================================== 
+++++++++++++ Inheritance Menu ...
Menu item number? 1
// s1(s): Student s1의 부모 클래스 Person의 복사생성자
Person::Person(const Person&):s1 1 65.4 true :Jongno-gu Seoul: 
Student::Student(const Student& s): Physics 3.8 1   // Student s1의 복사생성자
s1: s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
// s2 = s: Student s2의 부모 클래스 Person의 복사생성자
Person::Person(const Person&):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(const Student& s): Physics 3.8 1
s2: s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
Student::~Student(): Physics 3.8 1  // s2 소멸자
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
Student::~Student(): Physics 3.8 1  // s1 소멸자
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
```

### 문제 3 설명
```
Inheritance::student() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        cout << "s1 == s2 : " << (s1 == s2) << endl;
```
```
위 코드가 정상적으로 실행될 수 있도록 Student 클래스의 == 연산자를 구현하라.
구현 시 현 객체의 부모(Person)와 매개변수 s의 부모가 같고, 즉 *(Person*)this == s이고,
      현 객체의 학년과 학과가 각각 s 객체의 학년과 학과와 같으면 true를 반환하면 된다.
      이 중 하나라도 같지 않으면 false를 반환한다. 
      위 *(Person*)this == s 경우 *(Person*)this에 의해 Person의 ==가 호출되며 
      이 함수 호출 시 매개변수로는 s가 자동으로 const Person&로 변환되어 호출된다.   
```

### 문제 3 실행 결과
```
s1 == s2 : true
```

### 문제 4 설명
```
Inheritance::student() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        s2.setName("s2");
        s2.set(s1.getId()+1);
        s2.set(s1.getWeight() * 1.1);
        s2.set(!s1.getMarried());
        s2.setDepartment(s1.getDepartment()+"-Electronics");
        s2.setGPA(s1.getGPA()+1);
        s2.setYear(s1.getYear()+1);
        cout << "s2: "; s2.println();;
        cout << "s1 == s2 : " << (s1 == s2) << endl;
```
```
위 코드가 정상적으로 실행될 수 있도록 Student 클래스의 새로운 멤버함수들인
setDepartment(), setGPA(), setYear()와
getDepartment(), getGPA(), getYear() 등을 구현하라.
```

### 문제 4 실행 결과
```
s2: s2 2 71.94 false :Jongno-gu Seoul: Physics-Electronics 4.8 2
s1 == s2 : false
```

### 문제 5 설명
```
Inheritance::student() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        s2.whatAreYouDoing();
```
```
위 코드가 정상적으로 실행될 수 있도록 아래 실행 결과를 참고하여 
Student::study(), Student::takeClass()를 구현하라.
```

### 문제 5 실행 결과
```
~~~~~~~~~~~~~~~~ Student::whatAreYouDoing() ~~~~~~~~~~~~~~~~
s2 is studying as a 2-year student in Physics-Electronics
s2 took several courses and got GPA 4.8
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

### 문제 6 설명
```
1) Inheritance::student() 함수 마지막에 아래 코드를 추가하라.
```
```c++
        Student *s3 = (Student *)s1.clone();  // 다운 캐스팅
        cout << "s3: "; s3->println();
        cout << "s1: "; s1.println();;
        cout << "s3 == s1 : " << (*s3 == s1) << endl;
        delete s3;
```
```
2) 위 코드가 정상적으로 실행될 수 있도록 아래 실행 결과와 Person::clone()을 참고하여 
   Person* Student::clone()을 구현하라. 
   이 함수는 새로운 객체를 동적으로 생성하되 복사생성자를 활용하여 자기(this) 자신을 복제한다.
   복제된 것은 Student 객체일지라도 Person*를 반환해야 한다.
   Student*를 반환해도 컴파일러가 자동으로 Person*로 [업캐스팅]해서 반환한다.
```

### 문제 6 실행 결과
```
Person::Person(const Person&):s1 1 65.4 true :Jongno-gu Seoul:
Student::Student(const Student& s): Physics 3.8 1
s3: s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
s1: s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
s3 == s1 : true
Student::~Student(): Physics 3.8 1
Person::~Person():s1 1 65.4 true :Jongno-gu Seoul:
```