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

    // DP 배열 생성 (len1+1 x len2+1 크기)
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // DP 배열 채우기
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // 문자가 일치하면 이전 값에서 +1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                // 문자가 일치하지 않으면 이전 값 중 큰 값 가져오기
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 최종 결과 출력
    cout << dp[len1][len2] << endl;

  

    return 0;
}
