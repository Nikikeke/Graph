#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int N = 250;
const int INF = 0x3f3f3f3f;

struct node{
	int x, y;
	int door;
	bool operator < (const node &a) const{
		return a.door<door;
	}
};

int n, m, sx, sy, maxx, maxy;
int dis[N][N], h[N][N], l[N][N];

void BFS(){
	priority_queue<node> q;
	while (!q.empty())
		q.pop();
	for (int i = 0; i <= maxx; i++)
		for (int j = 0; j <= maxy; j++)
			dis[i][j] = INF;
	node cur;
	cur.x = 0, cur.y = 0, cur.door = 0;
	dis[0][0] = 0;
	q.push(cur);
	while (!q.empty()){
		cur = q.top();
		q.pop();
		int x = cur.x, y = cur.y;
		if (x == sx && y == sy)
			return;
		if (y + 1 <= maxy && dis[x][y + 1]>dis[x][y] + h[x][y + 1]){
			dis[x][y + 1] = dis[x][y] + h[x][y + 1];
			cur.x = x;
			cur.y = y + 1;
			cur.door = dis[x][y + 1];
			q.push(cur);
		}
		if (y - 1 >= 0 && dis[x][y - 1]>dis[x][y] + h[x][y]){
			dis[x][y - 1] = dis[x][y] + h[x][y];
			cur.x = x;
			cur.y = y - 1;
			cur.door = dis[x][y - 1];
			q.push(cur);
		}
		if (x - 1 >= 0 && dis[x - 1][y]>dis[x][y] + l[x][y]){
			dis[x - 1][y] = dis[x][y] + l[x][y];
			cur.x = x - 1;
			cur.y = y;
			cur.door = dis[x - 1][y];
			q.push(cur);
		}
		if (x + 1 <= maxx && dis[x + 1][y]>dis[x][y] + l[x + 1][y]){
			dis[x + 1][y] = dis[x][y] + l[x + 1][y];
			cur.x = x + 1;
			cur.y = y;
			cur.door = dis[x + 1][y];
			q.push(cur);
		}
	}
	dis[sx][sy] = -1;
}
int main(){



	int x, y, d, t;
	double f1, f2;
	while (~scanf("%d%d", &n, &m)){
		if (n == -1 && m == -1)
			break;
		maxx = -1, maxy = -1;
		memset(h, 0, sizeof(h));
		memset(l, 0, sizeof(l));
		while (n--){
			cin >> x >> y >> d >> t;
			if (d == 0){
				for (int i = 0; i<t; i++)
					h[x + i][y] = INF;
				maxx = max(maxx, x + t);
				maxy = max(maxy, y);
			}
			else{
				for (int i = 0; i<t; i++)
					l[x][y + i] = INF;
				maxx = max(maxx, x);
				maxy = max(maxy, y + t);
			}
		}
		while (m--){
			cin >> x >> y >> d;
			if (d == 0)
				h[x][y] = 1;
			else
				l[x][y] = 1;
		}
		cin >> f1 >> f2;
		if (f1>maxx || f2>maxy){
			cout << '0' << endl;
			continue;
		}
		sx = (int)f1, sy = (int)f2;
		BFS();
		cout << dis[sx][sy] << endl;
	}
	return 0;
}