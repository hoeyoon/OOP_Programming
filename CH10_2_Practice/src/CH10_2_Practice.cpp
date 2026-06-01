#include <iostream>
#include <vector>
using namespace std;

// 대량의 데이터를 순서적으로 저장하고 있는 컨테이너 클래스
class Container {
private:
	vector<int> v;

public:
	void push(int value);	// value를 컨테이너에 삽입
	void add(int inc);		// 컨테이너에 삽입된 모든 원소에 inc를 더함
	bool get(int index, int &value);// 컨테이너의 index(배열처럼 0부터 시작) 위치에 있는 원소 값을 반환
	int  find(int value);	// value 값을 가진 원소의 인덱스를 리턴함
	bool remove(int value);	// value 값을 가진 원소를 삭제하고 true 리턴, 존재하지 않으면 false
	void print();			// 컨테이너에 삽입된 모든 원소를 순서적으로 출력
};

void Container::push(int value){
	v.push_back(value);
}

void Container::add(int inc){
	for(int i = 0; i < (int)v.size(); i++){
		v[i] += inc;
	}
}

bool Container::get(int index, int &value){
	if(index < 0 || index >= (int)v.size()){
		return false;
	}
	value = v[index];
	return true;
}

int Container::find(int value){
	for(int i = 0; i < (int)v.size(); i++){
		if(v[i] == value){
			return i;
		}
	}
	return -1;
}

bool Container::remove(int value){
	vector<int>::iterator it;
	for(it = v.begin(); it != v.end(); it++){
		if(*it == value){
			v.erase(it);
			return true;
		}
	}
	return false;
}

void Container::print() {
	for (int i = 0; i < (int)v.size(); i++)
		cout << "[" << i << "]" << v[i] << " ";
	cout << endl << endl;
}

void test_int(int size) {
	Container c;

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push(min+i);
	cout << "push: ";
	c.print();

	int value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	cout << "find(" << max << "): " << c.find(max) << endl;
	cout << "find(" << min-1 << "): " << c.find(min-1) << endl << endl;

	cout << "remove(" << mid << "): " << c.remove(mid) << endl;
	c.print();

	cout << "remove(" << max+1 << "): " << c.remove(max+1) << endl;
	c.print();

	c.add(100);
	cout << "add(100): ";
	c.print();
}

int main()
{
	cout << "Enter the number of elements : " ;
	int size;
	cin >> size;
	cout << endl << "INTEGER Test" << endl << endl;
	test_int(size);
	return 0;
}	
