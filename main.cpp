#include <iostream>
using namespace std;

void merge(int tab[], int l, int m, int r) {
    int lSize = m - l + 1;
    int rSize = r - m;

    int* tabL = new int[lSize];
    int* tabR = new int[rSize];

    for (int i = 0; i < lSize; i++) {
        tabL[i] = tab[l + i];
    }

    for (int j = 0; j < rSize; j++) {
        tabR[j] = tab[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < lSize && j < rSize) {
        if (tabL[i] <= tabR[j]) {
            tab[k] = tabL[i];
            i = i + 1;
        } else {
            tab[k] = tabR[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < lSize) {
        tab[k] = tabL[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < rSize) {
        tab[k] = tabR[j];
        j = j + 1;
        k = k + 1;
    }

    delete[] tabL;
    delete[] tabR;
}

void mergeSort(int tab[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(tab, l, m);
        mergeSort(tab, m + 1, r);
        merge(tab, l, m, r);
    }
}

void printArray(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        cout << tab[i] << " | ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Wprowadz liczbe elementow do posortowania: ";
    cin >> n;

    int* tab = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    cout << endl << "Tablica przed posortowaniem:" << endl;
    printArray(tab, n);

    cout << endl << "Rozpoczecie sortowania" << endl << endl;

    mergeSort(tab, 0, n - 1);

    cout << "Tablica po sortowaniu:" << endl;
    printArray(tab, n);

    delete[] tab;

    return 0;
}

