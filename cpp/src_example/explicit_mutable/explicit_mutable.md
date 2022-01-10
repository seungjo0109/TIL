# Mutable

* 멤버 함수를 const로 선언하는 의미는 해당 함수가 객체 내부 상태의 영향을 주지 않기 위함

* 대부분의 경우, 의미상 상수 작업을 하는 경우, 실제로도 상수 작업을 하게 됨. 하지만, 실제로 꼭 그렇지만은 않음

* 보통 데이터베이스에 데이터를 요창할 때, 요청한 후 데이터를 수신하는 작업의 시간이 꽤나 오래 걸림
    * 보통 서버들의 경우 메모리에 캐쉬(cache)를 만들어서 자주 요청되는 데이터를 굳이 데이터베이스까지 가서 찾지 않아도 메모리에서 빠르게 조회할 수 있도록 함

* 캐쉬는 데이터베이스만큼 크지 않기 때문에 일부 유저들 정보 밖에 포함하지 않는다. 따라서 캐쉬에 해당 유저가 없으면 (cache miss), 데이터베이스에 직접 요청해야함
    * 대신 데이터베이스에서 유저 정보를 받으면 캐쉬에 저장해두어서 다음 요청 시, 빠르게 받을 수 있음

* 유저의 정보를 불러오는 함수가 const일 경우, 함수 내에서 캐쉬를 업데이트 하는 함수를 구현이 불가함
    * 이때 캐쉬 변수에 mutable 선언을 선언할 경우, const 내부에서 캐쉬 변수를 업데이트할 수 있음