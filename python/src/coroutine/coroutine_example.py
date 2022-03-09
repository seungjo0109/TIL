# Reference: https://docs.python.org/3/library/asyncio-task.html

# import time
import asyncio


async def task_func(module_num, sleep_time):
    print(f"Enter task_fnuc{module_num}")
    await asyncio.sleep(sleep_time)
    print(f"task_func{module_num} sleep {sleep_time} sec")


async def main():

    await asyncio.gather(
        task_func(1, 1),
        task_func(2, 2),
        task_func(3, 3),
        task_func(4, 4),
    )


if __name__ == "__main__":
    asyncio.run(main())
