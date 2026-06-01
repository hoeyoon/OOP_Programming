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

### 문제 3-1 설명
```
아래 [문제 3-1] 실행 결과를 먼저 확인하라. 
persons 벡테에서 관리되는 모든 사람들의 메모 중에 포함된 모든 단어에 대해 그 단어가 출현하는 횟수를 
세어서 "단어이름: 단어출현횟수"를 출력하되, 
단어의 출현 횟수가 가장 많은 사람부터 작은 순서로 출력해 준다.
---------------------------------------------------------------------------
CppSTL::top10WordCount() 함수를 구현하고, 이를 run()의 func_arr[]에 추가하라.
    이 함수에서 각 사람의 메모를 구한 후 
    그 메모에 있는 각 단어가 출현될 때마다 그 단어의 < 단어이름, 단어출현횟수 > 짝을 map 컨테이너에
    저장하되 이미 단어가 존재할 경우 그 단어의 출현횟수를 1 증가시킨다. 
    그런 후 마지막에 map에 저장된 각 원소 < 단어이름, 단어출현횟수 >를 순서적으로 출력한다. 
---------------------------------------------------------------------------
이 함수 코드는 다음과 같다. 코드를 잘 이해하기 바란다.
```
```c++
void CppSTL::top10WordCount() {
    map< string, int > wordCountMap;
    범위기반 for문을 사용하여 persons의 각 p에 대해 (CppSTL::countWord()처럼 하면 됨)
        p의 메모를 구하여 Memo memo에 저장한 후 
        for 문을 이용하여 memo 내의 각 단어를 얻어 와 wordCountMap의 [] 연산자를 사용하여 
            해당 단어의 출현횟수를 1 증가시킨다. (CppSTL::countWord()처럼 하면됨)
    cout << "=== Word count in alphabetical order ===" << endl;
    CppSTL::countWord()의 마지막 코드를 참고하여 wordCountMap의 각 단어 이름과 횟수를 출력하라.
}
```

### 문제 3-1 실행 결과
```
1 12 1 6
8        // Top10WordCount
=== Word count in alphabetical order ===
': 2
,: 65
.: 20
America: 2
Author: 2
Cooper: 2
Fenimore: 2
Few: 5
Indian: 18
Introduction: 2
It: 7
James: 2
Last: 12
Mohicans: 12
North: 2
Still: 8
The: 12
accompanying: 8
allusions: 11
and: 15
antithesis: 6
are: 11
as: 10
believed: 7
character: 6
confusion: 10
diversity: 5
exhibit: 5
explanation: 10
express: 5
greater: 11
if: 5
in: 34
information: 7
is: 15
it: 5
its: 11
itself: 8
may: 5
men: 5
most: 7
much: 16
names: 10
native: 2
necessary: 11
notes: 8
obscurity: 8
obvious: 8
of: 34
or: 13
reader: 8
render: 10
rendered: 11
s: 2
scene: 7
so: 21
some: 10
sufficiently: 11
tale: 7
text: 8
than: 2
that: 7
the: 70
there: 8
this: 7
to: 29
traditions: 8
understand: 11
useful: 10
warrior: 2
we: 5
```

