from collections import defaultdict


class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        colors = [-1] * n
        adj = defaultdict(list)
        for a, b in dislikes:
            adj[a - 1].append(b - 1)
            adj[b - 1].append(a - 1)

        visited = set()

        for node in range(n):
            if node in visited:
                continue
            colors[node] = 0
            # such loop will not end until all node are traverse.
            # If this line is executed at second time, it'll necessarily means the program is at another graph.
            stacks = [node]
            while stacks:
                cur_node = stacks.pop()
                cur_colr = colors[cur_node]
                for adj_n in adj[cur_node]:
                    if colors[adj_n] == -1:
                        colors[adj_n] = cur_colr ^ 1
                        stacks.append(adj_n)
                    elif colors[adj_n] == cur_colr:
                        return False
                visited.add(cur_node)
        return True
