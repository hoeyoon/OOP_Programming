# OJ CH10_3

### 이번 문제의 목적: STL(standard template library) 활용하기

### 코드 추가 및 변경 1
```
1) CppSTL::run() 내의 menuStr에 아래 문자열을 추가하라.----------------------------------------------------------------------------
        "- 6.DispMemo 7.CountWord 8.Top10WordCount 9.CopyPersons     -\n"
```

### 문제 1 설명
```
기존의 경우 PersonManager에서 관리되는 사람들의 초기 메모 문자열은 비어 있었다. 
이제 PersonManager의 생성자에서 persons 벡터에 삽입되는 각 사람의 메모를 초기화해 보자.
---------------------------------------------------------------------------
1) 먼저 메모 문자열로 사용될 아래 문자열 배열 memoArr[]을 class CppSTL 앞(위)쪽에 배치시켜라.
    아래의 각 R"(...)"은 "(와 )" 사이의 문자열을 정의하는데 각 행의 끝에 있는 줄바꾸기 문자('\n')도
    문자열 속에 함께 포함시켜 준다. 즉, 다음 문자열은 실제로 "abc\nDef"와 동일하다.
R("abc
Def")
    이런 방식은 여러 행으로 구성된 하나의 문자열을 정의할 때 유용하다.
```
```c++
const char* memoArr[] = { memoData,
R"(The Last of the Mohicans
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
)",

R"(The Last of the Mohicans
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
)",

R"(The Last of the Mohicans
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
)",

R"(The Last of the Mohicans
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
)",

R"(The Last of the Mohicans
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
)",

R"(confusion in the Indian names, as to render some explanation useful.
)",

R"(It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
)",

R"(greater antithesis of character,
)",

R"(confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
)",
};
int lenMemoArr = sizeof(memoArr) / sizeof(memoArr[0]);
```
```
이제 위 각 memoArr[i] 문자열을 벡터 persons의 각 사람의 초기 메모 내용로 설정하자.
2) CppSTL::CppSTL(...) 생성자 함수 { 본체 } 에 다음 코드를 추가하라. 
---------------------------------------------------------------------------
    int i = 0;
    범위기반 for문을 사용하여 벡터 persons의 각 원소 p에 대해, 즉 for (auto p : persons)
        // 참고로 p는 Person*이고, 아래 getMemo()는 char *이다.
        p가 포인터하는 객체의 메모(p->getMemo())가 nullptr이거나 또는 
                        메모 길이(strlen(p->getMemo()))가 0이면
             위 memoArr[i]를 p의 메모로 설정(setMemo()) 해 준다. 그리고
             i 값을 증가시킨 후 i가 lenMemoArr와 같거나 클 경우 다시 0으로 설정함
```
```
3) CppSTL::dispMemo() 함수를 구현하고, 이를 run()의 func_arr[]에 추가하라. 
    이 함수는 persons 벡터에 있는 모든 사람들의 메모 내용을 순서적으로 출력한다.
    함수 구현 시
---------------------------------------------------------------------------
    범위기반 for문을 사용하여 벡터 persons의 각 원소 p에 대해, 
        Memo 객체 memo를 선언한다; 이때 Memo 생성자의 인자로 p의 메모를 넘겨준다.
        // 즉, Memo 생성자는 p의 메모의 시작 주소를 매개변수로 넘겨 받아 
        // Memo 객체 memo에 메모를 복사하여 저장한다. 
        아래처럼의 p의 이름을 출력한다. 
        cout << "name: " << p->getName() << endl;
        실행결과를 참고하여 Memo의 적절한 멤버함수를 사용하여 memo의 내용을 출력하라.
```

