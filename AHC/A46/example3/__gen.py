import random

def generate_coords(n, filename):
    with open('./in/in1', 'w') as file:
        file.write(str(n) + '\n')
        for _ in range(n):
            x = random.randint(0, 1000)
            y = random.randint(0, 1000)
            file.write(f'{x} {y}\n')

# テスト
generate_coords(150, 'in1.txt')
