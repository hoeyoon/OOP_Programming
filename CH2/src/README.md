# OJ CH2

### 초기 프로그램 실행 결과

```c++
+++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
+ 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
+ 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? -1[엔터] // 사용자 직접 입력
Input a positive INTEGER.
Menu item number? 12 // 사용자 직접 입력 
12: OUT of selection range(0 ~ 11)
Menu item number? abc3 // 사용자 직접 입력
Input an INTEGER.
Menu item number? 1 // 사용자 직접 입력

+++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
+ 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
+ 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 2 // 사용자 직접 입력

+++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
+ 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
+ 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0 // 사용자 직접 입력
Good bye!!
```

### 문제 1 설명

[문제 1 실행 결과]처럼 출력되도록 print()와 println() 함수를 구현하라.

```c++
1) print(Person* p)
    p가 포인하는 구조체의 각 멤버를 [문제 1 실행 결과]와 동일하게 출력하라. 
    출력형식은 아래와 같다. 
        이름 id 체중 결혼여부 :주소:
    // 예) LeeSoonShin 0 70.1 1 :Gangnam Seoul:
    // 주소의 시작과 끝에는 ":"를 출력한다. 
    // (주소가 여러 단어로 구성되므로 ":"를 주소 구분자로 사용함)
    // 출력결과에서 bool 타입인 married는 1 또는 0으로 출력된다는 것을 주지하라.
    // 이후 문제에서 이를 true 또는 false로 출력되게 변경할 것이다.
    // print(Person* p)는 멤버들만 출력하고 줄바꾸기(endl)는 출력하지 않는다.

2) prinln(Person* p)
    print()를 호출하여 멤버들을 모두 출력한다.
    그 후 endl 조작자를 이용하여 줄바꾸기를 출력하라.
```

기존 printlnTest() 함수를 아래 함수로 교체하라.

```c++
void printlnTest() { // Menu item 1
    // 디폴트 값으로 초기화, 즉 모든 멤버 값을 0으로 초기화함
    Person p1 = {}; // 또는 Person p{};
    println(&p1);   
    // 위 p1을 Person p1;으로 선언해 놓고 p1을 출력해 보라. 아마 초기화가 되어 있지 않을 것이다.

    // 구조체의 각 멤버 초기화
    Person p2 = { "LeeSoonShin", 0, 70.1, true, "Gangnam Seoul" };
    println(&p2);

    Person p3{ "Hong,gildong", 1, 60.2, false, "Jongno-gu, Busan" };
    println(&p3);

    println(&p);
}
```

### 문제 1 실행결과
```c++
+++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
+ 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
+ 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1
 0 0 0 ::                            // 이름과 주소는 "" 문자열(빈 문자열)임
LeeSoonShin 0 70.1 1 :Gangnam Seoul:
Hong,gildong 1 60.2 0 :Jongno-gu, Busan:
Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:

... // 메뉴 생략
```

### 문제 2 설명

[문제 2 실행 결과]를 참고하여 init(...) 함수를 구현하라.

```c++
init(p, ...)
    p가 포인하는 구조체의 각 멤버를 함수의 상응하는 매개변수 값으로 초기화하라.
    p의 멤버 name과 id의 설정은 이미 구현되어 있으며 이를 참조하여 나머지 멤버도 값을 초기화하라.
    구조체 멤버 address도 name과 동일한 방법으로 매개변수 paddress의 내용을 복사해서 초기화하라.
    (strcpy() 사용법은 https://www.cplusplus.com/reference/을 검색해서 예문을 참조하라.)
```

기존 initTest() 함수를 아래 함수로 교체하라.

```c++
void initTest() { // Menu item 2
    Person u1;
    init(&u1, "u1", 10, 60.0, false, "Jongno-gu, Seoul");
    Person u2;
    init(&u2, "u2", p.id, p.weight, p.married, p.address);
    println(&p);
}
```

### 문제 2 실행결과

```c++
+++++++++++++ Person Structure Test Menu ++++++++++++
+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter +
... // 메뉴 생략
Menu item number? 2
init(u1 10 60 0 :Jongno-gu, Seoul:)
init(u2 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:)
Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:

... // 메뉴 생략
```