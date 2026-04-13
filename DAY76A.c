def dfs(node, adj, visited):
    visited[node] = True
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor, adj, visited)

def count_components(n, edges):
   

    adj = {i: [] for i in range(1, n + 1)}
    
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = {i: False for i in range(1, n + 1)}
    count = 0

    # Step 2: Traverse all nodes
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i, adj, visited)
            count += 1

    return count


    
n = 6
edges = [(1,2), (2,3), (5,6)]


print(count_components(n, edges))