// Test case generator

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000; // 10^4
const int MAX_VALUE = 99999999; // 10^8 - 1
const int MIN_VALUE = -99999999; // -10^8 + 1

const int HASH_MOD = 20011; // prime number

int unsigned_mod(int a, int b) {
    return (a % b + b) % b;
}

class RandomNumberGenerator {
    private:
        mt19937 rng;
        uniform_int_distribution<int> dist;
    public:
        RandomNumberGenerator(int min, int max) {
            random_device rd;
            rng = mt19937(rd());
            dist = uniform_int_distribution<int>(min, max);
        }

        int next() {
            return dist(rng);
        }
};

class IGenerator {
    public:
        RandomNumberGenerator rng;
        IGenerator() : rng(MIN_VALUE, MAX_VALUE) {}
        virtual vector<int> generate(int n) = 0;
};

class RandomCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            // generate n+1 random numbers
            // and allow at most n/2 duplicates
            vector<int> v;
            int numOfDuplicates = unsigned_mod(rng.next(), n / 2 + 1);
            int numOfRandomNumbers = n + 1 - numOfDuplicates;
            for (int i = 0; i < numOfRandomNumbers; i++) {
                v.push_back(rng.next() % 20000);
            }
            for (int i = 0; i < numOfDuplicates; i++) {
                v.push_back(v[unsigned_mod(rng.next(), v.size())]);
            }
            return v;
        }
};

class UniqueCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            unordered_set<int> s;
            vector<int> v;
            while (s.size() < n) {
                int x = rng.next();
                if (s.find(x) == s.end()) {
                    s.insert(x);
                    v.push_back(x);
                }
            }
            v.push_back(v[0]);
            return v;
        }
};

class AscendingCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            set<int> s;
            while (s.size() < n) {
                s.insert(rng.next());
            }
            vector<int> v(s.begin(), s.end());
            v.push_back(v[0]);
            return v;
        }
};

class RandomAscendingCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            multiset<int> s;
            while (s.size() < n) {
                s.insert(rng.next() % 20000);
            }
            vector<int> v(s.begin(), s.end());
            v.push_back(v[0]);
            return v;
        }
};

class CongruenceModuloCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            vector<int> v;
            int seed = rng.next() % HASH_MOD;
            // generate numbers in the form of seed + k * HASH_MOD and in range [MIN_VALUE, MAX_VALUE]
            for (int i = 0; i < n; i++) {
                v.push_back((seed + i * HASH_MOD) % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE);
            }
            random_shuffle(v.begin(), v.end());
            v.push_back(v[0]);
            return v;
        }
};

class SameCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            vector<int> v;
            int x = rng.next() % 20000;
            for (int i = 0; i < n; i++) {
                v.push_back(x);
            }
            v.push_back(v[0]);
            return v;
        }
};

class DescendingCaseGenerator : public IGenerator {
    public:
        vector<int> generate(int n) {
            set<int> s;
            while (s.size() < n) {
                s.insert(rng.next());
            }
            vector<int> v(s.begin(), s.end());
            reverse(v.begin(), v.end());
            v.push_back(v[0]);
            return v;
        }
};

void generate(int query, int n, IGenerator *generator) {
    for (int i = 0; i < query; i++) {
        vector<int> v = generator->generate(n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
}

int main() {
    int query = 10;
    int n = 9995; // the generated array will have 9995 elements
    freopen("D:\\2023A\\CS3334\\Project\\tests\\1.in", "w", stdout);
    IGenerator *generator = new RandomCaseGenerator();
    generate(query, n, generator);
    freopen("D:\\2023A\\CS3334\\Project\\tests\\2.in", "w", stdout);
    generator = new UniqueCaseGenerator();
    generate(query, n, generator);
    freopen("D:\\2023A\\CS3334\\Project\\tests\\3.in", "w", stdout);
    generator = new AscendingCaseGenerator();
    generate(query, n, generator);
    freopen("D:\\2023A\\CS3334\\Project\\tests\\4.in", "w", stdout);
    generator = new RandomAscendingCaseGenerator();
    generate(query, n, generator);
    freopen("D:\\2023A\\CS3334\\Project\\tests\\5.in", "w", stdout);
    generator = new CongruenceModuloCaseGenerator();
    generate(query, n, generator);
    freopen("D:\\2023A\\CS3334\\Project\\tests\\6.in", "w", stdout);
    generator = new SameCaseGenerator();
    generate(query, n, generator);
    freopen("D:\\2023A\\CS3334\\Project\\tests\\7.in", "w", stdout);
    generator = new DescendingCaseGenerator();
    generate(query, n, generator);
}