#include <iostream>
using namespace std;

class phanSo{
	private:
		int mauSo ,tuSo ;
	public:
		phanSo(int mauSo1, int tuSo1){
			mauSo = mauSo1;
			tuSo = tuSo1;
		}
		
		// friend.
		friend ostream& operator<<(ostream& cout, phanSo& a){
			cout<<"phan so: "<< a.tuSo  << "/" << a.mauSo <<  endl;
			return cout;
        }
};


int main(){
	phanSo a = phanSo(12, 11);
	phanSo b = phanSo(21, 22);
	cout<< a << b;
	
	return 0;
}