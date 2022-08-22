# NestExchange
Created application based on c++ and mongodb (mongoc).
The Nest Exchange can register new and authentication users, and buy fiat and crypto. it is also possible to add new features.
it's only the alpha version, it has no tests and has not been tested on windows yet. it has a connection to the database and registration of new accounts. 
# Pre-reqs
To build and run this app locally you will need a few things:
- Install  [MongoDB](https://www.mongodb.com/).
- Install  [Mongo C Driver](http://mongoc.org/).
#Getting started
- Clone the repository
> $ git clone https://github.com/Hizmu/NestExchange
- Compiled 
```
$ cd NestExchange && mkdir build && cd build
$ cmake .. && make -j
```
#Platforms
- Linux
- Windows64
