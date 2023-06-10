import matplotlib.pyplot as plt
plt.figure(figsize=(10, 10))
# 1.txtから座標データを読み込みます
coords = []
with open('in.txt', 'r') as file:
    n = int(file.readline())
    for _ in range(n):
        x, y = map(int, file.readline().split())
        coords.append((x, y))

# 2.txtからインデックスデータを読み込みます
indices = []
with open('out.txt', 'r') as file:
    while True:
        line = file.readline()
        if not line:
            break
        indices.append(int(line))

# matplotlibを使って、座標とインデックスに基づいて線を描画します
for i in range(len(indices) - 1):
    plt.plot(*zip(coords[indices[i] - 1], coords[indices[i + 1] - 1]), marker='o')

# 描画結果を保存します
plt.savefig('out.png')
