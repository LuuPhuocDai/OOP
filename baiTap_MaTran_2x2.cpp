#include <iostream>
using namespace std;

// ma tran 2x2.
class matrix{
	private:
		int a, b, c, d;
	public:
		
		// khoi tao.
		matrix(){
			a = b = c = d = 0;
		}
		
		// ma tran cho trc.
		matrix(int e, int f, int g, int h){
			a = e;
			b = f;
			c = g;
			d = h;
		}

		// duyet ma tran cho trc.
		friend ostream& operator <<(ostream& Cout, matrix& duyet){
			int mt[2][2] = {duyet.a, duyet.b, duyet.c, duyet.d};
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					Cout<< mt[i][j]<<" ";
				}
				Cout<< endl;
			}
			return Cout;
		}
		
		// phep cong hai ma tran.
		friend matrix operator +(matrix x, matrix y){
			matrix result;
			result.a = x.a + y.a;
			result.b = x.b + y.b;
			result.c = x.c + y.c;
			result.d = x.d + y.d;
			return result;
		}
		
		// phep nhan hai ma tran.
		friend matrix operator *(matrix x, matrix y){
			matrix result;
			result.a = x.a * y.a + x.b * y.c;
			result.b = x.a * y.b + x.b * y.d;
			result.c = x.c * y.a + x.d * y.c;
			result.d = x.c * y.b + x.d * y.d;
			return result;
		}
};



int main(){
	matrix a = matrix(1, 2, 3, 4);
	matrix b = matrix(4, 3, 2, 1);
	
	// xuat hai ma tran cho trc.'
	cout<<"xuat hai mang tran"<< endl;
	cout<<"ma tran a:\n"<< a << endl <<"ma tran b:\n"<< b << endl;
	
	// cong hai ma tran.
	matrix tong = a + b;
	cout<<"phep cong:\n"<< tong << endl;
	
	// phep nhan.
	matrix tich = a * b;
	cout<<"phep nhan:\n"<< tich;
	return 0;
}