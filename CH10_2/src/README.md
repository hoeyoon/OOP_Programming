# OJ CH10_2

### 이번 문제의 목적: STL(standard template library) 활용하기
```
기존 vector< T > 템플릿 클래스를 활용해 본다. 
random_shuffle(), sort(), reverse() 등의 알고리즘 함수들을 활용해 본다.
```

### 문제 0 설명
```
기존 Vector< T > 클래스 대신 C++ STL의 vector< T > 클래스 활용하기

1) 기존 PersonManager 클래스의 아래 멤버를 주석 처리하라.
    Vector< Person* >  persons; 
    그리고 아래 멤버를 위 문장 바로 밑에 추가하라. 
    vector< Person* >  persons; 
    기존에는 우리가 직접 작성한 Vector< > 클래스를 사용했지만 
    지금부터는 C++ STL 라이브러리에서 제공하는 vector< > 클래스를 활용할 예정이다.
---------------------------------------------------------------------------
2) PersonManager::remove() 에서 기존에는 persons.erase(index)를 호출했는데, 
    vector< >의 멤버 함수는 인덱스 대신 iterator를 사용해야 한다. 
    따라서 다음과 같이 수정하라.
    persons.erase(persons.begin()+index)
    이는 index 위치의 iterator를 사용하여 벡터 원소를 삭제하는 것이다.
    vector< T >::iterator는 포인터 변수처럼 정수 값을 더하여 반복자 위치를 옮길 수 있다. 
---------------------------------------------------------------------------
3) PersonManager::insert() 에서 기존에는 persons.insert(index, ...)를 호출했는데, 
    이를 다음과 같이 수정하라. 이 역시 반복자를 이용하여 원소를 삽입해야 하기 때문이다.
    persons.insert(persons.begin()+index, ...)
---------------------------------------------------------------------------
4) 나머지 push_back(), at(), capacity(), clear(), empty(), size(), 
    operator[] 등의 기존 Vector< T > 멤버 함수들은 vector< T > 멤버 함수들과 
    기능이 동일하므로 PersonManager 클래스 내에서 수정없이 그대로 사용할 수 있다.
---------------------------------------------------------------------------
5) 기존의 class VectorOperator 내의 Vector< >는 수정하지 마라.
```

### 문제 0 실행 결과
```
// 아래 각 메뉴항목을 순서적으로 실행했을 때 모두 정상 실행되어야 한다.
// 정상적으로 인적 객체가 삽입되고 삭제되어야 한다.
//----------------------------------------------------------------------------
1   // PersonManager
====================== Person Management Menu ...
1   // Display
6   // Delete
15  // Index to delete
6   // Delete
0   // Index to delete
5   // Insert
0   // Index to insert in front
P p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
5   // Insert
15  // Index to insert in front
A a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
```

### 문제 0-1 설명
```
BasePM 클래스 추가: PersonManager의 부모 클래스

1) 아래 새로운 Vector< T >와 Factory 클래스 사이에 배치하라.
    이 클래스는 PersonManager와 새로 생성할 CppSTL 클래스의 부모 클래스가 될 예정이다.
```
```c++
class BasePM
{
protected:
    vector< Person* >& persons;
    int& cpCount;

public:
    BasePM(vector< Person* >& persons, int& cpCount):
    	persons{persons}, cpCount{cpCount} { };  // 두 참조변수 초기화
    void display();
    void copyPersons();
};
```
```
2) 위 BasePM의 두 함수 display()와 copyPersons()를 외부에 구현하되
    기존 PersonManager의 동일한 함수를 복사해서 삽입하라.
3) PersonManager에서 위 BasePM을 public으로 상속하라.
4) PersonManager의 생성자 함수 서두(:와 { 사이)의 맨 앞에, 즉 array{array} 앞에
    위 BasePM의 생성자를 호출하는 BasePM(persons, cpCount), 을 삽입하라.
    이렇게 하면 부모 클래스 BasePM의 persons와 cpCount는 참조변수이므로
    PersonManager의 두 멤버 변수인 persons와 cpCount를 공유하게 된다.
5) PersonManager의 두 함수 display()와 copyPersons()를 삭제하라.
    이들 함수들은 부모 클래스 BasePM의 동일한 함수들에 의해 대체된다.
```

