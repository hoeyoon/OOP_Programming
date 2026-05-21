# OJ CH9_1_liveCoding
### 문제 설명
```
추상 클래스와 상속을 사용하여 패키지의 크기를 비교하는 프로그램을 작성하고자 한다

① AbstractItem 추상 클래스:  패키지를 비교하고 정보를 얻는 데 필요한 메서드compareTo,
    getSize, getName 메서드는 추상 메서드로 선언되어 있으며, 파생 클래스에서 구현

② ConcretePackage 클래스: AbstractItem 클래스를 상속받아 구현된 클래스래스로 
     패키지의 이름(name), 길이(length), 너비(width), 높이(height)를
     멤버 변수로 가지고 있고, 생성자를 통해 정보를 초기화한다  
  - getSize 메서드는 패키지의 부피를 계산하여 반환(부피= 길이*너비* 높이)
  - getName 메서드는 패키지의 이름을 반환
  - compareTo 메서드는 다른 패키지와의 크기를 비교하여, 같으면 0, 작으면 -1, 크면 1을 반환

③ main 함수:
   - AbstractItem 포인터 배열을 선언하여 패키지 객체를 저장
   - 사용자로부터 패키지의 이름, 길이, 너비, 높이를 입력받아 ConcretePackage 객체를 생성
      하고 배열에 저장
    - 첫 번째 패키지와 나머지 패키지를 비교하여 결과를 출력(비교는 compareTo 메서드를 
    사용)

** 제공된 기본 소스는 변경할 수 없다
```
### 입출력 형식
```
패키지 3개 생성(이름 길이 너비 높이 입력) =>
pk1 4 3 6
pk2 2 4 4
pk3 4 6 9
패키지 크기 비교 =>
pk1 > pk2
pk1 < pk3
```

### 소스코드
```c++
// include <   > 사이의 공백을 제거하세요
#include < iostream>
using namespace std;

// 추상 클래스 AbstractItem 정의
class AbstractItem {
public:
    // 추상 메서드로 compareTo 정의
    virtual int compareTo(AbstractItem* other) const = 0;
    // 추상 메서드로 getSize 정의
    /*              */
    // 추상 메서드로 getName 정의
    /*                */
    // 가상 소멸자
   /*                  */
};

// ConcretePackage 클래스는 AbstractItem 클래스를 상속
class ConcretePackage : public AbstractItem {
private:
    string name; // 패키지의 이름
    int length, width, height; // 패키지의 길이, 너비, 높이

public:
    // 생성자
    ConcretePackage(string n, int l, int w, int h) : name(n), length(l), width(w), height(h) {}

    // 패키지의 부피를 계산하여 반환하는 메서드
    /*                     */

    // 패키지의 이름을 반환하는 메서드
    /*                       */

    // 다른 패키지와의 크기를 비교하는 메서드
     /*                         */

int main() {
    // 패키지 포인터 배열 선언
    AbstractItem* packages[3];

    cout << "패키지 3개 생성(이름 길이 너비 높이 입력) =>" << endl;
    for (int i = 0; i < 3; ++i) {
        string n;
        int l, w, h;
        cin >> n >> l >> w >> h; // 사용자로부터 입력 받음
        packages[i] = new ConcretePackage(n, l, w, h); // 패키지 객체 생성 및 배열에 추가
    }

    cout << "패키지 크기 비교 =>" << endl;

     string firstName = packages[0]->getName(); // 첫 번째 패키지의 이름
    for (int i = 1; i < 3; ++i) {
        /*                            */                      // 현재 패키지의 이름
        /*                             */                       // 첫 번째 패키지와 비교
        // 비교 결과에 따라 출력
       /*

        */

    // 메모리 해제(동적으로 할당된 패키지 객체 삭제)
  /*

   */

    return 0;
}
```