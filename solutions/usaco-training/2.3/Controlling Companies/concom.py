"""
ID: colindi1
LANG: PYTHON3
TASK: concom
"""

from dataclasses import dataclass

@dataclass
class Company:
    number: int
    controlling: set[object]
    being_controlled_by: set[object]

    def add_controlled(self, obj):
        self.controlling.add(obj)
    
    def merge_controlled(self, obj):
        for c in obj.controlling:
            self.add_controlled(c)
            
    def add_being_controlled(self, obj):
        self.being_controlled_by.add(obj)
    
with open("/Users/colinding/Documents/Coding/Competitions/USACO/Chapter 2/2.3/Controlling Companies/concom.in", "r") as file:
    lines = [i.replace("\n", "") for i in file.readlines()]

N = lines.pop(0)

companies = dict()

for info in lines:
    controlling, controlled, percentage = map(int, info.split())

    if controlling not in companies:
        company = Company(controlling, set(), set())
        companies[controlling] = company

    if controlled not in companies:
        company = Company(controlled, set(), set())
        companies[controlled] = company

    if percentage > 50:
        companies[controlling].add_controlled(controlled)
        companies[controlled].merge_controlled(companies[controlling])
        companies[controlled].add_being_controlled(controlling)


out = []

for company in companies.values():
    for controlled in company.controlling:
        if controlled == company.number:
            continue
        
        to_append = f"{company.number} {controlled}"

        if to_append not in out:
            out.append(to_append)

with open("concom.out", "w") as file:
    file.write("\n".join(out)+"\n")
