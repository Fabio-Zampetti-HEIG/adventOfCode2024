#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void fillVectors(vector<int>& v1, vector<int>& v2) {
    int n, m;
    while (cin >> n >> m) {
        v1.push_back(n);
        v2.push_back(m);
    }
}

int sumDistanceOfLists(vector<int>& list1, vector<int>& list2) {
    int sum = 0;
    for (size_t i = 0; i < list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }
    return sum;
}

bool AreListsEqualSize(vector<int>& list1, vector<int>& list2) {
    return list1.size() == list2.size();
}

int similarityScore (vector<int>& list1, vector<int>& list2) {
    map<int, int> rightCount;
    for (size_t i = 0; i < list2.size(); i++) {
        rightCount[list2[i]]++;
    }
    int score = 0;
    for (size_t i = 0; i < list1.size(); i++) {
        score = score + list1[i] * rightCount[list1[i]];
    }
    return score;
}

int main() {
    vector<int> list1;
    vector<int> list2;
    fillVectors(list1, list2);
    if (!AreListsEqualSize(list1, list2)) {
        cout << "Lists are not equal in size" << endl;
        return 1;
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int sumDistLists = sumDistanceOfLists(list1, list2);
    cout << "part one : " << sumDistLists << endl;
    int score = similarityScore(list1, list2);
    cout << "part two : " << score << endl;

    return 0;
}
