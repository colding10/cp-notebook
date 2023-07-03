#include <cmath>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;

    int range = sqrt(num);
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i <= range; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;

    return true;
}
