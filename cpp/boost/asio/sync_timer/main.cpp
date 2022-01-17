#include <iostream>

// All of the asio classes can be used by simply including the "asio.hpp" header file.
#include <boost/asio.hpp>       

int main(void)
{
    /*
     All programs that use asio need to have at least one I/O execution context,
     such as an io_context or thread_pool object.
     An I/O execution provieds access to I/O functionality.
    */
    boost::asio::io_context io;

    /*
     The core asio classes that provide I/O  functionality (or as in this case timer functionalitly)
     always take a reference to an io_context as their first constructor argument
    */
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    /*
     A timer is always in one of two stats: "expired" or "not expired"
    */
    t.wait();

    std::cout << "Hello asio!" << std::endl;

    return 0;
}