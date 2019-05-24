#include "SalesList.h"

SalesList::SalesList() {

  std::fstream infile;
  infile.open("sales.txt");
  assert(infile.is_open());
  while (!infile.eof()) {
    SalesItem item = {-1, -1, -1, -1, -1, -1};
    infile >> item.no;
    infile >> item.time;
    infile >> item.restAddX;
    infile >> item.restAddY;
    infile >> item.cusAddX;
    infile >> item.cusAddY;
    Saleslist.push_back(item);
  }
  infile.close();
  //关闭文件输入流

}


void SalesList::PrintSalsesList() {
	using namespace std;
	if(Saleslist.size()==0){
		cout << "NO SALESITEM IN LIST!\n";
	} else {
		for(auto i : Saleslist){
			cout << i.no << ' ' << i.time << ' ' << i.restAddX << ' ' << i.restAddY << ' ' << i.cusAddX << ' '  << i.cusAddY << endl;
		}
		cout << "The num of AllSalesItems is " << Saleslist.size() << endl;
	}
}

SalesList::~SalesList() {}
