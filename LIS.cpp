#include <bits/stdc++.h>
using namespace std;

int arr[200005];
vector<int> lis;

int bs(int n, int tar)
{
    int l = 0, r = n;
    int mid = 1;
    while(l <= r && l < n)
    {
        mid = (l + r) / 2;
        if(tar == lis[mid])
            return mid;
        else if(tar < lis[mid])
            r = mid - 1;
        else
            l = mid + 1;
//        printf("%d %d %d %d %d\n", l, r, mid, tar, lis[mid]);
//        for(int i=0; i<n; i++)
//            printf("%d ", lis[i]);
//        printf("\n");
    }
    if (l != n)
        return max(0, l);
    return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    lis.assign(n, 0);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        lis[i] = 0;
    }
    lis[0]=arr[0];
    int ans=1;
    for(int i = 1; i < n; i++)
    {
        int pos = bs(ans, arr[i]);
        if(pos >= ans)
            lis[ans++] = arr[i];
        else
            lis[pos] = arr[i];
    }
    printf("%d\n", ans);
}
/*
8
7 3 5 3 6 2 9 8

10
3 8 3 8 1 5 10 5 8 10
*/
