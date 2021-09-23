def lastDigitOf(num: int):
    return num % 10


def placeValueOf(num: int, place: int) -> int:
    """
    Get the value on the place specified.

    :param num: The num
    :param place: The place. 1 for unit place, 10 for tens place, 100 for hundreds place.
    :return: The value digit.
    """
    return lastDigitOf(num // place)
