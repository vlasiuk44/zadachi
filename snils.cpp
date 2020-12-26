

bool prime(long long n) {
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
    
    
void z4() {
    ofstream fit("new.txt");
    setlocale(LC_ALL, "Russian");
    for (int i = 100000000; i < 1000000000; i++)
    {
        if (prime(i)) {
            int m = 9;
            int summ = 0;
            string k = to_string(i);
            for (int j = 0; j < k.length(); j++)
            {
                summ += (k[j] - '0') * m;
                m--;
            }
            if (summ % 101 == summ) {
                fit << i << "\n";
            }
        }
    }
}

int main() {
    z4();
   
}
