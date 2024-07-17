from working import convert
import pytest

def test_times_from_desc():
    assert convert('9:00 AM to 5:00 PM') == '09:00 to 17:00'
    assert convert('9 AM to 5 PM') == '09:00 to 17:00'
    assert convert('10 AM to 5 PM') == '10:00 to 17:00'
    assert convert('10 PM to 5 PM') == '22:00 to 17:00'
    assert convert('12 AM to 5 PM') == '00:00 to 17:00'
    assert convert('12 PM to 5 PM') == '12:00 to 17:00'


def test_more_more_times():
    assert convert('10 PM to 8 AM') == '22:00 to 08:00'
    assert convert('10:30 PM to 8:50 AM') == '22:30 to 08:50'
    ...

def test_values():
    #10 am ok 12 am ok 14 am not ok
    #10 pm ok 12 pm ok 14 pm not ok
    with pytest.raises(ValueError):
        assert convert('12 AM to 14 PM')
        assert convert('10 AM to 27 PM')
        assert convert('9:60 AM to 5:60 PM')
        assert convert('9:59 AM to 5:60 PM')
        assert convert('9:59 AM to 5:61 PM')
        assert convert('9 AM - 5 PM')
        assert convert('09:00 AM - 17:00 PM')
    ...

def test_long_hours():
    with pytest.raises(ValueError):
        assert convert('cat')
    ...
