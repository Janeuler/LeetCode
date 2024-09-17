#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        // 使用邻接表存储图
        std::vector<std::vector<int>> graph(numCourses);
        for (auto &x : prerequisites)
        {
            graph[x[1]].push_back(x[0]); // x[1] 是 x[0] 的先修课程
        }

        // 记录访问状态：0 - 未访问，1 - 正在访问，2 - 已访问
        std::vector<int> visited(numCourses, 0);

        // 对每个节点进行 DFS
        for (int i = 0; i < numCourses; ++i)
        {
            if (visited[i] == 0 && !dfs(graph, visited, i))
            {
                return false; // 存在环
            }
        }

        return true; // 不存在环
    }

private:
    // 深度优先搜索
    bool dfs(const std::vector<std::vector<int>> &graph, std::vector<int> &visited, int curr)
    {
        visited[curr] = 1; // 标记为正在访问

        // 遍历所有邻居节点
        for (int neighbor : graph[curr])
        {
            if (visited[neighbor] == 1)
            {
                return false; // 存在环
            }
            else if (visited[neighbor] == 0 && !dfs(graph, visited, neighbor))
            {
                return false; // 存在环
            }
        }

        visited[curr] = 2; // 标记为已访问
        return true;
    }
};
