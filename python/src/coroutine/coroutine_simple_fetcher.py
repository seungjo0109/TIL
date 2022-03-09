# import requests
import asyncio
import aiohttp


async def fetcher(session, url):
    async with session.get(url) as response:
        return await response.text()


async def main():
    urls = [
        "https://www.naver.com",
        "https://www.google.com",
        "https://www.facebook.com",
    ]
    async with aiohttp.ClientSession() as session:
        result = await asyncio.gather(*[fetcher(session, url) for url in urls])
        print(result)


if __name__ == "__main__":
    asyncio.run(main())
