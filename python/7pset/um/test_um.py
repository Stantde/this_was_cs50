from um import count

def test_this():
    assert count('yum') == 0
    assert count('hello, um, world') == 1
    assert count('ummmm, hi, um, world?') == 1

def test_more():
    assert count('Not in here, you wont') == 0

def test_c50():
    assert count("Um? Mum? Is this that album where, um, umm, the clumsy alums play drums?") == 2