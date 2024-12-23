#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

const int N = 600;
string command;
string employeeNames[N];
string encodedBits;
map<string, int> IdMap;
vector<int> sons[N];
vector<int> order;
int currentIdIndex, hasSupervisor[N], supervisor[N];

int getId(const string& employeeName) {
    if (IdMap.count(employeeName)) {
        return IdMap[employeeName];
        }
    return IdMap[employeeName] = ++currentIdIndex;
}

void _sort(const int& currentEmployee) {
    order.push_back(currentEmployee);
    for (auto subordinate : sons[currentEmployee]) {
        encodedBits += "1";
        _sort(subordinate);
        encodedBits += "0";
    }
}

int main() {
    int i;
    cin >> command;
    cin.ignore();

    if (command == "ENCODE") {
        string input;
        while (getline(cin, input)) {
            int delimiterPos;
            string supervisorName;
            vector<int> spacePositions;
            for (i = 0; i < input.size(); ++i) {
                if (input[i] == ':') supervisorName = input.substr(0, i);
                if (input[i] == ' ') spacePositions.push_back(i);
            }
            int currentEmployee = getId(supervisorName);
            for (i = 0; i < spacePositions.size(); ++i) {
                string subordinateName = input.substr(spacePositions[i] + 1, 
                    (i + 1 < spacePositions.size() ? spacePositions[i + 1] : input.size()) - spacePositions[i] - 1);
                int nextEmployee = getId(subordinateName);
                sons[currentEmployee].push_back(nextEmployee);
                hasSupervisor[nextEmployee] = 1;
            }
        }
        for (auto [employeeName, employeeId] : IdMap) employeeNames[employeeId] = employeeName;
        int rootEmployee;
        for (i = 1; i <= currentIdIndex; ++i) if (!hasSupervisor[i]) { rootEmployee = i; break; }
        _sort(rootEmployee);
        for (auto employeeId : order) cout << employeeNames[employeeId] << endl;
        cout << encodedBits << endl;

    } else {
        string input;
        int numEmployees = 0;
        while (getline(cin, input)) {
            if (input[0] == '0' || input[0] == '1') break;
            employeeNames[++numEmployees] = input;
        }
        int currentEmployee = 1, previousEmployee = 1;
        for (i = 0; i < input.size(); ++i) {
            if (input[i] == '1') {
                ++currentEmployee;
                sons[previousEmployee].push_back(currentEmployee);
                supervisor[currentEmployee] = previousEmployee;
                previousEmployee = currentEmployee;
            } else {
                previousEmployee = supervisor[previousEmployee];
            }
        }
        for (i = 1; i <= numEmployees; ++i) if (!sons[i].empty()) {
            cout << employeeNames[i] << ":";
            for (auto subordinate : sons[i]) cout << " " << employeeNames[subordinate];
            cout << endl;
        }
    }
    return 0;
}