### 문제 0-1 실행 결과
```
1   // PersonManager
====================== Person Management Menu ...
1   // Display
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

7   // CopyPersons
display(): count 32
// [0] ~ [15] : 위 출력결과와 동일
[16] pp0 30 71 true :Gwangju Nam-gu Bongseon-dong 21:
...
[20] ss1 41 66.4 false :Jongno-gu Seoul: Physics 3.8 1
...
[24] ww1 51 34.3 true :Kangnam-gu Seoul: Samsung Director
...
[28] aa1 61 56.5 false :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
...
[31] aa4 64 67.6 false :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
```

### 문제 1 설명
```
CppSTL class 추가

1) 아래 새로운 class CppSTL를 BasePM과 Factory 클래스 사이에 배치하라.
    이 클래스는 C++ 표준 STL 라이브러리 및 알고리즘을 활용하고 테스트하는 클래스이다.
```
```c++
/******************************************************************************
 * ch10_2: CppSTL class
 ******************************************************************************/

class CppSTL: public BasePM
{
public:
    CppSTL(vector< Person* >& persons, int& cpCount);
    void shuffle();
    void sort();
    void reverseSort();
    void reverse();
    void run();
};

CppSTL::CppSTL(vector< Person* >& persons, int& cpCount):
    /* TODO: BasePM의 생성자를 호출하라 */ {
    // TODO: [문제 6] persons의 각 객체의 메모 멤버를 초기화하라.
}

void CppSTL::run() {
    using func_t = void (CppSTL::*)();
    func_t func_arr[] = {
        nullptr, &CppSTL::display, 
    };
    int menuCount = TODO: func_arr[] 배열의 길이;
    string menuStr =
        "----------------------- C++ STL Menu ------------------------\n"
        "- 0.Exit 1.Display 2.Shuffle 3.Sort 4.ReverseSort 5.Reverse -\n"
        "-------------------------------------------------------------\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this- >*func_arr[menuItem])();
    }
}
```
```
2) 위 [문제 0-1] PersonManager의 생성자의 서두를 참고하여 
    CppSTL의 생성자 서두에서 부모 클래스인 BasePM의 생성자를 호출하라.
3) CppSTL::run() 내의 menuCount 변수를 초기화하라.
4) 아래 함수를 PersonManager의 public 멤버 함수로 추가하고,
----------------------------------------------------------------------------
void PersonManager::cppSTL() {
    CppSTL(persons, cpCount).run(); // 임시객체 생성 후 run() 실행
    // CppSTL stl(persons, cpCount); stl.run(); 과 동일함
}
----------------------------------------------------------------------------
5) 아래 문자열을 PersonManager::run()의 메뉴 문자열에 추가하고, 
    이 함수 내의 func_arr[]에 위 PersonManager::cppSTL() 함수 주소를 등록하라.
----------------------------------------------------------------------------
        "= 12.C++STL(10_2)                                               =\n"
```

### 문제 1 실행 결과
```
1   // PersonManager
====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
= 5.Insert(6_2) 6.Delete(6_2) 7.CopyPersons(7_3) 8.Reset(7_3)   =
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =
= 12.C++STL(10_2)                                               =
=================================================================
Menu item number? 12

----------------------- C++ STL Menu ------------------------
- 0.Exit 1.Display 2.Shuffle 3.Sort 4.ReverseSort 5.Reverse -
-------------------------------------------------------------
Menu item number? 1   // Display
// 위 [문제 0-1]의 Display 메뉴항목 실행결과와 동일해야 함
```

