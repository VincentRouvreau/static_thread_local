Some static thread_local test

## The issue

```ipython
>>> import static_thread_local as stl
>>> stl.get_local()
get_default_local() 0x5df481da16c0
42
>>> stl.set_local(0)
get_default_local() 0x5df481da16c0
>>> stl.get_local()
get_default_local() 0x5df481da16c0
0
>>> stl.hello_local()
get_default_local() 0x5df481d63180
local= 42
```

`stl.hello_local()` should give the same pointer value and the same value as `stl.get_local()`
