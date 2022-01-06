#include <iostream>
#include <string>

int main(void)
{
    std::string str1{"TestString"};

    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str1.at(1): " << str1.at(1) << std::endl;
    std::cout << "str1[1]: " << str1[1] << std::endl;       // at 함수보다 빠르나 예외를 출력하지 않음
    std::cout << "str1.front(): " << str1.front() << std::endl;
    std::cout << "str1.back(): " << str1.back() << std::endl;
    std::cout << "str1.size(): " << str1.size() << std::endl;
    std::cout << "str1.length(): " << str1.length() << std::endl;

    /* 
        string 객체에 할당된 메모리를 반환
        vector의 capacity와 마찬가지로 string 길이가 증가할 수 있기 때문에 메모리 할당을 여유롭게 함
    */
    std::cout << "str1.capacity(): " << str1.capacity() << std::endl;
    str1.resize(20);
    std::cout << "str1.resize(20): " << str1.size() << std::endl;
    /*
        문자열을 넣기 전에 미리 "n만큼 크기의 스트링이 입력될 것이니 그에 맞는 capacity를 할당하라"는 함수
        보통 파일을 읽을 때 사용
        만약 메모리를 할당하지 않을 경우, 파일이 들어올 때마다 capacity를 증가하는 작업을 진행할 것임
    */
    str1.reserve(100);
    std::cout << "str1.reserve(100): "<< str1.capacity() << std::endl;       
    str1.clear();       // 문자열을 지우고, size, length는 0으로 만든다. capacity는 그대로 남는다.
    std::cout << "str1.clear(): "<< std::endl;
    std::cout << "str: " << str1 << ",  capacity: "<< str1.capacity() << ", size, length: "<< str1.size() << ", " << str1.length() << std::endl; 
    std::cout << "str1.empty(): " << str1.empty() << std::endl;
    
    str1 = "TestString";
    std::cout << "str1.substr(1): " << str1.substr(1) << std::endl;
    std::cout << "str1.replace(0, 1, \"tE\"): " << str1.replace(0,2, "tE") << std::endl;
    std::cout << "str1.compaer(\"tEstString\"): " << str1.compare("tEstString") << std::endl;
    std::cout << "str1.find(\"st\", 0): " << str1.find("st", 0) << std::endl;
    str1.push_back('!');
    std::cout << "str1.push_back('!'): " << str1 << std::endl;
    str1.pop_back();
    std::cout << "str1.pop_back(): " << str1 << std::endl <<std::endl;

    //string iterator
    std::cout<< "string iterator: " << std::endl; 
    for (std::string::iterator iter = str1.begin(); iter != str1.end(); ++iter){
        std::cout << *iter << std::endl;
    }

    std::string str2{"TESTSTRING!!!"};
    std::swap(str1, str2);
    std::cout << "swap(str1, str2)-> str1: " << str1 << ", str2: " << str2 << std::endl;

    //string operator
    std::cout << "str1 + str2: "<<str1 + str2 << std::endl;

}
