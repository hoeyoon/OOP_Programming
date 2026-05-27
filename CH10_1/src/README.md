# OJ CH10_1
### 이번 문제의 목적
```
VectorPerson 클래스를 템플릿 클래스 Vector< T >로 변경한다.
PMbyVector 클래스를 추가하여 Vector< T >를 테스트한다.
```

### 문제 1 설명
```
1) MainMenu의 문자열에서 일부분을 아래 문자열로 교체하라.
```
```
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10)                      *
```
```
2) 기존의 MultiManager를 아래 내용으로 교체하라.
    각 배열을 static으로 변경하고 배열 원소를 더 추가하였다. 배열 선언과 초기화를 주지하라.
    참고로 static 변수의 초기 값 설정은 클래스 외부에서 정의해 주어야 한다.
```
```c++
class MultiManager
{
    static Person persons[];
    static Student students[];
    static Worker workers[];
    static StudentWorker albas[];

public:
    static const int allPersonCount;
    static Person* allPersons[];
    PersonManager personMng { allPersons, allPersonCount };

    void run() {
        //cout << "PersonManager::run() starts" << endl;
        personMng.run();
        //cout << "PersonManager::run() returned" << endl;
    }
}; // ch3_2, 4_1, 4_2, ch8_2: MultiManager class

Person MultiManager::persons[5] = {
    Person("p0", 10, 70.0, false, "Gwangju Nam-gu Bongseon-dong 21"),
    Person("p1", 11, 61.1, true,  "Jong-ro 1-gil, Jongno-gu, Seoul"),
    Person("p2", 12, 52.2, false, "1001, Jungang-daero, Yeonje-gu, Busan"),
    Person("p3", 13, 83.3, true,  "100 Dunsan-ro Seo-gu Daejeon"),
    Person("p4", 14, 64.4, false, "88 Gongpyeong-ro, Jung-gu, Daegu"),
};

Student MultiManager::students[4] = {
    Student("s1", 21, 65.4, true,  "Jongno-gu Seoul", "Physics", 3.8, 1),
    Student("s2", 22, 54.3, false, "Yeonje-gu Busan", "Electronics", 2.5, 4),
    Student("s3", 23, 55.5, true,  "Dong-gu Incheon", "Computer", 3.5, 2),
    Student("s4", 24, 66.6, false, "Sasang-gu Sejong","History", 3.1, 1),
};

Worker MultiManager::workers[4] = {
    Worker("w1", 31, 33.3, false, "Kangnam-gu Seoul",  "Samsung", "Director"),
    Worker("w2", 32, 44.4, true,  "Dobong-gu Kwangju", "Hyundai", "Manager"),
    Worker("w3", 33, 55.5, true,  "Dong-gu Incheon",   "Hyundai", "Labor"),
    Worker("w4", 34, 66.6, false, "Sasang-gu Sejong",  "Kia", "CEO"),
};

StudentWorker MultiManager::albas[4] = {
    StudentWorker("a1", 41, 55.5, true, "Dong-gu Incheon",
                  "Computer", 3.5, 2, "Hyundai", "Labor",
                  "CU KangNam,Seven Eleven,GSStore Suwon", false),
    StudentWorker("a2", 42, 66.6, false, "Sasang-gu Sejong",
                  "History", 3.1, 1, "Kia", "CEO",
                  "Seven Eveven,eMart Jinju,CU Bongsun", true),
    StudentWorker("a3", 43, 51.9, false, "Buk-gu Daejeon",
                  "Computer", 3.5, 2, "Samsung", "Manager",
                  "Youngpung,Kyobo Gwanghwa,E-mart Suwon", true),
    StudentWorker("a4", 44, 66.6, true, "Nam-gu Busan",
                  "History", 3.1, 1, "LG", "DepartmentHead",
                  "CU, FamilyMart, LotteMart, HomePlus", false),
};

const int MultiManager::allPersonCount = 16;
Person* MultiManager::allPersons[allPersonCount] = {
        &persons[0],  &persons[1],  &persons[2],  &persons[3],
        &students[0], &students[1], &students[2], &students[3],
        &workers[0],  &workers[1],  &workers[2],  &workers[3],
        &albas[0],    &albas[1],    &albas[2],    &albas[3],
};
```
```
3) MultiManager::run() 함수 내의 두 개의 출력문을 아래처럼 모두 주석 처리하라.
```
```c++
class MultiManager
{
    ...
    void run() {
        //cout << "PersonManager::run() starts" << endl;
        personMng.run();
        //cout << "PersonManager::run() returned" << endl;
    }
};
```

