n = int(input("Enter number of vertices : "))
delta = int(input("Enter delta :- "))

tree = [[] for i in range(n + 1)]

print("Enter parent child weight: ")
for i in range(n - 1):
    u,v,w = map(int,input().split())
    tree[u].append((v,w))

booster = []
def dfs(u):
    max_delay = 0

    for v,w in tree[u]:
        d = dfs(v)

        if d + w > delta:
            booster.append(v)
        else:
            max_delay = max(max_delay,d + w)

    return max_delay

dfs(1)

print("Booster nodes are :",booster)