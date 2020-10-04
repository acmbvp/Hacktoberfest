from netaddr import iter_iprange
import tqdm
import time

generator = iter_iprange('67.220.192.0', '67.220.223.255', step=1)

#end = len(list(generator))
for i in tqdm.tqdm(generator):
  time.sleep(0)
  open('generate-ip.txt','a').write(str(i)+'\n')