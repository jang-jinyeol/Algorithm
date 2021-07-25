int Isprime(int n) {

    if (n == 1 || n == 0) {
        return 0;
    }
    else {
        for (int i = 2; i <= sqrt(n); i++) {

            if (n % i == 0) return 0;
        }
    }
    
    return 1;
}



int solution(string numbers) {
    int answer = 0;
    int num = 0;
    unordered_set<int>set; //vector는 중복 원소를 허용하기 때문에 set을 사용
   
    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++) {

            num = stoi(numbers.substr(0, i));
            if (Isprime(num)) {

                set.emplace(num);
            }
        }
    } while (next_permutation(numbers.begin(),numbers.end()));

    return set.size();
}



int main() {

    cout << solution("17");

}