### 문제 1 실행 결과
```
******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10)                      *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8) 7.PMbyVector               *
***************************************************************************
Menu item number? 1

====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
= 5.Insert(6_2) 6.Delete(6_2) 7.CopyPersons(7_3) 8.Reset(7_3)   =
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =
=================================================================
Menu item number? 1
display(): count 16
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] s1 21 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[5] s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[6] s3 23 55.5 true :Dong-gu Incheon: Computer 3.5 2
[7] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[8] w1 31 33.3 false :Kangnam-gu Seoul: Samsung Director
[9] w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[10] w3 33 55.5 true :Dong-gu Incheon: Hyundai Labor
[11] w4 34 66.6 false :Sasang-gu Sejong: Kia CEO
[12] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[13] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[14] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[15] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
```

### 문제 2 설명
```
VectorPerson을 템플릿 클래스 Vector< T >로 수정

지금까지 VectorPerson에 삽입하고, 저장하고, 빼내는 원소의 데이타 타입은 Person* 였다.
다시 말하지만 Person의 객체가 아니고 포인터를 pVector[]에 저장했다.
이제 VectorPerson을 Person, Student, Worker, StudWorker 등의 
다양한 종류의 객체 또는 포인터를 저장할 수 있는 템플릿 클래스로 만들어 보자. 
---------------------------------------------------------------------------
기존 VectorPerson 클래스를 템플릿 클래스 Vector< T >로 변환해 보자.
주의: 아래 각 항목을 실수없이 차근차근 수행하기 바란다.
---------------------------------------------------------------------------
1) class VectorPerson의 [선언부] 및 [멤버 함수 구현부]에서 VectorPerson 단어들을 
    모두 Vector로 수정하라. (이 외의 다른 곳은 아직 수정하지 마라.)
---------------------------------------------------------------------------
2)  아래 한 행 전체를 
template < typename T >
    클래스 외부에서 구현한 모든 멤버 함수 앞 줄에 추가하고, class Vector { 앞 줄에도 추가하라. 
    단, 클래스 [내부]에 있는 멤버 함수 앞에는 추가하지 마라.
---------------------------------------------------------------------------
3) 클래스 [외부]에서 구현한 모든 멤버 함수에 대해 아래를 수행하라. (클래스 [내부] 함수들은 제외)
    i) 외부에 구현된 멤버 함수들(operator 연산자 포함)의 이름 앞에 있는 
        Vector:: 을 Vector< T >:: 로 변경하라. 
    ii) 외부에 구현된 operator =, operator +=, operator + 연산자 함수의 
        [리턴 타입], [매개변수 타입], [지역 변수 타입]이 Vector 이면 Vector< T > 로 변경하고,
        Vector& 이면 Vector< T >& 로 변경하라.
---------------------------------------------------------------------------
 4) 지금까지 Vector에 삽입하고, 저장하고, 빼내는 원소의 데이타 타입은 Person* 였다.
    이제 변수 선언 시 Person* 를 임의의 데이타 타입(타입 매개변수) T 로 변경하자. 
    즉, Vector 클래스의 [선언부]와 [구현부]에서 Person* 를 모두 T 로 변경하고, 
    Person** 를 T* 로 변경하라.
    즉, Person **pVector 선언, at()와 operator [] 함수의 리턴 데이타 타입 등이다.
    이렇게 하면 Vector< Person* > 또는 Vector< Person >로 선언하여 
    Person 포인터 뿐만 아니라 Person 객체도 벡터 내에 저장할 수 있게 된다.
---------------------------------------------------------------------------
5) PersonManager 클래스 내의 멤버 변수 VectorPerson persons; 를 
    Vector< Person* > persons; 로 변경하라. 즉, Vector 클래스에 
    삽입하고, 저장하고, 빼내는 원소의 데이타 타입은 여전히 Person* 로 하겠다는 것이다.
---------------------------------------------------------------------------
6) VectorOperator 클래스 내에서 사용된 모든 VectorPerson 단어를 Vector< Person* > 
    로 변경하라. 출력 문장 내의 "VectorPerson ..." 단어도 마찬가지로 수정하라.
```

