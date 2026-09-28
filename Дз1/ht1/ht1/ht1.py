import numpy as np

def normalized():
    while True:
        n = input("Введите целое число больше 1: ")
        if n.isdigit() and int(n) > 1: 
            n = int(n)
            break
        else: print("Ошибка!!")
    data = np.random.randint(-50, 100, size = n)
    print("Исходный массив: ", data)
    min_val = data[0] 
    max_val = data[0] 
    for i in range(1, n):
         if (min_val > data[i]): min_val = data[i] 
         if (max_val < data[i]): max_val = data[i]
    if (min_val == max_val): 
        print("Максимальное и минимальное значения равны")
        return
    values = []
    for i in range(n):
         values.append((data[i] - min_val)/(max_val - min_val))
    normalized_data = np.array(values)
    print("Нормализованный массив: ", normalized_data)

np.set_printoptions(threshold=np.inf)
normalized()