Some thread_local test

## Behaviour

```ipython
>>> import static_thread_local as stl
>>> stl.get_local()
get_default_local() 0x5ae793c6fee0
42
>>> stl.set_local(0)
get_default_local() 0x5ae793c6fee0
>>> stl.hello_local()
get_default_local() 0x5ae793c6fee0
local= 0
```

## In Parallel

()

```ipython
>>> from joblib import Parallel, delayed
>>> import static_thread_local as stl
>>> import random

>>> def pouet():
...     stl.set_local(random.randint(0,10))
...     return stl.get_local()
...
>>> Parallel(n_jobs=-2)(delayed(pouet)() for _ in range(10))
get_default_local() 0x5a848444a970
get_default_local() 0x5a848444a970
get_default_local() 0x5722cce5b970
get_default_local() 0x5722cce5b970
get_default_local() 0x6165fc0e9970
get_default_local() 0x6165fc0e9970
get_default_local() 0x582fd9a7c970
get_default_local() 0x582fd9a7c970
get_default_local() 0x56cc2922b970
get_default_local() 0x56cc2922b970
get_default_local() 0x63ccc0e8c990
get_default_local() 0x63ccc0e8c990
get_default_local() 0x5bb9ea4c5970
get_default_local() 0x5bb9ea4c5970
get_default_local() 0x64900e5cb990
get_default_local() 0x64900e5cb990
get_default_local() get_default_local() 0x5ba591f049700x60a3ac3b4990

get_default_local() get_default_local() 0x5ba591f049700x60a3ac3b4990

[1, 4, 10, 4, 6, 10, 6, 8, 1, 4]
>>> # OK, 10 different pointer values

>>> Parallel(n_jobs=3)(delayed(pouet)() for _ in range(10))
get_default_local() get_default_local() 0x5a7cdfdb29700x5f5df1b6c970

get_default_local() get_default_local() 0x5a7cdfdb29700x5f5df1b6c970

get_default_local() 0x564cb02b7970
get_default_local() 0x564cb02b7970
get_default_local() 0x5f5df1b6c970
get_default_local() 0x5f5df1b6c970
get_default_local() 0x5a7cdfdb2970
get_default_local() 0x5a7cdfdb2970
get_default_local() 0x5f5df1b6c970
get_default_local() 0x5f5df1b6c970
get_default_local() 0x5a7cdfdb2970
get_default_local() 0x5a7cdfdb2970
get_default_local() 0x5f5df1b6c970
get_default_local() 0x5f5df1b6c970
get_default_local() 0x564cb02b7970
get_default_local() 0x564cb02b7970
get_default_local() 0x5a7cdfdb2970
get_default_local() 0x5a7cdfdb2970
[7, 3, 6, 0, 9, 9, 6, 7, 6, 9]
>>> # OK, only 3 different pointer values
```
