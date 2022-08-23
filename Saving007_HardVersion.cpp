#include "iostream"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
using namespace std;
int n, m;
#define MINLEN 42.5
struct Pointer {
    int x;
    int y;
}point[101];
bool answer = false; /* ��¼007�ܷ�ȫ����~~ */
bool visited[101] = { false }; /* �жϵ�ǰ���Ƿ񱻷��ʹ� */
int path[101] = { -1 }; /* ��¼��Ծ�����вȹ������� */
bool isSave(int x) { /* �жϴӵ�ǰ���ܷ��������� */
    if ((point[x].x - m <= -50) || (point[x].x + m >= 50) || (point[x].y - m <= -50) || (point[x].y + m >= 50))
        return true;
    return false;
}

bool jump(int x, int y) { /* �ж�2��������Ƿ�����Ծ������ */
    int p1 = pow(point[x].x - point[y].x, 2);
    int p2 = pow(point[x].y - point[y].y, 2);
    int r = m * m;
    if (p1 + p2 <= r)
        return true;
    return false;
}

int firstJump(int x) {  /* ��007���ڹµ�ʱ ��һ�ο���ѡ���������� ��Ϊ��һ���ж��ܷ���Ծ�ļ��㷽�������dfs����ͬ ����Ҫ����д */
    int p1 = pow(point[x].x, 2);
    int p2 = pow(point[x].y, 2);
    int r = (m + 7.5) * (m + 7.5);
    if (p1 + p2 <= r) {
        return p1 + p2;
    }
    return 0;
}
bool cmp(int a, int b) {
    return firstJump(a) < firstJump(b);
}
void bfs() { /* ��bfs���ж�����Ҫ�ȼ���С��������ϰ� */
    int b[101];
    queue<int>q;
    /* ����һ���ܲȵ������㰴�����С�����˳�������~ ��Ϊ������Ҫ��֤�ڲȵ�����������ȵ������ �����һ��������̵�~~*/
    for (int i = 0; i < n; i++) {
        b[i] = i;
    }
    sort(b, b + n, cmp); /* ���յ�һ���ľ�������~~~ */
    int last;


    for (int i = 0; i < n; i++) {
        if (firstJump(b[i])) { /* ������ȥ�� */
            q.push(b[i]);
            visited[b[i]] = true; /* ָ��ǰ�������һ����~ */
            last = b[i];
        }
    }


    int step = 2;  /* ��¼����Ҫ��Ծ�Ĵ��� */
    int tail;
    while (!q.empty()) {
        int p = q.front();
        q.pop();


        if (isSave(p)) {
            int k = 1;
            stack<int> s;
            cout << step << endl;
            while (k < step) {
                //cout << point[p].x << " " << point[p].y << endl;
                s.push(p);
                p = path[p];
                k++;
            }
            while (!s.empty()) {
                p = s.top();
                s.pop();
                cout << point[p].x << " " << point[p].y << endl;
            }
            return;
        }


        for (int i = 0; i < n; i++) {
            if (!visited[i] && jump(p, i)) { /* û�ȹ����������� */
                q.push(i);
                path[i] = p; /* �ǵõ�ǰ���ӽڵ�ĸ��ڵ�~ */
                visited[i] = true;
                tail = i; /* ָ����һ������һ��Ԫ�� */
            }
        }
        if (last == p) { /* ����������һ��~ */
            step += 1;
            last = tail;
        }
    }
    if (q.empty()) { /* �������Ϊ��  ˵��û����ȥ��~ */
        cout << "0" << endl;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    if (m >= MINLEN) { /* ����ֱ�Ӵӹµ����ᵽ���� ֱ����� */
        cout << "1" << endl;
        return 0;
    }
    bfs();
    return 0;
}