### 문제 1 실행 결과
```
1    // PersonManager
12   // C++STL
----------------------- C++ STL Menu ------------------------
- 0.Exit 1.Display 2.Shuffle 3.Sort 4.ReverseSort 5.Reverse -
- 6.DispMemo 7.CountWord 8.Top10WordCount 9.CopyPersons     -
-------------------------------------------------------------
Menu item number? 6    // DispMemo 
name: p0
------- Memo -------
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
--------------------
name: p1
------- Memo -------
The Last of the Mohicans
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
--------------------
name: p2
------- Memo -------
The Last of the Mohicans
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
--------------------
name: p3
------- Memo -------
The Last of the Mohicans
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
--------------------
name: s1
------- Memo -------
The Last of the Mohicans
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
--------------------
name: s2
------- Memo -------
The Last of the Mohicans
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
--------------------
name: s3
------- Memo -------
confusion in the Indian names, as to render some explanation useful.
--------------------
name: s4
------- Memo -------
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
--------------------
name: w1
------- Memo -------
greater antithesis of character,
--------------------
name: w2
------- Memo -------
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
--------------------
name: w3
------- Memo -------
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
--------------------
name: w4
------- Memo -------
The Last of the Mohicans
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
--------------------
name: a1
------- Memo -------
The Last of the Mohicans
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
--------------------
name: a2
------- Memo -------
The Last of the Mohicans
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
--------------------
name: a3
------- Memo -------
The Last of the Mohicans
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
--------------------
name: a4
------- Memo -------
The Last of the Mohicans
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
--------------------
```

### 문제 2-1 설명
```
map< K,V > 컨테이너

이제 map< K,V > 컨테이너를 활용해 보자. 
아래 [문제 2-1] 실행 결과를 먼저 확인하라. 사용자로부터 단어("the")를 입력 받고 persons 벡터에서 
관리되는 각 사람의 메모 중에 그 단어가 출현하는 횟수를 세어서 "사람이름: 단어출현횟수"를 출력해 준다. 
---------------------------------------------------------------------------
CppSTL::countWord() 함수를 구현하고, 이를 run()의 func_arr[]에 추가하라.
    이 함수에서 사용자로부터 단어 하나를 입력 받는다.
    persons 벡터에 등록된 각 사람의 메모 중에 이 단어가 출현하는 횟수를 세어 
        < 사람이름, 단어출현횟수 > 짝을 map 컨테이너에 저장하라.
    그런 후 마지막에 map에 저장된 각 원소 < 사람이름, 단어출현횟수 >를 순서적으로 출력하라. 
---------------------------------------------------------------------------
이 함수 코드는 다음과 같다. 코드를 잘 이해하기 바란다.
```
```c++
using PairStrInt = pair< string, int >; 
// 이후부터 pair< string, int > 를 간단히 PairStrInt 로 사용하겠다는 의미
// pair< string, int >는 struct pair { string first; int second; }와 동일함

void CppSTL::countWord() {
    map< string, int > wcMap; // < 사람이름, 단어출현횟수 >를 저장하는 컨테이너 (트리에 원소들을 보관)
    string next, &word = UI::getNext("Word to count? "); // 사용자로부터 단어 하나 입력 받음

    for (auto p: persons) { // persons에 보관 중인 각 사람 객체 포인터 p에 대해
        Memo memo(p->getMemo());
        int count = 0;
        for (size_t pos = 0; !memo.getNext(pos, next).empty(); ) // 메모에서 한 단어 빼옴
            if (next == word) ++count; // 사용자가 입력한 word와 같은 단어를 찾으면 count 증가
        wcMap[p->getName()] = wcMap[p->getName()] + count;
        // < 사람이름, count > 짝을 wcMap에 저장; 기존이 동일 이름이 있을 경우 기존 값에 count 값을 더함 
    }
    cout << "=== Word count in NAME order ===" << endl;
     
    // 아래 auto& p는 pair< string, int >& 이며 참조자(&)이다.
    // 즉 struct pair { string first; int second; }의 객체 참조자임
    // first가 키, second가 값
    for (auto& p: wcMap)  // wcMap에 저장된 각 pair< 사람이름, 단어출현횟수 > p에 대해,
        cout << p.first << ": " << p.second << endl; 
        // first: 사람이름, second: 단어출현횟수
    // 위의 범위기반 for 문의 각 p에 저장된 사람 이름은 사전적 순서로 출력된다.
    // map< string, int > wcMap에 저장될 때 키 값인 사람이름 순서로 정렬되어 저장되기 때문이다.
}
```

### 문제 2-1 실행 결과
```
1 12 1 6
----------------------- C++ STL Menu ...
- 6.DispMemo 7.CountWord 8.Top10WordCount 9.CopyPersons     -
-------------------------------------------------------------
Menu item number? 7
Word to count? the
=== Word count in NAME order ===                // 사람 이름 순으로 출력됨
a1: 3
a2: 6
a3: 2
a4: 6
p0: 9
p1: 7
p2: 3
p3: 6
s1: 2
s2: 6
s3: 1
s4: 2
w1: 0
w2: 1
w3: 9
w4: 7

Menu item number? 7
Word to count? of
=== Word count in NAME order ===
a1: 3
a2: 1
a3: 2
a4: 1
p0: 5
p1: 3
p2: 3
p3: 1
s1: 2
s2: 1
s3: 0
s4: 2
w1: 1
w2: 1
w3: 5
w4: 3
```

