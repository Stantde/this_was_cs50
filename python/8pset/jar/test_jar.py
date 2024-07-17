from jar import Jar
import pytest


def test_init():
    jar = Jar()
    assert jar.capacity == 12
    jar = Jar(40)
    assert jar.capacity == 40
    with pytest.raises(ValueError):
        assert jar == Jar(-1)
        assert jar == Jar("cat")

def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit():
    jar = Jar()
    jar.deposit(1)
    assert jar.size == 1
    jar.deposit(1)
    assert jar.size == 2
    with pytest.raises(ValueError):
        jar.deposit(11)
    #but I cans depoozet a cat?


def test_withdraw():
    n =12
    jar = Jar(n)
    jar.deposit(n)
    jar.withdraw(6)
    assert jar.size == 6
