LT_INCLUDE_STD = -1
LT_INCLUDE_USR = -2

LT_NORMAL = 1


class Line:
    data: str
    flag: int = LT_NORMAL

    def __init__(self, data: str) -> None:
        self.data = data
