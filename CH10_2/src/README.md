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