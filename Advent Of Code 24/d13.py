import pathlib
import re
from dataclasses import dataclass
from fractions import Fraction
from typing import Generator

LINE_RE = re.compile(
    r"(?:Button (?:[AB])|Prize): X(?:\+|=)(?P<x>\d+), Y(?:\+|=)(?P<y>\d+)"
)
p2_offset = 10000000000000


@dataclass
class Vec2:
    x: int
    y: int

    def ratio(self) -> Fraction:
        return Fraction(self.y) / Fraction(self.x)


def parse(raw_data, part2: bool = False) -> Generator[[], tuple[Vec2, Vec2, Vec2], []]:
    for dataset in raw_data.split("\n\n"):
        a, b, t = [
            Vec2(int(x), int(y))
            for x, y in (
                e
                for e in (
                    LINE_RE.match(e).groupdict().values() for e in dataset.splitlines()
                )
            )
        ]
        yield a, b, t


def check_result(Px: Fraction, Py: Fraction, a: Vec2, b: Vec2, t: Vec2) -> int:
    r = (Py - (b.ratio() * Px)) / (a.ratio() - b.ratio())
    if r.denominator == 1:
        x = r.numerator
        y = a.ratio() * x
        n_a = y / a.y
        dy = Py - y
        n_b = dy / b.y

        if n_b.denominator == 1 and n_a.denominator == 1:
            return (3 * abs(n_a) + abs(n_b)).numerator
    return 0


def solve(data: list[tuple[Vec2, Vec2, Vec2]]) -> tuple[int, int]:
    total_1 = sum(
        (check_result(Fraction(t.x), Fraction(t.y), a, b, t) for a, b, t in data)
    )
    total_2 = sum(
        (
            check_result(Fraction(t.x + p2_offset), Fraction(t.y + p2_offset), a, b, t)
            for a, b, t in data
        )
    )
    return total_1, total_2


data: list[tuple[Vec2, Vec2, Vec2]] = list(
    parse(pathlib.Path("input.txt").read_text())
)
print(*(f"Part {n}: {r}" for n, r in enumerate(solve(data), start=1)))