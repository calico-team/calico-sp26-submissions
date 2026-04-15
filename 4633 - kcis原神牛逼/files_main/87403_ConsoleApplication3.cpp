#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 忽略 T 后面的换行符

    while (T--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        string result;
        int j = 0; // 指向 B 中待匹配字符的位置

        for (char c : A) {
            if (j < (int)B.size() && c == B[j]) {
                result += c;  // 保留该字符
                ++j;          // 匹配成功，B 的指针后移
            }
            else {
                result += '#'; // 替换为 #
            }
        }

        cout << result << "\n";
    }

    return 0;
}