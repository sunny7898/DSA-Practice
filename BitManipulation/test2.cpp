#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void permut(unsigned current, unsigned max, unsigned n, int used[])
{
    if (n == 0)
        printf("%d\n", current);
    else {
        unsigned i;

        for (i = 1; i <= max; ++i) {
            if (!used[i]) {
            used[i] = 1;
            permut(current*10 + i, max, n - 1, used);
            used[i] = 0;
            }
        }
    }
}

int main()
{
    unsigned n;
    int used[10] = { 0 }; /* used[n] is 0 if the digit n is not yet used */

    printf("No of digits? : ");
    if ((scanf("%u", &n) != 1) || (n == 0) || (n > 9))
        return 0;

    permut(0, n, n, used);
    return 0;
}