#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertion_sort(vector<T>& a) {
    size_t N{a.size()};
    for (size_t i{1}; i < N; i++) {
        T key = a[i];
        size_t j{i - 1};
        while (a[j] > key && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    vector<int> a{1, 2, 6, 2, 4};
    insertion_sort(a);
    for (auto x : a)
        cout << x << endl;

    return 0;
}