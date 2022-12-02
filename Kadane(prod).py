while True:
  try:
    vec = list(map(int,input().split()))
    x = len(vec)
    
    minimo = 1
    maximo = 1
    ans = vec[0]
    
    for i in range (0, x-1):
      aux = max(vec[i], maximo*vec[i], minimo*vec[i])
      minimo = min(vec[i], maximo*vec[i], minimo*vec[i])

      maximo = aux
      ans = max(ans, maximo)
      
    print(ans)
    
  except EOFError:
    break
