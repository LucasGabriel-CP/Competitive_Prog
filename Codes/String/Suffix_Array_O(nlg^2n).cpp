using namespace std;

bool comp(vector<int> R, int i, int j, int p){
    if (R[i] != R[j])
        return R[i] < R[j];
    return R[i + p] < R[j + p];
}

vector<int> build(string& Str){
    int n = Str.length();
    vector<int> SA(n), R(n), Temp(n);
    for (int i = 0; i < n; ++i){
        SA[i] = i;
        R[i] = Str[i];
    }
    for (int p = 0; p <= n; p = !p ? 1 :  p *= 2){
        sort(SA.begin(), SA.end(), [&](int i, int j){ return comp(R, i, j, p);});
        Temp[SA[0]] = 0;
        for (int i = 1; i < n; ++i){
            Temp[SA[i]] = Temp[SA[i-1]];
            if (comp(R, SA[i], SA[i - 1], p))
                ++Temp[SA[i]];
        }
        R = Temp;
    }

    return SA;
}

vector<int> build_LCP(string& Str, vector<int> SA){
    int n = Str.length();
    vector<int> R(n), LCP(n);
    for (int i = 0; i < n; ++i) R[SA[i]] = i;
    int K = 0;
    for (int i = 0; i < n; ++i){
        if (i != n - 1){
            int j = SA[R[i] + 1];
            while (K < n && Str[i + K] == Str[j + K]) ++K;
            LCP[R[i]] = K;
            if (K) --K;
        }
    }

    return LCP;
}

int main(){
    string Str = "LATAGATA";
    Str += '$';
    vector<int> SuffixArr = build(Str);
    for (int i : SuffixArr)
        printf("%d\n", i);
    return 0;
}
