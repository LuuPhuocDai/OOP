#include <iostream>

using namespace std;

class phanSo{
	private:
		int tuSo;
		int mauSo;
	public:
		// khai bao.
		phanSo(){
			tuSo = 0;
			mauSo = 0;
		}
		
		// hai phan so cho trc.
		phanSo(int a, int b);
		
		// rut gon.
		void rutGon();
			
		// ham xuat.
		void outPut() {
            if (tuSo == 0)
               cout << "phan so = 0";
            else if (mauSo == 1)
                cout <<"phan so = "<< tuSo;
            else if (tuSo == mauSo)
                cout << "phan so = 1";
            else 
                cout <<"phan so = "<< tuSo << " / " << mauSo;
        }
        
        // xuat hai phan so.
		friend ostream& operator <<(ostream& COUT, phanSo a);
		
		
		// phep toan.
		// phep cong hai phan so.
		friend phanSo operator +(phanSo a, phanSo b);
		
		// phep tru hai phan so.
		friend phanSo operator -(phanSo a, phanSo b);
		
		// phep nhan hai phan so.
		friend phanSo operator *(phanSo a, phanSo b);
		
		// phep chia hai phan so.
		friend phanSo operator /(phanSo a, phanSo b);
		
		// so sanh hai phan so.
		friend bool operator ==(phanSo a, phanSo b);
};


// phan so cho trc.
phanSo::phanSo(int tuSo1, int mauSo1){
	tuSo = tuSo1;
	mauSo = mauSo1;
}

// rut gon.
// ucln.
int ucln(int a, int b){
	while(a != b){
		if(a > b) a = a - b;
		else b = b - a;
	}
	return a;
}

void phanSo::rutGon(){
	int UCLN = ucln(tuSo, mauSo);
	tuSo = tuSo / UCLN;
	mauSo = mauSo / UCLN;
}

// xuat hai phan so.
ostream& operator <<(ostream& COUT, phanSo a){
	a.rutGon();
	a.outPut();
	return COUT;
}

// phep cong hai phan so.
phanSo operator +(phanSo a, phanSo b){
   phanSo c;
   c.tuSo = (a.tuSo * b.mauSo) + (a.mauSo * b.tuSo);
   c.mauSo = a.mauSo * b.mauSo;
   return c;
}

// phep tru hai phan so.
phanSo operator -(phanSo a, phanSo b){
   phanSo c;
   c.tuSo = (a.tuSo * b.mauSo) - (a.mauSo * b.tuSo);
   c.mauSo = a.mauSo * b.mauSo;
   return c;
}

// phep nhan hai phan so.
phanSo operator *(phanSo a, phanSo b){
   phanSo c;
   c.tuSo = a.tuSo * b.tuSo;
   c.mauSo = a.mauSo * b.mauSo;
   return c;
}

// phep chia hai phan so.
phanSo operator /(phanSo a, phanSo b){
   phanSo c;
   c.tuSo = a.tuSo * b.mauSo;
   c.mauSo = a.mauSo * b.tuSo;
   return c;
}


// so sach hai phan so.
bool operator ==(phanSo a, phanSo b){
	if(a.tuSo == b.tuSo){
		if(a.mauSo == b.mauSo){
			return true;
		}
	}
	return false;
}


int main(){
	phanSo a = phanSo(99, 88);
	phanSo b = phanSo(11, 22);
	cout<<"phan so a:\n" << a <<"\nphan so b:\n"<< b << endl;
	
	// phep cong hai phan so.
	cout<< endl;
	phanSo tong = a + b;
	cout<<"phep cong:"<< endl << tong << endl;
	
	// phep tru hai phan so.
	cout<< endl;
	if(a == b){// truong hop khi hai phan so bang nhau de tranh loi.
		cout<<"phep tru:\n";
		cout<<"phan so = 0"<< endl;
	}
	else{
		phanSo hieu = a - b;
	    cout<<"phep tru:"<< endl << hieu << endl;
	}
	
	// phep nhan hai phan so.
	cout<< endl;
	phanSo tich = a * b;
	cout<<"phep nhan:"<< endl << tich << endl;
	
	// phep tru hai phan so.
	cout<< endl;
	phanSo thuong = a / b;
	cout<<"phep chia:"<< endl << thuong << endl;
	
	// so sach hai phan so.
	cout<< endl;
	if(a == b) cout<<"hai phan so bang nhau";
	else cout<< "hai phan so khong bang nhau";
	
	return 0;
}