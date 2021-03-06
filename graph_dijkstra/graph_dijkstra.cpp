/* ==========================================================================
   查找加权图的最短路径 Dijkstra方法
   ==========================================================================*/

#include "pch.h"
#include <iostream>
//#include <cstdio>

#define MAXLEN	1000
int cost[7][7];
int dist[7];

/**
 * create a weighting graph
 */
void creategraph(int *node, int num)
{
	int from, to, i;

	for (i = 0; i < num; i++) {
		from = node[i * 3];
		to = node[i * 3 + 1];
		cost[from][to] = node[i * 3 + 2];
	}
}

void shortestpath(int begin, int num)
{
	int selected[7];
	int min;
	int s;
	int i, j;

	int shortest_steps[7];
	int current_step_no = 0;

	for (i = 0; i < 7; i++) {
		shortest_steps[i] = -1;
	}

	for (i = 2; i <= num; i++) {
		selected[i] = 0;
		dist[i] = cost[begin][i];
	}

	shortest_steps[++current_step_no] = begin;
	selected[begin] = 1;
	dist[begin] = 0;
	printf("vrtx1     2     3     4     5     6     \n");
	for (j = 1; j <= num; j++) {
		printf(" %4d ", dist[j]);
	}
	printf("\n");
	printf(" %4d  %4d  %4d  %4d  %4d  %4d <--current steps\n",
		shortest_steps[1], shortest_steps[2], shortest_steps[3], shortest_steps[4], shortest_steps[5], shortest_steps[6]);

	for (i = 1; i <= num - 1; i++) {
		min = MAXLEN;
		for (j = 1; j <= num; j++) {
			if (min > dist[j] && selected[j] == 0) {
				s = j;
				min = dist[j];
			}
		}

		selected[s] = 1;
		shortest_steps[s] = 1;
		printf("确定到顶点%d 的最短距离是%d\n", s, min);

		for (j = 1; j <= num; j++) {
			if (selected[j] == 0 && dist[s] + cost[s][j] < dist[j]) {
				dist[j] = dist[s] + cost[s][j];
				printf("到顶点%d 途经%d 更短", j, s);
			}
			printf(" %4d ", dist[j]);
		}
		printf("\n");

		// current steps: 
		printf(" %4d  %4d  %4d  %4d  %4d  %4d <--current steps\n",
			shortest_steps[1], shortest_steps[2], shortest_steps[3], shortest_steps[4], shortest_steps[5], shortest_steps[6]);
	}
}

int main()
{
	int node[7][3] = {
		{1, 2, 35}, 
		{2, 3, 45},
		{2, 4, 30},
		{3, 5, 25},
		{4, 5, 45},
		{4, 6, 130},
		{5, 6, 100}
	};
	int i, j;

	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			cost[i][j] = MAXLEN;
		}
	}

	creategraph(&node[0][0], 7);
	printf("the weighting graph's adjacent matrix: \n");
	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			printf(" %4d ", cost[i][j]);
		}
		printf("\n");
	}

	printf("calculating the shortest path from the vertex 1 to the others vertex...\n");
	shortestpath(1, 6);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
