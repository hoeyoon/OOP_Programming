#include <iostream>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
    
    public:
	    void setRadius(int radius); // 반지름을 설정한다.
	    double getArea(); // 면적을 리턴한다.
};

void Circle::setRadius(int radius) {
/* 소스작성 */
    this->radius = radius;
}

double Circle::getArea() {
	/* 소스작성 */
    return radius * radius * 3.14;
}

int main() {
    int n;
    cout << "원의 개수 >> ";
    cin >> n;
    Circle *p = new Circle[n];
    int count = 0;

    for(int i = 0; i < n; i++){
        int rad;
        cout << "원 " << i + 1 << "의 반지름 >> ";
        cin >> rad;
        p[i].setRadius(rad);
        if(p[i].getArea() > 100){
            count++;
        }
    }
    cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;

	delete[] p; // 객체 배열 소멸
}