### 문제 2 실행 결과
```
// 컴파일 했을 경우 정상적으로 컴파일되어야 하며 
// 아래 메뉴항목을 순서적으로 실행했을 때 모두 정상 실행되어야 한다. (죽지 않고 실행된다면 OK)

******************************* Main Menu *...
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8)                            *
***************************************************************************
5   // OperatorOverload
9   // VectorOOL
1   // operator[]
1   // Display
0   // Exit
2   // operator!
3   // CopyConstructor
4   // operator=
5   // operator+
6   // operator=+
0   // Exit
0   // Exit
0   // Exit
```

### 문제 3 설명
```
PMbyVector 클래스 추가

위 문제에서 작성한 Vector< T >를 다양하게 활용해 보자.
PersonManager에서 Vector< Person* > persons를 선언하여 벡터에 Person*를 관리하였다.
Vector< T >에 Person* 대신 다양한 데이타 타입을 저장하고 관리해 보자.
---------------------------------------------------------------------------
1) 아래 클래스를 class Inheritance와 class MainMenu 사이에 배치하라.
    PMbyVector는 PersonManager처럼 Person 객체의 정보를 저장하고 관리한다. 
    그러나 Person의 객체들을 Vector< Person* > persons에 저장하지 않고
    하나의 Person 객체를 각 멤버별로 별도의 Vector< >에 저장한다.
```
```c++
class PMbyVector
{
    // 아래의 Vector들은 Person 객체의 멤버들을 저장하기 위함임
    Vector< string > name;
    Vector< int >    id;
    Vector< double > weight;
    Vector< bool >   married;
    Vector< char* >  address;
    int cpCount;   // copy() 시 사용할 복사 횟수: 새로운 사람 이름 생성용

    void pushArray();
    void pushPerson(Person* p);
    char* copyAddress(const char* addr);
    void printNotice(const string& preMessage, const string& postMessage);
    void clearVectors();
    void insertPerson(int index, Person* p);
    void erasePerson(int index);

public:
    PMbyVector();
    ~PMbyVector();
    void display();
    void append();
    void clear();
    void remove();
    void insert();
    void copy();
    void reset();
    void run();
};

// cpCount{}는 cpCount(0) 또는 cpCount=0와 같은 의미
PMbyVector::PMbyVector(): cpCount{} { pushArray(); }

PMbyVector::~PMbyVector() { /* 코드 추가 예정 */ }

// Person, Student, Worker, StudentWorker 객체들의 정보를 Vector들에 추가
void PMbyVector::pushArray() {
    for (int i = 0; i < MultiManager::allPersonCount; ++i)
        pushPerson(MultiManager::allPersons[i]);
}

// Person 객체의 각 멤버를 상응하는 Vector에 추가
// Person, Student, Worker, StudentWorker 객체들의 종류에 상관없이 
// 아래 정보만 저장함
void PMbyVector::pushPerson(Person* p) {
    name   .push_back(p->getName());
    id     .push_back(p->getId());
    weight .push_back(p->getWeight());
    married.push_back(p->getMarried());
    address.push_back(copyAddress(p->getAddress()));
}

// address 멤버의 경우 문자열을 저장하기 위한 메모리를 할당 받은 후 기존 주소 
// 문자열을 복사함; 새로 할당받은 메모리 주소를 반환함
char* PMbyVector::copyAddress(const char* addr) {
    if (addr == nullptr) return nullptr;
    char *newAddr = new char[strlen(addr)+1]; // +1은 문자열 끝의 '\0' 널 문자용
    strcpy(newAddr, addr);  // addr 문자열을 newAddr로 복사
    return newAddr;
}

void PMbyVector::display() { // Menu item 1
    int count = name.size();
    cout << "display(): count " << count << endl;
    for (int i = 0; i < count; ++i) {
        cout << "[" << i << "] " << name[i] << " ";
        cout << id[i] << " " << weight[i] << " " << married[i] << " :";
        cout << ((address[i]==nullptr)?"":address[i]) << ":" << endl;
    }
}
void PMbyVector::run() {
    using func_t = void (PMbyVector::*)();
    func_t func_arr[] = {
        nullptr, &PMbyVector::display,
    };
    int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 길이
    string menuStr =
    "============================ PMbyVector Menu =========================\n"
    "= 0.Exit 1.Display 2.Append 3.Clear 4.Insert 5.Delete 6.Copy 7.Reset =\n"
    "======================================================================\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this->*func_arr[menuItem])();
    }
} // 10_1: PMbyVector class
```
```
2) MainMenu::run() 내의 menuStr 문자열 중 일부를 아래 문자열로 교체하고,
    menuCount도 수정하라.
---------------------------------------------------------------------------
"* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8) 7.PMbyVector               *\n"
---------------------------------------------------------------------------
3) MainMenu::run() 에서 메인 메뉴항목 7번을 선택했을 때 실행하기 위한 
    case 문을 추가하고, 이 경우 PMbyVector().run();을 실행하도록 하라.
```

