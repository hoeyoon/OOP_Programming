#include <iostream>
#include <iomanip>
using namespace std;

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
};


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
