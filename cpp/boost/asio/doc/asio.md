# ASIO

* Most programs interact with the outside world in some way, whether it be via a file, a network, a serial cable, or the console. Sometimes, as is the cas with networking, individual I/O operations can take a lone time to complete.

* Boost.Asio provides the tools to manage these long running operations, without requiring programs to use concurrency models based on threads and explicit locking

* The Boost.Asio library is intended for programmers using C++ for systems programming, where access to operating system functionality such as networking is often required.

<br/>

### Core Concepts and Functionality
1. Basic Boost.Asio Anatomy
2. The Proactor Design Pattern: Concurrency Without Threads
3. THreads and Boost.Asio
4. Strands: Use Threads Without Explicit Locking
5. Buffers
6. Streams, Short Reads and Short Writes
7. Reactor-Style Operations
8. Line-Based Operations
9. Custom Memory Allocation
10. Per-Operation Cancellation
11. Handler Tracking
12. Concurrency Hints
13. Stackless Coroutines
14. Stackful Coroutines
15. C++20 Coroutines Support

<br/>

### Networking
1. TCP, UDP and ICMP
2. Support for Ohter Protocols
3. Socket iostreams
4. The BSD Socket API and Boost.Asio

<br/>

### Timers

<br/>

### Serial Ports

<br/>

### Signal Handling

<br/>

### POISX-Specific Functionality
1. UNIX Domain Sockets
2. Stream-Oriented File Descriptions
3. Fork

<br/>

### Windows-Specific Functionality
1. Stream-Oriented HANDLEs
2. Random-Access HANDLEs
3. Object HANDLEs

<br/>

### SSL

<br/>

### C++ 2011 Support
1. Movable I/O Objects
2. Movable Handlers
3. Variadic Templates
4. Array Container
5. Atomic
6. Shared Pointers
7. Chrono
8. Futures