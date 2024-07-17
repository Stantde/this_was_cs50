#from twttr import list_vowels
from twttr import shorten


def test_null():
    assert 1 == 1


def test_strs_with_one_vowel():
    assert shorten('twit') == 'twt'


def test_strs_with_two_vowel():
    assert shorten('liken') == 'lkn'


def test_strs_with_three_vowel():
    assert shorten('looking') == 'lkng'


def test_str_with_number():
    assert shorten('1337 c0d3') == '1337 c0d3'


def test_capital_vowel():
    assert shorten('THAT') == 'THT'

def test_punctuation():
    assert shorten("ain't") == "n't"
    assert shorten('potyy, chump!') == 'ptyy, chmp!'