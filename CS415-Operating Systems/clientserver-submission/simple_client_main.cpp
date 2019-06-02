#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, char *argv[] )
{
  std::string ary[10] = {
    "0)A beautiful, smart, and loving person will be coming into your life.",
    "1)A dubious friend may be an enemy in camouflage.",
    "2)A fresh start will put you on your way.",
    "3)A friend asks only for your time not your money.",
    "4)A friend is a present you give yourself.",
    "5)A gambler not only will lose what he has, but also will lose what he doesn’t have.",
    "6)A golden egg of opportunity falls into your lap this month",
    "7)A good friendship is often more important than a passionate romance.",
    "8)A hunch is creativity trying to tell you something.",
    "9)A lifetime friend shall soon be made."
  };
  for (int i = 0; i < 10; ++i){
  try
  {

    ClientSocket client_socket("localhost", 30000);

    std::string reply;

    try
    {
      int x = rand() % 10;
      client_socket << ary[x];
      client_socket >> reply;
    }
    catch (SocketException &)
    {
    }

    std::cout << "We received this response from the server:\n\"" << reply << "\"\n";
    ;

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }
  }
  return 0;
}
