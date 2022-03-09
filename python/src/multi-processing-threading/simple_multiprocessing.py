import time
import os
import threading
from concurrent import futures

nums = [50, 60, 50, 50]


def cpu_bound_func(num):
    print(f"{os.getpid()} process | {threading.get_ident()} thread")
    numbers = range(1, num)
    total = 1
    for i in numbers:
        for j in numbers:
            for k in numbers:
                total *= i * j * k
    return total


def main():

    # single threading
    # for num in nums:
    #     cpu_bound_func(num)

    # multithreading(just concurrency)
    # executor = futures.ThreadPoolExecutor(max_workers=10)
    # results = list(executor.map(cpu_bound_func, nums))

    # 파이썬의 멀티스레딩은 동시성을 사용해서 io bound 코드에서 유용하게 사용할 수 있지만
    # cpu bound 코드에서는 GIL(Global Interpreter Lock)에 의해 원하는 결과를 얻을 수 없음
    # multiprocessing
    executor = futures.ProcessPoolExecutor(max_workers=10)
    results = list(executor.map(cpu_bound_func, nums))


if __name__ == "__main__":
    before = time.time()
    main()
    after = time.time()
    print(after - before)