### 문제 3 실행 결과
```
******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10)                      *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8) 7.PMbyVector               *
***************************************************************************
Menu item number? 7

============================ PMbyVector Menu =========================
= 0.Exit 1.Display 2.Append 3.Clear 4.Insert 5.Delete 6.Copy 7.Reset =
======================================================================
Menu item number? 1
display(): count 16
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] s1 21 65.4 true :Jongno-gu Seoul:
[5] s2 22 54.3 false :Yeonje-gu Busan:
[6] s3 23 55.5 true :Dong-gu Incheon:
[7] s4 24 66.6 false :Sasang-gu Sejong:
[8] w1 31 33.3 false :Kangnam-gu Seoul:
[9] w2 32 44.4 true :Dobong-gu Kwangju:
[10] w3 33 55.5 true :Dong-gu Incheon:
[11] w4 34 66.6 false :Sasang-gu Sejong:
[12] a1 41 55.5 true :Dong-gu Incheon:
[13] a2 42 66.6 false :Sasang-gu Sejong:
[14] a3 43 51.9 false :Buk-gu Daejeon:
[15] a4 44 66.6 true :Nam-gu Busan:
```

### 문제 4 설명
```
PMbyVector::append()

PMbyVector::append()를 구현하고, run()의 func_arr[]에 등록하라.
1) 구현 시 PersonManager::append()를 복사해와 삽입하라.
2) PersonManager::printNotice(...)도 복사해서 추가하라.
3) append() 구현 시 p가 nullptr가 아닌 경우(if(p)), 
    persons.push_back(p)를 호출하는 대신 아래 두 문장들로 대체하라.
    i)  pushPerson(p)을 호출하여 객체의 정보를 Vector들에 삽입하라.
    ii) p가 포인터하는 객체 메모리는 더 이상 필요 없으므로 메모리를 반납하라.
```

### 문제 4 실행 결과
```
7    // PMbyVector
2    // Append
The number of persons to append? 7
Input 7 [delimiter(P, S, W, or A)] [person information] : 
// 아래 7개의 정보를 한번에 복사해서 입력하라. 
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
S s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21: Computer 3.3 2
W w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul: Kia CEO
A a3 14 54 false :Dong-gu, Incheon: Physics 3.8 1 Kakao Manager :SK, LG, KAI: true
S s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan: Biology 3.8 3
W w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul: Naver Department-Head
A a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false
display(): count 23
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...  // 기존과 동일
[16] p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[17] s3 12 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
[18] w3 13 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[19] a3 14 54 false :Dong-gu, Incheon:
[20] s4 15 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
[21] w4 16 77 false :Buk-ro 3, Kangdong-gu, Seoul:
[22] a4 17 88 true :Kangdong-gu, Daejeon:
```

### 문제 5 설명
```
PMbyVector::clear()

PMbyVector::clear()를 구현하고, run()의 func_arr[]에 등록하라.
1) 구현 시 PersonManager의 clear()를 복사해와 삽입하라.
2) deleteElemets()를 clearVectors()로 교체하라.
3) clearVectors()를 구현하라. 
    구현 시 PersonManager::deleteElemets()를 참고하여
    i) for를 이용하여 address.size()개의 각 address[i]가 포인터하는 메모리를 
        모두 반납하라. address[i]는 동적으로 할당 받은 char[] 배열이므로 
        반납시 []를 유의하라.
    ii) name, id, weight, married, address Vector 들의 모든 원소를 제거하라.
    iii) cpCount = 0;
```

### 문제 5 실행 결과
```
7    // PMbyVector
1    // Display
display(): count 16
...  // [문제 3] 실행 결과와 동일
3    // Clear
display(): count 0
1    // Display
display(): count 0
```

### 문제 6 설명
```
PMbyVector::~PMbyVector()

PMbyVector의 객체가 소멸될 때 [문제 5]에서처럼 address Vector에 저장된 
모든 메모리를 반납해야 한다. (이들은 생성자에서 동적으로 할당 받은 char[] 배열이기 때문이다.)
PMbyVector::~PMbyVector()를 구현하라.  
구현 시 앞서 구현한 clearVectors()를 호출하기만 하면 된다.
```

