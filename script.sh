awk -v loop=500 -v range=10000000 'BEGIN{
  srand()
  do {
    numb = 1 + int(rand() * range)
    if (!(numb in prev)) {
       print numb
       prev[numb] = 1
       count++
    }
  } while (count<loop)
}'


