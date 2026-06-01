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