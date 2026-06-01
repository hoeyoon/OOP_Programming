# OJ CH10_2_liveCoding

### 문제 설명
```
문자열을 입력받아 문자열의 길이를 출력하는 프로그램을 작성하시오.
각각의 문자열은 입력하였을 때 string 자료형에 입력받고
string 자료형을 저장할 수 있는 STL 컨테이너 vector에 삽입한다.
그 후 문자열의 길이의 출력은 for_each와 람다식을 사용하여 출력한다.

**아래 사항은 반드시 지킬것
- vector 컨테이너의 순회는 for_each를 사용
- 출력은 반드시 람다식을 사용
```

### 실행 결과
```
예제 - 1
<출력>문자열을 최대 5개 입력하세요:
<출력>문자열 1: <입력> apple
<출력>문자열 2: <입력> banana
<출력>문자열 3: <입력> orange
<출력>문자열 4: <입력> mango
<출력>문자열 5: <입력> kiwi
<출력>각 문자열의 길이:
<출력>apple의 길이: 5
<출력>banana의 길이: 6
<출력>orange의 길이: 6
<출력>mango의 길이: 5
<출력>kiwi의 길이: 4

예제 - 2
<출력>문자열을 최대 5개 입력하세요:
<출력>문자열 1: <입력> hello
<출력>문자열 2: <입력> world
<출력>문자열 3: <입력> hello
<출력>문자열 4: <입력> programming
<출력>문자열 5: <입력> language
<출력>각 문자열의 길이:
<출력>hello의 길이: 5
<출력>world의 길이: 5
<출력>hello의 길이: 5
<출력>programming의 길이: 11
<출력>language의 길이: 8

예제 - 3
<출력>문자열을 최대 5개 입력하세요:
<출력>문자열 1: <입력> programming
<출력>문자열 2: <입력> language
<출력>문자열 3: <입력> is
<출력>문자열 4: <입력> fun
<출력>문자열 5: <입력> tolearn
<출력>각 문자열의 길이:
<출력>programming의 길이: 11
<출력>language의 길이: 8
<출력>is의 길이: 2
<출력>fun의 길이: 3
<출력>tolearn의 길이: 7
```

### 소스코드
```c++
#include < iostream> //공백지우고 활용
#include < vector> //공백지우고 활용
#include < algorithm> //공백지우고 활용 
#define MAX_SIZE  5
using namespace std;


int main() {

     strVec;

    // 문자열 입력 받기
    cout << "문자열을 최대 " << MAX_SIZE << "개 입력하세요:" << endl;
    for (int i = 0; i < MAX_SIZE; ++i) {
        string str;
        cout << "문자열 " << i + 1 << ": ";
        cin >> str;
        //vector에 삽입하는 코드 필요
    }

    cout << "각 문자열의 길이:" << endl;
    for_each( , ,[  ](  ){  });
    // string 자료형의 문자열 길이를 구하는 함수는 .length() 이다.
    return 0;
}

```