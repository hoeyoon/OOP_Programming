#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Book {
    string title;   // 책 제목
    int isbn;       // ISBN 번호
    double price;   // 가격
    bool isNovel;   // 소설 책이니?

public:
    Book(string t = "", int i = 0, double p = 0, bool n = false) {
        title = t; isbn = i; price = p; isNovel = n;
    }
    ostream& print(ostream& out) const {
        return out << title << " " << isbn << " " << price << " " << isNovel;
    }
    void println() const { print(cout) << endl; }
    ostream& printFormat(ostream& out){
    	out << left << setw(10) << setfill('*') << title << ":" << showbase << hex << isbn << ":" <<
    			dec << setw(0) << setfill(' ') << setprecision(3) << price << ":" << setprecision(6) << boolalpha << isNovel << noboolalpha;
    	return out;
    }
    
    friend ostream& operator << (ostream& out, const Book& ref);
    friend istream& operator >> (istream& in, Book& ref);
};

// 여기에 필요한 함수들을 구현하시오.
ostream& operator << (ostream& out, const Book& ref){
	out << ref.title << " " << ref.isbn << " " << ref.price << " " << ref.isNovel;
	return out;
}

ostream& outPrompt(ostream& out){
	out << "Book: ";
	return out;
}

istream& operator >> (istream& in, Book& ref){
	in >> ref.title >> ref.isbn >> ref.price >> ref.isNovel;
	return in;
}

istream& inPrompt(istream& in){
	cout << "title ISBN price isNovel? ";
	return in;
}

//------------------------------------------------------
// 경고: 아래 함수들은 주석을 제거하는 것 외는 수정하지 마시오.
//        만약 본인의 임의대로 아래 함수를 수정할 경우 0점 처리함.
//------------------------------------------------------
int main() {
    Book books[] = {
         Book("book_A", 1234,  4./3, true),
         Book("B", 2345,  9./3, false),
         Book("title", 3456,  5.5/3, true),
    };
    int menu, index = 0;
    while (true) {
        cout << "menu item [0 ~ 6]? ";
        cin >> menu;
        if (menu == 0) break;
        else if (menu == 2) { // 조작자 outPrompt 구현
            cout << outPrompt;
        }
        else if (menu == 3) { // 연산자 >> books[index] 구현
            cout << "title ISBN price isNovel? ";
            cin >> books[index];
        }
        else if (menu == 4) { // 조작자 inPrompt 구현
            cin >> inPrompt >> books[index];
        }
        else if (menu == 5) { // 멤버함수 printFormat(cout) 구현
            cout << books[index] << endl;
            books[index].printFormat(cout) << endl;  // book의 멤버들을 순서적으로 출력함
        }
        else if (menu == 6) {
            cout << "book index to select [0,1,2]? ";
            cin >> index;
        }
        cout << books[index] << endl << endl;  // 연산자 << books[index] 구현
    }
    cout << "\nGood bye!!" << endl;
}
