#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    // DP �迭 ���� (len1+1 x len2+1 ũ��)
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // DP �迭 ä���
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // ���ڰ� ��ġ�ϸ� ���� ������ +1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                // ���ڰ� ��ġ���� ������ ���� �� �� ū �� ��������
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // ���� ��� ���
    cout << dp[len1][len2] << endl;

  

    return 0;
}
