import random

var = list(range(1,15))
random.shuffle(var)

n = 20
numeros_aleatorios = random.sample(range(1, 101), n)
print (numeros_aleatorios)
