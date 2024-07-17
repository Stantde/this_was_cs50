from numb3rs import validate
#, valid_ip_form, valid_ip_value
#test validate, form and number on values.
'''
def test_null():
    assert 1 == 1
'''
def test_validate_on_good_numbers():
    a = '192.255.255.1'
    b = '0.0.0.0'
    c = '127.0.0.1'
    assert validate(a) == True
    #assert valid_ip_form(a) == True
    #assert valid_ip_value(a) == True
    assert validate(b) == True
    #assert valid_ip_form(b) == True
    #assert valid_ip_value(b) == True
    assert validate(c) == True
    #assert valid_ip_form(c) == True
    #assert valid_ip_value(c) == True


def test_validate_on_negative_numbers():
    a = '-10.20.-30.40'
    b = '-1.10.0.40'
    c = '1-.10.0.40'
    assert validate(a) == False
    #assert valid_ip_form(a) == False
    #assert valid_ip_value(a) == False
    assert validate(b) == False
    #assert valid_ip_form(b) == False
    #assert valid_ip_value(b) == False
    assert validate(c) == False
    #assert valid_ip_form(c) == False
    #assert valid_ip_value(c) == False

def test_validate_on_large_numbers():
    a = '990.660.330.0'
    b = '9920.6560.330.0'
    c = '1.2.3.1000'
    assert validate(a) == False
    #assert valid_ip_form(a) == True
    #assert valid_ip_value(a) == False
    assert validate(b) == False
    #assert valid_ip_form(b) == False
    #assert valid_ip_value(b) == False
    assert validate(c) == False
    #assert valid_ip_form(c) == False
    #assert valid_ip_value(c) == False


def test_validate_on_not_numbers():
    a = '0.01.0t5.099'
    b = '0f.0.cat.0'
    c = '0.0.0@.0'
    d = '...'
    assert validate(a) == False
    #assert valid_ip_form(a) == False
    #assert valid_ip_value(a) == False
    assert validate(b) == False
    #assert valid_ip_form(b) == False
    #assert valid_ip_value(b) == False
    assert validate(c) == False
    #assert valid_ip_form(c) == False
    #assert valid_ip_value(c) == False
    assert validate(d) == False
    #assert valid_ip_form(d) == False
    #assert valid_ip_value(d) == False

def test_one_number():
    a = '192'
    assert validate(a) == False
    #assert valid_ip_form(a) == False
    #assert valid_ip_value(a) == True

def test_more_numbers():
    a = '45.23.35.16.44.45.64.54.69.75'
    assert validate(a) == False
    #assert valid_ip_form(a) == False
    #assert valid_ip_value(a) == True

def test_more_tests():
    assert validate('this is the end') == False
    assert validate('how \n do I break this?') == False
    assert validate('"25.21.15.1"') == False


def test_validate_im_running_out_of_ideas():
    assert validate('1.2.3.4') == True
    assert validate('1.2.4') == False
    assert validate('1..4') == False
    assert validate('1.') == False
    assert validate('512.1.1.1') == False
    assert validate('1.512.1.1') == False
    assert validate('1.1.512.1') == False
    assert validate('1.1.1.512') == False

def main():
    ...


if __name__ == '__main__':
    main()


    ...