### 문제 6 실행 결과
```
7    // PMbyVector: PMbyVector 객체 생성
1    // Display
display(): count 16
...  // [문제 3] 실행 결과와 동일
0    // Exit: PMbyVector 객체 소멸되면서 ~PMbyVector() 호출됨
```

### 문제 7 설명
```
PMbyVector::insert()

PMbyVector::insert()를 구현하고, run()의 func_arr[]에 등록하라.
1) 구현 시 PersonManager::insert()를 복사해와 삽입하라.
2) persons.size()의 persons 대신 PMbyVector의 다른 Vector 이름으로 수정하라. 
    (name 또는 다른 Vector 이름을 사용해도 됨)
3) p가 nullptr인 경우 바로 리턴하라.
4) (p가 nullptr가 아닌 경우)
    persons.insert(index, p)를 호출하는 대신 아래 두 문장들로 대체하라.
    i)  insertPerson(index, p)을 호출하여 객체의 정보를 Vector[index] 위치에 삽입하라.
    ii) p가 포인터하는 객체 메모리는 더 이상 필요 없으므로 메모리를 반납하라.
5) insertPerson(int index, Person* p) 함수를 구현하라. 구현 시
    i) pushPerson(Person* p)의 내용을 복사해 삽입하라.
    ii) Vector::push_back(...) 함수 호출 대신 insert(...) 함수를 호출하라.
```

### 문제 7 실행 결과
```
7    // PMbyVector
1    // Display
display(): count 16
...  // [문제 3] 실행 결과와 동일

4    // Insert
Index to insert in front? 0
Input [delimiter(P, S, W, or A)] [person information] to insert:
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
display(): count 17
[0] p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:       // 새로 추가된 원소
[1] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
... 
[16] a4 44 66.6 true :Nam-gu Busan:

4    // Insert
Index to insert in front? 17
Input [delimiter(P, S, W, or A)] [person information] to insert:
A a4 17 88 true :Kangdong-gu, Daejeon: Electronics 3.4 2 NC Developer :CU, GS: false
display(): count 18
...  // 위와 동일
[16] a4 44 66.6 true :Nam-gu Busan:
[17] a4 17 88 true :Kangdong-gu, Daejeon:        // 새로 추가된 원소

3    // Clear
display(): count 0

4    // Insert: count가 0이므로 index to insert를 입력 받지 않음
Input [delimiter(P, S, W, or A)] [person information] to insert:
P p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
display(): count 1
[0] p3 11 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
```

### 문제 8 설명
```
PMbyVector::remove()

PMbyVector::remove()를 구현하고, run()의 func_arr[]에 등록하라.
1) 구현 시 PersonManager::remove()를 복사해와 삽입하라.
2) persons.size()의 persons 대신 PMbyVector 내의 다른 Vector 이름으로 수정하라.
3) delete persons[index]; persons.erase(index); 두 개의 문장 대신
    erasePerson(index);를 호출하라.
4) erasePerson(int index) 함수를 구현하라. 
    이 함수는 각 Vector의 index 위치의 원소를 제거한다. 구현시 먼저 
    i) address[index]는 동적으로 할당 받은 char[] 배열이므로 
        이 메모리를 먼저 반납하라. 반납시 []를 유의하라.
    i) insertPerson(int index, Person* p)의 내용을 복사해서 위 문장 뒤에 삽입하라.
    ii) insert(...)를 erase(...)로 변경하고, 두번째 인자를 모두 제거하라.
```

### 문제 8 실행 결과
```
7    // PMbyVector
1    // Display
display(): count 16
...  // [문제 3] 실행 결과와 동일

5    // Delete
Index to delete? 0
display(): count 15
[0] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[1] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[...
[13] a3 43 51.9 false :Buk-gu Daejeon:
[14] a4 44 66.6 true :Nam-gu Busan:

5    // Delete
Index to delete? 14
display(): count 14
[0] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[1] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
...
[12] a2 42 66.6 false :Sasang-gu Sejong:
[13] a3 43 51.9 false :Buk-gu Daejeon:

5    // Delete
Index to delete? 14
14: OUT of selection range(0 ~ 13)
Index to delete? 3
display(): count 13
...
[2] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[3] s2 22 54.3 false :Yeonje-gu Busan:
[4] s3 23 55.5 true :Dong-gu Incheon:
...
[12] a3 43 51.9 false :Buk-gu Daejeon:
```