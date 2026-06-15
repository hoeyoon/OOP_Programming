#include <iostream>
#include <iomanip>
using namespace std;

//-------------------------------------------------
// 웨이팅 코드 클래스
//-------------------------------------------------
class WaitingCode {
private:
    char code[7];   // 6자리 웨이팅 코드 + 문자열 종료 문자 '\0'

public:
    WaitingCode() {
        for (int i = 0; i < 6; i++) {
            code[i] = '0';
        }
        code[6] = '\0';
    }

    //-------------------------------------------------
    // 문제 3
    // WaitingCode의 추출 연산자 >> 를 프렌드 함수로 구현하라.
    //
    // 조건:
    // 1. 입력 스트림에서 웨이팅 코드 문자 6개를 읽어 code 배열에 저장한다.
    // 2. 코드 앞에 남아 있는 공백 문자나 개행 문자는 code 배열에 저장하지 않는다.
    // 3. 문자 입력에는 istream의 멤버 함수 get()을 사용한다.
    // 4. 마지막에는 code[6]에 '\0'을 저장한다.
    // 5. 입력 스트림 in을 리턴한다.
    //
    // 입력 예:
    // A12B34
    //
    // 저장 결과:
    // code[0] = 'A'
    // code[1] = '1'
    // code[2] = '2'
    // code[3] = 'B'
    // code[4] = '3'
    // code[5] = '4'
    // code[6] = '\0'
    //-------------------------------------------------
    friend istream& operator>>(istream& in, WaitingCode& wc);

    //-------------------------------------------------
    // 문제 4
    // WaitingCode의 삽입 연산자 << 를 프렌드 함수로 구현하라.
    //
    // 조건:
    // 1. 코드는 3글자씩 끊어서 출력한다.
    // 2. 두 묶음 사이에는 '-'를 출력한다.
    // 3. 출력 스트림 out을 리턴한다.
    //
    // 출력 예:
    // A12-B34
    //-------------------------------------------------
    friend ostream& operator<<(ostream& out, const WaitingCode& wc);
};

//-------------------------------------------------
// 동명동 맛집 방문 클래스
//-------------------------------------------------
class DongmyeongRestaurant {
private:
    string restaurant;      // 식당 이름
    string menu;            // 대표 메뉴
    int waitingNumber;      // 웨이팅 번호
    double rating;          // 평점
    char seatType;          // 좌석 유형
    WaitingCode code;       // 웨이팅 코드

public:
    DongmyeongRestaurant() {
        restaurant = "";
        menu = "";
        waitingNumber = 0;
        rating = 0.0;
        seatType = 'N';
    }

    //-------------------------------------------------
    // 문제 1
    // readBasic() 함수를 구현하라.
    //
    // 이 함수는 cin과 추출 연산자 >> 를 이용하여
    // 식당 이름, 대표 메뉴, 웨이팅 번호, 평점, 좌석 유형을 입력받는다.
    //
    // 입력 순서:
    // 식당이름 대표메뉴 웨이팅번호 평점 좌석유형
    //
    // 단, 식당 이름과 대표 메뉴는 공백 없이 입력된다고 가정한다.
    //
    // 입력 예:
    // tongdakHouse chicken 27 4.856 T
    //
    // seatType 의미:
    // T: table
    // B: bar
    // O: outdoor
    //-------------------------------------------------
    void readBasic() {
        //===================
        // 문제 1의 구현
    	cin >> restaurant >> menu >> waitingNumber >> rating >> seatType;
        //===================
    }

    //-------------------------------------------------
    // 문제 2
    // printLine() 함수를 구현하라.
    //
    // 이 함수는 cout.put()을 이용하여
    // 매개변수 ch 문자를 count번 출력한 뒤 줄을 바꾼다.
    //
    // 예:
    // printLine('=', 20);
    //
    // 출력:
    // ====================
    //-------------------------------------------------
    void printLine(char ch, int count) {
        //===================
        // 문제 2의 구현
    	for(int i = 0; i < count; i++){
    		cout.put(ch);
    	}
    	cout.put('\n');
        //===================
    }

    //-------------------------------------------------
    // 웨이팅 코드 입력
    // 아래 함수는 수정하지 않는다.
    //-------------------------------------------------
    void readCode() {
        cin >> code;
    }

    //-------------------------------------------------
    // 문제 5
    // printTicket() 함수를 구현하라.
    //
    // 이 함수는 동명동 맛집 방문권을 출력한다.
    //
    // 조건:
    // 1. 웨이팅 번호는 출력 폭 5칸으로 출력한다.
    // 2. 웨이팅 번호 앞의 빈칸은 문자 '0'으로 채운다.
    // 3. 평점은 fixed 형식으로 소수점 아래 2자리까지 출력한다.
    // 4. 웨이팅 코드 출력에는 WaitingCode의 삽입 연산자 << 를 사용한다.
    // 5. 출력 형식은 실행 예시와 정확히 일치해야 한다.
    //
    // 출력 형식:
    // Restaurant : tongdakHouse
    // Menu       : chicken
    // Seat Type  : T
    // Waiting No : 00027
    // Rating     : 4.86
    // Code       : A12-B34
    //-------------------------------------------------
    void printTicket() {
        //===================
        // 문제 5의 구현
    	cout << "Restaurant : " << restaurant << endl;
    	cout << "Menu       : " << menu << endl;
    	cout << "Seat Type  : " << seatType << endl;
    	cout << "Waiting No : " << setw(5) << setfill('0') << waitingNumber << setw(3) << setfill(' ') <<  endl;
    	cout << "Rating     : " << fixed << setprecision(2) << rating << endl;
    	cout << "Code       : " << code << endl;
        //===================
    }
};

//-------------------------------------------------
// 문제 3 구현 위치
//-------------------------------------------------
istream& operator>>(istream& in, WaitingCode& wc) {
    //===================
    // 문제 3의 구현
	int i = 0;
	while(i < 6){
		int t = in.get();
		if(t != '\t' && t != '\n' && t != ' '){
			wc.code[i] = t;
			i++;
		}
	}
	wc.code[6] = '\0';
//	cout << wc.code << endl;
    return in;
    //===================
}

//-------------------------------------------------
// 문제 4 구현 위치
//-------------------------------------------------
ostream& operator<<(ostream& out, const WaitingCode& wc) {
    //===================
    // 문제 4의 구현
	for(int i = 0; i < 3; i++){
		out << wc.code[i];
	}
	out << "-";
	for(int i = 3; i < 6; i++){
		out << wc.code[i];
	}
    return out;
    //===================
}

//-------------------------------------------------
// 아래 코드는 수정 불가
//-------------------------------------------------
int main() {
    DongmyeongRestaurant visit;

    visit.readBasic();
    visit.readCode();

    visit.printLine('=', 32);
    cout << "DONGMYEONG FOOD TICKET" << endl;
    visit.printLine('=', 32);

    visit.printTicket();

    visit.printLine('=', 32);

    cout << "Enjoy your meal!" << endl;

    return 0;
}
//-------------------------------------------------
// 소스 코드 종료
//-------------------------------------------------