### 문제 2 설명
```
전역함수 random_shuffle()

CppSTL::shuffle() 함수를 구현하고, 이를 CppSTL::run()의 func_arr[]에 추가하라.
함수 구현 시 
i) 이 함수에서 persons 벡터에 있는 원소들의 배치 순서를 랜덤하게 재배치하라.
    이때 기존 < algorithm >에 있는 전역함수 random_shuffle()을 사용하라. 즉,
    random_shuffle(persons의 시작 iterator, persons의 끝 iterator) 호출하여
    persons 벡터에 있는 원소들의 배치 순서를 랜덤하게 재배치하라. 이 함수 호출 시
    함수 인자인 시작과 끝 iterator는 persons의 begin()과 end()를 사용하면 된다. 
    헤드 파일 < algorithm >을 include하라.
ii) display()를 호출하라.
```

### 문제 2 실행 결과
```
1 12 1 2   // Shuffle
// 랜덤하게 재배치하므로 출력 순서가 아래와 다르게 출력될 수도 있음
[0] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[3] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[4] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[5] w4 34 66.6 false :Sasang-gu Sejong: Kia CEO
[6] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[7] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[8] s1 21 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[9] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
[10] w1 31 33.3 false :Kangnam-gu Seoul: Samsung Director
[11] s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[12] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[13] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[14] w3 33 55.5 true :Dong-gu Incheon: Hyundai Labor
[15] s3 23 55.5 true :Dong-gu Incheon: Computer 3.5 2

// 위 2번 Shuffle 메뉴 항목을 실행할 때마다 원소들의 배치 순서가 다르게 출력될 것이다.
```

### 문제 3 설명
```
CppSTL::sort() 함수를 구현하고, 이를 run()의 func_arr[]에 추가하라.
이 함수에서 persons 벡터에 있는 사람들을 사전적 이름 순서로 정렬하되, 
이름이 같을 경우에는 id 순서(작은 수에서 큰 수 순서)로 배치하라.
----------------------------------------------------------------------------
함수 구현 시 기존 < algorithm >에 있는 sort() 전역 함수를 사용하라. 즉,
i) std::sort(persons의 시작 iterator, persons의 끝 iterator) 호출하여 정렬한다.
    persons의 시작 iterator: persons.begin()
    persons의 끝 iterator:  persons.end()
ii) display()를 호출하라.
----------------------------------------------------------------------------
위에서 sort() 앞에 std::를 붙이는 이유는 알고리즘의 sort() 전역함수를 호출하기 위함이다.
만약 std::가 없으면 CppSTL의 멤버함수 sort()를 잘못 호출하게 되므로 반드시 붙여 주어야 한다.
위처럼 구현하여 실행해 보라. Person 클래스의 name 멤버를 순서적으로 비교하는 함수가  
없기 때문에 정상적으로 정렬이 되지 않을 것이다.
----------------------------------------------------------------------------
이런 문제를 해결하기 위해 위 std::sort() 함수를 호출할 때 별도로 Person 클래스의 name 멤버를
비교하는 람다 함수를 마지막 인자로 넘겨 주어야 한다. 
1) 이를 위해 아래의 comp 람다 함수를 CppSTL::sort() 함수 내의 맨처음에 선언하라.
```
```c++
    auto comp = [] (Person* e1, Person* e2) - > bool {
        return ( (e1- >getName() < e2- >getName()) ||
                 (e1- >getName() == e2- >getName() && e1- >getId() < e2- >getId()) ) ?
               true: false;
    };
```
```
2) std::sort() 함수 호출시 마지막 인자로 아래처럼 람다 변수 comp를 추가하라.
----------------------------------------------------------------------------
   std::sort(persons의 시작 iterator, persons의 끝 iterator, comp);
----------------------------------------------------------------------------
이렇게 정렬 함수를 호출하면 이 함수는 persons 벡터를 정렬하면서 벡터 내의 
두 사람 객체를 비교하기 위해 매번 람다 함수 comp를 호출하게 된다. 
이때 비교하고자 하는 두 사람 객체의 포인터(Person*)가 매개변수로 넘어 온다. 
이 포인터가 넘어 오는 이유는 vector< Person* > persons에 저장되어 있는 것은 
객체가 아니라 객체 포인터이기 때문이다.
일반적으로 정렬시 사용되는 람다 함수는 e1이 e2보다 작으면 true, 아니면 false를 반환한다.
이때 요구되는 비교 조건은 응용 프로그램에 따라 다른 조건이 주어지는데 
그 조건에 맞게 람다 함수를 작성하면 된다. 
----------------------------------------------------------------------------
위 comp 람다 함수는 매개변수 e1과 e2를 직접 비교하는 것이 아니라 우리 문제의 요구조건에 따라 
e1과 e2의 이름을 비교하여 (e1의 이름이 e2의 이름보다 작거나) 또는 
(두 이름이 같은 경우 e1의 id가 e2의 id 보다 작으면) true를 반환한다. 
```

