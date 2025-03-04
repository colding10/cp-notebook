import random
import subprocess
import time
import statistics
from typing import List, Tuple

def generate_test_case() -> Tuple[int, int, int]:
    a = random.randint(1, 20000)
    b = random.randint(1, 20000)
    c = random.randint(1, min(a, b))
    return a, b, c

def run_test(a: int, b: int, c: int) -> Tuple[bool, float]:
    input_data = f"{a}\n{b}\n{c}\n"
    start_time = time.time()
    
    try:
        process = subprocess.run(
            ["pypy3.10", "j5.py"],
            input=input_data,
            text=True,
            capture_output=True,
        )
        execution_time = time.time() - start_time
        
        return process.returncode == 0, execution_time
    except subprocess.TimeoutExpired:
        return False, 2.0
    except Exception as e:
        print(f"Error running test: {e}")
        return False, 0.0

def main():
    NUM_TESTS = 100
    successful_tests = 0
    failed_tests = 0
    execution_times: List[float] = []
    
    print(f"Running {NUM_TESTS} test cases...")
    
    for i in range(NUM_TESTS):
        a, b, c = generate_test_case()
        success, exec_time = run_test(a, b, c)
        
        if success:
            print(f"[SUCCESS] TC {i+1}")
            successful_tests += 1
            execution_times.append(exec_time)
        else:
            failed_tests += 1
            print(f"Failed test case #{i + 1}: A={a}, B={b}, C={c}")
    
    # Calculate statistics
    success_rate = (successful_tests / NUM_TESTS) * 100
    
    print("\nTest Results Summary:")
    print(f"Total test cases: {NUM_TESTS}")
    print(f"Successful tests: {successful_tests}")
    print(f"Failed tests: {failed_tests}")
    print(f"Success rate: {success_rate:.2f}%")
    
    if execution_times:
        avg_time = statistics.mean(execution_times)
        max_time = max(execution_times)
        min_time = min(execution_times)
        print(f"\nExecution Time Statistics:")
        print(f"Average time: {avg_time:.6f} seconds")
        print(f"Maximum time: {max_time:.6f} seconds")
        print(f"Minimum time: {min_time:.6f} seconds")

if __name__ == "__main__":
    main()

