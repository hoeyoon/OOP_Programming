#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 클래스 템플릿: 임의의 자료형 T 값들을 저장하고 처리
template <typename T>
class DataSet {
public:
    // [제공] 멤버 변수: arr는 값 저장 배열(최대 SIZE개), count는 현재 저장된 개수
    static constexpr int SIZE = 4;
    T arr[SIZE];
    int count;

    // [제공] 생성자: values 벡터의 모든 원소에 start를 더해 arr[]에 저장한 후 출력
    DataSet(vector<T>& values, const T start) {
        count = 0;
        for (size_t i = 0; i < values.size(); ++i)
            add((T)(values[i] + start));
        print();
    }

    // [제공] 저장된 값들의 개수
    int size() { return count; }

    // [제공] arr[idx]의 참조자를 리턴
    T& operator [] (int idx) { return arr[idx]; }

    // [제공] 저장된 값들을 "[data] v1 v2 ..." 형식으로 한 줄에 출력
    void print() {
        cout << "[data]";
        for (int i = 0; i < count; i++) cout << " " << arr[i];
        cout << endl;
    }

    //--------------------------------------------------
    // 아래 구현할 함수의 매개변수와 리턴 타입은 main의 호출 문장과
    // 위 [제공] 함수를 참고하여 작성하시오.
    //--------------------------------------------------
    // [1] 값 x를 배열 끝에 추가하는 멤버함수 add(x)를 정의하시오.
    //     - 가득 차 있으면(count가 SIZE 이상) 아무 일도 하지 않고 그냥 리턴한다.
    //     - 그렇지 않으면 arr[count] 위치에 x를 저장하고 count를 1 늘린다.

    // [2] 저장된 모든 값의 합계를 리턴하는 멤버함수 sum()을 정의하시오.
    //     - arr에 저장된 count 개의 원소 값들을 모두 더하여 리턴하시오.

    // [3] 값 v를 검색하여 그 인덱스를 리턴하는 멤버함수 find(v)를 정의하시오.
    //     - 찾았을 경우 해당 배열 인덱스를 리턴하시오.
    //     - 못 찾았을 경우 -1을 리턴하시오.
    void add(T x){
    	if(count >= SIZE){
    		return;
    	}
    	arr[count] = x;
    	count++;
    }

    T sum(){
    	T s = 0;
    	for(int i = 0; i < count; i++){
    		s += arr[i];
    	}
    	return s;
    }
    int find(string& v){
    	int i;
    	for(i = 0; i < count; i++){
    		if(arr[i] == v){
    			return i;
    		}
    	}
    	return -1;
    }
};

// [4] dataSet의 원소 중 최솟값과 최댓값을 찾아 매개변수 min, max에 담는
//     전역 템플릿 함수 minMax(dataSet, min, max)를 정의하시오.
//     - dataSet[i] (operator[])와 dataSet.size()를 사용하여 모든 원소를 순회한다.
//     - 매개변수와 리턴 타입은 main의 호출 문장을 참고하여 직접 작성하시오.
template<typename T>
void minMax(DataSet<T>& s, char& min, char& max){
	min = s.arr[0];
	max = s.arr[0];
	for(int i = 0; i < s.size(); i++){
		if(max < s.arr[i]){
			max = s.arr[i];
		}
		if(min > s.arr[i]){
			min = s.arr[i];
		}
	}
}


// [제공] main(): 메뉴 1~4에 따라 자료형별 DataSet을 생성·실행
//-----------------------------------------------------------------------------
//        ※ 수정 금지 : 수정할 경우 0점 처리함
//-----------------------------------------------------------------------------
int main() {
    double start = 0;   // 각 원소에 더할 값(기본 0). 메뉴 5에서 변경
    while (true) {
        cout << endl << "menu: 0.exit 1.add 2.sum 3.find 4.minMax 5.setStart >> ";
        int item;
        cin >> item;
        if (item == 0) break;

        // 아래 각 case별로 주석을 푼 후 한 문제씩 순서적으로 해결하면 쉽게 문제를 풀 수 있음
        // 각 case별로 문제 푼 후 제출해도 부분 점수 있음

        switch (item) {

        case 1: {                                 // int 벡터로 생성 (add: SIZE 초과분 무시 확인)
            vector<int> values = { 0, 1, 2, 3, 4 };
            DataSet<int> ds(values, start);
            break;
        }


        case 2: {                                 // double 벡터로 생성 후 합계 출력
            vector< double> values = { 0.5, 1.5, 2.5, 3.5 };
            DataSet< double> ds(values, start);
            cout << "sum: " << ds.sum() << endl;   // 전체 합 출력
            break;
        }


        case 3: {                                 // string 벡터로 생성 후 단어 검색
            vector< string> values = { "abc", "def", "ghi", "jkl" };
            DataSet< string> ds(values, to_string((int)start));
            cout << "word to find >> ";            // 검색할 단어 입력
            string word;
            cin >> word;
            cout << "found index: " << ds.find(word) << endl;   // 찾은 인덱스 (없으면 -1)
            break;
        }


        case 4: {                                 // char 벡터로 생성 후 최소·최대 출력
            vector< char> values = { 'a', 'b', 'c', 'd', 'e', 'f' };
            DataSet< char> ds(values, start);
            char min, max;
            minMax(ds, min, max);                  // 최솟값·최댓값 구하기
            cout << "min: " << min << ", max: " << max << endl;
            break;
        }

        case 5:                                   // 각 원소에 더할 값 start 입력
            cout << "start value to add >> ";
            cin >> start;
            break;
        }
    }
    cout << endl << "Good bye!!" << endl;
}
