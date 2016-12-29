#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define maxn 500
bool data[maxn][maxn];
int ind[maxn];
int v, a;
int main()
{
	int s, d;
	memset(data, 0, sizeof(data));
	memset(ind, 0, sizeof(ind));
	cin >> v >> a;
	for (int i = 0; i<a; i++)
	{
		cin >> s >> d;
		data[s][d] = 1;

		ind[d]++;
	}
	for (int i = 1; i <= v; i++)
	{
		if (ind[i] == 0)
		{
			cout << 'v' << i << ' ';
			ind[i]--;
			for (int j = 1; j <= v; j++)
			{
				if (data[i][j])
				{
					data[i][j] = 0;
					ind[j]--;
				}
			}
			i = 0;

		}


	}

	return 0;
}