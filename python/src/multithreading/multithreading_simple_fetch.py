from concurrent import futures
import requests
import time


def fetcher(params):
    session = params[0]
    url = params[1]
    with session.get(url) as response:
        return response.text


def main():

    urls = ["https://www.naver.com", "https://www.google.com"]

    executor = futures.ThreadPoolExecutor(max_workers=10)

    with requests.Session() as session:
        params = [(session, url) for url in urls]

        results = list(executor.map(fetcher, params))
        print(results)


if __name__ == "__main__":
    before = time.time()
    main()
    after = time.time()
    print(after - before)
