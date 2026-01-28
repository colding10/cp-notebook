#
# @lc app=leetcode id=1507 lang=python3
#
# [1507] Reformat Date
#

# @lc code=start
class Solution:
    def reformatDate(self, date: str) -> str:
        day_str, month_str, year_str = date.split()
        day_number = ""
        months = "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec"
        months = months.split()
        months = [""] + months
        
        for c in day_str:
            if not c.isdigit():
                break
            day_number += c
        
        
        month_number = f"{months.index(month_str):02d}"
        day_number = f"{int(day_number):02d}"
        year_num = year_str
        
        return "-".join((year_num, month_number, day_number))
# @lc code=end