### 문제 3-2 설명
```
// 아래 [문제 3-2] 실행 결과를 먼저 확인하라. 
// 기존 [문제 3-1] 출력에 이어서 출력한 단어들 중 출현 횟수가 가장 많은 10개의 단어를 선별한 후
// 출현 회수가 많은 단어부터 작은 단어 순으로 정렬하여 출력하였다.
//----------------------------------------------------------------------------
여기서는 우순순위 큐 priority_queue< > 를 사용한다. 이 컨테이너는 데이타를 큐에 보관하지만
FIFO 순서가가 아니라 우선순위 순서로, 즉 빼낼 때 우선순위가 제일 높은 원소부터 빼 낼 수 있게 해 준다.
우선순위를 지정하는 것은 원소를 비교하는 비교함수에서 결정한다.
여기서 우선순위는, 출현횟수가 많은 10개의 단어 중 (출현횟수가 가장 많은 단어가) 우선순위가 가장 높으며
(출현횟수가 같을 경우 단어이름이 사전적 순서에서 앞선 단어가) 우선순위가 더 높은 것으로 정의한다.
---------------------------------------------------------------------------
아래 헤드 파일을 소스파일 앞쪽에 추가하라.
---------------------------------------------------------------------------
#include < queue >      // ch10_3 추가
---------------------------------------------------------------------------
그리고 기존 CppSTL::top10WordCount() 함수의 맨 뒤에 아래 코드를 추가하라.
```
```c++
    // 우선순위 큐에서 우선순위를 비교할 때 사용하는 함수 operator 정의
    // e1, e2는 pair< string, int > , 즉 struct pair { string first; int second; }
    //         pair< 단어이름, 출현횟수 >
    struct CountComp {
        // 두 개 단어의 우선순위를 비교하는 함수 operator
        // 이 함수는 아래 우선순위큐에 객체를 pq.push(p)할 때 우선순위 결정을 위해 호출 됨
        // e1, e2는 아래 우선순위큐 pq에 저장된 임의의 두 원소임
        bool operator()(PairStrInt& e1, PairStrInt& e2) {
            return (e1.second < e2.second) ||
                   (e1.second == e2.second && e2.first < e1.first);
            // (e1의 출현회수가 e2의 출현횟수 보다 작으면) true를 또는
            // (출현횟수가 같을 경우 이름이 작으면) true를 반환한다. 
            // 이렇게 반환하면 우선순위큐에선 결국 출현횟수(second)가 높은 순으로 정렬되며 
            // 출현횟수가 같으면 단어이름(first) 순서로 정렬됨
        }
    };
    // 우선순위큐< 삽입할 데이터 구조, 삽입된 데이터를 보관할 컨테이너, 비교함수를 가진 클래스 >
    priority_queue< PairStrInt, vector< PairStrInt >, CountComp > pq;
    for (auto p: wordCountMap)
        pq.push(p); // 우선순위큐에 < 단어이름, 출현횟수 > p를 삽입 (우선순위에 따라 자동 정렬됨)

    // 출현횟수가 가장 많은 10개의 단어를 출력함
    cout << "\n=== Top 10 word count ===" << endl;

    // 아래 pq.pop()은 우선순위큐에서 우선순위가 가장 높은 객체를 제거(삭제)함
    for (int i = 0; i <  10 && !pq.empty(); pq.pop(), ++i) {
        // 아래 top()은 (우선순위큐에서 삭제하지는 않고) 우선순위가 가장 높은 객체를 얻어 옴 
        PairStrInt p = pq.top(); 
        cout << p.first << ": " << p.second << endl;
    }
```

### 문제 3-2 실행 결과
```
1 12 1 6
8        // Top10WordCount
=== Word count in alphabetical order ===
': 2
...      // 기존 [문제 3-1] 실행 결과와 동일
we: 5

=== Top 10 word count ===
the: 70
,: 65
in: 34   // in과 of는 출현횟수가 동일하며 이 경우 단어이름 순서로 출력됨
of: 34
to: 29
so: 21
.: 20
Indian: 18
much: 16
and: 15
```

### 문제 4 설명
```
앞 과제 "10장 문제-2"의 [문제 0-1]에서 기존 PersonManager 클래스에 있던 
display()와 copyPersons()를 부모 클래스인 BasePM 클래스로 옮겼었다. 
---------------------------------------------------------------------------
CppSTL의 부모 클래스 BasePM에 있는 copyPersons() 함수를 
CppSTL::run()의 func_arr[]에 추가하라. 1번 메뉴 항목인 display() 등록을 참고하라.
```

### 문제 4 실행 결과
```
1 12  // C++STL
9     // CopyPersons
display(): count 32
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
...
[15] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
[16] pp0 30 71 true :Gwangju Nam-gu Bongseon-dong 21:
[17] pp1 31 62.1 false :Jong-ro 1-gil, Jongno-gu, Seoul:
[18] pp2 32 53.2 true :1001, Jungang-daero, Yeonje-gu, Busan:
...
[30] aa3 63 52.9 true :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[31] aa4 64 67.6 false :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
```