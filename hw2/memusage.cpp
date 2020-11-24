#include <bits/stdc++.h>
#define pb push_back
#define PII pair<int, int>
#define mkp make_pair
#define Lint long long
#define R_max 1073741824 //2^30
using namespace std;
set<int> SC;
typedef struct
{
    unsigned long size, resident, share, text, lib, data, dt;
} statm_t;

void read_off_memory_status(statm_t &result)
{
    unsigned long dummy;
    const char *statm_path = "/proc/self/statm";
    FILE *f = fopen(statm_path, "r");
    if (!f)
    {
        perror(statm_path);
        abort();
    }
    if (7 != fscanf(f, "%ld %ld %ld %ld %ld %ld %ld",
                    &result.size, &result.resident, &result.share, &result.text, &result.lib, &result.data, &result.dt))
    {
        perror(statm_path);
        abort();
    }
    fclose(f);
}
int main()
{
    int size = 1 << 18;
    statm_t start, end;
    srand(time(NULL));
    read_off_memory_status(start);
    cout << "original memusage:   " << (start.size << 2) << " KB("<<(start.size) << " pages)" << endl;
    for (int j = 0; j < size; j++)
        SC.insert(rand() % R_max + 1);
    read_off_memory_status(end);
    cout << "final memusage:     " << (end.size << 2) << " KB("<<(end.size) << " pages)" << endl;
    cout << "set memusage:  " << ((end.size - start.size) << 2) << " KB" << endl;
    cout << endl;
    cout << "size/node= " << ((end.size - start.size) << 12) / size << " Bytes" << endl;
    return 0;
}
