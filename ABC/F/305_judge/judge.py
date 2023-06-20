def process_graph(edges, N, M):
    # N, Mを出力
    print(N, M)

    # u, vのいずれかが1であるエッジを抽出し、出力
    adjacent_to_1 = []
    for u, v in edges:
        if u == 1:
            adjacent_to_1.append(v)
        elif v == 1:
            adjacent_to_1.append(u)
    
    # 1に隣接するノードの数とそのリストを出力
    print(len(adjacent_to_1), *adjacent_to_1)

    while True:
        p = int(input())  # ユーザからの入力を受け取る
        if p == N:
            print('ok')
        else:
            # pに隣接するノードを見つける
            adjacent_to_p = []
            for u, v in edges:
                if u == p:
                    adjacent_to_p.append(v)
                elif v == p:
                    adjacent_to_p.append(u)
            
            # pに隣接するノードの数とそのリストを出力
            print(len(adjacent_to_p), *adjacent_to_p)

# 入力ファイルからデータを読み込む
with open('in/in2', 'r') as f:
    N, M = map(int, f.readline().split())
    edges = []
    for _ in range(M):
        u, v = map(int, f.readline().split())
        edges.append((u, v))

# グラフを処理
process_graph(edges, N, M)
