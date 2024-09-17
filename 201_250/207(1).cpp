#include <vector>

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {

        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> visit(numCourses, 0);
        // 构建邻接关系
        for (auto &x : prerequisites)
        {
            graph[x[0]].push_back(x[1]);
        }

        // 逐步循环判断是否出现环
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(graph, visit, i))
                return false;
        }

        return true;
    }

private:
    // 已经访问，设置为2， 然后可以将当前的访问的元素设置为2， 如果重复出现相同的数字，同时visit[i] == 1， 则说明出现了一个循环，则返回false，说明
    // 无法完成课程的学习，否则进行当前课程的前置课程的学习，当当前课程的所有前置课程都实现后，完成当前课程的学习
    bool dfs(const std::vector<std::vector<int>> &graph, std::vector<int> &visit, int curriculum)
    {
        visit[curriculum] = 1;

        for (const auto &x : graph[curriculum])
        {
            if (visit[x] == 1)
                return false;
            if (!visit[x] && !dfs(graph, visit, x))
                return false;
        }

        visit[curriculum] = 2;
        return true;
    }
};