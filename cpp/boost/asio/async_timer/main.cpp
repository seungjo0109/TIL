//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

int main()
{
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

  /*
   steady_timer::async_wait() function to perform an asynchronous wait
   When calling ths function we pass the print callback handler that was defined above
  */
  t.async_wait(&print);

  /*
   Finally, we must call the io_context::run() member function on the io_context object. 
   The asio library provides a guarantee that callback handlers will only be called from threads that are currently calling io_context::run().
   Therefore unless the io_context::run() functio is called the callback for the asynchronous wait competion will never be invoked.
  */
  io.run();

  return 0;
}