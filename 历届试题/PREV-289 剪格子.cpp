#include<bits/stdc++.h>
using namespace std;
// N表示行数，M表示列数，num表示包含左上角格子的那个区域包含的格子的最小数目，sum表示输入的所有数字之和
int N, M, num = INT_MAX, sum = 0;
int A[10][10];// 输入的N行M列数字
bool visit[10][10];// 表示是否被访问过
bool outOfBorder(int i, int j) {// 判断当前坐标是否越界
    if (i < 0 || i >= N || j < 0 || j >= M)
        return true;
    return false;
}
// 深度优先遍历,i、j表示当前坐标的行列，currentSum表示当前遍历过的数字之和，currentNum表示当前遍历过的数字数量
void DFS(int i, int j, int currentSum, int currentNum) {
    visit[i][j] = true;// 访问过该坐标下的数字
    currentSum += A[i][j];// 更新遍历过的数字之和
    ++currentNum;// 更新遍历过的数字数量
    if (2 * currentSum >= sum) {// 如果当前遍历过的数字之和大于等于所有数字之和的一半
        if (2 * currentSum == sum)// 如果当前遍历过的数字之和等于所有数字之和的一半
            num = min(currentNum, num);// 更新包含左上角格子的那个区域包含的格子的最小数目
        visit[i][j] = false;
        return;// 回溯到上一结点
    }
    if (!outOfBorder(i, j + 1) && !visit[i][j + 1])// 向右移动
        DFS(i, j + 1, currentSum, currentNum);
    if (!outOfBorder(i + 1, j) && !visit[i + 1][j])// 向下移动
        DFS(i + 1, j, currentSum, currentNum);
    if (!outOfBorder(i, j - 1) && !visit[i][j - 1])// 向左移动
        DFS(i, j - 1, currentSum, currentNum);
    if (!outOfBorder(i - 1, j) && !visit[i - 1][j])// 向上移动
        DFS(i - 1, j, currentSum, currentNum);
    visit[i][j] = false;
}
int main(){
    scanf("%d%d",&M,&N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            scanf("%d",&A[i][j]);
            sum += A[i][j];
        }
    DFS(0,0,0,0);
    if (num == INT_MAX)// num没有变化过，说明没有符合要求的剪法
        printf("0");// 输出0
    else
        printf("%d",num);
    return 0;
}
