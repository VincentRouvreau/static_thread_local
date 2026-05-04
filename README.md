Some static thread_local test

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