### 문제 2-2 설명
```
위 CppSTL::countWord() 함수는 사람이름이 사전적 순서로 출력되었다. 이는 
map< string, int > wcMap에 저장할 때 키 값인 이름 순서로 정렬해서 저장하기 때문이다.
---------------------------------------------------------------------------
아래 [문제 2-2] 실행 결과를 먼저 확인하라. 기존 출력에 이어 추가적으로 
사용자가 입력한 단어의 출현 횟수가 가장 많은 사람부터 작은 순서로 정렬하여 출력해 준다.
---------------------------------------------------------------------------
기존 CppSTL::countWord() 함수의 맨 뒤에 단어의 출현 횟수가 가장 많은 사람부터 
횟수가 가장 작은 사람 순서로 "사람이름: 출현횟수"를 출력하는 코드를 삽입하라. 
이를 구현하기 위해 "사람이름: 출현횟수"를 wcMap에서 하나씩 구해와 벡터에 저장한 후 
이 벡터를 출현횟수 순서로 정렬하면 된다.
---------------------------------------------------------------------------
기존 CppSTL::countWord() 함수의 맨 뒤에 아래 코드를 추가하라. 코드 추가 시 먼저,
```
```c++
    PairStrInt(이름과 출현회수를 저장하는 짝) 타입의 객체를 저장하는 새로운 vector 객체 변수 
    wcVector를 선언하라. 즉, vector< PairStrInt > wcVector;
    // PairStrInt은 countWord() 함수 앞쪽 코드 참조;

    // 각 <이름, 출현횟수> p를 wcMap에서 구해 와 wcVector 벡터에 저장한다.
    // 아래 p는 PairStrInt 형의 객체임; 이 객체를 바로 벡터에 삽입하면 됨
    범위기반 for문을 사용하여 벡터 wcMap 각 원소 auto& p에 대해
       원소 p를 wcVector의 맨 뒤에 추가 (원소 p는 < 이름,출현회수 >를 저장하는 짝 pair 임)

    // 정렬 시 사용되는 람다 함수: 출현횟수(second)가 큰 수에서 작은 수 순서로 정렬
    //                      출현횟수가 동일할 경우 사람이름(first) 순서으로 정렬
    // e1과 e2는 wcVector 벡터 내의 임의의 두 원소임
    auto comp = [](PairStrInt& e1, PairStrInt& e2) {
        return (e1.second > e2.second) || 
               (e2.second == e1.second && e1.first < e2.first);
    };
    위 람다 함수를 사용하여여 wcVector의 처음부터 끝까지 정렬하라. (CppSTL::sort() 함수 참조)

    cout << "\n=== Word count in COUNT order ===" << endl;
    기존 CppSTL::countWord()의 마지막 코드를 참고하여 
    wcVector의 각 원소의 이름과 횟수를 출력하라.
```

### 문제 2-2 실행 결과
```
1 12 1 6 
7      // CountWord 
Word to count? the
=== Word count in NAME order ===
a1: 3
...    // 기존 [문제 2-1] 실행 결과와 동일
w4: 7

       // 아래는 출현 횟수 높은 순으로 출력됨; 동일 횟수인 경우 사람 이름 순
=== Word count in COUNT order ===  
p0: 9
w3: 9
p1: 7
w4: 7
a2: 6
a4: 6
p3: 6
s2: 6
a1: 3
p2: 3
a3: 2
s1: 2
s4: 2
s3: 1
w2: 1
w1: 0


Menu item number? 7
Word to count? of
=== Word count in NAME order ===
a1: 3
...    // 기존 [문제 2-1] 실행 결과와 동일
w4: 3

=== Word count in COUNT order ===
p0: 5
w3: 5
a1: 3
p1: 3
p2: 3
w4: 3
a3: 2
s1: 2
s4: 2
a2: 1
a4: 1
p3: 1
s2: 1
w1: 1
w2: 1
s3: 0
```