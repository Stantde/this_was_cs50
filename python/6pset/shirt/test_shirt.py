from shirt import get_extension

def test_null():
    assert 1 == 1

def test_one_period():
    assert get_extension('hi.pdf') == 'pdf'

def test_no_period():
    assert get_extension('hipdf') == 'hipdf'

def test_two_periods():
    assert get_extension('h.ip.df') == 'df'

def test_empty():
    assert get_extension('') == ''

# any corner cases that should be considered?