from twttr import shorten

def test_strs_with_one_vowel():
    assert shorten('twit') == 'twt'


def test_strs_with_two_vowel():
    assert shorten('liken') == 'lkn'


def test_strs_with_three_vowel():
    assert shorten('looking') == 'lkng'


def test_str_with_number():
    assert shorten('1337 c0d3') == '1337 c0d3'