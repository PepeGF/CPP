#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> jacobsthal(int const n) {
    // esta función genera una lista de los n primeros números de la serie de Jacobsthal
    // Jn = Jn-1 + 2 * Jn-2

    std::vector<int> jacob;
    if (n >= 0) jacob.push_back(0); // J(0)
    if (n >= 1) jacob.push_back(1); // J(1)
    for (int i = 2; ; ++i) {
        int next_value = jacob[i-1] + 2 * jacob[i-2];
        if (next_value > n) break;
        jacob.push_back(next_value);
    }

    return jacob;
}

std::vector<int> create_serie(const std::vector<int>& jacob, int n) {
    std::vector<int> result;
    std::vector<bool> included(n + 1, false);

    // Marcar todos los números de Jacobsthal en el rango [0, n] como incluidos
    for (std::vector<int>::const_iterator it = jacob.begin(); it != jacob.end(); ++it) {
        int value = *it;
        if (value <= n) {
            result.push_back(value);
            included[value] = true;
        }
    }

    // Añadir los números restantes en el rango [0, n] que no están en la serie de Jacobsthal
    for (int i = 0; i <= n; ++i) {
        if (!included[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter the maximum value for the series: ";
    std::cin >> n;

    std::vector<int> jacob = jacobsthal(n);

    std::vector<int> serie = create_serie(jacob, n);

    std::cout << "Generated series: ";
    for (std::vector<int>::iterator it = serie.begin(); it != serie.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