### 문제 3 실행 결과
```
1    // PersonManager
1    // Display
2    // Append
6
P p3 9 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
P p3 8 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
P p3 7 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
W w3 4 55.5 true :Dong-gu Incheon: Hyundai Labor
W w3 3 55.5 true :Dong-gu Incheon: Hyundai Labor
S s2 1 54.3 false :Yeonje-gu Busan: Electronics 2.5 4

12   // C++STL
----------------------- C++ STL Menu ...
1    // Display
3    // Sort
display(): count 22
[0] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[1] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[2] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[3] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
[4] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[5] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[6] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[7] p3 7 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[8] p3 8 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[9] p3 9 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[10] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[11] s1 21 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[12] s2 1 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[13] s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[14] s3 23 55.5 true :Dong-gu Incheon: Computer 3.5 2
[15] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[16] w1 31 33.3 false :Kangnam-gu Seoul: Samsung Director
[17] w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[18] w3 3 55.5 true :Dong-gu Incheon: Hyundai Labor
[19] w3 4 55.5 true :Dong-gu Incheon: Hyundai Labor
[20] w3 33 55.5 true :Dong-gu Incheon: Hyundai Labor
[21] w4 34 66.6 false :Sasang-gu Sejong: Kia CEO

2    // Shuffle
3    // Sort: 앞선 Sort와 동일한 결과가 나와야 함
```

### 문제 4 설명
```
CppSTL::reverseSort() 함수를 구현하고, 이를 run()의 func_arr[]에 추가하라. 
이 함수에서 persons 벡터에 있는 사람들을 사전적 이름 순서를 역순으로 정렬하되, 
이름이 같을 경우에는 id의 역순(큰 수에서 작은 수 순서)로 배치하라.
----------------------------------------------------------------------------
1) 함수 구현 시 위 [문제 3]처럼
    auto comp = 람다 함수 구현 
       // 위 [문제 3]의 람다 함수와 동일하게 구현하되 return 값을 반대로 반환하면 됨)
       // 즉, true를 false로, false를 true로 반환하면 역순으로 정렬된다.
    std::sort() 함수를 이용하여 정렬한다.
    그런 후 display()를 호출하라.
----------------------------------------------------------------------------
이렇게 구현한 후 프로그램을 실행시켜라. 아래 [문제 4] 실행 결과와 동일하게 나와야 한다.
----------------------------------------------------------------------------
2) 위 코드가 정상적으로 실행되면 다음과 같이 프로그램을 수정하라.
    위 auto comp = 람다식; 문장 전체를 주석으로 처리하라. 
    람다식을 사용하지 않고 다른 방식으로 구현할 예정임.
    아래 클래스를 기존 주석처리된 람다식 뒤에 배치하라. 함수 내에서 다른 클래스 선언 가능함.
```
```c++
    class Compare { 
    public:
        bool operator()(Person* e1, Person* e2) { // template 멤버 함수
            TODO: 람다식의 return 문장을 여기에 배치
        }
    };
```
```
3) 위 클래스 다음에 아래 객체 변수를 선언하라. std::sort() 문장은 기존처럼 사용한다.
----------------------------------------------------------------------------
    Compare comp; // 이렇게 객체를 선언한 후 sort() 문장에서 기존처럼 이 객체를 사용함
----------------------------------------------------------------------------
    이는 위 함수 연산자 operator()를 가진 클래스의 객체를 생성한 후 이 객체를 
    sort() 함수의 마지막 인자로 넘겨 주는 것이다. 
    중요: 실제로 1)의 auto comp 람다식은 컴파일러에 의해 이런 식으로 구현된다. 
    이렇게 해서 프로그램을 실행시켜도 [문제 4] 실행 결과와 동일하게 나와야 한다.
----------------------------------------------------------------------------
4) 이제 위 Compare comp; 문장과 바로 다음 문장인 std::sort() 함수 호출 문장을 
    주석처리하고, 대신 아래 sort() 문장을 주석처리된 기존 sort() 문장 뒤에 삽입하라. 
    이는 미리 선언된 객체 변수 comp를 sort() 함수 인자로 넘겨 주는 대신
    Compare의 임시 객체를 생성한 후 바로 sort()의 마지막 인자로 넘겨 주는 문장이다. 
    std::sort(persons.begin(), persons.end(), Compare()); // 임시 객체 생성
```

