from typing import List, Literal

import line


def flag_line(line: Line) -> None:
    line.flag = LT_NORMAL
    if line.data.startswith("#include <"):
        line.flag = LT_INCLUDE_STD
    if line.data.startswith("#include \""):
        line.flag = LT_INCLUDE_USR


def filter_lines(lines : List[Line]) -> bool:
    for l in lines:
        flag_line(l)
