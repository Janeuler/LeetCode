#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<int> ans;
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> visited(numCourses, 0);

        for (const auto &x : prerequisites)
        {
            graph[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] != 2)
                if (!dfs(i, graph, visited, ans))
                {
                    return {};
                }
        }

        return ans;
    }

private:
    bool dfs(int index, std::vector<std::vector<int>> &graph, std::vector<int> &visited, std::vector<int> &ans)
    {
        visited[index] = 1;

        for (const auto &x : graph[index])
        {
            if (!visited[x] && !dfs(x, graph, visited, ans))
            {
                return false;
            }
            if (visited[x] == 1)
            {
                return false;
            }
        }

        visited[index] = 2;
        // auto it = find(ans.begin(), ans.end(), index);
        // if (it == ans.end())
        ans.push_back(index);
        return true;
    }
};