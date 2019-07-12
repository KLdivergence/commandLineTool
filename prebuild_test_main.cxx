// #include <boost/bind.hpp>
#include <boost/program_options.hpp>
#include <boost/foreach.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <boost/unordered_set.hpp>

#include "hello.h"

// --------
// #include "mem_manager.h"    // must be the final #include header
// --------
namespace bpo = boost::program_options;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;

namespace {
  const string testPath = "/internal/versioned_data/testDir/";

  // bool addNewDir(string& destPath) {
  //   using namespace Auds;
  //   AudsClient c;
  //   boost::shared_ptr<AddRequest> addRequest(FDS::make_shared<AddRequest>
  //                                   (AddRequest(destPath.c_str())));
  //   addRequest->NodeType(AudsFile::AUDS_DIRECTORY);
  //   boost::shared_ptr<WriteResponse> addResponse;
  //   try {
  //     addResponse = c.SendRequest(addRequest);
  //   } catch(AudsException& e) {
  //     cout << " -- FAILURE: (" << AudsStatusToString(e.GetStatus())
  //           << ") " << e.GetMessage() << endl;
  //     return false;
  //   }

  //   if(!addResponse->IsOk()) {
  //     if(addResponse->GetStatus() == EXISTS) {
  //       cout << " -- (exists)" << endl;
  //     } else {
  //       cout << " -- FAILURE: (" << AudsStatusToString(addResponse->GetStatus())
  //             << ") " << addResponse->GetMessage() << endl;
  //       return false;
  //     }
  //   }
  //   return true;
  // }
}

int main(int argc, char** argv) {
  bpo::options_description desc("Options");
  vector<string> inputPaths;
  inputPaths.push_back(testPath);
  string prebuildName;
  int version = 50;

  sayHello();

  desc.add_options()
    ("help,h", "Produce help message")
    ("version,v",bpo::value<int>(&version), "Build a prebuild based on a certain version")
    ("name,n",bpo::value<string>(&prebuildName), "The name of prebuild")
    ("create,c", "Create a new prebuild")
    ("delete,d", "Delete a new prebuild");

  bpo::variables_map options;

  try {
    bpo::store(bpo::parse_command_line(argc, argv, desc), options);
  } catch(bpo::error& exception) {
    cerr << "Error parsing command line: " << exception.what() << endl;
    cerr << "(use -h for usage help)" << endl;
    return 1;
  }
  bpo::notify(options);

  if(options.count("help")) {
    cout << "Versioned Data Promotion Tool" << endl
         << "   Usage: " << argv[0] << " [options]" << endl;
    cout << desc << "\n";
    return 1;
  }

  cout<<version<<std::endl;
}