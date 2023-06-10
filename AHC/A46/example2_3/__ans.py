import math

def calculate_score(P, ans):
    N = len(P)
    score = 0
    for i in range(N):
        x1, y1 = P[ans[i] - 1]
        x2, y2 = P[ans[(i+1)%N] - 1]
        score += math.sqrt((x2-x1)**2 + (y2-y1)**2)
    return score

# Pは座標のリスト、ansは解答の配列
P = []
with open('in.txt', 'r') as file:
    n = int(file.readline())
    for _ in range(n):
        x, y = map(int, file.readline().split())
        P.append((x, y))

ans = []
with open('out.txt', 'r') as file:
    while True:
        line = file.readline()
        if not line:
            break
        ans.append(int(line))
print(calculate_score(P, ans))
