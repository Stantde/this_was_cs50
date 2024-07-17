import pytest
from journal import *

def test_ask():
    assert ask() == None

def test_start():
    assert start('C' , 0) == 'C'
    assert start('(CAT' , 0) == 'C'
    with pytest.raises(OSError):
        assert start('X' , 0)
        assert start('c' , 0)
        assert start('       c' , 0)
        #assert start(' ', 0)


