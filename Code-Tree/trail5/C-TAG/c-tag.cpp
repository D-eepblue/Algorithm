#include <iostream>
#include <unordered_set>

using namespace std;

int n, m, ret = 0;
string A[500];
string B[500];

int trans(char c){
    if(c == 'A') return 1;
    if(c == 'C') return 2;
    if(c == 'G') return 3;
    if(c == 'T') return 4;
}

int getHash(string& str, int a, int b, int c){
    int hash = 0;
    hash += trans(str[a]) * 10 * 10;
    hash += trans(str[b]) * 10;
    hash += trans(str[c]);
    return hash;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    for(int i = 0; i < m; i ++){
        for(int j = i; j < m; j ++){
            for(int k = j; k < m; k ++){
                if(i == j || j == k || i == k) continue;
                
                unordered_set<int> setA, setB, setU;

                for(int l = 0; l < n; l ++){
                    setA.insert(getHash(A[l], i, j, k));
                    setU.insert(getHash(A[l], i, j, k));
                    
                    setB.insert(getHash(B[l], i, j, k));
                    setU.insert(getHash(B[l], i, j, k));
                }

                if(setA.size() + setB.size() == setU.size()){
                    ret ++;
                }
            }
        }
    }

    cout << ret;

    return 0;
}
