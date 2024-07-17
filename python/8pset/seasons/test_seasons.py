from seasons import get_date
from seasons import caluate_time_delta
from seasons import convert_to_minutes
import pytest

def test_convert_to_minutes():
    assert convert_to_minutes(1) == 24*60
    assert convert_to_minutes(-1) == -24*60

def test_zeroes():
    assert convert_to_minutes(0) == 0

def test_non_words():
    with pytest.raises(OSError):
        assert get_date()


