#include <iostream>

using namespace std;

constexpr int MAX_N = 100'005;

int N;
char B[MAX_N];
int rock[MAX_N], scissor[MAX_N], paper[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++) {
        if (B[i] == 'H') paper[i] = 1;
        if (B[i] == 'S') rock[i] = 1;
        if (B[i] == 'P') scissor[i] = 1;

        if (i > 0) {
            paper[i] += paper[i - 1];
            rock[i] += rock[i - 1];
            scissor[i] += scissor[i - 1];
        }
    }

    int ret = 0;

    // 바꾸지 않은 경우
    ret = max(ret, rock[N - 1]);
    ret = max(ret, scissor[N - 1]);
    ret = max(ret, paper[N - 1]);

    for (int i = 1; i < N; i++) {
        ret = max(ret, rock[i - 1] + paper[N - 1] - paper[i - 1]);
        ret = max(ret, rock[i - 1] + scissor[N - 1] - scissor[i - 1]);
        ret = max(ret, scissor[i - 1] + paper[N - 1] - paper[i - 1]);
        ret = max(ret, scissor[i - 1] + rock[N - 1] - rock[i - 1]);
        ret = max(ret, paper[i - 1] + scissor[N - 1] - scissor[i - 1]);
        ret = max(ret, paper[i - 1] + rock[N - 1] - rock[i - 1]);
    }

    cout << ret;

    return 0;
}