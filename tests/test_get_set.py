import static_thread_local as stl

def test_get():
    assert stl.get() == 42

def test_set():
    stl.set(0)
    assert stl.get() == 0
