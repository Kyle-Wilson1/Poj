#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string multiply(const string &a, const string &b);

string getZeroString(long n) {

    string st;
    for (int i = 0; i < n; ++i)
        st += '0';

    return st;
}

string exp(string st, int n) {

    long dot = st.find('.');
    long front = 0, end = 0;
    //如果为小数，去掉末尾的0
    if (dot >= 0) {
        end = st.size() - 1;
        while (end > 0) {
            if (st[end] != '0')break;
            --end;
        }
        end = st.size() - 1 - end;
        st = st.substr(0, st.size() - end);

    }

    // 计算小数部分的数字长度
    long decimalSize;
    if (dot < 0) decimalSize = 0;
    else decimalSize = (st.size() - 1 - dot) * n;

    //去掉.
    if (dot >= 0) {
        st = st.substr(0, dot) + st.substr(dot + 1, st.size());
    }

    //去掉前面的0
    while (front < st.size()) {
        if (st[front] != '0' && st[front] != '.')break;
        ++front;
    }
    string original = st.substr(front, st.size());
    string answer = original;

    if (original.empty()) { return "0"; }

    for (int i = 0; i < n - 1; ++i) {
        answer = multiply(answer, original);
    }

    //没有小数部分
    if (dot < 0 || decimalSize <= 0)return answer;

    //整数为0,  如0.000123
    if (answer.size() <= decimalSize) {
        return "." + getZeroString(decimalSize - answer.size()) + answer;
    }

    //正常小数位， 如123.1
    answer.insert(answer.size() - decimalSize, ".");

    return answer;
}

string multiply(const string &a, const string &b) {

    long l1 = a.size() - 1;
    long l2 = b.size() - 1;

    long l = l1 + l2 + 1;
    int *ret = new int[l + 1];
    for (int i = 0; i < l + 1; ++i) ret[i] = 0;

    for (long i = l1; i >= 0; --i)
        for (long j = l2; j >= 0; --j) {

            long pos = l1 - i + l2 - j;
            int temp = (a[i] - 48) * (b[j] - 48) + ret[pos];

            ret[pos] = temp % 10;
            ret[pos + 1] += temp / 10;
        }


    if (ret[l] <= 0) { --l; };

    string st;
    for (long i = l; i >= 0; --i) {
        st += ret[i] + '0';
    }

    delete[]ret;
    return st;
}

int main() {

    ifstream fin("a.in");
    ofstream fout("a.out");

    string r;
    int n;

    while (fin >> r >> n) {
        if (n == 0) fout << 1 << endl;
        else
            fout << exp(r, n) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}