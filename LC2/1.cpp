#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------
// 쿠폰 지갑 클래스
//-------------------------------------------------
class CouponWallet {
private:
    int fixed;      // 정액 할인 금액
    int percent;    // 퍼센트 할인율

public:
    //-------------------------------------------------
    // 생성자
    // fixed와 percent를 초기화한다.
    // percent가 100보다 크면 100으로 보정한다.
    //-------------------------------------------------
    CouponWallet(int fixed = 0, int percent = 0) {
        this->fixed = fixed;
        this->percent = percent;

        if (this->percent > 100) {
            this->percent = 100;
        }
    }

    //-------------------------------------------------
    // 현재 fixed 값을 반환한다.
    //-------------------------------------------------
    int getFixed() {
        return fixed;
    }

    //-------------------------------------------------
    // 현재 percent 값을 반환한다.
    //-------------------------------------------------
    int getPercent() {
        return percent;
    }

    //-------------------------------------------------
    // 문제 1
    // getDiscount() 함수를 구현하라.
    //
    // 조건:
    // 1. 상품 가격 price가 주어졌을 때 할인 금액을 계산한다.
    //
    //    할인금액 = fixed + price * percent / 100
    //
    // 2. 모든 계산은 정수 연산으로 처리한다.
    // 3. 할인금액이 상품 가격보다 크면 상품 가격을 반환한다.
    // 4. 그렇지 않으면 계산된 할인금액을 반환한다.
    //-------------------------------------------------
    int getDiscount(int price) {
        //===================
        // 문제 1의 구현
    	int dis = fixed + price * percent / 100;
    	if(dis > price){
    		return price;
    	}
        return fixed + price * percent / 100;
        //===================
    }

    //-------------------------------------------------
    // 문제 2
    // CouponWallet operator+(CouponWallet op2)를 구현하라.
    //
    // 조건:
    // 1. 두 쿠폰 지갑을 병합한다.
    // 2. fixed는 서로 더한다.
    // 3. percent도 서로 더한다.
    // 4. percent가 100보다 크면 100으로 보정한다.
    // 5. 병합 결과를 가진 새로운 CouponWallet 객체를 반환한다.
    //-------------------------------------------------
    CouponWallet operator+(CouponWallet op2) {
        //===================
        // 문제 2의 구현
    	CouponWallet tmp;
    	tmp.fixed = this->fixed + op2.fixed;
    	tmp.percent = this->percent + op2.percent;
    	if(tmp.percent > 100){
    		tmp.percent = 100;
    	}
        return tmp;
        //===================
    }

    //-------------------------------------------------
    // 문제 3
    // CouponWallet& operator<<(int amount)를 구현하라.
    //
    // 조건:
    // 1. 현재 쿠폰 지갑의 fixed에 amount를 더한다.
    // 2. 자기 자신의 참조를 반환한다.
    // 3. current << a << b 형태로 연속 사용이 가능해야 한다.
    //-------------------------------------------------
    CouponWallet& operator<<(int amount) {
        //===================
        // 문제 3의 구현
    	this->fixed += amount;

        return *this;
        //===================
    }

    //-------------------------------------------------
    // 문제 4
    // friend CouponWallet operator+(int bonus, CouponWallet op2)를 구현하라.
    //
    // 조건:
    // 1. bonus + wallet 형태의 연산을 가능하게 한다.
    // 2. bonus 값을 op2의 fixed에 추가한다.
    // 3. 변경된 쿠폰 지갑 객체를 반환한다.
    //-------------------------------------------------
    friend CouponWallet operator+(int bonus, CouponWallet op2);

    //-------------------------------------------------
    // 문제 5
    // friend bool operator==(CouponWallet op1, CouponWallet op2)를 구현하라.
    //
    // 조건:
    // 1. 두 쿠폰 지갑의 fixed가 같고,
    // 2. percent도 같으면 true를 반환한다.
    // 3. 그렇지 않으면 false를 반환한다.
    //-------------------------------------------------
    friend bool operator==(CouponWallet op1, CouponWallet op2);
};

//-------------------------------------------------
// 문제 4 구현 위치
//-------------------------------------------------
CouponWallet operator+(int bonus, CouponWallet op2) {
    //===================
    // 문제 4의 구현
	op2.fixed += bonus;
    return op2;
    //===================
}

//-------------------------------------------------
// 문제 5 구현 위치
//-------------------------------------------------
bool operator==(CouponWallet op1, CouponWallet op2) {
    //===================
    // 문제 5의 구현
	if(op1.fixed == op2.fixed && op1.percent == op2.percent){
		return true;
	}
    return false;
    //===================
}

//-------------------------------------------------
// 아래 코드는 수정 불가
//-------------------------------------------------
int main() {
    int initFixed;
    int initPercent;

    cin >> initFixed >> initPercent;

    CouponWallet current(initFixed, initPercent);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;

        if (command == "MERGE") {
            int f;
            int p;

            cin >> f >> p;

            current = current + CouponWallet(f, p);
        }
        else if (command == "CASH") {
            int a;
            int b;

            cin >> a >> b;

            current << a << b;
        }
        else if (command == "BONUS") {
            int x;

            cin >> x;

            current = x + current;
        }
        else if (command == "BUY") {
            int price;

            cin >> price;

            cout << current.getDiscount(price) << endl;
        }
        else if (command == "CHECK") {
            int f;
            int p;

            cin >> f >> p;

            if (current == CouponWallet(f, p)) {
                cout << "SAME" << endl;
            }
            else {
                cout << "DIFFERENT" << endl;
            }
        }
        else if (command == "PRINT") {
            cout << current.getFixed() << " " << current.getPercent() << endl;
        }
    }

    return 0;
}
//-------------------------------------------------
// 소스 코드 종료
//-------------------------------------------------
