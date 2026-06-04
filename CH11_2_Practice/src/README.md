# OJ CH11_1_Practice
### 문제 설명
```c++
다음은 Box 클래스 정의의 일부분이다.

class Box {
private:
    string label;                     // 박스 라벨
    int permitWeight, itemWeight;     // 박스 허용용량, 박스에 담은 물품의 총 용량
public:
    Box() {
        itemWeight = 0;               
    }
    Box(string label, int weight) {
        this->label = label;
        permitWeight = weight;
        itemWeight = 0;
    }
    ...
};

다음은 main 함수의 내용이다.

int main() {
    Box box, box2("Book", 30);   //  두 개의 박스 객체 생성

    cin >> box;                  // box 객체의 label, permotWeight 입력
    cout << box;                 // box 객체의 라벨과 남은 용량 출력
    box.putItem(5);              // box 객체에 물품 용량을 추가
    cout << box;
    box.putItem(20);        // box 객체에 물품 중량 추가. 이때 남은 허용용량을 체크하고 부족하면 오류메세지 출력
    
    cout << box2;
    box2.putItem(15);
    cin >> box2;              // // 박스가 라벨과 중량을 가지고 있는 경우 This box is not empty. You .. 출력
    cout << box2;

    return 0;
}

문제 : 아래와 같이 입출력이 되도록 <<, >> 연산자를 중복정의하시오. 이때 사용자 정의 조작자 boxSign 함수를 만들어
[[[[[ BOX ]]]]] 문자열을 출력하게 하시오.
```

### 실행 결과
```
(출력)Box label and weight : (입력)Toy 20
(출력)[[[[[ BOX ]]]]]
(출력)Box label : Toy
(출력)Box available weight : 20
(출력)[[[[[ BOX ]]]]]
(출력)Box label : Toy
(출력)Box available weight : 15
(출력)This box doesn't have available space.
(출력)[[[[[ BOX ]]]]]
(출력)Box label : Book
(출력)Box available weight : 30
(출력)This box is not empty. You can change only label of this box
(출력)Box label : (입력)Food
(출력)[[[[[ BOX ]]]]]
(출력)Box label : Food
(출력)Box available weight : 15
```