### 문제 4 실행 결과
```
1    // PersonManager
1    // Display
2    // Append
6 
P p3 9 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
P p3 8 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
P p3 7 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
W w3 4 55.5 true :Dong-gu Incheon: Hyundai Labor
W w3 3 55.5 true :Dong-gu Incheon: Hyundai Labor
S s2 1 54.3 false :Yeonje-gu Busan: Electronics 2.5 4

12   // C++STL
1    // Display
4    // ReverseSort
display(): count 22
[0] w4 34 66.6 false :Sasang-gu Sejong: Kia CEO
[1] w3 33 55.5 true :Dong-gu Incheon: Hyundai Labor
[2] w3 4 55.5 true :Dong-gu Incheon: Hyundai Labor
[3] w3 3 55.5 true :Dong-gu Incheon: Hyundai Labor
[4] w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[5] w1 31 33.3 false :Kangnam-gu Seoul: Samsung Director
[6] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[7] s3 23 55.5 true :Dong-gu Incheon: Computer 3.5 2
[8] s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[9] s2 1 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[10] s1 21 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[11] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[12] p3 9 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[13] p3 8 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[14] p3 7 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[15] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[16] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[17] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[18] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
[19] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[20] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[21] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false

2    // Shuffle
4    // ReverseSort: 앞선 ReverseSort와 동일한 결과가 나와야 함
```

### 문제 5 설명
```
전역함수 reverse()

CppSTL::reverse() 함수를 구현하고, 이를 run()의 func_arr[]에 추가하라. 
이 함수에서 persons 벡터에 있는 원소들의 배치 순서를 역으로 배치한다. 
즉, 1 3 4 2로 저장된 원소를 2 4 3 1 등으로 역으로 재배치하는 것이다.  
이 함수 구현 시
----------------------------------------------------------------------------
   기존 < algorithm >에 있는 전역함수 reverse()를 사용하라. 즉,
   std::reverse(persons의 시작 iterator, persons의 끝 iterator) 호출하라.
   그런 후 display()를 호출하라.
```

### 문제 5 실행 결과
```
1    // PersonManager
12   // C++STL
1    // Display
5    // Reverse
display(): count 16
[0] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
[1] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[2] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[3] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[4] w4 34 66.6 false :Sasang-gu Sejong: Kia CEO
[5] w3 33 55.5 true :Dong-gu Incheon: Hyundai Labor
[6] w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[7] w1 31 33.3 false :Kangnam-gu Seoul: Samsung Director
[8] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[9] s3 23 55.5 true :Dong-gu Incheon: Computer 3.5 2
[10] s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[11] s1 21 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[12] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[13] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[14] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[15] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:

3    // Sort
5    // Reverse: 위 [문제 4] 실행결과의 ReverseSort와 동일한 결과가 나와야 함
```