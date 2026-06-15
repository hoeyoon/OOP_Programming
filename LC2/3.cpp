#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------
// 추상 클래스 SmartDevice
//-------------------------------------------------
class SmartDevice {
private:
    SmartDevice* next;      // 다음 기기를 가리키는 포인터

protected:
    string name;            // 기기 이름

    // 순수 가상 함수
    // 파생 클래스에서 반드시 오버라이딩해야 한다.
    virtual void operate() = 0;

public:
    // 생성자
    SmartDevice(const string& name) {
        this->name = name;
        next = nullptr;
    }

    // 가상 소멸자
    // 기본 클래스 포인터로 파생 클래스 객체를 delete할 수 있으므로 virtual 필요
    virtual ~SmartDevice() { }

    // 기기 실행 함수
    // 내부에서 operate()를 호출한다.
    // operate()는 순수 가상 함수이지만,
    // 실제 실행 시에는 파생 클래스에서 오버라이딩한 operate()가 호출된다.
    void turnOn();

    // 현재 기기 뒤에 새 기기를 연결한다.
    SmartDevice* add(SmartDevice* device);

    // 다음 기기 주소를 리턴한다.
    SmartDevice* getNext() {
        return next;
    }

    // 기기 이름을 리턴한다.
    string getName() {
        return name;
    }
};

//-------------------------------------------------
// SmartDevice의 멤버 함수 구현
//-------------------------------------------------

// 문제 1
// turnOn() 함수를 구현하라.
// 이 함수는 순수 가상 함수 operate()를 호출해야 한다.
void SmartDevice::turnOn() {
    //===================
    // 문제 1의 구현
	operate();
    //===================
}

// 문제 2
// add() 함수를 구현하라.
// 현재 객체의 next가 매개변수 device를 가리키도록 연결하고,
// 연결한 device의 주소를 리턴하라.
SmartDevice* SmartDevice::add(SmartDevice* device) {
    //===================
    // 문제 2의 구현
	this->next = device;
    return device;
    //===================
}

//-------------------------------------------------
// 파생 클래스 Light
//-------------------------------------------------
class Light : public SmartDevice {
private:
    int brightness;     // 밝기

protected:
    // SmartDevice의 순수 가상 함수 operate() 오버라이딩
    void operate() override;

public:
    Light(const string& name, int brightness)
        : SmartDevice(name) {
        this->brightness = brightness;
    }
};

// 문제 3
// Light의 operate() 함수를 구현하라.
// 출력 형식:
// [조명] livingLight 밝기 80%로 켭니다.
void Light::operate() {
    //===================
    // 문제 3의 구현
	cout << "[조명] " << name << " 밝기 " << brightness << "%로 켭니다." << endl;
    //===================
}

//-------------------------------------------------
// 파생 클래스 AirConditioner
//-------------------------------------------------
class AirConditioner : public SmartDevice {
private:
    int temperature;    // 목표 온도

protected:
    // SmartDevice의 순수 가상 함수 operate() 오버라이딩
    void operate() override;

public:
    AirConditioner(const string& name, int temperature)
        : SmartDevice(name) {
        this->temperature = temperature;
    }
};

// 문제 4
// AirConditioner의 operate() 함수를 구현하라.
// 출력 형식:
// [에어컨] bedroomAircon 목표 온도 24도로 냉방합니다.
void AirConditioner::operate() {
    //===================
    // 문제 4의 구현
	cout << "[에어컨] " << name << " 목표 온도 " << temperature << "도로 냉방합니다." << endl;
    //===================
}

//-------------------------------------------------
// 파생 클래스 RobotCleaner
//-------------------------------------------------
class RobotCleaner : public SmartDevice {
private:
    int minutes;        // 청소 시간

protected:
    // SmartDevice의 순수 가상 함수 operate() 오버라이딩
    void operate() override;

public:
    RobotCleaner(const string& name, int minutes)
        : SmartDevice(name) {
        this->minutes = minutes;
    }
};

// 문제 5
// RobotCleaner의 operate() 함수를 구현하라.
// 출력 형식:
// [로봇청소기] cleaner 30분 동안 청소합니다.
void RobotCleaner::operate() {
    //===================
    // 문제 5의 구현
	cout << "[로봇청소기] " << name << " " << minutes << "분 동안 청소합니다." << endl;
    //===================
}

//-------------------------------------------------
// 스마트 홈 전체를 관리하는 클래스
//-------------------------------------------------
class SmartHome {
private:
    SmartDevice* first;     // 첫 번째 기기
    SmartDevice* last;      // 마지막 기기
    int count;              // 등록된 기기 수

public:
    // 생성자
    SmartHome() {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    // 소멸자
    // 등록된 모든 기기를 삭제한다.
    ~SmartHome() {
        SmartDevice* p = first;

        while (p != nullptr) {
            SmartDevice* q = p->getNext();
            delete p;
            p = q;
        }
    }

    // 새 기기 등록
    void addDevice(SmartDevice* device) {
        if (first == nullptr) {
            first = device;
            last = device;
        }
        else {
            last = last->add(device);
        }

        count++;
        cout << device->getName() << " 등록 완료" << endl;
    }

    // 등록된 기기 목록 출력
    void showDevices() {
        if (first == nullptr) {
            cout << "등록된 기기가 없습니다." << endl;
            return;
        }

        cout << "등록된 기기 목록" << endl;

        SmartDevice* p = first;
        int index = 1;

        while (p != nullptr) {
            cout << index << ". " << p->getName() << endl;
            p = p->getNext();
            index++;
        }
    }

    // 등록된 모든 기기 실행
    void runAll() {
        if (first == nullptr) {
            cout << "실행할 기기가 없습니다." << endl;
            return;
        }

        cout << "전체 기기를 실행합니다." << endl;

        SmartDevice* p = first;

        while (p != nullptr) {
            p->turnOn();
            p = p->getNext();
        }
    }
};

//-------------------------------------------------
// 아래 코드는 수정 불가
//-------------------------------------------------
int main() {
    SmartHome home;

    while (true) {
        cout << endl
            << "menu: 0.exit 1.addLight 2.addAircon 3.addCleaner 4.showDevices 5.runAll >> ";

        int menu;
        cin >> menu;

        if (menu == 0) break;

        switch (menu) {
        case 1: {
            string name;
            int brightness;

            cout << "light name? ";
            cin >> name;

            cout << "brightness? ";
            cin >> brightness;

            home.addDevice(new Light(name, brightness));
            break;
        }

        case 2: {
            string name;
            int temperature;

            cout << "aircon name? ";
            cin >> name;

            cout << "temperature? ";
            cin >> temperature;

            home.addDevice(new AirConditioner(name, temperature));
            break;
        }

        case 3: {
            string name;
            int minutes;

            cout << "cleaner name? ";
            cin >> name;

            cout << "minutes? ";
            cin >> minutes;

            home.addDevice(new RobotCleaner(name, minutes));
            break;
        }

        case 4:
            home.showDevices();
            break;

        case 5:
            home.runAll();
            break;

        default:
            cout << "잘못된 메뉴입니다." << endl;
            break;
        }
    }

    cout << endl << "Good bye!!" << endl;
}
//-------------------------------------------------
// 소스 코드 종료
//-------------------------------------------------
