#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    ofstream outfile("output.txt");
    if (!outfile) {
        cerr << "Ошибка открытия файла для записи" << endl;
        return 1;
    }

    int n;
    infile >> n;
    stack<int> stack;

    for (int i = 0; i < n; i++) {
        double x, y;
        int shlang;
        infile >> x >> y >> shlang;
        if (!stack.empty() && stack.top() == shlang) {
            stack.pop();
        }
        else {
            stack.push(shlang); 
        }
    }

    if (stack.empty()) {
        outfile << "Yes";
    }
    else {
        outfile << "No";
    }

    infile.close();
    outfile.close();

    return 0;
}
