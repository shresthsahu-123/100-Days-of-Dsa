```python
# DFS approach to check if graph is connected

def dfs(node, visited, adj):
    visited[node] = True
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor, visited, adj)

n, m = map(int, input().split())

adj = {i: [] for i in range(1, n+1)}

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

visited = {i: False for i in range(1, n+1)}

dfs(1, visited, adj)

if all(visited.values()):
    print("CONNECTED")
else:
    print("NOT CONNECTED")
```
