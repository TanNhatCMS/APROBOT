#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    int w[5000];
    ifstream fin("APROBOT.INP");
    fin >> N >> K;
    for (int i = 0; i < N; i++)
        fin >> w[i];
    fin.close();

    int min_num = 0;
    for (int i = 0; i < N; i += K) {
        int max_pos = i;
        for (int j = i + 1; j < min(i + K, N); j++) {
            if (w[j] > w[max_pos]) {
                max_pos = j;
            }
        }
        if (max_pos > i) {
            for (int j = max_pos; j > i; j--) {
                swap(w[j], w[j - 1]);
                min_num++;
            }
        }
    }

    ofstream fout("APROBOT.OUT");
    fout << min_num;
    fout.close();

    // Đọc dữ liệu từ file APROBOT.OUT và in ra màn hình
    ifstream foutput("APROBOT.OUT");
    int result;
    foutput >> result;
    cout << result;
    foutput.close();

    return 0;
}
