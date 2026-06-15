#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class VoteCounter {
    // [제공] 멤버 변수
    vector< string> log;       // 투표가 들어온 순서 기록 (후보 이름)
    map< string, int> tally;   // 집계: 후보별 득표수 < 후보이름, 득표수>

public:
    // [제공] 생성자
    VoteCounter() {
        cout << "Vote tally started" << endl;   // 투표 집계 시작
    }

    // [제공] log 벡터에 저장된 모든 투표자를 "[Vote log] Kim Lee ..." 형식으로 출력
    void print() {
        cout << "[Vote log]";                   // 투표 순서
        for (size_t i = 0; i < log.size(); i++)
            cout << " " << log[i];
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    // 아래 구현할 함수의 매개변수와 리턴 타입은 main의 호출 문장을 참고하여 작성하시오.
    //-----------------------------------------------------------------------------
    // [1] 투표를 처리하는 멤버함수 vote(name)을 정의하시오.
    //     - log 벡터의 끝에 name을 추가하시오.
    //     - tally에서 name의 득표수를 1 증가시키시오.
    void vote(string& name){
    	log.push_back(name);
    	tally[name]++;
    }

    // [2] 특정 후보의 득표수를 리턴하는 멤버함수 getVotes(name)을 정의하시오.
    //     - tally에 name이 없으면 0을 리턴하시오.
    //     - 있으면 해당 후보의 득표수를 리턴하시오.
    int getVotes(string& name){
    	map< string, int>::iterator it;
    	if((it = tally.find(name)) != tally.end()){
    		return it->second;
    	}
    	return 0;
    }

    // [3] 집계 결과를 출력하는 멤버함수 result()를 정의하시오.
    //     - "[Result]"(집계 결과)를 출력한 후
    //     - tally를 반복자(iterator)로 순회하며
    //       "name: N votes" (이름: N표) 형식으로 한 줄씩 출력하시오.
    //       (map은 이름(키)의 오름차순으로 자동 정렬되어 있다.)
    void result(){
    	cout << "[Result]" << endl;
    	for(auto it : tally){
    		cout << it.first << ": " << it.second << " votes" << endl;
    	}
    }

    // [4] 득표수 순위를 출력하는 멤버함수 ranking()을 정의하시오.
    //     - 반복자로 tally를 순회하며 각 후보의 득표수(it->second)를
    //       vector< int> counts에 추가한다.
    //     - 벡터 counts를 오름차순 정렬하시오.
    //     - "[Ranking]"(순위)을 출력한 후, 정렬된 counts를 뒤에서 앞으로(높은 득표수부터) 살펴보며
    //        (counts에서 같은 득표수는 한 번만 처리 — 직전 값과 같으면 건너뜀)
    //        그 득표수를 가진 후보자들을 tally에서 찾아 아래 출력 양식으로 출력하시오.
    //        (반복자로 순회하며 같은 득표수를 가진 후보를 계속 출력)
    //        (map은 이름 오름차순이므로 같은 득표수를 가진 후보는 이름순으로 출력됨)
    //     - "N: name (M votes)" (N위: 이름 (M표)) 형식으로 한 줄씩 출력하시오. (1위부터)
    void ranking(){
    	vector<int> counts;
		for(auto it : tally){
			counts.push_back(it.second);
		}
		sort(counts.begin(), counts.end());
		cout << "[Ranking]" << endl;

		int s = 1;
		for(int i = counts.size() - 1; i >= 0; i--){
			for(auto it : tally){
				if(it.second == counts[i] && counts[i] != counts[i - 1]){
					cout << s++ << " :" << it.first << " (" << it.second << " votes)" << endl;
				}
			}
		}
    }

};

// [제공] main(): 메뉴 1~4에 따라 각 기능을 호출
//-----------------------------------------------------------------------------
//        ※ 수정 금지 : 수정할 경우 0점 처리함
//-----------------------------------------------------------------------------
int main() {
    VoteCounter vc;
    vector< string> names = { "Kim", "Lee", "Kim", "Park", "Lee" };   // 기본 투표자 명단

    while (true) {
        cout << endl << "menu: 0.exit 1.vote 2.getVotes 3.result 4.ranking 5.setVoters >> ";
        int item;
        cin >> item;
        if (item == 0) break;

        // 아래 각 case별로 주석을 푼 후 한 문제씩 순서적으로 해결하면 쉽게 문제를 풀 수 있고
        // 또한 각 case별로 문제를 푼 후 제출해도 부분 점수 있음

        switch (item) {

            case 1:                                   // names의 이름들로 연속 투표
                for (size_t i = 0; i < names.size(); i++)
                    vc.vote(names[i]);   // 해당 후보 이름으로 투표함
                vc.print();
                break;


            case 2: {
                string name;
                cout << "Candidate to check>> ";    // 득표수를 조회할 후보
                cin >> name;
                cout << name << ": " << vc.getVotes(name) << " votes" << endl;   // 이름: N표
                break;
            }


            case 3:
                vc.result(); // 후보별 득표수 출력
                break;


            case 4:
                vc.ranking();  // 높은 득표수 순위별로 후보 이름 출력
                break;

            case 5:                                   // 투표자 이름들을 한 번에 입력받아 저장
                cin.ignore();   // 직전 cin >> item이 남긴 개행 제거
                names.clear();
                while (true) {  // 투표할 후보 이름을 순서적으로 입력 받아 저장
                    string name;
                    cout << "voter [Enter to end]>> ";   // 투표할 후보 이름 (Enter: 입력 종료)
                    getline(cin, name);
                    if (name.empty()) break;
                    names.push_back(name);
                }
                break;
        }
    }
    cout << endl << "Good bye!!" << endl;
}
