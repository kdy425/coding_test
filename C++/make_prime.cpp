#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;  // 2는 소수
    if (num % 2 == 0) return false;  // 짝수는 소수가 아님

    for (int i = 3; i <= sqrt(num); i=i+2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    unordered_set<int> set;

    size_t size = nums.size();
    int sum;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            for (size_t k = j + 1; k < size; k++) {
                sum = nums[i] + nums[j] + nums[k];
                
                if (is_prime(sum)) {
                    answer++;

                }
            }
        }
    }
    return answer;
}

int main() {
    //vector<int> nums = { 1,2,3,4 };
    vector<int> nums = { 1,2,7,6,4 };
    cout << solution(nums);

    
}