#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<int>> findPairs(const vector<int>& array, int target) {
    vector<vector<int>> pairs;
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] + array[j] == target) {
                pairs.push_back({ array[i], array[j] });
            }
        }
    }
    return pairs;
}

vector<int> mergeArray(const vector<vector<int>>& pairs) {
    unordered_set<int> mergedSet;
    for (const auto& pair : pairs) {
        for (int element : pair) {
            mergedSet.insert(element);
        }
    }
    vector<int> mergedArray(mergedSet.begin(), mergedSet.end());
    sort(mergedArray.begin(), mergedArray.end());
    return mergedArray;
}

vector<vector<int>> doubleTarget(const vector<int>& array, int target) {
    int doubledTarget = target * 2;
    vector<vector<int>> pairs;
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            for (int k = j + 1; k < array.size(); k++) {
                if (array[i] + array[j] + array[k] == doubledTarget) {
                    pairs.push_back({ array[i], array[j], array[k] });
                }
            }
        }
    }
    return pairs;
}

int main() {
    vector<int> array = { 1, 3, 2, 2, -4, -6, -2, 8 };
    int target = 4;

    vector<vector<int>> pairs = findPairs(array, target);
    cout << "Pairs for target " << target << ":\n";
    for (const auto& pair : pairs) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    vector<int> mergedArray = mergeArray(pairs);
    cout << "Merged array:\n";
    for (const auto& element : mergedArray) {
        cout << element << " ";
    }
    cout << endl;

    vector<vector<int>> doubledTargetPairs = doubleTarget(mergedArray, target);
    cout << "Pairs for double target:\n";
    for (const auto& pair : doubledTargetPairs) {
        cout << "[";
        for (const auto& element : pair) {
            cout << element << " ";
        }
        cout << "]\n";
    }

    return 0;
}
