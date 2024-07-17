def main():
    greeting = input("Please input a greeting. ")
    money = value(greeting)
    print('$ ' + str(money))
    ...


def value(greeting):
    if "hello" in greeting.casefold():
        # Output $0
        return 0
    elif greeting.lstrip().startswith('h'.casefold()):
        # Output $20

        return 20
    else:
        # Output $100
        return 100


if __name__ == "__main__":
    main()