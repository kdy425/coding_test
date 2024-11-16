//น้มุ 21921
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> array(n);
    for (int& num : array) {
        cin >> num;
    }

    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += array[i];
    }

    int max_value = sum;
    int count = 1;

    for (int i = x; i < n; i++) {
        sum = sum - array[i - x] + array[i];
        if (sum > max_value) {
            max_value = sum;
            count = 1;
        }
        else if (sum == max_value) {
            count++;
        }
    }

    if (max_value > 0) {
        cout << max_value << '\n' << count << '\n';
    }
    else {
        cout << "SAD\n";
    }

    return 0;
}