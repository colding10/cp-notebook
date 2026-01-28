class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        previous_ending = 0
        times = {i : [-1] for i in range(n)}
        
        for data in logs:
            worker_id, ending_time = data
            time_taken = ending_time - previous_ending
            previous_ending = ending_time
            times[worker_id].append(time_taken)
        
        times = {i : max(v) for i, v in times.items()}
        maximum_time_taken = max(times.values())
        
        max_ids = []
        for key, value in times.items():
            if value == maximum_time_taken:
                max_ids.append(key)
        
        return min(max_ids)